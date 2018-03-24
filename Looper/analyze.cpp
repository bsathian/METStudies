#include "ScanChain.C"
#include <stdlib.h>

int main(int argc, char* argv[]) {
  TChain *ch = new TChain("Events");
  
  TString input_files = argv[1];
  TObjArray *tx = infile.Tokenize(",");
  for (int i = 0; i < tx->GetEntries(); i++) {
    TString fname = ((TObjString *)(tx->At(i)))->String();
    fname.ReplaceAll("'","");
    chain->Add(fname);
  }

  TString output_file = argv[2];
  TString idx = argv[3];
  TString output_name = output_file + "_" + idx;

  TString weight_file = argv[4];
  TString sReweight = argv[5];
  bool puReweight = (sReweight == "YesReweight");

  int selection = atoi(argv[6]);
  double scale1fb = atof(argv[7]);
  double target_lumi = atof(argv[8]);

  ScanChain(chain, output_name, weight_file, puReweight, selection, scale1fb, target_lumi); 
}
