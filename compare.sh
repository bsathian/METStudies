source ~/Utilities/./ShellFunctions.sh

ERAS=$1
REWEIGHT="pileupReweightsMC_${ERAS}.root"

echo "[wrapper] Submitting first round of jobs to derive PU weights"

cd BatchSubmit
python ducks.py $ERAS "none"
cd ..

echo "[wrapper] Adding histograms"

python add_histograms.py $ERAS

echo "[wrapper] Deriving PU weights"

DATA_HISTOGRAMS="histograms/Zll_histograms_"$ERAS".root"
MC_HISTOGRAMS="histograms/Zll_histograms_MC_"$ERAS".root"
root -l -b -q "makeWeightHisto_noconf.C+(${REWEIGHT}, ${DATA_HISTOGRAMS}, ${MC_HISTOGRAMS}, 'hNVtx', 'hNVtx', 'pileupReweight')"

echo "[wrapper] Submitting second round of jobs for MC with PU reweighting"

python BatchSubmit/ducks.py $ERAS $REWEIGHT

echo "[wrapper] Adding histograms"

python add_histograms.py $ERAS

echo "[wrapper] Making plots"

Plots/makePlots $ERAS "4.8"
