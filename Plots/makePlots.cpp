#include "PlotHelper.h"

const int nEtaRegions = 6;
const int nCandCats = 4;

void make_plot(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name, TString x_label, double lumi, double scale, vector<TString> vInfo, int idx) {
  TH1D* hData = (TH1D*)vFiles[0]->Get(hist_name + "0");
  vector<TH1D*> hMC;
  for (int i = 1; i < vFiles.size(); i++) 
    hMC.push_back((TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx)));
  Comparison* c = new Comparison(c1, hData, hMC);
  if (lumi == 4.8)
    c->give_info({"2017 Run B"});
  else if (lumi == 23.5)
    c->give_info({"2017 Runs C,D,E"});
  else if (lumi == 13.5)
    c->give_info({"2017 Run F"});
  else if (lumi == 9.76)
    c->give_info({"2017 Run C"});
  else if (lumi == 13.74)
    c->give_info({"2017 Runs D,E"});
  c->set_filename(output_name);
  c->set_rat_label("#frac{Data}{MC}");
  c->set_legend_labels({"2017 Data", "Drell-Yan", "DiBoson", "TriBoson", "Top"});
  c->set_x_label(x_label);
  c->set_y_label("Events");
  c->set_data_drawOpt("E");
  c->set_lumi(lumi);
  c->set_scale(scale);
  if (hist_name.Contains("T1CMET"))
    c->set_x_bin_range({1,70});
  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete c;
} 

double get_scaleMC(vector<TFile*> vFiles, TString hist_name, int histIdx, double lumi) {
  TH1D* hData = (TH1D*)vFiles[0]->Get(hist_name + "0");
  TH1D* hMC;
  for (int i = 1; i < vFiles.size(); i++) {
    if (i == 1)
      hMC = (TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx));
    else
      hMC->Add((TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx)));
  }
  cout << "Data/MC: " << hData->Integral()/(hMC->Integral() * lumi) << endl;
  return hData->Integral()/(hMC->Integral());
}

