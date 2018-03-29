python add_histograms.py "B"
root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_B.root", "histograms/Zll_histograms_B.root", "histograms/Zll_histograms_MC_noreweight.root", "hNVtx", "hNVtx", "pileupReweight")'

python add_histograms.py "C,D,E"
root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_C,D,E.root", "histograms/Zll_histograms_C,D,E.root", "histograms/Zll_histograms_MC_noreweight.root", "hNVtx", "hNVtx", "pileupReweight")'

python add_histograms.py "F"
root -l -b -q 'makeWeightHisto_noconf.C+("pileupReweightsMC_F.root", "histograms/Zll_histograms_F.root", "histograms/Zll_histograms_MC_noreweight.root", "hNVtx", "hNVtx", "pileupReweight")'
