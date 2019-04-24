
// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TH2D.h"

// CMS3
#include "../../CORE/CMS3.cc"
#include "../../CORE/Base.cc"
#include "../../CORE/Config.h"

#include "../../CORE/TriggerSelections.cc"
#include "../../CORE/IsolationTools.cc"
#include "../../CORE/ElectronSelections.cc"
#include "../../CORE/MuonSelections.cc"
#include "../../CORE/Tools/JetCorrector.cc"
#include "../../CORE/Tools/goodrun.cc"
#include "CORE/MetSelections.cc"
#include "../../CORE/VertexSelections.cc"

//#include "ScanChain.h"
#include "MetHelper.h"

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
  vector<TH1D*> hpfMET_recipe = create_histogram_vector("hpfMET_recipe", 80, 0, 400, nHists);
  vector<TH1D*> hpfMET_myImplementation = create_histogram_vector("hpfMET_myImplementation", 80, 0, 400, nHists);
  vector<TH1D*> hpfModifiedMET_recipe = create_histogram_vector("hpfModifiedMET_recipe", 80, 0, 400, nHists);
  vector<TH1D*> hpfModifiedMET_myImplementation = create_histogram_vector("hpfModifiedMET_myImplementation", 80, 0, 400, nHists);
  vector<TH1D*> hpfMET = create_histogram_vector("hpfMET", 80, 0, 400, nHists);
  vector<TH1D*> hpfMETraw = create_histogram_vector("hpfMETraw", 80, 0, 400, nHists); 
  vector<TH1D*> hpfModMETraw = create_histogram_vector("hpfModMETraw", 80, 0, 400, nHists);
  vector<TH1D*> hpfMETraw_0jets = create_histogram_vector("hpfMETraw_0jets", 80, 0, 400, nHists);
  vector<TH1D*> hpfModMETraw_0jets = create_histogram_vector("hpfModMETraw_0jets", 80, 0, 400, nHists);
  vector<TH1D*> hpfMETraw_1pjets = create_histogram_vector("hpfMETraw_1pjets", 80, 0, 400, nHists);
  vector<TH1D*> hpfModMETraw_1pjets = create_histogram_vector("hpfModMETraw_1pjets", 80, 0, 400, nHists);
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
  //MetHelper* mV8_std = new MetHelper("V8_std", nHists, "V8", "V8", 0);
  //mV8_std->create_raw_met_histograms();
  //MetHelper* mV8_v1 = new MetHelper("V8_v1", nHists, "V8", "V8", 1);
  //MetHelper* mV8_v2C = new MetHelper("V8_v2C", nHists, "V8", "V8", 2);
  //MetHelper* mV8_v2D = new MetHelper("V8_v2D", nHists, "V8", "V8", 3);

  //MetHelper* mV6_v2C = new MetHelper("V6_v2C", nHists, "V6", "V6", 2);
  //MetHelper* mV6_std = new MetHelper("V6_std", nHists, "V6", "V6", 0);
  //MetHelper* mV6_v2C_50GeV = new MetHelper("V6_v2C_50GeV", nHists, "V6", "V6", 5);

  //MetHelper* mV11_std = new MetHelper("V11_std", nHists, "V11", "V11", 0);
  //mV11_std->create_raw_met_histograms();
  //MetHelper* mV11_v1 = new MetHelper("V11_v1", nHists, "V11", "V11", 1);
  //MetHelper* mV11_v2C = new MetHelper("V11_v2C", nHists, "V11", "V11", 2);
  //MetHelper* mV11_v2C_recipe = new MetHelper("V11_v2C_recipe", nHists, "V11", "V11", 4);

  //MetHelper* mV11_v2C_50GeV = new MetHelper("V11_v2C_50GeV", nHists, "V11", "V11", 5);
 
  //MetHelper* mV24_v2C_50GeV = new MetHelper("V24_v2C_50GeV", nHists, "V24", "V24", 5);
  //MetHelper* mV25_v2C_50GeV = new MetHelper("V25_v2C_50GeV", nHists, "V25", "V24", 5);
  //MetHelper* mV26_v2C_50GeV = new MetHelper("V26_v2C_50GeV", nHists, "V26", "V24", 5);
  MetHelper* mV32_std = new MetHelper("V32_std", nHists, "V32", "V24", 0); 
  //MetHelper* mV32_v2C_50GeV = new MetHelper("V32_v2C_50GeV", nHists, "V32", "V24", 5);


  //MetHelper* mV11_v2C_corr = new MetHelper("V11_v2C_corr", nHists, "V11", "V11", 2, true);
  //MetHelper* mV11_v2D = new MetHelper("V11_v2D", nHists, "V11D", "V11D", 3);

  // Jets
  vector<TH1D*> hLeadJetPt = create_histogram_vector("hLeadJetPt", 100, 0, 500, nHists);
  vector<TH1D*> hLeadJetEta = create_histogram_vector("hLeadJetEta", 50, 0, 5, nHists);

  vector<TH1D*> hJetPt = create_histogram_vector("hJetPt", 100, 0, 500, nHists);
  vector<TH1D*> hJetEta = create_histogram_vector("hJetEta", 50, 0, 5, nHists);  

  vector<TH2D*> hJetEtaPhi = create_2Dhistogram_vector("hJetEtaPhi", 50, -5, 5, 50, -3.142, 3.142, nHists);
  vector<TH2D*> hJetPtEta = create_2Dhistogram_vector("hJetPtEta", 50, 0, 500, 50, -5, 5, nHists);
  vector<TH2D*> hJetPtPhi = create_2Dhistogram_vector("hJetPtPhi", 50, 0, 500, 50, -3.142, 3.142, nHists);
  vector<TH2D*> hT1CMETvT1CMETMod = create_2Dhistogram_vector("hT1CMETvT1CMETMod", 80, 0, 400, 80, 0, 400, nHists);
  vector<TH2D*> hT1CMETModvT1CMETModCorr = create_2Dhistogram_vector("hT1CMETModvT1CMETModCorr", 80, 0, 400, 80, 0, 400, nHists); 


  vector<TH2D*> hT1CMET_FormEval_vs_TForm = create_2Dhistogram_vector("hT1CMET_FormEval_vs_TForm", 80, 0, 400, 80, 0, 400, nHists);


  vector<TH2D*> hT1CMET_Modv1_vs_Nominal = create_2Dhistogram_vector("hT1CMET_Modv1_vs_Nominal", 80, 0, 400, 80, 0, 400, nHists);
  vector<TH2D*> hT1CMET_Modv2_vs_Nominal = create_2Dhistogram_vector("hT1CMET_Modv2_vs_Nominal", 80, 0, 400, 80, 0, 400, nHists);
  vector<TH2D*> hRawCMET_Modv2_vs_Nominal = create_2Dhistogram_vector("hRawCMET_Modv2_vs_Nominal", 80, 0, 400, 80, 0, 400, nHists);

  vector<TH1D*> hJetUncorrPt = create_histogram_vector("hJetUncorrPt", 100, 0, 500, nHists);

  vector<TH2D*> hJetUncorrPtEta = create_2Dhistogram_vector("hJetUncorrPtEta", 50, 0, 500, 50, -5, 5, nHists);
  vector<TH2D*> hJetUncorrPtPhi = create_2Dhistogram_vector("hJetUncorrPtPhi", 50, 0, 500, 50, -3.142, 3.142, nHists);

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


  double vtxBins[] = {0,5,10,15,20,25,30,35,40,45,100};
  int nVtxBins = (sizeof(vtxBins)/sizeof(vtxBins[0]))-1;
  vector<TH1D*> hNVtx;
  vector<TH1D*> hNVtx_up, hNVtx_down;
  for (int i = 0; i < nHists; i++) { 
   TString name = "hNVtx"+to_string(i);
   hNVtx.push_back(new TH1D(name,"", nVtxBins, vtxBins));
   hNVtx[i]->Sumw2();
   hNVtx_up.push_back(new TH1D(name + "_up","", nVtxBins, vtxBins));
   hNVtx_up[i]->Sumw2();
   hNVtx_down.push_back(new TH1D(name + "_down","", nVtxBins, vtxBins));
   hNVtx_down[i]->Sumw2();
  }

  vector<TH1D*> hPhotonpTEndcap = create_histogram_vector("hPhotonpTEndcap", 100, 0, 100, nHists);

  vector<TH1D*> hNJets = create_histogram_vector("hNJets", 16, -0.5, 15.5, nHists);

  vector<TFile*> fWeights;
  vector<TH1D*> hWeights;
  vector<TFile*> fWeights_up;
  vector<TH1D*> hWeights_up;
  vector<TFile*> fWeights_down;
  vector<TH1D*> hWeights_down;
  if (puReweight) {
    for (int i = 0; i < nHists; i++) {
      fWeights.push_back(new TFile(vWeightFile[i], "READ"));
      hWeights.push_back((TH1D*)fWeights[i]->Get("pileupReweight"));
      //fWeights_down.push_back(new TFile(vWeightFile[i].ReplaceAll("MC", "MC_down"), "READ"));
      //hWeights_down.push_back((TH1D*)fWeights_down[i]->Get("pileupReweight_down"));
      //fWeights_up.push_back(new TFile(vWeightFile[i].ReplaceAll("MC", "MC_up"), "READ"));
      //hWeights_up.push_back((TH1D*)fWeights_up[i]->Get("pileupReweight_up"));
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
      json_file = "Cert_294927-306462_13TeV_EOY2017ReReco_Collisions17_JSON_snt.txt"; 
      set_goodrun_file(json_file);
    }
    
    for (unsigned int event = 0; event < nEventsTree; ++event) {
      if (nEventsTotal >= nEventsChain) continue;
      tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;
      CMS3::progress( nEventsTotal, nEventsChain );
  
      if (selection == 10) {
	double t1met_mod_v2 = t1CMET_configurable(currentFileName, "V6", "V6", 75., {2.65, 3.139}, true, true, 75.).pt();
        double t1met_mod_v1 = t1CMET_configurable(currentFileName, "V6", "V6", 75., {2.65, 3.139}, true, false).pt();
        cout << cms3.evt_event() << ":" << cms3.evt_run() << ":" << cms3.evt_lumiBlock() << " , Type-1 MET mod v1: " << t1met_mod_v1 << " , Type-1 MET mod v2: " << t1met_mod_v2 << endl;
        continue;
      }


      if (selection == 3) {
        cout << endl << "Event number " << event << endl;
        cout << "Type-1 MET: " << t1CMET(currentFileName, 0).pt() << endl;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets = correctedJets(currentFileName, "V8", "V8"); 
        for (int i = 0; i < vCorrectedJets.size(); i++)
          cout << "Jet number " << i << ": " << vCorrectedJets[i].pt() << endl;
      }

      if (selection == 6) {
	double t1met = t1CMET(currentFileName, 0).pt();
	cout << t1met << endl;
      }

      if (selection == 4) {
        //if (dMass < 81 || dMass > 101)                                                  continue;
        double t1met_base = evt_pfmet();
        double t1met = t1CMET_configurable(currentFileName, "V11", "V11", 0, {0,0}, true, false, 0, 0).pt();
        if (!(t1met > 120 && t1met < 170)) continue;
        double t1met_mod = t1CMET_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0).pt();
	double t1met_mod_corr = t1CMET_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0, true).pt();
        //cout << evt_run() << " " << evt_lumiBlock() << " " << evt_event() << " " << t1met << " " << t1met_base << endl;
        //cout << evt_run() << " " << evt_lumiBlock() << " " << evt_event() << " " << t1met << " " << t1met_mod << endl;
        cout << t1met << " " << t1met_mod << " " << t1met_mod_corr << endl; 
        continue;
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

      if (selection == 7) {
	if (!isElEvt)
	  continue;
      }

      // Check filters
      if (firstGoodVertex() == -1)		continue;
      if (!filt_goodVertices())          	continue;
      if (!filt_globalTightHalo2016())   	continue;
      if (!filt_hbheNoise())             	continue;
      if (!filt_hbheNoiseIso())          	continue; 
      if (!filt_ecalTP())			continue;
      if (evt_isRealData()) { if (!filt_eeBadSc()) continue; } // only for data
      if (!filt_BadPFMuonFilter())		continue;
      if (!filt_BadChargedCandidateFilter())	continue;
      if (!filt_ecalBadCalibFilter())		continue;

      // Check if leps pass POG IDs
      if (!lepsPassPOG(isElEvt, id1, id2)) 						continue;
      if (!opposite_sign(isElEvt, id1, id2))						continue;

      if (selection == 7) {
	if (!lepsPassOtherLenient(isElEvt, id1, id2))                                   continue;
	double ZpT = -1;
        double dMass = dilepMass(isElEvt, id1, id2, ZpT);
        if (dMass < 81 || dMass > 101)                                                  continue;
	double weight = 1.;
	if (!cms3.evt_isRealData())
	  weight *= sgn(genps_weight());
	
        	
	continue;	
      }

      if (selection == 2) { // only fill hNVtx for deriving pileup weights
        if (!lepsPassOtherLenient(isElEvt, id1, id2))                                   continue;
	double ZpT = -1;
	double dMass = dilepMass(isElEvt, id1, id2, ZpT);
	if (dMass < 81 || dMass > 101)                                                  continue;
 	double weight = 1;
	int nvtx = evt_nvtxs();
        int nvtx_up(nvtx), nvtx_down(nvtx);
        if (cms3.evt_isRealData()) {
          nvtx_up += 2;
	  nvtx_down -= 2;
	}

	// Weight further if MC
	if (!cms3.evt_isRealData()) {
	  weight *= scale1fb * target_lumi *sgn(genps_weight());
	}
        fill_histograms(hNVtx, nvtx, {weight});
	fill_histograms(hNVtx_up, nvtx_up, {weight});
	fill_histograms(hNVtx_down, nvtx_down, {weight});
	continue;		
      }

      // Check pT/eta requirements
      if (selection == 1 || selection == 5) { // regular Z->ll
        if (!lepsPassOtherLenient(isElEvt, id1, id2)) 					continue;
      }
      else if (selection == 0) { // Z-Removed MET selection
        if (!lepsPassOther(isElEvt, id1, id2)) 						continue;
      }

      // Grab pu weights
      vector<double> weight(nHists, 1);
      vector<double> weight_up(nHists, 1);
      vector<double> weight_down(nHists, 1);
      int nvtx = evt_nvtxs();
      if (puReweight) {
        for (int i = 0; i < nHists; i++) {
	  weight[i] *= hWeights[i]->GetBinContent(hWeights[i]->FindBin(nvtx));
	  //weight_up[i] *= hWeights_up[i]->GetBinContent(hWeights_up[i]->FindBin(nvtx));
	  //weight_down[i] *= hWeights_down[i]->GetBinContent(hWeights_down[i]->FindBin(nvtx));
        }
      }
      // Weight further if MC
      if (!cms3.evt_isRealData()) {
	for (int i = 0; i < nHists; i++) {
          weight[i] *= scale1fb * target_lumi *sgn(genps_weight());
	  //weight_up[i] *= scale1fb * target_lumi *sgn(genps_weight());
	  //weight_down[i] *= scale1fb * target_lumi *sgn(genps_weight());
	}
      }

      // Fill dilep mass before cutting on it
      double ZpT = -1;
      double dMass = dilepMass(isElEvt, id1, id2, ZpT);
      fill_histograms(hDilepMass,dMass, weight);
      if (isElEvt)
	fill_histograms(hDilepMassEE,dMass, weight);
      else
	fill_histograms(hDilepMassMuMu,dMass, weight);


      if (selection == 9) {
	if (!isElEvt)									continue;
	if (dMass < 81 || dMass > 101)                                                  continue;
	int nJet = nJets(isElEvt, id1, id2);
	if (nJet == 0) 									continue;
	if (evt_pfmet_raw() < 250)							continue;
	double t1met = t1CMET_configurable(currentFileName, "V11", "V11", 0, {0,0}, true, false, 0, 0).pt();
	//double t1met_mod = t1CMET_configurable(currentFileName, "V11", "V11", 75., {2.65, 3.139}, true, true, 75.).pt();
	cout << cms3.evt_event() << ":" << cms3.evt_run() << ":" << cms3.evt_lumiBlock() << " , raw MET: " << evt_pfmet_raw() << " , Type-1 MET mod v2: " << t1met << endl;
	continue;	
      }

      if (selection == 1 || selection == 5) { // regular Z->ll
        if (dMass < 81 || dMass > 101)							continue;
      }
      
      else if (selection == 0) { // Z-Removed MET selection
	if (dMass < 71 || dMass > 111)							continue;
        if (ZpT < 200)									continue;
      }

      if (selection == 4) {
	if (dMass < 81 || dMass > 101)                                                  continue;
        double t1met_base = evt_pfmet();
        double t1met = t1CMET_configurable(currentFileName, "V6", "V6", 0, {0,0}, true, false, 0, 0).pt();
        if (!(t1met > 120 && t1met < 170)) continue;
        //double t1met_mod = t1CMET_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0).pt();
        cout << evt_run() << " " << evt_lumiBlock() << " " << evt_event() << " " << t1met << " " << t1met_base << endl;
        continue;
      }
 

      double dPhi2(0), dPhiRaw(0);
      if (selection == 0) {
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET = t1CMET(currentFileName, 0);
	double zRemMET = ZRemovedMET(fT1CMET, isElEvt, id1, id2, dPhi2);
	fill_histograms(hZRemovedMET,zRemMET, weight);

	double zRemMETRaw = ZRemovedMETRaw(isElEvt, id1, id2, dPhiRaw);
	fill_histograms(hZRemovedMETRaw,zRemMETRaw, weight);

	if (zRemMET < 100 || zRemMET > 200)						continue;
      }

      if (selection == 8) {
	//if (!low_pt_ec_jet())
	//  continue;

	//if (abs(evt_pfmet_raw() - 11.3659) > 0.001 && !low_pt_ec_jet())
	//  continue; 

	//cout << cms3.evt_event() << " " << cms3.evt_run() << " " << cms3.evt_lumiBlock() << " " << cms3.evt_lumiRun() << endl;

	//for (int i = 0; i < cms3.pfjets_p4().size(); i++)
	//  cout << "Jet with pT: " << cms3.pfjets_p4()[i].pt() << ", eta: " << cms3.pfjets_p4()[i].eta() << endl; 

        double raw_met_mod = t1CMET_raw_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0);
        double raw_met_mod_recipe = evt_old_pfmet_raw();
        double raw_met_nominal = evt_pfmet_raw();

	double t1met_v1b = t1CMET_configurable(currentFileName, "V11", "V11", 75., {2.65, 3.139}, true).pt();  

        //cout << raw_met_nominal << " " << raw_met_mod_recipe << " " << raw_met_mod << endl;

        double t1met_mod = t1CMET_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0).pt();
	cout << raw_met_mod_recipe << " " << raw_met_mod << "         " << evt_old_pfmet() << " " << t1met_mod << endl;

	//cout << "Modified Type-1 MET V1: " << endl;
	//cout << t1met_v1b << " " << evt_mod_pfmet() << endl;

        //double t1met_mod = t1CMET_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0).pt();
        //cout << "Raw MET (recipe): " << evt_mod_pfmet_raw() << endl;
        continue;
      }


      cout << event << " / " << nEventsTree << endl;

      if (selection == 5) {
        cout << event << " / " << nEventsTree << endl;
        double t1met_recipe = evt_pfmet();
        double t1met_mod_recipe = evt_old_pfmet();
        //double t1met = t1CMET_configurable(currentFileName, "V6", "V6", 0, {0,0}, true, false, 0, 0).pt();
        double t1met_mod = t1CMET_configurable(currentFileName, "V11", "V11", 0, {2.65, 3.139}, true, true, 75., 0).pt();

        fill_histograms(hpfMET_recipe, t1met_recipe, {1});
        fill_histograms(hpfModifiedMET_recipe, t1met_mod_recipe, {1});

        //fill_histograms(hpfMET_myImplementation, t1met, {1});
        fill_histograms(hpfModifiedMET_myImplementation, t1met_mod, {1});
        continue;
      } 

      // Done with selection, now fill histograms
      fill_histograms(hpfMETraw, evt_pfmet_raw(), weight);
      fill_histograms(hpfModMETraw, evt_old_pfmet_raw(), weight); 

      int nJet = nJets(isElEvt, id1, id2);

      if (nJet == 0) {
        fill_histograms(hpfMETraw_0jets, evt_pfmet_raw(), weight);
        fill_histograms(hpfModMETraw_0jets, evt_old_pfmet_raw(), weight);
      }
      else if (nJet >= 1) {
	fill_histograms(hpfMETraw_1pjets, evt_pfmet_raw(), weight);
        fill_histograms(hpfModMETraw_1pjets, evt_old_pfmet_raw(), weight);
      }

      //mV11_std->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);
      //mV11_v1->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);
      //mV11_v2C->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);
      //mV11_v2C_recipe->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);

      //mV11_v2C_50GeV->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);

      //mV24_v2C_50GeV->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);
      //mV25_v2C_50GeV->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);
      //mV26_v2C_50GeV->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight);


      double lead_jet_eta = cms3.pfjets_p4().size() > 0 ? abs(cms3.pfjets_p4().at(0).eta()) : 999;
      double pu = cms3.evt_nvtxs();

      vector<double> vId = {pu, lead_jet_eta};

      //mV6_std->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight, vId);
      mV32_std->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight, vId);

      //mV6_v2C_50GeV->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight, vId);
      //mV32_v2C_50GeV->fill_met_histograms(currentFileName, isElEvt, id1, id2, nJet, weight, vId);

      

      /*
      double t1_met_V6(0), t1_met_V11(0), t1_met_V27(0);
      t1_met_V6 = mV6_v2C_50GeV->get_t1met();
      t1_met_V11 = mV11_v2C_50GeV->get_t1met();
      t1_met_V27 = mV27_v2C_50GeV->get_t1met();

      double t1_met(0), t1_met_mod(0), t1_met_mod_v1(0), t1_met_mod_myImp(0), t1_met_mod_50GeV(0), t1_met_mod_V6(0);
      t1_met = mV11_std->get_t1met();
      t1_met_mod_v1 = mV11_v1->get_t1met();
      t1_met_mod = mV11_v2C_recipe->get_t1met();
      t1_met_mod_myImp = mV11_v2C->get_t1met();
      t1_met_mod_50GeV = mV11_v2C_50GeV->get_t1met();
      t1_met_mod_V6 = mV6_v2C->get_t1met();



      //cout << t1_met << " " << evt_pfmet() << endl;
      //cout << t1_met << " " << t1_met_mod_v1 << " " << t1_met_mod << " " << t1_met_mod_myImp << " " << t1_met_mod_50GeV << endl; 
      


      fill_histograms2D(hT1CMET_Modv1_vs_Nominal, t1_met, t1_met_mod_v1, weight);
      fill_histograms2D(hT1CMET_Modv2_vs_Nominal, t1_met, t1_met_mod, weight);
      fill_histograms2D(hRawCMET_Modv2_vs_Nominal, evt_pfmet_raw(), evt_mod_pfmet_raw(), weight);
      */

      //t1_met_mod_corr = mV11_v2C_corr->get_t1met(); 

      //double t1_met_mod_recipe = evt_mod_pfmet();
      //double t1_met_mod_recipe_reapplyJECs = t1CMET(currentFileName, 2).pt();
      //cout << "Modified MET (my imp): " << t1_met_mod << endl;
      //cout << "Modified MET (recipe, using FormulaEvaluator): " << t1_met_mod_recipe << endl;
      //cout << "Modified MET (reicpe, using TFormula        ): " << t1_met_mod_recipe_reapplyJECs << endl;

      //fill_histograms2D(hT1CMET_FormEval_vs_TForm, t1_met_mod_recipe, t1_met_mod_recipe_reapplyJECs, weight);
      //fill_histograms2D(hT1CMETvT1CMETMod, t1_met, t1_met_mod, weight);
      //fill_histograms2D(hT1CMETModvT1CMETModCorr, t1_met_mod, t1_met_mod_corr, weight);

      int nCands = pfcands_p4().size();
      fill_histograms(hNCands,nCands, weight);

      vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >>> vFourVec(nEtaRegions, vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >>(nCandCats));
      vector<vector<double>> vSumET(nEtaRegions, vector<double>(nCandCats, 0.0));

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourVRawMETMod;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourVRawMETMod_v2;

      double sumETPhotonsEndcapClustered(0), sumETPhotonsEndcapUnclustered(0);

      int nCCands(0), nPCands(0), nNCands(0);

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets_V11 = correctedJets(currentFileName, "V11", "V11");

      for (int i = 0; i < cms3.pfjets_p4().size(); i++) {
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> jet_p4 = cms3.pfjets_p4().at(i)*cms3.pfjets_undoJEC().at(i);	
	//cout << cms3.pfjets_p4().at(i).pt() << endl;
	//for (int j = 0; j < cms3.pfjets_pfcandIndicies()[i].size(); j++)
	//  cout << cms3.pfjets_pfcandIndicies()[i][j] << endl;
	//cout << jet_p4.pt() << endl;
        //cout << vCorrectedJets_V11[i].pt() << endl;
        //cout << endl;
	if (!(jet_p4.pt() > 0)) continue;
	if (i == 0) {
	  fill_histograms(hLeadJetPt, jet_p4.pt(), weight);
	  fill_histograms(hLeadJetEta, abs(cms3.pfjets_p4().at(0).eta()), weight); 
	}
	fill_histograms(hJetPt, jet_p4.pt(), weight);
	fill_histograms(hJetEta, abs(cms3.pfjets_p4().at(i).eta()), weight);
 
	fill_histograms2D(hJetEtaPhi, cms3.pfjets_p4().at(i).eta(), cms3.pfjets_p4().at(i).phi(), weight);
	fill_histograms2D(hJetPtEta, vCorrectedJets_V11[i].pt(), cms3.pfjets_p4().at(i).eta(), weight);
        fill_histograms2D(hJetPtPhi, vCorrectedJets_V11[i].pt(), cms3.pfjets_p4().at(i).phi(), weight);

        //fill_histograms(hJetUncorrPt, jet_p4.pt(), weight);

        fill_histograms2D(hJetUncorrPtEta, jet_p4.pt(), cms3.pfjets_p4().at(i).eta(), weight);
        fill_histograms2D(hJetUncorrPtPhi, jet_p4.pt(), cms3.pfjets_p4().at(i).phi(), weight);

 
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

/*      for (int i=0; i<nCands; i++) { // begin pf cand loop
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
      }*/
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
