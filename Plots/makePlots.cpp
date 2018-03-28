#include "PlotHelper.h"

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
  TFile* fData = new TFile("histograms/Zll_histograms_" + eras + ".root");
  TFile* fDY = new TFile("histograms/Zll_histograms_Drell-Yan_" + eras + ".root");
  TFile* fDiBoson = new TFile("histograms/Zll_histograms_DiBoson_" + eras + ".root");
  TFile* fTriBoson = new TFile("histograms/Zll_histograms_TriBoson_" + eras + ".root");
  TFile* fTop = new TFile("histograms/Zll_histograms_Top_" + eras + ".root");
  vector<TFile*> vFiles = {fData, fDY, fDiBoson, fTriBoson, fTop};

  TCanvas* c1 = new TCanvas("c1", "histos", 600, 800);
  make_plot(c1, vFiles, output_name, "hT1CMET", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET"}, 1); 
}
