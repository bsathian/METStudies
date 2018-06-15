#include "PlotHelper.h"

const int nEtaRegions = 6;
const int nCandCats = 4;

void make_plot(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name, TString x_label, double lumi, double scale, vector<TString> vInfo, int idx) {
  TH1D* hData = (TH1D*)vFiles[0]->Get(hist_name + "0");
  vector<TH1D*> hMC;
  for (int i = 1; i < vFiles.size(); i++) 
    hMC.push_back((TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx)));
  if (hist_name == "hT1CMET" || hist_name == "hT1CMET_tightID")
    cout << hMC[0]->Integral(41,80) << endl;
  Comparison* c = new Comparison(c1, hData, hMC);
  if (lumi == 4.8)
    c->give_info({"2017 Run B"});
  else if (lumi == 23.5)
    c->give_info({"2017 Runs C,D,E"});
  else if (lumi == 13.5)
    c->give_info({"2017 Run F (09May2018 ReReco)"});
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

  if (hist_name == "hT1CMET" || hist_name == "hT1CMET_tightID")
    cout << hMC[0]->Integral(41,80) << endl;
  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete hData;
  for (int i = 0; i < hMC.size(); i++)
    delete hMC[i];
  delete c;
} 

void make_2Dplot(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name, TString x_label, TString y_label, double lumi, double scale, vector<TString> vInfo, int idx) {
  TH2D* hData = (TH2D*)vFiles[0]->Get(hist_name + "0");
  vector<TH2D*> hMC;
  for (int i = 1; i < vFiles.size(); i++)
    hMC.push_back((TH2D*)vFiles[i]->Get(hist_name + to_string(histIdx)));
  TH2D* hMCSum;
  hMCSum = (TH2D*)hMC[0]->Clone("hMCSum");
  for (int i = 1; i < hMC.size(); i++)
    hMCSum->Add(hMC[i]);
  cout << hData->GetEntries() << endl;
  Comparison* c = new Comparison(c1, hData, hMCSum);
  c->set_filename(output_name);
  c->set_x_label(x_label);
  c->set_y_label(y_label);
  c->set_lumi(lumi);
  c->set_scale(scale);
  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete hData;
  for (int i = 0; i < hMC.size(); i++)
    delete hMC[i];
  delete hMCSum;
  delete c;
}

