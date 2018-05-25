import sys, os
import time
import itertools
import numpy

import argparse

from metis.Sample import DirectorySample
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser

exec_path = "condor_exe.sh"
tar_path = "package.tar.gz"
hadoop_path = "MET"

# Don't need to parse args anymore, take care of PU reweighting bookkeeping in analyze.cpp

parser = argparse.ArgumentParser()
#parser.add_argument("eras", help = "Which 2017 data eras to consider (B,C,D,E,F)", type=str)
#parser.add_argument("weightfile", type=str, help = "root file to use for pileup reweighting")
parser.add_argument("--reweight", help = "(Re)derive pileup weights", action="store_true")
args = parser.parse_args()

#job_tag = "MET_v1" + args.eras
job_tag = "MET_v6"

eras = "B,C,D,E,F"
eras = eras.split(",")

data = {"B" : ["/DoubleEG_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"C" : ["/DoubleEG_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"D" : ["/DoubleEG_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"E": ["/DoubleMuon_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleEG_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"], 
	"F" : ["/DoubleEG_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/", "/DoubleMuon_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands/"]}

mc = {"Drell-Yan" : [["/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/", "/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 7181.0, 212922560.0, 0.161, 1],
	"WW" : [["/WW_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 63.21, 7547722.0, 0.0, 5],
	"WZ" : [["/WZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 22.82, 3928630.0, 0.0, 1],
	"ZZ" : [["/ZZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 10.32, 1949768.0, 0.0, 1],
	"WWW": [["/WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.286, 240000.0, 0.062, 5],
	"WZZ": [["/WZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.05565, 250000.0, 0.060, 1],
	"WWZ": [["/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.1651, 250000.0, 0.057, 1],
	"ZZZ": [["/ZZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 0.01398, 250000.0, 0.073, 1],
	"ST_s" : [["/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 3.74, 9472619.0, 0.188, 5],
	"ST_t_top" : [["/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 136.02, 5841455.0, 0.0, 5],
	"ST_t_antitop" : [["/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 80.95, 3891190.0, 0.0, 5],
	"ST_tW_top": [["/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 34.91, 7558006.0, 0.0, 5],
	"ST_tW_antitop": [["/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 34.91, 6620324.0, 0.0, 5],
	"TTJets": [["/TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands/"], 831.76, 153596015.0, 0.314, 5], 
}

basepath = "/hadoop/cms/store/user/smay/ProjectMetis"
total_summary = {}
while True:
  all_jobs_done = True
  for key, info in mc.iteritems():
    for set in info[0]:
      #if args.weightfile == "none" and (not args.reweight or eras[0] != "MC") : # only if you've already made unweighted MC histograms for nvtx reweighting
      #  continue
      sample = DirectorySample(dataset = set, location = basepath + set)
      if not args.reweight:
        job_args = "%s %d %.12f" % ("Reweight", 1, (info[1]*1000.0)/(info[2] * (1 - (2*info[3]))))
	#output_name = "Zll_histograms_" + args.eras + ".root"
        output_name = "Zll_histograms.root"
      else:
        job_args = "%s %d %.12f" % ("none", 2, (info[1]*1000.0)/(info[2] * (1 - (2*info[3]))))
	output_name = "Zll_histograms_All.root"
      task = CondorTask(
              sample = sample,
              open_dataset = False,
              flush = True,
              files_per_output = info[4],
              output_name = output_name,
              tag = job_tag,
              cmssw_version = "CMSSW_9_2_1", # doesn't do anything
              arguments = job_args,
              executable = exec_path,
              tarfile = tar_path,
              condor_submit_params = {"sites" : "T2_US_UCSD"},
              special_dir = hadoop_path
              )
      task.process()
      if not task.complete():
        print("Job %s still running." % job_tag)
        all_jobs_done = False
      total_summary[set] = task.get_task_summary()
      if task.complete():
	print ""
	print "Job={} finished".format(job_tag)
	print ""
 
  for era in eras:
    if era == "MC":
      continue
    for set in data[era]:
      #if args.weightfile != "none" and not args.reweight: # we already made histos for data
      #  continue
      sample = DirectorySample(dataset = set, location = basepath + set)
      #print(sample.get_files())
      if not args.reweight:
        job_args = 'none 1 1'
      else:
        job_args = 'none 2 1'
      task = CondorTask(
	      sample = sample,
	      open_dataset = False,
	      flush = True,
	      files_per_output = 1,
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
      if not task.complete():
        print("Job %s still running." % job_tag)
        all_jobs_done = False
      total_summary[set] = task.get_task_summary()
      if task.complete():
	print ""
	print "Job={} finished".format(job_tag)
	print ""

  if all_jobs_done:
    print ""
    print "All jobs are finished."
    print ""
    break
  #StatsParser(data=total_summary, webdir="~/public_html/dump/Zll_MetStudies/").do()
  #os.system("chmod -R 755 ~/public_html/dump/Zll_MetStudies")
  print "Sleeping 300 seconds ..."
  time.sleep(300)
