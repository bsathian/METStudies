#ifndef _METHELPER_H_
#define _METHELPER_H_

#include "ScanChain.h"

class MetHelper
{
  public:
    MetHelper(TString name_, int nHists_, string jec_version_data_, string jec_version_mc_, int type_);
    //~MetHelper();

    void create_histograms();
    void create_raw_met_histograms();
    void fill_met_histograms(TString currentFileName, bool isElEvt, int id1, int id2, int nJets, vector<double> weights);
    void fill_raw_met_histograms(bool isElEvt, int id1, int id2, int nJets, vector<double> weights);

  private:
    TString name;
    int nHists;
    int histIdx;
    string jec_version_data;
    string jec_version_mc;
    int type;

    const vector<double> resolution_bins = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 325, 350, 375, 400, 450, 500};
    const int nBins = 80;
    const double x_low = 0;
    const double x_high = 400;

    vector<TH1D*> hT1CMET;
    vector<TH1D*> hT1CMET_up;
    vector<TH1D*> hT1CMET_down;

    vector<TH1D*> hT1CMET_0Jets;
    vector<TH1D*> hT1CMET_0Jets_up;
    vector<TH1D*> hT1CMET_0Jets_down;

    vector<TH1D*> hT1CMET_1pJets;
    vector<TH1D*> hT1CMET_1pJets_up;
    vector<TH1D*> hT1CMET_1pJets_down;

    vector<TH1D*> hJetPt; 

    vector<TH1D*> hZpT;
    vector<TH1D*> hT1CMET_UPara;
    vector<TH1D*> hT1CMET_UPerp;
    vector<TH1D*> hT1CMET_UParaPlusqT;

    vector<vector<TH1D*>> hResPara;
    vector<vector<TH1D*>> hResPerp;
    vector<vector<TH1D*>> hResponse;
    vector<vector<TH1D*>> hResponseEE;
    vector<vector<TH1D*>> hResponseMM;

    vector<TH1D*> hRawMET;
    vector<TH1D*> hRawMET_0Jets;
    vector<TH1D*> hRawMET_1pJets;

    vector<TH1D*> hRawJetPt;
    
    vector<TH1D*> hRawZpT;
    vector<TH1D*> hRaw_UPara;
    vector<TH1D*> hRaw_UPerp;
    vector<TH1D*> hRaw_UParaPlusqT;

    vector<vector<TH1D*>> hRawResPara;
    vector<vector<TH1D*>> hRawResPerp;
    vector<vector<TH1D*>> hRawResponse;
    vector<vector<TH1D*>> hRawResponseEE;
    vector<vector<TH1D*>> hRawResponseMM;
};

inline
MetHelper::MetHelper(TString name_, int nHists_, string jec_version_data_, string jec_version_mc_, int type_){
  name = name_;
  nHists = nHists_;
  jec_version_data = jec_version_data_;
  jec_version_mc = jec_version_mc_;
  type = type_;

  create_histograms();
}

