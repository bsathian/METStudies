bool goodMuon(unsigned int muIdx) {
  if (!isTightMuonPOG(muIdx))           { return false; }
  if (muRelIso03EA(muIdx,1) > 0.4)      { return false; }
  return true;
}

bool lepsPassPOG(bool isElEvt, int &id1, int &id2) {
  // Are there at least 2 leptons?
  // If electrons, do they pass loose POG ID?
  // If muons, do they pass tight POG ID?
  int nLeps;
  if (isElEvt)
    nLeps = (els_p4()).size();
  else
    nLeps = (mus_p4()).size();
  int nGoodLeps = 0;
  for (int i=0; i<nLeps; i++) {
    if (isElEvt) {
      if (isLooseElectronPOGspring16_v1(i)) {
        nGoodLeps++;
        if (nGoodLeps == 1) id1 = i;
        else if (nGoodLeps == 2) id2 = i;
      }
    }
    else {
      if (goodMuon(i)) {
        nGoodLeps++;
        if (nGoodLeps == 1) id1 = i;
        else if (nGoodLeps == 2) id2 = i;
      }
    }
  }
  return (nGoodLeps == 2);
}

bool opposite_sign(bool isElEvt, int id1, int id2) {
  double charge_product;
  if (isElEvt)
    charge_product = els_charge().at(id1)*els_charge().at(id2);
  else
    charge_product = mus_charge().at(id1)*mus_charge().at(id2);
  return (charge_product < 0); 
}

double dilepMass(bool isElEvt, int id1, int id2, double &ZpT) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fZ;
  if (isElEvt)
    fZ = els_p4().at(id1)+els_p4().at(id2);
  else
    fZ = mus_p4().at(id1)+mus_p4().at(id2);
  ZpT = fZ.pt();
  return fZ.mass();
}

double dilepPhi(bool isElEvt, int id1, int id2) {
  if (isElEvt)
    return (els_p4().at(id1)+els_p4().at(id2)).phi();
  else
    return (mus_p4().at(id1)+mus_p4().at(id2)).phi();
}

int lepsEtaRegion(bool isElEvt, int id1, int id2) {
  if (isElEvt) {
    if (abs(els_p4().at(id1).eta()) < 1.3 && abs(els_p4().at(id2).eta()) < 1.3)
      return 0;
    else if (abs(els_p4().at(id1).eta()) > 1.3 && abs(els_p4().at(id2).eta()) > 1.3)
      return 1;
    else
      return 2;
  }
  else {
    if (abs(mus_p4().at(id1).eta()) < 1.3 && abs(mus_p4().at(id2).eta()) < 1.3)
      return 0;
    else if (abs(mus_p4().at(id1).eta()) > 1.3 && abs(mus_p4().at(id2).eta()) > 1.3)
      return 1;
    else
      return 2;
  }
}

bool lepsPassOther(bool isElEvt, int id1, int id2) {
  if (isElEvt) {
    if ((els_p4().at(id1)).Pt() >= 100 && (els_p4().at(id2)).Pt() >= 30
          && abs((els_p4().at(id1)).eta()) < 2.4 && abs((els_p4().at(id2)).eta()) < 2.4
          && (abs((els_p4().at(id1)).eta()) < 1.4 || abs((els_p4().at(id1)).eta()) > 1.6)
          && (abs((els_p4().at(id2)).eta()) < 1.4 || abs((els_p4().at(id2)).eta()) > 1.6)) { return true; }
    else { return false; }
  }
  else {
    if ((mus_p4().at(id1)).Pt() >= 100 && (mus_p4().at(id2)).Pt() >= 30
          && abs((mus_p4().at(id1)).eta()) < 2.4 && abs((mus_p4().at(id2)).eta()) < 2.4) { return true; }
    else { return false; }
  }
}

