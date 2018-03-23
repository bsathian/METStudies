#include <iostream>
#include <fstream>
#include <sstream>
#include "getDatasetInfo.h"
#include "defaultList.icc"

using namespace std;

DatasetInfoFromFile::DatasetInfoFromFile() : dslist_(default_dslist) {}

void DatasetInfoFromFile::loadFromFile(const string filename) {
  ifstream ifile(filename);
  if (!ifile) throw std::invalid_argument("Dataset info file " + filename + " does not exist!");
  string dsname, cmstag;
  datasetInfo dsinfo;
  string line;
  while (getline(ifile, line)) {
    if (line.find("# dataset") == 0) {}    // check the ordering of the variables <-- implement later
    if (line[0] == '#') continue;
    istringstream lstream(line);
    string entry;
    for (int i = 0; lstream >> std::ws >> entry; ++i) {
      switch (i) {
      case 0: dsname = entry; break;
      case 1: cmstag = entry; break;
      case 2: dsinfo.nevts_tot = stoul(entry); break;
      case 3: dsinfo.nevts_eff = stoul(entry); break;
      case 4: dsinfo.xsec = stof(entry); break;
      case 5: dsinfo.scale1fb = stof(entry); break;
      case 6: throw std::invalid_argument("Dataset info file has too many arguments! Please update this code!");
      }
    }
    dslist_[cmstag+dsname] = dsinfo; // insert info into the dataset list
  }
}

void DatasetInfoFromFile::checkEntryExist(const string dsname, const string cmstag) {
  if (isEmpty())
    throw std::invalid_argument("The dataset list is empty. Please check if the dataset info file is properly loaded.");
  if (dslist_.find(cmstag+dsname) == dslist_.end())
    throw std::invalid_argument("The dataset " + dsname + " with cmstag: " + cmstag + " cannot be found in the list. Please update the dataset info file.");
}

float DatasetInfoFromFile::getScale1fbFromFile(const string dsname, const string cmstag) {
  checkEntryExist(dsname, cmstag);
  return dslist_[cmstag+dsname].scale1fb;
}

float DatasetInfoFromFile::getXsecFromFile(const string dsname, const string cmstag) {
  checkEntryExist(dsname, cmstag);
  return dslist_[cmstag+dsname].xsec;
}

unsigned DatasetInfoFromFile::getnEventsTotalFromFile(const string dsname, const string cmstag) {
  checkEntryExist(dsname, cmstag);
  return dslist_[cmstag+dsname].nevts_tot;
}

unsigned DatasetInfoFromFile::getnEventsEffectiveFromFile(const string dsname, const string cmstag) {
  checkEntryExist(dsname, cmstag);
  return dslist_[cmstag+dsname].nevts_eff;
}
