#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"

// CMS3
#include "../../CORE/CMS3.cc"

using namespace std;
using namespace tas;

int ScanChain(TChain* chain) { 
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  unsigned int nEventsNeg = 0; // number of events that have negative weight

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {
    TString currentFileName = currentFile->GetTitle();
    cout << currentFileName << endl;
    TFile file(currentFileName);
    TTree *tree = (TTree*)file.Get("Events");
    TTreeCache::SetLearnEntries(10);
    tree->SetCacheSize(128*1024*1024);
    cms3.Init(tree);
    if (nEventsTotal >= nEventsChain) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();

    for (unsigned int event = 0; event < nEventsTree; ++event) {
      if (nEventsTotal >= nEventsChain) continue;
      tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;
      CMS3::progress( nEventsTotal, nEventsChain );

      if (genps_weight() < 0) {
        nEventsNeg++;
      } 
    }
    delete tree;
    file.Close();
   
  }

  if (nEventsChain != nEventsTotal) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time: " << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time: " << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;


  cout << float(nEventsNeg)/float(nEventsTotal) << " of events have negative weights" << endl;
  cout << nEventsNeg << " negative weight events and " << nEventsTotal << " total events." << endl;

  delete bmark;
  return 0;
}