bool lepsPassOtherLenient(bool isElEvt, int id1, int id2) {
  double lead_pt = 45;
  double sublead_pt = 40;
  if (isElEvt) {
    if ((els_p4().at(id1)).Pt() >= lead_pt && (els_p4().at(id2)).Pt() >= sublead_pt
          && abs((els_p4().at(id1)).eta()) < 2.4 && abs((els_p4().at(id2)).eta()) < 2.4
          && (abs((els_p4().at(id1)).eta()) < 1.4 || abs((els_p4().at(id1)).eta()) > 1.6)
          && (abs((els_p4().at(id2)).eta()) < 1.4 || abs((els_p4().at(id2)).eta()) > 1.6)) { return true; }
    else { return false; }
  }
  else {
    if ((mus_p4().at(id1)).Pt() >= lead_pt && (mus_p4().at(id2)).Pt() >= sublead_pt
          && abs((mus_p4().at(id1)).eta()) < 2.4 && abs((mus_p4().at(id2)).eta()) < 2.4) { return true; }
    else { return false; }
  }
}

int sortEta(double eta) {
  if (eta >= 0 && eta < 1.3)            { return 0; }
  else if (eta >= 1.3 && eta < 1.6)     { return 1; }
  else if (eta >= 1.6 && eta < 2.5)     { return 2; }
  else if (eta >= 2.5 && eta < 3.0)     { return 3; }
  else if (eta >= 3.0)                  { return 4; }

}

double DeltaR(const LorentzVector p1, const LorentzVector p2){
  /*Returns the DeltaR between objects p1 and p2.*/
  double dphi = acos( cos( p1.phi() - p2.phi() ) );
  return sqrt( (p1.eta() - p2.eta())*(p1.eta() - p2.eta())+ dphi*dphi );
}

bool low_pt_ec_jet() {
  for (int i = 0; i < pfjets_p4().size(); i++) { 
    if (abs(pfjets_p4()[i].eta()) > 2.65 && abs(pfjets_p4()[i].eta()) < 3.139 && pfjets_p4()[i].pt() > 25 && pfjets_p4()[i].pt() < 50) {
    //cout << "Jet with eta: " << abs(pfjets_p4()[i].eta()) << " and pt: " << pfjets_p4()[i].pt() << endl;
    return true;
  }
  }
  return false;
}


int nJets(bool isElEvt, int id1, int id2) {
  int n = 0;
  int nJetCands = pfjets_p4().size();
  for (int i=0; i<nJetCands; i++) {
    if ((pfjets_p4().at(i)).Pt() < 35)                  { continue; }
    if (abs((pfjets_p4().at(i)).eta()) > 3.0)           { continue; }
    LorentzVector pl1, pl2;
    if (isElEvt) {
      pl1 = els_p4().at(id1);
      pl2 = els_p4().at(id2);
    }
    else {
      pl1 = mus_p4().at(id1);
      pl2 = mus_p4().at(id2);
    }
    if (DeltaR(pfjets_p4().at(i),pl1) < 0.4)            { continue; }
    if (DeltaR(pfjets_p4().at(i),pl2) < 0.4)            { continue; }
    //if (!isLoosePFJet(i)) { continue; }
    n++;
  }
  return n;
}

double ZRemovedMET(ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET, bool isElEvt, int id1, int id2, double &phiZ) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fZRemoved = fT1CMET;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fLep1;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fLep2;
  if (isElEvt) {
    fLep1 = els_p4().at(id1);
    fLep2 = els_p4().at(id2);
  }
  else {
    fLep1 = mus_p4().at(id1);
    fLep2 = mus_p4().at(id2);
  }
  fZRemoved += fLep1;
  fZRemoved += fLep2;
  phiZ = fZRemoved.phi();
  return fZRemoved.pt();
}

double sgn(double x) {
  return x > 0 ? 1 : -1;
}

double pPRel(const LorentzVector& pCand, const LorentzVector& pLep) {
  if (pLep.pt()<=0.) return 0.;
  LorentzVector jp4 = pLep;
  double dot = pCand.Vect().Dot( pLep.Vect() );
  return sgn(dot)*sqrt((dot*dot)/pLep.P2());
}

