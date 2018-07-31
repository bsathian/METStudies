#include "PlotHelper.h"

const int nEtaRegions = 6;
const int nCandCats = 4;

const double met_bins[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 195, 210, 230, 255, 285, 335, 400};
const int n_met_bins = (sizeof(met_bins) / sizeof(met_bins[0])) - 1;

void make_plot(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name, TString x_label, double lumi, double scale, vector<TString> vInfo, int idx, bool rebin = false, vector<double> rat_range = {}) {
  TH1D* hDataTemp = (TH1D*)vFiles[0]->Get(hist_name + "0");
  TH1D* hData;
  if (rebin)
    hData = (TH1D*)hDataTemp->Rebin(n_met_bins, hist_name + "0" + "rebin", met_bins);
  else
    hData = (TH1D*)hDataTemp->Clone(hist_name + "0" + "rebin");
  vector<TH1D*> hMC;
  for (int i = 1; i < vFiles.size(); i++) {
    TH1D* hMCTemp1 = (TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx)); 
    TH1D* hMCTemp2;
    if (rebin)
      hMCTemp2 = (TH1D*)hMCTemp1->Rebin(n_met_bins, hist_name + to_string(histIdx) + "rebin", met_bins);
    else
      hMCTemp2 = (TH1D*)hMCTemp1->Clone(hist_name + to_string(histIdx) + "rebin");
    hMC.push_back(hMCTemp2);
    delete hMCTemp1;
    //hMC.push_back((TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx)));
    //if (rebin)
    //  hMC[i-1]->Rebin(n_met_bins, "", met_bins);
  }
  TString name = output_name;
  Comparison* c = new Comparison(c1, hData, hMC);
  if (lumi == 4.8)
    c->give_info({"2017 Run B"});
  else if (lumi == 23.5)
    c->give_info({"2017 Runs C,D,E"});
  else if (lumi == 13.5) {
    if (name.Contains("v2"))
      c->give_info({"2017 Run F (09May2018 ReReco)"});
    else
      c->give_info({"2017 Run F"});
  }
  else if (lumi == 9.76)
    c->give_info({"2017 Run C"});
  else if (lumi == 13.74)
    c->give_info({"2017 Runs D,E"});
  c->set_filename(output_name);
  c->set_rat_label("#frac{Data}{MC}");
  //c->set_legend_labels({"2017 Data", "Drell-Yan", "DiBoson", "TriBoson", "Top"});
 
  if (name.Contains("v2") && !name.Contains("nominal"))
    c->set_legend_labels({"2017 Data", "Drell-Yan (12Apr2018)", "DiBoson", "Top"});
  else
    c->set_legend_labels({"2017 Data", "Drell-Yan", "DiBoson", "Top"});
  c->set_x_label(x_label);
  c->set_y_label("Events");
  c->set_data_drawOpt("E");
  c->set_lumi(lumi);
  c->set_scale(scale);
  if (rat_range.size() > 0) {
    c->set_rat_lim_range(rat_range);
    c->set_log_rat();
  }
  if (rebin)
    c->set_x_bin_range({1, n_met_bins});
  //if (hist_name.Contains("T1CMET"))
  //  c->set_x_bin_range({1,70});

  if (hist_name == "hT1CMET" || hist_name == "hT1CMET_tightID" || hist_name == "h_eta5_cand3MET") {
    cout << hist_name + to_string(histIdx) << endl;
    cout << hMC[0]->Integral(41,80) << endl;
  }
  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete hData;
  for (int i = 0; i < hMC.size(); i++)
    delete hMC[i];
  delete c;
} 

