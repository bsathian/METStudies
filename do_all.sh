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
#cd Looper
#make
#cd ..
#cp Looper/analyze .

#rm -rf /hadoop/cms/store/user/smay/MET/*
#cp -ra Looper/jetCorrections/ . 
#tar -czf BatchSubmit/package.tar.gz analyze Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON_snt.txt Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_snt.txt pileupReweight*.root jetCorrections CORE/
#cd BatchSubmit
#rm -rf tasks/
#python ducks.py

#cd ..
#python add_histograms.py "B" --skip_mc
#python add_histograms.py "C" --skip_mc
#python add_histograms.py "D,E" --skip_mc
#python add_histograms.py "F" --skip_mc
#python add_histograms.py "All" --skip_data

# Plots #
cd Plots
./makePlots "B" "4.80"
./makePlots "C" "9.76"
./makePlots "D,E" "13.74"
./makePlots "F" "13.5"