double boson_pT(bool isElEvt, int id1, int id2, ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fMet, double &u_para, double &u_perp, double &u_para_plus_qt) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fZ;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fLep1;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fLep2;
  if (isElEvt) {
    fLep1 = els_p4().at(id1);
    fLep2 = els_p4().at(id2);
  }
  else {
    fLep1 = mus_p4().at(id1);
    fLep2 = mus_p4().at(id2);
    //cout << "Mus pt: " << fLep1.pt() << endl;
    //cout << "Mus pt: " << fLep2.pt() << endl;
  }

  fZ += fLep1;
  fZ += fLep2;

  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fU = -fMet - fZ;
  //cout << fU.pt() << " " << fU.mag() << endl;


  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> qT = fZ;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> uT = fU;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> eT = fMet;
  qT.SetPz(0);
  uT.SetPz(0);
  eT.SetPz(0);

  u_para = pPRel(uT, qT);
  u_perp = sgn((qT.px()*uT.py()) - (uT.px()*qT.py()))*sqrt(pow(uT.pt(), 2) - pow(u_para, 2));
  u_para_plus_qt = qT.pt() + u_para; 

  //cout << "Boson pT: " << qT.pt() << " , u_parallel: " << u_para << " , u_perp: " << u_perp << endl;

  return qT.pt();
}

int find_index(vector<double> bins, double value) {
  for (int i = 0; i < bins.size() - 1; i++) {
    if (value >= bins[i] && value < bins[i+1])
      return i;
  }
  if (value > bins[bins.size() -1])
    return bins.size() - 1;
  else {
    cout << "Did not sort into a bin" << endl;
    return -1;
  }
}

double ZRemovedMETRaw(bool isElEvt, int id1, int id2, double &phiZ) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fZRemoved;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fLep1;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fLep2;
  for (int i = 0; i < cms3.pfcands_p4().size(); i++) {
    ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fourV = cms3.pfcands_p4().at(i);
    fZRemoved += fourV;
  }
  fZRemoved = -fZRemoved;  // want negative sum of pf candidates
  if (isElEvt) {
    fLep1 = els_p4().at(id1);
    fLep2 = els_p4().at(id2);
  }
  else {
    fLep1 = mus_p4().at(id1);
    fLep2 = mus_p4().at(id2);
  }
  fZRemoved += fLep1;
  fZRemoved += fLep2;
  phiZ = fZRemoved.phi();
  return fZRemoved.pt();
}

double mht(bool isElEvt, int id1, int id2) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fMHT;
  for (int i=0; i< pfjets_p4().size(); i++) {
    if ((pfjets_p4().at(i)).Pt() < 35)                  { continue; }
    if (abs((pfjets_p4().at(i)).eta()) > 2.4)           { continue; }
    LorentzVector pl1, pl2;
    if (isElEvt) {
      pl1 = els_p4().at(id1);
      pl2 = els_p4().at(id2);
    }
    else {
      pl1 = mus_p4().at(id1);
      pl2 = mus_p4().at(id2);
    }
    if (DeltaR(pfjets_p4().at(i),pl1) < 0.4)            { continue; }
    if (DeltaR(pfjets_p4().at(i),pl2) < 0.4)            { continue; }
    fMHT += cms3.pfjets_p4().at(i);
  }
  return fMHT.pt();
}

bool isClusteredCand(const LorentzVector pCand) {
  for (unsigned int i = 0; i < pfjets_p4().size(); i++) {
    if (DeltaR(pCand, pfjets_p4().at(i)) <= 0.4)
      return true;
  }
  return false;
}

ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> t1CMET(TString currentFileName, int use_cleaned_met) {
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017D")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017E")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017F")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_V8_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);

  pT1CMET = getT1CHSMET_fromMINIAOD(jet_corrector, NULL, 0, 0, use_cleaned_met);

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  delete jet_corrector;
  return fT1CMET;
}