inline
void MetHelper::create_histograms() {
  hT1CMET = create_histogram_vector("hT1CMET" + name, nBins, x_low, x_high, nHists);
  hT1CMET_up = create_histogram_vector("hT1CMET_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_down = create_histogram_vector("hT1CMET_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_0Jets = create_histogram_vector("hT1CMET_0Jets" + name, nBins, x_low, x_high, nHists);
  hT1CMET_0Jets_up = create_histogram_vector("hT1CMET_0Jets_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_0Jets_down = create_histogram_vector("hT1CMET_0Jets_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_1pJets = create_histogram_vector("hT1CMET_1pJets" + name, nBins, x_low, x_high, nHists);
  hT1CMET_1pJets_up = create_histogram_vector("hT1CMET_1pJets_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_1pJets_down = create_histogram_vector("hT1CMET_1pJets_down" + name, nBins, x_low, x_high, nHists);

  hJetPt = create_histogram_vector("hJetPt" + name, nBins, x_low, x_high, nHists);

  hZpT = create_histogram_vector("hZpT" + name, 100, 0, 400, nHists);
  hT1CMET_UPara = create_histogram_vector("hT1CMET_UPara" + name, 200, -400, 400, nHists);
  hT1CMET_UPerp = create_histogram_vector("hT1CMET_UPerp" + name, 100, -200, 200, nHists);
  hT1CMET_UParaPlusqT = create_histogram_vector("hT1CMET_UParaPlusqT" + name, 100, -200, 200, nHists);

  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponse.push_back(create_histogram_vector("hT1CMET_Response" + name + to_string(i), 100, -10, 10, nHists));
    hResponseEE.push_back(create_histogram_vector("hT1CMET_ResponseEE" + name + to_string(i), 100, -10, 10, nHists));
    hResponseMM.push_back(create_histogram_vector("hT1CMET_ResponseMM" + name + to_string(i), 100, -10, 10, nHists));
    hResPara.push_back(create_histogram_vector("hT1CMET_ResPara" + name + to_string(i), 200, -400, 400, nHists));
    hResPerp.push_back(create_histogram_vector("hT1CMET_ResPerp" + name + to_string(i), 100, -200, 200, nHists));
  }   
}

inline
void MetHelper::create_raw_met_histograms() {
  hRawMET = create_histogram_vector("hRawMET", nBins, x_low, x_high, nHists);
  hRawMET_0Jets = create_histogram_vector("hRawMET_0Jets", nBins, x_low, x_high, nHists);
  hRawMET_1pJets = create_histogram_vector("hRawMET_1pJets", nBins, x_low, x_high, nHists);

  hRawJetPt = create_histogram_vector("hRawJetPt", nBins, x_low, x_high, nHists);
  
  hRawZpT = create_histogram_vector("hRawZpT", 100, 0, 400, nHists);
  hRaw_UPara = create_histogram_vector("hRaw_UPara", 200, -400, 400, nHists);
  hRaw_UPerp = create_histogram_vector("hRaw_UPerp", 100, -200, 200, nHists);
  hRaw_UParaPlusqT = create_histogram_vector("hRaw_UParaPlusqT", 100, -200, 200, nHists);

  for (int i = 0; i < resolution_bins.size(); i++) {
    hRawResponse.push_back(create_histogram_vector("hRaw_Response" + to_string(i), 100, -10, 10, nHists));
    hRawResponseEE.push_back(create_histogram_vector("hRaw_ResponseEE" + to_string(i), 100, -10, 10, nHists));
    hRawResponseMM.push_back(create_histogram_vector("hRaw_ResponseMM" + to_string(i), 100, -10, 10, nHists));
    hRawResPara.push_back(create_histogram_vector("hRaw_ResPara" + to_string(i), 200, -400, 400, nHists));
    hRawResPerp.push_back(create_histogram_vector("hRaw_ResPerp" + to_string(i), 100, -200, 200, nHists));
  }
}

inline
void MetHelper::fill_raw_met_histograms(bool isElEvt, int id1, int id2, int nJets, vector<double> weights) {
  double metX = cms3.evt_pfmet_raw() * cos(cms3.evt_pfmetPhi_raw());
  double metY = cms3.evt_pfmet_raw() * sin(cms3.evt_pfmetPhi_raw());
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fRawMET(metX, metY, 0, cms3.evt_pfmet_raw());

  for(unsigned int iJet = 0; iJet < cms3.pfjets_p4().size(); iJet++){
     LorentzVector jetp4_uncorr = cms3.pfjets_p4().at(iJet)*cms3.pfjets_undoJEC().at(iJet);
     fill_histograms(hRawJetPt, jetp4_uncorr.pt(), weights);
  }

  fill_histograms(hRawMET, fRawMET.pt(), weights);
  if (nJets == 0)
    fill_histograms(hRawMET_0Jets, fRawMET.pt(), weights);
  else
    fill_histograms(hRawMET_1pJets, fRawMET.pt(), weights);

  double boson_pt, u_para, u_perp, u_para_plus_qt;
  boson_pt = boson_pT(isElEvt, id1, id2, fRawMET, u_para, u_perp, u_para_plus_qt);

  int resolution_idx = find_index(resolution_bins, boson_pt);
  fill_histograms(hZpT, boson_pt, weights);
  fill_histograms(hRaw_UPara, u_para, weights);
  fill_histograms(hRaw_UPerp, u_perp, weights);
  fill_histograms(hRaw_UParaPlusqT, u_para_plus_qt, weights);

  fill_histograms(hRawResponse[resolution_idx], -u_para/boson_pt, weights);
  if (isElEvt)      fill_histograms(hRawResponseEE[resolution_idx], -u_para/boson_pt, weights);
  else              fill_histograms(hRawResponseMM[resolution_idx], -u_para/boson_pt, weights);
  fill_histograms(hRawResPara[resolution_idx], u_para, weights);
  fill_histograms(hRawResPerp[resolution_idx], u_perp, weights);
}

inline
void MetHelper::fill_met_histograms(TString currentFileName, bool isElEvt, int id1, int id2, int nJets, vector<double> weights) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET, fT1CMET_up, fT1CMET_down;

  double pt_jec_thresh(0), pt_thresh(0);
  vector<double> eta_exclusion_range = {0, 0};
  bool exclude_jets = false;
  if (type == 0) {

  }// standard, do nothing
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

  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets = correctedJets(currentFileName, jec_version_data, jec_version_mc);  
  for (unsigned int i = 0; i < vCorrectedJets.size(); i++) {
    fill_histograms(hJetPt, vCorrectedJets[i].pt(), weights);
  }

  fT1CMET = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, true, exclude_jets, pt_thresh, 0);
  fT1CMET_up = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, true, exclude_jets, pt_thresh, 1);
  fT1CMET_down = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, true, exclude_jets, pt_thresh, 2);

  if (type == 2 || type == 3) {
    cout << fT1CMET.pt() << endl;
  }

  fill_histograms(hT1CMET, fT1CMET.pt(), weights);
  fill_histograms(hT1CMET_up, fT1CMET_up.pt(), weights);
  fill_histograms(hT1CMET_down, fT1CMET_down.pt(), weights);

  if (nJets == 0) {
    fill_histograms(hT1CMET_0Jets, fT1CMET.pt(), weights);
    fill_histograms(hT1CMET_0Jets_up, fT1CMET_up.pt(), weights);
    fill_histograms(hT1CMET_0Jets_down, fT1CMET_down.pt(), weights);
  }
  else {
    fill_histograms(hT1CMET_1pJets, fT1CMET.pt(), weights);
    fill_histograms(hT1CMET_1pJets_up, fT1CMET_up.pt(), weights);
    fill_histograms(hT1CMET_1pJets_down, fT1CMET_down.pt(), weights);
  }


  // Response & Resolution
  double boson_pt, u_para, u_perp, u_para_plus_qt;
  boson_pt = boson_pT(isElEvt, id1, id2, fT1CMET, u_para, u_perp, u_para_plus_qt);

  int resolution_idx = find_index(resolution_bins, boson_pt);
  fill_histograms(hZpT, boson_pt, weights);
  fill_histograms(hT1CMET_UPara, u_para, weights);
  fill_histograms(hT1CMET_UPerp, u_perp, weights);
  fill_histograms(hT1CMET_UParaPlusqT, u_para_plus_qt, weights);

  fill_histograms(hResponse[resolution_idx], -u_para/boson_pt, weights);
  if (isElEvt)      fill_histograms(hResponseEE[resolution_idx], -u_para/boson_pt, weights);
  else              fill_histograms(hResponseMM[resolution_idx], -u_para/boson_pt, weights);
  fill_histograms(hResPara[resolution_idx], u_para, weights);
  fill_histograms(hResPerp[resolution_idx], u_perp, weights);


}

#endif // _METHELPER_H_