#include "LeptonSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

/*
 * NOTE:
 *   - works in CMS4_00-00-08 and later only (made with CMSSW 94X+)
 *
 * USAGE:
 *
 * // include
 * #include "CORE/LeptonSelections.cc"
 *
 * // initialize once with TMVA XMLs
 * createAndInitLeptonMVA(
 *            "CORE/data/el_BDTG.weights.xml",
 *            "CORE/data/mu_BDTG.weights.xml"
 *            );
 *
 * // predict for each muon (imu is mus_* index)
 * float leptonMVA = getLeptonMVA(13, imu);
 *
 * // predict for each electron (iel is mus_* index)
 * float leptonMVA = getLeptonMVA(11, iel);
 *
 */

readLeptonMVA* globalLeptonMVAreader = 0;

bool lepIDCacheSet = false;
lepIDcache lepID_cache;
void lepID::setCache(int id, int idx, float mva) {
    assert(lepIDCacheSet==false);//you must unset it before setting it again
    lepID_cache.setCacheValues(id,idx,mva);
    lepIDCacheSet = true;
}
void lepID::unsetCache() {
    lepIDCacheSet = false;
}

using namespace tas;

void readLeptonMVA::DumpValues() {
    std::cout << "Dump:" << std::endl;
    std::cout << "     LepGood_pt: " << LepGood_pt <<  std::endl;
    std::cout << "     LepGood_eta: " << LepGood_eta <<  std::endl;
    std::cout << "     LepGood_jetPtRelv2: " << LepGood_jetPtRelv2 <<  std::endl;
    std::cout << "     LepGood_jetNDauChargedMVASel: " << LepGood_jetNDauChargedMVASel <<  std::endl;
    std::cout << "     LepGood_miniRelIsoCharged: " << LepGood_miniRelIsoCharged <<  std::endl;
    std::cout << "     LepGood_miniRelIsoNeutral: " << LepGood_miniRelIsoNeutral <<  std::endl;
    std::cout << "     LepGood_jetPtRatio: " << LepGood_jetPtRatio <<  std::endl;
    std::cout << "     LepGood_jetBTagCSV: " << LepGood_jetBTagCSV <<  std::endl;
    std::cout << "     LepGood_sip3d: " << LepGood_sip3d <<  std::endl;
    std::cout << "     LepGood_dxy: " << LepGood_dxy <<  std::endl;
    std::cout << "     LepGood_dz: " << LepGood_dz <<  std::endl;
    std::cout << "   Electron only: " <<  std::endl;
    std::cout << "     LepGood_mvaIdSpring16HZZ: " << LepGood_mvaIdSpring16HZZ <<  std::endl;
    std::cout << "   Muon only: " <<  std::endl;
    std::cout << "     LepGood_segmentCompatibility: " << LepGood_segmentCompatibility <<  std::endl;

}

void readLeptonMVA::InitMVA(string path_el, string path_mu) {

    LepGood_pt = 0.;
    LepGood_eta = 0.;
    LepGood_jetPtRelv2 = 0.;
    LepGood_jetNDauChargedMVASel = 0.;
    LepGood_miniRelIsoCharged = 0.;
    LepGood_miniRelIsoNeutral = 0.;
    LepGood_jetPtRatio = 0.;
    LepGood_jetBTagCSV = 0.;
    LepGood_sip3d = 0.;
    LepGood_dxy = 0.;
    LepGood_dz = 0.;
    LepGood_mvaIdSpring16HZZ = 0.; // specific to electrons
    LepGood_segmentCompatibility = 0.; // specific to muons

    //Declare Reader
    reader_el = new TMVA::Reader();
    reader_mu = new TMVA::Reader();

    //Shut the hell up
    TMVA::gConfig().SetSilent( kTRUE );


    reader_el->AddVariable("LepGood_pt", &LepGood_pt);
    reader_el->AddVariable("LepGood_eta", &LepGood_eta);
    reader_el->AddVariable("LepGood_jetNDauChargedMVASel", &LepGood_jetNDauChargedMVASel);
    reader_el->AddVariable("LepGood_miniRelIsoCharged", &LepGood_miniRelIsoCharged);
    reader_el->AddVariable("LepGood_miniRelIsoNeutral", &LepGood_miniRelIsoNeutral);
    reader_el->AddVariable("LepGood_jetPtRelv2", &LepGood_jetPtRelv2);
    reader_el->AddVariable("LepGood_jetPtRatio", &LepGood_jetPtRatio);
    reader_el->AddVariable("LepGood_jetBTagCSV", &LepGood_jetBTagCSV);
    reader_el->AddVariable("LepGood_sip3d", &LepGood_sip3d);
    reader_el->AddVariable("LepGood_dxy", &LepGood_dxy);
    reader_el->AddVariable("LepGood_dz", &LepGood_dz);
    reader_el->AddVariable("LepGood_mvaIdSpring16HZZ", &LepGood_mvaIdSpring16HZZ);
    reader_el->BookMVA("BDTG", path_el);

    reader_mu->AddVariable("LepGood_pt", &LepGood_pt);
    reader_mu->AddVariable("LepGood_eta", &LepGood_eta);
    reader_mu->AddVariable("LepGood_jetNDauChargedMVASel", &LepGood_jetNDauChargedMVASel);
    reader_mu->AddVariable("LepGood_miniRelIsoCharged", &LepGood_miniRelIsoCharged);
    reader_mu->AddVariable("LepGood_miniRelIsoNeutral", &LepGood_miniRelIsoNeutral);
    reader_mu->AddVariable("LepGood_jetPtRelv2", &LepGood_jetPtRelv2);
    reader_mu->AddVariable("LepGood_jetPtRatio", &LepGood_jetPtRatio);
    reader_mu->AddVariable("LepGood_jetBTagCSV", &LepGood_jetBTagCSV);
    reader_mu->AddVariable("LepGood_sip3d", &LepGood_sip3d);
    reader_mu->AddVariable("LepGood_dxy", &LepGood_dxy);
    reader_mu->AddVariable("LepGood_dz", &LepGood_dz);
    reader_mu->AddVariable("LepGood_segmentCompatibility", &LepGood_segmentCompatibility);
    reader_mu->BookMVA("BDTG", path_mu);


}


