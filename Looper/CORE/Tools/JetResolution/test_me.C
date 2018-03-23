#include "JetResolution.h"
#include "../../CMS3.h"

int main() {


  //void test_me() {  
  //  gROOT->LoadMacro("./JetResolution.so");
  //  gROOT->LoadMacro("../../CMS3_CORE.so");

  JetResolution res;  
  res.loadResolutionFile("data/Spring16_25nsV1_MC_PtResolution_AK4PFchs.txt");
  res.loadScaleFactorFile("data/Spring16_25nsV1_MC_SF_AK4PFchs.txt");

  TFile* testFile = TFile::Open("root://cmsxrootd.fnal.gov//store/group/snt/run2_25ns_80MiniAODv2/TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/V08-00-05/merged_ntuple_1.root");
  TTree* testTree = (TTree*) testFile->Get("Events");
  cms3.Init(testTree);

  for (size_t ievent = 0; ievent < testTree->GetEntries(); ievent++) {
    cms3.GetEntry(ievent);

    cout << "Event: " << ievent << endl;
    vector<Double_t> GenJetPt;
    cout <<  "   Gen jets:" << endl;
    for (auto& genjet : cms3.genjets_p4NoMuNoNu()) {
      cout << "     pt, eta, phi: " << genjet.pt() << " " << genjet.eta() << " " << genjet.phi() << endl;
      GenJetPt.push_back(genjet.pt());
    }
    
    for (size_t ijet = 0; ijet < cms3.pfjets_p4().size(); ijet++) {
      cout << "   Reco jet number: " << ijet << endl; 
      res.loadVariable("JetEta", cms3.pfjets_p4().at(ijet).eta());
      res.loadVariable("Rho", cms3.evt_fixgridfastjet_all_rho());
      res.loadVariable("JetPt", cms3.pfjets_p4().at(ijet).pt()); // should be the corrected energy. Not taken into account here.

      auto smearing = res.smear(cms3.pfjets_p4().at(ijet), cms3.genjets_p4NoMuNoNu(), GenJetPt, 0);
      auto matching = res.match();
      
      cout << "   MC resolution:        " << res.getResolution() << endl;
      cout << "   data/MC scale factor: " << res.getScaleFactor(0) << endl;
      cout << "   jet eta:              " << cms3.pfjets_p4().at(ijet).eta() << endl;
      cout << "   jet phi:              " << cms3.pfjets_p4().at(ijet).phi() << endl;
      cout << "   rho:                  " << cms3.evt_fixgridfastjet_all_rho() << endl;
      cout << "   is matched:           " << matching[0] << endl;
      cout << "   original jet pT:      " << cms3.pfjets_p4().at(ijet).pt() << endl;
      cout << "   smeared jet pT:       " << smearing[0] << endl;
      cout << endl;
    }
  }
  testFile->Close();
  
}
