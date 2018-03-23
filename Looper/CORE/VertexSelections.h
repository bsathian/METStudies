#ifndef VERTEXSELECTIONS_H
#define VERTEXSELECTIONS_H
#include "CMS3.h"
#include "TString.h"
#include "Base.h"

bool isGoodVertex(size_t ivtx);
int firstGoodVertex();

bool isSoftBtag_noDR( size_t sv_idx );

#endif