float readLeptonMVA::MVA(int id, unsigned int index) {

    if (lepIDCacheSet) return lepID_cache.getMVA(id,index);

    float disc = -1;

    // set variables and bind them to the proper ranges, too!
    if (abs(id) == 11) {
        LepGood_pt = els_p4()[index].pt();
        LepGood_eta = els_p4()[index].eta();
        LepGood_jetPtRelv2 = els_ptRel()[index];
        LepGood_jetNDauChargedMVASel = els_jetNDauChargedMVASel()[index];
        LepGood_miniRelIsoCharged = els_miniRelIso_chg()[index];
        LepGood_miniRelIsoNeutral = els_miniRelIso_all()[index] - els_miniRelIso_chg()[index]; 
        LepGood_jetPtRatio = min(els_ptRatio()[index],1.5f);
        LepGood_jetBTagCSV = els_jetBTagCSV()[index];
        LepGood_sip3d = fabs(els_ip3d()[index]/els_ip3derr()[index]);
        LepGood_dxy = log(fabs(els_dxyPV()[index]));
        LepGood_dz = log(fabs(els_dzPV()[index]));
        LepGood_mvaIdSpring16HZZ = els_VIDSpring16HZZMvaValue()[index];
        if (LepGood_jetBTagCSV > -98.) LepGood_jetBTagCSV = max(LepGood_jetBTagCSV,0.0f);

        disc = reader_el->EvaluateMVA("BDTG");

    } else {
        LepGood_pt = mus_p4()[index].pt();
        LepGood_eta = mus_p4()[index].eta();
        LepGood_jetPtRelv2 = mus_ptRel()[index];
        LepGood_jetNDauChargedMVASel = mus_jetNDauChargedMVASel()[index];
        LepGood_miniRelIsoCharged = mus_miniRelIso_chg()[index];
        LepGood_miniRelIsoNeutral = mus_miniRelIso_all()[index] - mus_miniRelIso_chg()[index]; 
        LepGood_jetPtRatio = min(mus_ptRatio()[index],1.5f);
        LepGood_jetBTagCSV = mus_jetBTagCSV()[index];
        LepGood_sip3d = fabs(mus_ip3d()[index]/mus_ip3derr()[index]);
        LepGood_dxy = log(fabs(mus_dxyPV()[index]));
        LepGood_dz = log(fabs(mus_dzPV()[index]));
        LepGood_segmentCompatibility = mus_segmCompatibility()[index];
        if (LepGood_jetBTagCSV > -98.) LepGood_jetBTagCSV = max(LepGood_jetBTagCSV,0.0f);

        disc = reader_mu->EvaluateMVA("BDTG");
    }

    return disc;

}

void createAndInitLeptonMVA(std::string path_el, std::string path_mu) {
    globalLeptonMVAreader = new readLeptonMVA();
    globalLeptonMVAreader->InitMVA(path_el, path_mu); 
}

float getLeptonMVA(int id, unsigned int index) {
    return globalLeptonMVAreader->MVA(id, index);
}
