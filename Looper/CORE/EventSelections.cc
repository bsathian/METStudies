#include "EventSelections.h"

using namespace tas;

#if __cplusplus > 201400
constexpr unsigned int getBitMask() {
  const int sub_detectors[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9, 12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29, 30, 31 };
  unsigned int bitmask(0);
  for (auto i : sub_detectors) bitmask |= (1 << i);
  return bitmask;
}

bool haveFunctionalDCS() {
  // defined in https://cmssdt.cern.ch/SDT/doxygen/CMSSW_6_1_1/doc/html/d1/d05/DcsStatus_8h_source.html#l00084. Ignore CASTOR and ZDC.
  const unsigned int detectormask = getBitMask();
  return (evt_detectorStatus() & detectormask) == detectormask;
}

#else

bool haveFunctionalDCS() {
    // defined in https://cmssdt.cern.ch/SDT/doxygen/CMSSW_6_1_1/doc/html/d1/d05/DcsStatus_8h_source.html#l00084. Ignore CASTOR and ZDC.
    std::vector<int> detectors = { 0, 1, 2, 3, 5, 6, 7, 8, 9, 12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29, 30, 31 };
    for(unsigned int iDet = 0; iDet < detectors.size(); iDet++) {
        if( ! ( evt_detectorStatus() & (1 << detectors[iDet]  ) ) ) return false;
    }
    return true;
}
#endif
