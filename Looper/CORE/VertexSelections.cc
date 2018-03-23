#include "VertexSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

using namespace tas;

bool isGoodVertex(size_t ivtx) {
  if (vtxs_isFake()[ivtx]) return false;
  if (vtxs_ndof()[ivtx] <= 4.) return false;
  if (vtxs_position()[ivtx].Rho() > 2.0) return false;
  if (fabs(vtxs_position()[ivtx].Z()) > 24.0) return false;
  return true;
}

int firstGoodVertex () {
    for (unsigned int vidx = 0; vidx < vtxs_position().size(); vidx++) {
        if (isGoodVertex(vidx))
            return vidx;
    }
    return -1;
}

// Implementation of soft b-tagger from 2016 0-lepton stop search (minus the Delta-R requirement)
// Documented in AN-16-437, section 3.6

bool isSoftBtag_noDR( size_t svidx ) {
	if( svs_p4()[svidx].Pt() >= 20.0 ) return false;
	if( svs_nTrks()[svidx] < 3 ) return false;
	if( svs_distXYval()[svidx] >= 3.0 ) return false;
	if( svs_dist3Dsig()[svidx] <= 4.0 ) return false;
	if( cos(svs_anglePV()[svidx]) <= 0.98 ) return false;
	// You should also test that this SV is DR>0.4 away from your analysis jets
	return true;
}