void make_resolution_plot(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name1, TString hist_name2, TString label1, TString label2, TString x_label, TString y_label, double mLumi, double scale, vector<TString> vInfo, vector<double> y_lim, int idx) {
  c1->cd();
  TPad* mainPad = new TPad("p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  mainPad->SetBottomMargin(0.02);
  mainPad->SetRightMargin(0.07);
  mainPad->SetTopMargin(0.08);
  mainPad->SetLeftMargin(0.12);
  mainPad->Draw();
  mainPad->cd();

  double resolution_bins[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 400};
  int n_resolution_bins = (sizeof(resolution_bins)/sizeof(resolution_bins[0]))-1;

  TH1D* hD1 = new TH1D("hD1", "", n_resolution_bins, resolution_bins);
  TH1D* hD2 = new TH1D("hD2", "", n_resolution_bins, resolution_bins);
  TH1D* hM1 = new TH1D("hM1", "", n_resolution_bins, resolution_bins);
  TH1D* hM2 = new TH1D("hM2", "", n_resolution_bins, resolution_bins);  
  
  for (int i = 0; i < n_resolution_bins; i++) {
    TH1D* hDataTemp1 = (TH1D*)vFiles[0]->Get(hist_name1 + to_string(i+1) + "0");
    TH1D* hDataTemp2 = (TH1D*)vFiles[0]->Get(hist_name2 + to_string(i+1) + "0");
    TH1D* hMCTemp1 = (TH1D*)vFiles[1]->Get(hist_name1 + to_string(i+1) + to_string(histIdx));
    TH1D* hMCTemp2 = (TH1D*)vFiles[1]->Get(hist_name2 + to_string(i+1) + to_string(histIdx));
    for (int j = 2; j < vFiles.size(); j++) {
      hMCTemp1->Add((TH1D*)vFiles[j]->Get(hist_name1 + to_string(i+1) + to_string(histIdx)));
      hMCTemp2->Add((TH1D*)vFiles[j]->Get(hist_name2 + to_string(i+1) + to_string(histIdx)));
    }
    if (hist_name1.Contains("Perp") || hist_name1.Contains("Para")) {
      hD1->SetBinContent(i+1, hDataTemp1->GetStdDev());
      hD2->SetBinContent(i+1, hDataTemp2->GetStdDev());
      hM1->SetBinContent(i+1, hMCTemp1->GetStdDev());
      hM2->SetBinContent(i+1, hMCTemp2->GetStdDev());
      hD1->SetBinError(i+1, hDataTemp1->GetStdDevError());
      hD2->SetBinError(i+1, hDataTemp2->GetStdDevError()); 
      hM1->SetBinError(i+1, hMCTemp1->GetStdDevError()); 
      hM2->SetBinError(i+1, hMCTemp2->GetStdDevError()); 
    }
    else {
      hD1->SetBinContent(i+1, hDataTemp1->GetMean());
      hD2->SetBinContent(i+1, hDataTemp2->GetMean());
      hM1->SetBinContent(i+1, hMCTemp1->GetMean());
      hM2->SetBinContent(i+1, hMCTemp2->GetMean());
      hD1->SetBinError(i+1, hDataTemp1->GetMeanError());
      hD2->SetBinError(i+1, hDataTemp2->GetMeanError());
      hM1->SetBinError(i+1, hMCTemp1->GetMeanError());
      hM2->SetBinError(i+1, hMCTemp2->GetMeanError());
    }

    delete hDataTemp1;
    delete hDataTemp2;
    delete hMCTemp1;
    delete hMCTemp2;
  }
 
  bool resolution_plot = !(hist_name1.Contains("Perp") || hist_name1.Contains("Para"));
 
  hD1->Draw("E");
  hD2->Draw("SAME,E");
  gPad->RedrawAxis();
  vector<TH1D*> mVHData = {hD1, hD2};
  vector<int> dataColors = {kBlack, kRed};
  for (int i=0; i<mVHData.size(); i++) {
    mVHData[i]->SetMarkerStyle(20);
    mVHData[i]->SetMarkerColor(dataColors[i]);
    mVHData[i]->SetLineColor(dataColors[i]);
    mVHData[i]->SetLineWidth(2);
    mVHData[i]->GetXaxis()->SetLabelOffset(999);
    mVHData[i]->GetXaxis()->SetLabelSize(0);
    mVHData[i]->GetYaxis()->SetTitle(y_label);
    mVHData[i]->GetYaxis()->SetRangeUser(y_lim[0], y_lim[1]);
  }

  TLine* h_line = new TLine(0, 1, 400, 1);
  if (resolution_plot) {
    h_line->SetLineWidth(2);
    h_line->SetLineStyle(2);
    h_line->Draw("SAME");
  }

  double fs = 0.04;
  TLatex* cms = new TLatex(0.20, 0.93, "CMS Preliminary");
  cms->SetTextSize(fs);
  cms->SetNDC(kTRUE);
  cms->Draw("SAME");

  TLatex* lumi;
  if (mLumi != -1) {
    TString lumiText = Form("%.2f",mLumi);
    lumiText += " fb^{-1} (13 TeV)";
    lumi = new TLatex(0.66, 0.93, lumiText.Data());
    lumi->SetTextSize(fs);
    lumi->SetNDC(kTRUE);
    lumi->Draw("SAME");
  }
  else {
    lumi = new TLatex(0.73, 0.93, "(13 TeV)");
    lumi->SetTextSize(fs);
    lumi->SetNDC(kTRUE);
    lumi->Draw("SAME");
  }

  if (mLumi == 4.8)
    vInfo.push_back("2017 Run B");
  else if (mLumi == 13.5)
    vInfo.push_back("2017 Run F (09May2018 ReReco)");
  else if (mLumi == 9.76)
    vInfo.push_back("2017 Run C");
  else if (mLumi == 13.74)
    vInfo.push_back("2017 Runs D,E");

  vector<TLatex*> t(vInfo.size());
  for(int i=0; i<vInfo.size(); i++) {
    double j = i;
    j *= 0.05;
    t[i] = new TLatex(0.20, 0.85-j, vInfo[i]);
    t[i]->SetTextSize(fs);
    t[i]->SetNDC(kTRUE);
    t[i]->Draw("SAME");
  }

  vector<TString> mVLegendLabels = {"All JECs", "Modified JECs"}; 
  if (mVLegendLabels.size() > 0) {
    double j = mVHData.size()*0.05;
    TLegend* l1 = new TLegend(0.60, 0.77-j, 0.92, 0.89);
    for (int i=0; i<mVHData.size(); i++)
      l1->AddEntry(mVHData[i], mVLegendLabels[i], "lep");
    //int idxMC = mVHData.size();
    //for (int i=0; i<mVHMC.size(); i++) {
    //  if (!mBothData) l1->AddEntry(mVHMC[i], mVLegendLabels[idxMC+i], "f");
    //  else l1->AddEntry(mHMC, mVLegendLabels[idxMC], "lep");
    //}
    l1->SetBorderSize(0);
    l1->Draw("SAME");
  }

  c1->cd();
  TPad* ratPad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.3);
  ratPad->SetBottomMargin(0.36);
  ratPad->SetRightMargin(0.07);
  ratPad->SetTopMargin(0.07);
  ratPad->SetLeftMargin(0.12);
  ratPad->Draw();
  ratPad->cd();
  ratPad->SetGridy();


  vector<TH1D*> mVHRat;
  vector<TH1D*> hMC = {hM1, hM2}; 
  mVHRat.push_back((TH1D*)hD1->Clone("mVHRat0"));
  mVHRat.push_back((TH1D*)hD2->Clone("mVHRat1"));
  mVHRat[0]->SetTitle("");
  mVHRat[0]->Divide(hMC[0]);
  mVHRat[0]->GetYaxis()->SetRangeUser(0.5,1.5);
  mVHRat[0]->GetYaxis()->SetLabelSize(0.08);
  mVHRat[0]->GetXaxis()->SetLabelSize(0.08);
  mVHRat[0]->GetYaxis()->SetNdivisions(5);

  TString mRatLabel = "#frac{Data}{MC}";
  mVHRat[0]->GetYaxis()->SetTitle(mRatLabel);
  mVHRat[0]->GetYaxis()->SetTitleSize(0.08);
  mVHRat[0]->GetYaxis()->SetTitleOffset(0.65);
  mVHRat[0]->GetYaxis()->CenterTitle();

  mVHRat[0]->GetXaxis()->SetTitle(x_label);
  mVHRat[0]->GetXaxis()->SetTitleOffset(1.1);
  mVHRat[0]->GetXaxis()->SetTitleSize(0.12);

  mVHRat[0]->SetMarkerStyle(20);
  //mVHRat[0]->SetMarkerSize(1);
  mVHRat[0]->SetStats(0);
  //mVHRat[0]->GetXaxis()->SetRange(mXBinRange[0], mXBinRange[1]);
  mVHRat[0]->SetMarkerColor(dataColors[0]);
  mVHRat[0]->SetLineColor(dataColors[0]);
  mVHRat[0]->SetFillColor(dataColors[0]);

  mVHRat[0]->Draw("e1x0");
  mVHRat[0]->GetXaxis()->SetLabelOffset();
  mVHRat[0]->GetXaxis()->SetLabelSize(0.07);


  for (int i=1; i<mVHData.size(); i++) {
    TString idx = Form("%d", i);
    mVHRat.push_back((TH1D*)mVHData[i]->Clone("mVHRat"+idx));
    mVHRat[i]->Divide(hMC[i]);
    mVHRat[i]->SetMarkerStyle(20);
    mVHRat[i]->SetMarkerColor(dataColors[i]);
    mVHRat[i]->SetFillColor(dataColors[i]);
    mVHRat[i]->SetLineColor(dataColors[i]);
    mVHRat[i]->SetStats(0);
    mVHRat[i]->Draw("e1x0, same");
  }
 
  if (idx == 0)
    c1->Print((output_name+"(").c_str());
  else if (idx == 1)
    c1->Print((output_name).c_str());
  else if (idx == 2)
    c1->Print((output_name+")").c_str());
  c1->Clear("D");

  delete h_line;
  delete mainPad;
  delete ratPad;
  delete hD1;
  delete hD2;
  delete hM1;
  delete hM2;
}

