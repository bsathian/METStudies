#include "Math/VectorUtil.h"
#include "IsoTrackVeto.h"
#include "IsolationTools.h"
#include "CMS3.h"

[[deprecated("The iso variables can be directly accessed in cms4.")]]
float TrackIso(int thisPf, float coneR, float deltaZCut, bool useFromPV, bool useLeptons){

  return cms3.pfcands_trackIso().at(thisPf);
}

[[deprecated("The iso variables can be directly accessed in cms4.")]]
float MiniTrackIso(int thisPf, float deltaZCut){

  return cms3.pfcands_miniTrackIso().at(thisPf);
}

// Need to add warning to the use of these functions (didn't put in as don't want CORE compile time warning)
PFCandIsoResults PFCandPFIso(int thisPf, float coneR, float deltaZCut, bool useFromPV, float mindr) {

  PFCandIsoResults res;
  res.chiso = 0.;
  res.nhiso = 0.;
  res.phiso = 0.;
  res.PUpt = 0.;

  for (int ipf = 0; ipf < (int)cms3.pfcands_p4().size(); ipf++) {

    if( ipf == thisPf ) continue; // skip this PFCandidate
    double dr=ROOT::Math::VectorUtil::DeltaR( cms3.pfcands_p4().at(ipf) , cms3.pfcands_p4().at(thisPf) );
    if( dr < mindr ) continue; // skip pfcands inside inner radius
    if( dr > coneR ) continue; // skip pfcands outside the cone                                     

    float pt = cms3.pfcands_p4().at(ipf).pt();
    int particleId = cms3.pfcands_particleId().at(ipf);
    if( abs(particleId) == 211 && pt>=0.0 ) {
      if ((fabs(cms3.pfcands_dz().at(ipf)) < deltaZCut) || (useFromPV && cms3.pfcands_fromPV().at(ipf) > 1)) res.chiso += pt;
      else res.PUpt += pt;
    }
    else if (abs(particleId) == 130) res.nhiso += pt;
    else if (abs(particleId) == 22 ) res.phiso += pt;
  }

  return res;
}

[[deprecated("This function may not be correct in cms4.")]]
PFCandIsoResults PFCandMiniPFIso(int thisPf, float deltaZCut){
  float pt = cms3.pfcands_p4().at(thisPf).pt();
  float dr = getMiniDR(pt);
  return PFCandPFIso(thisPf,dr,deltaZCut);
}

[[deprecated("This function may not be correct in cms4.")]]
float PFCandRelIsoAn04(int thisPf, bool useDBcor) {
  float pt = cms3.pfcands_p4().at(thisPf).pt();
  PFCandIsoResults results = PFCandPFIso(thisPf, 0.4, 0.0, true, 0.3);
  if (useDBcor) return (results.chiso + std::max(float(0.0), results.nhiso + results.phiso - float(0.5)*results.PUpt))/pt;
  else return (results.chiso + results.nhiso + results.phiso)/pt;

}