double t1CMET_raw_configurable(TString currentFileName, string dataVersion, string mcVersion, double ptThresh, vector<double> etaExclusionRange, bool useHE, bool excludeJets = false, double ptThresh2 = 75., int unc = 0, bool corr = false) {
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);
  JetCorrectionUncertainty jet_uncertainty;
  if (dataVersion == "V8b" || dataVersion == "V8c" || dataVersion == "V8d" || dataVersion == "V9") {
    if (currentFileName.Contains("2017B") || currentFileName.Contains("2017C") || currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) {
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> dummy(0, 0, 0, 0);
      return 0;
      //return dummy;
    }
  }
  else if (dataVersion == "V11C" || dataVersion == "V11D") {
    if (currentFileName.Contains("2017B") || currentFileName.Contains("2017C") || currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) {
      dataVersion = "V11";
      mcVersion = "V11";
    }
  }
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }
  else if (currentFileName.Contains("2017D") && dataVersion != "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017E") && dataVersion != "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }
  else if ((currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) && dataVersion == "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   ); 
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  ); 
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  ); 
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt"); 
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }

  else if (currentFileName.Contains("2017F") && !currentFileName.Contains("09May2018")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017F") && currentFileName.Contains("09May2018")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_09May2018F_V2_DATA_Uncertainty_AK4PFchs.txt";
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);
  jet_uncertainty.setParameters(jetcorr_uncertainty_filename);

  bool uncUp = unc == 1;

  double raw_mod_met = raw_met_modified(jet_corrector, unc > 0 ? &jet_uncertainty : NULL, uncUp, true, 0, useHE, ptThresh, etaExclusionRange, true, ptThresh2, corr);

  /*
  if (excludeJets)
    pT1CMET = getT1CHSMET_fromMINIAOD_configurable(jet_corrector, unc > 0 ? &jet_uncertainty : NULL, uncUp, true, 0, useHE, ptThresh, etaExclusionRange, true, ptThresh2, corr);
  else
    pT1CMET = getT1CHSMET_fromMINIAOD_configurable(jet_corrector, unc > 0 ? &jet_uncertainty : NULL, uncUp, !useHE, 0, useHE, ptThresh, etaExclusionRange, corr);

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  */
  delete jet_corrector;
  return raw_mod_met;
}


ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> t1CMET_configurable(TString currentFileName, string dataVersion, string mcVersion, double ptThresh, vector<double> etaExclusionRange, bool useHE, bool excludeJets = false, double ptThresh2 = 15., int unc = 0, bool corr = false) {
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);
  JetCorrectionUncertainty jet_uncertainty;
  if (dataVersion == "V8b" || dataVersion == "V8c" || dataVersion == "V8d" || dataVersion == "V9") { 
    if (currentFileName.Contains("2017B") || currentFileName.Contains("2017C") || currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) {
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> dummy(0, 0, 0, 0);
      return dummy; 
    }
  }
  else if (dataVersion == "V11C" || dataVersion == "V11D") {
    if (currentFileName.Contains("2017B") || currentFileName.Contains("2017C") || currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) {
      dataVersion = "V11";
      mcVersion = "V11";
    }
  }
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017D") && dataVersion != "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017E") && dataVersion != "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }
  else if ((currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) && dataVersion == "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017DE_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }
  else if (currentFileName.Contains("2017F") && !currentFileName.Contains("09May2018")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017F") && currentFileName.Contains("09May2018")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_09May2018F_V2_DATA_Uncertainty_AK4PFchs.txt";
  }

  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);
  jet_uncertainty.setParameters(jetcorr_uncertainty_filename);

  bool uncUp = unc == 1;

  if (excludeJets)
    pT1CMET = getT1CHSMET_fromMINIAOD_configurable(jet_corrector, unc > 0 ? &jet_uncertainty : NULL, uncUp, true, ptThresh, useHE, ptThresh2, etaExclusionRange, true, ptThresh2, corr);
  else
    pT1CMET = getT1CHSMET_fromMINIAOD_configurable(jet_corrector, unc > 0 ? &jet_uncertainty : NULL, uncUp, false, 0, useHE, ptThresh, etaExclusionRange, false, ptThresh2, corr);

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  delete jet_corrector;
  return fT1CMET;
}


