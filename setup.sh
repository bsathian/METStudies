export SCRAM_ARCH=slc6_amd64_gcc630   # or whatever scram_arch you need for your desired CMSSW release
export CMSSW_VERSION=CMSSW_9_4_0
source /cvmfs/cms.cern.ch/cmsset_default.sh
cd /cvmfs/cms.cern.ch/$SCRAM_ARCH/cms/cmssw/$CMSSW_VERSION/src
eval `scramv1 runtime -sh`
cd -

cd ~/ProjectMetis/
source setup.sh
cd ~/Commissioning2017/Commissioning2017_MET/

source ~/Utilities/ShellFunctions.sh
export -f addHistos
