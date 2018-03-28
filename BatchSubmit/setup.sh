echo "Running setup script"

cd ~/ProjectMetis
#source setup.sh
cd ~/Commissioning2017/Commissioning2017_MET
cp Looper/analyze analyze
tar -czf BatchSubmit/package.tar.gz analyze Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON_snt.txt Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_snt.txt pileupReweight*.root jetCorrections CORE/ 
cd BatchSubmit