/*
ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> t1CMET_noHE(TString currentFileName, double ptThresh, vector<double> etaExclusionRange, bool useHE) {
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017D")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017E")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017F")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_V8_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);

  pT1CMET = getT1CHSMET_fromMINIAOD_noECJECs(jet_corrector, NULL, 0, 1, 0, useHE, ptThresh, etaExclusionRange);

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  delete jet_corrector;
  return fT1CMET;
}

ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> t1CMET_tightID(TString currentFileName) {
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017D")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017E")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017F")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_V8_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);

  pT1CMET = getT1CHSMET_fromMINIAOD_tightID(jet_corrector, NULL, 0, 0, 0);

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  delete jet_corrector;
  return fT1CMET;
}



ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> t1CMET_PartialJECs(TString currentFileName, bool mc, bool residual) {
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    if (mc) {
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L1FastJet_AK4PFchs.txt"   );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2Relative_AK4PFchs.txt"  );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    }
    if (residual) 
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    if (mc) {
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L1FastJet_AK4PFchs.txt"   );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2Relative_AK4PFchs.txt"  );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    }
    if (residual)
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017D")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    if (mc) {
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L1FastJet_AK4PFchs.txt"   );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2Relative_AK4PFchs.txt"  );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    }
    if (residual)
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017E")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    if (mc) {
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L1FastJet_AK4PFchs.txt"   );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2Relative_AK4PFchs.txt"  );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    }
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017F")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    if (mc) {
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L1FastJet_AK4PFchs.txt"   );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2Relative_AK4PFchs.txt"  );
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    }
    if (residual)
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    if (mc) {
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L1FastJet_AK4PFchs.txt");
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L2Relative_AK4PFchs.txt");
      jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L3Absolute_AK4PFchs.txt");
      jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_V8_MC_Uncertainty_AK4PFchs.txt";
    }
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);

  pT1CMET = getT1CHSMET_fromMINIAOD(jet_corrector, NULL, 0, 0, 0);

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  delete jet_corrector;
  return fT1CMET;
}

ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> t1CMET_version(TString currentFileName, string version) { 
  std::pair<float, float> pT1CMET;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;

  if (currentFileName.Contains("2017B") || currentFileName.Contains("2017C") || currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) {
    ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> dummy(0,0,0,0);
    return dummy;
  }

  FactorizedJetCorrector* jet_corrector(0);
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017B_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017C_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017D")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017D_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017E")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017E_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017F")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017F_" + dataVersion + "_DATA_Uncertainty_AK4PFchs.txt";
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_" + mcVersion + "_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);

  if (version != "V9")
    pT1CMET = getT1CHSMET_fromMINIAOD(jet_corrector, NULL, 0, 0, 0);
  else 
    pT1CMET = getT1CHSMET_fromMINIAOD_noECJECs(jet_corrector, NULL, 0, 1, 0, true, 99999, {2.853, 2.964});

  float metX = pT1CMET.first * cos(pT1CMET.second);
  float metY = pT1CMET.first * sin(pT1CMET.second);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET(metX, metY, 0, pT1CMET.first);
  delete jet_corrector;
  return fT1CMET;
}
*/


vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> correctedJets(TString currentFileName, string version, string version_mc) {

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;


  FactorizedJetCorrector* jet_corrector(0);

  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + version + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + version + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + version + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_" + version + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017B_" + version + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + version + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + version + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + version + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_" + version + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017C_" + version + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017D") && version != "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + version + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + version + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + version + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_" + version + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017D_" + version + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017E") && version != "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + version + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + version + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + version + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_" + version + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017E_" + version + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if ((currentFileName.Contains("2017D") || currentFileName.Contains("2017E")) && version == "V32") {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + version + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + version + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + version + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017DE_" + version + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017DE_" + version + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017F") && !currentFileName.Contains("09May2018")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + version + "_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + version + "_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + version + "_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_" + version + "_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017F_" + version + "_DATA_Uncertainty_AK4PFchs.txt";
  }else if (currentFileName.Contains("2017F") && currentFileName.Contains("09May2018")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_09May2018F_V2_DATA_L2L3Residual_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_09May2018F_V2_DATA_Uncertainty_AK4PFchs.txt";
  }

  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + version_mc + "_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + version_mc + "_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_" + version_mc + "_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_" + version_mc + "_MC_Uncertainty_AK4PFchs.txt";
   }
  else {
    cout << "Did not grab JECs" << endl; // should not happen
  }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);
  
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> v = getCorrectedJets( jet_corrector );
  delete jet_corrector;
  return v;
}
  

/*
vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> apply_JECs(TString currentFileName) {
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vJet_p4;

  std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
  std::string jetcorr_uncertainty_filename;

  FactorizedJetCorrector* jet_corrector(0);
 
  if (currentFileName.Contains("2017B")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017B_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017C")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017C_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017D")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017D_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017E")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017E_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }else if (currentFileName.Contains("2017F")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L1FastJet_AK4PFchs.txt"   );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2Relative_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L3Absolute_AK4PFchs.txt"  );
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017F_V8_DATA_L2L3Residual_AK4PFchs.txt");
  }
  else if (currentFileName.Contains("Fall17")) {
    jetcorr_filenames_pfL1FastJetL2L3.clear();
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L1FastJet_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L2Relative_AK4PFchs.txt");
    jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Fall17_17Nov2017_V8_MC_L3Absolute_AK4PFchs.txt");
    jetcorr_uncertainty_filename = "jetCorrections/Fall17_17Nov2017_V8_MC_Uncertainty_AK4PFchs.txt";
   }

  jet_corrector = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);
   
  
}
*/

TH1D* create_histogram(TString name, int nBins, double x_low, double x_high) {
  TH1D* h = new TH1D(name, "", nBins, x_low, x_high);
  h->Sumw2();
  return h;
}

vector<TH1D*> create_histogram_vector(TString name, int nBins, double x_low, double x_high, int nHists) {
  vector<TH1D*> vHists;
  for (int i = 0; i < nHists; i++) {
    vHists.push_back(create_histogram(name+to_string(i), nBins, x_low, x_high));
  }
  return vHists;
}

vector<TH2D*> create_2Dhistogram_vector(TString name, int nBinsX, double x_low, double x_high, int nBinsY, double y_low, double y_high, int nHists) {
  vector<TH2D*> vHists;
  for (int i = 0; i < nHists; i++) {
    vHists.push_back(new TH2D(name+to_string(i), "", nBinsX, x_low, x_high, nBinsY, y_low, y_high));
    vHists[i]->Sumw2();
  }
  return vHists;
}

void fill_histograms(vector<TH1D*> vHists, double value, vector<double> vWeights) {
  for (int i = 0; i < vHists.size(); i++) {
    vHists[i]->Fill(value, vWeights[i]);
  }
}

void fill_histograms2D(vector<TH2D*> vHists, double x_value, double y_value, vector<double> vWeights) {
  for (int i = 0; i < vHists.size(); i++) {
    vHists[i]->Fill(x_value, y_value, vWeights[i]);
  }
}

