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

int ScanChain(TChain* chain, TString output_name, TString weightFile, bool puReweight, int selection, double scale1fb, double target_lumi = 1.) {
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  TFile* f1 = new TFile(output_name+".root", "RECREATE");
  f1->cd();

  // Pf cand MET, Sum E_T, MET phi for each eta region and pf candidate category
  vector<vector<vector<TH1D*>>> vhMET = create_met_histograms(nEtaRegions, nCandCats);

  // MET
  TH1D* hpfMET = create_histogram("hpfMET", 80, 0, 400);
  TH1D* hpfMETraw = create_histogram("hpfMETraw", 80, 0, 400); 
  TH1D* hT1CMET = create_histogram("hT1CMET", 80, 0, 400);
  TH1D* hZRemovedMET = create_histogram("hZRemovedMET", 80, 0, 400);
  TH1D* hZRemovedMETRaw = create_histogram("hZRemovedMETRaw", 80, 0, 400);
  TH1D* hMHT = create_histogram("hMHT", 80, 0, 400);

  // Dilepton Mass
  TH1D* hDilepMass = create_histogram("hDilepMass", 100, 0, 250);
  TH1D* hDilepMassEE = create_histogram("hDilepMassEE", 100, 0, 250);
  TH1D* hDilepMassMuMu = create_histogram("hDilepMassMuMu", 100, 0, 250);

  // Pf Cand pT
  TH1D* hCCpT = create_histogram("hCCpT", 100, 0, 100); 
  TH1D* hPhotonpT = create_histogram("hPhotonpT", 100, 0, 100); 
  TH1D* hNeutpT = create_histogram("hNeutpT", 100, 0, 100); 
  vector<TH1D*> vhCandpT = {hCCpT, hPhotonpT, hNeutpT};
 
  // Pf Cand eta
  TH1D* hCCeta = create_histogram("hCCeta", 50, 0, 5);
  TH1D* hPhotoneta = create_histogram("hPhotoneta", 50, 0, 5);
  TH1D* hNeuteta = create_histogram("hNeuteta", 50, 0, 5);
  vector<TH1D*> vhCandeta = {hCCeta, hPhotoneta, hNeuteta};

  // Candidate multiplicity
  TH1D* hNCands = create_histogram("hNCands", 300, 0, 3000);
  TH1D* hNCCands = create_histogram("hNCCands", 300, 0, 3000);
  TH1D* hNPCands = create_histogram("hNPCands", 300, 0, 3000);
  TH1D* hNNCands = create_histogram("hNNCands", 300, 0, 3000);

  // Misc
  TH1D* hSumETEndcapPhotonsUnclustered = create_histogram("hSumETEndcapPhotonsUnclustered", 100, 0, 1000);
  TH1D* hSumETEndcapPhotonsClustered = create_histogram("hSumETEndcapPhotonsClustered", 100, 0, 1000); 

  TH1D* hRawMETMod = create_histogram("hRawMETMod", 80, 0, 400);
  TH1D* hRawMETMod_v2 = create_histogram("hRawMETMod_v2", 80, 0, 400);  
  TH1D* hT1CMETMod = create_histogram("hT1CMETMod", 80, 0, 400);
  TH1D* hT1CMETMod_v2 = create_histogram("hT1CMETMod_v2", 80, 0, 400);

  TH1D* hT1CMET_NoECJECs_v1 = create_histogram("hT1CMET_NoECJECs_v1", 80, 0, 400); // no  HE, pT < 30 
  TH1D* hT1CMET_NoECJECs_v2 = create_histogram("hT1CMET_NoECJECs_v2", 80, 0, 400); // no  HE, pT < 50
  TH1D* hT1CMET_NoECJECs_v3 = create_histogram("hT1CMET_NoECJECs_v3", 80, 0, 400); // use HE, pt < 30
  TH1D* hT1CMET_NoECJECs_v4 = create_histogram("hT1CMET_NoECJECs_v4", 80, 0, 400); // use HE, pt < 50

  double vtxBins[] = {0,5,10,15,20,25,30,35,40,45,100};
  int nVtxBins = (sizeof(vtxBins)/sizeof(vtxBins[0]))-1;
  TH1D* hNVtx = new TH1D("hNVtx","", nVtxBins, vtxBins);
  hNVtx->Sumw2();

  TH1D* hPhotonpTEndcap = create_histogram("hPhotonpTEndcap", 100, 0, 100);

  TH1D* hNJets = create_histogram("hNJets", 16, -0.5, 15.5);

  TFile* fWeights;
  TH1D* hWeights;
  if (puReweight) {
    fWeights = new TFile(weightFile, "READ");
    hWeights = (TH1D*)fWeights->Get("pileupReweight");
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

      // Check if leps pass POG IDs
      if (!lepsPassPOG(isElEvt, id1, id2)) 						continue;

      if (selection == 2) { // only fill hNVtx for deriving pileup weights
        if (!lepsPassOtherLenient(isElEvt, id1, id2))                                   continue;
	double ZpT = -1;
	double dMass = dilepMass(isElEvt, id1, id2, ZpT);
	if (dMass < 81 || dMass > 101)                                                  continue;
 	double weight = 1;
	int nvtx = evt_nvtxs();
	if (puReweight)
	  weight *= hWeights->GetBinContent(hWeights->FindBin(nvtx));

	// Weight further if MC
	if (!cms3.evt_isRealData()) {
	  weight *= scale1fb * target_lumi *sgn(genps_weight());
	}
	hNVtx->Fill(nvtx, weight);
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
      double weight = 1;
      int nvtx = evt_nvtxs();
      if (puReweight) 
	weight *= hWeights->GetBinContent(hWeights->FindBin(nvtx));
      
      // Weight further if MC
      if (!cms3.evt_isRealData()) {
        weight *= scale1fb * target_lumi *sgn(genps_weight());
      }

      // Fill dilep mass before cutting on it
      double ZpT = -1;
      double dMass = dilepMass(isElEvt, id1, id2, ZpT);
      hDilepMass->Fill(dMass, weight);
      if (isElEvt)
	hDilepMassEE->Fill(dMass, weight);
      else
	hDilepMassMuMu->Fill(dMass, weight);

      if (selection == 1) { // regular Z->ll
        if (dMass < 81 || dMass > 101)							continue;
      }
      
      else if (selection == 0) { // Z-Removed MET selection
	if (dMass < 71 || dMass > 111)							continue;
        if (ZpT < 200)									continue;
      }

      // Fill Z-Removed MET before cutting on it (if selection == 0)
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET = t1CMET(currentFileName);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod = t1CMET_noHE(currentFileName, 15., {0., 0.}, false);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v1 = t1CMET_noHE(currentFileName, 30., {2.5, 3.0}, false);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v2 = t1CMET_noHE(currentFileName, 50., {2.5, 3.0}, false);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v3 = t1CMET_noHE(currentFileName, 30., {2.5, 3.0}, true);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMETMod_v4 = t1CMET_noHE(currentFileName, 50., {2.5, 3.0}, true);

      double dPhi2(0), dPhiRaw(0);
      if (selection == 0) {
	double zRemMET = ZRemovedMET(fT1CMET, isElEvt, id1, id2, dPhi2);
	hZRemovedMET->Fill(zRemMET, weight);

	double zRemMETRaw = ZRemovedMETRaw(isElEvt, id1, id2, dPhiRaw);
	hZRemovedMETRaw->Fill(zRemMETRaw, weight);

	if (zRemMET < 100 || zRemMET > 200)						continue;
      }
      // Done with selection, now fill histograms
      hT1CMET->Fill(fT1CMET.pt(), weight);
      hT1CMETMod->Fill(fT1CMETMod.pt(), weight);

      hT1CMET_NoECJECs_v1->Fill(fT1CMETMod_v1.pt(), weight);
      hT1CMET_NoECJECs_v2->Fill(fT1CMETMod_v2.pt(), weight);
      hT1CMET_NoECJECs_v3->Fill(fT1CMETMod_v3.pt(), weight);
      hT1CMET_NoECJECs_v4->Fill(fT1CMETMod_v4.pt(), weight);

      hNVtx->Fill(nvtx, weight);
      
      hpfMET->Fill(evt_pfmet(), weight);
      hpfMETraw->Fill(evt_pfmet_raw(), weight);

      int nJet = nJets(isElEvt, id1, id2);
      hNJets->Fill(nJet, weight);

      int nCands = pfcands_p4().size();
      hNCands->Fill(nCands, weight);

      vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >>> vFourVec(nEtaRegions, vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >>(nCandCats));
      vector<vector<double>> vSumET(nEtaRegions, vector<double>(nCandCats, 0.0));

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourVRawMETMod;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourVRawMETMod_v2;

      double sumETPhotonsEndcapClustered(0), sumETPhotonsEndcapUnclustered(0);

      int nCCands(0), nPCands(0), nNCands(0);
      for (int i=0; i<nCands; i++) { // begin pf cand loop
        continue;
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

	vhCandpT[candIdx]->Fill(pt, weight);
	vhCandeta[candIdx]->Fill(eta, weight);
	if (candIdx == 1 && eta > 2.3 && eta < 3.0) hPhotonpTEndcap->Fill(pt, weight);
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
      hNCCands->Fill(nCCands, weight);
      hNPCands->Fill(nPCands, weight);
      hNNCands->Fill(nNCands, weight);

      hSumETEndcapPhotonsUnclustered->Fill(sumETPhotonsEndcapUnclustered, weight);
      hSumETEndcapPhotonsClustered->Fill(sumETPhotonsEndcapClustered, weight);

      hRawMETMod->Fill(fourVRawMETMod.Pt(), weight);
      hRawMETMod_v2->Fill(fourVRawMETMod_v2.Pt(), weight);

      // Fill pf cand histos
      for (int i=0; i<nEtaRegions; i++) {
	continue; //skip pf cands for saving time
        for (int j=0; j<nCandCats; j++) {
          if (vSumET[i][j] == 0) { continue; }
          vhMET[i][j][0]->Fill(vFourVec[i][j].Pt(), weight);
          vhMET[i][j][1]->Fill(vSumET[i][j], weight);
          vhMET[i][j][2]->Fill(vFourVec[i][j].Phi(), weight);
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