void make_plot_rat_unc(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name, TString hist_name_up, TString hist_name_down, TString x_label, double lumi, double scale, vector<TString> vInfo, int idx, bool rebin = false) {
  TH1D* hDataTemp = (TH1D*)vFiles[0]->Get(hist_name + "0");
  TH1D* hData;

  TH1D* hDataUpTemp = (TH1D*)vFiles[0]->Get(hist_name_up + "0");
  TH1D* hDataUp;

  TH1D* hDataDownTemp = (TH1D*)vFiles[0]->Get(hist_name_down + "0");
  TH1D* hDataDown;

  if (rebin) {
    hData = (TH1D*)hDataTemp->Rebin(n_met_bins, hist_name + "0" + "rebin", met_bins);
    hDataUp = (TH1D*)hDataUpTemp->Rebin(n_met_bins, hist_name_up + "0" + "rebin", met_bins);
    hDataDown = (TH1D*)hDataDownTemp->Rebin(n_met_bins, hist_name_down + "0" + "rebin", met_bins);
  }
  else {
    hData = (TH1D*)hDataTemp->Clone(hist_name + "0" + "rebin");
    hDataUp = (TH1D*)hDataUpTemp->Clone(hist_name_up + "0" + "rebin");
    hDataDown = (TH1D*)hDataDownTemp->Clone(hist_name_down + "0" + "rebin");
  }

  vector<TH1D*> hMC;
  vector<TH1D*> hMCUp;
  vector<TH1D*> hMCDown;
  for (int i = 1; i < vFiles.size(); i++) {
    TH1D* hMCTemp1 = (TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx));
    TH1D* hMCTemp2;

    TH1D* hMCUpTemp1 = (TH1D*)vFiles[i]->Get(hist_name_up + to_string(histIdx));
    TH1D* hMCUpTemp2;

    TH1D* hMCDownTemp1 = (TH1D*)vFiles[i]->Get(hist_name_down + to_string(histIdx));
    TH1D* hMCDownTemp2;

    if (rebin) {
      hMCTemp2 = (TH1D*)hMCTemp1->Rebin(n_met_bins, hist_name + to_string(histIdx) + "rebin", met_bins);
      hMCUpTemp2 = (TH1D*)hMCUpTemp1->Rebin(n_met_bins, hist_name_up + to_string(histIdx) + "rebin", met_bins);
      hMCDownTemp2 = (TH1D*)hMCDownTemp1->Rebin(n_met_bins, hist_name_down + to_string(histIdx) + "rebin", met_bins);
    }
    else {
      hMCTemp2 = (TH1D*)hMCTemp1->Clone(hist_name + to_string(histIdx) + "rebin");
      hMCUpTemp2 = (TH1D*)hMCUpTemp1->Clone(hist_name_up + to_string(histIdx) + "rebin");
      hMCDownTemp2 = (TH1D*)hMCDownTemp1->Clone(hist_name_down + to_string(histIdx) + "rebin");    
    }
    hMC.push_back(hMCTemp2);
    hMCUp.push_back(hMCUpTemp2);
    hMCDown.push_back(hMCDownTemp2);

    delete hMCTemp1;
    delete hMCUpTemp1;
    delete hMCDownTemp1;
    //hMC.push_back((TH1D*)vFiles[i]->Get(hist_name + to_string(histIdx)));
    //if (rebin)
    //  hMC[i-1]->Rebin(n_met_bins, "", met_bins);
  }

  TH1D* hRatUnc = (TH1D*)hData->Clone("rat_unc");
  TH1D* hMCSumUp = (TH1D*)hMCUp[0]->Clone("mc_unc_up");
  TH1D* hMCSumDown = (TH1D*)hMCDown[0]->Clone("mc_unc_down");
  for (int i = 1; i < hMC.size(); i++) {
    hMCSumUp->Add(hMCUp[i]);
    hMCSumDown->Add(hMCDown[i]);
  }
  hMCSumUp->Scale(scale);
  hMCSumDown->Scale(scale);

  TH1D* hRatUp = (TH1D*)hDataUp->Clone("rat_up");
  TH1D* hRatDown = (TH1D*)hDataDown->Clone("rat_down");
  hRatUp->Divide(hMCSumUp);
  hRatDown->Divide(hMCSumDown);
  for (int i = 0; i < hRatUnc->GetNbinsX() + 1; i++) {
    hRatUnc->SetBinContent(i, 1);
    hRatUnc->SetBinError(i, abs(hRatUp->GetBinContent(i) - hRatDown->GetBinContent(i)));
  }

  if (hist_name == "hT1CMET" || hist_name == "hT1CMET_tightID")
    cout << hMC[0]->Integral(41,80) << endl;
  //Comparison* c = new Comparison(c1, hData, hMC);
  Comparison* c = new Comparison(c1, hData, hMC, hRatUnc);
  if (lumi == 4.8)
    c->give_info({"2017 Run B"});
  else if (lumi == 23.5)
    c->give_info({"2017 Runs C,D,E"});
  else if (lumi == 13.5) {
    TString name = output_name;
    if (name.Contains("v2"))
      c->give_info({"2017 Run F (09May2018 ReReco)"});
    else
      c->give_info({"2017 Run F"});
  }
  else if (lumi == 9.76)
    c->give_info({"2017 Run C"});
  else if (lumi == 13.74)
    c->give_info({"2017 Runs D,E"});
  c->set_filename(output_name);
  c->set_rat_label("#frac{Data}{MC}");
  //c->set_legend_labels({"2017 Data", "Drell-Yan", "DiBoson", "TriBoson", "Top"});
  c->set_legend_labels({"2017 Data", "Drell-Yan", "DiBoson", "Top"});
  c->set_x_label(x_label);
  c->set_y_label("Events");
  c->set_data_drawOpt("E");
  c->set_lumi(lumi);
  c->set_scale(scale);
  c->set_rat_unc_label("JEC Unc.");
  if (rebin)
    c->set_x_bin_range({1, n_met_bins});
  //if (hist_name.Contains("T1CMET"))
  //  c->set_x_bin_range({1,70});

  if (hist_name == "hT1CMET" || hist_name == "hT1CMET_tightID")
    cout << hMC[0]->Integral(41,80) << endl;
  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete hData;
  for (int i = 0; i < hMC.size(); i++) {
    delete hMC[i];
    delete hMCUp[i];
    delete hMCDown[i];
  }

  delete hRatUnc;
  delete hMCSumUp;
  delete hMCSumDown;
  delete hRatUp;
  delete hRatDown;

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
  if (hist_name.Contains("Uncorr"))
    c->set_x_bin_range({3,50});

  for (int i = 0; i < vInfo.size(); i++)
    c->give_info(vInfo[i]);
  c->plot(idx);
  delete hData;
  for (int i = 0; i < hMC.size(); i++)
    delete hMC[i];
  delete hMCSum;
  delete c;
}