void make_double_plot(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name1, TString hist_name2, TString label1, TString label2, TString x_label, double lumi, double scale, vector<TString> vInfo, bool data, int idx) {
  TH1D* h1;
  TH1D* h2;
  if (data) {
    h1 = (TH1D*)vFiles[0]->Get(hist_name1 + "0");
    h2 = (TH1D*)vFiles[0]->Get(hist_name2 + "0");
  }  
  else {
    h1 = (TH1D*)vFiles[1]->Get(hist_name1 + to_string(histIdx)); 
    h2 = (TH1D*)vFiles[1]->Get(hist_name2 + to_string(histIdx));
    for (int i = 2; i < vFiles.size(); i++) {
      h1->Add((TH1D*)vFiles[i]->Get(hist_name1 + to_string(histIdx)));
      h2->Add((TH1D*)vFiles[i]->Get(hist_name2 + to_string(histIdx)));
    }
  }
  Comparison* c = new Comparison(c1, h1, h2);
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
  c->set_both_data();
  TString rat_label = "#frac{" + label1 + "}{" + label2 + "}";
  c->set_rat_label(rat_label);
  c->set_legend_labels({label1, label2});
  if (data)
    c->give_info("Data vs. Data");
  else
    c->give_info("MC vs. MC");
  c->set_x_label(x_label);
  c->set_y_label("Events");
  c->set_lumi(lumi);
  c->set_scale(scale);
  c->set_x_bin_range({1,80});
  c->set_rat_lim_range({0.0, 5.0});
  c->plot(idx);

  delete h1;
  delete h2;

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
  double scale = hData->Integral()/(hMC->Integral());
  delete hMC;
  delete hData;
  return scale; 
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
  if (eras == "F" || eras == "Fv2")	histIdx = 3;


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
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt", "p_{T} [GeV]", lumi, scaleMC, {"Jet p_{T}"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hLeadJetEta", "#eta [GeV]", lumi, -1, {"Lead jet #eta"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetEta", "#eta [GeV]", lumi, scaleMC, {"Jet #eta"}, 1);

  // 0-1 Jet Bins
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0JetsMod", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Neutral EC)", "0 Jets"}, 1); 
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v1", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v2", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v3", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v4", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJetsMod", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Neutral EC)", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v1", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v2", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Neutral EC)", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v3", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET", "No JECs for p_{T} < 30 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v4", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET", "No JECs for p_{T} < 50 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoResiduals", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (No Resdiuals)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_tightID", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (Tight Jet ID)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoResiduals", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Resdiuals)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_tightID", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (Tight Jet ID)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoResiduals", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (No Resdiuals)", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_tightID", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (Tight Jet ID)", "#geq 1 Jets"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hJet_Emfrac", "Jet EM Fraction", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac", "Jet Neutral EM Fraction", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac", "Jet Neutral Hadronic Fraction", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Charged_Hadfrac", "Jet Charged Hadronic Fraction", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_hf", "Jet Neutral EM Fraction (HF)", lumi, -1, {""}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_hf", "Jet Neutral Hadronic Fraction (HF)", lumi, -1, {""}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_RunFV6", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (V6 JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt_RunFV6", "Jet p_{T} [GeV]", lumi, scaleMC, {"Jet p_{T} (V6 JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_RunFV6", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V6 JECs)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_RunFV6", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V6 JECs)", "#geq 1 Jets"}, 1);
  
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_RunFV8b", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (V8b JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt_RunFV8b", "Jet p_{T} [GeV]", lumi, scaleMC, {"Jet p_{T} (V8b JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_RunFV8b", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V8b JECs)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_RunFV8b", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V8b JECs)", "#geq 1 Jets"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_RunFV8c", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (V8c JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt_RunFV8c", "Jet p_{T} [GeV]", lumi, scaleMC, {"Jet p_{T} (V8c JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_RunFV8c", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V8c JECs)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_RunFV8c", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V8c JECs)", "#geq 1 Jets"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_RunFV8d", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (V8d JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt_RunFV8d", "Jet p_{T} [GeV]", lumi, scaleMC, {"Jet p_{T} (V8d JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_RunFV8d", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V8d JECs)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_RunFV8d", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V8d JECs)", "#geq 1 Jets"}, 1);

  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET", "h_eta5_cand3MET", "Type-1 MET", "Raw MET", "E_{T}^{miss} [GeV]", lumi, -1, {""}, true, 1);
  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET", "h_eta5_cand3MET", "Type-1 MET", "Raw MET","E_{T}^{miss} [GeV]", lumi, -1, {""}, false, 1);

  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoResiduals", "h_eta5_cand3MET", "Type-1 MET (No Residuals)", "Raw MET", "E_{T}^{miss} [GeV]", lumi, -1, {""}, true, 1);
  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoResiduals", "h_eta5_cand3MET", "Type-1 MET (No Residuals)", "Raw MET", "E_{T}^{miss} [GeV]", lumi, -1, {""}, false, 1);

  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET", "hT1CMET_NoResiduals", "Type-1 MET", "Type-1 MET (No Residuals)", "E_{T}^{miss} [GeV]", lumi, -1, {""}, true, 1);
  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET", "hT1CMET_NoResiduals", "Type-1 MET", "Type-1 MET (No Residuals)", "E_{T}^{miss} [GeV]", lumi, -1, {""}, false, 1);

  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET_tightID", "hT1CMET", "Type-1 MET (Tight ID)", "Type-1 MET", "E_{T}^{miss} [GeV]", lumi, -1, {""}, true, 1);
  make_double_plot(c1, histIdx, vFiles, output_name, "hT1CMET_tightID", "hT1CMET", "Type-1 MET (Tight ID)", "Type-1 MET", "E_{T}^{miss} [GeV]", lumi, -1, {""}, false, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_central", "Jet Neutral EM Fraction", lumi, -1, {"|#eta| <= 2.7"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_central", "Jet Neutral Hadronic Fraction", lumi, -1, {"|#eta| <= 2.7"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_forward", "Jet Neutral EM Fraction", lumi, -1, {"2.7 < |#eta| <= 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_forward", "Jet Neutral Hadronic Fraction", lumi, -1, {"2.7 < |#eta| <= 3.0"}, 1);
 
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_central", "Jet Neutral EM Fraction", lumi, scaleMC, {"|#eta| <= 2.7"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_central", "Jet Neutral Hadronic Fraction", lumi, scaleMC, {"|#eta| <= 2.7"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_forward", "Jet Neutral EM Fraction", lumi, scaleMC, {"2.7 < |#eta| <= 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_forward", "Jet Neutral Hadronic Fraction", lumi, scaleMC, {"2.7 < |#eta| <= 3.0"}, 1);
 
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v5", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 25"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v6", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 75 && 2.7 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v7", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 75 && 2.5 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_NoECJECs_v8", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 100 && 2.7 < |#eta| < 3.0"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v5", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 25", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v6", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 75 && 2.7 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v7", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 75 && 2.5 < |#eta| < 3.0", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_NoECJECs_v8", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 100 && 2.7 < |#eta| < 3.0", "0 Jets"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v5", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 25", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v6", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 75 && 2.7 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v7", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 75 && 2.5 < |#eta| < 3.0", "#geq 1 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_NoECJECs_v8", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "No JECs for p_{T} < 100 && 2.7 < |#eta| < 3.0", "#geq 1 Jets"}, 1); 

  make_2Dplot(c1, histIdx, vFiles, output_name, "hJetEtaPhi", "Jet #eta", "Jet #phi", lumi, -1, {}, 1);
  make_2Dplot(c1, histIdx, vFiles, output_name, "hJetPtEta", "Jet p_{T} [GeV]", "Jet #eta", lumi, -1, {}, 1);
  make_2Dplot(c1, histIdx, vFiles, output_name, "hJetPtPhi", "Jet p_{T} [GeV]", "Jet #phi", lumi, -1, {}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_RunFV9", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET (V9 JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJetPt_RunFV9", "Jet p_{T} [GeV]", lumi, scaleMC, {"Jet p_{T} (V9 JECs)"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_RunFV9", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V9 JECs)", "0 Jets"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_RunFV9", "E_{T}^{miss} [GeV]", lumi, scaleMC, {"T1-Corrected MET (V9 JECs)", "#geq 1 Jets"}, 1); 


  // Scale & Resolution
  // V8
  make_plot(c1, histIdx, vFiles, output_name, "hZpT_V8", "q_{T} [GeV]", lumi, -1, {"V8 JECs"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPara_V8", "u_{#parallel} [GeV]", lumi, -1, {"All JECs applied", "V8 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaMod_V8", "u_{#parallel} [GeV]", lumi, -1, {"Modified JECs", "V8 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPerp_V8", "u_{#perp}  [GeV]", lumi, -1, {"All JECs applied", "V8 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPerpMod_V8", "u_{#perp}  [GeV]", lumi, -1, {"Modified JECs", "V8 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqT_V8", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"All JECs applied", "V8 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqTMod_V8", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"Modified JECs", "V8 JECs"},1); 

  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResPara_V8", "hResParaMod_V8", "", "", "q_{T}", "#sigma(u_{#parallel}) [GeV]", lumi, -1, {"V8 JECs"}, {20, 75}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResPerp_V8", "hResPerpMod_V8", "", "", "q_{T}", "#sigma(u_{#perp} ) [GeV]", lumi, -1, {"V8 JECs"}, {20, 50}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResponse_V8", "hResponseMod_V8", "", "", "q_{T}", "-<u_{#parallel}>/q_{T}", lumi, -1, {"V8 JECs"}, {0.6, 1.25}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResponseEE_V8", "hResponseModEE_V8", "", "", "q_{T}", "-<u_{#parallel}>/q_{T}", lumi, -1, {"V8 JECs", "Z #rightarrow ee events"}, {0.6, 1.25}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResponseMM_V8", "hResponseModMM_V8", "", "", "q_{T}", "-<u_{#parallel}>/q_{T}", lumi, -1, {"V8 JECs", "Z #rightarrow #mu#mu events"}, {0.6, 1.25}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_V8", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "V8 JECs"}, 1);

  // extras for V8
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqT_highqT_V8", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"All JECs applied", "V8 JECs", "q_{T} > 130 GeV"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqTMod_highqT_V8", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"Modified JECs", "V8 JECs", "q_{T} > 130 GeV"},1);

  // V6
  make_plot(c1, histIdx, vFiles, output_name, "hZpT_V6", "q_{T} [GeV]", lumi, -1, {"V6 JECs"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPara_V6", "u_{#parallel} [GeV]", lumi, -1, {"All JECs applied", "V6 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaMod_V6", "u_{#parallel} [GeV]", lumi, -1, {"Modified JECs", "V6 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPerp_V6", "u_{#perp}  [GeV]", lumi, -1, {"All JECs applied", "V6 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPerpMod_V6", "u_{#perp}  [GeV]", lumi, -1, {"Modified JECs", "V6 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqT_V6", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"All JECs applied", "V6 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqTMod_V6", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"Modified JECs", "V6 JECs"},1);

  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResPara_V6", "hResParaMod_V6", "", "", "q_{T}", "#sigma(u_{#parallel}) [GeV]", lumi, -1, {"V6 JECs"}, {20, 75}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResPerp_V6", "hResPerpMod_V6", "", "", "q_{T}", "#sigma(u_{#perp} ) [GeV]", lumi, -1, {"V6 JECs"}, {20, 50}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResponse_V6", "hResponseMod_V6", "", "", "q_{T}", "-<u_{#parallel}>/q_{T}", lumi, -1, {"V6 JECs"}, {0.6, 1.25}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_V6", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "V6 JECs"}, 1);

  // V9
  make_plot(c1, histIdx, vFiles, output_name, "hZpT_V9", "q_{T} [GeV]", lumi, -1, {"V9 JECs"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPara_V9", "u_{#parallel} [GeV]", lumi, -1, {"All JECs applied", "V9 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaMod_V9", "u_{#parallel} [GeV]", lumi, -1, {"Modified JECs", "V9 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPerp_V9", "u_{#perp}  [GeV]", lumi, -1, {"All JECs applied", "V9 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUPerpMod_V9", "u_{#perp}  [GeV]", lumi, -1, {"Modified JECs", "V9 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqT_V9", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"All JECs applied", "V9 JECs"},1);
  make_plot(c1, histIdx, vFiles, output_name, "hUParaPlusqTMod_V9", "u_{#parallel} + q_{T} [GeV]", lumi, -1, {"Modified JECs", "V9 JECs"},1);

  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResPara_V9", "hResParaMod_V9", "", "", "q_{T}", "#sigma(u_{#parallel}) [GeV]", lumi, -1, {"V9 JECs"}, {20, 75}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResPerp_V9", "hResPerpMod_V9", "", "", "q_{T}", "#sigma(u_{#perp} ) [GeV]", lumi, -1, {"V9 JECs"}, {20, 50}, 1);
  make_resolution_plot(c1, histIdx, vFiles, output_name, "hResponse_V9", "hResponseMod_V9", "", "", "q_{T}", "-<u_{#parallel}>/q_{T}", lumi, -1, {"V9 JECs"}, {0.6, 1.25}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_V9", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "V9 JECs"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hT1CMETMod_V6", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "V6 JECs", "No JECs for p_{T} < 75", "          && 2.7 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMETMod_V8", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "V8 JECs", "No JECs for p_{T} < 75", "          && 2.7 < |#eta| < 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMETMod_V9", "E_{T}^{miss} [GeV]", lumi, -1, {"T1-Corrected MET", "V9 JECs", "No JECs for p_{T} < 75", "          && 2.7 < |#eta| < 3.0"}, 2);
  
}
