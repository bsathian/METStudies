import sys, os
import time
import itertools
import numpy

import argparse

from metis.Sample import DirectorySample
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser

job_tag = "MET_v1"
exec_path = "condor_exe.sh"
tar_path = "package.tar.gz"
hadoop_path = "MET"

os.system("./setup.sh")

parser = argparse.ArgumentParser()

data = ["DoubleEG_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleEG_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleEG_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleEG_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleEG_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleMuon_Run2017B-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleMuon_Run2017C-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleMuon_Run2017D-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleMuon_Run2017E-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands", "DoubleMuon_Run2017F-17Nov2017-v1_MINIAOD_CMS4_V00-00-06_allPfCands"]

mc = ["ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISummer17MiniAOD-92X_upgrade2017_realistic_v10-v2_MINIAODSIM_CMS4_V00-00-06_allPfCands", "ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISummer17MiniAOD-92X_upgrade2017_realistic_v10-v2_MINIAODSIM_CMS4_V00-00-06_allPfCands", "WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands", "WW_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands", "WZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands", "WZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands", "ZZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands", "ZZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM_CMS4_V00-00-06_allPfCands"]

