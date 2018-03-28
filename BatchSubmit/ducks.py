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
mc = {"Drell-Yan" : [["/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/", "/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 7181.0, 212922560.0],
	"WW" : [["/WW_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 63.21, 7547722.0],
	"WZ" : [["/WZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 22.82, 3928630.0],
	"ZZ" : [["/ZZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 10.32, 1949768.0],
	"WWW": [["/WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.286, 240000.0],
	"WZZ": [["/WZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.05565, 250000.0],
	"WWZ": [["/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.1651, 250000.0],
	"ZZZ": [["/ZZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.01398, 250000.0],
	"ST_s" : [["/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 3.74, 9472619.0],
	"ST_t_top" : [["/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 136.02, 5841455.0],
	"ST_t_antitop" : [["/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 80.95, 3891190.0],
	"ST_tW_top": [["/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 34.91, 7558006.0],
	"ST_tW_antitop": [["/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 34.91, 6620324.0],
	"TTJets": [["/TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 72.1, 153596015.0], 
}

basepath = "/hadoop/cms/store/user/smay/ProjectMetis"
total_summary = {}
while True:
  all_jobs_done = True
  allcomplete = True
  for key, info in mc.iteritems():
    for set in info[0]:
      sample = DirectorySample(dataset = set, location = basepath + set)
      job_args = "%s %d %.12f" % (args.weightfile, 1, (info[1]*1000.0)/info[2])
      task = CondorTask(
              sample = sample,
              open_dataset = False,
              flush = True,
              files_per_output = 5,
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
      if not task.complete():
        all_jobs_done = False
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
	      files_per_output = 5,
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
      if not task.complete():
        all_jobs_done = False
      total_summary[set] = task.get_task_summary()
      if allcomplete:
	print ""
	print "Job={} finished".format(job_tag)
	print ""
	break

  if all_jobs_done:
    print ""
    print "All jobs are finished."
    print ""
    break
  StatsParser(data=total_summary, webdir="~/public_html/dump/Zll_MetStudies/").do()
  os.system("chmod -R 755 ~/public_html/dump/Zll_MetStudies")
  print "Sleeping 300 seconds ..."
  time.sleep(300)
