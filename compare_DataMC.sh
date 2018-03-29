echo " "
echo "[wrapper] adding histograms and making PU reweight histograms for Run B"
echo " "

python add_histograms.py "B"
root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_B.root", "histograms/Zll_histograms_B.root", "histograms/Zll_histograms_MC_noreweight.root", "hNVtx", "hNVtx", "pileupReweight")'

echo " "
echo "[wrapper] adding histograms and making PU reweight histograms for Runs C,D,E"
echo " "

python add_histograms.py "C,D,E"
root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_C,D,E.root", "histograms/Zll_histograms_C,D,E.root", "histograms/Zll_histograms_MC_noreweight.root", "hNVtx", "hNVtx", "pileupReweight")'

echo " "
echo "[wrapper] adding histograms and making PU reweight histograms for Run F"
echo " "

python add_histograms.py "F"
root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_F.root", "histograms/Zll_histograms_F.root", "histograms/Zll_histograms_MC_noreweight.root", "hNVtx", "hNVtx", "pileupReweight")'

echo " "
echo "[wrapper] submitting jobs for MC"
echo " "

python BatchSubmit/ducks.py "B" "pileupReweightsMC_B.root" &
python BatchSubmit/ducks.py "C,D,E" "pileupReweightsMC_C,D,E.root" &
python BatchSubmit/ducks.py "F" "pileupReweightsMC_F.root" &

wait

echo " "
echo "[wrapper] Done analyzing MC"
echo "[wrapper] Making plots"
echo " "

Plots/makePlots "B" "4.8"
Plots/makePlots "C,D,E" "23.5"
Plots/makePlots "F" "10.4"
