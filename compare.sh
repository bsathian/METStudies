source ~/Utilities/./ShellFunctions.sh

ERAS=$1
REWEIGHT="pileupReweightsMC_${ERAS}.root"

python BatchSubmit/ducks.py $ERAS "none"

python add_histograms.py $ERAS

DATA_HISTOGRAMS="histograms/Zll_histograms_"$ERAS".root"
MC_HISTOGRAMS="histograms/Zll_histograms_MC_"$ERAS".root"
root -l -b -q "makeWeightHisto_noconf.C+(${REWEIGHT}, ${DATA_HISTOGRAMS}, ${MC_HISTOGRAMS}, 'hNVtx', 'hNVtx', 'pileupReweight')"

python BatchSubmit/ducks.py $ERAS $REWEIGHT

python add_histograms.py $ERAS

Plots/makePlots $ERAS