int main(int argc, char* argv[])
{
  // Style options
  gStyle->SetOptStat(0);
  gStyle->SetPalette(kRainBow,0);
  gStyle->SetPaintTextFormat(".2f");
  gStyle->SetTickLength(0.01);
  gStyle->SetErrorX(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetTitleAlign(33);
  gStyle->SetTitleX(.93);
  gStyle->SetTitleFontSize(0.03);


  TString eras = argv[1];
  string eras_s = argv[1];
  double lumi = atof(argv[2]);
  string output_name = "plots_" + eras_s + ".pdf";

  int histIdx;
  if (eras == "B") 	histIdx = 0;
  if (eras == "C")	histIdx = 1;
  if (eras == "D,E")	histIdx = 2;
  if (eras == "F")	histIdx = 3;

  TFile* fData = new TFile("../histograms/Zll_histograms_" + eras + ".root");
  TFile* fDY = new TFile("../histograms/Zll_histograms_Drell-Yan.root");
  TFile* fDiBoson = new TFile("../histograms/Zll_histograms_DiBoson.root");
  TFile* fTriBoson = new TFile("../histograms/Zll_histograms_TriBoson.root");
  TFile* fTop = new TFile("../histograms/Zll_histograms_Top.root");
  vector<TFile*> vFiles = {fData, fDY, fDiBoson, fTriBoson, fTop};

  TCanvas* c1 = new TCanvas("c1", "histos", 600, 800);
  double scaleMC = get_scaleMC(vFiles, "hT1CMET", histIdx, lumi);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET"}, 0); 
  make_plot(c1, histIdx, vFiles, output_name, "hNJets", "N_{jets}", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hCCpT", "p_{T} [GeV]", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hPhotonpT", "p_{T} [GeV]", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNeutpT", "p_{T} [GeV]", lumi, -1, {"Neutral Hadron Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hCCeta", "|#eta|", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hPhotoneta", "|#eta|", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNeuteta", "|#eta|", lumi, -1, {"Neutral Hadron Candidates"}, 1); 


  // Pf Cand Quantities, split by eta and type
  vector<TString> vEta = {"0 < |#eta| < 1.3", "1.3 < |#eta| < 1.6", "1.6 < |#eta| < 2.5", "2.5 < |#eta| < 3.0", "|#eta| > 3.0", "All #eta"};
  vector<TString> vCands = {"Charged Candidates", "Photon Candidates", "Neutral Hadrons"};
  for (int i=0; i<nEtaRegions-1; i++) {
    TString etaIdx = to_string(i);
    for (int j=0; j<nCandCats-1; j++) {
      TString candIdx = to_string(j);
      vector<TString> v1;
      v1.push_back(vCands[j]);
      v1.push_back(vEta[i]);
      TString base = "h_eta" + etaIdx + "_cand"+ candIdx;
      make_plot(c1, histIdx, vFiles, output_name, base + "MET", "E_{T}^{miss} [GeV]", lumi, scaleMC, v1, 1);
      make_plot(c1, histIdx, vFiles, output_name, base + "SumET", "Sum E_{T} [GeV]", lumi, scaleMC, v1, 1);
      make_plot(c1, histIdx, vFiles, output_name, base + "METPhi", "E_{T}^{miss} #phi", lumi, scaleMC, v1, 1);
    }
  }

  // Pf Cand Quantities, split by eta, inclusive in type
  for (int i=0; i<nEtaRegions; i++) {
    TString etaIdx = to_string(i);
    vector<TString> v1;
    v1.push_back("All Candidates");
    v1.push_back(vEta[i]);
    TString base = "h_eta" + etaIdx + "_cand3";
    make_plot(c1, histIdx, vFiles, output_name, base + "MET", "E_{T}^{miss} [GeV]", lumi, scaleMC, v1, 1);
    make_plot(c1, histIdx, vFiles, output_name, base + "SumET", "Sum E_{T} [GeV]", lumi, scaleMC, v1, 1);
    make_plot(c1, histIdx, vFiles, output_name, base + "METPhi", "E_{T}^{miss} #phi", lumi, scaleMC, v1, 1);
  }

  make_plot(c1, histIdx, vFiles, output_name, "hNCands", "Candidate Multiplicity", lumi, -1, {"All Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNCCands", "Candidate Multiplicity", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNPCands", "Candidate Multiplicity", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNNCands", "Candidate Multiplicity", lumi, -1, {"Neutral Hadron Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hSumETEndcapPhotonsClustered", "Sum E_{T} [GeV]", lumi, -1, {"Clustered Photon Candidates", "2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hSumETEndcapPhotonsUnclustered", "Sum E_{T} [GeV]", lumi, -1, {"Unclustered Photon Candidates", "2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hPhotonpTEndcap", "p_{T} [GeV]", lumi, -1, {"Photon Candidates", "2.3 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNVtx", "N_{vtx}", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hRawMETMod_v2", "E_{T}^{miss} [GeV]", lumi, -1, {"Raw MET (No Low pT HE)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hRawMETMod", "E_{T}^{miss} [GeV]", lumi, -1, {"Raw MET (No Neutral EC)"}, 1);  
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMETMod", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)"}, 1); 
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v1", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v2", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v3", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v4", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hLeadJetPt", "p_{T} [GeV]", lumi, -1, {"Lead jet p_{T}"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt", "p_{T} [GeV]", lumi, -1, {"Jet p_{T}"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hLeadJetEta", "#eta [GeV]", lumi, -1, {"Lead jet #eta"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetEta", "#eta [GeV]", lumi, -1, {"Jet #eta"}, 1);

  // 0-1 Jet Bins
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0JetsMod", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "0 Jets"}, 1); 
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v1", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v2", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v3", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v4", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJetsMod", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v1", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v2", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v3", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v4", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 2);

}
