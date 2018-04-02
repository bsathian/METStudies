#include "PlotHelper.h"

const int nEtaRegions = 6;
const int nCandCats = 4;


void make_plot(TCanvas* c1, vector<TFile*> vFiles, string output_name, TString hist_name, TString x_label, double lumi, double scale, vector<TString> vInfo, int idx) {
  TH1D* hData = (TH1D*)vFiles[0]->Get(hist_name);
  vector<TH1D*> hMC;
  for (int i = 1; i < vFiles.size(); i++) 
    hMC.push_back((TH1D*)vFiles[i]->Get(hist_name));
  Comparison* c = new Comparison(c1, hData, hMC);
  c->set_filename(output_name);
  c->set_rat_label("#frac{Data}{MC}");
  c->set_legend_labels({"2017 Data", "Drell-Yan", "DiBoson", "TriBoson", "Top"});
  c->set_x_label(x_label);
  c->set_y_label("Events");
  c->set_data_drawOpt("E");
  c->set_lumi(lumi);
  c->set_scale(scale);
  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete c;
} 

double get_scaleMC(vector<TFile*> vFiles, TString hist_name) {
  TH1D* hData = (TH1D*)vFiles[0]->Get(hist_name);
  TH1D* hMC;
  for (int i = 1; i < vFiles.size(); i++) {
    if (i == 1)
      hMC = (TH1D*)vFiles[i]->Get(hist_name);
    else
      hMC->Add((TH1D*)vFiles[i]->Get(hist_name));
  }
  return hData->Integral()/hMC->Integral();
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
  TFile* fData = new TFile("../histograms/Zll_histograms_" + eras + ".root");
  TFile* fDY = new TFile("../histograms/Zll_histograms_Drell-Yan_" + eras + ".root");
  TFile* fDiBoson = new TFile("../histograms/Zll_histograms_DiBoson_" + eras + ".root");
  TFile* fTriBoson = new TFile("../histograms/Zll_histograms_TriBoson_" + eras + ".root");
  TFile* fTop = new TFile("../histograms/Zll_histograms_Top_" + eras + ".root");
  vector<TFile*> vFiles = {fData, fDY, fDiBoson, fTriBoson, fTop};

  TCanvas* c1 = new TCanvas("c1", "histos", 600, 800);
  double scaleMC = get_scaleMC(vFiles, "hT1CMET");
  make_plot(c1, vFiles, output_name, "hT1CMET", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET"}, 0); 
  make_plot(c1, vFiles, output_name, "hNJets", "N_{jets}", lumi, -1, {""}, 1);
  make_plot(c1, vFiles, output_name, "hCCpT", "p_{T} [GeV]", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hPhotonpT", "p_{T} [GeV]", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hNeutpT", "p_{T} [GeV]", lumi, -1, {"Neutral Hadron Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hCCeta", "|#eta|", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hPhotoneta", "|#eta|", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hNeuteta", "|#eta|", lumi, -1, {"Neutral Hadron Candidates"}, 1); 


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
      make_plot(c1, vFiles, output_name, base + "MET", "E_{T}^{miss} [GeV]", lumi, scaleMC, v1, 1);
      make_plot(c1, vFiles, output_name, base + "SumET", "Sum E_{T} [GeV]", lumi, scaleMC, v1, 1);
      make_plot(c1, vFiles, output_name, base + "METPhi", "E_{T}^{miss} #phi", lumi, scaleMC, v1, 1);
    }
  }

  // Pf Cand Quantities, split by eta, inclusive in type
  for (int i=0; i<nEtaRegions; i++) {
    TString etaIdx = to_string(i);
    vector<TString> v1;
    v1.push_back("All Candidates");
    v1.push_back(vEta[i]);
    TString base = "h_eta" + etaIdx + "_cand3";
    make_plot(c1, vFiles, output_name, base + "MET", "E_{T}^{miss} [GeV]", lumi, scaleMC, v1, 1);
    make_plot(c1, vFiles, output_name, base + "SumET", "Sum E_{T} [GeV]", lumi, scaleMC, v1, 1);
    make_plot(c1, vFiles, output_name, base + "METPhi", "E_{T}^{miss} #phi", lumi, scaleMC, v1, 1);
  }

  make_plot(c1, vFiles, output_name, "hNCands", "Candidate Multiplicity", lumi, -1, {"All Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hNCCands", "Candidate Multiplicity", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hNPCands", "Candidate Multiplicity", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hNNCands", "Candidate Multiplicity", lumi, -1, {"Neutral Hadron Candidates"}, 1);
  make_plot(c1, vFiles, output_name, "hSumETEndcapPhotonsClustered", "Sum E_{T} [GeV]", lumi, -1, {"Clustered Photon Candidates", "2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, vFiles, output_name, "hSumETEndcapPhotonsUnclustered", "Sum E_{T} [GeV]", lumi, -1, {"Unclustered Photon Candidates", "2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, vFiles, output_name, "hPhotonpTEndcap", "p_{T} [GeV]", lumi, -1, {"Photon Candidates", "2.3 < |#eta| < 3.0"}, 1);
  make_plot(c1, vFiles, output_name, "hNVtx", "N_{vtx}", lumi, -1, {""}, 1);
  make_plot(c1, vFiles, output_name, "hRawMETMod_v2", "E_{T}^{miss} [GeV]", lumi, -1, {"Raw MET (No Low pT HE)"}, 1);
  make_plot(c1, vFiles, output_name, "hRawMETMod", "E_{T}^{miss} [GeV]", lumi, -1, {"Raw MET (No HE)"}, 1);  
  make_plot(c1, vFiles, output_name, "hT1CMETMod", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No HE)"}, 2); 

}
