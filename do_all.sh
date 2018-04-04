source setup.sh

# Fill nvtx histograms to derive pileup weights #
#cd BatchSubmit
#rm -rf tasks
#cd ..
#cp Looper/analyze analyze
#tar -czf BatchSubmit/package.tar.gz analyze Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON_snt.txt Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_snt.txt pileupReweight*.root jetCorrections CORE/
#cd BatchSubmit
#python ducks.py "MC" "none" --reweight &
#sleep 10
#python ducks.py "B" "none" --reweight &
#sleep 10
#python ducks.py "C,D,E" "none" --reweight &
#sleep 10
#python ducks.py "F" "none" --reweight &
#wait
#cd ..

# Derive pileup weights #
#python add_histograms.py "All" --skip_data
#python add_histograms.py "B" --skip_mc
#python add_histograms.py "C,D,E" --skip_mc
#python add_histograms.py "F" --skip_mc

#root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_B.root", "histograms/Zll_histograms_B.root", "histograms/Zll_histograms_MC_All.root", "hNVtx", "hNVtx", "pileupReweight")'
#root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_C,D,E.root", "histograms/Zll_histograms_C,D,E.root", "histograms/Zll_histograms_MC_All.root", "hNVtx", "hNVtx", "pileupReweight")'
#root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_F.root", "histograms/Zll_histograms_F.root", "histograms/Zll_histograms_MC_All.root", "hNVtx", "hNVtx", "pileupReweight")'


# Main analysis #
cd Looper
make
cd ..
cp Looper/analyze .

rm -rf /hadoop/cms/store/user/smay/MET/*
tar -czf BatchSubmit/package.tar.gz analyze Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON_snt.txt Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_snt.txt pileupReweight*.root jetCorrections CORE/
cd BatchSubmit
rm -rf tasks/
python ducks.py "B" "pileupReweightsMC_B.root"
rm -rf tasks/
python ducks.py "C,D,E" "pileupReweightsMC_C,D,E.root"
rm -rf tasks/
python ducks.py "F" "pileupReweightsMC_F.root"

python add_histograms.py "B"
python add_histograms.py "C,D,E"
python add_histograms.py "F"

# Plots #
cd Plots
./makePlots "B" "4.8"
./makePlots "C,D,E" "23.5"
./makePlots "F" "13.5"
