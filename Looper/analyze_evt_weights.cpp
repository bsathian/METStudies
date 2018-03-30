#include "ScanEvtWeights.C"
#include <stdlib.h>

int main(int argc, char* argv[])
{
  cout << "Input files: " << argv[1] << endl;

  TChain *chain = new TChain("Events");
  
  TString input_files = argv[1];
  TObjArray *tx = input_files.Tokenize(",");
  for (int i = 0; i < tx->GetEntries(); i++) {
    TString fname = ((TObjString *)(tx->At(i)))->String();
    fname.ReplaceAll("'","");
    cout << "Adding file: " << fname << endl;
    chain->Add(fname);
  }

  ScanChain(chain);
  return 0;
}
