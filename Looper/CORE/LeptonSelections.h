#ifndef LEPTONSELECTIONS_H
#define LEPTONSELECTIONS_H
#include "CMS3.h"
#include "TString.h"
#include "Base.h"
#include "TMVA/Reader.h"
#include "TMVA/Config.h"


class readLeptonMVA {
    public:
        void InitMVA(string path_el, string path_mu);
        float MVA(int id, unsigned int index); 
        void DumpValues();

    private:

        TMVA::Reader* reader_el;
        TMVA::Reader* reader_mu;

        // for both e, mu
        float LepGood_pt;
        float LepGood_eta;
        float LepGood_jetPtRelv2;
        float LepGood_jetNDauChargedMVASel;
        float LepGood_miniRelIsoCharged;
        float LepGood_miniRelIsoNeutral;
        float LepGood_jetPtRatio;
        float LepGood_jetBTagCSV;
        float LepGood_sip3d;
        float LepGood_dxy;
        float LepGood_dz;
        float LepGood_mvaIdSpring16HZZ; // specific to electrons
        float LepGood_segmentCompatibility; // specific to muons

};

void createAndInitLeptonMVA(std::string path_el, std::string path_mu); 

float getLeptonMVA(int id, unsigned int index);

struct lepIDcache {
    public:
        void  setCacheValues(int id, int idx, float mva) {
            id_ = abs(id); // 11 or 13 for e, mu
            idx_ = idx;
            mva_ = mva;
        }
        // make sure it was set for this lepton before returning
        float getMVA(int id, int idx) {assert(abs(id)==id_ && idx==idx_); return mva_;}
    private:
        int id_;
        int idx_;
        float mva_;
};
namespace lepID {
    void setCache(int id, int idx, float mva);
    void unsetCache();
}

#endif
