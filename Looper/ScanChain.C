#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TH2D.h"

// CMS3
#include "CMS3.cc"
#include "CORE/Base.cc"
#include "CORE/TriggerSelections.cc"
#include "CORE/IsolationTools.cc"
#include "CORE/ElectronSelections.cc"
#include "CORE/MuonSelections.cc"
#include "CORE/Tools/JetCorrector.cc"
#include "CORE/Tools/goodrun.cc"
#include "CORE/MetSelections.cc"
#include "CORE/VertexSelections.cc"

#include "ScanChain.h"

using namespace std;
using namespace tas;

const TString elT = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v";
const TString muT1 = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v";
const TString muT2 = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v";
const TString muT3 = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v";

const int nEtaRegions = 6;
const int nCandCats = 4;
const int nMETVars = 3;

int ScanChain(TChain* chain, TString output_name, vector<TString> vWeightFile, bool puReweight, int selection, double scale1fb, double target_lumi = 1.) {
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  int nHists = puReweight ? vWeightFile.size() : 1; 
  cout << nHists << endl;
  if (puReweight) cout << "puReweight" << endl;
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  TFile* f1 = new TFile(output_name+".root", "RECREATE");
  f1->cd();

  // Pf cand MET, Sum E_T, MET phi for each eta region and pf candidate category
  vector<vector<vector<vector<TH1D*>>>> vhMET = create_met_histograms_vector(nEtaRegions, nCandCats, nHists);

  // MET
  vector<TH1D*> hpfMET = create_histogram_vector("hpfMET", 80, 0, 400, nHists);
  vector<TH1D*> hpfMETraw = create_histogram_vector("hpfMETraw", 80, 0, 400, nHists); 
  vector<TH1D*> hT1CMET = create_histogram_vector("hT1CMET", 80, 0, 400, nHists);
  vector<TH1D*> hZRemovedMET = create_histogram_vector("hZRemovedMET", 80, 0, 400, nHists);
  vector<TH1D*> hZRemovedMETRaw = create_histogram_vector("hZRemovedMETRaw", 80, 0, 400, nHists);
  vector<TH1D*> hMHT = create_histogram_vector("hMHT", 80, 0, 400, nHists);

  // Dilepton Mass
  vector<TH1D*> hDilepMass = create_histogram_vector("hDilepMass", 100, 0, 250, nHists);
  vector<TH1D*> hDilepMassEE = create_histogram_vector("hDilepMassEE", 100, 0, 250, nHists);
  vector<TH1D*> hDilepMassMuMu = create_histogram_vector("hDilepMassMuMu", 100, 0, 250, nHists);

  // Pf Cand pT
  vector<TH1D*> hCCpT = create_histogram_vector("hCCpT", 100, 0, 100, nHists); 
  vector<TH1D*> hPhotonpT = create_histogram_vector("hPhotonpT", 100, 0, 100, nHists); 
  vector<TH1D*> hNeutpT = create_histogram_vector("hNeutpT", 100, 0, 100, nHists); 
  vector<vector<TH1D*>> vhCandpT = {hCCpT, hPhotonpT, hNeutpT};
 
  // Pf Cand eta
  vector<TH1D*> hCCeta = create_histogram_vector("hCCeta", 50, 0, 5, nHists);
  vector<TH1D*> hPhotoneta = create_histogram_vector("hPhotoneta", 50, 0, 5, nHists);
  vector<TH1D*> hNeuteta = create_histogram_vector("hNeuteta", 50, 0, 5, nHists);
  vector<vector<TH1D*>> vhCandeta = {hCCeta, hPhotoneta, hNeuteta};

  // Candidate multiplicity
  vector<TH1D*> hNCands = create_histogram_vector("hNCands", 300, 0, 3000, nHists);
  vector<TH1D*> hNCCands = create_histogram_vector("hNCCands", 300, 0, 3000, nHists);
  vector<TH1D*> hNPCands = create_histogram_vector("hNPCands", 300, 0, 3000, nHists);
  vector<TH1D*> hNNCands = create_histogram_vector("hNNCands", 300, 0, 3000, nHists);

  // Misc
  vector<TH1D*> hSumETEndcapPhotonsUnclustered = create_histogram_vector("hSumETEndcapPhotonsUnclustered", 100, 0, 1000, nHists);
  vector<TH1D*> hSumETEndcapPhotonsClustered = create_histogram_vector("hSumETEndcapPhotonsClustered", 100, 0, 1000, nHists); 

  // Type-1 MET variations
  vector<TH1D*> hRawMETMod = create_histogram_vector("hRawMETMod", 80, 0, 400, nHists);
  vector<TH1D*> hRawMETMod_v2 = create_histogram_vector("hRawMETMod_v2", 80, 0, 400, nHists);  
  vector<TH1D*> hT1CMETMod = create_histogram_vector("hT1CMETMod", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMETMod_v2 = create_histogram_vector("hT1CMETMod_v2", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_NoECJECs_v1 = create_histogram_vector("hT1CMET_NoECJECs_v1", 80, 0, 400, nHists); // no  HE, pT < 30 
  vector<TH1D*> hT1CMET_NoECJECs_v2 = create_histogram_vector("hT1CMET_NoECJECs_v2", 80, 0, 400, nHists); // no  HE, pT < 50
  vector<TH1D*> hT1CMET_NoECJECs_v3 = create_histogram_vector("hT1CMET_NoECJECs_v3", 80, 0, 400, nHists); // use HE, pt < 30
  vector<TH1D*> hT1CMET_NoECJECs_v4 = create_histogram_vector("hT1CMET_NoECJECs_v4", 80, 0, 400, nHists); // use HE, pt < 50

  vector<TH1D*> hT1CMET_NoECJECs_v5 = create_histogram_vector("hT1CMET_NoECJECs_v5", 80, 0, 400, nHists); // JEC pT > 25
  vector<TH1D*> hT1CMET_NoECJECs_v6 = create_histogram_vector("hT1CMET_NoECJECs_v6", 80, 0, 400, nHists); // JEC pT > 75, eta in [2.7, 3.0]
  vector<TH1D*> hT1CMET_NoECJECs_v7 = create_histogram_vector("hT1CMET_NoECJECs_v7", 80, 0, 400, nHists); // JEC pT > 75, eta in [2.5, 3.0]
  vector<TH1D*> hT1CMET_NoECJECs_v8 = create_histogram_vector("hT1CMET_NoECJECs_v8", 80, 0, 400, nHists); // JEC pT > 100, eta in [2.7, 3.0]

  vector<TH1D*> hT1CMET_NoECJets = create_histogram_vector("hT1CMET_NoECJets", 80, 0, 400, nHists); // no Jets (or associated pf cands) with pT < 70, eta in [2.7, 3.0]

  vector<TH1D*> hT1CMET_V6 = create_histogram_vector("hT1CMET_V6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_V8 = create_histogram_vector("hT1CMET_V8", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_V9 = create_histogram_vector("hT1CMET_V9", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMETMod_V6 = create_histogram_vector("hT1CMETMod_V6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMETMod_V8 = create_histogram_vector("hT1CMETMod_V8", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMETMod_V9 = create_histogram_vector("hT1CMETMod_V9", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_NoResiduals = create_histogram_vector("hT1CMET_NoResiduals", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_tightID = create_histogram_vector("hT1CMET_tightID", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_RunFV6 = create_histogram_vector("hT1CMET_RunFV6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_RunFV8b = create_histogram_vector("hT1CMET_RunFV8b", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_RunFV8c = create_histogram_vector("hT1CMET_RunFV8c", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_RunFV8d = create_histogram_vector("hT1CMET_RunFV8d", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_RunFV9 = create_histogram_vector("hT1CMET_RunFV9", 80, 0, 400, nHists);

  vector<TH1D*> hJetPt_RunFV6 = create_histogram_vector("hJetPt_RunFV6", 80, 0, 400, nHists);
  vector<TH1D*> hJetPt_RunFV8b = create_histogram_vector("hJetPt_RunFV8b", 80, 0, 400, nHists);
  vector<TH1D*> hJetPt_RunFV8c = create_histogram_vector("hJetPt_RunFV8c", 80, 0, 400, nHists);
  vector<TH1D*> hJetPt_RunFV8d = create_histogram_vector("hJetPt_RunFV8d", 80, 0, 400, nHists);
  vector<TH1D*> hJetPt_RunFV9 = create_histogram_vector("hJetPt_RunFV9", 80, 0, 400, nHists);

  vector<TH1D*> hJet_Emfrac = create_histogram_vector("hJet_Emfrac", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Emfrac = create_histogram_vector("hJet_Neutral_Emfrac", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Hadfrac = create_histogram_vector("hJet_Neutral_Hadfrac", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Charged_Hadfrac = create_histogram_vector("hJet_Charged_Hadfrac", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Emfrac_hf = create_histogram_vector("hJet_Neutral_Emfrac_hf", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Hadfrac_hf = create_histogram_vector("hJet_Neutral_Hadfrac_hf", 100, 0, 1, nHists);

  vector<TH1D*> hJet_Neutral_Emfrac_central = create_histogram_vector("hJet_Neutral_Emfrac_central", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Hadfrac_central = create_histogram_vector("hJet_Neutral_Hadfrac_central", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Emfrac_forward = create_histogram_vector("hJet_Neutral_Emfrac_forward", 100, 0, 1, nHists);
  vector<TH1D*> hJet_Neutral_Hadfrac_forward = create_histogram_vector("hJet_Neutral_Hadfrac_forward", 100, 0, 1, nHists);

  // 0-1 jet binned MET
  vector<TH1D*> hpfMET_0Jets = create_histogram_vector("hpfMET_0Jets", 80, 0, 400, nHists);
  vector<TH1D*> hpfMET_0Jetsraw = create_histogram_vector("hpfMET_0Jetsraw", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets = create_histogram_vector("hT1CMET_0Jets", 80, 0, 400, nHists);

  vector<TH1D*> hRawMET_0JetsMod = create_histogram_vector("hRawMET_0JetsMod", 80, 0, 400, nHists);
  vector<TH1D*> hRawMET_0JetsMod_v2 = create_histogram_vector("hRawMET_0JetsMod_v2", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0JetsMod = create_histogram_vector("hT1CMET_0JetsMod", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0JetsMod_v2 = create_histogram_vector("hT1CMET_0JetsMod_v2", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v1 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v1", 80, 0, 400, nHists); // no  HE, pT < 30 
  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v2 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v2", 80, 0, 400, nHists); // no  HE, pT < 50
  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v3 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v3", 80, 0, 400, nHists); // use HE, pt < 30
  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v4 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v4", 80, 0, 400, nHists); // use HE, pt < 50

  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v5 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v5", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v6 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v7 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v7", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_NoECJECs_v8 = create_histogram_vector("hT1CMET_0Jets_NoECJECs_v8", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_0Jets_NoResiduals = create_histogram_vector("hT1CMET_0Jets_NoResiduals", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_tightID = create_histogram_vector("hT1CMET_0Jets_tightID", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_0Jets_RunFV6 = create_histogram_vector("hT1CMET_0Jets_RunFV6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_RunFV8b = create_histogram_vector("hT1CMET_0Jets_RunFV8b", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_RunFV8c = create_histogram_vector("hT1CMET_0Jets_RunFV8c", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_RunFV8d = create_histogram_vector("hT1CMET_0Jets_RunFV8d", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_0Jets_RunFV9 = create_histogram_vector("hT1CMET_0Jets_RunFV9", 80, 0, 400, nHists);

  vector<TH1D*> hpfMET_1pJets = create_histogram_vector("hpfMET_1pJets", 80, 0, 400, nHists);
  vector<TH1D*> hpfMET_1pJetsraw = create_histogram_vector("hpfMET_1pJetsraw", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets = create_histogram_vector("hT1CMET_1pJets", 80, 0, 400, nHists);

  vector<TH1D*> hRawMET_1pJetsMod = create_histogram_vector("hRawMET_1pJetsMod", 80, 0, 400, nHists);
  vector<TH1D*> hRawMET_1pJetsMod_v2 = create_histogram_vector("hRawMET_1pJetsMod_v2", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJetsMod = create_histogram_vector("hT1CMET_1pJetsMod", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJetsMod_v2 = create_histogram_vector("hT1CMET_1pJetsMod_v2", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v1 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v1", 80, 0, 400, nHists); // no  HE, pT < 30 
  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v2 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v2", 80, 0, 400, nHists); // no  HE, pT < 50
  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v3 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v3", 80, 0, 400, nHists); // use HE, pt < 30
  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v4 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v4", 80, 0, 400, nHists); // use HE, pt < 50

  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v5 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v5", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v6 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v7 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v7", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_NoECJECs_v8 = create_histogram_vector("hT1CMET_1pJets_NoECJECs_v8", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_1pJets_NoResiduals = create_histogram_vector("hT1CMET_1pJets_NoResiduals", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_tightID = create_histogram_vector("hT1CMET_1pJets_tightID", 80, 0, 400, nHists);

  vector<TH1D*> hT1CMET_1pJets_RunFV6 = create_histogram_vector("hT1CMET_1pJets_RunFV6", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_RunFV8b = create_histogram_vector("hT1CMET_1pJets_RunFV8b", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_RunFV8c = create_histogram_vector("hT1CMET_1pJets_RunFV8c", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_RunFV8d = create_histogram_vector("hT1CMET_1pJets_RunFV8d", 80, 0, 400, nHists);
  vector<TH1D*> hT1CMET_1pJets_RunFV9 = create_histogram_vector("hT1CMET_1pJets_RunFV9", 80, 0, 400, nHists);

  // Jets
  vector<TH1D*> hLeadJetPt = create_histogram_vector("hLeadJetPt", 100, 0, 500, nHists);
  vector<TH1D*> hLeadJetEta = create_histogram_vector("hLeadJetEta", 50, 0, 5, nHists);

  vector<TH1D*> hJetPt = create_histogram_vector("hJetPt", 100, 0, 500, nHists);
  vector<TH1D*> hJetEta = create_histogram_vector("hJetEta", 50, 0, 5, nHists);  

  vector<TH2D*> hJetEtaPhi = create_2Dhistogram_vector("hJetEtaPhi", 50, -5, 5, 50, -3.142, 3.142, nHists);
  vector<TH2D*> hJetPtEta = create_2Dhistogram_vector("hJetPtEta", 50, 0, 500, 50, -5, 5, nHists);
  vector<TH2D*> hJetPtPhi = create_2Dhistogram_vector("hJetPtPhi", 50, 0, 500, 50, -3.142, 3.142, nHists);


  // Scale & Resolution
  //vector<double> resolution_bins = {0, 25, 50, 75, 100, 150, 200, 250, 300, 400};

  vector<TH1D*> hZpT_V6 = create_histogram_vector("hZpT_V6", 100, 0, 400, nHists);
  vector<TH1D*> hUPara_V6 = create_histogram_vector("hUPara_V6", 200, -400, 400, nHists);
  vector<TH1D*> hUPerp_V6 = create_histogram_vector("hUPerp_V6", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqT_V6 = create_histogram_vector("hUParaPlusqT_V6", 100, -200, 200, nHists);
  //vector<TH1D*> hResponse = create_histogram_vector("hResponse", 
  //vector<TH1D*> hRes = create_histogram_vector("hRes", 100, -1, 1, nHists);  

  vector<double> resolution_bins = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 400};
  vector<vector<TH1D*>> hResPara_V6;
  vector<vector<TH1D*>> hResPerp_V6;
  vector<vector<TH1D*>> hResponse_V6;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponse_V6.push_back(create_histogram_vector("hResponse_V6" + to_string(i), 100, -10, 10, nHists));
    hResPara_V6.push_back(create_histogram_vector("hResPara_V6" + to_string(i), 200, -400, 400, nHists));
    hResPerp_V6.push_back(create_histogram_vector("hResPerp_V6" + to_string(i), 100, -200, 200, nHists));
  }

  vector<TH1D*> hUParaMod_V6 = create_histogram_vector("hUParaMod_V6", 200, -400, 400, nHists);
  vector<TH1D*> hUPerpMod_V6 = create_histogram_vector("hUPerpMod_V6", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqTMod_V6 = create_histogram_vector("hUParaPlusqTMod_V6", 100, -200, 200, nHists);
  //vector<TH1D*> hResponse = create_histogram_vector("hResponse",   

  vector<vector<TH1D*>> hResParaMod_V6;
  vector<vector<TH1D*>> hResPerpMod_V6;
  vector<vector<TH1D*>> hResponseMod_V6;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponseMod_V6.push_back(create_histogram_vector("hResponseMod_V6" + to_string(i), 100, -10, 10, nHists));
    hResParaMod_V6.push_back(create_histogram_vector("hResParaMod_V6" + to_string(i), 200, -400, 400, nHists));
    hResPerpMod_V6.push_back(create_histogram_vector("hResPerpMod_V6" + to_string(i), 100, -200, 200, nHists));
  }


  vector<TH1D*> hZpT_V8 = create_histogram_vector("hZpT_V8", 100, 0, 400, nHists);
  vector<TH1D*> hUPara_V8 = create_histogram_vector("hUPara_V8", 200, -400, 400, nHists);
  vector<TH1D*> hUPerp_V8 = create_histogram_vector("hUPerp_V8", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqT_V8 = create_histogram_vector("hUParaPlusqT_V8", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqT_highqT_V8 = create_histogram_vector("hUParaPlusqT_highqT_V8", 100, -200, 200, nHists);
  //vector<TH1D*> hResponse = create_histogram_vector("hResponse", 
  //vector<TH1D*> hRes = create_histogram_vector("hRes", 100, -1, 1, nHists);  

  vector<vector<TH1D*>> hResPara_V8;
  vector<vector<TH1D*>> hResPerp_V8;
  vector<vector<TH1D*>> hResponse_V8;
  vector<vector<TH1D*>> hResponseEE_V8;
  vector<vector<TH1D*>> hResponseMM_V8;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponse_V8.push_back(create_histogram_vector("hResponse_V8" + to_string(i), 100, -10, 10, nHists));
    hResponseEE_V8.push_back(create_histogram_vector("hResponseEE_V8" + to_string(i), 100, -10, 10, nHists));
    hResponseMM_V8.push_back(create_histogram_vector("hResponseMM_V8" + to_string(i), 100, -10, 10, nHists)); 
    hResPara_V8.push_back(create_histogram_vector("hResPara_V8" + to_string(i), 200, -400, 400, nHists));
    hResPerp_V8.push_back(create_histogram_vector("hResPerp_V8" + to_string(i), 100, -200, 200, nHists));
  }

  vector<TH1D*> hUParaMod_V8 = create_histogram_vector("hUParaMod_V8", 200, -400, 400, nHists);
  vector<TH1D*> hUPerpMod_V8 = create_histogram_vector("hUPerpMod_V8", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqTMod_V8 = create_histogram_vector("hUParaPlusqTMod_V8", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqTMod_highqT_V8 = create_histogram_vector("hUParaPlusqTMod_highqT_V8", 100, -200, 200, nHists);
  //vector<TH1D*> hResponse = create_histogram_vector("hResponse",   

  vector<vector<TH1D*>> hResParaMod_V8;
  vector<vector<TH1D*>> hResPerpMod_V8;
  vector<vector<TH1D*>> hResponseMod_V8;
  vector<vector<TH1D*>> hResponseModEE_V8;
  vector<vector<TH1D*>> hResponseModMM_V8;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponseMod_V8.push_back(create_histogram_vector("hResponseMod_V8" + to_string(i), 100, -10, 10, nHists));
    hResponseModEE_V8.push_back(create_histogram_vector("hResponseModEE_V8" + to_string(i), 100, -10, 10, nHists));
    hResponseModMM_V8.push_back(create_histogram_vector("hResponseModMM_V8" + to_string(i), 100, -10, 10, nHists));
    hResParaMod_V8.push_back(create_histogram_vector("hResParaMod_V8" + to_string(i), 200, -400, 400, nHists));
    hResPerpMod_V8.push_back(create_histogram_vector("hResPerpMod_V8" + to_string(i), 100, -200, 200, nHists));
  }

  vector<TH1D*> hZpT_V9 = create_histogram_vector("hZpT_V9", 100, 0, 400, nHists);
  vector<TH1D*> hUPara_V9 = create_histogram_vector("hUPara_V9", 200, -400, 400, nHists);
  vector<TH1D*> hUPerp_V9 = create_histogram_vector("hUPerp_V9", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqT_V9 = create_histogram_vector("hUParaPlusqT_V9", 100, -200, 200, nHists);
  //vector<TH1D*> hResponse = create_histogram_vector("hResponse", 
  //vector<TH1D*> hRes = create_histogram_vector("hRes", 100, -1, 1, nHists);  

  vector<vector<TH1D*>> hResPara_V9;
  vector<vector<TH1D*>> hResPerp_V9;
  vector<vector<TH1D*>> hResponse_V9;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponse_V9.push_back(create_histogram_vector("hResponse_V9" + to_string(i), 100, -10, 10, nHists));
    hResPara_V9.push_back(create_histogram_vector("hResPara_V9" + to_string(i), 200, -400, 400, nHists));
    hResPerp_V9.push_back(create_histogram_vector("hResPerp_V9" + to_string(i), 100, -200, 200, nHists));
  }

  vector<TH1D*> hUParaMod_V9 = create_histogram_vector("hUParaMod_V9", 200, -400, 400, nHists);
  vector<TH1D*> hUPerpMod_V9 = create_histogram_vector("hUPerpMod_V9", 100, -200, 200, nHists);
  vector<TH1D*> hUParaPlusqTMod_V9 = create_histogram_vector("hUParaPlusqTMod_V9", 100, -200, 200, nHists);
  //vector<TH1D*> hResponse = create_histogram_vector("hResponse",   

  vector<vector<TH1D*>> hResParaMod_V9;
  vector<vector<TH1D*>> hResPerpMod_V9;
  vector<vector<TH1D*>> hResponseMod_V9;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponseMod_V9.push_back(create_histogram_vector("hResponseMod_V9" + to_string(i), 100, -10, 10, nHists));
    hResParaMod_V9.push_back(create_histogram_vector("hResParaMod_V9" + to_string(i), 200, -400, 400, nHists));
    hResPerpMod_V9.push_back(create_histogram_vector("hResPerpMod_V9" + to_string(i), 100, -200, 200, nHists));
  }
 


  double vtxBins[] = {0,5,10,15,20,25,30,35,40,45,100};
  int nVtxBins = (sizeof(vtxBins)/sizeof(vtxBins[0]))-1;
  vector<TH1D*> hNVtx;
  for (int i = 0; i < nHists; i++) { 
   TString name = "hNVtx"+to_string(i);
   hNVtx.push_back(new TH1D(name,"", nVtxBins, vtxBins));
   hNVtx[i]->Sumw2();
  }

  vector<TH1D*> hPhotonpTEndcap = create_histogram_vector("hPhotonpTEndcap", 100, 0, 100, nHists);

  vector<TH1D*> hNJets = create_histogram_vector("hNJets", 16, -0.5, 15.5, nHists);

  vector<TFile*> fWeights;
  vector<TH1D*> hWeights;
  if (puReweight) {
    for (int i = 0; i < nHists; i++) {
      fWeights.push_back(new TFile(vWeightFile[i], "READ"));
      hWeights.push_back((TH1D*)fWeights[i]->Get("pileupReweight"));
    }
  } 

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {
    TString currentFileName = currentFile->GetTitle();
    TFile file(currentFileName);
    TTree *tree = (TTree*)file.Get("Events");
    TTreeCache::SetLearnEntries(10);
    tree->SetCacheSize(128*1024*1024);
    cms3.Init(tree);
    if (nEventsTotal >= nEventsChain) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();

    const char* json_file;
    if (currentFileName.Contains("2016")) {
      json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_snt.txt";
      set_goodrun_file(json_file);
    }
    else {
      json_file = "Cert_294927-306462_13TeV_PromptReco_Collisions17_JSON_snt.txt"; // FIXME: update to rereco json file
      set_goodrun_file(json_file);
    }

    for (unsigned int event = 0; event < nEventsTree; ++event) {
      if (nEventsTotal >= nEventsChain) continue;
      tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;
      CMS3::progress( nEventsTotal, nEventsChain );
 
      if (selection == 3) {
        cout << endl << "Event number " << event << endl;
        cout << "Type-1 MET: " << t1CMET(currentFileName).pt() << endl;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets = correctedJets(currentFileName, "V8"); 
        for (int i = 0; i < vCorrectedJets.size(); i++)
          cout << "Jet number " << i << ": " << vCorrectedJets[i].pt() << endl;
      }

      // Check golden json 
      if (evt_isRealData()) {
        if (!goodrun(evt_run(), evt_lumiBlock())) {  continue; }
      }

      // Check triggers, categorize as ee/uu
      bool isElEvt;
      int id1(-1), id2(-1);
      if (cms3.evt_isRealData()) {
        if (!(passHLTTriggerPattern(elT) ||  passHLTTriggerPattern(muT1) || passHLTTriggerPattern(muT2) || passHLTTriggerPattern(muT3))) continue;
        if (passHLTTriggerPattern(elT))                                          isElEvt = true;
        else if (passHLTTriggerPattern(muT1) || passHLTTriggerPattern(muT2) || passHLTTriggerPattern(muT3))      isElEvt = false;
      }

      else {
        if (lepsPassPOG(true, id1, id2))
          isElEvt = true;
        else if (lepsPassPOG(false, id1, id2))
          isElEvt = false;
        else continue;
      }

      // Check filters
      if (firstGoodVertex() == -1)		continue;
      if (!filt_goodVertices())          	continue;
      if (!filt_globalTightHalo2016())   	continue;
      if (!filt_hbheNoise())             	continue;
      if (!filt_hbheNoiseIso())          	continue; 
      if (!filt_ecalTP())			continue;
      if (!filt_eeBadSc())			continue;

      // Check if leps pass POG IDs
      if (!lepsPassPOG(isElEvt, id1, id2)) 						continue;

      if (selection == 2) { // only fill hNVtx for deriving pileup weights
        if (!lepsPassOtherLenient(isElEvt, id1, id2))                                   continue;
	double ZpT = -1;
	double dMass = dilepMass(isElEvt, id1, id2, ZpT);
	if (dMass < 81 || dMass > 101)                                                  continue;
 	double weight = 1;
	int nvtx = evt_nvtxs();

	// Weight further if MC
	if (!cms3.evt_isRealData()) {
	  weight *= scale1fb * target_lumi *sgn(genps_weight());
	}
        fill_histograms(hNVtx, nvtx, {weight});
	//hNVtx->Fill(nvtx, weight);
	continue;		
      }

      // Check pT/eta requirements
      if (selection == 1) { // regular Z->ll
        if (!lepsPassOtherLenient(isElEvt, id1, id2)) 					continue;
      }
      else if (selection == 0) { // Z-Removed MET selection
        if (!lepsPassOther(isElEvt, id1, id2)) 						continue;
      }

      // Grab pu weights
      vector<double> weight(nHists, 1);
      int nvtx = evt_nvtxs();
      if (puReweight) {
        for (int i = 0; i < nHists; i++) {
	  weight[i] *= hWeights[i]->GetBinContent(hWeights[i]->FindBin(nvtx));
        }
      }
      // Weight further if MC
      if (!cms3.evt_isRealData()) {
	for (int i = 0; i < nHists; i++)
          weight[i] *= scale1fb * target_lumi *sgn(genps_weight());
      }

      // Fill dilep mass before cutting on it
      double ZpT = -1;
      double dMass = dilepMass(isElEvt, id1, id2, ZpT);
      fill_histograms(hDilepMass,dMass, weight);
      if (isElEvt)
	fill_histograms(hDilepMassEE,dMass, weight);
      else
	fill_histograms(hDilepMassMuMu,dMass, weight);

      if (selection == 1) { // regular Z->ll
        if (dMass < 81 || dMass > 101)							continue;
      }
      
      else if (selection == 0) { // Z-Removed MET selection
	if (dMass < 71 || dMass > 111)							continue;
        if (ZpT < 200)									continue;
      }

      // Fill Z-Removed MET before cutting on it (if selection == 0)
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET = t1CMET(currentFileName);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_V6 = t1CMET_configurable(currentFileName, "V6", "V6", 0., {0,0}, true);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_V8 = t1CMET_configurable(currentFileName, "V8", "V8", 0., {0,0}, true);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_V9 = t1CMET_configurable(currentFileName, "V9", "V8", 0., {0,0}, true);

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET = fT1CMET_V8;

      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod = t1CMET_noHE(currentFileName, 15., {0., 0.}, false);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v1 = t1CMET_noHE(currentFileName, 30., {2.5, 3.0}, false);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v2 = t1CMET_noHE(currentFileName, 50., {2.5, 3.0}, false);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v3 = t1CMET_noHE(currentFileName, 30., {2.5, 3.0}, true);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v4 = t1CMET_noHE(currentFileName, 50., {2.5, 3.0}, true);

      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v5 = t1CMET_noHE(currentFileName, 25., {0.0,10.0}, true);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v6 = t1CMET_noHE(currentFileName, 75., {2.7,3.0}, true);

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_NoECJets = t1CMET_configurable(currentFileName, "V8", "V8", 0., {0.0, 0.0}, true, true);

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_V6 = t1CMET_configurable(currentFileName, "V6", "V6", 75., {2.7,3.0}, true);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_V8 = t1CMET_configurable(currentFileName, "V8", "V8", 75., {2.7,3.0}, true);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_V9 = t1CMET_configurable(currentFileName, "V9", "V8", 75., {2.7,3.0}, true);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v6 = fT1CMETMod_V8;
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v7 = t1CMET_noHE(currentFileName, 75., {2.5,3.0}, true);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v8 = t1CMET_noHE(currentFileName, 100., {2.7,3.0}, true);

      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_NoResiduals = t1CMET_PartialJECs(currentFileName, true, false);
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_tightID = t1CMET_tightID(currentFileName); 

      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_RunFV6 = t1CMET_version(currentFileName, "V6");
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_RunFV8b = t1CMET_version(currentFileName, "V8b");
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_RunFV8c = t1CMET_version(currentFileName, "V8c");
      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_RunFV8d = t1CMET_version(currentFileName, "V8d");
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_RunFV9 = fT1CMET_V9; 

      double dPhi2(0), dPhiRaw(0);
      if (selection == 0) {
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET = t1CMET(currentFileName);
	double zRemMET = ZRemovedMET(fT1CMET, isElEvt, id1, id2, dPhi2);
	fill_histograms(hZRemovedMET,zRemMET, weight);

	double zRemMETRaw = ZRemovedMETRaw(isElEvt, id1, id2, dPhiRaw);
	fill_histograms(hZRemovedMETRaw,zRemMETRaw, weight);

	if (zRemMET < 100 || zRemMET > 200)						continue;
      }
      // Done with selection, now fill histograms
      fill_histograms(hT1CMET,fT1CMET.pt(), weight);
      //fill_histograms(hT1CMETMod,fT1CMETMod.pt(), weight);

      //fill_histograms(hT1CMET_NoECJECs_v1,fT1CMETMod_v1.pt(), weight);
      //fill_histograms(hT1CMET_NoECJECs_v2,fT1CMETMod_v2.pt(), weight);
      //fill_histograms(hT1CMET_NoECJECs_v3,fT1CMETMod_v3.pt(), weight);
      //fill_histograms(hT1CMET_NoECJECs_v4,fT1CMETMod_v4.pt(), weight);

      //fill_histograms(hT1CMET_NoECJECs_v5,fT1CMETMod_v5.pt(), weight);
      //fill_histograms(hT1CMET_NoECJECs_v6,fT1CMETMod_v6.pt(), weight);
      //fill_histograms(hT1CMET_NoECJECs_v7,fT1CMETMod_v7.pt(), weight);
      //fill_histograms(hT1CMET_NoECJECs_v8,fT1CMETMod_v8.pt(), weight);

      //fill_histograms(hT1CMET_NoResiduals, fT1CMET_NoResiduals.pt(), weight); 
      //fill_histograms(hT1CMET_tightID, fT1CMET_tightID.pt(), weight);

      //fill_histograms(hT1CMET_RunFV6, fT1CMET_RunFV6.pt(), weight);
      //fill_histograms(hT1CMET_RunFV8b, fT1CMET_RunFV8b.pt(), weight);
      //fill_histograms(hT1CMET_RunFV8c, fT1CMET_RunFV8c.pt(), weight);
      //fill_histograms(hT1CMET_RunFV8d, fT1CMET_RunFV8d.pt(), weight); 
      //fill_histograms(hT1CMET_RunFV9, fT1CMET_RunFV9.pt(), weight); 

      fill_histograms(hT1CMET_NoECJets, fT1CMET_NoECJets.pt(), weight);

      fill_histograms(hT1CMET_V6,fT1CMET_V6.pt(), weight);
      fill_histograms(hT1CMET_V8,fT1CMET_V8.pt(), weight);
      fill_histograms(hT1CMET_V9,fT1CMET_V9.pt(), weight);

      fill_histograms(hT1CMETMod_V6,fT1CMETMod_V6.pt(), weight);
      fill_histograms(hT1CMETMod_V8,fT1CMETMod_V8.pt(), weight);
      fill_histograms(hT1CMETMod_V9,fT1CMETMod_V9.pt(), weight);

      fill_histograms(hNVtx,nvtx, weight);
      
      fill_histograms(hpfMET,evt_pfmet(), weight);
      fill_histograms(hpfMETraw,evt_pfmet_raw(), weight);

      int nJet = nJets(isElEvt, id1, id2);
      fill_histograms(hNJets,nJet, weight);

      // Scale and resolution
      // V6
      double u_para_V6, u_perp_V6, u_para_plus_qt_V6;
      double boson_pt_V6 = boson_pT(isElEvt, id1, id2, fT1CMET_V6, u_para_V6, u_perp_V6, u_para_plus_qt_V6);

      double u_para_mod_V6, u_perp_mod_V6, u_para_plus_qt_mod_V6;
      double boson_pt_mod_V6 = boson_pT(isElEvt, id1, id2, fT1CMETMod_V6, u_para_mod_V6, u_perp_mod_V6, u_para_plus_qt_mod_V6);

      int resolution_idx_V6 = find_index(resolution_bins, boson_pt_V6);

      fill_histograms(hZpT_V6, boson_pt_V6, weight);
      fill_histograms(hUPara_V6, u_para_V6, weight);     
      fill_histograms(hUPerp_V6, u_perp_V6, weight);
      fill_histograms(hUParaPlusqT_V6, u_para_plus_qt_V6, weight);

      fill_histograms(hResponse_V6[resolution_idx_V6], -u_para_V6/boson_pt_V6, weight);
      fill_histograms(hResPara_V6[resolution_idx_V6], u_para_V6, weight);
      fill_histograms(hResPerp_V6[resolution_idx_V6], u_perp_V6, weight);

      fill_histograms(hUParaMod_V6, u_para_mod_V6, weight);
      fill_histograms(hUPerpMod_V6, u_perp_mod_V6, weight);
      fill_histograms(hUParaPlusqTMod_V6, u_para_plus_qt_mod_V6, weight);
 
      fill_histograms(hResponseMod_V6[resolution_idx_V6], -u_para_mod_V6/boson_pt_V6, weight);
      fill_histograms(hResParaMod_V6[resolution_idx_V6], u_para_mod_V6, weight);
      fill_histograms(hResPerpMod_V6[resolution_idx_V6], u_perp_mod_V6, weight);

      // V8
      double u_para_V8, u_perp_V8, u_para_plus_qt_V8;
      double boson_pt_V8 = boson_pT(isElEvt, id1, id2, fT1CMET_V8, u_para_V8, u_perp_V8, u_para_plus_qt_V8);

      double u_para_mod_V8, u_perp_mod_V8, u_para_plus_qt_mod_V8;
      double boson_pt_mod_V8 = boson_pT(isElEvt, id1, id2, fT1CMETMod_V8, u_para_mod_V8, u_perp_mod_V8, u_para_plus_qt_mod_V8);

      int resolution_idx_V8 = find_index(resolution_bins, boson_pt_V8);

      fill_histograms(hZpT_V8, boson_pt_V8, weight);
      fill_histograms(hUPara_V8, u_para_V8, weight);
      fill_histograms(hUPerp_V8, u_perp_V8, weight);
      fill_histograms(hUParaPlusqT_V8, u_para_plus_qt_V8, weight);
      if (boson_pt_V8 > 130) fill_histograms(hUParaPlusqT_highqT_V8, u_para_plus_qt_V8, weight);

      fill_histograms(hResponse_V8[resolution_idx_V8], -u_para_V8/boson_pt_V8, weight);
      if (isElEvt) 	fill_histograms(hResponseEE_V8[resolution_idx_V8], -u_para_V8/boson_pt_V8, weight);
      else		fill_histograms(hResponseMM_V8[resolution_idx_V8], -u_para_V8/boson_pt_V8, weight);
      fill_histograms(hResPara_V8[resolution_idx_V8], u_para_V8, weight);
      fill_histograms(hResPerp_V8[resolution_idx_V8], u_perp_V8, weight);

      fill_histograms(hUParaMod_V8, u_para_mod_V8, weight);
      fill_histograms(hUPerpMod_V8, u_perp_mod_V8, weight);
      fill_histograms(hUParaPlusqTMod_V8, u_para_plus_qt_mod_V8, weight);
      if (boson_pt_V8 > 130) fill_histograms(hUParaPlusqTMod_highqT_V8, u_para_plus_qt_mod_V8, weight);

      fill_histograms(hResponseMod_V8[resolution_idx_V8], -u_para_mod_V8/boson_pt_V8, weight);
      if (isElEvt)	fill_histograms(hResponseModEE_V8[resolution_idx_V8], -u_para_mod_V8/boson_pt_V8, weight);
      else 		fill_histograms(hResponseModMM_V8[resolution_idx_V8], -u_para_mod_V8/boson_pt_V8, weight);
      fill_histograms(hResParaMod_V8[resolution_idx_V8], u_para_mod_V8, weight);
      fill_histograms(hResPerpMod_V8[resolution_idx_V8], u_perp_mod_V8, weight);
      
      // V9
      double u_para_V9, u_perp_V9, u_para_plus_qt_V9;
      double boson_pt_V9 = boson_pT(isElEvt, id1, id2, fT1CMET_V9, u_para_V9, u_perp_V9, u_para_plus_qt_V9);

      double u_para_mod_V9, u_perp_mod_V9, u_para_plus_qt_mod_V9;
      double boson_pt_mod_V9 = boson_pT(isElEvt, id1, id2, fT1CMETMod_V9, u_para_mod_V9, u_perp_mod_V9, u_para_plus_qt_mod_V9);

      int resolution_idx_V9 = find_index(resolution_bins, boson_pt_V9);

      fill_histograms(hZpT_V9, boson_pt_V9, weight);
      fill_histograms(hUPara_V9, u_para_V9, weight);
      fill_histograms(hUPerp_V9, u_perp_V9, weight);
      fill_histograms(hUParaPlusqT_V9, u_para_plus_qt_V9, weight);

      fill_histograms(hResponse_V9[resolution_idx_V9], -u_para_V9/boson_pt_V9, weight);
      fill_histograms(hResPara_V9[resolution_idx_V9], u_para_V9, weight);
      fill_histograms(hResPerp_V9[resolution_idx_V9], u_perp_V9, weight);

      fill_histograms(hUParaMod_V9, u_para_mod_V9, weight);
      fill_histograms(hUPerpMod_V9, u_perp_mod_V9, weight);
      fill_histograms(hUParaPlusqTMod_V9, u_para_plus_qt_mod_V9, weight);

      fill_histograms(hResponseMod_V9[resolution_idx_V9], -u_para_mod_V9/boson_pt_V9, weight);
      fill_histograms(hResParaMod_V9[resolution_idx_V9], u_para_mod_V9, weight);
      fill_histograms(hResPerpMod_V9[resolution_idx_V9], u_perp_mod_V9, weight);

      if (nJet == 0) {
        fill_histograms(hT1CMET_0Jets,fT1CMET.pt(), weight);
	//fill_histograms(hT1CMET_0JetsMod,fT1CMETMod.pt(), weight);

	//fill_histograms(hT1CMET_0Jets_NoECJECs_v1,fT1CMETMod_v1.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_NoECJECs_v2,fT1CMETMod_v2.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_NoECJECs_v3,fT1CMETMod_v3.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_NoECJECs_v4,fT1CMETMod_v4.pt(), weight);

	//fill_histograms(hT1CMET_0Jets_RunFV6, fT1CMET_RunFV6.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_RunFV8b, fT1CMET_RunFV8b.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_RunFV8c, fT1CMET_RunFV8c.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_RunFV8d, fT1CMET_RunFV8d.pt(), weight);
	fill_histograms(hT1CMET_0Jets_RunFV9, fT1CMET_RunFV9.pt(), weight);
	
	//fill_histograms(hT1CMET_0Jets_NoECJECs_v5,fT1CMETMod_v5.pt(), weight);
        fill_histograms(hT1CMET_0Jets_NoECJECs_v6,fT1CMETMod_v6.pt(), weight);
        //fill_histograms(hT1CMET_0Jets_NoECJECs_v7,fT1CMETMod_v7.pt(), weight);
        //fill_histograms(hT1CMET_0Jets_NoECJECs_v8,fT1CMETMod_v8.pt(), weight);

	//fill_histograms(hT1CMET_0Jets_NoResiduals, fT1CMET_NoResiduals.pt(), weight);
	//fill_histograms(hT1CMET_0Jets_tightID, fT1CMET_tightID.pt(), weight);

	fill_histograms(hpfMET_0Jets,evt_pfmet(), weight);
	fill_histograms(hpfMET_0Jetsraw,evt_pfmet_raw(), weight);
      }

      else if (nJet >= 1) {
	fill_histograms(hT1CMET_1pJets,fT1CMET.pt(), weight);
        //fill_histograms(hT1CMET_1pJetsMod,fT1CMETMod.pt(), weight);

        //fill_histograms(hT1CMET_1pJets_NoECJECs_v1,fT1CMETMod_v1.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_NoECJECs_v2,fT1CMETMod_v2.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_NoECJECs_v3,fT1CMETMod_v3.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_NoECJECs_v4,fT1CMETMod_v4.pt(), weight);

	//fill_histograms(hT1CMET_1pJets_RunFV6, fT1CMET_RunFV6.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_RunFV8b, fT1CMET_RunFV8b.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_RunFV8c, fT1CMET_RunFV8c.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_RunFV8d, fT1CMET_RunFV8d.pt(), weight);
        fill_histograms(hT1CMET_1pJets_RunFV9, fT1CMET_RunFV9.pt(), weight);

	//fill_histograms(hT1CMET_1pJets_NoECJECs_v5,fT1CMETMod_v5.pt(), weight);
        fill_histograms(hT1CMET_1pJets_NoECJECs_v6,fT1CMETMod_v6.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_NoECJECs_v7,fT1CMETMod_v7.pt(), weight);
        //fill_histograms(hT1CMET_1pJets_NoECJECs_v8,fT1CMETMod_v8.pt(), weight);
     
	//fill_histograms(hT1CMET_1pJets_NoResiduals, fT1CMET_NoResiduals.pt(), weight);
	//fill_histograms(hT1CMET_1pJets_tightID, fT1CMET_tightID.pt(), weight);

        fill_histograms(hpfMET_1pJets,evt_pfmet(), weight);
        fill_histograms(hpfMET_1pJetsraw,evt_pfmet_raw(), weight);
      }

      int nCands = pfcands_p4().size();
      fill_histograms(hNCands,nCands, weight);

      vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >>> vFourVec(nEtaRegions, vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >>(nCandCats));
      vector<vector<double>> vSumET(nEtaRegions, vector<double>(nCandCats, 0.0));

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourVRawMETMod;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourVRawMETMod_v2;

      double sumETPhotonsEndcapClustered(0), sumETPhotonsEndcapUnclustered(0);

      int nCCands(0), nPCands(0), nNCands(0);

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets_V6 = correctedJets(currentFileName, "V6");
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets_V8b = correctedJets(currentFileName, "V8b");
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets_V8c = correctedJets(currentFileName, "V8c");
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets_V8d = correctedJets(currentFileName, "V8d");
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets_V9 = correctedJets(currentFileName, "V9");     
 
      for (int i = 0; i < cms3.pfjets_p4().size(); i++) {
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> jet_p4 = cms3.pfjets_p4().at(i)*cms3.pfjets_undoJEC().at(i);	
	if (!(jet_p4.pt() > 0)) continue;
	if (i == 0) {
	  fill_histograms(hLeadJetPt, jet_p4.pt(), weight);
	  fill_histograms(hLeadJetEta, abs(cms3.pfjets_p4().at(0).eta()), weight); 
	}
	fill_histograms(hJetPt, jet_p4.pt(), weight);
	fill_histograms(hJetEta, abs(cms3.pfjets_p4().at(i).eta()), weight);
        fill_histograms(hJetPt_RunFV6, vCorrectedJets_V6[i].pt(), weight);
	fill_histograms(hJetPt_RunFV8b, vCorrectedJets_V8b[i].pt(), weight);
	fill_histograms(hJetPt_RunFV8c, vCorrectedJets_V8c[i].pt(), weight);
	fill_histograms(hJetPt_RunFV8d, vCorrectedJets_V8d[i].pt(), weight);
	fill_histograms(hJetPt_RunFV9, vCorrectedJets_V9[i].pt(), weight);        
 
	fill_histograms2D(hJetEtaPhi, cms3.pfjets_p4().at(i).eta(), cms3.pfjets_p4().at(i).phi(), weight);
	fill_histograms2D(hJetPtEta, vCorrectedJets_V8d[i].pt(), cms3.pfjets_p4().at(i).eta(), weight);
        fill_histograms2D(hJetPtPhi, vCorrectedJets_V8d[i].pt(), cms3.pfjets_p4().at(i).phi(), weight);
 
        float emfrac = (cms3.pfjets_chargedEmE().at(i) + cms3.pfjets_neutralEmE().at(i)) / jet_p4.E();
	float neutral_emfrac = cms3.pfjets_neutralEmE().at(i) / jet_p4.E();
	float neutral_hadfrac = cms3.pfjets_neutralHadronE().at(i) / jet_p4.E();
	float charged_hadfrac = cms3.pfjets_chargedHadronE().at(i) / jet_p4.E();
	float neutral_emfrac_hf = cms3.pfjets_hfEmE().at(i) / jet_p4.E();
	float neutral_hadfrac_hf = cms3.pfjets_hfHadronE().at(i) / jet_p4.E();
    
        if (abs(cms3.pfjets_p4().at(i).eta()) <= 3.0) {
	  fill_histograms(hJet_Emfrac, emfrac, weight);
	  fill_histograms(hJet_Neutral_Emfrac, neutral_emfrac, weight);
	  fill_histograms(hJet_Neutral_Hadfrac, neutral_hadfrac, weight);
	  fill_histograms(hJet_Charged_Hadfrac, charged_hadfrac, weight);
	}	
	else {
	  fill_histograms(hJet_Neutral_Emfrac_hf, neutral_emfrac_hf, weight);
	  fill_histograms(hJet_Neutral_Hadfrac_hf, neutral_hadfrac_hf, weight); 
	}

	if (abs(cms3.pfjets_p4().at(i).eta()) <= 2.7) {
	  fill_histograms(hJet_Neutral_Emfrac_central, neutral_emfrac, weight);
          fill_histograms(hJet_Neutral_Hadfrac_central, neutral_hadfrac, weight);
	}
	else if (abs(cms3.pfjets_p4().at(i).eta()) <= 3.0) {
	  fill_histograms(hJet_Neutral_Emfrac_forward, neutral_emfrac, weight);
          fill_histograms(hJet_Neutral_Hadfrac_forward, neutral_hadfrac, weight);
	}
      }

      for (int i=0; i<nCands; i++) { // begin pf cand loop
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourV = cms3.pfcands_p4().at(i);
        double pt = fourV.Pt();
        double phi = fourV.Phi();
        double etaS = fourV.eta();
        double eta = abs(etaS);
        int etaIdx = sortEta(eta);
        int candIdx = -1;
        int particleId = abs(pfcands_particleId().at(i));

	if (abs(pfcands_charge().at(i)) > 0)             { candIdx = 0; nCCands++; }        // charged candidate
        else if (particleId == 22 )                      { candIdx = 1; nPCands++; }        // photon candidate
        else                                             { candIdx = 2; nNCands++; }        // neutral hadron candidate

	fill_histograms(vhCandpT[candIdx], pt, weight);
	fill_histograms(vhCandeta[candIdx], eta, weight);
	if (candIdx == 1 && eta > 2.3 && eta < 3.0) fill_histograms(hPhotonpTEndcap,pt, weight);
	vFourVec[etaIdx][candIdx] += fourV;
	vFourVec[etaIdx][3] += fourV;
	vFourVec[5][3] += fourV;
	vSumET[etaIdx][candIdx] += pt;
	vSumET[etaIdx][3] += pt;
	vSumET[5][3] += pt;

   
        if (!( (candIdx == 1 || candIdx == 2) && (eta > 2.5 && eta < 3.0)) && !(candIdx == 1 && eta > 2.5)) // not a low pt photon or neutral had in endcap
          fourVRawMETMod += fourV;
        // Raw MET excluding low pT photons and neutral hads in endcap
	if (!( (candIdx == 1 || candIdx == 2) && pt < 10 && (eta > 2.0 && eta < 3.0))) // not a low pt photon or neutral had in endcap
          fourVRawMETMod_v2 += fourV;

	// Check clustered vs unclustered photons
	if (candIdx == 1 && etaIdx == 3) {
	  if (isClusteredCand(fourV))
	    sumETPhotonsEndcapClustered += pt;
	  else
	    sumETPhotonsEndcapUnclustered += pt;
	}
      } // end pf cand loop
      fill_histograms(hNCCands,nCCands, weight);
      fill_histograms(hNPCands,nPCands, weight);
      fill_histograms(hNNCands,nNCands, weight);

      fill_histograms(hSumETEndcapPhotonsUnclustered,sumETPhotonsEndcapUnclustered, weight);
      fill_histograms(hSumETEndcapPhotonsClustered,sumETPhotonsEndcapClustered, weight);

      fill_histograms(hRawMETMod,fourVRawMETMod.Pt(), weight);
      fill_histograms(hRawMETMod_v2,fourVRawMETMod_v2.Pt(), weight);

      if (nJet == 0) {
        fill_histograms(hRawMET_0JetsMod,fourVRawMETMod.Pt(), weight);
        fill_histograms(hRawMET_0JetsMod_v2,fourVRawMETMod_v2.Pt(), weight);
      }
      else if (nJet >= 1) {
	fill_histograms(hRawMET_1pJetsMod,fourVRawMETMod.Pt(), weight);
        fill_histograms(hRawMET_1pJetsMod_v2,fourVRawMETMod_v2.Pt(), weight);
      }

      // Fill pf cand histos
      for (int i=0; i<nEtaRegions; i++) {
        for (int j=0; j<nCandCats; j++) {
          if (vSumET[i][j] == 0) { continue; }
	  fill_histograms(vhMET[i][j][0], vFourVec[i][j].Pt(), weight);
          fill_histograms(vhMET[i][j][1], vSumET[i][j], weight);
	  fill_histograms(vhMET[i][j][2], vFourVec[i][j].Phi(), weight);
          //vhMET[i][j][0]->Fill(vFourVec[i][j].Pt(), weight);
          //vhMET[i][j][1]->Fill(vSumET[i][j], weight);
          //vhMET[i][j][2]->Fill(vFourVec[i][j].Phi(), weight);
        }
      }
    }
    delete tree;
    file.Close();
  }
  f1->cd();
  f1->Write();
  f1->Close();
  delete f1;

  if (nEventsChain != nEventsTotal) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time: " << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time: " << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  return 0;
}
