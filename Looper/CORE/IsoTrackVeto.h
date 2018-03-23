#ifndef ISOTRACKVETO_H
#define ISOTRACKVETO_H

struct PFCandIsoResults {
  float chiso;
  float nhiso;
  float phiso;
  float PUpt;
};

[[deprecated("The iso variables can be directly accessed in cms4.")]]
float TrackIso(int thisPf, float coneR = 0.3, float deltaZCut = 0.1, bool useFromPV = false, bool useLeptons = true);
[[deprecated("The iso variables can be directly accessed in cms4.")]]
float MiniTrackIso(int thisPf, float deltaZCut = 0.1);
// Need to add warning to the use of these functions (didn't put this in as don't want CORE compile time warning)
PFCandIsoResults PFCandPFIso(int thisPf, float coneR = 0.3, float deltaZCut = 0.1, bool useFromPV = false, float mindir = -1.);
[[deprecated("This function may not be correct in cms4.")]]
PFCandIsoResults PFCandMiniPFIso(int thisPf, float deltaZCut = 0.1);
[[deprecated("This function may not be correct in cms4.")]]
float PFCandRelIsoAn04(int thisPf, bool useDBcor = true);

#endif