vector<vector<vector<TH1D*>>> create_met_histograms(int nEtaRegions, int nCandCats) {
  vector<vector<vector<TH1D*>>> vhMET;
  for (int i=0; i<nEtaRegions; i++) { 
    vector<vector<TH1D*>> vTemp2;
    for (int j=0; j<nCandCats; j++) {
      TString etaIdx = to_string(i);
      TString candIdx = to_string(j);
      TString base = "h_eta" + etaIdx + "_cand" + candIdx;
      TString name1 = base + "MET";
      TString name2 = base + "SumET";
      TString name3 = base + "METPhi";
      vector<TH1D*> vTemp1;
      vTemp1.push_back(new TH1D(name1,"",80,0,400));
      vTemp1.push_back(new TH1D(name2,"",200,0,2000));
      vTemp1.push_back(new TH1D(name3,"",40,-3.142,3.142));
      for (int k=0; k<vTemp1.size(); k++)
        vTemp1[k]->Sumw2();
      vTemp2.push_back(vTemp1);
    }
    vhMET.push_back(vTemp2);
  }
  return vhMET;
}

vector<vector<vector<TH1D*>>> create_met_histograms(int nEtaRegions, int nCandCats, TString idx) {
  vector<vector<vector<TH1D*>>> vhMET;
  for (int i=0; i<nEtaRegions; i++) {
    vector<vector<TH1D*>> vTemp2;
    for (int j=0; j<nCandCats; j++) {
      TString etaIdx = to_string(i);
      TString candIdx = to_string(j);
      TString base = "h_eta" + etaIdx + "_cand" + candIdx;
      TString name1 = base + "MET";
      TString name2 = base + "SumET";
      TString name3 = base + "METPhi";
      vector<TH1D*> vTemp1;
      vTemp1.push_back(new TH1D(name1+idx,"",80,0,400));
      vTemp1.push_back(new TH1D(name2+idx,"",200,0,2000));
      vTemp1.push_back(new TH1D(name3+idx,"",40,-3.142,3.142));
      for (int k=0; k<vTemp1.size(); k++)
        vTemp1[k]->Sumw2();
      vTemp2.push_back(vTemp1);
    }
    vhMET.push_back(vTemp2);
  }
  return vhMET;
}

vector<vector<vector<vector<TH1D*>>>> create_met_histograms_vector(int nEtaRegions, int nCandCats, int nHists) {
  vector<vector<vector<vector<TH1D*>>>> vhMET;
  for (int i=0; i<nEtaRegions; i++) {
    vector<vector<vector<TH1D*>>> vTemp2;
    for (int j=0; j<nCandCats; j++) {
      TString etaIdx = to_string(i);
      TString candIdx = to_string(j);
      TString base = "h_eta" + etaIdx + "_cand" + candIdx;
      TString name1 = base + "MET";
      TString name2 = base + "SumET";
      TString name3 = base + "METPhi";
      vector<vector<TH1D*>> vTemp1;
      vTemp1.push_back(create_histogram_vector(name1, 80, 0, 400, nHists));
      vTemp1.push_back(create_histogram_vector(name2, 200, 0, 2000, nHists));
      vTemp1.push_back(create_histogram_vector(name3, 40, -3.142, 3.142, nHists));
      vTemp2.push_back(vTemp1);
    }
    vhMET.push_back(vTemp2);
  }
  return vhMET;
}

