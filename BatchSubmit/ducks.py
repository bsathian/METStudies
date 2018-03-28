import sys, os
import time
import itertools
import numpy

import argparse

os.system("./setup.sh")

from metis.Sample import DirectorySample
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser

job_tag = "MET_v1"
exec_path = "condor_exe.sh"
tar_path = "package.tar.gz"
hadoop_path = "MET"

parser = argparse.ArgumentParser()
parser.add_argument("eras", help = "Which 2017 data eras to consider (B,C,D,E,F)", type=str)
parser.add_argument("weightfile", type=str, help = "root file to use for pileup reweighting")
#parser.add_argument("--reweight", help = "(Re)derive pileup weights", action="store_true")
args = parser.parse_args()

eras = args.eras.split(",")


data = {"B" : ["/DoubleEG_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"C" : ["/DoubleEG_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"D" : ["/DoubleEG_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"E": ["/DoubleMuon_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleEG_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"F" : ["/DoubleEG_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"]}

# mc "name" : [[samples], xsec(*bf*kfac), nEvents]
# TO-DO: figure out MC normalization
mc = {#"Drell-Yan" : [["DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/", "DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 6025.2, 212922560],
	"WW" : [["/WW_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 63.21, 7547722],
	"WZ" : [["/WZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 22.82, 3928630],
}

#mc = 

basepath = "/hadoop/cms/store/user/smay/ProjectMetis"
total_summary = {}
while True:
  allcomplete = True
  for key, info in mc.iteritems():
    for set in info[0]:
      sample = DirectorySample(dataset = set, location = basepath + set)
      job_args = "%s %d %.12f" % (args.weightfile, 1, info[1]/info[2])
      task = CondorTask(
              sample = sample,
              open_dataset = False,
              flush = True,
              files_per_output = 10,
              output_name = "Zll_histograms.root",
              tag = job_tag,
              cmssw_version = "CMSSW_9_2_1", # doesn't do anything
              arguments = job_args,
              executable = exec_path,
              tarfile = tar_path,
              condor_submit_params = {"sites" : "T2_US_UCSD"},
              special_dir = hadoop_path
              )
      task.process()
      allcomplete = allcomplete and task.complete()
      total_summary[set] = task.get_task_summary()
      if allcomplete:
	print ""
	print "Job={} finished".format(job_tag)
	print ""
	break   
 
  for era in eras:
    for set in data[era]:
      if args.weightfile != "none": # we already made histos for data
        continue
      sample = DirectorySample(dataset = set, location = basepath + set)
      #print(sample.get_files())
      job_args = 'none 1 1'
      task = CondorTask(
	      sample = sample,
	      open_dataset = False,
	      flush = True,
	      files_per_output = 25,
	      output_name = "Zll_histograms.root",
	      tag = job_tag,
	      cmssw_version = "CMSSW_9_2_1", # doesn't do anything
	      arguments = job_args,
	      executable = exec_path,
	      tarfile = tar_path,
	      condor_submit_params = {"sites" : "T2_US_UCSD"},
	      special_dir = hadoop_path
	      )
      task.process()
      allcomplete = allcomplete and task.complete()
      total_summary[set] = task.get_task_summary()
      if allcomplete:
	print ""
	print "Job={} finished".format(job_tag)
	print ""
	break

  StatsParser(data=total_summary, webdir="~/public_html/dump/Zll_MetStudies/").do()
  os.system("chmod -R 755 ~/public_html/dump/Zll_MetStudies")
  print "Sleeping 300 seconds ..."
  time.sleep(300)
