#ifndef UTILS_H
#define UTILS_H
#include "Math/LorentzVector.h"
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

float DeltaR(float eta1, float eta2, float phi1, float phi2);
float DeltaR(LorentzVector v1, LorentzVector v2); 
float DeltaPhi(float phi1, float phi2);
float MT(float pt1, float phi1, float pt2, float phi2);

#endif
