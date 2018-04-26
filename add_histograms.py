import sys, os
import time
import itertools
import numpy
import glob

os.chdir("histograms")
sys.path.append("~/Utilities")

import argparse
parser = argparse.ArgumentParser()
parser.add_argument("eras", help = "Which 2017 data eras to consider (B,C,D,E,F)", type=str)
parser.add_argument("--skip_data", action="store_true")
parser.add_argument("--skip_mc"  , action="store_true")
args = parser.parse_args()
eras = args.eras.split(",")

doData = True
doMC = True
if args.skip_data:
  doData = False
if args.skip_mc:
  doMC = False

tag = "MET_v3"

data = {"B" : ["DoubleEG_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/", "DoubleMuon_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/"],  
        "C" : ["DoubleEG_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/", "DoubleMuon_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/"],
        "D" : ["DoubleEG_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/", "DoubleMuon_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/"],
	"E" : ["DoubleEG_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/", "DoubleMuon_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/"],
	"F" : ["DoubleEG_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/", "DoubleMuon_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands__" + tag + "/"]}


mc = {	"Drell-Yan" : ["DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/"] ,
	"DiBoson" : ["WW_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "WZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "ZZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/"],
	"TriBoson" : ["WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "WZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "ZZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/"],
	"Top" : ["ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/", "TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands__" + tag + "/"]
}

nPar = 10
basepath = "/hadoop/cms/store/user/smay/MET/"

if (doData):
  intermediate_files = ""
  for era in eras:
    for set in data[era]:
      files = glob.glob(basepath+set+"*.root")
      if len(files) == 0:
	continue
      intermediate_file = "intermediate_" + set.replace("/", "_")
      intermediate_files += intermediate_file + ".root "
      print("addHistos %s %s %d %d" % (intermediate_file, basepath+set+"/Zll_histograms", len(files), nPar))
      os.system("addHistos %s %s %d %d" % (intermediate_file, basepath+set+"/Zll_histograms", len(files), nPar))

  os.system("hadd -fk Zll_histograms_%s %s" % (args.eras + ".root", intermediate_files))

if (doMC):
  process_files = ""
  for key, sets in mc.iteritems():
    intermediate_files = ""
    for set in sets:
      files = glob.glob(basepath+set+"*.root") 
      if len(files) == 0:
	continue
      intermediate_file = "intermediate_" + set.replace("/","_") 
      intermediate_files += intermediate_file + ".root "
      print("addHistos %s %s %d %d" % (intermediate_file, basepath+set+"/Zll_histograms", len(files), nPar))
      os.system("addHistos %s %s %d %d" % (intermediate_file, basepath+set+"/Zll_histograms", len(files), nPar))
    process_file = "Zll_histograms_%s.root" % (key)
    process_files += process_file + " "
    print("hadd -fk %s %s" % (process_file, intermediate_files))
    os.system("hadd -fk %s %s" % (process_file, intermediate_files))

  os.system("hadd -fk Zll_histograms_MC.root %s" % (process_files))