/*
const vector<double> resolution_bins = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 325, 350, 375, 400, 450, 500};

void create_T1CMET_histogram_vectors(TString name, int nHists) {
  const int nBins = 80;
  const double x_low = 0;
  const double x_high = 400;

  vector<TH1D*> hT1CMET = create_histogram_vector("hT1CMET" + name, nBins, x_low, x_high, nHists);
  vector<TH1D*> hT1CMET_up = create_histogram_vector("hT1CMET_up" + name, nBins, x_low, x_high, nHists);
  vector<TH1D*> hT1CMET_down = create_histogram_vector("hT1CMET_down" + name, nBins, x_low, x_high, nHists);

  vector<TH1D*> hT1CMET_0Jets = create_histogram_vector("hT1CMET_0Jets" + name, nBins, x_low, x_high, nHists);
  vector<TH1D*> hT1CMET_0Jets_up = create_histogram_vector("hT1CMET_0Jets_up" + name, nBins, x_low, x_high, nHists);
  vector<TH1D*> hT1CMET_0Jets_down = create_histogram_vector("hT1CMET_0Jets_down" + name, nBins, x_low, x_high, nHists);

  vector<TH1D*> hT1CMET_1pJets = create_histogram_vector("hT1CMET_1pJets" + name, nBins, x_low, x_high, nHists);
  vector<TH1D*> hT1CMET_1pJets_up = create_histogram_vector("hT1CMET_1pJets_up" + name, nBins, x_low, x_high, nHists);
  vector<TH1D*> hT1CMET_1pJets_down = create_histogram_vector("hT1CMET_1pJets_down" + name, nBins, x_low, x_high, nHists);

  vector<TH1D*> hJetPt = create_histogram_vector("hJetPt" + name, nBins, x_low, x_high, nHists);

  vector<TH1D*> hZpT = create_histogram_vector("hZpT" + name, 100, 0, 400, nHists);
  vector<TH1D*> hT1CMET_UPara = create_histogram_vector("hT1CMET_UPara" + name, 200, -400, 400, nHists);
  vector<TH1D*> hT1CMET_UPerp = create_histogram_vector("hT1CMET_UPerp" + name, 100, -200, 200, nHists);
  vector<TH1D*> hT1CMET_UParaPlusqT = create_histogram_vector("hT1CMET_UParaPlusqT" + name, 100, -200, 200, nHists);

  vector<vector<TH1D*>> hResPara;
  vector<vector<TH1D*>> hResPerp;
  vector<vector<TH1D*>> hResponse;
  vector<vector<TH1D*>> hResponseEE;
  vector<vector<TH1D*>> hResponseMM;
  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponse.push_back(create_histogram_vector("hT1CMET_Response" + name + to_string(i), 100, -10, 10, nHists));
    hResponseEE.push_back(create_histogram_vector("hT1CMET_ResponseEE" + name + to_string(i), 100, -10, 10, nHists));
    hResponseMM.push_back(create_histogram_vector("hT1CMET_ResponseMM" + name + to_string(i), 100, -10, 10, nHists));
    hResPara.push_back(create_histogram_vector("hT1CMET_ResPara" + name + to_string(i), 200, -400, 400, nHists));
    hResPerp.push_back(create_histogram_vector("hT1CMET_ResPerp" + name + to_string(i), 100, -200, 200, nHists));
  }   
} 

void fill_T1CMET_histogram_vectors(TString name, int histIdx, TString currentFileName, TString jec_version_data, TString jec_version_mc, int nJets, int type) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET, fT1CMET_up, fT1CMET_down;
  
  double pt_jec_thresh(0), pt_thresh(0);
  vector<double> eta_exclusion_range = {0, 0};
  bool exclude_jets = false
  if (type == 0) // standard, do nothing
  else if (type == 1) { // modified
    pt_jec_thresh = 75;
    eta_exclusion_range = {2.65, 3.139};
  }
  else if (type == 2) { // modified C 
    pt_thresh = 75;
    eta_exclusion_range = {2.65, 3.139};
    exclude_jets = true;
  }
  else if (type == 3) { // modified D
    pt_thresh = 99999999999;
    eta_exclusion_range = {2.65, 3.139};
    exclude_jets = true;
  }

  fT1CMET = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, true, exclude_jets, pt_thresh, 0);
  fT1CMET_up = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, true, exclude_jets, pt_thresh, 1);
  fT1CMET_down = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, true, exclude_jets, pt_thresh, 1);

  

  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets = correctedJets(currentFileName, jec_version_data);  

} 

*/

float sgn(float x) {
  if (x < 0)
    return -1;
  else if (x > 0)
    return 1;
  else
    return 0;

}