void make_resolution_plots(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, vector<TString> hist_names, double lumi, double scale, vector<TString> vInfo, vector<TString> vLabels, int idx) {
  c1->cd();
  TPad* mainPad = new TPad("p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  mainPad->SetBottomMargin(0.02);
  mainPad->SetRightMargin(0.07);
  mainPad->SetTopMargin(0.08);
  mainPad->SetLeftMargin(0.12);
  mainPad->Draw();
  mainPad->cd();

  double resolution_bins[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 325, 350, 375, 400, 450, 500};
  int n_resolution_bins = (sizeof(resolution_bins)/sizeof(resolution_bins[0]))-1;

  vector<TH1D*> vHData_response;
  vector<TH1D*> vHMC_response;
  vector<TH1D*> vHData_responseEE;
  vector<TH1D*> vHMC_responseEE;
  vector<TH1D*> vHData_responseMM;
  vector<TH1D*> vHMC_responseMM;
  vector<TH1D*> vHData_res_para;
  vector<TH1D*> vHMC_res_para;
  vector<TH1D*> vHData_res_perp;
  vector<TH1D*> vHMC_res_perp;
  for (int i = 0; i < hist_names.size(); i++) {
    vHData_response.push_back(new TH1D(("hData_response" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHMC_response.push_back(new TH1D(("hMC_response" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHData_responseEE.push_back(new TH1D(("hData_responseEE" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHMC_responseEE.push_back(new TH1D(("hMC_responseEE" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHData_responseMM.push_back(new TH1D(("hData_responseMM" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHMC_responseMM.push_back(new TH1D(("hMC_responseMM" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHData_res_para.push_back(new TH1D(("hData_res_para" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHMC_res_para.push_back(new TH1D(("hMC_res_para" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHData_res_perp.push_back(new TH1D(("hData_res_perp" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
    vHMC_res_perp.push_back(new TH1D(("hMC_res_perp" + to_string(i)).data(), "", n_resolution_bins, resolution_bins));
  }  

  for (int i = 0; i < n_resolution_bins; i++) {
    for (int j = 0; j <  hist_names.size(); j++) {
      TH1D* hDataTemp = (TH1D*)vFiles[0]->Get("hT1CMET_Response" + hist_names[j] + to_string(i+1) + "0");
      TH1D* hMCTemp = (TH1D*)vFiles[1]->Get("hT1CMET_Response" + hist_names[j] + to_string(i+1) + to_string(histIdx));
      TH1D* hDataTempEE = (TH1D*)vFiles[0]->Get("hT1CMET_ResponseEE" + hist_names[j] + to_string(i+1) + "0");
      TH1D* hMCTempEE = (TH1D*)vFiles[1]->Get("hT1CMET_ResponseEE" + hist_names[j] + to_string(i+1) + to_string(histIdx));
      TH1D* hDataTempMM = (TH1D*)vFiles[0]->Get("hT1CMET_ResponseMM" + hist_names[j] + to_string(i+1) + "0");
      TH1D* hMCTempMM = (TH1D*)vFiles[1]->Get("hT1CMET_ResponseMM" + hist_names[j] + to_string(i+1) + to_string(histIdx));

      for (int k = 2; k < vFiles.size(); k++) {
        hMCTemp->Add((TH1D*)vFiles[k]->Get("hT1CMET_Response" + hist_names[j] + to_string(i+1) + to_string(histIdx)));
	hMCTempEE->Add((TH1D*)vFiles[k]->Get("hT1CMET_ResponseEE" + hist_names[j] + to_string(i+1) + to_string(histIdx)));
	hMCTempMM->Add((TH1D*)vFiles[k]->Get("hT1CMET_ResponseMM" + hist_names[j] + to_string(i+1) + to_string(histIdx)));
      }
   
      vHData_response[j]->SetBinContent(i+1, hDataTemp->GetMean());
      vHData_response[j]->SetBinError(i+1, hDataTemp->GetMeanError());
      vHMC_response[j]->SetBinContent(i+1, hMCTemp->GetMean());
      vHMC_response[j]->SetBinError(i+1, hMCTemp->GetMeanError());
      
      vHData_responseEE[j]->SetBinContent(i+1, hDataTempEE->GetMean());
      vHData_responseEE[j]->SetBinError(i+1, hDataTempEE->GetMeanError());
      vHMC_responseEE[j]->SetBinContent(i+1, hMCTempEE->GetMean());
      vHMC_responseEE[j]->SetBinError(i+1, hMCTempEE->GetMeanError());

      vHData_responseMM[j]->SetBinContent(i+1, hDataTempMM->GetMean());
      vHData_responseMM[j]->SetBinError(i+1, hDataTempMM->GetMeanError());
      vHMC_responseMM[j]->SetBinContent(i+1, hMCTempMM->GetMean());
      vHMC_responseMM[j]->SetBinError(i+1, hMCTempMM->GetMeanError()); 

      delete hDataTemp;
      delete hMCTemp;
      delete hDataTempEE;
      delete hMCTempEE;
      delete hDataTempMM;
      delete hMCTempMM;
    }   
  }

  for (int i = 0; i < n_resolution_bins; i++) {
    for (int j = 0; j <  hist_names.size(); j++) {
      TH1D* hDataTempPara = (TH1D*)vFiles[0]->Get("hT1CMET_ResPara" + hist_names[j] + to_string(i+1) + "0");
      TH1D* hMCTempPara = (TH1D*)vFiles[1]->Get("hT1CMET_ResPara" + hist_names[j] + to_string(i+1) + to_string(histIdx));
      TH1D* hDataTempPerp = (TH1D*)vFiles[0]->Get("hT1CMET_ResPerp" + hist_names[j] + to_string(i+1) + "0");
      TH1D* hMCTempPerp = (TH1D*)vFiles[1]->Get("hT1CMET_ResPerp" + hist_names[j] + to_string(i+1) + to_string(histIdx));
      for (int k = 2; k < vFiles.size(); k++) {
        hMCTempPara->Add((TH1D*)vFiles[k]->Get("hT1CMET_ResPara" + hist_names[j] + to_string(i+1) + to_string(histIdx)));
	hMCTempPerp->Add((TH1D*)vFiles[k]->Get("hT1CMET_ResPerp" + hist_names[j] + to_string(i+1) + to_string(histIdx)));
      }

      vHData_res_para[j]->SetBinContent(i+1, hDataTempPara->GetStdDev() / vHData_response[j]->GetBinContent(i+1));
      vHMC_res_para[j]->SetBinContent(i+1, hMCTempPara->GetStdDev() / vHMC_response[j]->GetBinContent(i+1));
      vHData_res_perp[j]->SetBinContent(i+1, hDataTempPerp->GetStdDev() / vHData_response[j]->GetBinContent(i+1));
      vHMC_res_perp[j]->SetBinContent(i+1, hMCTempPerp->GetStdDev() / vHMC_response[j]->GetBinContent(i+1));  

      vHData_res_para[j]->SetBinError(i+1, hDataTempPara->GetStdDevError() / vHData_response[j]->GetBinContent(i+1));
      vHMC_res_para[j]->SetBinError(i+1, hMCTempPara->GetStdDevError() / vHMC_response[j]->GetBinContent(i+1));
      vHData_res_perp[j]->SetBinError(i+1, hDataTempPerp->GetStdDevError() / vHData_response[j]->GetBinContent(i+1));
      vHMC_res_perp[j]->SetBinError(i+1, hMCTempPerp->GetStdDevError() / vHMC_response[j]->GetBinContent(i+1));
 
      delete hDataTempPara;
      delete hMCTempPara;
      delete hDataTempPerp;
      delete hMCTempPerp;
    }
  } 

  Comparison* c_response = new Comparison(c1, vHData_response, vHMC_response);
  c_response->set_filename(output_name);
  c_response->set_y_lim_range({0.85, 1.1});
  //c_response->give_hlines({0.86, 0.88, 0.90, 0.92, 0.94, 0.96, 0.98, 1.0, 1.02, 1.04, 1.06, 1.08});
  c_response->give_hlines({1});
  //c_response->give_hlines({0.98,1,1.02});
  c_response->set_info(vInfo);
  c_response->set_lumi(lumi);
  c_response->set_multiple_comparisons();
  c_response->set_no_log();
  c_response->set_legend_labels(vLabels);
  c_response->set_scale(1);
  c_response->set_x_label("q_{T} [GeV]");
  c_response->set_y_label("-<u_{#parallel}>/q_{T}");
  c_response->set_rat_label("#frac{Data}{MC}");
  c_response->set_rat_lim_range({0.9, 1.1});
  c_response->set_legend_lower_right();
  c_response->plot(idx == 0 ? 0 : 1);

  Comparison* c_responseEE = new Comparison(c1, vHData_responseEE, vHMC_responseEE);
  c_responseEE->set_filename(output_name);
  c_responseEE->set_y_lim_range({0.85, 1.1});
  c_responseEE->give_hlines({1});
  //c_responseEE->give_hlines({0.86, 0.88, 0.90, 0.92, 0.94, 0.96, 0.98, 1.0, 1.02, 1.04, 1.06, 1.08});
  c_responseEE->set_info(vInfo);
  c_responseEE->set_lumi(lumi);
  c_responseEE->set_multiple_comparisons();
  c_responseEE->set_no_log();
  c_responseEE->set_legend_labels(vLabels);
  c_responseEE->set_scale(1);
  c_responseEE->set_x_label("q_{T} [GeV]");
  c_responseEE->set_y_label("-<u_{#parallel}>/q_{T}");
  c_responseEE->set_rat_label("#frac{Data}{MC}");
  c_responseEE->set_rat_lim_range({0.9, 1.1});
  c_responseEE->give_info("Z #rightarrow ee Events");
  c_responseEE->set_legend_lower_right();
  c_responseEE->plot(1);

  Comparison* c_responseMM = new Comparison(c1, vHData_responseMM, vHMC_responseMM);
  c_responseMM->set_filename(output_name);
  c_responseMM->set_y_lim_range({0.85, 1.1});
  c_responseMM->give_hlines({1});
  //c_responseMM->give_hlines({0.86, 0.88, 0.90, 0.92, 0.94, 0.96, 0.98, 1.0, 1.02, 1.04, 1.06, 1.08});
  c_responseMM->set_info(vInfo);
  c_responseMM->set_lumi(lumi);
  c_responseMM->set_multiple_comparisons();
  c_responseMM->set_no_log();
  c_responseMM->set_legend_labels(vLabels);
  c_responseMM->set_scale(1);
  c_responseMM->set_x_label("q_{T} [GeV]");
  c_responseMM->set_y_label("-<u_{#parallel}>/q_{T}");
  c_responseMM->set_rat_label("#frac{Data}{MC}");
  c_responseMM->set_rat_lim_range({0.9, 1.1});
  c_responseMM->give_info("Z #rightarrow #mu#mu Events");
  c_responseMM->set_legend_lower_right();
  c_responseMM->plot(1);

  Comparison* c_res_para = new Comparison(c1, vHData_res_para, vHMC_res_para);
  c_res_para->set_filename(output_name);  
  c_res_para->set_x_bin_range({6, 23});
  c_res_para->set_y_lim_range({25, 60});
  c_res_para->set_no_flow();
  c_res_para->set_info(vInfo);
  c_res_para->set_lumi(lumi);
  c_res_para->set_multiple_comparisons();
  c_res_para->set_no_log();
  c_res_para->set_legend_labels(vLabels);
  c_res_para->set_scale(1);
  c_res_para->set_x_label("q_{T} [GeV]");
  c_res_para->set_y_label("#sigma(u_{#parallel}) [GeV]");
  c_res_para->set_rat_label("#frac{Data}{MC}");
  c_res_para->give_info("Response corrected");
  c_res_para->set_rat_lim_range({0.75, 1.25});
  c_res_para->plot(1);

  Comparison* c_res_perp = new Comparison(c1, vHData_res_perp, vHMC_res_perp);
  c_res_perp->set_filename(output_name);
  c_res_perp->set_x_bin_range({6, 23});
  c_res_perp->set_y_lim_range({25, 60});
  c_res_perp->set_no_flow();
  c_res_perp->set_info(vInfo);
  c_res_perp->set_lumi(lumi);
  c_res_perp->set_multiple_comparisons();
  c_res_perp->set_no_log();
  c_res_perp->set_legend_labels(vLabels);
  c_res_perp->set_scale(1);
  c_res_perp->set_x_label("q_{T} [GeV]");
  c_res_perp->set_y_label("#sigma(u_{#perp}) [GeV]");
  c_res_perp->set_rat_label("#frac{Data}{MC}");
  c_res_perp->give_info("Response corrected");
  c_res_perp->set_rat_lim_range({0.75, 1.25});
  c_res_perp->plot(idx == 2 ? 2 : 1);

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

void make_met_plots(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString name, double lumi, double scale, vector<TString> vInfo, int idx) {
  //make_plot(c1, histIdx, vFiles, output_name, "hT1CMET" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo, idx == 0 ? 0 : 1, true);
  make_plot_rat_unc(c1, histIdx, vFiles, output_name, "hT1CMET" + name, "hT1CMET_up" + name, "hT1CMET_down" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo, idx == 0 ? 0 : 1, true); 
  vector<TString> vInfo_up = vInfo;
  vInfo_up.push_back("JEC Varied Up");
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_up" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_up, 1, true);
  vector<TString> vInfo_down = vInfo;
  vInfo_down.push_back("JEC Varied Down");
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_down" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_down, 1, true);
  
  vector<TString> vInfo_0Jets = vInfo;
  vInfo_0Jets.push_back("0 Jets");
  //make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_0Jets, idx == 0 ? 0 : 1, true);
  make_plot_rat_unc(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets" + name, "hT1CMET_0Jets_up" + name, "hT1CMET_0Jets_down" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_0Jets, idx == 0 ? 0 : 1, true);
  vector<TString> vInfo_0Jets_up = vInfo_0Jets;
  vInfo_0Jets_up.push_back("JEC Varied Up");
  //vInfo_0Jets_up.push_back("0 Jets");
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_up" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_0Jets_up, 1, true);
  vector<TString> vInfo_0Jets_down = vInfo_0Jets;
  vInfo_0Jets_down.push_back("JEC Varied Down");
  //vInfo_0Jets_down.push_back("0 Jets");
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_0Jets_down" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_0Jets_down, 1, true); 

  vector<TString> vInfo_1pJets = vInfo;
  vInfo_1pJets.push_back("#geq 1 Jets");
  make_plot_rat_unc(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets" + name, "hT1CMET_1pJets_up" + name, "hT1CMET_1pJets_down" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_1pJets, idx == 0 ? 0 : 1, true);
  //make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_1pJets, idx == 0 ? 0 : 1, true);
  vector<TString> vInfo_1pJets_up = vInfo_1pJets;
  vInfo_1pJets_up.push_back("JEC Varied Up");
  //vInfo_1pJets_up.push_back("#geq 1 Jets");
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_up" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_1pJets_up, 1, true);
  vector<TString> vInfo_1pJets_down = vInfo_1pJets;
  vInfo_1pJets_down.push_back("JEC Varied Down");
  //vInfo_1pJets_down.push_back("#geq 1 Jets");
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_1pJets_down" + name, "E_{T}^{miss} [GeV]", lumi, scale, vInfo_1pJets_down, 1, true);

  make_plot(c1, histIdx, vFiles, output_name, "hJetPt" + name, "Jet p_{T} [GeV]", lumi, scale, vInfo, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hZpT" + name, "q_{T} [GeV]", lumi, scale, vInfo, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_UPara" + name, "u_{#parallel} [GeV]", lumi, scale, vInfo, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_UPerp" + name, "u_{#perp}  [GeV]", lumi, scale, vInfo, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hT1CMET_UParaPlusqT" + name, "u_{#parallel} + q_{T} [GeV]", lumi, scale, vInfo, idx == 2 ? 2 : 1);

} 


int main(int argc, char* argv[])
{
  // Style options
  gStyle->SetOptStat(0);
  gStyle->SetPalette(kRainBow,0);
  gStyle->SetPaintTextFormat(".2f");
  gStyle->SetTickLength(0.01);
  //gStyle->SetErrorX(0);
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
  if (eras == "F" || eras == "Fv2_nominal" || eras == "Fv2")	histIdx = 3;

  TString era_info;
  if (eras == "B") 	era_info = "2017 Run B";
  if (eras == "C")      era_info = "2017 Run C";
  if (eras == "D,E")      era_info = "2017 Runs D,E";
  if (eras == "F")      era_info = "2017 Run F";
  if (eras.Contains("Fv2"))      era_info = "2017 Run F (09May2018 ReReco)";


  TString eras_trimmed = eras.Contains("nominal") ? "Fv2" : eras;

  TFile* fData = new TFile("../histograms/Zll_histograms_" + eras_trimmed + ".root");
  TFile* fDY;
  if (eras == "Fv2") 
    fDY = new TFile("../histograms/Zll_histograms_Drell-Yan_v2.root");
  else
    fDY = new TFile("../histograms/Zll_histograms_Drell-Yan.root");
  TFile* fDiBoson = new TFile("../histograms/Zll_histograms_DiBoson.root");
  TFile* fTriBoson = new TFile("../histograms/Zll_histograms_TriBoson.root");
  TFile* fTop = new TFile("../histograms/Zll_histograms_Top.root");
  //vector<TFile*> vFiles = {fData, fDY, fDiBoson, fTriBoson, fTop};
  vector<TFile*> vFiles = {fData, fDY, fDiBoson, fTop};

  TCanvas* c1 = new TCanvas("c1", "histos", 600, 800);
  double scaleMC = get_scaleMC(vFiles, "hDilepMass", histIdx, lumi);
  //double scaleMC = lumi; 

  //make_met_plots(c1, histIdx, vFiles, output_name, "V8_std", lumi, scaleMC, {"V8 JECs"}, 0);
  //make_met_plots(c1, histIdx, vFiles, output_name, "V8_v1", lumi, scaleMC, {"V8 JECs", "Modified v1 Type-1 MET"}, 1);  
  //make_resolution_plots(c1, histIdx, vFiles, output_name, {"V8_std", "V8_v1"}, lumi, scaleMC, {era_info, "V8 JECs"}, {"Std. Type-1 MET", "Mod. v1 Type-1 MET"}, 1);

  make_met_plots(c1, histIdx, vFiles, output_name, "V11_std", lumi, scaleMC, {"V11 JECs"}, 0);
  //make_met_plots(c1, histIdx, vFiles, output_name, "V11_v1", lumi, scaleMC, {"V11 JECs", "Modified v1 Type-1 MET"}, 1);
  make_met_plots(c1, histIdx, vFiles, output_name, "V11_v2C", lumi, scaleMC, {"V11C JECs", "Modified v2C Type-1 MET"}, 1);
  //make_met_plots(c1, histIdx, vFiles, output_name, "V11_v2D", lumi, scaleMC, {"V11D JECs", "Modified v2D Type-1 MET"}, 1);
 
  //make_resolution_plots(c1, histIdx, vFiles, output_name, {"V11_std", "V11_v1", "V11_v2C", "V11_v2D"}, lumi, scaleMC, {era_info, "V11 JECs"}, {"Std. Type-1 MET", "Mod. v1 Type-1 MET", "Mod. v2C Type-1 MET", "Mod. v2D Type-1 MET"}, 1);
  //make_resolution_plots(c1, histIdx, vFiles, output_name, {"V11_std", "V11_v1"}, lumi, scaleMC, {era_info, "V11 JECs"}, {"Std. Type-1 MET", "Mod. v1 Type-1 MET"}, 1);
  make_resolution_plots(c1, histIdx, vFiles, output_name, {"V11_std", "V11_v2C"}, lumi, scaleMC, {era_info, "V11 JECs"}, {"Std. Type-1 MET", "Mod. v2C Type-1 MET"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_central", "Jet Neutral EM Fraction", lumi, -1, {"|#eta| <= 2.7"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_central", "Jet Neutral Hadronic Fraction", lumi, -1, {"|#eta| <= 2.7"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Emfrac_forward", "Jet Neutral EM Fraction", lumi, -1, {"2.7 < |#eta| <= 3.0"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hJet_Neutral_Hadfrac_forward", "Jet Neutral Hadronic Fraction", lumi, -1, {"2.7 < |#eta| <= 3.0"}, 1);

  make_plot(c1, histIdx, vFiles, output_name, "hCCpT", "p_{T} [GeV]", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hPhotonpT", "p_{T} [GeV]", lumi, -1, {"Photon Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hNeutpT", "p_{T} [GeV]", lumi, -1, {"Neutral Hadron Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hCCeta", "|#eta|", lumi, -1, {"Charged Candidates"}, 1);
  make_plot(c1, histIdx, vFiles, output_name, "hPhotoneta", "|#eta|", lumi, -1, {"Photon Candidates"}, 1, false, {0.1, 33.3});
  make_plot(c1, histIdx, vFiles, output_name, "hNeuteta", "|#eta|", lumi, -1, {"Neutral Hadron Candidates"}, 1);

  //make_plot_rat_unc(TCanvas* c1, int histIdx, vector<TFile*> vFiles, string output_name, TString hist_name, TString hist_name_up, TString hist_name_down, TString x_label, double lumi, double scale, vector<TString> vInfo, int idx, bool rebin = false)

  make_plot(c1, histIdx, vFiles, output_name, "h_eta5_cand3MET", "Raw E_{T}^{miss} [GeV]", lumi, scaleMC, {}, 1, true);
  make_2Dplot(c1, histIdx, vFiles, output_name, "hJetUncorrPtEta", "(Uncorrected) Jet p_{T} [GeV]", "Jet #eta", lumi, -1, {}, 1);

  make_2Dplot(c1, histIdx, vFiles, output_name, "hT1CMETModvT1CMETModCorr", "Modified E_{T}^{miss} (Uncorr. Thresh.) [GeV]", "Modified E_{T}^{miss} (Corr. Thresh.) [GeV]", lumi, -1, {}, 2);

}
