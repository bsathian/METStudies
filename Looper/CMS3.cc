#include "CMS3.h"
CMS3 cms3;

void CMS3::Init(TTree *tree) {
  hlt_bits_branch = tree->GetBranch(tree->GetAlias("hlt_bits"));
  if (hlt_bits_branch) hlt_bits_branch->SetAddress(&hlt_bits_);
  els_mc_motherp4_branch = tree->GetBranch(tree->GetAlias("els_mc_motherp4"));
  if (els_mc_motherp4_branch) els_mc_motherp4_branch->SetAddress(&els_mc_motherp4_);
  els_mc_p4_branch = tree->GetBranch(tree->GetAlias("els_mc_p4"));
  if (els_mc_p4_branch) els_mc_p4_branch->SetAddress(&els_mc_p4_);
  mus_mc_motherp4_branch = tree->GetBranch(tree->GetAlias("mus_mc_motherp4"));
  if (mus_mc_motherp4_branch) mus_mc_motherp4_branch->SetAddress(&mus_mc_motherp4_);
  mus_mc_p4_branch = tree->GetBranch(tree->GetAlias("mus_mc_p4"));
  if (mus_mc_p4_branch) mus_mc_p4_branch->SetAddress(&mus_mc_p4_);
  pfjets_mc_p4_branch = tree->GetBranch(tree->GetAlias("pfjets_mc_p4"));
  if (pfjets_mc_p4_branch) pfjets_mc_p4_branch->SetAddress(&pfjets_mc_p4_);
  photons_mc_motherp4_branch = tree->GetBranch(tree->GetAlias("photons_mc_motherp4"));
  if (photons_mc_motherp4_branch) photons_mc_motherp4_branch->SetAddress(&photons_mc_motherp4_);
  photons_mc_p4_branch = tree->GetBranch(tree->GetAlias("photons_mc_p4"));
  if (photons_mc_p4_branch) photons_mc_p4_branch->SetAddress(&photons_mc_p4_);
  els_mc_patMatch_p4_branch = tree->GetBranch(tree->GetAlias("els_mc_patMatch_p4"));
  if (els_mc_patMatch_p4_branch) els_mc_patMatch_p4_branch->SetAddress(&els_mc_patMatch_p4_);
  els_p4_branch = tree->GetBranch(tree->GetAlias("els_p4"));
  if (els_p4_branch) els_p4_branch->SetAddress(&els_p4_);
  els_p4In_branch = tree->GetBranch(tree->GetAlias("els_p4In"));
  if (els_p4In_branch) els_p4In_branch->SetAddress(&els_p4In_);
  els_p4Out_branch = tree->GetBranch(tree->GetAlias("els_p4Out"));
  if (els_p4Out_branch) els_p4Out_branch->SetAddress(&els_p4Out_);
  els_trk_p4_branch = tree->GetBranch(tree->GetAlias("els_trk_p4"));
  if (els_trk_p4_branch) els_trk_p4_branch->SetAddress(&els_trk_p4_);
  els_trk_vertex_p4_branch = tree->GetBranch(tree->GetAlias("els_trk_vertex_p4"));
  if (els_trk_vertex_p4_branch) els_trk_vertex_p4_branch->SetAddress(&els_trk_vertex_p4_);
  els_vertex_p4_branch = tree->GetBranch(tree->GetAlias("els_vertex_p4"));
  if (els_vertex_p4_branch) els_vertex_p4_branch->SetAddress(&els_vertex_p4_);
  genjets_p4NoMuNoNu_branch = tree->GetBranch(tree->GetAlias("genjets_p4NoMuNoNu"));
  if (genjets_p4NoMuNoNu_branch) genjets_p4NoMuNoNu_branch->SetAddress(&genjets_p4NoMuNoNu_);
  genps_p4_branch = tree->GetBranch(tree->GetAlias("genps_p4"));
  if (genps_p4_branch) genps_p4_branch->SetAddress(&genps_p4_);
  hyp_ll_p4_branch = tree->GetBranch(tree->GetAlias("hyp_ll_p4"));
  if (hyp_ll_p4_branch) hyp_ll_p4_branch->SetAddress(&hyp_ll_p4_);
  hyp_lt_p4_branch = tree->GetBranch(tree->GetAlias("hyp_lt_p4"));
  if (hyp_lt_p4_branch) hyp_lt_p4_branch->SetAddress(&hyp_lt_p4_);
  hyp_p4_branch = tree->GetBranch(tree->GetAlias("hyp_p4"));
  if (hyp_p4_branch) hyp_p4_branch->SetAddress(&hyp_p4_);
  isotracks_p4_branch = tree->GetBranch(tree->GetAlias("isotracks_p4"));
  if (isotracks_p4_branch) isotracks_p4_branch->SetAddress(&isotracks_p4_);
  mus_bfit_p4_branch = tree->GetBranch(tree->GetAlias("mus_bfit_p4"));
  if (mus_bfit_p4_branch) mus_bfit_p4_branch->SetAddress(&mus_bfit_p4_);
  mus_gfit_p4_branch = tree->GetBranch(tree->GetAlias("mus_gfit_p4"));
  if (mus_gfit_p4_branch) mus_gfit_p4_branch->SetAddress(&mus_gfit_p4_);
  mus_mc_patMatch_p4_branch = tree->GetBranch(tree->GetAlias("mus_mc_patMatch_p4"));
  if (mus_mc_patMatch_p4_branch) mus_mc_patMatch_p4_branch->SetAddress(&mus_mc_patMatch_p4_);
  mus_p4_branch = tree->GetBranch(tree->GetAlias("mus_p4"));
  if (mus_p4_branch) mus_p4_branch->SetAddress(&mus_p4_);
  mus_pfp4_branch = tree->GetBranch(tree->GetAlias("mus_pfp4"));
  if (mus_pfp4_branch) mus_pfp4_branch->SetAddress(&mus_pfp4_);
  mus_trk_p4_branch = tree->GetBranch(tree->GetAlias("mus_trk_p4"));
  if (mus_trk_p4_branch) mus_trk_p4_branch->SetAddress(&mus_trk_p4_);
  pfcands_p4_branch = tree->GetBranch(tree->GetAlias("pfcands_p4"));
  if (pfcands_p4_branch) pfcands_p4_branch->SetAddress(&pfcands_p4_);
  pfjets_p4_branch = tree->GetBranch(tree->GetAlias("pfjets_p4"));
  if (pfjets_p4_branch) pfjets_p4_branch->SetAddress(&pfjets_p4_);
  pfjets_puppi_p4_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_p4"));
  if (pfjets_puppi_p4_branch) pfjets_puppi_p4_branch->SetAddress(&pfjets_puppi_p4_);
  taus_pf_p4_branch = tree->GetBranch(tree->GetAlias("taus_pf_p4"));
  if (taus_pf_p4_branch) taus_pf_p4_branch->SetAddress(&taus_pf_p4_);
  photons_p4_branch = tree->GetBranch(tree->GetAlias("photons_p4"));
  if (photons_p4_branch) photons_p4_branch->SetAddress(&photons_p4_);
  svs_p4_branch = tree->GetBranch(tree->GetAlias("svs_p4"));
  if (svs_p4_branch) svs_p4_branch->SetAddress(&svs_p4_);
  svs_position_branch = tree->GetBranch(tree->GetAlias("svs_position"));
  if (svs_position_branch) svs_position_branch->SetAddress(&svs_position_);
  ak8jets_p4_branch = tree->GetBranch(tree->GetAlias("ak8jets_p4"));
  if (ak8jets_p4_branch) ak8jets_p4_branch->SetAddress(&ak8jets_p4_);
  ak8jets_softdropPuppiSubjet1_branch = tree->GetBranch(tree->GetAlias("ak8jets_softdropPuppiSubjet1"));
  if (ak8jets_softdropPuppiSubjet1_branch) ak8jets_softdropPuppiSubjet1_branch->SetAddress(&ak8jets_softdropPuppiSubjet1_);
  ak8jets_softdropPuppiSubjet2_branch = tree->GetBranch(tree->GetAlias("ak8jets_softdropPuppiSubjet2"));
  if (ak8jets_softdropPuppiSubjet2_branch) ak8jets_softdropPuppiSubjet2_branch->SetAddress(&ak8jets_softdropPuppiSubjet2_);
  vtxs_position_branch = tree->GetBranch(tree->GetAlias("vtxs_position"));
  if (vtxs_position_branch) vtxs_position_branch->SetAddress(&vtxs_position_);

  tree->SetMakeClass(1);

  genweightsID_branch = tree->GetBranch(tree->GetAlias("genweightsID"));
  if (genweightsID_branch) genweightsID_branch->SetAddress(&genweightsID_);
  evt_CMS3tag_branch = tree->GetBranch(tree->GetAlias("evt_CMS3tag"));
  if (evt_CMS3tag_branch) evt_CMS3tag_branch->SetAddress(&evt_CMS3tag_);
  evt_dataset_branch = tree->GetBranch(tree->GetAlias("evt_dataset"));
  if (evt_dataset_branch) evt_dataset_branch->SetAddress(&evt_dataset_);
  hlt_trigNames_branch = tree->GetBranch(tree->GetAlias("hlt_trigNames"));
  if (hlt_trigNames_branch) hlt_trigNames_branch->SetAddress(&hlt_trigNames_);
  pfjets_bDiscriminatorNames_branch = tree->GetBranch(tree->GetAlias("pfjets_bDiscriminatorNames"));
  if (pfjets_bDiscriminatorNames_branch) pfjets_bDiscriminatorNames_branch->SetAddress(&pfjets_bDiscriminatorNames_);
  pfjets_puppi_bDiscriminatorNames_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_bDiscriminatorNames"));
  if (pfjets_puppi_bDiscriminatorNames_branch) pfjets_puppi_bDiscriminatorNames_branch->SetAddress(&pfjets_puppi_bDiscriminatorNames_);
  taus_pf_IDnames_branch = tree->GetBranch(tree->GetAlias("taus_pf_IDnames"));
  if (taus_pf_IDnames_branch) taus_pf_IDnames_branch->SetAddress(&taus_pf_IDnames_);
  evt_cscTightHaloId_branch = tree->GetBranch(tree->GetAlias("evt_cscTightHaloId"));
  if (evt_cscTightHaloId_branch) evt_cscTightHaloId_branch->SetAddress(&evt_cscTightHaloId_);
  evt_hbheFilter_branch = tree->GetBranch(tree->GetAlias("evt_hbheFilter"));
  if (evt_hbheFilter_branch) evt_hbheFilter_branch->SetAddress(&evt_hbheFilter_);
  filt_chargedHadronTrackResolution_branch = tree->GetBranch(tree->GetAlias("filt_chargedHadronTrackResolution"));
  if (filt_chargedHadronTrackResolution_branch) filt_chargedHadronTrackResolution_branch->SetAddress(&filt_chargedHadronTrackResolution_);
  filt_cscBeamHalo_branch = tree->GetBranch(tree->GetAlias("filt_cscBeamHalo"));
  if (filt_cscBeamHalo_branch) filt_cscBeamHalo_branch->SetAddress(&filt_cscBeamHalo_);
  filt_cscBeamHalo2015_branch = tree->GetBranch(tree->GetAlias("filt_cscBeamHalo2015"));
  if (filt_cscBeamHalo2015_branch) filt_cscBeamHalo2015_branch->SetAddress(&filt_cscBeamHalo2015_);
  filt_cscBeamHaloTrkMuUnveto_branch = tree->GetBranch(tree->GetAlias("filt_cscBeamHaloTrkMuUnveto"));
  if (filt_cscBeamHaloTrkMuUnveto_branch) filt_cscBeamHaloTrkMuUnveto_branch->SetAddress(&filt_cscBeamHaloTrkMuUnveto_);
  filt_ecalBoundaryEnergy_branch = tree->GetBranch(tree->GetAlias("filt_ecalBoundaryEnergy"));
  if (filt_ecalBoundaryEnergy_branch) filt_ecalBoundaryEnergy_branch->SetAddress(&filt_ecalBoundaryEnergy_);
  filt_ecalLaser_branch = tree->GetBranch(tree->GetAlias("filt_ecalLaser"));
  if (filt_ecalLaser_branch) filt_ecalLaser_branch->SetAddress(&filt_ecalLaser_);
  filt_ecalTP_branch = tree->GetBranch(tree->GetAlias("filt_ecalTP"));
  if (filt_ecalTP_branch) filt_ecalTP_branch->SetAddress(&filt_ecalTP_);
  filt_eeBadSc_branch = tree->GetBranch(tree->GetAlias("filt_eeBadSc"));
  if (filt_eeBadSc_branch) filt_eeBadSc_branch->SetAddress(&filt_eeBadSc_);
  filt_globalSuperTightHalo2016_branch = tree->GetBranch(tree->GetAlias("filt_globalSuperTightHalo2016"));
  if (filt_globalSuperTightHalo2016_branch) filt_globalSuperTightHalo2016_branch->SetAddress(&filt_globalSuperTightHalo2016_);
  filt_globalTightHalo2016_branch = tree->GetBranch(tree->GetAlias("filt_globalTightHalo2016"));
  if (filt_globalTightHalo2016_branch) filt_globalTightHalo2016_branch->SetAddress(&filt_globalTightHalo2016_);
  filt_goodVertices_branch = tree->GetBranch(tree->GetAlias("filt_goodVertices"));
  if (filt_goodVertices_branch) filt_goodVertices_branch->SetAddress(&filt_goodVertices_);
  filt_hbheNoise_branch = tree->GetBranch(tree->GetAlias("filt_hbheNoise"));
  if (filt_hbheNoise_branch) filt_hbheNoise_branch->SetAddress(&filt_hbheNoise_);
  filt_hbheNoiseIso_branch = tree->GetBranch(tree->GetAlias("filt_hbheNoiseIso"));
  if (filt_hbheNoiseIso_branch) filt_hbheNoiseIso_branch->SetAddress(&filt_hbheNoiseIso_);
  filt_hcalLaser_branch = tree->GetBranch(tree->GetAlias("filt_hcalLaser"));
  if (filt_hcalLaser_branch) filt_hcalLaser_branch->SetAddress(&filt_hcalLaser_);
  filt_hcalStrip_branch = tree->GetBranch(tree->GetAlias("filt_hcalStrip"));
  if (filt_hcalStrip_branch) filt_hcalStrip_branch->SetAddress(&filt_hcalStrip_);
  filt_metfilter_branch = tree->GetBranch(tree->GetAlias("filt_metfilter"));
  if (filt_metfilter_branch) filt_metfilter_branch->SetAddress(&filt_metfilter_);
  filt_muonBadTrack_branch = tree->GetBranch(tree->GetAlias("filt_muonBadTrack"));
  if (filt_muonBadTrack_branch) filt_muonBadTrack_branch->SetAddress(&filt_muonBadTrack_);
  filt_trackingFailure_branch = tree->GetBranch(tree->GetAlias("filt_trackingFailure"));
  if (filt_trackingFailure_branch) filt_trackingFailure_branch->SetAddress(&filt_trackingFailure_);
  filt_trkPOGFilters_branch = tree->GetBranch(tree->GetAlias("filt_trkPOGFilters"));
  if (filt_trkPOGFilters_branch) filt_trkPOGFilters_branch->SetAddress(&filt_trkPOGFilters_);
  filt_trkPOG_logErrorTooManyClusters_branch = tree->GetBranch(tree->GetAlias("filt_trkPOG_logErrorTooManyClusters"));
  if (filt_trkPOG_logErrorTooManyClusters_branch) filt_trkPOG_logErrorTooManyClusters_branch->SetAddress(&filt_trkPOG_logErrorTooManyClusters_);
  filt_trkPOG_manystripclus53X_branch = tree->GetBranch(tree->GetAlias("filt_trkPOG_manystripclus53X"));
  if (filt_trkPOG_manystripclus53X_branch) filt_trkPOG_manystripclus53X_branch->SetAddress(&filt_trkPOG_manystripclus53X_);
  filt_trkPOG_toomanystripclus53X_branch = tree->GetBranch(tree->GetAlias("filt_trkPOG_toomanystripclus53X"));
  if (filt_trkPOG_toomanystripclus53X_branch) filt_trkPOG_toomanystripclus53X_branch->SetAddress(&filt_trkPOG_toomanystripclus53X_);
  els_conv_vtx_flag_branch = tree->GetBranch(tree->GetAlias("els_conv_vtx_flag"));
  if (els_conv_vtx_flag_branch) els_conv_vtx_flag_branch->SetAddress(&els_conv_vtx_flag_);
  els_isGsfCtfScPixChargeConsistent_branch = tree->GetBranch(tree->GetAlias("els_isGsfCtfScPixChargeConsistent"));
  if (els_isGsfCtfScPixChargeConsistent_branch) els_isGsfCtfScPixChargeConsistent_branch->SetAddress(&els_isGsfCtfScPixChargeConsistent_);
  genps_fromHardProcessBeforeFSR_branch = tree->GetBranch(tree->GetAlias("genps_fromHardProcessBeforeFSR"));
  if (genps_fromHardProcessBeforeFSR_branch) genps_fromHardProcessBeforeFSR_branch->SetAddress(&genps_fromHardProcessBeforeFSR_);
  genps_fromHardProcessDecayed_branch = tree->GetBranch(tree->GetAlias("genps_fromHardProcessDecayed"));
  if (genps_fromHardProcessDecayed_branch) genps_fromHardProcessDecayed_branch->SetAddress(&genps_fromHardProcessDecayed_);
  genps_fromHardProcessFinalState_branch = tree->GetBranch(tree->GetAlias("genps_fromHardProcessFinalState"));
  if (genps_fromHardProcessFinalState_branch) genps_fromHardProcessFinalState_branch->SetAddress(&genps_fromHardProcessFinalState_);
  genps_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch(tree->GetAlias("genps_isDirectHardProcessTauDecayProductFinalState"));
  if (genps_isDirectHardProcessTauDecayProductFinalState_branch) genps_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genps_isDirectHardProcessTauDecayProductFinalState_);
  genps_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch(tree->GetAlias("genps_isDirectPromptTauDecayProductFinalState"));
  if (genps_isDirectPromptTauDecayProductFinalState_branch) genps_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genps_isDirectPromptTauDecayProductFinalState_);
  genps_isHardProcess_branch = tree->GetBranch(tree->GetAlias("genps_isHardProcess"));
  if (genps_isHardProcess_branch) genps_isHardProcess_branch->SetAddress(&genps_isHardProcess_);
  genps_isLastCopy_branch = tree->GetBranch(tree->GetAlias("genps_isLastCopy"));
  if (genps_isLastCopy_branch) genps_isLastCopy_branch->SetAddress(&genps_isLastCopy_);
  genps_isLastCopyBeforeFSR_branch = tree->GetBranch(tree->GetAlias("genps_isLastCopyBeforeFSR"));
  if (genps_isLastCopyBeforeFSR_branch) genps_isLastCopyBeforeFSR_branch->SetAddress(&genps_isLastCopyBeforeFSR_);
  genps_isMostlyLikePythia6Status3_branch = tree->GetBranch(tree->GetAlias("genps_isMostlyLikePythia6Status3"));
  if (genps_isMostlyLikePythia6Status3_branch) genps_isMostlyLikePythia6Status3_branch->SetAddress(&genps_isMostlyLikePythia6Status3_);
  genps_isPromptDecayed_branch = tree->GetBranch(tree->GetAlias("genps_isPromptDecayed"));
  if (genps_isPromptDecayed_branch) genps_isPromptDecayed_branch->SetAddress(&genps_isPromptDecayed_);
  genps_isPromptFinalState_branch = tree->GetBranch(tree->GetAlias("genps_isPromptFinalState"));
  if (genps_isPromptFinalState_branch) genps_isPromptFinalState_branch->SetAddress(&genps_isPromptFinalState_);
  isotracks_isHighPurityTrack_branch = tree->GetBranch(tree->GetAlias("isotracks_isHighPurityTrack"));
  if (isotracks_isHighPurityTrack_branch) isotracks_isHighPurityTrack_branch->SetAddress(&isotracks_isHighPurityTrack_);
  isotracks_isPFCand_branch = tree->GetBranch(tree->GetAlias("isotracks_isPFCand"));
  if (isotracks_isPFCand_branch) isotracks_isPFCand_branch->SetAddress(&isotracks_isPFCand_);
  isotracks_isTightTrack_branch = tree->GetBranch(tree->GetAlias("isotracks_isTightTrack"));
  if (isotracks_isTightTrack_branch) isotracks_isTightTrack_branch->SetAddress(&isotracks_isTightTrack_);
  pfcands_isGlobalMuon_branch = tree->GetBranch(tree->GetAlias("pfcands_isGlobalMuon"));
  if (pfcands_isGlobalMuon_branch) pfcands_isGlobalMuon_branch->SetAddress(&pfcands_isGlobalMuon_);
  pfcands_isStandAloneMuon_branch = tree->GetBranch(tree->GetAlias("pfcands_isStandAloneMuon"));
  if (pfcands_isStandAloneMuon_branch) pfcands_isStandAloneMuon_branch->SetAddress(&pfcands_isStandAloneMuon_);
  pfcands_trackHighPurity_branch = tree->GetBranch(tree->GetAlias("pfcands_trackHighPurity"));
  if (pfcands_trackHighPurity_branch) pfcands_trackHighPurity_branch->SetAddress(&pfcands_trackHighPurity_);
  photons_haspixelSeed_branch = tree->GetBranch(tree->GetAlias("photons_haspixelSeed"));
  if (photons_haspixelSeed_branch) photons_haspixelSeed_branch->SetAddress(&photons_haspixelSeed_);
  photons_passElectronVeto_branch = tree->GetBranch(tree->GetAlias("photons_passElectronVeto"));
  if (photons_passElectronVeto_branch) photons_passElectronVeto_branch->SetAddress(&photons_passElectronVeto_);
  evt_bField_branch = tree->GetBranch(tree->GetAlias("evt_bField"));
  if (evt_bField_branch) evt_bField_branch->SetAddress(&evt_bField_);
  evt_instantLumi_branch = tree->GetBranch(tree->GetAlias("evt_instantLumi"));
  if (evt_instantLumi_branch) evt_instantLumi_branch->SetAddress(&evt_instantLumi_);
  evt_instantLumiErr_branch = tree->GetBranch(tree->GetAlias("evt_instantLumiErr"));
  if (evt_instantLumiErr_branch) evt_instantLumiErr_branch->SetAddress(&evt_instantLumiErr_);
  evt_lumiFill_branch = tree->GetBranch(tree->GetAlias("evt_lumiFill"));
  if (evt_lumiFill_branch) evt_lumiFill_branch->SetAddress(&evt_lumiFill_);
  evt_lumiRun_branch = tree->GetBranch(tree->GetAlias("evt_lumiRun"));
  if (evt_lumiRun_branch) evt_lumiRun_branch->SetAddress(&evt_lumiRun_);
  evt_pileup_branch = tree->GetBranch(tree->GetAlias("evt_pileup"));
  if (evt_pileup_branch) evt_pileup_branch->SetAddress(&evt_pileup_);
  evt_pileupRMS_branch = tree->GetBranch(tree->GetAlias("evt_pileupRMS"));
  if (evt_pileupRMS_branch) evt_pileupRMS_branch->SetAddress(&evt_pileupRMS_);
  evt_fixgrid_all_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgrid_all_rho"));
  if (evt_fixgrid_all_rho_branch) evt_fixgrid_all_rho_branch->SetAddress(&evt_fixgrid_all_rho_);
  evt_fixgridfastjet_allcalo_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgridfastjet_allcalo_rho"));
  if (evt_fixgridfastjet_allcalo_rho_branch) evt_fixgridfastjet_allcalo_rho_branch->SetAddress(&evt_fixgridfastjet_allcalo_rho_);
  evt_fixgridfastjet_central_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgridfastjet_central_rho"));
  if (evt_fixgridfastjet_central_rho_branch) evt_fixgridfastjet_central_rho_branch->SetAddress(&evt_fixgridfastjet_central_rho_);
  evt_fixgridfastjet_all_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgridfastjet_all_rho"));
  if (evt_fixgridfastjet_all_rho_branch) evt_fixgridfastjet_all_rho_branch->SetAddress(&evt_fixgridfastjet_all_rho_);
  evt_fixgridfastjet_centralcalo_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgridfastjet_centralcalo_rho"));
  if (evt_fixgridfastjet_centralcalo_rho_branch) evt_fixgridfastjet_centralcalo_rho_branch->SetAddress(&evt_fixgridfastjet_centralcalo_rho_);
  evt_fixgridfastjet_centralchargedpileup_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgridfastjet_centralchargedpileup_rho"));
  if (evt_fixgridfastjet_centralchargedpileup_rho_branch) evt_fixgridfastjet_centralchargedpileup_rho_branch->SetAddress(&evt_fixgridfastjet_centralchargedpileup_rho_);
  evt_fixgridfastjet_centralneutral_rho_branch = tree->GetBranch(tree->GetAlias("evt_fixgridfastjet_centralneutral_rho"));
  if (evt_fixgridfastjet_centralneutral_rho_branch) evt_fixgridfastjet_centralneutral_rho_branch->SetAddress(&evt_fixgridfastjet_centralneutral_rho_);
  evt_kfactor_branch = tree->GetBranch(tree->GetAlias("evt_kfactor"));
  if (evt_kfactor_branch) evt_kfactor_branch->SetAddress(&evt_kfactor_);
  evt_scale1fb_branch = tree->GetBranch(tree->GetAlias("evt_scale1fb"));
  if (evt_scale1fb_branch) evt_scale1fb_branch->SetAddress(&evt_scale1fb_);
  evt_xsec_excl_branch = tree->GetBranch(tree->GetAlias("evt_xsec_excl"));
  if (evt_xsec_excl_branch) evt_xsec_excl_branch->SetAddress(&evt_xsec_excl_);
  evt_xsec_incl_branch = tree->GetBranch(tree->GetAlias("evt_xsec_incl"));
  if (evt_xsec_incl_branch) evt_xsec_incl_branch->SetAddress(&evt_xsec_incl_);
  genps_alphaQCD_branch = tree->GetBranch(tree->GetAlias("genps_alphaQCD"));
  if (genps_alphaQCD_branch) genps_alphaQCD_branch->SetAddress(&genps_alphaQCD_);
  genps_pthat_branch = tree->GetBranch(tree->GetAlias("genps_pthat"));
  if (genps_pthat_branch) genps_pthat_branch->SetAddress(&genps_pthat_);
  genps_qScale_branch = tree->GetBranch(tree->GetAlias("genps_qScale"));
  if (genps_qScale_branch) genps_qScale_branch->SetAddress(&genps_qScale_);
  genps_weight_branch = tree->GetBranch(tree->GetAlias("genps_weight"));
  if (genps_weight_branch) genps_weight_branch->SetAddress(&genps_weight_);
  gen_sumEt_branch = tree->GetBranch(tree->GetAlias("gen_sumEt"));
  if (gen_sumEt_branch) gen_sumEt_branch->SetAddress(&gen_sumEt_);
  pdfinfo_pdf1_branch = tree->GetBranch(tree->GetAlias("pdfinfo_pdf1"));
  if (pdfinfo_pdf1_branch) pdfinfo_pdf1_branch->SetAddress(&pdfinfo_pdf1_);
  pdfinfo_pdf2_branch = tree->GetBranch(tree->GetAlias("pdfinfo_pdf2"));
  if (pdfinfo_pdf2_branch) pdfinfo_pdf2_branch->SetAddress(&pdfinfo_pdf2_);
  pdfinfo_scale_branch = tree->GetBranch(tree->GetAlias("pdfinfo_scale"));
  if (pdfinfo_scale_branch) pdfinfo_scale_branch->SetAddress(&pdfinfo_scale_);
  pdfinfo_x1_branch = tree->GetBranch(tree->GetAlias("pdfinfo_x1"));
  if (pdfinfo_x1_branch) pdfinfo_x1_branch->SetAddress(&pdfinfo_x1_);
  pdfinfo_x2_branch = tree->GetBranch(tree->GetAlias("pdfinfo_x2"));
  if (pdfinfo_x2_branch) pdfinfo_x2_branch->SetAddress(&pdfinfo_x2_);
  evt_calomet_branch = tree->GetBranch(tree->GetAlias("evt_calomet"));
  if (evt_calomet_branch) evt_calomet_branch->SetAddress(&evt_calomet_);
  evt_calometPhi_branch = tree->GetBranch(tree->GetAlias("evt_calometPhi"));
  if (evt_calometPhi_branch) evt_calometPhi_branch->SetAddress(&evt_calometPhi_);
  evt_pfmet_branch = tree->GetBranch(tree->GetAlias("evt_pfmet"));
  if (evt_pfmet_branch) evt_pfmet_branch->SetAddress(&evt_pfmet_);
  evt_pfmet_ElectronEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_ElectronEnDown"));
  if (evt_pfmet_ElectronEnDown_branch) evt_pfmet_ElectronEnDown_branch->SetAddress(&evt_pfmet_ElectronEnDown_);
  evt_pfmet_ElectronEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_ElectronEnUp"));
  if (evt_pfmet_ElectronEnUp_branch) evt_pfmet_ElectronEnUp_branch->SetAddress(&evt_pfmet_ElectronEnUp_);
  evt_pfmet_JetEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetEnDown"));
  if (evt_pfmet_JetEnDown_branch) evt_pfmet_JetEnDown_branch->SetAddress(&evt_pfmet_JetEnDown_);
  evt_pfmet_JetEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetEnUp"));
  if (evt_pfmet_JetEnUp_branch) evt_pfmet_JetEnUp_branch->SetAddress(&evt_pfmet_JetEnUp_);
  evt_pfmet_JetResDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetResDown"));
  if (evt_pfmet_JetResDown_branch) evt_pfmet_JetResDown_branch->SetAddress(&evt_pfmet_JetResDown_);
  evt_pfmet_JetResUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_JetResUp"));
  if (evt_pfmet_JetResUp_branch) evt_pfmet_JetResUp_branch->SetAddress(&evt_pfmet_JetResUp_);
  evt_pfmet_MuonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_MuonEnDown"));
  if (evt_pfmet_MuonEnDown_branch) evt_pfmet_MuonEnDown_branch->SetAddress(&evt_pfmet_MuonEnDown_);
  evt_pfmet_MuonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_MuonEnUp"));
  if (evt_pfmet_MuonEnUp_branch) evt_pfmet_MuonEnUp_branch->SetAddress(&evt_pfmet_MuonEnUp_);
  evt_pfmetPhi_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi"));
  if (evt_pfmetPhi_branch) evt_pfmetPhi_branch->SetAddress(&evt_pfmetPhi_);
  evt_pfmetPhi_ElectronEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_ElectronEnDown"));
  if (evt_pfmetPhi_ElectronEnDown_branch) evt_pfmetPhi_ElectronEnDown_branch->SetAddress(&evt_pfmetPhi_ElectronEnDown_);
  evt_pfmetPhi_ElectronEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_ElectronEnUp"));
  if (evt_pfmetPhi_ElectronEnUp_branch) evt_pfmetPhi_ElectronEnUp_branch->SetAddress(&evt_pfmetPhi_ElectronEnUp_);
  evt_pfmetPhi_JetEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetEnDown"));
  if (evt_pfmetPhi_JetEnDown_branch) evt_pfmetPhi_JetEnDown_branch->SetAddress(&evt_pfmetPhi_JetEnDown_);
  evt_pfmetPhi_JetEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetEnUp"));
  if (evt_pfmetPhi_JetEnUp_branch) evt_pfmetPhi_JetEnUp_branch->SetAddress(&evt_pfmetPhi_JetEnUp_);
  evt_pfmetPhi_JetResDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetResDown"));
  if (evt_pfmetPhi_JetResDown_branch) evt_pfmetPhi_JetResDown_branch->SetAddress(&evt_pfmetPhi_JetResDown_);
  evt_pfmetPhi_JetResUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_JetResUp"));
  if (evt_pfmetPhi_JetResUp_branch) evt_pfmetPhi_JetResUp_branch->SetAddress(&evt_pfmetPhi_JetResUp_);
  evt_pfmetPhi_MuonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_MuonEnDown"));
  if (evt_pfmetPhi_MuonEnDown_branch) evt_pfmetPhi_MuonEnDown_branch->SetAddress(&evt_pfmetPhi_MuonEnDown_);
  evt_pfmetPhi_MuonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_MuonEnUp"));
  if (evt_pfmetPhi_MuonEnUp_branch) evt_pfmetPhi_MuonEnUp_branch->SetAddress(&evt_pfmetPhi_MuonEnUp_);
  evt_pfmetPhi_PhotonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_PhotonEnDown"));
  if (evt_pfmetPhi_PhotonEnDown_branch) evt_pfmetPhi_PhotonEnDown_branch->SetAddress(&evt_pfmetPhi_PhotonEnDown_);
  evt_pfmetPhi_PhotonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_PhotonEnUp"));
  if (evt_pfmetPhi_PhotonEnUp_branch) evt_pfmetPhi_PhotonEnUp_branch->SetAddress(&evt_pfmetPhi_PhotonEnUp_);
  evt_pfmetPhi_TauEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_TauEnDown"));
  if (evt_pfmetPhi_TauEnDown_branch) evt_pfmetPhi_TauEnDown_branch->SetAddress(&evt_pfmetPhi_TauEnDown_);
  evt_pfmetPhi_TauEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_TauEnUp"));
  if (evt_pfmetPhi_TauEnUp_branch) evt_pfmetPhi_TauEnUp_branch->SetAddress(&evt_pfmetPhi_TauEnUp_);
  evt_pfmetPhi_UnclusteredEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_UnclusteredEnDown"));
  if (evt_pfmetPhi_UnclusteredEnDown_branch) evt_pfmetPhi_UnclusteredEnDown_branch->SetAddress(&evt_pfmetPhi_UnclusteredEnDown_);
  evt_pfmetPhi_UnclusteredEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_UnclusteredEnUp"));
  if (evt_pfmetPhi_UnclusteredEnUp_branch) evt_pfmetPhi_UnclusteredEnUp_branch->SetAddress(&evt_pfmetPhi_UnclusteredEnUp_);
  evt_pfmetPhi_raw_branch = tree->GetBranch(tree->GetAlias("evt_pfmetPhi_raw"));
  if (evt_pfmetPhi_raw_branch) evt_pfmetPhi_raw_branch->SetAddress(&evt_pfmetPhi_raw_);
  evt_pfmet_PhotonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_PhotonEnDown"));
  if (evt_pfmet_PhotonEnDown_branch) evt_pfmet_PhotonEnDown_branch->SetAddress(&evt_pfmet_PhotonEnDown_);
  evt_pfmet_PhotonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_PhotonEnUp"));
  if (evt_pfmet_PhotonEnUp_branch) evt_pfmet_PhotonEnUp_branch->SetAddress(&evt_pfmet_PhotonEnUp_);
  evt_pfmetSig_branch = tree->GetBranch(tree->GetAlias("evt_pfmetSig"));
  if (evt_pfmetSig_branch) evt_pfmetSig_branch->SetAddress(&evt_pfmetSig_);
  evt_pfmetSignificance_branch = tree->GetBranch(tree->GetAlias("evt_pfmetSignificance"));
  if (evt_pfmetSignificance_branch) evt_pfmetSignificance_branch->SetAddress(&evt_pfmetSignificance_);
  evt_pfmet_TauEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_TauEnDown"));
  if (evt_pfmet_TauEnDown_branch) evt_pfmet_TauEnDown_branch->SetAddress(&evt_pfmet_TauEnDown_);
  evt_pfmet_TauEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_TauEnUp"));
  if (evt_pfmet_TauEnUp_branch) evt_pfmet_TauEnUp_branch->SetAddress(&evt_pfmet_TauEnUp_);
  evt_pfmet_UnclusteredEnDown_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_UnclusteredEnDown"));
  if (evt_pfmet_UnclusteredEnDown_branch) evt_pfmet_UnclusteredEnDown_branch->SetAddress(&evt_pfmet_UnclusteredEnDown_);
  evt_pfmet_UnclusteredEnUp_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_UnclusteredEnUp"));
  if (evt_pfmet_UnclusteredEnUp_branch) evt_pfmet_UnclusteredEnUp_branch->SetAddress(&evt_pfmet_UnclusteredEnUp_);
  evt_pfmet_raw_branch = tree->GetBranch(tree->GetAlias("evt_pfmet_raw"));
  if (evt_pfmet_raw_branch) evt_pfmet_raw_branch->SetAddress(&evt_pfmet_raw_);
  evt_pfsumet_branch = tree->GetBranch(tree->GetAlias("evt_pfsumet"));
  if (evt_pfsumet_branch) evt_pfsumet_branch->SetAddress(&evt_pfsumet_);
  evt_pfsumet_raw_branch = tree->GetBranch(tree->GetAlias("evt_pfsumet_raw"));
  if (evt_pfsumet_raw_branch) evt_pfsumet_raw_branch->SetAddress(&evt_pfsumet_raw_);
  gen_met_branch = tree->GetBranch(tree->GetAlias("gen_met"));
  if (gen_met_branch) gen_met_branch->SetAddress(&gen_met_);
  gen_metPhi_branch = tree->GetBranch(tree->GetAlias("gen_metPhi"));
  if (gen_metPhi_branch) gen_metPhi_branch->SetAddress(&gen_metPhi_);
  evt_puppi_calomet_branch = tree->GetBranch(tree->GetAlias("evt_puppi_calomet"));
  if (evt_puppi_calomet_branch) evt_puppi_calomet_branch->SetAddress(&evt_puppi_calomet_);
  evt_puppi_calometPhi_branch = tree->GetBranch(tree->GetAlias("evt_puppi_calometPhi"));
  if (evt_puppi_calometPhi_branch) evt_puppi_calometPhi_branch->SetAddress(&evt_puppi_calometPhi_);
  evt_puppi_pfmet_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet"));
  if (evt_puppi_pfmet_branch) evt_puppi_pfmet_branch->SetAddress(&evt_puppi_pfmet_);
  evt_puppi_pfmet_ElectronEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_ElectronEnDown"));
  if (evt_puppi_pfmet_ElectronEnDown_branch) evt_puppi_pfmet_ElectronEnDown_branch->SetAddress(&evt_puppi_pfmet_ElectronEnDown_);
  evt_puppi_pfmet_ElectronEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_ElectronEnUp"));
  if (evt_puppi_pfmet_ElectronEnUp_branch) evt_puppi_pfmet_ElectronEnUp_branch->SetAddress(&evt_puppi_pfmet_ElectronEnUp_);
  evt_puppi_pfmet_JetEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_JetEnDown"));
  if (evt_puppi_pfmet_JetEnDown_branch) evt_puppi_pfmet_JetEnDown_branch->SetAddress(&evt_puppi_pfmet_JetEnDown_);
  evt_puppi_pfmet_JetEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_JetEnUp"));
  if (evt_puppi_pfmet_JetEnUp_branch) evt_puppi_pfmet_JetEnUp_branch->SetAddress(&evt_puppi_pfmet_JetEnUp_);
  evt_puppi_pfmet_JetResDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_JetResDown"));
  if (evt_puppi_pfmet_JetResDown_branch) evt_puppi_pfmet_JetResDown_branch->SetAddress(&evt_puppi_pfmet_JetResDown_);
  evt_puppi_pfmet_JetResUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_JetResUp"));
  if (evt_puppi_pfmet_JetResUp_branch) evt_puppi_pfmet_JetResUp_branch->SetAddress(&evt_puppi_pfmet_JetResUp_);
  evt_puppi_pfmet_MuonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_MuonEnDown"));
  if (evt_puppi_pfmet_MuonEnDown_branch) evt_puppi_pfmet_MuonEnDown_branch->SetAddress(&evt_puppi_pfmet_MuonEnDown_);
  evt_puppi_pfmet_MuonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_MuonEnUp"));
  if (evt_puppi_pfmet_MuonEnUp_branch) evt_puppi_pfmet_MuonEnUp_branch->SetAddress(&evt_puppi_pfmet_MuonEnUp_);
  evt_puppi_pfmetPhi_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi"));
  if (evt_puppi_pfmetPhi_branch) evt_puppi_pfmetPhi_branch->SetAddress(&evt_puppi_pfmetPhi_);
  evt_puppi_pfmetPhi_ElectronEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_ElectronEnDown"));
  if (evt_puppi_pfmetPhi_ElectronEnDown_branch) evt_puppi_pfmetPhi_ElectronEnDown_branch->SetAddress(&evt_puppi_pfmetPhi_ElectronEnDown_);
  evt_puppi_pfmetPhi_ElectronEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_ElectronEnUp"));
  if (evt_puppi_pfmetPhi_ElectronEnUp_branch) evt_puppi_pfmetPhi_ElectronEnUp_branch->SetAddress(&evt_puppi_pfmetPhi_ElectronEnUp_);
  evt_puppi_pfmetPhi_JetEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_JetEnDown"));
  if (evt_puppi_pfmetPhi_JetEnDown_branch) evt_puppi_pfmetPhi_JetEnDown_branch->SetAddress(&evt_puppi_pfmetPhi_JetEnDown_);
  evt_puppi_pfmetPhi_JetEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_JetEnUp"));
  if (evt_puppi_pfmetPhi_JetEnUp_branch) evt_puppi_pfmetPhi_JetEnUp_branch->SetAddress(&evt_puppi_pfmetPhi_JetEnUp_);
  evt_puppi_pfmetPhi_JetResDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_JetResDown"));
  if (evt_puppi_pfmetPhi_JetResDown_branch) evt_puppi_pfmetPhi_JetResDown_branch->SetAddress(&evt_puppi_pfmetPhi_JetResDown_);
  evt_puppi_pfmetPhi_JetResUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_JetResUp"));
  if (evt_puppi_pfmetPhi_JetResUp_branch) evt_puppi_pfmetPhi_JetResUp_branch->SetAddress(&evt_puppi_pfmetPhi_JetResUp_);
  evt_puppi_pfmetPhi_MuonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_MuonEnDown"));
  if (evt_puppi_pfmetPhi_MuonEnDown_branch) evt_puppi_pfmetPhi_MuonEnDown_branch->SetAddress(&evt_puppi_pfmetPhi_MuonEnDown_);
  evt_puppi_pfmetPhi_MuonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_MuonEnUp"));
  if (evt_puppi_pfmetPhi_MuonEnUp_branch) evt_puppi_pfmetPhi_MuonEnUp_branch->SetAddress(&evt_puppi_pfmetPhi_MuonEnUp_);
  evt_puppi_pfmetPhi_PhotonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_PhotonEnDown"));
  if (evt_puppi_pfmetPhi_PhotonEnDown_branch) evt_puppi_pfmetPhi_PhotonEnDown_branch->SetAddress(&evt_puppi_pfmetPhi_PhotonEnDown_);
  evt_puppi_pfmetPhi_PhotonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_PhotonEnUp"));
  if (evt_puppi_pfmetPhi_PhotonEnUp_branch) evt_puppi_pfmetPhi_PhotonEnUp_branch->SetAddress(&evt_puppi_pfmetPhi_PhotonEnUp_);
  evt_puppi_pfmetPhi_TauEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_TauEnDown"));
  if (evt_puppi_pfmetPhi_TauEnDown_branch) evt_puppi_pfmetPhi_TauEnDown_branch->SetAddress(&evt_puppi_pfmetPhi_TauEnDown_);
  evt_puppi_pfmetPhi_TauEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_TauEnUp"));
  if (evt_puppi_pfmetPhi_TauEnUp_branch) evt_puppi_pfmetPhi_TauEnUp_branch->SetAddress(&evt_puppi_pfmetPhi_TauEnUp_);
  evt_puppi_pfmetPhi_UnclusteredEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_UnclusteredEnDown"));
  if (evt_puppi_pfmetPhi_UnclusteredEnDown_branch) evt_puppi_pfmetPhi_UnclusteredEnDown_branch->SetAddress(&evt_puppi_pfmetPhi_UnclusteredEnDown_);
  evt_puppi_pfmetPhi_UnclusteredEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_UnclusteredEnUp"));
  if (evt_puppi_pfmetPhi_UnclusteredEnUp_branch) evt_puppi_pfmetPhi_UnclusteredEnUp_branch->SetAddress(&evt_puppi_pfmetPhi_UnclusteredEnUp_);
  evt_puppi_pfmetPhi_raw_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetPhi_raw"));
  if (evt_puppi_pfmetPhi_raw_branch) evt_puppi_pfmetPhi_raw_branch->SetAddress(&evt_puppi_pfmetPhi_raw_);
  evt_puppi_pfmet_PhotonEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_PhotonEnDown"));
  if (evt_puppi_pfmet_PhotonEnDown_branch) evt_puppi_pfmet_PhotonEnDown_branch->SetAddress(&evt_puppi_pfmet_PhotonEnDown_);
  evt_puppi_pfmet_PhotonEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_PhotonEnUp"));
  if (evt_puppi_pfmet_PhotonEnUp_branch) evt_puppi_pfmet_PhotonEnUp_branch->SetAddress(&evt_puppi_pfmet_PhotonEnUp_);
  evt_puppi_pfmetSig_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetSig"));
  if (evt_puppi_pfmetSig_branch) evt_puppi_pfmetSig_branch->SetAddress(&evt_puppi_pfmetSig_);
  evt_puppi_pfmetSignificance_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmetSignificance"));
  if (evt_puppi_pfmetSignificance_branch) evt_puppi_pfmetSignificance_branch->SetAddress(&evt_puppi_pfmetSignificance_);
  evt_puppi_pfmet_TauEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_TauEnDown"));
  if (evt_puppi_pfmet_TauEnDown_branch) evt_puppi_pfmet_TauEnDown_branch->SetAddress(&evt_puppi_pfmet_TauEnDown_);
  evt_puppi_pfmet_TauEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_TauEnUp"));
  if (evt_puppi_pfmet_TauEnUp_branch) evt_puppi_pfmet_TauEnUp_branch->SetAddress(&evt_puppi_pfmet_TauEnUp_);
  evt_puppi_pfmet_UnclusteredEnDown_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_UnclusteredEnDown"));
  if (evt_puppi_pfmet_UnclusteredEnDown_branch) evt_puppi_pfmet_UnclusteredEnDown_branch->SetAddress(&evt_puppi_pfmet_UnclusteredEnDown_);
  evt_puppi_pfmet_UnclusteredEnUp_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_UnclusteredEnUp"));
  if (evt_puppi_pfmet_UnclusteredEnUp_branch) evt_puppi_pfmet_UnclusteredEnUp_branch->SetAddress(&evt_puppi_pfmet_UnclusteredEnUp_);
  evt_puppi_pfmet_raw_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfmet_raw"));
  if (evt_puppi_pfmet_raw_branch) evt_puppi_pfmet_raw_branch->SetAddress(&evt_puppi_pfmet_raw_);
  evt_puppi_pfsumet_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfsumet"));
  if (evt_puppi_pfsumet_branch) evt_puppi_pfsumet_branch->SetAddress(&evt_puppi_pfsumet_);
  evt_puppi_pfsumet_raw_branch = tree->GetBranch(tree->GetAlias("evt_puppi_pfsumet_raw"));
  if (evt_puppi_pfsumet_raw_branch) evt_puppi_pfsumet_raw_branch->SetAddress(&evt_puppi_pfsumet_raw_);
  genps_lepdaughter_p4_branch = tree->GetBranch(tree->GetAlias("genps_lepdaughter_p4"));
  if (genps_lepdaughter_p4_branch) genps_lepdaughter_p4_branch->SetAddress(&genps_lepdaughter_p4_);
  pfjets_pfcandmup4_branch = tree->GetBranch(tree->GetAlias("pfjets_pfcandmup4"));
  if (pfjets_pfcandmup4_branch) pfjets_pfcandmup4_branch->SetAddress(&pfjets_pfcandmup4_);
  pfjets_puppi_pfcandmup4_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_pfcandmup4"));
  if (pfjets_puppi_pfcandmup4_branch) pfjets_puppi_pfcandmup4_branch->SetAddress(&pfjets_puppi_pfcandmup4_);
  els_mc3dr_branch = tree->GetBranch(tree->GetAlias("els_mc3dr"));
  if (els_mc3dr_branch) els_mc3dr_branch->SetAddress(&els_mc3dr_);
  els_mcdr_branch = tree->GetBranch(tree->GetAlias("els_mcdr"));
  if (els_mcdr_branch) els_mcdr_branch->SetAddress(&els_mcdr_);
  mus_mc3dr_branch = tree->GetBranch(tree->GetAlias("mus_mc3dr"));
  if (mus_mc3dr_branch) mus_mc3dr_branch->SetAddress(&mus_mc3dr_);
  mus_mcdr_branch = tree->GetBranch(tree->GetAlias("mus_mcdr"));
  if (mus_mcdr_branch) mus_mcdr_branch->SetAddress(&mus_mcdr_);
  pfjets_mc3dr_branch = tree->GetBranch(tree->GetAlias("pfjets_mc3dr"));
  if (pfjets_mc3dr_branch) pfjets_mc3dr_branch->SetAddress(&pfjets_mc3dr_);
  pfjets_mcdr_branch = tree->GetBranch(tree->GetAlias("pfjets_mcdr"));
  if (pfjets_mcdr_branch) pfjets_mcdr_branch->SetAddress(&pfjets_mcdr_);
  photons_mc3dr_branch = tree->GetBranch(tree->GetAlias("photons_mc3dr"));
  if (photons_mc3dr_branch) photons_mc3dr_branch->SetAddress(&photons_mc3dr_);
  photons_mcdr_branch = tree->GetBranch(tree->GetAlias("photons_mcdr"));
  if (photons_mcdr_branch) photons_mcdr_branch->SetAddress(&photons_mcdr_);
  els_VIDNonTrigMvaValue_branch = tree->GetBranch(tree->GetAlias("els_VIDNonTrigMvaValue"));
  if (els_VIDNonTrigMvaValue_branch) els_VIDNonTrigMvaValue_branch->SetAddress(&els_VIDNonTrigMvaValue_);
  els_VIDSpring16GPMvaValue_branch = tree->GetBranch(tree->GetAlias("els_VIDSpring16GPMvaValue"));
  if (els_VIDSpring16GPMvaValue_branch) els_VIDSpring16GPMvaValue_branch->SetAddress(&els_VIDSpring16GPMvaValue_);
  els_VIDSpring16HZZMvaValue_branch = tree->GetBranch(tree->GetAlias("els_VIDSpring16HZZMvaValue"));
  if (els_VIDSpring16HZZMvaValue_branch) els_VIDSpring16HZZMvaValue_branch->SetAddress(&els_VIDSpring16HZZMvaValue_);
  els_VIDTrigMvaValue_branch = tree->GetBranch(tree->GetAlias("els_VIDTrigMvaValue"));
  if (els_VIDTrigMvaValue_branch) els_VIDTrigMvaValue_branch->SetAddress(&els_VIDTrigMvaValue_);
  els_chi2_branch = tree->GetBranch(tree->GetAlias("els_chi2"));
  if (els_chi2_branch) els_chi2_branch->SetAddress(&els_chi2_);
  els_ckf_chi2_branch = tree->GetBranch(tree->GetAlias("els_ckf_chi2"));
  if (els_ckf_chi2_branch) els_ckf_chi2_branch->SetAddress(&els_ckf_chi2_);
  els_ckf_ndof_branch = tree->GetBranch(tree->GetAlias("els_ckf_ndof"));
  if (els_ckf_ndof_branch) els_ckf_ndof_branch->SetAddress(&els_ckf_ndof_);
  els_conv_vtx_prob_branch = tree->GetBranch(tree->GetAlias("els_conv_vtx_prob"));
  if (els_conv_vtx_prob_branch) els_conv_vtx_prob_branch->SetAddress(&els_conv_vtx_prob_);
  els_d0Err_branch = tree->GetBranch(tree->GetAlias("els_d0Err"));
  if (els_d0Err_branch) els_d0Err_branch->SetAddress(&els_d0Err_);
  els_dEtaIn_branch = tree->GetBranch(tree->GetAlias("els_dEtaIn"));
  if (els_dEtaIn_branch) els_dEtaIn_branch->SetAddress(&els_dEtaIn_);
  els_dEtaOut_branch = tree->GetBranch(tree->GetAlias("els_dEtaOut"));
  if (els_dEtaOut_branch) els_dEtaOut_branch->SetAddress(&els_dEtaOut_);
  els_dPhiIn_branch = tree->GetBranch(tree->GetAlias("els_dPhiIn"));
  if (els_dPhiIn_branch) els_dPhiIn_branch->SetAddress(&els_dPhiIn_);
  els_dPhiOut_branch = tree->GetBranch(tree->GetAlias("els_dPhiOut"));
  if (els_dPhiOut_branch) els_dPhiOut_branch->SetAddress(&els_dPhiOut_);
  els_dxyPV_branch = tree->GetBranch(tree->GetAlias("els_dxyPV"));
  if (els_dxyPV_branch) els_dxyPV_branch->SetAddress(&els_dxyPV_);
  els_dzPV_branch = tree->GetBranch(tree->GetAlias("els_dzPV"));
  if (els_dzPV_branch) els_dzPV_branch->SetAddress(&els_dzPV_);
  els_e1x5_full5x5_branch = tree->GetBranch(tree->GetAlias("els_e1x5_full5x5"));
  if (els_e1x5_full5x5_branch) els_e1x5_full5x5_branch->SetAddress(&els_e1x5_full5x5_);
  els_e2x5Max_full5x5_branch = tree->GetBranch(tree->GetAlias("els_e2x5Max_full5x5"));
  if (els_e2x5Max_full5x5_branch) els_e2x5Max_full5x5_branch->SetAddress(&els_e2x5Max_full5x5_);
  els_e5x5_full5x5_branch = tree->GetBranch(tree->GetAlias("els_e5x5_full5x5"));
  if (els_e5x5_full5x5_branch) els_e5x5_full5x5_branch->SetAddress(&els_e5x5_full5x5_);
  els_eOverPIn_branch = tree->GetBranch(tree->GetAlias("els_eOverPIn"));
  if (els_eOverPIn_branch) els_eOverPIn_branch->SetAddress(&els_eOverPIn_);
  els_eOverPOut_branch = tree->GetBranch(tree->GetAlias("els_eOverPOut"));
  if (els_eOverPOut_branch) els_eOverPOut_branch->SetAddress(&els_eOverPOut_);
  els_eSC_branch = tree->GetBranch(tree->GetAlias("els_eSC"));
  if (els_eSC_branch) els_eSC_branch->SetAddress(&els_eSC_);
  els_eSCPresh_branch = tree->GetBranch(tree->GetAlias("els_eSCPresh"));
  if (els_eSCPresh_branch) els_eSCPresh_branch->SetAddress(&els_eSCPresh_);
  els_eSCRaw_branch = tree->GetBranch(tree->GetAlias("els_eSCRaw"));
  if (els_eSCRaw_branch) els_eSCRaw_branch->SetAddress(&els_eSCRaw_);
  els_eSeed_branch = tree->GetBranch(tree->GetAlias("els_eSeed"));
  if (els_eSeed_branch) els_eSeed_branch->SetAddress(&els_eSeed_);
  els_ecalEnergy_branch = tree->GetBranch(tree->GetAlias("els_ecalEnergy"));
  if (els_ecalEnergy_branch) els_ecalEnergy_branch->SetAddress(&els_ecalEnergy_);
  els_ecalEnergyError_branch = tree->GetBranch(tree->GetAlias("els_ecalEnergyError"));
  if (els_ecalEnergyError_branch) els_ecalEnergyError_branch->SetAddress(&els_ecalEnergyError_);
  els_ecalIso_branch = tree->GetBranch(tree->GetAlias("els_ecalIso"));
  if (els_ecalIso_branch) els_ecalIso_branch->SetAddress(&els_ecalIso_);
  els_ecalIso04_branch = tree->GetBranch(tree->GetAlias("els_ecalIso04"));
  if (els_ecalIso04_branch) els_ecalIso04_branch->SetAddress(&els_ecalIso04_);
  els_ecalPFClusterIso_branch = tree->GetBranch(tree->GetAlias("els_ecalPFClusterIso"));
  if (els_ecalPFClusterIso_branch) els_ecalPFClusterIso_branch->SetAddress(&els_ecalPFClusterIso_);
  els_etaSC_branch = tree->GetBranch(tree->GetAlias("els_etaSC"));
  if (els_etaSC_branch) els_etaSC_branch->SetAddress(&els_etaSC_);
  els_etaSCwidth_branch = tree->GetBranch(tree->GetAlias("els_etaSCwidth"));
  if (els_etaSCwidth_branch) els_etaSCwidth_branch->SetAddress(&els_etaSCwidth_);
  els_fbrem_branch = tree->GetBranch(tree->GetAlias("els_fbrem"));
  if (els_fbrem_branch) els_fbrem_branch->SetAddress(&els_fbrem_);
  els_full5x5_hOverE_branch = tree->GetBranch(tree->GetAlias("els_full5x5_hOverE"));
  if (els_full5x5_hOverE_branch) els_full5x5_hOverE_branch->SetAddress(&els_full5x5_hOverE_);
  els_hOverE_branch = tree->GetBranch(tree->GetAlias("els_hOverE"));
  if (els_hOverE_branch) els_hOverE_branch->SetAddress(&els_hOverE_);
  els_hcalDepth1TowerSumEt_branch = tree->GetBranch(tree->GetAlias("els_hcalDepth1TowerSumEt"));
  if (els_hcalDepth1TowerSumEt_branch) els_hcalDepth1TowerSumEt_branch->SetAddress(&els_hcalDepth1TowerSumEt_);
  els_hcalIso_branch = tree->GetBranch(tree->GetAlias("els_hcalIso"));
  if (els_hcalIso_branch) els_hcalIso_branch->SetAddress(&els_hcalIso_);
  els_hcalIso04_branch = tree->GetBranch(tree->GetAlias("els_hcalIso04"));
  if (els_hcalIso04_branch) els_hcalIso04_branch->SetAddress(&els_hcalIso04_);
  els_hcalPFClusterIso_branch = tree->GetBranch(tree->GetAlias("els_hcalPFClusterIso"));
  if (els_hcalPFClusterIso_branch) els_hcalPFClusterIso_branch->SetAddress(&els_hcalPFClusterIso_);
  els_ip2d_branch = tree->GetBranch(tree->GetAlias("els_ip2d"));
  if (els_ip2d_branch) els_ip2d_branch->SetAddress(&els_ip2d_);
  els_ip2derr_branch = tree->GetBranch(tree->GetAlias("els_ip2derr"));
  if (els_ip2derr_branch) els_ip2derr_branch->SetAddress(&els_ip2derr_);
  els_ip3d_branch = tree->GetBranch(tree->GetAlias("els_ip3d"));
  if (els_ip3d_branch) els_ip3d_branch->SetAddress(&els_ip3d_);
  els_ip3derr_branch = tree->GetBranch(tree->GetAlias("els_ip3derr"));
  if (els_ip3derr_branch) els_ip3derr_branch->SetAddress(&els_ip3derr_);
  els_mc_patMatch_dr_branch = tree->GetBranch(tree->GetAlias("els_mc_patMatch_dr"));
  if (els_mc_patMatch_dr_branch) els_mc_patMatch_dr_branch->SetAddress(&els_mc_patMatch_dr_);
  els_miniIso_ch_branch = tree->GetBranch(tree->GetAlias("els_miniIso_ch"));
  if (els_miniIso_ch_branch) els_miniIso_ch_branch->SetAddress(&els_miniIso_ch_);
  els_miniIso_db_branch = tree->GetBranch(tree->GetAlias("els_miniIso_db"));
  if (els_miniIso_db_branch) els_miniIso_db_branch->SetAddress(&els_miniIso_db_);
  els_miniIso_em_branch = tree->GetBranch(tree->GetAlias("els_miniIso_em"));
  if (els_miniIso_em_branch) els_miniIso_em_branch->SetAddress(&els_miniIso_em_);
  els_miniIso_nh_branch = tree->GetBranch(tree->GetAlias("els_miniIso_nh"));
  if (els_miniIso_nh_branch) els_miniIso_nh_branch->SetAddress(&els_miniIso_nh_);
  els_miniIso_uncor_branch = tree->GetBranch(tree->GetAlias("els_miniIso_uncor"));
  if (els_miniIso_uncor_branch) els_miniIso_uncor_branch->SetAddress(&els_miniIso_uncor_);
  els_ndof_branch = tree->GetBranch(tree->GetAlias("els_ndof"));
  if (els_ndof_branch) els_ndof_branch->SetAddress(&els_ndof_);
  els_pfChargedHadronIso_branch = tree->GetBranch(tree->GetAlias("els_pfChargedHadronIso"));
  if (els_pfChargedHadronIso_branch) els_pfChargedHadronIso_branch->SetAddress(&els_pfChargedHadronIso_);
  els_pfNeutralHadronIso_branch = tree->GetBranch(tree->GetAlias("els_pfNeutralHadronIso"));
  if (els_pfNeutralHadronIso_branch) els_pfNeutralHadronIso_branch->SetAddress(&els_pfNeutralHadronIso_);
  els_pfPUIso_branch = tree->GetBranch(tree->GetAlias("els_pfPUIso"));
  if (els_pfPUIso_branch) els_pfPUIso_branch->SetAddress(&els_pfPUIso_);
  els_pfPhotonIso_branch = tree->GetBranch(tree->GetAlias("els_pfPhotonIso"));
  if (els_pfPhotonIso_branch) els_pfPhotonIso_branch->SetAddress(&els_pfPhotonIso_);
  els_phiSC_branch = tree->GetBranch(tree->GetAlias("els_phiSC"));
  if (els_phiSC_branch) els_phiSC_branch->SetAddress(&els_phiSC_);
  els_phiSCwidth_branch = tree->GetBranch(tree->GetAlias("els_phiSCwidth"));
  if (els_phiSCwidth_branch) els_phiSCwidth_branch->SetAddress(&els_phiSCwidth_);
  els_ptErr_branch = tree->GetBranch(tree->GetAlias("els_ptErr"));
  if (els_ptErr_branch) els_ptErr_branch->SetAddress(&els_ptErr_);
  els_ptErrGsf_branch = tree->GetBranch(tree->GetAlias("els_ptErrGsf"));
  if (els_ptErrGsf_branch) els_ptErrGsf_branch->SetAddress(&els_ptErrGsf_);
  els_r9_branch = tree->GetBranch(tree->GetAlias("els_r9"));
  if (els_r9_branch) els_r9_branch->SetAddress(&els_r9_);
  els_r9_full5x5_branch = tree->GetBranch(tree->GetAlias("els_r9_full5x5"));
  if (els_r9_full5x5_branch) els_r9_full5x5_branch->SetAddress(&els_r9_full5x5_);
  els_scSeedEta_branch = tree->GetBranch(tree->GetAlias("els_scSeedEta"));
  if (els_scSeedEta_branch) els_scSeedEta_branch->SetAddress(&els_scSeedEta_);
  els_sigmaEtaEta_full5x5_branch = tree->GetBranch(tree->GetAlias("els_sigmaEtaEta_full5x5"));
  if (els_sigmaEtaEta_full5x5_branch) els_sigmaEtaEta_full5x5_branch->SetAddress(&els_sigmaEtaEta_full5x5_);
  els_sigmaIEtaIEta_branch = tree->GetBranch(tree->GetAlias("els_sigmaIEtaIEta"));
  if (els_sigmaIEtaIEta_branch) els_sigmaIEtaIEta_branch->SetAddress(&els_sigmaIEtaIEta_);
  els_sigmaIEtaIEta_full5x5_branch = tree->GetBranch(tree->GetAlias("els_sigmaIEtaIEta_full5x5"));
  if (els_sigmaIEtaIEta_full5x5_branch) els_sigmaIEtaIEta_full5x5_branch->SetAddress(&els_sigmaIEtaIEta_full5x5_);
  els_sigmaIPhiIPhi_branch = tree->GetBranch(tree->GetAlias("els_sigmaIPhiIPhi"));
  if (els_sigmaIPhiIPhi_branch) els_sigmaIPhiIPhi_branch->SetAddress(&els_sigmaIPhiIPhi_);
  els_sigmaIPhiIPhi_full5x5_branch = tree->GetBranch(tree->GetAlias("els_sigmaIPhiIPhi_full5x5"));
  if (els_sigmaIPhiIPhi_full5x5_branch) els_sigmaIPhiIPhi_full5x5_branch->SetAddress(&els_sigmaIPhiIPhi_full5x5_);
  els_tkIso_branch = tree->GetBranch(tree->GetAlias("els_tkIso"));
  if (els_tkIso_branch) els_tkIso_branch->SetAddress(&els_tkIso_);
  els_tkIso04_branch = tree->GetBranch(tree->GetAlias("els_tkIso04"));
  if (els_tkIso04_branch) els_tkIso04_branch->SetAddress(&els_tkIso04_);
  els_trackMomentumError_branch = tree->GetBranch(tree->GetAlias("els_trackMomentumError"));
  if (els_trackMomentumError_branch) els_trackMomentumError_branch->SetAddress(&els_trackMomentumError_);
  els_trkdr_branch = tree->GetBranch(tree->GetAlias("els_trkdr"));
  if (els_trkdr_branch) els_trkdr_branch->SetAddress(&els_trkdr_);
  els_trkshFrac_branch = tree->GetBranch(tree->GetAlias("els_trkshFrac"));
  if (els_trkshFrac_branch) els_trkshFrac_branch->SetAddress(&els_trkshFrac_);
  els_z0Err_branch = tree->GetBranch(tree->GetAlias("els_z0Err"));
  if (els_z0Err_branch) els_z0Err_branch->SetAddress(&els_z0Err_);
  genps_charge_branch = tree->GetBranch(tree->GetAlias("genps_charge"));
  if (genps_charge_branch) genps_charge_branch->SetAddress(&genps_charge_);
  genps_iso_branch = tree->GetBranch(tree->GetAlias("genps_iso"));
  if (genps_iso_branch) genps_iso_branch->SetAddress(&genps_iso_);
  genweights_branch = tree->GetBranch(tree->GetAlias("genweights"));
  if (genweights_branch) genweights_branch->SetAddress(&genweights_);
  isotracks_dEdxPixel_branch = tree->GetBranch(tree->GetAlias("isotracks_dEdxPixel"));
  if (isotracks_dEdxPixel_branch) isotracks_dEdxPixel_branch->SetAddress(&isotracks_dEdxPixel_);
  isotracks_dEdxStrip_branch = tree->GetBranch(tree->GetAlias("isotracks_dEdxStrip"));
  if (isotracks_dEdxStrip_branch) isotracks_dEdxStrip_branch->SetAddress(&isotracks_dEdxStrip_);
  isotracks_deltaEta_branch = tree->GetBranch(tree->GetAlias("isotracks_deltaEta"));
  if (isotracks_deltaEta_branch) isotracks_deltaEta_branch->SetAddress(&isotracks_deltaEta_);
  isotracks_deltaPhi_branch = tree->GetBranch(tree->GetAlias("isotracks_deltaPhi"));
  if (isotracks_deltaPhi_branch) isotracks_deltaPhi_branch->SetAddress(&isotracks_deltaPhi_);
  isotracks_dxy_branch = tree->GetBranch(tree->GetAlias("isotracks_dxy"));
  if (isotracks_dxy_branch) isotracks_dxy_branch->SetAddress(&isotracks_dxy_);
  isotracks_dxyError_branch = tree->GetBranch(tree->GetAlias("isotracks_dxyError"));
  if (isotracks_dxyError_branch) isotracks_dxyError_branch->SetAddress(&isotracks_dxyError_);
  isotracks_dz_branch = tree->GetBranch(tree->GetAlias("isotracks_dz"));
  if (isotracks_dz_branch) isotracks_dz_branch->SetAddress(&isotracks_dz_);
  isotracks_dzError_branch = tree->GetBranch(tree->GetAlias("isotracks_dzError"));
  if (isotracks_dzError_branch) isotracks_dzError_branch->SetAddress(&isotracks_dzError_);
  isotracks_matchedCaloJetEmEnergy_branch = tree->GetBranch(tree->GetAlias("isotracks_matchedCaloJetEmEnergy"));
  if (isotracks_matchedCaloJetEmEnergy_branch) isotracks_matchedCaloJetEmEnergy_branch->SetAddress(&isotracks_matchedCaloJetEmEnergy_);
  isotracks_matchedCaloJetHadEnergy_branch = tree->GetBranch(tree->GetAlias("isotracks_matchedCaloJetHadEnergy"));
  if (isotracks_matchedCaloJetHadEnergy_branch) isotracks_matchedCaloJetHadEnergy_branch->SetAddress(&isotracks_matchedCaloJetHadEnergy_);
  isotracks_miniIso_ch_branch = tree->GetBranch(tree->GetAlias("isotracks_miniIso_ch"));
  if (isotracks_miniIso_ch_branch) isotracks_miniIso_ch_branch->SetAddress(&isotracks_miniIso_ch_);
  isotracks_miniIso_db_branch = tree->GetBranch(tree->GetAlias("isotracks_miniIso_db"));
  if (isotracks_miniIso_db_branch) isotracks_miniIso_db_branch->SetAddress(&isotracks_miniIso_db_);
  isotracks_miniIso_em_branch = tree->GetBranch(tree->GetAlias("isotracks_miniIso_em"));
  if (isotracks_miniIso_em_branch) isotracks_miniIso_em_branch->SetAddress(&isotracks_miniIso_em_);
  isotracks_miniIso_nh_branch = tree->GetBranch(tree->GetAlias("isotracks_miniIso_nh"));
  if (isotracks_miniIso_nh_branch) isotracks_miniIso_nh_branch->SetAddress(&isotracks_miniIso_nh_);
  isotracks_pfIso_ch_branch = tree->GetBranch(tree->GetAlias("isotracks_pfIso_ch"));
  if (isotracks_pfIso_ch_branch) isotracks_pfIso_ch_branch->SetAddress(&isotracks_pfIso_ch_);
  isotracks_pfIso_db_branch = tree->GetBranch(tree->GetAlias("isotracks_pfIso_db"));
  if (isotracks_pfIso_db_branch) isotracks_pfIso_db_branch->SetAddress(&isotracks_pfIso_db_);
  isotracks_pfIso_em_branch = tree->GetBranch(tree->GetAlias("isotracks_pfIso_em"));
  if (isotracks_pfIso_em_branch) isotracks_pfIso_em_branch->SetAddress(&isotracks_pfIso_em_);
  isotracks_pfIso_nh_branch = tree->GetBranch(tree->GetAlias("isotracks_pfIso_nh"));
  if (isotracks_pfIso_nh_branch) isotracks_pfIso_nh_branch->SetAddress(&isotracks_pfIso_nh_);
  mus_bfit_ptErr_branch = tree->GetBranch(tree->GetAlias("mus_bfit_ptErr"));
  if (mus_bfit_ptErr_branch) mus_bfit_ptErr_branch->SetAddress(&mus_bfit_ptErr_);
  mus_caloCompatibility_branch = tree->GetBranch(tree->GetAlias("mus_caloCompatibility"));
  if (mus_caloCompatibility_branch) mus_caloCompatibility_branch->SetAddress(&mus_caloCompatibility_);
  mus_chi2LocalMomentum_branch = tree->GetBranch(tree->GetAlias("mus_chi2LocalMomentum"));
  if (mus_chi2LocalMomentum_branch) mus_chi2LocalMomentum_branch->SetAddress(&mus_chi2LocalMomentum_);
  mus_chi2LocalPosition_branch = tree->GetBranch(tree->GetAlias("mus_chi2LocalPosition"));
  if (mus_chi2LocalPosition_branch) mus_chi2LocalPosition_branch->SetAddress(&mus_chi2LocalPosition_);
  mus_d0Err_branch = tree->GetBranch(tree->GetAlias("mus_d0Err"));
  if (mus_d0Err_branch) mus_d0Err_branch->SetAddress(&mus_d0Err_);
  mus_dxyPV_branch = tree->GetBranch(tree->GetAlias("mus_dxyPV"));
  if (mus_dxyPV_branch) mus_dxyPV_branch->SetAddress(&mus_dxyPV_);
  mus_dzPV_branch = tree->GetBranch(tree->GetAlias("mus_dzPV"));
  if (mus_dzPV_branch) mus_dzPV_branch->SetAddress(&mus_dzPV_);
  mus_ecal_time_branch = tree->GetBranch(tree->GetAlias("mus_ecal_time"));
  if (mus_ecal_time_branch) mus_ecal_time_branch->SetAddress(&mus_ecal_time_);
  mus_gfit_chi2_branch = tree->GetBranch(tree->GetAlias("mus_gfit_chi2"));
  if (mus_gfit_chi2_branch) mus_gfit_chi2_branch->SetAddress(&mus_gfit_chi2_);
  mus_gfit_ptErr_branch = tree->GetBranch(tree->GetAlias("mus_gfit_ptErr"));
  if (mus_gfit_ptErr_branch) mus_gfit_ptErr_branch->SetAddress(&mus_gfit_ptErr_);
  mus_hcal_time_branch = tree->GetBranch(tree->GetAlias("mus_hcal_time"));
  if (mus_hcal_time_branch) mus_hcal_time_branch->SetAddress(&mus_hcal_time_);
  mus_ip2d_branch = tree->GetBranch(tree->GetAlias("mus_ip2d"));
  if (mus_ip2d_branch) mus_ip2d_branch->SetAddress(&mus_ip2d_);
  mus_ip2derr_branch = tree->GetBranch(tree->GetAlias("mus_ip2derr"));
  if (mus_ip2derr_branch) mus_ip2derr_branch->SetAddress(&mus_ip2derr_);
  mus_ip3d_branch = tree->GetBranch(tree->GetAlias("mus_ip3d"));
  if (mus_ip3d_branch) mus_ip3d_branch->SetAddress(&mus_ip3d_);
  mus_ip3derr_branch = tree->GetBranch(tree->GetAlias("mus_ip3derr"));
  if (mus_ip3derr_branch) mus_ip3derr_branch->SetAddress(&mus_ip3derr_);
  mus_iso03_emEt_branch = tree->GetBranch(tree->GetAlias("mus_iso03_emEt"));
  if (mus_iso03_emEt_branch) mus_iso03_emEt_branch->SetAddress(&mus_iso03_emEt_);
  mus_iso03_hadEt_branch = tree->GetBranch(tree->GetAlias("mus_iso03_hadEt"));
  if (mus_iso03_hadEt_branch) mus_iso03_hadEt_branch->SetAddress(&mus_iso03_hadEt_);
  mus_iso03_sumPt_branch = tree->GetBranch(tree->GetAlias("mus_iso03_sumPt"));
  if (mus_iso03_sumPt_branch) mus_iso03_sumPt_branch->SetAddress(&mus_iso03_sumPt_);
  mus_isoR03_pf_ChargedHadronPt_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_ChargedHadronPt"));
  if (mus_isoR03_pf_ChargedHadronPt_branch) mus_isoR03_pf_ChargedHadronPt_branch->SetAddress(&mus_isoR03_pf_ChargedHadronPt_);
  mus_isoR03_pf_ChargedParticlePt_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_ChargedParticlePt"));
  if (mus_isoR03_pf_ChargedParticlePt_branch) mus_isoR03_pf_ChargedParticlePt_branch->SetAddress(&mus_isoR03_pf_ChargedParticlePt_);
  mus_isoR03_pf_NeutralHadronEt_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_NeutralHadronEt"));
  if (mus_isoR03_pf_NeutralHadronEt_branch) mus_isoR03_pf_NeutralHadronEt_branch->SetAddress(&mus_isoR03_pf_NeutralHadronEt_);
  mus_isoR03_pf_NeutralHadronEtHighThreshold_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_NeutralHadronEtHighThreshold"));
  if (mus_isoR03_pf_NeutralHadronEtHighThreshold_branch) mus_isoR03_pf_NeutralHadronEtHighThreshold_branch->SetAddress(&mus_isoR03_pf_NeutralHadronEtHighThreshold_);
  mus_isoR03_pf_PUPt_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_PUPt"));
  if (mus_isoR03_pf_PUPt_branch) mus_isoR03_pf_PUPt_branch->SetAddress(&mus_isoR03_pf_PUPt_);
  mus_isoR03_pf_PhotonEt_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_PhotonEt"));
  if (mus_isoR03_pf_PhotonEt_branch) mus_isoR03_pf_PhotonEt_branch->SetAddress(&mus_isoR03_pf_PhotonEt_);
  mus_isoR03_pf_PhotonEtHighThreshold_branch = tree->GetBranch(tree->GetAlias("mus_isoR03_pf_PhotonEtHighThreshold"));
  if (mus_isoR03_pf_PhotonEtHighThreshold_branch) mus_isoR03_pf_PhotonEtHighThreshold_branch->SetAddress(&mus_isoR03_pf_PhotonEtHighThreshold_);
  mus_isoR04_pf_ChargedHadronPt_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_ChargedHadronPt"));
  if (mus_isoR04_pf_ChargedHadronPt_branch) mus_isoR04_pf_ChargedHadronPt_branch->SetAddress(&mus_isoR04_pf_ChargedHadronPt_);
  mus_isoR04_pf_ChargedParticlePt_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_ChargedParticlePt"));
  if (mus_isoR04_pf_ChargedParticlePt_branch) mus_isoR04_pf_ChargedParticlePt_branch->SetAddress(&mus_isoR04_pf_ChargedParticlePt_);
  mus_isoR04_pf_NeutralHadronEt_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_NeutralHadronEt"));
  if (mus_isoR04_pf_NeutralHadronEt_branch) mus_isoR04_pf_NeutralHadronEt_branch->SetAddress(&mus_isoR04_pf_NeutralHadronEt_);
  mus_isoR04_pf_NeutralHadronEtHighThreshold_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_NeutralHadronEtHighThreshold"));
  if (mus_isoR04_pf_NeutralHadronEtHighThreshold_branch) mus_isoR04_pf_NeutralHadronEtHighThreshold_branch->SetAddress(&mus_isoR04_pf_NeutralHadronEtHighThreshold_);
  mus_isoR04_pf_PUPt_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_PUPt"));
  if (mus_isoR04_pf_PUPt_branch) mus_isoR04_pf_PUPt_branch->SetAddress(&mus_isoR04_pf_PUPt_);
  mus_isoR04_pf_PhotonEt_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_PhotonEt"));
  if (mus_isoR04_pf_PhotonEt_branch) mus_isoR04_pf_PhotonEt_branch->SetAddress(&mus_isoR04_pf_PhotonEt_);
  mus_isoR04_pf_PhotonEtHighThreshold_branch = tree->GetBranch(tree->GetAlias("mus_isoR04_pf_PhotonEtHighThreshold"));
  if (mus_isoR04_pf_PhotonEtHighThreshold_branch) mus_isoR04_pf_PhotonEtHighThreshold_branch->SetAddress(&mus_isoR04_pf_PhotonEtHighThreshold_);
  mus_iso_ecalvetoDep_branch = tree->GetBranch(tree->GetAlias("mus_iso_ecalvetoDep"));
  if (mus_iso_ecalvetoDep_branch) mus_iso_ecalvetoDep_branch->SetAddress(&mus_iso_ecalvetoDep_);
  mus_iso_hcalvetoDep_branch = tree->GetBranch(tree->GetAlias("mus_iso_hcalvetoDep"));
  if (mus_iso_hcalvetoDep_branch) mus_iso_hcalvetoDep_branch->SetAddress(&mus_iso_hcalvetoDep_);
  mus_iso_hovetoDep_branch = tree->GetBranch(tree->GetAlias("mus_iso_hovetoDep"));
  if (mus_iso_hovetoDep_branch) mus_iso_hovetoDep_branch->SetAddress(&mus_iso_hovetoDep_);
  mus_iso_trckvetoDep_branch = tree->GetBranch(tree->GetAlias("mus_iso_trckvetoDep"));
  if (mus_iso_trckvetoDep_branch) mus_iso_trckvetoDep_branch->SetAddress(&mus_iso_trckvetoDep_);
  mus_mc_patMatch_dr_branch = tree->GetBranch(tree->GetAlias("mus_mc_patMatch_dr"));
  if (mus_mc_patMatch_dr_branch) mus_mc_patMatch_dr_branch->SetAddress(&mus_mc_patMatch_dr_);
  mus_miniIso_ch_branch = tree->GetBranch(tree->GetAlias("mus_miniIso_ch"));
  if (mus_miniIso_ch_branch) mus_miniIso_ch_branch->SetAddress(&mus_miniIso_ch_);
  mus_miniIso_db_branch = tree->GetBranch(tree->GetAlias("mus_miniIso_db"));
  if (mus_miniIso_db_branch) mus_miniIso_db_branch->SetAddress(&mus_miniIso_db_);
  mus_miniIso_em_branch = tree->GetBranch(tree->GetAlias("mus_miniIso_em"));
  if (mus_miniIso_em_branch) mus_miniIso_em_branch->SetAddress(&mus_miniIso_em_);
  mus_miniIso_nh_branch = tree->GetBranch(tree->GetAlias("mus_miniIso_nh"));
  if (mus_miniIso_nh_branch) mus_miniIso_nh_branch->SetAddress(&mus_miniIso_nh_);
  mus_miniIso_uncor_branch = tree->GetBranch(tree->GetAlias("mus_miniIso_uncor"));
  if (mus_miniIso_uncor_branch) mus_miniIso_uncor_branch->SetAddress(&mus_miniIso_uncor_);
  mus_ptErr_branch = tree->GetBranch(tree->GetAlias("mus_ptErr"));
  if (mus_ptErr_branch) mus_ptErr_branch->SetAddress(&mus_ptErr_);
  mus_segmCompatibility_branch = tree->GetBranch(tree->GetAlias("mus_segmCompatibility"));
  if (mus_segmCompatibility_branch) mus_segmCompatibility_branch->SetAddress(&mus_segmCompatibility_);
  mus_trkKink_branch = tree->GetBranch(tree->GetAlias("mus_trkKink"));
  if (mus_trkKink_branch) mus_trkKink_branch->SetAddress(&mus_trkKink_);
  mus_z0Err_branch = tree->GetBranch(tree->GetAlias("mus_z0Err"));
  if (mus_z0Err_branch) mus_z0Err_branch->SetAddress(&mus_z0Err_);
  pfcands_dxy_branch = tree->GetBranch(tree->GetAlias("pfcands_dxy"));
  if (pfcands_dxy_branch) pfcands_dxy_branch->SetAddress(&pfcands_dxy_);
  pfcands_dxyError_branch = tree->GetBranch(tree->GetAlias("pfcands_dxyError"));
  if (pfcands_dxyError_branch) pfcands_dxyError_branch->SetAddress(&pfcands_dxyError_);
  pfcands_dz_branch = tree->GetBranch(tree->GetAlias("pfcands_dz"));
  if (pfcands_dz_branch) pfcands_dz_branch->SetAddress(&pfcands_dz_);
  pfcands_dzAssociatedPV_branch = tree->GetBranch(tree->GetAlias("pfcands_dzAssociatedPV"));
  if (pfcands_dzAssociatedPV_branch) pfcands_dzAssociatedPV_branch->SetAddress(&pfcands_dzAssociatedPV_);
  pfcands_dzError_branch = tree->GetBranch(tree->GetAlias("pfcands_dzError"));
  if (pfcands_dzError_branch) pfcands_dzError_branch->SetAddress(&pfcands_dzError_);
  pfcands_mass_branch = tree->GetBranch(tree->GetAlias("pfcands_mass"));
  if (pfcands_mass_branch) pfcands_mass_branch->SetAddress(&pfcands_mass_);
  pfcands_miniTrackIso_branch = tree->GetBranch(tree->GetAlias("pfcands_miniTrackIso"));
  if (pfcands_miniTrackIso_branch) pfcands_miniTrackIso_branch->SetAddress(&pfcands_miniTrackIso_);
  pfcands_puppiWeight_branch = tree->GetBranch(tree->GetAlias("pfcands_puppiWeight"));
  if (pfcands_puppiWeight_branch) pfcands_puppiWeight_branch->SetAddress(&pfcands_puppiWeight_);
  pfcands_puppiWeightNoLep_branch = tree->GetBranch(tree->GetAlias("pfcands_puppiWeightNoLep"));
  if (pfcands_puppiWeightNoLep_branch) pfcands_puppiWeightNoLep_branch->SetAddress(&pfcands_puppiWeightNoLep_);
  pfcands_trackIso_branch = tree->GetBranch(tree->GetAlias("pfcands_trackIso"));
  if (pfcands_trackIso_branch) pfcands_trackIso_branch->SetAddress(&pfcands_trackIso_);
  pfjets_area_branch = tree->GetBranch(tree->GetAlias("pfjets_area"));
  if (pfjets_area_branch) pfjets_area_branch->SetAddress(&pfjets_area_);
  pfjets_axis1_branch = tree->GetBranch(tree->GetAlias("pfjets_axis1"));
  if (pfjets_axis1_branch) pfjets_axis1_branch->SetAddress(&pfjets_axis1_);
  pfjets_chargedEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_chargedEmE"));
  if (pfjets_chargedEmE_branch) pfjets_chargedEmE_branch->SetAddress(&pfjets_chargedEmE_);
  pfjets_chargedHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_chargedHadronE"));
  if (pfjets_chargedHadronE_branch) pfjets_chargedHadronE_branch->SetAddress(&pfjets_chargedHadronE_);
  pfjets_electronE_branch = tree->GetBranch(tree->GetAlias("pfjets_electronE"));
  if (pfjets_electronE_branch) pfjets_electronE_branch->SetAddress(&pfjets_electronE_);
  pfjets_hfEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_hfEmE"));
  if (pfjets_hfEmE_branch) pfjets_hfEmE_branch->SetAddress(&pfjets_hfEmE_);
  pfjets_hfHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_hfHadronE"));
  if (pfjets_hfHadronE_branch) pfjets_hfHadronE_branch->SetAddress(&pfjets_hfHadronE_);
  pfjets_muonE_branch = tree->GetBranch(tree->GetAlias("pfjets_muonE"));
  if (pfjets_muonE_branch) pfjets_muonE_branch->SetAddress(&pfjets_muonE_);
  pfjets_neutralEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_neutralEmE"));
  if (pfjets_neutralEmE_branch) pfjets_neutralEmE_branch->SetAddress(&pfjets_neutralEmE_);
  pfjets_neutralHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_neutralHadronE"));
  if (pfjets_neutralHadronE_branch) pfjets_neutralHadronE_branch->SetAddress(&pfjets_neutralHadronE_);
  pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch = tree->GetBranch(tree->GetAlias("pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag"));
  if (pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch) pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch->SetAddress(&pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_);
  pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch = tree->GetBranch(tree->GetAlias("pfjets_pfDeepCSVJetTagsprobbPlusprobbb"));
  if (pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch) pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch->SetAddress(&pfjets_pfDeepCSVJetTagsprobbPlusprobbb_);
  pfjets_photonE_branch = tree->GetBranch(tree->GetAlias("pfjets_photonE"));
  if (pfjets_photonE_branch) pfjets_photonE_branch->SetAddress(&pfjets_photonE_);
  pfjets_pileupJetId_branch = tree->GetBranch(tree->GetAlias("pfjets_pileupJetId"));
  if (pfjets_pileupJetId_branch) pfjets_pileupJetId_branch->SetAddress(&pfjets_pileupJetId_);
  pfjets_ptDistribution_branch = tree->GetBranch(tree->GetAlias("pfjets_ptDistribution"));
  if (pfjets_ptDistribution_branch) pfjets_ptDistribution_branch->SetAddress(&pfjets_ptDistribution_);
  pfjets_undoJEC_branch = tree->GetBranch(tree->GetAlias("pfjets_undoJEC"));
  if (pfjets_undoJEC_branch) pfjets_undoJEC_branch->SetAddress(&pfjets_undoJEC_);
  pfjets_puppi_area_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_area"));
  if (pfjets_puppi_area_branch) pfjets_puppi_area_branch->SetAddress(&pfjets_puppi_area_);
  pfjets_puppi_axis1_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_axis1"));
  if (pfjets_puppi_axis1_branch) pfjets_puppi_axis1_branch->SetAddress(&pfjets_puppi_axis1_);
  pfjets_puppi_chargedEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_chargedEmE"));
  if (pfjets_puppi_chargedEmE_branch) pfjets_puppi_chargedEmE_branch->SetAddress(&pfjets_puppi_chargedEmE_);
  pfjets_puppi_chargedHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_chargedHadronE"));
  if (pfjets_puppi_chargedHadronE_branch) pfjets_puppi_chargedHadronE_branch->SetAddress(&pfjets_puppi_chargedHadronE_);
  pfjets_puppi_electronE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_electronE"));
  if (pfjets_puppi_electronE_branch) pfjets_puppi_electronE_branch->SetAddress(&pfjets_puppi_electronE_);
  pfjets_puppi_hfEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_hfEmE"));
  if (pfjets_puppi_hfEmE_branch) pfjets_puppi_hfEmE_branch->SetAddress(&pfjets_puppi_hfEmE_);
  pfjets_puppi_hfHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_hfHadronE"));
  if (pfjets_puppi_hfHadronE_branch) pfjets_puppi_hfHadronE_branch->SetAddress(&pfjets_puppi_hfHadronE_);
  pfjets_puppi_muonE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_muonE"));
  if (pfjets_puppi_muonE_branch) pfjets_puppi_muonE_branch->SetAddress(&pfjets_puppi_muonE_);
  pfjets_puppi_neutralEmE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_neutralEmE"));
  if (pfjets_puppi_neutralEmE_branch) pfjets_puppi_neutralEmE_branch->SetAddress(&pfjets_puppi_neutralEmE_);
  pfjets_puppi_neutralHadronE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_neutralHadronE"));
  if (pfjets_puppi_neutralHadronE_branch) pfjets_puppi_neutralHadronE_branch->SetAddress(&pfjets_puppi_neutralHadronE_);
  pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag"));
  if (pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch) pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch->SetAddress(&pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_);
  pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb"));
  if (pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch) pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch->SetAddress(&pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_);
  pfjets_puppi_photonE_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_photonE"));
  if (pfjets_puppi_photonE_branch) pfjets_puppi_photonE_branch->SetAddress(&pfjets_puppi_photonE_);
  pfjets_puppi_pileupJetId_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_pileupJetId"));
  if (pfjets_puppi_pileupJetId_branch) pfjets_puppi_pileupJetId_branch->SetAddress(&pfjets_puppi_pileupJetId_);
  pfjets_puppi_ptDistribution_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_ptDistribution"));
  if (pfjets_puppi_ptDistribution_branch) pfjets_puppi_ptDistribution_branch->SetAddress(&pfjets_puppi_ptDistribution_);
  pfjets_puppi_undoJEC_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_undoJEC"));
  if (pfjets_puppi_undoJEC_branch) pfjets_puppi_undoJEC_branch->SetAddress(&pfjets_puppi_undoJEC_);
  photons_ecalPFClusterIso_branch = tree->GetBranch(tree->GetAlias("photons_ecalPFClusterIso"));
  if (photons_ecalPFClusterIso_branch) photons_ecalPFClusterIso_branch->SetAddress(&photons_ecalPFClusterIso_);
  photons_full5x5_hOverE_branch = tree->GetBranch(tree->GetAlias("photons_full5x5_hOverE"));
  if (photons_full5x5_hOverE_branch) photons_full5x5_hOverE_branch->SetAddress(&photons_full5x5_hOverE_);
  photons_full5x5_hOverEtowBC_branch = tree->GetBranch(tree->GetAlias("photons_full5x5_hOverEtowBC"));
  if (photons_full5x5_hOverEtowBC_branch) photons_full5x5_hOverEtowBC_branch->SetAddress(&photons_full5x5_hOverEtowBC_);
  photons_full5x5_r9_branch = tree->GetBranch(tree->GetAlias("photons_full5x5_r9"));
  if (photons_full5x5_r9_branch) photons_full5x5_r9_branch->SetAddress(&photons_full5x5_r9_);
  photons_full5x5_sigmaIEtaIEta_branch = tree->GetBranch(tree->GetAlias("photons_full5x5_sigmaIEtaIEta"));
  if (photons_full5x5_sigmaIEtaIEta_branch) photons_full5x5_sigmaIEtaIEta_branch->SetAddress(&photons_full5x5_sigmaIEtaIEta_);
  photons_hOverE_branch = tree->GetBranch(tree->GetAlias("photons_hOverE"));
  if (photons_hOverE_branch) photons_hOverE_branch->SetAddress(&photons_hOverE_);
  photons_hOverEtowBC_branch = tree->GetBranch(tree->GetAlias("photons_hOverEtowBC"));
  if (photons_hOverEtowBC_branch) photons_hOverEtowBC_branch->SetAddress(&photons_hOverEtowBC_);
  photons_hcalPFClusterIso_branch = tree->GetBranch(tree->GetAlias("photons_hcalPFClusterIso"));
  if (photons_hcalPFClusterIso_branch) photons_hcalPFClusterIso_branch->SetAddress(&photons_hcalPFClusterIso_);
  photons_ntkIsoHollow03_branch = tree->GetBranch(tree->GetAlias("photons_ntkIsoHollow03"));
  if (photons_ntkIsoHollow03_branch) photons_ntkIsoHollow03_branch->SetAddress(&photons_ntkIsoHollow03_);
  photons_recoChargedHadronIso_branch = tree->GetBranch(tree->GetAlias("photons_recoChargedHadronIso"));
  if (photons_recoChargedHadronIso_branch) photons_recoChargedHadronIso_branch->SetAddress(&photons_recoChargedHadronIso_);
  photons_recoNeutralHadronIso_branch = tree->GetBranch(tree->GetAlias("photons_recoNeutralHadronIso"));
  if (photons_recoNeutralHadronIso_branch) photons_recoNeutralHadronIso_branch->SetAddress(&photons_recoNeutralHadronIso_);
  photons_recoPhotonIso_branch = tree->GetBranch(tree->GetAlias("photons_recoPhotonIso"));
  if (photons_recoPhotonIso_branch) photons_recoPhotonIso_branch->SetAddress(&photons_recoPhotonIso_);
  photons_sigmaIEtaIEta_branch = tree->GetBranch(tree->GetAlias("photons_sigmaIEtaIEta"));
  if (photons_sigmaIEtaIEta_branch) photons_sigmaIEtaIEta_branch->SetAddress(&photons_sigmaIEtaIEta_);
  photons_tkIsoHollow03_branch = tree->GetBranch(tree->GetAlias("photons_tkIsoHollow03"));
  if (photons_tkIsoHollow03_branch) photons_tkIsoHollow03_branch->SetAddress(&photons_tkIsoHollow03_);
  puInfo_trueNumInteractions_branch = tree->GetBranch(tree->GetAlias("puInfo_trueNumInteractions"));
  if (puInfo_trueNumInteractions_branch) puInfo_trueNumInteractions_branch->SetAddress(&puInfo_trueNumInteractions_);
  svs_anglePV_branch = tree->GetBranch(tree->GetAlias("svs_anglePV"));
  if (svs_anglePV_branch) svs_anglePV_branch->SetAddress(&svs_anglePV_);
  svs_chi2_branch = tree->GetBranch(tree->GetAlias("svs_chi2"));
  if (svs_chi2_branch) svs_chi2_branch->SetAddress(&svs_chi2_);
  svs_dist3Dsig_branch = tree->GetBranch(tree->GetAlias("svs_dist3Dsig"));
  if (svs_dist3Dsig_branch) svs_dist3Dsig_branch->SetAddress(&svs_dist3Dsig_);
  svs_dist3Dval_branch = tree->GetBranch(tree->GetAlias("svs_dist3Dval"));
  if (svs_dist3Dval_branch) svs_dist3Dval_branch->SetAddress(&svs_dist3Dval_);
  svs_distXYsig_branch = tree->GetBranch(tree->GetAlias("svs_distXYsig"));
  if (svs_distXYsig_branch) svs_distXYsig_branch->SetAddress(&svs_distXYsig_);
  svs_distXYval_branch = tree->GetBranch(tree->GetAlias("svs_distXYval"));
  if (svs_distXYval_branch) svs_distXYval_branch->SetAddress(&svs_distXYval_);
  svs_ndof_branch = tree->GetBranch(tree->GetAlias("svs_ndof"));
  if (svs_ndof_branch) svs_ndof_branch->SetAddress(&svs_ndof_);
  svs_prob_branch = tree->GetBranch(tree->GetAlias("svs_prob"));
  if (svs_prob_branch) svs_prob_branch->SetAddress(&svs_prob_);
  svs_xError_branch = tree->GetBranch(tree->GetAlias("svs_xError"));
  if (svs_xError_branch) svs_xError_branch->SetAddress(&svs_xError_);
  svs_yError_branch = tree->GetBranch(tree->GetAlias("svs_yError"));
  if (svs_yError_branch) svs_yError_branch->SetAddress(&svs_yError_);
  svs_zError_branch = tree->GetBranch(tree->GetAlias("svs_zError"));
  if (svs_zError_branch) svs_zError_branch->SetAddress(&svs_zError_);
  ak8jets_area_branch = tree->GetBranch(tree->GetAlias("ak8jets_area"));
  if (ak8jets_area_branch) ak8jets_area_branch->SetAddress(&ak8jets_area_);
  ak8jets_mass_branch = tree->GetBranch(tree->GetAlias("ak8jets_mass"));
  if (ak8jets_mass_branch) ak8jets_mass_branch->SetAddress(&ak8jets_mass_);
  ak8jets_nJettinessTau1_branch = tree->GetBranch(tree->GetAlias("ak8jets_nJettinessTau1"));
  if (ak8jets_nJettinessTau1_branch) ak8jets_nJettinessTau1_branch->SetAddress(&ak8jets_nJettinessTau1_);
  ak8jets_nJettinessTau2_branch = tree->GetBranch(tree->GetAlias("ak8jets_nJettinessTau2"));
  if (ak8jets_nJettinessTau2_branch) ak8jets_nJettinessTau2_branch->SetAddress(&ak8jets_nJettinessTau2_);
  ak8jets_nJettinessTau3_branch = tree->GetBranch(tree->GetAlias("ak8jets_nJettinessTau3"));
  if (ak8jets_nJettinessTau3_branch) ak8jets_nJettinessTau3_branch->SetAddress(&ak8jets_nJettinessTau3_);
  ak8jets_prunedMass_branch = tree->GetBranch(tree->GetAlias("ak8jets_prunedMass"));
  if (ak8jets_prunedMass_branch) ak8jets_prunedMass_branch->SetAddress(&ak8jets_prunedMass_);
  ak8jets_puppi_eta_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_eta"));
  if (ak8jets_puppi_eta_branch) ak8jets_puppi_eta_branch->SetAddress(&ak8jets_puppi_eta_);
  ak8jets_puppi_mass_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_mass"));
  if (ak8jets_puppi_mass_branch) ak8jets_puppi_mass_branch->SetAddress(&ak8jets_puppi_mass_);
  ak8jets_puppi_nJettinessTau1_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_nJettinessTau1"));
  if (ak8jets_puppi_nJettinessTau1_branch) ak8jets_puppi_nJettinessTau1_branch->SetAddress(&ak8jets_puppi_nJettinessTau1_);
  ak8jets_puppi_nJettinessTau2_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_nJettinessTau2"));
  if (ak8jets_puppi_nJettinessTau2_branch) ak8jets_puppi_nJettinessTau2_branch->SetAddress(&ak8jets_puppi_nJettinessTau2_);
  ak8jets_puppi_nJettinessTau3_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_nJettinessTau3"));
  if (ak8jets_puppi_nJettinessTau3_branch) ak8jets_puppi_nJettinessTau3_branch->SetAddress(&ak8jets_puppi_nJettinessTau3_);
  ak8jets_puppi_phi_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_phi"));
  if (ak8jets_puppi_phi_branch) ak8jets_puppi_phi_branch->SetAddress(&ak8jets_puppi_phi_);
  ak8jets_puppi_pt_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_pt"));
  if (ak8jets_puppi_pt_branch) ak8jets_puppi_pt_branch->SetAddress(&ak8jets_puppi_pt_);
  ak8jets_puppi_softdropMass_branch = tree->GetBranch(tree->GetAlias("ak8jets_puppi_softdropMass"));
  if (ak8jets_puppi_softdropMass_branch) ak8jets_puppi_softdropMass_branch->SetAddress(&ak8jets_puppi_softdropMass_);
  ak8jets_softdropMass_branch = tree->GetBranch(tree->GetAlias("ak8jets_softdropMass"));
  if (ak8jets_softdropMass_branch) ak8jets_softdropMass_branch->SetAddress(&ak8jets_softdropMass_);
  ak8jets_undoJEC_branch = tree->GetBranch(tree->GetAlias("ak8jets_undoJEC"));
  if (ak8jets_undoJEC_branch) ak8jets_undoJEC_branch->SetAddress(&ak8jets_undoJEC_);
  vtxs_ndof_branch = tree->GetBranch(tree->GetAlias("vtxs_ndof"));
  if (vtxs_ndof_branch) vtxs_ndof_branch->SetAddress(&vtxs_ndof_);
  pfjets_bDiscriminators_branch = tree->GetBranch(tree->GetAlias("pfjets_bDiscriminators"));
  if (pfjets_bDiscriminators_branch) pfjets_bDiscriminators_branch->SetAddress(&pfjets_bDiscriminators_);
  pfjets_puppi_bDiscriminators_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_bDiscriminators"));
  if (pfjets_puppi_bDiscriminators_branch) pfjets_puppi_bDiscriminators_branch->SetAddress(&pfjets_puppi_bDiscriminators_);
  taus_pf_IDs_branch = tree->GetBranch(tree->GetAlias("taus_pf_IDs"));
  if (taus_pf_IDs_branch) taus_pf_IDs_branch->SetAddress(&taus_pf_IDs_);
  puInfo_instLumi_branch = tree->GetBranch(tree->GetAlias("puInfo_instLumi"));
  if (puInfo_instLumi_branch) puInfo_instLumi_branch->SetAddress(&puInfo_instLumi_);
  evt_bunchCrossing_branch = tree->GetBranch(tree->GetAlias("evt_bunchCrossing"));
  if (evt_bunchCrossing_branch) evt_bunchCrossing_branch->SetAddress(&evt_bunchCrossing_);
  evt_experimentType_branch = tree->GetBranch(tree->GetAlias("evt_experimentType"));
  if (evt_experimentType_branch) evt_experimentType_branch->SetAddress(&evt_experimentType_);
  evt_isRealData_branch = tree->GetBranch(tree->GetAlias("evt_isRealData"));
  if (evt_isRealData_branch) evt_isRealData_branch->SetAddress(&evt_isRealData_);
  evt_orbitNumber_branch = tree->GetBranch(tree->GetAlias("evt_orbitNumber"));
  if (evt_orbitNumber_branch) evt_orbitNumber_branch->SetAddress(&evt_orbitNumber_);
  evt_storeNumber_branch = tree->GetBranch(tree->GetAlias("evt_storeNumber"));
  if (evt_storeNumber_branch) evt_storeNumber_branch->SetAddress(&evt_storeNumber_);
  pdfinfo_id1_branch = tree->GetBranch(tree->GetAlias("pdfinfo_id1"));
  if (pdfinfo_id1_branch) pdfinfo_id1_branch->SetAddress(&pdfinfo_id1_);
  pdfinfo_id2_branch = tree->GetBranch(tree->GetAlias("pdfinfo_id2"));
  if (pdfinfo_id2_branch) pdfinfo_id2_branch->SetAddress(&pdfinfo_id2_);
  els_mc3_id_branch = tree->GetBranch(tree->GetAlias("els_mc3_id"));
  if (els_mc3_id_branch) els_mc3_id_branch->SetAddress(&els_mc3_id_);
  els_mc3idx_branch = tree->GetBranch(tree->GetAlias("els_mc3idx"));
  if (els_mc3idx_branch) els_mc3idx_branch->SetAddress(&els_mc3idx_);
  els_mc3_motherid_branch = tree->GetBranch(tree->GetAlias("els_mc3_motherid"));
  if (els_mc3_motherid_branch) els_mc3_motherid_branch->SetAddress(&els_mc3_motherid_);
  els_mc3_motheridx_branch = tree->GetBranch(tree->GetAlias("els_mc3_motheridx"));
  if (els_mc3_motheridx_branch) els_mc3_motheridx_branch->SetAddress(&els_mc3_motheridx_);
  els_mc_id_branch = tree->GetBranch(tree->GetAlias("els_mc_id"));
  if (els_mc_id_branch) els_mc_id_branch->SetAddress(&els_mc_id_);
  els_mc_motherid_branch = tree->GetBranch(tree->GetAlias("els_mc_motherid"));
  if (els_mc_motherid_branch) els_mc_motherid_branch->SetAddress(&els_mc_motherid_);
  mus_mc3_id_branch = tree->GetBranch(tree->GetAlias("mus_mc3_id"));
  if (mus_mc3_id_branch) mus_mc3_id_branch->SetAddress(&mus_mc3_id_);
  mus_mc3idx_branch = tree->GetBranch(tree->GetAlias("mus_mc3idx"));
  if (mus_mc3idx_branch) mus_mc3idx_branch->SetAddress(&mus_mc3idx_);
  mus_mc3_motherid_branch = tree->GetBranch(tree->GetAlias("mus_mc3_motherid"));
  if (mus_mc3_motherid_branch) mus_mc3_motherid_branch->SetAddress(&mus_mc3_motherid_);
  mus_mc3_motheridx_branch = tree->GetBranch(tree->GetAlias("mus_mc3_motheridx"));
  if (mus_mc3_motheridx_branch) mus_mc3_motheridx_branch->SetAddress(&mus_mc3_motheridx_);
  mus_mc_id_branch = tree->GetBranch(tree->GetAlias("mus_mc_id"));
  if (mus_mc_id_branch) mus_mc_id_branch->SetAddress(&mus_mc_id_);
  mus_mc_motherid_branch = tree->GetBranch(tree->GetAlias("mus_mc_motherid"));
  if (mus_mc_motherid_branch) mus_mc_motherid_branch->SetAddress(&mus_mc_motherid_);
  pfjets_mc3_id_branch = tree->GetBranch(tree->GetAlias("pfjets_mc3_id"));
  if (pfjets_mc3_id_branch) pfjets_mc3_id_branch->SetAddress(&pfjets_mc3_id_);
  pfjets_mc3idx_branch = tree->GetBranch(tree->GetAlias("pfjets_mc3idx"));
  if (pfjets_mc3idx_branch) pfjets_mc3idx_branch->SetAddress(&pfjets_mc3idx_);
  pfjets_mc_motherid_branch = tree->GetBranch(tree->GetAlias("pfjets_mc_motherid"));
  if (pfjets_mc_motherid_branch) pfjets_mc_motherid_branch->SetAddress(&pfjets_mc_motherid_);
  photons_mc3_id_branch = tree->GetBranch(tree->GetAlias("photons_mc3_id"));
  if (photons_mc3_id_branch) photons_mc3_id_branch->SetAddress(&photons_mc3_id_);
  photons_mc3idx_branch = tree->GetBranch(tree->GetAlias("photons_mc3idx"));
  if (photons_mc3idx_branch) photons_mc3idx_branch->SetAddress(&photons_mc3idx_);
  photons_mc3_motherid_branch = tree->GetBranch(tree->GetAlias("photons_mc3_motherid"));
  if (photons_mc3_motherid_branch) photons_mc3_motherid_branch->SetAddress(&photons_mc3_motherid_);
  photons_mc3_motheridx_branch = tree->GetBranch(tree->GetAlias("photons_mc3_motheridx"));
  if (photons_mc3_motheridx_branch) photons_mc3_motheridx_branch->SetAddress(&photons_mc3_motheridx_);
  photons_mc_id_branch = tree->GetBranch(tree->GetAlias("photons_mc_id"));
  if (photons_mc_id_branch) photons_mc_id_branch->SetAddress(&photons_mc_id_);
  photons_mc_motherid_branch = tree->GetBranch(tree->GetAlias("photons_mc_motherid"));
  if (photons_mc_motherid_branch) photons_mc_motherid_branch->SetAddress(&photons_mc_motherid_);
  els_VIDNonTrigMvaCat_branch = tree->GetBranch(tree->GetAlias("els_VIDNonTrigMvaCat"));
  if (els_VIDNonTrigMvaCat_branch) els_VIDNonTrigMvaCat_branch->SetAddress(&els_VIDNonTrigMvaCat_);
  els_VIDSpring16GPMvaCat_branch = tree->GetBranch(tree->GetAlias("els_VIDSpring16GPMvaCat"));
  if (els_VIDSpring16GPMvaCat_branch) els_VIDSpring16GPMvaCat_branch->SetAddress(&els_VIDSpring16GPMvaCat_);
  els_VIDSpring16HZZMvaCat_branch = tree->GetBranch(tree->GetAlias("els_VIDSpring16HZZMvaCat"));
  if (els_VIDSpring16HZZMvaCat_branch) els_VIDSpring16HZZMvaCat_branch->SetAddress(&els_VIDSpring16HZZMvaCat_);
  els_VIDTrigMvaCat_branch = tree->GetBranch(tree->GetAlias("els_VIDTrigMvaCat"));
  if (els_VIDTrigMvaCat_branch) els_VIDTrigMvaCat_branch->SetAddress(&els_VIDTrigMvaCat_);
  els_category_branch = tree->GetBranch(tree->GetAlias("els_category"));
  if (els_category_branch) els_category_branch->SetAddress(&els_category_);
  els_charge_branch = tree->GetBranch(tree->GetAlias("els_charge"));
  if (els_charge_branch) els_charge_branch->SetAddress(&els_charge_);
  els_ckf_charge_branch = tree->GetBranch(tree->GetAlias("els_ckf_charge"));
  if (els_ckf_charge_branch) els_ckf_charge_branch->SetAddress(&els_ckf_charge_);
  els_ckf_laywithmeas_branch = tree->GetBranch(tree->GetAlias("els_ckf_laywithmeas"));
  if (els_ckf_laywithmeas_branch) els_ckf_laywithmeas_branch->SetAddress(&els_ckf_laywithmeas_);
  els_exp_innerlayers_branch = tree->GetBranch(tree->GetAlias("els_exp_innerlayers"));
  if (els_exp_innerlayers_branch) els_exp_innerlayers_branch->SetAddress(&els_exp_innerlayers_);
  els_exp_outerlayers_branch = tree->GetBranch(tree->GetAlias("els_exp_outerlayers"));
  if (els_exp_outerlayers_branch) els_exp_outerlayers_branch->SetAddress(&els_exp_outerlayers_);
  els_isEB_branch = tree->GetBranch(tree->GetAlias("els_isEB"));
  if (els_isEB_branch) els_isEB_branch->SetAddress(&els_isEB_);
  els_isEcalDriven_branch = tree->GetBranch(tree->GetAlias("els_isEcalDriven"));
  if (els_isEcalDriven_branch) els_isEcalDriven_branch->SetAddress(&els_isEcalDriven_);
  els_isTrackerDriven_branch = tree->GetBranch(tree->GetAlias("els_isTrackerDriven"));
  if (els_isTrackerDriven_branch) els_isTrackerDriven_branch->SetAddress(&els_isTrackerDriven_);
  els_lostHits_branch = tree->GetBranch(tree->GetAlias("els_lostHits"));
  if (els_lostHits_branch) els_lostHits_branch->SetAddress(&els_lostHits_);
  els_lost_pixelhits_branch = tree->GetBranch(tree->GetAlias("els_lost_pixelhits"));
  if (els_lost_pixelhits_branch) els_lost_pixelhits_branch->SetAddress(&els_lost_pixelhits_);
  els_mc_patMatch_id_branch = tree->GetBranch(tree->GetAlias("els_mc_patMatch_id"));
  if (els_mc_patMatch_id_branch) els_mc_patMatch_id_branch->SetAddress(&els_mc_patMatch_id_);
  els_nlayers_branch = tree->GetBranch(tree->GetAlias("els_nlayers"));
  if (els_nlayers_branch) els_nlayers_branch->SetAddress(&els_nlayers_);
  els_nlayers3D_branch = tree->GetBranch(tree->GetAlias("els_nlayers3D"));
  if (els_nlayers3D_branch) els_nlayers3D_branch->SetAddress(&els_nlayers3D_);
  els_nlayersLost_branch = tree->GetBranch(tree->GetAlias("els_nlayersLost"));
  if (els_nlayersLost_branch) els_nlayersLost_branch->SetAddress(&els_nlayersLost_);
  els_sccharge_branch = tree->GetBranch(tree->GetAlias("els_sccharge"));
  if (els_sccharge_branch) els_sccharge_branch->SetAddress(&els_sccharge_);
  els_trk_charge_branch = tree->GetBranch(tree->GetAlias("els_trk_charge"));
  if (els_trk_charge_branch) els_trk_charge_branch->SetAddress(&els_trk_charge_);
  els_type_branch = tree->GetBranch(tree->GetAlias("els_type"));
  if (els_type_branch) els_type_branch->SetAddress(&els_type_);
  els_validHits_branch = tree->GetBranch(tree->GetAlias("els_validHits"));
  if (els_validHits_branch) els_validHits_branch->SetAddress(&els_validHits_);
  els_valid_pixelhits_branch = tree->GetBranch(tree->GetAlias("els_valid_pixelhits"));
  if (els_valid_pixelhits_branch) els_valid_pixelhits_branch->SetAddress(&els_valid_pixelhits_);
  els_passVIDNonTrigMvaWP80Id_branch = tree->GetBranch(tree->GetAlias("els_passVIDNonTrigMvaWP80Id"));
  if (els_passVIDNonTrigMvaWP80Id_branch) els_passVIDNonTrigMvaWP80Id_branch->SetAddress(&els_passVIDNonTrigMvaWP80Id_);
  els_passVIDNonTrigMvaWP90Id_branch = tree->GetBranch(tree->GetAlias("els_passVIDNonTrigMvaWP90Id"));
  if (els_passVIDNonTrigMvaWP90Id_branch) els_passVIDNonTrigMvaWP90Id_branch->SetAddress(&els_passVIDNonTrigMvaWP90Id_);
  els_passVIDTrigMvaWP80Id_branch = tree->GetBranch(tree->GetAlias("els_passVIDTrigMvaWP80Id"));
  if (els_passVIDTrigMvaWP80Id_branch) els_passVIDTrigMvaWP80Id_branch->SetAddress(&els_passVIDTrigMvaWP80Id_);
  els_passVIDTrigMvaWP90Id_branch = tree->GetBranch(tree->GetAlias("els_passVIDTrigMvaWP90Id"));
  if (els_passVIDTrigMvaWP90Id_branch) els_passVIDTrigMvaWP90Id_branch->SetAddress(&els_passVIDTrigMvaWP90Id_);
  genps_id_branch = tree->GetBranch(tree->GetAlias("genps_id"));
  if (genps_id_branch) genps_id_branch->SetAddress(&genps_id_);
  genps_id_mother_branch = tree->GetBranch(tree->GetAlias("genps_id_mother"));
  if (genps_id_mother_branch) genps_id_mother_branch->SetAddress(&genps_id_mother_);
  genps_id_simplegrandma_branch = tree->GetBranch(tree->GetAlias("genps_id_simplegrandma"));
  if (genps_id_simplegrandma_branch) genps_id_simplegrandma_branch->SetAddress(&genps_id_simplegrandma_);
  genps_id_simplemother_branch = tree->GetBranch(tree->GetAlias("genps_id_simplemother"));
  if (genps_id_simplemother_branch) genps_id_simplemother_branch->SetAddress(&genps_id_simplemother_);
  genps_idx_mother_branch = tree->GetBranch(tree->GetAlias("genps_idx_mother"));
  if (genps_idx_mother_branch) genps_idx_mother_branch->SetAddress(&genps_idx_mother_);
  genps_idx_simplemother_branch = tree->GetBranch(tree->GetAlias("genps_idx_simplemother"));
  if (genps_idx_simplemother_branch) genps_idx_simplemother_branch->SetAddress(&genps_idx_simplemother_);
  genps_status_branch = tree->GetBranch(tree->GetAlias("genps_status"));
  if (genps_status_branch) genps_status_branch->SetAddress(&genps_status_);
  hyp_ll_charge_branch = tree->GetBranch(tree->GetAlias("hyp_ll_charge"));
  if (hyp_ll_charge_branch) hyp_ll_charge_branch->SetAddress(&hyp_ll_charge_);
  hyp_ll_id_branch = tree->GetBranch(tree->GetAlias("hyp_ll_id"));
  if (hyp_ll_id_branch) hyp_ll_id_branch->SetAddress(&hyp_ll_id_);
  hyp_ll_index_branch = tree->GetBranch(tree->GetAlias("hyp_ll_index"));
  if (hyp_ll_index_branch) hyp_ll_index_branch->SetAddress(&hyp_ll_index_);
  hyp_lt_charge_branch = tree->GetBranch(tree->GetAlias("hyp_lt_charge"));
  if (hyp_lt_charge_branch) hyp_lt_charge_branch->SetAddress(&hyp_lt_charge_);
  hyp_lt_id_branch = tree->GetBranch(tree->GetAlias("hyp_lt_id"));
  if (hyp_lt_id_branch) hyp_lt_id_branch->SetAddress(&hyp_lt_id_);
  hyp_lt_index_branch = tree->GetBranch(tree->GetAlias("hyp_lt_index"));
  if (hyp_lt_index_branch) hyp_lt_index_branch->SetAddress(&hyp_lt_index_);
  hyp_type_branch = tree->GetBranch(tree->GetAlias("hyp_type"));
  if (hyp_type_branch) hyp_type_branch->SetAddress(&hyp_type_);
  isotracks_charge_branch = tree->GetBranch(tree->GetAlias("isotracks_charge"));
  if (isotracks_charge_branch) isotracks_charge_branch->SetAddress(&isotracks_charge_);
  isotracks_fromPV_branch = tree->GetBranch(tree->GetAlias("isotracks_fromPV"));
  if (isotracks_fromPV_branch) isotracks_fromPV_branch->SetAddress(&isotracks_fromPV_);
  isotracks_numberOfLostHitsInner_branch = tree->GetBranch(tree->GetAlias("isotracks_numberOfLostHitsInner"));
  if (isotracks_numberOfLostHitsInner_branch) isotracks_numberOfLostHitsInner_branch->SetAddress(&isotracks_numberOfLostHitsInner_);
  isotracks_numberOfLostHitsOuter_branch = tree->GetBranch(tree->GetAlias("isotracks_numberOfLostHitsOuter"));
  if (isotracks_numberOfLostHitsOuter_branch) isotracks_numberOfLostHitsOuter_branch->SetAddress(&isotracks_numberOfLostHitsOuter_);
  isotracks_numberOfLostPixelHitsInner_branch = tree->GetBranch(tree->GetAlias("isotracks_numberOfLostPixelHitsInner"));
  if (isotracks_numberOfLostPixelHitsInner_branch) isotracks_numberOfLostPixelHitsInner_branch->SetAddress(&isotracks_numberOfLostPixelHitsInner_);
  isotracks_numberOfValidPixelHits_branch = tree->GetBranch(tree->GetAlias("isotracks_numberOfValidPixelHits"));
  if (isotracks_numberOfValidPixelHits_branch) isotracks_numberOfValidPixelHits_branch->SetAddress(&isotracks_numberOfValidPixelHits_);
  isotracks_particleId_branch = tree->GetBranch(tree->GetAlias("isotracks_particleId"));
  if (isotracks_particleId_branch) isotracks_particleId_branch->SetAddress(&isotracks_particleId_);
  isotracks_pixelLayersWithMeasurement_branch = tree->GetBranch(tree->GetAlias("isotracks_pixelLayersWithMeasurement"));
  if (isotracks_pixelLayersWithMeasurement_branch) isotracks_pixelLayersWithMeasurement_branch->SetAddress(&isotracks_pixelLayersWithMeasurement_);
  isotracks_trackerLayersWithMeasurement_branch = tree->GetBranch(tree->GetAlias("isotracks_trackerLayersWithMeasurement"));
  if (isotracks_trackerLayersWithMeasurement_branch) isotracks_trackerLayersWithMeasurement_branch->SetAddress(&isotracks_trackerLayersWithMeasurement_);
  mus_algo_branch = tree->GetBranch(tree->GetAlias("mus_algo"));
  if (mus_algo_branch) mus_algo_branch->SetAddress(&mus_algo_);
  mus_algoOrig_branch = tree->GetBranch(tree->GetAlias("mus_algoOrig"));
  if (mus_algoOrig_branch) mus_algoOrig_branch->SetAddress(&mus_algoOrig_);
  mus_bfit_algo_branch = tree->GetBranch(tree->GetAlias("mus_bfit_algo"));
  if (mus_bfit_algo_branch) mus_bfit_algo_branch->SetAddress(&mus_bfit_algo_);
  mus_charge_branch = tree->GetBranch(tree->GetAlias("mus_charge"));
  if (mus_charge_branch) mus_charge_branch->SetAddress(&mus_charge_);
  mus_exp_innerlayers_branch = tree->GetBranch(tree->GetAlias("mus_exp_innerlayers"));
  if (mus_exp_innerlayers_branch) mus_exp_innerlayers_branch->SetAddress(&mus_exp_innerlayers_);
  mus_exp_outerlayers_branch = tree->GetBranch(tree->GetAlias("mus_exp_outerlayers"));
  if (mus_exp_outerlayers_branch) mus_exp_outerlayers_branch->SetAddress(&mus_exp_outerlayers_);
  mus_gfit_algo_branch = tree->GetBranch(tree->GetAlias("mus_gfit_algo"));
  if (mus_gfit_algo_branch) mus_gfit_algo_branch->SetAddress(&mus_gfit_algo_);
  mus_gfit_ndof_branch = tree->GetBranch(tree->GetAlias("mus_gfit_ndof"));
  if (mus_gfit_ndof_branch) mus_gfit_ndof_branch->SetAddress(&mus_gfit_ndof_);
  mus_gfit_validSTAHits_branch = tree->GetBranch(tree->GetAlias("mus_gfit_validSTAHits"));
  if (mus_gfit_validSTAHits_branch) mus_gfit_validSTAHits_branch->SetAddress(&mus_gfit_validSTAHits_);
  mus_iso03_ntrk_branch = tree->GetBranch(tree->GetAlias("mus_iso03_ntrk"));
  if (mus_iso03_ntrk_branch) mus_iso03_ntrk_branch->SetAddress(&mus_iso03_ntrk_);
  mus_lostHits_branch = tree->GetBranch(tree->GetAlias("mus_lostHits"));
  if (mus_lostHits_branch) mus_lostHits_branch->SetAddress(&mus_lostHits_);
  mus_mc_patMatch_id_branch = tree->GetBranch(tree->GetAlias("mus_mc_patMatch_id"));
  if (mus_mc_patMatch_id_branch) mus_mc_patMatch_id_branch->SetAddress(&mus_mc_patMatch_id_);
  mus_nlayers_branch = tree->GetBranch(tree->GetAlias("mus_nlayers"));
  if (mus_nlayers_branch) mus_nlayers_branch->SetAddress(&mus_nlayers_);
  mus_numberOfMatchedStations_branch = tree->GetBranch(tree->GetAlias("mus_numberOfMatchedStations"));
  if (mus_numberOfMatchedStations_branch) mus_numberOfMatchedStations_branch->SetAddress(&mus_numberOfMatchedStations_);
  mus_pfcharge_branch = tree->GetBranch(tree->GetAlias("mus_pfcharge"));
  if (mus_pfcharge_branch) mus_pfcharge_branch->SetAddress(&mus_pfcharge_);
  mus_pfidx_branch = tree->GetBranch(tree->GetAlias("mus_pfidx"));
  if (mus_pfidx_branch) mus_pfidx_branch->SetAddress(&mus_pfidx_);
  mus_pfparticleId_branch = tree->GetBranch(tree->GetAlias("mus_pfparticleId"));
  if (mus_pfparticleId_branch) mus_pfparticleId_branch->SetAddress(&mus_pfparticleId_);
  mus_pid_PFMuon_branch = tree->GetBranch(tree->GetAlias("mus_pid_PFMuon"));
  if (mus_pid_PFMuon_branch) mus_pid_PFMuon_branch->SetAddress(&mus_pid_PFMuon_);
  mus_pid_TM2DCompatibilityLoose_branch = tree->GetBranch(tree->GetAlias("mus_pid_TM2DCompatibilityLoose"));
  if (mus_pid_TM2DCompatibilityLoose_branch) mus_pid_TM2DCompatibilityLoose_branch->SetAddress(&mus_pid_TM2DCompatibilityLoose_);
  mus_pid_TM2DCompatibilityTight_branch = tree->GetBranch(tree->GetAlias("mus_pid_TM2DCompatibilityTight"));
  if (mus_pid_TM2DCompatibilityTight_branch) mus_pid_TM2DCompatibilityTight_branch->SetAddress(&mus_pid_TM2DCompatibilityTight_);
  mus_pid_TMLastStationLoose_branch = tree->GetBranch(tree->GetAlias("mus_pid_TMLastStationLoose"));
  if (mus_pid_TMLastStationLoose_branch) mus_pid_TMLastStationLoose_branch->SetAddress(&mus_pid_TMLastStationLoose_);
  mus_pid_TMLastStationTight_branch = tree->GetBranch(tree->GetAlias("mus_pid_TMLastStationTight"));
  if (mus_pid_TMLastStationTight_branch) mus_pid_TMLastStationTight_branch->SetAddress(&mus_pid_TMLastStationTight_);
  mus_pid_TMOneStationTight_branch = tree->GetBranch(tree->GetAlias("mus_pid_TMOneStationTight"));
  if (mus_pid_TMOneStationTight_branch) mus_pid_TMOneStationTight_branch->SetAddress(&mus_pid_TMOneStationTight_);
  mus_type_branch = tree->GetBranch(tree->GetAlias("mus_type"));
  if (mus_type_branch) mus_type_branch->SetAddress(&mus_type_);
  mus_validHits_branch = tree->GetBranch(tree->GetAlias("mus_validHits"));
  if (mus_validHits_branch) mus_validHits_branch->SetAddress(&mus_validHits_);
  mus_validPixelHits_branch = tree->GetBranch(tree->GetAlias("mus_validPixelHits"));
  if (mus_validPixelHits_branch) mus_validPixelHits_branch->SetAddress(&mus_validPixelHits_);
  pfcands_IdAssociatedPV_branch = tree->GetBranch(tree->GetAlias("pfcands_IdAssociatedPV"));
  if (pfcands_IdAssociatedPV_branch) pfcands_IdAssociatedPV_branch->SetAddress(&pfcands_IdAssociatedPV_);
  pfcands_charge_branch = tree->GetBranch(tree->GetAlias("pfcands_charge"));
  if (pfcands_charge_branch) pfcands_charge_branch->SetAddress(&pfcands_charge_);
  pfcands_numberOfHits_branch = tree->GetBranch(tree->GetAlias("pfcands_numberOfHits"));
  if (pfcands_numberOfHits_branch) pfcands_numberOfHits_branch->SetAddress(&pfcands_numberOfHits_);
  pfcands_numberOfPixelHits_branch = tree->GetBranch(tree->GetAlias("pfcands_numberOfPixelHits"));
  if (pfcands_numberOfPixelHits_branch) pfcands_numberOfPixelHits_branch->SetAddress(&pfcands_numberOfPixelHits_);
  pfcands_particleId_branch = tree->GetBranch(tree->GetAlias("pfcands_particleId"));
  if (pfcands_particleId_branch) pfcands_particleId_branch->SetAddress(&pfcands_particleId_);
  pfcands_pixelLayersWithMeasurement_branch = tree->GetBranch(tree->GetAlias("pfcands_pixelLayersWithMeasurement"));
  if (pfcands_pixelLayersWithMeasurement_branch) pfcands_pixelLayersWithMeasurement_branch->SetAddress(&pfcands_pixelLayersWithMeasurement_);
  pfcands_stripLayersWithMeasurement_branch = tree->GetBranch(tree->GetAlias("pfcands_stripLayersWithMeasurement"));
  if (pfcands_stripLayersWithMeasurement_branch) pfcands_stripLayersWithMeasurement_branch->SetAddress(&pfcands_stripLayersWithMeasurement_);
  pfjets_chargedHadronMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_chargedHadronMultiplicity"));
  if (pfjets_chargedHadronMultiplicity_branch) pfjets_chargedHadronMultiplicity_branch->SetAddress(&pfjets_chargedHadronMultiplicity_);
  pfjets_chargedMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_chargedMultiplicity"));
  if (pfjets_chargedMultiplicity_branch) pfjets_chargedMultiplicity_branch->SetAddress(&pfjets_chargedMultiplicity_);
  pfjets_electronMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_electronMultiplicity"));
  if (pfjets_electronMultiplicity_branch) pfjets_electronMultiplicity_branch->SetAddress(&pfjets_electronMultiplicity_);
  pfjets_hadronFlavour_branch = tree->GetBranch(tree->GetAlias("pfjets_hadronFlavour"));
  if (pfjets_hadronFlavour_branch) pfjets_hadronFlavour_branch->SetAddress(&pfjets_hadronFlavour_);
  pfjets_muonMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_muonMultiplicity"));
  if (pfjets_muonMultiplicity_branch) pfjets_muonMultiplicity_branch->SetAddress(&pfjets_muonMultiplicity_);
  pfjets_neutralHadronMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_neutralHadronMultiplicity"));
  if (pfjets_neutralHadronMultiplicity_branch) pfjets_neutralHadronMultiplicity_branch->SetAddress(&pfjets_neutralHadronMultiplicity_);
  pfjets_neutralMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_neutralMultiplicity"));
  if (pfjets_neutralMultiplicity_branch) pfjets_neutralMultiplicity_branch->SetAddress(&pfjets_neutralMultiplicity_);
  pfjets_npfcands_branch = tree->GetBranch(tree->GetAlias("pfjets_npfcands"));
  if (pfjets_npfcands_branch) pfjets_npfcands_branch->SetAddress(&pfjets_npfcands_);
  pfjets_partonFlavour_branch = tree->GetBranch(tree->GetAlias("pfjets_partonFlavour"));
  if (pfjets_partonFlavour_branch) pfjets_partonFlavour_branch->SetAddress(&pfjets_partonFlavour_);
  pfjets_photonMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_photonMultiplicity"));
  if (pfjets_photonMultiplicity_branch) pfjets_photonMultiplicity_branch->SetAddress(&pfjets_photonMultiplicity_);
  pfjets_totalMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_totalMultiplicity"));
  if (pfjets_totalMultiplicity_branch) pfjets_totalMultiplicity_branch->SetAddress(&pfjets_totalMultiplicity_);
  pfjets_puppi_chargedHadronMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_chargedHadronMultiplicity"));
  if (pfjets_puppi_chargedHadronMultiplicity_branch) pfjets_puppi_chargedHadronMultiplicity_branch->SetAddress(&pfjets_puppi_chargedHadronMultiplicity_);
  pfjets_puppi_chargedMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_chargedMultiplicity"));
  if (pfjets_puppi_chargedMultiplicity_branch) pfjets_puppi_chargedMultiplicity_branch->SetAddress(&pfjets_puppi_chargedMultiplicity_);
  pfjets_puppi_electronMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_electronMultiplicity"));
  if (pfjets_puppi_electronMultiplicity_branch) pfjets_puppi_electronMultiplicity_branch->SetAddress(&pfjets_puppi_electronMultiplicity_);
  pfjets_puppi_hadronFlavour_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_hadronFlavour"));
  if (pfjets_puppi_hadronFlavour_branch) pfjets_puppi_hadronFlavour_branch->SetAddress(&pfjets_puppi_hadronFlavour_);
  pfjets_puppi_muonMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_muonMultiplicity"));
  if (pfjets_puppi_muonMultiplicity_branch) pfjets_puppi_muonMultiplicity_branch->SetAddress(&pfjets_puppi_muonMultiplicity_);
  pfjets_puppi_neutralHadronMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_neutralHadronMultiplicity"));
  if (pfjets_puppi_neutralHadronMultiplicity_branch) pfjets_puppi_neutralHadronMultiplicity_branch->SetAddress(&pfjets_puppi_neutralHadronMultiplicity_);
  pfjets_puppi_neutralMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_neutralMultiplicity"));
  if (pfjets_puppi_neutralMultiplicity_branch) pfjets_puppi_neutralMultiplicity_branch->SetAddress(&pfjets_puppi_neutralMultiplicity_);
  pfjets_puppi_npfcands_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_npfcands"));
  if (pfjets_puppi_npfcands_branch) pfjets_puppi_npfcands_branch->SetAddress(&pfjets_puppi_npfcands_);
  pfjets_puppi_partonFlavour_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_partonFlavour"));
  if (pfjets_puppi_partonFlavour_branch) pfjets_puppi_partonFlavour_branch->SetAddress(&pfjets_puppi_partonFlavour_);
  pfjets_puppi_photonMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_photonMultiplicity"));
  if (pfjets_puppi_photonMultiplicity_branch) pfjets_puppi_photonMultiplicity_branch->SetAddress(&pfjets_puppi_photonMultiplicity_);
  pfjets_puppi_totalMultiplicity_branch = tree->GetBranch(tree->GetAlias("pfjets_puppi_totalMultiplicity"));
  if (pfjets_puppi_totalMultiplicity_branch) pfjets_puppi_totalMultiplicity_branch->SetAddress(&pfjets_puppi_totalMultiplicity_);
  taus_pf_charge_branch = tree->GetBranch(tree->GetAlias("taus_pf_charge"));
  if (taus_pf_charge_branch) taus_pf_charge_branch->SetAddress(&taus_pf_charge_);
  photons_photonID_loose_branch = tree->GetBranch(tree->GetAlias("photons_photonID_loose"));
  if (photons_photonID_loose_branch) photons_photonID_loose_branch->SetAddress(&photons_photonID_loose_);
  photons_photonID_tight_branch = tree->GetBranch(tree->GetAlias("photons_photonID_tight"));
  if (photons_photonID_tight_branch) photons_photonID_tight_branch->SetAddress(&photons_photonID_tight_);
  puInfo_bunchCrossing_branch = tree->GetBranch(tree->GetAlias("puInfo_bunchCrossing"));
  if (puInfo_bunchCrossing_branch) puInfo_bunchCrossing_branch->SetAddress(&puInfo_bunchCrossing_);
  puInfo_nPUvertices_branch = tree->GetBranch(tree->GetAlias("puInfo_nPUvertices"));
  if (puInfo_nPUvertices_branch) puInfo_nPUvertices_branch->SetAddress(&puInfo_nPUvertices_);
  svs_nTrks_branch = tree->GetBranch(tree->GetAlias("svs_nTrks"));
  if (svs_nTrks_branch) svs_nTrks_branch->SetAddress(&svs_nTrks_);
  _npfcands_branch = tree->GetBranch(tree->GetAlias("_npfcands"));
  if (_npfcands_branch) _npfcands_branch->SetAddress(&_npfcands_);
  ak8jets_partonFlavour_branch = tree->GetBranch(tree->GetAlias("ak8jets_partonFlavour"));
  if (ak8jets_partonFlavour_branch) ak8jets_partonFlavour_branch->SetAddress(&ak8jets_partonFlavour_);
  vtxs_isFake_branch = tree->GetBranch(tree->GetAlias("vtxs_isFake"));
  if (vtxs_isFake_branch) vtxs_isFake_branch->SetAddress(&vtxs_isFake_);
  vtxs_isValid_branch = tree->GetBranch(tree->GetAlias("vtxs_isValid"));
  if (vtxs_isValid_branch) vtxs_isValid_branch->SetAddress(&vtxs_isValid_);
  genps_lepdaughter_id_branch = tree->GetBranch(tree->GetAlias("genps_lepdaughter_id"));
  if (genps_lepdaughter_id_branch) genps_lepdaughter_id_branch->SetAddress(&genps_lepdaughter_id_);
  genps_lepdaughter_idx_branch = tree->GetBranch(tree->GetAlias("genps_lepdaughter_idx"));
  if (genps_lepdaughter_idx_branch) genps_lepdaughter_idx_branch->SetAddress(&genps_lepdaughter_idx_);
  photons_PFCand_idx_branch = tree->GetBranch(tree->GetAlias("photons_PFCand_idx"));
  if (photons_PFCand_idx_branch) photons_PFCand_idx_branch->SetAddress(&photons_PFCand_idx_);
  pfcands_fromPV_branch = tree->GetBranch(tree->GetAlias("pfcands_fromPV"));
  if (pfcands_fromPV_branch) pfcands_fromPV_branch->SetAddress(&pfcands_fromPV_);
  pfcands_normalizedChi2_branch = tree->GetBranch(tree->GetAlias("pfcands_normalizedChi2"));
  if (pfcands_normalizedChi2_branch) pfcands_normalizedChi2_branch->SetAddress(&pfcands_normalizedChi2_);
  pfcands_packedHits_branch = tree->GetBranch(tree->GetAlias("pfcands_packedHits"));
  if (pfcands_packedHits_branch) pfcands_packedHits_branch->SetAddress(&pfcands_packedHits_);
  pfcands_packedLayers_branch = tree->GetBranch(tree->GetAlias("pfcands_packedLayers"));
  if (pfcands_packedLayers_branch) pfcands_packedLayers_branch->SetAddress(&pfcands_packedLayers_);
  pfcands_pvAssociationQuality_branch = tree->GetBranch(tree->GetAlias("pfcands_pvAssociationQuality"));
  if (pfcands_pvAssociationQuality_branch) pfcands_pvAssociationQuality_branch->SetAddress(&pfcands_pvAssociationQuality_);
  evt_nels_branch = tree->GetBranch(tree->GetAlias("evt_nels"));
  if (evt_nels_branch) evt_nels_branch->SetAddress(&evt_nels_);
  evt_detectorStatus_branch = tree->GetBranch(tree->GetAlias("evt_detectorStatus"));
  if (evt_detectorStatus_branch) evt_detectorStatus_branch->SetAddress(&evt_detectorStatus_);
  evt_lumiBlock_branch = tree->GetBranch(tree->GetAlias("evt_lumiBlock"));
  if (evt_lumiBlock_branch) evt_lumiBlock_branch->SetAddress(&evt_lumiBlock_);
  evt_run_branch = tree->GetBranch(tree->GetAlias("evt_run"));
  if (evt_run_branch) evt_run_branch->SetAddress(&evt_run_);
  evt_ngenjetsNoMuNoNu_branch = tree->GetBranch(tree->GetAlias("evt_ngenjetsNoMuNoNu"));
  if (evt_ngenjetsNoMuNoNu_branch) evt_ngenjetsNoMuNoNu_branch->SetAddress(&evt_ngenjetsNoMuNoNu_);
  genps_signalProcessID_branch = tree->GetBranch(tree->GetAlias("genps_signalProcessID"));
  if (genps_signalProcessID_branch) genps_signalProcessID_branch->SetAddress(&genps_signalProcessID_);
  evt_nphotons_branch = tree->GetBranch(tree->GetAlias("evt_nphotons"));
  if (evt_nphotons_branch) evt_nphotons_branch->SetAddress(&evt_nphotons_);
  evt_nvtxs_branch = tree->GetBranch(tree->GetAlias("evt_nvtxs"));
  if (evt_nvtxs_branch) evt_nvtxs_branch->SetAddress(&evt_nvtxs_);
  hlt_l1prescales_branch = tree->GetBranch(tree->GetAlias("hlt_l1prescales"));
  if (hlt_l1prescales_branch) hlt_l1prescales_branch->SetAddress(&hlt_l1prescales_);
  hlt_prescales_branch = tree->GetBranch(tree->GetAlias("hlt_prescales"));
  if (hlt_prescales_branch) hlt_prescales_branch->SetAddress(&hlt_prescales_);
  isotracks_crossedHcalStatus_branch = tree->GetBranch(tree->GetAlias("isotracks_crossedHcalStatus"));
  if (isotracks_crossedHcalStatus_branch) isotracks_crossedHcalStatus_branch->SetAddress(&isotracks_crossedHcalStatus_);
  evt_event_branch = tree->GetBranch(tree->GetAlias("evt_event"));
  if (evt_event_branch) evt_event_branch->SetAddress(&evt_event_);
  evt_timestamp_branch = tree->GetBranch(tree->GetAlias("evt_timestamp"));
  if (evt_timestamp_branch) evt_timestamp_branch->SetAddress(&evt_timestamp_);

  tree->SetMakeClass(0);
}

void CMS3::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  genweightsID_isLoaded = false;
  hlt_bits_isLoaded = false;
  evt_CMS3tag_isLoaded = false;
  evt_dataset_isLoaded = false;
  hlt_trigNames_isLoaded = false;
  pfjets_bDiscriminatorNames_isLoaded = false;
  pfjets_puppi_bDiscriminatorNames_isLoaded = false;
  taus_pf_IDnames_isLoaded = false;
  evt_cscTightHaloId_isLoaded = false;
  evt_hbheFilter_isLoaded = false;
  filt_chargedHadronTrackResolution_isLoaded = false;
  filt_cscBeamHalo_isLoaded = false;
  filt_cscBeamHalo2015_isLoaded = false;
  filt_cscBeamHaloTrkMuUnveto_isLoaded = false;
  filt_ecalBoundaryEnergy_isLoaded = false;
  filt_ecalLaser_isLoaded = false;
  filt_ecalTP_isLoaded = false;
  filt_eeBadSc_isLoaded = false;
  filt_globalSuperTightHalo2016_isLoaded = false;
  filt_globalTightHalo2016_isLoaded = false;
  filt_goodVertices_isLoaded = false;
  filt_hbheNoise_isLoaded = false;
  filt_hbheNoiseIso_isLoaded = false;
  filt_hcalLaser_isLoaded = false;
  filt_hcalStrip_isLoaded = false;
  filt_metfilter_isLoaded = false;
  filt_muonBadTrack_isLoaded = false;
  filt_trackingFailure_isLoaded = false;
  filt_trkPOGFilters_isLoaded = false;
  filt_trkPOG_logErrorTooManyClusters_isLoaded = false;
  filt_trkPOG_manystripclus53X_isLoaded = false;
  filt_trkPOG_toomanystripclus53X_isLoaded = false;
  els_conv_vtx_flag_isLoaded = false;
  els_isGsfCtfScPixChargeConsistent_isLoaded = false;
  genps_fromHardProcessBeforeFSR_isLoaded = false;
  genps_fromHardProcessDecayed_isLoaded = false;
  genps_fromHardProcessFinalState_isLoaded = false;
  genps_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
  genps_isDirectPromptTauDecayProductFinalState_isLoaded = false;
  genps_isHardProcess_isLoaded = false;
  genps_isLastCopy_isLoaded = false;
  genps_isLastCopyBeforeFSR_isLoaded = false;
  genps_isMostlyLikePythia6Status3_isLoaded = false;
  genps_isPromptDecayed_isLoaded = false;
  genps_isPromptFinalState_isLoaded = false;
  isotracks_isHighPurityTrack_isLoaded = false;
  isotracks_isPFCand_isLoaded = false;
  isotracks_isTightTrack_isLoaded = false;
  pfcands_isGlobalMuon_isLoaded = false;
  pfcands_isStandAloneMuon_isLoaded = false;
  pfcands_trackHighPurity_isLoaded = false;
  photons_haspixelSeed_isLoaded = false;
  photons_passElectronVeto_isLoaded = false;
  evt_bField_isLoaded = false;
  evt_instantLumi_isLoaded = false;
  evt_instantLumiErr_isLoaded = false;
  evt_lumiFill_isLoaded = false;
  evt_lumiRun_isLoaded = false;
  evt_pileup_isLoaded = false;
  evt_pileupRMS_isLoaded = false;
  evt_fixgrid_all_rho_isLoaded = false;
  evt_fixgridfastjet_allcalo_rho_isLoaded = false;
  evt_fixgridfastjet_central_rho_isLoaded = false;
  evt_fixgridfastjet_all_rho_isLoaded = false;
  evt_fixgridfastjet_centralcalo_rho_isLoaded = false;
  evt_fixgridfastjet_centralchargedpileup_rho_isLoaded = false;
  evt_fixgridfastjet_centralneutral_rho_isLoaded = false;
  evt_kfactor_isLoaded = false;
  evt_scale1fb_isLoaded = false;
  evt_xsec_excl_isLoaded = false;
  evt_xsec_incl_isLoaded = false;
  genps_alphaQCD_isLoaded = false;
  genps_pthat_isLoaded = false;
  genps_qScale_isLoaded = false;
  genps_weight_isLoaded = false;
  gen_sumEt_isLoaded = false;
  pdfinfo_pdf1_isLoaded = false;
  pdfinfo_pdf2_isLoaded = false;
  pdfinfo_scale_isLoaded = false;
  pdfinfo_x1_isLoaded = false;
  pdfinfo_x2_isLoaded = false;
  evt_calomet_isLoaded = false;
  evt_calometPhi_isLoaded = false;
  evt_pfmet_isLoaded = false;
  evt_pfmet_ElectronEnDown_isLoaded = false;
  evt_pfmet_ElectronEnUp_isLoaded = false;
  evt_pfmet_JetEnDown_isLoaded = false;
  evt_pfmet_JetEnUp_isLoaded = false;
  evt_pfmet_JetResDown_isLoaded = false;
  evt_pfmet_JetResUp_isLoaded = false;
  evt_pfmet_MuonEnDown_isLoaded = false;
  evt_pfmet_MuonEnUp_isLoaded = false;
  evt_pfmetPhi_isLoaded = false;
  evt_pfmetPhi_ElectronEnDown_isLoaded = false;
  evt_pfmetPhi_ElectronEnUp_isLoaded = false;
  evt_pfmetPhi_JetEnDown_isLoaded = false;
  evt_pfmetPhi_JetEnUp_isLoaded = false;
  evt_pfmetPhi_JetResDown_isLoaded = false;
  evt_pfmetPhi_JetResUp_isLoaded = false;
  evt_pfmetPhi_MuonEnDown_isLoaded = false;
  evt_pfmetPhi_MuonEnUp_isLoaded = false;
  evt_pfmetPhi_PhotonEnDown_isLoaded = false;
  evt_pfmetPhi_PhotonEnUp_isLoaded = false;
  evt_pfmetPhi_TauEnDown_isLoaded = false;
  evt_pfmetPhi_TauEnUp_isLoaded = false;
  evt_pfmetPhi_UnclusteredEnDown_isLoaded = false;
  evt_pfmetPhi_UnclusteredEnUp_isLoaded = false;
  evt_pfmetPhi_raw_isLoaded = false;
  evt_pfmet_PhotonEnDown_isLoaded = false;
  evt_pfmet_PhotonEnUp_isLoaded = false;
  evt_pfmetSig_isLoaded = false;
  evt_pfmetSignificance_isLoaded = false;
  evt_pfmet_TauEnDown_isLoaded = false;
  evt_pfmet_TauEnUp_isLoaded = false;
  evt_pfmet_UnclusteredEnDown_isLoaded = false;
  evt_pfmet_UnclusteredEnUp_isLoaded = false;
  evt_pfmet_raw_isLoaded = false;
  evt_pfsumet_isLoaded = false;
  evt_pfsumet_raw_isLoaded = false;
  gen_met_isLoaded = false;
  gen_metPhi_isLoaded = false;
  evt_puppi_calomet_isLoaded = false;
  evt_puppi_calometPhi_isLoaded = false;
  evt_puppi_pfmet_isLoaded = false;
  evt_puppi_pfmet_ElectronEnDown_isLoaded = false;
  evt_puppi_pfmet_ElectronEnUp_isLoaded = false;
  evt_puppi_pfmet_JetEnDown_isLoaded = false;
  evt_puppi_pfmet_JetEnUp_isLoaded = false;
  evt_puppi_pfmet_JetResDown_isLoaded = false;
  evt_puppi_pfmet_JetResUp_isLoaded = false;
  evt_puppi_pfmet_MuonEnDown_isLoaded = false;
  evt_puppi_pfmet_MuonEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_isLoaded = false;
  evt_puppi_pfmetPhi_ElectronEnDown_isLoaded = false;
  evt_puppi_pfmetPhi_ElectronEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_JetEnDown_isLoaded = false;
  evt_puppi_pfmetPhi_JetEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_JetResDown_isLoaded = false;
  evt_puppi_pfmetPhi_JetResUp_isLoaded = false;
  evt_puppi_pfmetPhi_MuonEnDown_isLoaded = false;
  evt_puppi_pfmetPhi_MuonEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_PhotonEnDown_isLoaded = false;
  evt_puppi_pfmetPhi_PhotonEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_TauEnDown_isLoaded = false;
  evt_puppi_pfmetPhi_TauEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_UnclusteredEnDown_isLoaded = false;
  evt_puppi_pfmetPhi_UnclusteredEnUp_isLoaded = false;
  evt_puppi_pfmetPhi_raw_isLoaded = false;
  evt_puppi_pfmet_PhotonEnDown_isLoaded = false;
  evt_puppi_pfmet_PhotonEnUp_isLoaded = false;
  evt_puppi_pfmetSig_isLoaded = false;
  evt_puppi_pfmetSignificance_isLoaded = false;
  evt_puppi_pfmet_TauEnDown_isLoaded = false;
  evt_puppi_pfmet_TauEnUp_isLoaded = false;
  evt_puppi_pfmet_UnclusteredEnDown_isLoaded = false;
  evt_puppi_pfmet_UnclusteredEnUp_isLoaded = false;
  evt_puppi_pfmet_raw_isLoaded = false;
  evt_puppi_pfsumet_isLoaded = false;
  evt_puppi_pfsumet_raw_isLoaded = false;
  els_mc_motherp4_isLoaded = false;
  els_mc_p4_isLoaded = false;
  mus_mc_motherp4_isLoaded = false;
  mus_mc_p4_isLoaded = false;
  pfjets_mc_p4_isLoaded = false;
  photons_mc_motherp4_isLoaded = false;
  photons_mc_p4_isLoaded = false;
  els_mc_patMatch_p4_isLoaded = false;
  els_p4_isLoaded = false;
  els_p4In_isLoaded = false;
  els_p4Out_isLoaded = false;
  els_trk_p4_isLoaded = false;
  els_trk_vertex_p4_isLoaded = false;
  els_vertex_p4_isLoaded = false;
  genjets_p4NoMuNoNu_isLoaded = false;
  genps_p4_isLoaded = false;
  hyp_ll_p4_isLoaded = false;
  hyp_lt_p4_isLoaded = false;
  hyp_p4_isLoaded = false;
  isotracks_p4_isLoaded = false;
  mus_bfit_p4_isLoaded = false;
  mus_gfit_p4_isLoaded = false;
  mus_mc_patMatch_p4_isLoaded = false;
  mus_p4_isLoaded = false;
  mus_pfp4_isLoaded = false;
  mus_trk_p4_isLoaded = false;
  pfcands_p4_isLoaded = false;
  pfjets_p4_isLoaded = false;
  pfjets_puppi_p4_isLoaded = false;
  taus_pf_p4_isLoaded = false;
  photons_p4_isLoaded = false;
  svs_p4_isLoaded = false;
  svs_position_isLoaded = false;
  ak8jets_p4_isLoaded = false;
  ak8jets_softdropPuppiSubjet1_isLoaded = false;
  ak8jets_softdropPuppiSubjet2_isLoaded = false;
  vtxs_position_isLoaded = false;
  genps_lepdaughter_p4_isLoaded = false;
  pfjets_pfcandmup4_isLoaded = false;
  pfjets_puppi_pfcandmup4_isLoaded = false;
  els_mc3dr_isLoaded = false;
  els_mcdr_isLoaded = false;
  mus_mc3dr_isLoaded = false;
  mus_mcdr_isLoaded = false;
  pfjets_mc3dr_isLoaded = false;
  pfjets_mcdr_isLoaded = false;
  photons_mc3dr_isLoaded = false;
  photons_mcdr_isLoaded = false;
  els_VIDNonTrigMvaValue_isLoaded = false;
  els_VIDSpring16GPMvaValue_isLoaded = false;
  els_VIDSpring16HZZMvaValue_isLoaded = false;
  els_VIDTrigMvaValue_isLoaded = false;
  els_chi2_isLoaded = false;
  els_ckf_chi2_isLoaded = false;
  els_ckf_ndof_isLoaded = false;
  els_conv_vtx_prob_isLoaded = false;
  els_d0Err_isLoaded = false;
  els_dEtaIn_isLoaded = false;
  els_dEtaOut_isLoaded = false;
  els_dPhiIn_isLoaded = false;
  els_dPhiOut_isLoaded = false;
  els_dxyPV_isLoaded = false;
  els_dzPV_isLoaded = false;
  els_e1x5_full5x5_isLoaded = false;
  els_e2x5Max_full5x5_isLoaded = false;
  els_e5x5_full5x5_isLoaded = false;
  els_eOverPIn_isLoaded = false;
  els_eOverPOut_isLoaded = false;
  els_eSC_isLoaded = false;
  els_eSCPresh_isLoaded = false;
  els_eSCRaw_isLoaded = false;
  els_eSeed_isLoaded = false;
  els_ecalEnergy_isLoaded = false;
  els_ecalEnergyError_isLoaded = false;
  els_ecalIso_isLoaded = false;
  els_ecalIso04_isLoaded = false;
  els_ecalPFClusterIso_isLoaded = false;
  els_etaSC_isLoaded = false;
  els_etaSCwidth_isLoaded = false;
  els_fbrem_isLoaded = false;
  els_full5x5_hOverE_isLoaded = false;
  els_hOverE_isLoaded = false;
  els_hcalDepth1TowerSumEt_isLoaded = false;
  els_hcalIso_isLoaded = false;
  els_hcalIso04_isLoaded = false;
  els_hcalPFClusterIso_isLoaded = false;
  els_ip2d_isLoaded = false;
  els_ip2derr_isLoaded = false;
  els_ip3d_isLoaded = false;
  els_ip3derr_isLoaded = false;
  els_mc_patMatch_dr_isLoaded = false;
  els_miniIso_ch_isLoaded = false;
  els_miniIso_db_isLoaded = false;
  els_miniIso_em_isLoaded = false;
  els_miniIso_nh_isLoaded = false;
  els_miniIso_uncor_isLoaded = false;
  els_ndof_isLoaded = false;
  els_pfChargedHadronIso_isLoaded = false;
  els_pfNeutralHadronIso_isLoaded = false;
  els_pfPUIso_isLoaded = false;
  els_pfPhotonIso_isLoaded = false;
  els_phiSC_isLoaded = false;
  els_phiSCwidth_isLoaded = false;
  els_ptErr_isLoaded = false;
  els_ptErrGsf_isLoaded = false;
  els_r9_isLoaded = false;
  els_r9_full5x5_isLoaded = false;
  els_scSeedEta_isLoaded = false;
  els_sigmaEtaEta_full5x5_isLoaded = false;
  els_sigmaIEtaIEta_isLoaded = false;
  els_sigmaIEtaIEta_full5x5_isLoaded = false;
  els_sigmaIPhiIPhi_isLoaded = false;
  els_sigmaIPhiIPhi_full5x5_isLoaded = false;
  els_tkIso_isLoaded = false;
  els_tkIso04_isLoaded = false;
  els_trackMomentumError_isLoaded = false;
  els_trkdr_isLoaded = false;
  els_trkshFrac_isLoaded = false;
  els_z0Err_isLoaded = false;
  genps_charge_isLoaded = false;
  genps_iso_isLoaded = false;
  genweights_isLoaded = false;
  isotracks_dEdxPixel_isLoaded = false;
  isotracks_dEdxStrip_isLoaded = false;
  isotracks_deltaEta_isLoaded = false;
  isotracks_deltaPhi_isLoaded = false;
  isotracks_dxy_isLoaded = false;
  isotracks_dxyError_isLoaded = false;
  isotracks_dz_isLoaded = false;
  isotracks_dzError_isLoaded = false;
  isotracks_matchedCaloJetEmEnergy_isLoaded = false;
  isotracks_matchedCaloJetHadEnergy_isLoaded = false;
  isotracks_miniIso_ch_isLoaded = false;
  isotracks_miniIso_db_isLoaded = false;
  isotracks_miniIso_em_isLoaded = false;
  isotracks_miniIso_nh_isLoaded = false;
  isotracks_pfIso_ch_isLoaded = false;
  isotracks_pfIso_db_isLoaded = false;
  isotracks_pfIso_em_isLoaded = false;
  isotracks_pfIso_nh_isLoaded = false;
  mus_bfit_ptErr_isLoaded = false;
  mus_caloCompatibility_isLoaded = false;
  mus_chi2LocalMomentum_isLoaded = false;
  mus_chi2LocalPosition_isLoaded = false;
  mus_d0Err_isLoaded = false;
  mus_dxyPV_isLoaded = false;
  mus_dzPV_isLoaded = false;
  mus_ecal_time_isLoaded = false;
  mus_gfit_chi2_isLoaded = false;
  mus_gfit_ptErr_isLoaded = false;
  mus_hcal_time_isLoaded = false;
  mus_ip2d_isLoaded = false;
  mus_ip2derr_isLoaded = false;
  mus_ip3d_isLoaded = false;
  mus_ip3derr_isLoaded = false;
  mus_iso03_emEt_isLoaded = false;
  mus_iso03_hadEt_isLoaded = false;
  mus_iso03_sumPt_isLoaded = false;
  mus_isoR03_pf_ChargedHadronPt_isLoaded = false;
  mus_isoR03_pf_ChargedParticlePt_isLoaded = false;
  mus_isoR03_pf_NeutralHadronEt_isLoaded = false;
  mus_isoR03_pf_NeutralHadronEtHighThreshold_isLoaded = false;
  mus_isoR03_pf_PUPt_isLoaded = false;
  mus_isoR03_pf_PhotonEt_isLoaded = false;
  mus_isoR03_pf_PhotonEtHighThreshold_isLoaded = false;
  mus_isoR04_pf_ChargedHadronPt_isLoaded = false;
  mus_isoR04_pf_ChargedParticlePt_isLoaded = false;
  mus_isoR04_pf_NeutralHadronEt_isLoaded = false;
  mus_isoR04_pf_NeutralHadronEtHighThreshold_isLoaded = false;
  mus_isoR04_pf_PUPt_isLoaded = false;
  mus_isoR04_pf_PhotonEt_isLoaded = false;
  mus_isoR04_pf_PhotonEtHighThreshold_isLoaded = false;
  mus_iso_ecalvetoDep_isLoaded = false;
  mus_iso_hcalvetoDep_isLoaded = false;
  mus_iso_hovetoDep_isLoaded = false;
  mus_iso_trckvetoDep_isLoaded = false;
  mus_mc_patMatch_dr_isLoaded = false;
  mus_miniIso_ch_isLoaded = false;
  mus_miniIso_db_isLoaded = false;
  mus_miniIso_em_isLoaded = false;
  mus_miniIso_nh_isLoaded = false;
  mus_miniIso_uncor_isLoaded = false;
  mus_ptErr_isLoaded = false;
  mus_segmCompatibility_isLoaded = false;
  mus_trkKink_isLoaded = false;
  mus_z0Err_isLoaded = false;
  pfcands_dxy_isLoaded = false;
  pfcands_dxyError_isLoaded = false;
  pfcands_dz_isLoaded = false;
  pfcands_dzAssociatedPV_isLoaded = false;
  pfcands_dzError_isLoaded = false;
  pfcands_mass_isLoaded = false;
  pfcands_miniTrackIso_isLoaded = false;
  pfcands_puppiWeight_isLoaded = false;
  pfcands_puppiWeightNoLep_isLoaded = false;
  pfcands_trackIso_isLoaded = false;
  pfjets_area_isLoaded = false;
  pfjets_axis1_isLoaded = false;
  pfjets_chargedEmE_isLoaded = false;
  pfjets_chargedHadronE_isLoaded = false;
  pfjets_electronE_isLoaded = false;
  pfjets_hfEmE_isLoaded = false;
  pfjets_hfHadronE_isLoaded = false;
  pfjets_muonE_isLoaded = false;
  pfjets_neutralEmE_isLoaded = false;
  pfjets_neutralHadronE_isLoaded = false;
  pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded = false;
  pfjets_pfDeepCSVJetTagsprobbPlusprobbb_isLoaded = false;
  pfjets_photonE_isLoaded = false;
  pfjets_pileupJetId_isLoaded = false;
  pfjets_ptDistribution_isLoaded = false;
  pfjets_undoJEC_isLoaded = false;
  pfjets_puppi_area_isLoaded = false;
  pfjets_puppi_axis1_isLoaded = false;
  pfjets_puppi_chargedEmE_isLoaded = false;
  pfjets_puppi_chargedHadronE_isLoaded = false;
  pfjets_puppi_electronE_isLoaded = false;
  pfjets_puppi_hfEmE_isLoaded = false;
  pfjets_puppi_hfHadronE_isLoaded = false;
  pfjets_puppi_muonE_isLoaded = false;
  pfjets_puppi_neutralEmE_isLoaded = false;
  pfjets_puppi_neutralHadronE_isLoaded = false;
  pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded = false;
  pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_isLoaded = false;
  pfjets_puppi_photonE_isLoaded = false;
  pfjets_puppi_pileupJetId_isLoaded = false;
  pfjets_puppi_ptDistribution_isLoaded = false;
  pfjets_puppi_undoJEC_isLoaded = false;
  photons_ecalPFClusterIso_isLoaded = false;
  photons_full5x5_hOverE_isLoaded = false;
  photons_full5x5_hOverEtowBC_isLoaded = false;
  photons_full5x5_r9_isLoaded = false;
  photons_full5x5_sigmaIEtaIEta_isLoaded = false;
  photons_hOverE_isLoaded = false;
  photons_hOverEtowBC_isLoaded = false;
  photons_hcalPFClusterIso_isLoaded = false;
  photons_ntkIsoHollow03_isLoaded = false;
  photons_recoChargedHadronIso_isLoaded = false;
  photons_recoNeutralHadronIso_isLoaded = false;
  photons_recoPhotonIso_isLoaded = false;
  photons_sigmaIEtaIEta_isLoaded = false;
  photons_tkIsoHollow03_isLoaded = false;
  puInfo_trueNumInteractions_isLoaded = false;
  svs_anglePV_isLoaded = false;
  svs_chi2_isLoaded = false;
  svs_dist3Dsig_isLoaded = false;
  svs_dist3Dval_isLoaded = false;
  svs_distXYsig_isLoaded = false;
  svs_distXYval_isLoaded = false;
  svs_ndof_isLoaded = false;
  svs_prob_isLoaded = false;
  svs_xError_isLoaded = false;
  svs_yError_isLoaded = false;
  svs_zError_isLoaded = false;
  ak8jets_area_isLoaded = false;
  ak8jets_mass_isLoaded = false;
  ak8jets_nJettinessTau1_isLoaded = false;
  ak8jets_nJettinessTau2_isLoaded = false;
  ak8jets_nJettinessTau3_isLoaded = false;
  ak8jets_prunedMass_isLoaded = false;
  ak8jets_puppi_eta_isLoaded = false;
  ak8jets_puppi_mass_isLoaded = false;
  ak8jets_puppi_nJettinessTau1_isLoaded = false;
  ak8jets_puppi_nJettinessTau2_isLoaded = false;
  ak8jets_puppi_nJettinessTau3_isLoaded = false;
  ak8jets_puppi_phi_isLoaded = false;
  ak8jets_puppi_pt_isLoaded = false;
  ak8jets_puppi_softdropMass_isLoaded = false;
  ak8jets_softdropMass_isLoaded = false;
  ak8jets_undoJEC_isLoaded = false;
  vtxs_ndof_isLoaded = false;
  pfjets_bDiscriminators_isLoaded = false;
  pfjets_puppi_bDiscriminators_isLoaded = false;
  taus_pf_IDs_isLoaded = false;
  puInfo_instLumi_isLoaded = false;
  evt_bunchCrossing_isLoaded = false;
  evt_experimentType_isLoaded = false;
  evt_isRealData_isLoaded = false;
  evt_orbitNumber_isLoaded = false;
  evt_storeNumber_isLoaded = false;
  pdfinfo_id1_isLoaded = false;
  pdfinfo_id2_isLoaded = false;
  els_mc3_id_isLoaded = false;
  els_mc3idx_isLoaded = false;
  els_mc3_motherid_isLoaded = false;
  els_mc3_motheridx_isLoaded = false;
  els_mc_id_isLoaded = false;
  els_mc_motherid_isLoaded = false;
  mus_mc3_id_isLoaded = false;
  mus_mc3idx_isLoaded = false;
  mus_mc3_motherid_isLoaded = false;
  mus_mc3_motheridx_isLoaded = false;
  mus_mc_id_isLoaded = false;
  mus_mc_motherid_isLoaded = false;
  pfjets_mc3_id_isLoaded = false;
  pfjets_mc3idx_isLoaded = false;
  pfjets_mc_motherid_isLoaded = false;
  photons_mc3_id_isLoaded = false;
  photons_mc3idx_isLoaded = false;
  photons_mc3_motherid_isLoaded = false;
  photons_mc3_motheridx_isLoaded = false;
  photons_mc_id_isLoaded = false;
  photons_mc_motherid_isLoaded = false;
  els_VIDNonTrigMvaCat_isLoaded = false;
  els_VIDSpring16GPMvaCat_isLoaded = false;
  els_VIDSpring16HZZMvaCat_isLoaded = false;
  els_VIDTrigMvaCat_isLoaded = false;
  els_category_isLoaded = false;
  els_charge_isLoaded = false;
  els_ckf_charge_isLoaded = false;
  els_ckf_laywithmeas_isLoaded = false;
  els_exp_innerlayers_isLoaded = false;
  els_exp_outerlayers_isLoaded = false;
  els_isEB_isLoaded = false;
  els_isEcalDriven_isLoaded = false;
  els_isTrackerDriven_isLoaded = false;
  els_lostHits_isLoaded = false;
  els_lost_pixelhits_isLoaded = false;
  els_mc_patMatch_id_isLoaded = false;
  els_nlayers_isLoaded = false;
  els_nlayers3D_isLoaded = false;
  els_nlayersLost_isLoaded = false;
  els_sccharge_isLoaded = false;
  els_trk_charge_isLoaded = false;
  els_type_isLoaded = false;
  els_validHits_isLoaded = false;
  els_valid_pixelhits_isLoaded = false;
  els_passVIDNonTrigMvaWP80Id_isLoaded = false;
  els_passVIDNonTrigMvaWP90Id_isLoaded = false;
  els_passVIDTrigMvaWP80Id_isLoaded = false;
  els_passVIDTrigMvaWP90Id_isLoaded = false;
  genps_id_isLoaded = false;
  genps_id_mother_isLoaded = false;
  genps_id_simplegrandma_isLoaded = false;
  genps_id_simplemother_isLoaded = false;
  genps_idx_mother_isLoaded = false;
  genps_idx_simplemother_isLoaded = false;
  genps_status_isLoaded = false;
  hyp_ll_charge_isLoaded = false;
  hyp_ll_id_isLoaded = false;
  hyp_ll_index_isLoaded = false;
  hyp_lt_charge_isLoaded = false;
  hyp_lt_id_isLoaded = false;
  hyp_lt_index_isLoaded = false;
  hyp_type_isLoaded = false;
  isotracks_charge_isLoaded = false;
  isotracks_fromPV_isLoaded = false;
  isotracks_numberOfLostHitsInner_isLoaded = false;
  isotracks_numberOfLostHitsOuter_isLoaded = false;
  isotracks_numberOfLostPixelHitsInner_isLoaded = false;
  isotracks_numberOfValidPixelHits_isLoaded = false;
  isotracks_particleId_isLoaded = false;
  isotracks_pixelLayersWithMeasurement_isLoaded = false;
  isotracks_trackerLayersWithMeasurement_isLoaded = false;
  mus_algo_isLoaded = false;
  mus_algoOrig_isLoaded = false;
  mus_bfit_algo_isLoaded = false;
  mus_charge_isLoaded = false;
  mus_exp_innerlayers_isLoaded = false;
  mus_exp_outerlayers_isLoaded = false;
  mus_gfit_algo_isLoaded = false;
  mus_gfit_ndof_isLoaded = false;
  mus_gfit_validSTAHits_isLoaded = false;
  mus_iso03_ntrk_isLoaded = false;
  mus_lostHits_isLoaded = false;
  mus_mc_patMatch_id_isLoaded = false;
  mus_nlayers_isLoaded = false;
  mus_numberOfMatchedStations_isLoaded = false;
  mus_pfcharge_isLoaded = false;
  mus_pfidx_isLoaded = false;
  mus_pfparticleId_isLoaded = false;
  mus_pid_PFMuon_isLoaded = false;
  mus_pid_TM2DCompatibilityLoose_isLoaded = false;
  mus_pid_TM2DCompatibilityTight_isLoaded = false;
  mus_pid_TMLastStationLoose_isLoaded = false;
  mus_pid_TMLastStationTight_isLoaded = false;
  mus_pid_TMOneStationTight_isLoaded = false;
  mus_type_isLoaded = false;
  mus_validHits_isLoaded = false;
  mus_validPixelHits_isLoaded = false;
  pfcands_IdAssociatedPV_isLoaded = false;
  pfcands_charge_isLoaded = false;
  pfcands_numberOfHits_isLoaded = false;
  pfcands_numberOfPixelHits_isLoaded = false;
  pfcands_particleId_isLoaded = false;
  pfcands_pixelLayersWithMeasurement_isLoaded = false;
  pfcands_stripLayersWithMeasurement_isLoaded = false;
  pfjets_chargedHadronMultiplicity_isLoaded = false;
  pfjets_chargedMultiplicity_isLoaded = false;
  pfjets_electronMultiplicity_isLoaded = false;
  pfjets_hadronFlavour_isLoaded = false;
  pfjets_muonMultiplicity_isLoaded = false;
  pfjets_neutralHadronMultiplicity_isLoaded = false;
  pfjets_neutralMultiplicity_isLoaded = false;
  pfjets_npfcands_isLoaded = false;
  pfjets_partonFlavour_isLoaded = false;
  pfjets_photonMultiplicity_isLoaded = false;
  pfjets_totalMultiplicity_isLoaded = false;
  pfjets_puppi_chargedHadronMultiplicity_isLoaded = false;
  pfjets_puppi_chargedMultiplicity_isLoaded = false;
  pfjets_puppi_electronMultiplicity_isLoaded = false;
  pfjets_puppi_hadronFlavour_isLoaded = false;
  pfjets_puppi_muonMultiplicity_isLoaded = false;
  pfjets_puppi_neutralHadronMultiplicity_isLoaded = false;
  pfjets_puppi_neutralMultiplicity_isLoaded = false;
  pfjets_puppi_npfcands_isLoaded = false;
  pfjets_puppi_partonFlavour_isLoaded = false;
  pfjets_puppi_photonMultiplicity_isLoaded = false;
  pfjets_puppi_totalMultiplicity_isLoaded = false;
  taus_pf_charge_isLoaded = false;
  photons_photonID_loose_isLoaded = false;
  photons_photonID_tight_isLoaded = false;
  puInfo_bunchCrossing_isLoaded = false;
  puInfo_nPUvertices_isLoaded = false;
  svs_nTrks_isLoaded = false;
  _npfcands_isLoaded = false;
  ak8jets_partonFlavour_isLoaded = false;
  vtxs_isFake_isLoaded = false;
  vtxs_isValid_isLoaded = false;
  genps_lepdaughter_id_isLoaded = false;
  genps_lepdaughter_idx_isLoaded = false;
  photons_PFCand_idx_isLoaded = false;
  pfcands_fromPV_isLoaded = false;
  pfcands_normalizedChi2_isLoaded = false;
  pfcands_packedHits_isLoaded = false;
  pfcands_packedLayers_isLoaded = false;
  pfcands_pvAssociationQuality_isLoaded = false;
  evt_nels_isLoaded = false;
  evt_detectorStatus_isLoaded = false;
  evt_lumiBlock_isLoaded = false;
  evt_run_isLoaded = false;
  evt_ngenjetsNoMuNoNu_isLoaded = false;
  genps_signalProcessID_isLoaded = false;
  evt_nphotons_isLoaded = false;
  evt_nvtxs_isLoaded = false;
  hlt_l1prescales_isLoaded = false;
  hlt_prescales_isLoaded = false;
  isotracks_crossedHcalStatus_isLoaded = false;
  evt_event_isLoaded = false;
  evt_timestamp_isLoaded = false;
}

void CMS3::LoadAllBranches() {
  // load all branches
  if (genweightsID_branch != 0) genweightsID();
  if (hlt_bits_branch != 0) hlt_bits();
  if (evt_CMS3tag_branch != 0) evt_CMS3tag();
  if (evt_dataset_branch != 0) evt_dataset();
  if (hlt_trigNames_branch != 0) hlt_trigNames();
  if (pfjets_bDiscriminatorNames_branch != 0) pfjets_bDiscriminatorNames();
  if (pfjets_puppi_bDiscriminatorNames_branch != 0) pfjets_puppi_bDiscriminatorNames();
  if (taus_pf_IDnames_branch != 0) taus_pf_IDnames();
  if (evt_cscTightHaloId_branch != 0) evt_cscTightHaloId();
  if (evt_hbheFilter_branch != 0) evt_hbheFilter();
  if (filt_chargedHadronTrackResolution_branch != 0) filt_chargedHadronTrackResolution();
  if (filt_cscBeamHalo_branch != 0) filt_cscBeamHalo();
  if (filt_cscBeamHalo2015_branch != 0) filt_cscBeamHalo2015();
  if (filt_cscBeamHaloTrkMuUnveto_branch != 0) filt_cscBeamHaloTrkMuUnveto();
  if (filt_ecalBoundaryEnergy_branch != 0) filt_ecalBoundaryEnergy();
  if (filt_ecalLaser_branch != 0) filt_ecalLaser();
  if (filt_ecalTP_branch != 0) filt_ecalTP();
  if (filt_eeBadSc_branch != 0) filt_eeBadSc();
  if (filt_globalSuperTightHalo2016_branch != 0) filt_globalSuperTightHalo2016();
  if (filt_globalTightHalo2016_branch != 0) filt_globalTightHalo2016();
  if (filt_goodVertices_branch != 0) filt_goodVertices();
  if (filt_hbheNoise_branch != 0) filt_hbheNoise();
  if (filt_hbheNoiseIso_branch != 0) filt_hbheNoiseIso();
  if (filt_hcalLaser_branch != 0) filt_hcalLaser();
  if (filt_hcalStrip_branch != 0) filt_hcalStrip();
  if (filt_metfilter_branch != 0) filt_metfilter();
  if (filt_muonBadTrack_branch != 0) filt_muonBadTrack();
  if (filt_trackingFailure_branch != 0) filt_trackingFailure();
  if (filt_trkPOGFilters_branch != 0) filt_trkPOGFilters();
  if (filt_trkPOG_logErrorTooManyClusters_branch != 0) filt_trkPOG_logErrorTooManyClusters();
  if (filt_trkPOG_manystripclus53X_branch != 0) filt_trkPOG_manystripclus53X();
  if (filt_trkPOG_toomanystripclus53X_branch != 0) filt_trkPOG_toomanystripclus53X();
  if (els_conv_vtx_flag_branch != 0) els_conv_vtx_flag();
  if (els_isGsfCtfScPixChargeConsistent_branch != 0) els_isGsfCtfScPixChargeConsistent();
  if (genps_fromHardProcessBeforeFSR_branch != 0) genps_fromHardProcessBeforeFSR();
  if (genps_fromHardProcessDecayed_branch != 0) genps_fromHardProcessDecayed();
  if (genps_fromHardProcessFinalState_branch != 0) genps_fromHardProcessFinalState();
  if (genps_isDirectHardProcessTauDecayProductFinalState_branch != 0) genps_isDirectHardProcessTauDecayProductFinalState();
  if (genps_isDirectPromptTauDecayProductFinalState_branch != 0) genps_isDirectPromptTauDecayProductFinalState();
  if (genps_isHardProcess_branch != 0) genps_isHardProcess();
  if (genps_isLastCopy_branch != 0) genps_isLastCopy();
  if (genps_isLastCopyBeforeFSR_branch != 0) genps_isLastCopyBeforeFSR();
  if (genps_isMostlyLikePythia6Status3_branch != 0) genps_isMostlyLikePythia6Status3();
  if (genps_isPromptDecayed_branch != 0) genps_isPromptDecayed();
  if (genps_isPromptFinalState_branch != 0) genps_isPromptFinalState();
  if (isotracks_isHighPurityTrack_branch != 0) isotracks_isHighPurityTrack();
  if (isotracks_isPFCand_branch != 0) isotracks_isPFCand();
  if (isotracks_isTightTrack_branch != 0) isotracks_isTightTrack();
  if (pfcands_isGlobalMuon_branch != 0) pfcands_isGlobalMuon();
  if (pfcands_isStandAloneMuon_branch != 0) pfcands_isStandAloneMuon();
  if (pfcands_trackHighPurity_branch != 0) pfcands_trackHighPurity();
  if (photons_haspixelSeed_branch != 0) photons_haspixelSeed();
  if (photons_passElectronVeto_branch != 0) photons_passElectronVeto();
  if (evt_bField_branch != 0) evt_bField();
  if (evt_instantLumi_branch != 0) evt_instantLumi();
  if (evt_instantLumiErr_branch != 0) evt_instantLumiErr();
  if (evt_lumiFill_branch != 0) evt_lumiFill();
  if (evt_lumiRun_branch != 0) evt_lumiRun();
  if (evt_pileup_branch != 0) evt_pileup();
  if (evt_pileupRMS_branch != 0) evt_pileupRMS();
  if (evt_fixgrid_all_rho_branch != 0) evt_fixgrid_all_rho();
  if (evt_fixgridfastjet_allcalo_rho_branch != 0) evt_fixgridfastjet_allcalo_rho();
  if (evt_fixgridfastjet_central_rho_branch != 0) evt_fixgridfastjet_central_rho();
  if (evt_fixgridfastjet_all_rho_branch != 0) evt_fixgridfastjet_all_rho();
  if (evt_fixgridfastjet_centralcalo_rho_branch != 0) evt_fixgridfastjet_centralcalo_rho();
  if (evt_fixgridfastjet_centralchargedpileup_rho_branch != 0) evt_fixgridfastjet_centralchargedpileup_rho();
  if (evt_fixgridfastjet_centralneutral_rho_branch != 0) evt_fixgridfastjet_centralneutral_rho();
  if (evt_kfactor_branch != 0) evt_kfactor();
  if (evt_scale1fb_branch != 0) evt_scale1fb();
  if (evt_xsec_excl_branch != 0) evt_xsec_excl();
  if (evt_xsec_incl_branch != 0) evt_xsec_incl();
  if (genps_alphaQCD_branch != 0) genps_alphaQCD();
  if (genps_pthat_branch != 0) genps_pthat();
  if (genps_qScale_branch != 0) genps_qScale();
  if (genps_weight_branch != 0) genps_weight();
  if (gen_sumEt_branch != 0) gen_sumEt();
  if (pdfinfo_pdf1_branch != 0) pdfinfo_pdf1();
  if (pdfinfo_pdf2_branch != 0) pdfinfo_pdf2();
  if (pdfinfo_scale_branch != 0) pdfinfo_scale();
  if (pdfinfo_x1_branch != 0) pdfinfo_x1();
  if (pdfinfo_x2_branch != 0) pdfinfo_x2();
  if (evt_calomet_branch != 0) evt_calomet();
  if (evt_calometPhi_branch != 0) evt_calometPhi();
  if (evt_pfmet_branch != 0) evt_pfmet();
  if (evt_pfmet_ElectronEnDown_branch != 0) evt_pfmet_ElectronEnDown();
  if (evt_pfmet_ElectronEnUp_branch != 0) evt_pfmet_ElectronEnUp();
  if (evt_pfmet_JetEnDown_branch != 0) evt_pfmet_JetEnDown();
  if (evt_pfmet_JetEnUp_branch != 0) evt_pfmet_JetEnUp();
  if (evt_pfmet_JetResDown_branch != 0) evt_pfmet_JetResDown();
  if (evt_pfmet_JetResUp_branch != 0) evt_pfmet_JetResUp();
  if (evt_pfmet_MuonEnDown_branch != 0) evt_pfmet_MuonEnDown();
  if (evt_pfmet_MuonEnUp_branch != 0) evt_pfmet_MuonEnUp();
  if (evt_pfmetPhi_branch != 0) evt_pfmetPhi();
  if (evt_pfmetPhi_ElectronEnDown_branch != 0) evt_pfmetPhi_ElectronEnDown();
  if (evt_pfmetPhi_ElectronEnUp_branch != 0) evt_pfmetPhi_ElectronEnUp();
  if (evt_pfmetPhi_JetEnDown_branch != 0) evt_pfmetPhi_JetEnDown();
  if (evt_pfmetPhi_JetEnUp_branch != 0) evt_pfmetPhi_JetEnUp();
  if (evt_pfmetPhi_JetResDown_branch != 0) evt_pfmetPhi_JetResDown();
  if (evt_pfmetPhi_JetResUp_branch != 0) evt_pfmetPhi_JetResUp();
  if (evt_pfmetPhi_MuonEnDown_branch != 0) evt_pfmetPhi_MuonEnDown();
  if (evt_pfmetPhi_MuonEnUp_branch != 0) evt_pfmetPhi_MuonEnUp();
  if (evt_pfmetPhi_PhotonEnDown_branch != 0) evt_pfmetPhi_PhotonEnDown();
  if (evt_pfmetPhi_PhotonEnUp_branch != 0) evt_pfmetPhi_PhotonEnUp();
  if (evt_pfmetPhi_TauEnDown_branch != 0) evt_pfmetPhi_TauEnDown();
  if (evt_pfmetPhi_TauEnUp_branch != 0) evt_pfmetPhi_TauEnUp();
  if (evt_pfmetPhi_UnclusteredEnDown_branch != 0) evt_pfmetPhi_UnclusteredEnDown();
  if (evt_pfmetPhi_UnclusteredEnUp_branch != 0) evt_pfmetPhi_UnclusteredEnUp();
  if (evt_pfmetPhi_raw_branch != 0) evt_pfmetPhi_raw();
  if (evt_pfmet_PhotonEnDown_branch != 0) evt_pfmet_PhotonEnDown();
  if (evt_pfmet_PhotonEnUp_branch != 0) evt_pfmet_PhotonEnUp();
  if (evt_pfmetSig_branch != 0) evt_pfmetSig();
  if (evt_pfmetSignificance_branch != 0) evt_pfmetSignificance();
  if (evt_pfmet_TauEnDown_branch != 0) evt_pfmet_TauEnDown();
  if (evt_pfmet_TauEnUp_branch != 0) evt_pfmet_TauEnUp();
  if (evt_pfmet_UnclusteredEnDown_branch != 0) evt_pfmet_UnclusteredEnDown();
  if (evt_pfmet_UnclusteredEnUp_branch != 0) evt_pfmet_UnclusteredEnUp();
  if (evt_pfmet_raw_branch != 0) evt_pfmet_raw();
  if (evt_pfsumet_branch != 0) evt_pfsumet();
  if (evt_pfsumet_raw_branch != 0) evt_pfsumet_raw();
  if (gen_met_branch != 0) gen_met();
  if (gen_metPhi_branch != 0) gen_metPhi();
  if (evt_puppi_calomet_branch != 0) evt_puppi_calomet();
  if (evt_puppi_calometPhi_branch != 0) evt_puppi_calometPhi();
  if (evt_puppi_pfmet_branch != 0) evt_puppi_pfmet();
  if (evt_puppi_pfmet_ElectronEnDown_branch != 0) evt_puppi_pfmet_ElectronEnDown();
  if (evt_puppi_pfmet_ElectronEnUp_branch != 0) evt_puppi_pfmet_ElectronEnUp();
  if (evt_puppi_pfmet_JetEnDown_branch != 0) evt_puppi_pfmet_JetEnDown();
  if (evt_puppi_pfmet_JetEnUp_branch != 0) evt_puppi_pfmet_JetEnUp();
  if (evt_puppi_pfmet_JetResDown_branch != 0) evt_puppi_pfmet_JetResDown();
  if (evt_puppi_pfmet_JetResUp_branch != 0) evt_puppi_pfmet_JetResUp();
  if (evt_puppi_pfmet_MuonEnDown_branch != 0) evt_puppi_pfmet_MuonEnDown();
  if (evt_puppi_pfmet_MuonEnUp_branch != 0) evt_puppi_pfmet_MuonEnUp();
  if (evt_puppi_pfmetPhi_branch != 0) evt_puppi_pfmetPhi();
  if (evt_puppi_pfmetPhi_ElectronEnDown_branch != 0) evt_puppi_pfmetPhi_ElectronEnDown();
  if (evt_puppi_pfmetPhi_ElectronEnUp_branch != 0) evt_puppi_pfmetPhi_ElectronEnUp();
  if (evt_puppi_pfmetPhi_JetEnDown_branch != 0) evt_puppi_pfmetPhi_JetEnDown();
  if (evt_puppi_pfmetPhi_JetEnUp_branch != 0) evt_puppi_pfmetPhi_JetEnUp();
  if (evt_puppi_pfmetPhi_JetResDown_branch != 0) evt_puppi_pfmetPhi_JetResDown();
  if (evt_puppi_pfmetPhi_JetResUp_branch != 0) evt_puppi_pfmetPhi_JetResUp();
  if (evt_puppi_pfmetPhi_MuonEnDown_branch != 0) evt_puppi_pfmetPhi_MuonEnDown();
  if (evt_puppi_pfmetPhi_MuonEnUp_branch != 0) evt_puppi_pfmetPhi_MuonEnUp();
  if (evt_puppi_pfmetPhi_PhotonEnDown_branch != 0) evt_puppi_pfmetPhi_PhotonEnDown();
  if (evt_puppi_pfmetPhi_PhotonEnUp_branch != 0) evt_puppi_pfmetPhi_PhotonEnUp();
  if (evt_puppi_pfmetPhi_TauEnDown_branch != 0) evt_puppi_pfmetPhi_TauEnDown();
  if (evt_puppi_pfmetPhi_TauEnUp_branch != 0) evt_puppi_pfmetPhi_TauEnUp();
  if (evt_puppi_pfmetPhi_UnclusteredEnDown_branch != 0) evt_puppi_pfmetPhi_UnclusteredEnDown();
  if (evt_puppi_pfmetPhi_UnclusteredEnUp_branch != 0) evt_puppi_pfmetPhi_UnclusteredEnUp();
  if (evt_puppi_pfmetPhi_raw_branch != 0) evt_puppi_pfmetPhi_raw();
  if (evt_puppi_pfmet_PhotonEnDown_branch != 0) evt_puppi_pfmet_PhotonEnDown();
  if (evt_puppi_pfmet_PhotonEnUp_branch != 0) evt_puppi_pfmet_PhotonEnUp();
  if (evt_puppi_pfmetSig_branch != 0) evt_puppi_pfmetSig();
  if (evt_puppi_pfmetSignificance_branch != 0) evt_puppi_pfmetSignificance();
  if (evt_puppi_pfmet_TauEnDown_branch != 0) evt_puppi_pfmet_TauEnDown();
  if (evt_puppi_pfmet_TauEnUp_branch != 0) evt_puppi_pfmet_TauEnUp();
  if (evt_puppi_pfmet_UnclusteredEnDown_branch != 0) evt_puppi_pfmet_UnclusteredEnDown();
  if (evt_puppi_pfmet_UnclusteredEnUp_branch != 0) evt_puppi_pfmet_UnclusteredEnUp();
  if (evt_puppi_pfmet_raw_branch != 0) evt_puppi_pfmet_raw();
  if (evt_puppi_pfsumet_branch != 0) evt_puppi_pfsumet();
  if (evt_puppi_pfsumet_raw_branch != 0) evt_puppi_pfsumet_raw();
  if (els_mc_motherp4_branch != 0) els_mc_motherp4();
  if (els_mc_p4_branch != 0) els_mc_p4();
  if (mus_mc_motherp4_branch != 0) mus_mc_motherp4();
  if (mus_mc_p4_branch != 0) mus_mc_p4();
  if (pfjets_mc_p4_branch != 0) pfjets_mc_p4();
  if (photons_mc_motherp4_branch != 0) photons_mc_motherp4();
  if (photons_mc_p4_branch != 0) photons_mc_p4();
  if (els_mc_patMatch_p4_branch != 0) els_mc_patMatch_p4();
  if (els_p4_branch != 0) els_p4();
  if (els_p4In_branch != 0) els_p4In();
  if (els_p4Out_branch != 0) els_p4Out();
  if (els_trk_p4_branch != 0) els_trk_p4();
  if (els_trk_vertex_p4_branch != 0) els_trk_vertex_p4();
  if (els_vertex_p4_branch != 0) els_vertex_p4();
  if (genjets_p4NoMuNoNu_branch != 0) genjets_p4NoMuNoNu();
  if (genps_p4_branch != 0) genps_p4();
  if (hyp_ll_p4_branch != 0) hyp_ll_p4();
  if (hyp_lt_p4_branch != 0) hyp_lt_p4();
  if (hyp_p4_branch != 0) hyp_p4();
  if (isotracks_p4_branch != 0) isotracks_p4();
  if (mus_bfit_p4_branch != 0) mus_bfit_p4();
  if (mus_gfit_p4_branch != 0) mus_gfit_p4();
  if (mus_mc_patMatch_p4_branch != 0) mus_mc_patMatch_p4();
  if (mus_p4_branch != 0) mus_p4();
  if (mus_pfp4_branch != 0) mus_pfp4();
  if (mus_trk_p4_branch != 0) mus_trk_p4();
  if (pfcands_p4_branch != 0) pfcands_p4();
  if (pfjets_p4_branch != 0) pfjets_p4();
  if (pfjets_puppi_p4_branch != 0) pfjets_puppi_p4();
  if (taus_pf_p4_branch != 0) taus_pf_p4();
  if (photons_p4_branch != 0) photons_p4();
  if (svs_p4_branch != 0) svs_p4();
  if (svs_position_branch != 0) svs_position();
  if (ak8jets_p4_branch != 0) ak8jets_p4();
  if (ak8jets_softdropPuppiSubjet1_branch != 0) ak8jets_softdropPuppiSubjet1();
  if (ak8jets_softdropPuppiSubjet2_branch != 0) ak8jets_softdropPuppiSubjet2();
  if (vtxs_position_branch != 0) vtxs_position();
  if (genps_lepdaughter_p4_branch != 0) genps_lepdaughter_p4();
  if (pfjets_pfcandmup4_branch != 0) pfjets_pfcandmup4();
  if (pfjets_puppi_pfcandmup4_branch != 0) pfjets_puppi_pfcandmup4();
  if (els_mc3dr_branch != 0) els_mc3dr();
  if (els_mcdr_branch != 0) els_mcdr();
  if (mus_mc3dr_branch != 0) mus_mc3dr();
  if (mus_mcdr_branch != 0) mus_mcdr();
  if (pfjets_mc3dr_branch != 0) pfjets_mc3dr();
  if (pfjets_mcdr_branch != 0) pfjets_mcdr();
  if (photons_mc3dr_branch != 0) photons_mc3dr();
  if (photons_mcdr_branch != 0) photons_mcdr();
  if (els_VIDNonTrigMvaValue_branch != 0) els_VIDNonTrigMvaValue();
  if (els_VIDSpring16GPMvaValue_branch != 0) els_VIDSpring16GPMvaValue();
  if (els_VIDSpring16HZZMvaValue_branch != 0) els_VIDSpring16HZZMvaValue();
  if (els_VIDTrigMvaValue_branch != 0) els_VIDTrigMvaValue();
  if (els_chi2_branch != 0) els_chi2();
  if (els_ckf_chi2_branch != 0) els_ckf_chi2();
  if (els_ckf_ndof_branch != 0) els_ckf_ndof();
  if (els_conv_vtx_prob_branch != 0) els_conv_vtx_prob();
  if (els_d0Err_branch != 0) els_d0Err();
  if (els_dEtaIn_branch != 0) els_dEtaIn();
  if (els_dEtaOut_branch != 0) els_dEtaOut();
  if (els_dPhiIn_branch != 0) els_dPhiIn();
  if (els_dPhiOut_branch != 0) els_dPhiOut();
  if (els_dxyPV_branch != 0) els_dxyPV();
  if (els_dzPV_branch != 0) els_dzPV();
  if (els_e1x5_full5x5_branch != 0) els_e1x5_full5x5();
  if (els_e2x5Max_full5x5_branch != 0) els_e2x5Max_full5x5();
  if (els_e5x5_full5x5_branch != 0) els_e5x5_full5x5();
  if (els_eOverPIn_branch != 0) els_eOverPIn();
  if (els_eOverPOut_branch != 0) els_eOverPOut();
  if (els_eSC_branch != 0) els_eSC();
  if (els_eSCPresh_branch != 0) els_eSCPresh();
  if (els_eSCRaw_branch != 0) els_eSCRaw();
  if (els_eSeed_branch != 0) els_eSeed();
  if (els_ecalEnergy_branch != 0) els_ecalEnergy();
  if (els_ecalEnergyError_branch != 0) els_ecalEnergyError();
  if (els_ecalIso_branch != 0) els_ecalIso();
  if (els_ecalIso04_branch != 0) els_ecalIso04();
  if (els_ecalPFClusterIso_branch != 0) els_ecalPFClusterIso();
  if (els_etaSC_branch != 0) els_etaSC();
  if (els_etaSCwidth_branch != 0) els_etaSCwidth();
  if (els_fbrem_branch != 0) els_fbrem();
  if (els_full5x5_hOverE_branch != 0) els_full5x5_hOverE();
  if (els_hOverE_branch != 0) els_hOverE();
  if (els_hcalDepth1TowerSumEt_branch != 0) els_hcalDepth1TowerSumEt();
  if (els_hcalIso_branch != 0) els_hcalIso();
  if (els_hcalIso04_branch != 0) els_hcalIso04();
  if (els_hcalPFClusterIso_branch != 0) els_hcalPFClusterIso();
  if (els_ip2d_branch != 0) els_ip2d();
  if (els_ip2derr_branch != 0) els_ip2derr();
  if (els_ip3d_branch != 0) els_ip3d();
  if (els_ip3derr_branch != 0) els_ip3derr();
  if (els_mc_patMatch_dr_branch != 0) els_mc_patMatch_dr();
  if (els_miniIso_ch_branch != 0) els_miniIso_ch();
  if (els_miniIso_db_branch != 0) els_miniIso_db();
  if (els_miniIso_em_branch != 0) els_miniIso_em();
  if (els_miniIso_nh_branch != 0) els_miniIso_nh();
  if (els_miniIso_uncor_branch != 0) els_miniIso_uncor();
  if (els_ndof_branch != 0) els_ndof();
  if (els_pfChargedHadronIso_branch != 0) els_pfChargedHadronIso();
  if (els_pfNeutralHadronIso_branch != 0) els_pfNeutralHadronIso();
  if (els_pfPUIso_branch != 0) els_pfPUIso();
  if (els_pfPhotonIso_branch != 0) els_pfPhotonIso();
  if (els_phiSC_branch != 0) els_phiSC();
  if (els_phiSCwidth_branch != 0) els_phiSCwidth();
  if (els_ptErr_branch != 0) els_ptErr();
  if (els_ptErrGsf_branch != 0) els_ptErrGsf();
  if (els_r9_branch != 0) els_r9();
  if (els_r9_full5x5_branch != 0) els_r9_full5x5();
  if (els_scSeedEta_branch != 0) els_scSeedEta();
  if (els_sigmaEtaEta_full5x5_branch != 0) els_sigmaEtaEta_full5x5();
  if (els_sigmaIEtaIEta_branch != 0) els_sigmaIEtaIEta();
  if (els_sigmaIEtaIEta_full5x5_branch != 0) els_sigmaIEtaIEta_full5x5();
  if (els_sigmaIPhiIPhi_branch != 0) els_sigmaIPhiIPhi();
  if (els_sigmaIPhiIPhi_full5x5_branch != 0) els_sigmaIPhiIPhi_full5x5();
  if (els_tkIso_branch != 0) els_tkIso();
  if (els_tkIso04_branch != 0) els_tkIso04();
  if (els_trackMomentumError_branch != 0) els_trackMomentumError();
  if (els_trkdr_branch != 0) els_trkdr();
  if (els_trkshFrac_branch != 0) els_trkshFrac();
  if (els_z0Err_branch != 0) els_z0Err();
  if (genps_charge_branch != 0) genps_charge();
  if (genps_iso_branch != 0) genps_iso();
  if (genweights_branch != 0) genweights();
  if (isotracks_dEdxPixel_branch != 0) isotracks_dEdxPixel();
  if (isotracks_dEdxStrip_branch != 0) isotracks_dEdxStrip();
  if (isotracks_deltaEta_branch != 0) isotracks_deltaEta();
  if (isotracks_deltaPhi_branch != 0) isotracks_deltaPhi();
  if (isotracks_dxy_branch != 0) isotracks_dxy();
  if (isotracks_dxyError_branch != 0) isotracks_dxyError();
  if (isotracks_dz_branch != 0) isotracks_dz();
  if (isotracks_dzError_branch != 0) isotracks_dzError();
  if (isotracks_matchedCaloJetEmEnergy_branch != 0) isotracks_matchedCaloJetEmEnergy();
  if (isotracks_matchedCaloJetHadEnergy_branch != 0) isotracks_matchedCaloJetHadEnergy();
  if (isotracks_miniIso_ch_branch != 0) isotracks_miniIso_ch();
  if (isotracks_miniIso_db_branch != 0) isotracks_miniIso_db();
  if (isotracks_miniIso_em_branch != 0) isotracks_miniIso_em();
  if (isotracks_miniIso_nh_branch != 0) isotracks_miniIso_nh();
  if (isotracks_pfIso_ch_branch != 0) isotracks_pfIso_ch();
  if (isotracks_pfIso_db_branch != 0) isotracks_pfIso_db();
  if (isotracks_pfIso_em_branch != 0) isotracks_pfIso_em();
  if (isotracks_pfIso_nh_branch != 0) isotracks_pfIso_nh();
  if (mus_bfit_ptErr_branch != 0) mus_bfit_ptErr();
  if (mus_caloCompatibility_branch != 0) mus_caloCompatibility();
  if (mus_chi2LocalMomentum_branch != 0) mus_chi2LocalMomentum();
  if (mus_chi2LocalPosition_branch != 0) mus_chi2LocalPosition();
  if (mus_d0Err_branch != 0) mus_d0Err();
  if (mus_dxyPV_branch != 0) mus_dxyPV();
  if (mus_dzPV_branch != 0) mus_dzPV();
  if (mus_ecal_time_branch != 0) mus_ecal_time();
  if (mus_gfit_chi2_branch != 0) mus_gfit_chi2();
  if (mus_gfit_ptErr_branch != 0) mus_gfit_ptErr();
  if (mus_hcal_time_branch != 0) mus_hcal_time();
  if (mus_ip2d_branch != 0) mus_ip2d();
  if (mus_ip2derr_branch != 0) mus_ip2derr();
  if (mus_ip3d_branch != 0) mus_ip3d();
  if (mus_ip3derr_branch != 0) mus_ip3derr();
  if (mus_iso03_emEt_branch != 0) mus_iso03_emEt();
  if (mus_iso03_hadEt_branch != 0) mus_iso03_hadEt();
  if (mus_iso03_sumPt_branch != 0) mus_iso03_sumPt();
  if (mus_isoR03_pf_ChargedHadronPt_branch != 0) mus_isoR03_pf_ChargedHadronPt();
  if (mus_isoR03_pf_ChargedParticlePt_branch != 0) mus_isoR03_pf_ChargedParticlePt();
  if (mus_isoR03_pf_NeutralHadronEt_branch != 0) mus_isoR03_pf_NeutralHadronEt();
  if (mus_isoR03_pf_NeutralHadronEtHighThreshold_branch != 0) mus_isoR03_pf_NeutralHadronEtHighThreshold();
  if (mus_isoR03_pf_PUPt_branch != 0) mus_isoR03_pf_PUPt();
  if (mus_isoR03_pf_PhotonEt_branch != 0) mus_isoR03_pf_PhotonEt();
  if (mus_isoR03_pf_PhotonEtHighThreshold_branch != 0) mus_isoR03_pf_PhotonEtHighThreshold();
  if (mus_isoR04_pf_ChargedHadronPt_branch != 0) mus_isoR04_pf_ChargedHadronPt();
  if (mus_isoR04_pf_ChargedParticlePt_branch != 0) mus_isoR04_pf_ChargedParticlePt();
  if (mus_isoR04_pf_NeutralHadronEt_branch != 0) mus_isoR04_pf_NeutralHadronEt();
  if (mus_isoR04_pf_NeutralHadronEtHighThreshold_branch != 0) mus_isoR04_pf_NeutralHadronEtHighThreshold();
  if (mus_isoR04_pf_PUPt_branch != 0) mus_isoR04_pf_PUPt();
  if (mus_isoR04_pf_PhotonEt_branch != 0) mus_isoR04_pf_PhotonEt();
  if (mus_isoR04_pf_PhotonEtHighThreshold_branch != 0) mus_isoR04_pf_PhotonEtHighThreshold();
  if (mus_iso_ecalvetoDep_branch != 0) mus_iso_ecalvetoDep();
  if (mus_iso_hcalvetoDep_branch != 0) mus_iso_hcalvetoDep();
  if (mus_iso_hovetoDep_branch != 0) mus_iso_hovetoDep();
  if (mus_iso_trckvetoDep_branch != 0) mus_iso_trckvetoDep();
  if (mus_mc_patMatch_dr_branch != 0) mus_mc_patMatch_dr();
  if (mus_miniIso_ch_branch != 0) mus_miniIso_ch();
  if (mus_miniIso_db_branch != 0) mus_miniIso_db();
  if (mus_miniIso_em_branch != 0) mus_miniIso_em();
  if (mus_miniIso_nh_branch != 0) mus_miniIso_nh();
  if (mus_miniIso_uncor_branch != 0) mus_miniIso_uncor();
  if (mus_ptErr_branch != 0) mus_ptErr();
  if (mus_segmCompatibility_branch != 0) mus_segmCompatibility();
  if (mus_trkKink_branch != 0) mus_trkKink();
  if (mus_z0Err_branch != 0) mus_z0Err();
  if (pfcands_dxy_branch != 0) pfcands_dxy();
  if (pfcands_dxyError_branch != 0) pfcands_dxyError();
  if (pfcands_dz_branch != 0) pfcands_dz();
  if (pfcands_dzAssociatedPV_branch != 0) pfcands_dzAssociatedPV();
  if (pfcands_dzError_branch != 0) pfcands_dzError();
  if (pfcands_mass_branch != 0) pfcands_mass();
  if (pfcands_miniTrackIso_branch != 0) pfcands_miniTrackIso();
  if (pfcands_puppiWeight_branch != 0) pfcands_puppiWeight();
  if (pfcands_puppiWeightNoLep_branch != 0) pfcands_puppiWeightNoLep();
  if (pfcands_trackIso_branch != 0) pfcands_trackIso();
  if (pfjets_area_branch != 0) pfjets_area();
  if (pfjets_axis1_branch != 0) pfjets_axis1();
  if (pfjets_chargedEmE_branch != 0) pfjets_chargedEmE();
  if (pfjets_chargedHadronE_branch != 0) pfjets_chargedHadronE();
  if (pfjets_electronE_branch != 0) pfjets_electronE();
  if (pfjets_hfEmE_branch != 0) pfjets_hfEmE();
  if (pfjets_hfHadronE_branch != 0) pfjets_hfHadronE();
  if (pfjets_muonE_branch != 0) pfjets_muonE();
  if (pfjets_neutralEmE_branch != 0) pfjets_neutralEmE();
  if (pfjets_neutralHadronE_branch != 0) pfjets_neutralHadronE();
  if (pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch != 0) pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag();
  if (pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch != 0) pfjets_pfDeepCSVJetTagsprobbPlusprobbb();
  if (pfjets_photonE_branch != 0) pfjets_photonE();
  if (pfjets_pileupJetId_branch != 0) pfjets_pileupJetId();
  if (pfjets_ptDistribution_branch != 0) pfjets_ptDistribution();
  if (pfjets_undoJEC_branch != 0) pfjets_undoJEC();
  if (pfjets_puppi_area_branch != 0) pfjets_puppi_area();
  if (pfjets_puppi_axis1_branch != 0) pfjets_puppi_axis1();
  if (pfjets_puppi_chargedEmE_branch != 0) pfjets_puppi_chargedEmE();
  if (pfjets_puppi_chargedHadronE_branch != 0) pfjets_puppi_chargedHadronE();
  if (pfjets_puppi_electronE_branch != 0) pfjets_puppi_electronE();
  if (pfjets_puppi_hfEmE_branch != 0) pfjets_puppi_hfEmE();
  if (pfjets_puppi_hfHadronE_branch != 0) pfjets_puppi_hfHadronE();
  if (pfjets_puppi_muonE_branch != 0) pfjets_puppi_muonE();
  if (pfjets_puppi_neutralEmE_branch != 0) pfjets_puppi_neutralEmE();
  if (pfjets_puppi_neutralHadronE_branch != 0) pfjets_puppi_neutralHadronE();
  if (pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch != 0) pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag();
  if (pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch != 0) pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb();
  if (pfjets_puppi_photonE_branch != 0) pfjets_puppi_photonE();
  if (pfjets_puppi_pileupJetId_branch != 0) pfjets_puppi_pileupJetId();
  if (pfjets_puppi_ptDistribution_branch != 0) pfjets_puppi_ptDistribution();
  if (pfjets_puppi_undoJEC_branch != 0) pfjets_puppi_undoJEC();
  if (photons_ecalPFClusterIso_branch != 0) photons_ecalPFClusterIso();
  if (photons_full5x5_hOverE_branch != 0) photons_full5x5_hOverE();
  if (photons_full5x5_hOverEtowBC_branch != 0) photons_full5x5_hOverEtowBC();
  if (photons_full5x5_r9_branch != 0) photons_full5x5_r9();
  if (photons_full5x5_sigmaIEtaIEta_branch != 0) photons_full5x5_sigmaIEtaIEta();
  if (photons_hOverE_branch != 0) photons_hOverE();
  if (photons_hOverEtowBC_branch != 0) photons_hOverEtowBC();
  if (photons_hcalPFClusterIso_branch != 0) photons_hcalPFClusterIso();
  if (photons_ntkIsoHollow03_branch != 0) photons_ntkIsoHollow03();
  if (photons_recoChargedHadronIso_branch != 0) photons_recoChargedHadronIso();
  if (photons_recoNeutralHadronIso_branch != 0) photons_recoNeutralHadronIso();
  if (photons_recoPhotonIso_branch != 0) photons_recoPhotonIso();
  if (photons_sigmaIEtaIEta_branch != 0) photons_sigmaIEtaIEta();
  if (photons_tkIsoHollow03_branch != 0) photons_tkIsoHollow03();
  if (puInfo_trueNumInteractions_branch != 0) puInfo_trueNumInteractions();
  if (svs_anglePV_branch != 0) svs_anglePV();
  if (svs_chi2_branch != 0) svs_chi2();
  if (svs_dist3Dsig_branch != 0) svs_dist3Dsig();
  if (svs_dist3Dval_branch != 0) svs_dist3Dval();
  if (svs_distXYsig_branch != 0) svs_distXYsig();
  if (svs_distXYval_branch != 0) svs_distXYval();
  if (svs_ndof_branch != 0) svs_ndof();
  if (svs_prob_branch != 0) svs_prob();
  if (svs_xError_branch != 0) svs_xError();
  if (svs_yError_branch != 0) svs_yError();
  if (svs_zError_branch != 0) svs_zError();
  if (ak8jets_area_branch != 0) ak8jets_area();
  if (ak8jets_mass_branch != 0) ak8jets_mass();
  if (ak8jets_nJettinessTau1_branch != 0) ak8jets_nJettinessTau1();
  if (ak8jets_nJettinessTau2_branch != 0) ak8jets_nJettinessTau2();
  if (ak8jets_nJettinessTau3_branch != 0) ak8jets_nJettinessTau3();
  if (ak8jets_prunedMass_branch != 0) ak8jets_prunedMass();
  if (ak8jets_puppi_eta_branch != 0) ak8jets_puppi_eta();
  if (ak8jets_puppi_mass_branch != 0) ak8jets_puppi_mass();
  if (ak8jets_puppi_nJettinessTau1_branch != 0) ak8jets_puppi_nJettinessTau1();
  if (ak8jets_puppi_nJettinessTau2_branch != 0) ak8jets_puppi_nJettinessTau2();
  if (ak8jets_puppi_nJettinessTau3_branch != 0) ak8jets_puppi_nJettinessTau3();
  if (ak8jets_puppi_phi_branch != 0) ak8jets_puppi_phi();
  if (ak8jets_puppi_pt_branch != 0) ak8jets_puppi_pt();
  if (ak8jets_puppi_softdropMass_branch != 0) ak8jets_puppi_softdropMass();
  if (ak8jets_softdropMass_branch != 0) ak8jets_softdropMass();
  if (ak8jets_undoJEC_branch != 0) ak8jets_undoJEC();
  if (vtxs_ndof_branch != 0) vtxs_ndof();
  if (pfjets_bDiscriminators_branch != 0) pfjets_bDiscriminators();
  if (pfjets_puppi_bDiscriminators_branch != 0) pfjets_puppi_bDiscriminators();
  if (taus_pf_IDs_branch != 0) taus_pf_IDs();
  if (puInfo_instLumi_branch != 0) puInfo_instLumi();
  if (evt_bunchCrossing_branch != 0) evt_bunchCrossing();
  if (evt_experimentType_branch != 0) evt_experimentType();
  if (evt_isRealData_branch != 0) evt_isRealData();
  if (evt_orbitNumber_branch != 0) evt_orbitNumber();
  if (evt_storeNumber_branch != 0) evt_storeNumber();
  if (pdfinfo_id1_branch != 0) pdfinfo_id1();
  if (pdfinfo_id2_branch != 0) pdfinfo_id2();
  if (els_mc3_id_branch != 0) els_mc3_id();
  if (els_mc3idx_branch != 0) els_mc3idx();
  if (els_mc3_motherid_branch != 0) els_mc3_motherid();
  if (els_mc3_motheridx_branch != 0) els_mc3_motheridx();
  if (els_mc_id_branch != 0) els_mc_id();
  if (els_mc_motherid_branch != 0) els_mc_motherid();
  if (mus_mc3_id_branch != 0) mus_mc3_id();
  if (mus_mc3idx_branch != 0) mus_mc3idx();
  if (mus_mc3_motherid_branch != 0) mus_mc3_motherid();
  if (mus_mc3_motheridx_branch != 0) mus_mc3_motheridx();
  if (mus_mc_id_branch != 0) mus_mc_id();
  if (mus_mc_motherid_branch != 0) mus_mc_motherid();
  if (pfjets_mc3_id_branch != 0) pfjets_mc3_id();
  if (pfjets_mc3idx_branch != 0) pfjets_mc3idx();
  if (pfjets_mc_motherid_branch != 0) pfjets_mc_motherid();
  if (photons_mc3_id_branch != 0) photons_mc3_id();
  if (photons_mc3idx_branch != 0) photons_mc3idx();
  if (photons_mc3_motherid_branch != 0) photons_mc3_motherid();
  if (photons_mc3_motheridx_branch != 0) photons_mc3_motheridx();
  if (photons_mc_id_branch != 0) photons_mc_id();
  if (photons_mc_motherid_branch != 0) photons_mc_motherid();
  if (els_VIDNonTrigMvaCat_branch != 0) els_VIDNonTrigMvaCat();
  if (els_VIDSpring16GPMvaCat_branch != 0) els_VIDSpring16GPMvaCat();
  if (els_VIDSpring16HZZMvaCat_branch != 0) els_VIDSpring16HZZMvaCat();
  if (els_VIDTrigMvaCat_branch != 0) els_VIDTrigMvaCat();
  if (els_category_branch != 0) els_category();
  if (els_charge_branch != 0) els_charge();
  if (els_ckf_charge_branch != 0) els_ckf_charge();
  if (els_ckf_laywithmeas_branch != 0) els_ckf_laywithmeas();
  if (els_exp_innerlayers_branch != 0) els_exp_innerlayers();
  if (els_exp_outerlayers_branch != 0) els_exp_outerlayers();
  if (els_isEB_branch != 0) els_isEB();
  if (els_isEcalDriven_branch != 0) els_isEcalDriven();
  if (els_isTrackerDriven_branch != 0) els_isTrackerDriven();
  if (els_lostHits_branch != 0) els_lostHits();
  if (els_lost_pixelhits_branch != 0) els_lost_pixelhits();
  if (els_mc_patMatch_id_branch != 0) els_mc_patMatch_id();
  if (els_nlayers_branch != 0) els_nlayers();
  if (els_nlayers3D_branch != 0) els_nlayers3D();
  if (els_nlayersLost_branch != 0) els_nlayersLost();
  if (els_sccharge_branch != 0) els_sccharge();
  if (els_trk_charge_branch != 0) els_trk_charge();
  if (els_type_branch != 0) els_type();
  if (els_validHits_branch != 0) els_validHits();
  if (els_valid_pixelhits_branch != 0) els_valid_pixelhits();
  if (els_passVIDNonTrigMvaWP80Id_branch != 0) els_passVIDNonTrigMvaWP80Id();
  if (els_passVIDNonTrigMvaWP90Id_branch != 0) els_passVIDNonTrigMvaWP90Id();
  if (els_passVIDTrigMvaWP80Id_branch != 0) els_passVIDTrigMvaWP80Id();
  if (els_passVIDTrigMvaWP90Id_branch != 0) els_passVIDTrigMvaWP90Id();
  if (genps_id_branch != 0) genps_id();
  if (genps_id_mother_branch != 0) genps_id_mother();
  if (genps_id_simplegrandma_branch != 0) genps_id_simplegrandma();
  if (genps_id_simplemother_branch != 0) genps_id_simplemother();
  if (genps_idx_mother_branch != 0) genps_idx_mother();
  if (genps_idx_simplemother_branch != 0) genps_idx_simplemother();
  if (genps_status_branch != 0) genps_status();
  if (hyp_ll_charge_branch != 0) hyp_ll_charge();
  if (hyp_ll_id_branch != 0) hyp_ll_id();
  if (hyp_ll_index_branch != 0) hyp_ll_index();
  if (hyp_lt_charge_branch != 0) hyp_lt_charge();
  if (hyp_lt_id_branch != 0) hyp_lt_id();
  if (hyp_lt_index_branch != 0) hyp_lt_index();
  if (hyp_type_branch != 0) hyp_type();
  if (isotracks_charge_branch != 0) isotracks_charge();
  if (isotracks_fromPV_branch != 0) isotracks_fromPV();
  if (isotracks_numberOfLostHitsInner_branch != 0) isotracks_numberOfLostHitsInner();
  if (isotracks_numberOfLostHitsOuter_branch != 0) isotracks_numberOfLostHitsOuter();
  if (isotracks_numberOfLostPixelHitsInner_branch != 0) isotracks_numberOfLostPixelHitsInner();
  if (isotracks_numberOfValidPixelHits_branch != 0) isotracks_numberOfValidPixelHits();
  if (isotracks_particleId_branch != 0) isotracks_particleId();
  if (isotracks_pixelLayersWithMeasurement_branch != 0) isotracks_pixelLayersWithMeasurement();
  if (isotracks_trackerLayersWithMeasurement_branch != 0) isotracks_trackerLayersWithMeasurement();
  if (mus_algo_branch != 0) mus_algo();
  if (mus_algoOrig_branch != 0) mus_algoOrig();
  if (mus_bfit_algo_branch != 0) mus_bfit_algo();
  if (mus_charge_branch != 0) mus_charge();
  if (mus_exp_innerlayers_branch != 0) mus_exp_innerlayers();
  if (mus_exp_outerlayers_branch != 0) mus_exp_outerlayers();
  if (mus_gfit_algo_branch != 0) mus_gfit_algo();
  if (mus_gfit_ndof_branch != 0) mus_gfit_ndof();
  if (mus_gfit_validSTAHits_branch != 0) mus_gfit_validSTAHits();
  if (mus_iso03_ntrk_branch != 0) mus_iso03_ntrk();
  if (mus_lostHits_branch != 0) mus_lostHits();
  if (mus_mc_patMatch_id_branch != 0) mus_mc_patMatch_id();
  if (mus_nlayers_branch != 0) mus_nlayers();
  if (mus_numberOfMatchedStations_branch != 0) mus_numberOfMatchedStations();
  if (mus_pfcharge_branch != 0) mus_pfcharge();
  if (mus_pfidx_branch != 0) mus_pfidx();
  if (mus_pfparticleId_branch != 0) mus_pfparticleId();
  if (mus_pid_PFMuon_branch != 0) mus_pid_PFMuon();
  if (mus_pid_TM2DCompatibilityLoose_branch != 0) mus_pid_TM2DCompatibilityLoose();
  if (mus_pid_TM2DCompatibilityTight_branch != 0) mus_pid_TM2DCompatibilityTight();
  if (mus_pid_TMLastStationLoose_branch != 0) mus_pid_TMLastStationLoose();
  if (mus_pid_TMLastStationTight_branch != 0) mus_pid_TMLastStationTight();
  if (mus_pid_TMOneStationTight_branch != 0) mus_pid_TMOneStationTight();
  if (mus_type_branch != 0) mus_type();
  if (mus_validHits_branch != 0) mus_validHits();
  if (mus_validPixelHits_branch != 0) mus_validPixelHits();
  if (pfcands_IdAssociatedPV_branch != 0) pfcands_IdAssociatedPV();
  if (pfcands_charge_branch != 0) pfcands_charge();
  if (pfcands_numberOfHits_branch != 0) pfcands_numberOfHits();
  if (pfcands_numberOfPixelHits_branch != 0) pfcands_numberOfPixelHits();
  if (pfcands_particleId_branch != 0) pfcands_particleId();
  if (pfcands_pixelLayersWithMeasurement_branch != 0) pfcands_pixelLayersWithMeasurement();
  if (pfcands_stripLayersWithMeasurement_branch != 0) pfcands_stripLayersWithMeasurement();
  if (pfjets_chargedHadronMultiplicity_branch != 0) pfjets_chargedHadronMultiplicity();
  if (pfjets_chargedMultiplicity_branch != 0) pfjets_chargedMultiplicity();
  if (pfjets_electronMultiplicity_branch != 0) pfjets_electronMultiplicity();
  if (pfjets_hadronFlavour_branch != 0) pfjets_hadronFlavour();
  if (pfjets_muonMultiplicity_branch != 0) pfjets_muonMultiplicity();
  if (pfjets_neutralHadronMultiplicity_branch != 0) pfjets_neutralHadronMultiplicity();
  if (pfjets_neutralMultiplicity_branch != 0) pfjets_neutralMultiplicity();
  if (pfjets_npfcands_branch != 0) pfjets_npfcands();
  if (pfjets_partonFlavour_branch != 0) pfjets_partonFlavour();
  if (pfjets_photonMultiplicity_branch != 0) pfjets_photonMultiplicity();
  if (pfjets_totalMultiplicity_branch != 0) pfjets_totalMultiplicity();
  if (pfjets_puppi_chargedHadronMultiplicity_branch != 0) pfjets_puppi_chargedHadronMultiplicity();
  if (pfjets_puppi_chargedMultiplicity_branch != 0) pfjets_puppi_chargedMultiplicity();
  if (pfjets_puppi_electronMultiplicity_branch != 0) pfjets_puppi_electronMultiplicity();
  if (pfjets_puppi_hadronFlavour_branch != 0) pfjets_puppi_hadronFlavour();
  if (pfjets_puppi_muonMultiplicity_branch != 0) pfjets_puppi_muonMultiplicity();
  if (pfjets_puppi_neutralHadronMultiplicity_branch != 0) pfjets_puppi_neutralHadronMultiplicity();
  if (pfjets_puppi_neutralMultiplicity_branch != 0) pfjets_puppi_neutralMultiplicity();
  if (pfjets_puppi_npfcands_branch != 0) pfjets_puppi_npfcands();
  if (pfjets_puppi_partonFlavour_branch != 0) pfjets_puppi_partonFlavour();
  if (pfjets_puppi_photonMultiplicity_branch != 0) pfjets_puppi_photonMultiplicity();
  if (pfjets_puppi_totalMultiplicity_branch != 0) pfjets_puppi_totalMultiplicity();
  if (taus_pf_charge_branch != 0) taus_pf_charge();
  if (photons_photonID_loose_branch != 0) photons_photonID_loose();
  if (photons_photonID_tight_branch != 0) photons_photonID_tight();
  if (puInfo_bunchCrossing_branch != 0) puInfo_bunchCrossing();
  if (puInfo_nPUvertices_branch != 0) puInfo_nPUvertices();
  if (svs_nTrks_branch != 0) svs_nTrks();
  if (_npfcands_branch != 0) _npfcands();
  if (ak8jets_partonFlavour_branch != 0) ak8jets_partonFlavour();
  if (vtxs_isFake_branch != 0) vtxs_isFake();
  if (vtxs_isValid_branch != 0) vtxs_isValid();
  if (genps_lepdaughter_id_branch != 0) genps_lepdaughter_id();
  if (genps_lepdaughter_idx_branch != 0) genps_lepdaughter_idx();
  if (photons_PFCand_idx_branch != 0) photons_PFCand_idx();
  if (pfcands_fromPV_branch != 0) pfcands_fromPV();
  if (pfcands_normalizedChi2_branch != 0) pfcands_normalizedChi2();
  if (pfcands_packedHits_branch != 0) pfcands_packedHits();
  if (pfcands_packedLayers_branch != 0) pfcands_packedLayers();
  if (pfcands_pvAssociationQuality_branch != 0) pfcands_pvAssociationQuality();
  if (evt_nels_branch != 0) evt_nels();
  if (evt_detectorStatus_branch != 0) evt_detectorStatus();
  if (evt_lumiBlock_branch != 0) evt_lumiBlock();
  if (evt_run_branch != 0) evt_run();
  if (evt_ngenjetsNoMuNoNu_branch != 0) evt_ngenjetsNoMuNoNu();
  if (genps_signalProcessID_branch != 0) genps_signalProcessID();
  if (evt_nphotons_branch != 0) evt_nphotons();
  if (evt_nvtxs_branch != 0) evt_nvtxs();
  if (hlt_l1prescales_branch != 0) hlt_l1prescales();
  if (hlt_prescales_branch != 0) hlt_prescales();
  if (isotracks_crossedHcalStatus_branch != 0) isotracks_crossedHcalStatus();
  if (evt_event_branch != 0) evt_event();
  if (evt_timestamp_branch != 0) evt_timestamp();
}

const vector<string> &CMS3::genweightsID() {
  if (not genweightsID_isLoaded) {
    if (genweightsID_branch != 0) {
      genweightsID_branch->GetEntry(index);
    } else {
      printf("branch genweightsID_branch does not exist!\n");
      exit(1);
    }
    genweightsID_isLoaded = true;
  }
  return genweightsID_;
}

const TBits &CMS3::hlt_bits() {
  if (not hlt_bits_isLoaded) {
    if (hlt_bits_branch != 0) {
      hlt_bits_branch->GetEntry(index);
    } else {
      printf("branch hlt_bits_branch does not exist!\n");
      exit(1);
    }
    hlt_bits_isLoaded = true;
  }
  return hlt_bits_;
}

const vector<TString> &CMS3::evt_CMS3tag() {
  if (not evt_CMS3tag_isLoaded) {
    if (evt_CMS3tag_branch != 0) {
      evt_CMS3tag_branch->GetEntry(index);
    } else {
      printf("branch evt_CMS3tag_branch does not exist!\n");
      exit(1);
    }
    evt_CMS3tag_isLoaded = true;
  }
  return evt_CMS3tag_;
}

const vector<TString> &CMS3::evt_dataset() {
  if (not evt_dataset_isLoaded) {
    if (evt_dataset_branch != 0) {
      evt_dataset_branch->GetEntry(index);
    } else {
      printf("branch evt_dataset_branch does not exist!\n");
      exit(1);
    }
    evt_dataset_isLoaded = true;
  }
  return evt_dataset_;
}

const vector<TString> &CMS3::hlt_trigNames() {
  if (not hlt_trigNames_isLoaded) {
    if (hlt_trigNames_branch != 0) {
      hlt_trigNames_branch->GetEntry(index);
    } else {
      printf("branch hlt_trigNames_branch does not exist!\n");
      exit(1);
    }
    hlt_trigNames_isLoaded = true;
  }
  return hlt_trigNames_;
}

const vector<TString> &CMS3::pfjets_bDiscriminatorNames() {
  if (not pfjets_bDiscriminatorNames_isLoaded) {
    if (pfjets_bDiscriminatorNames_branch != 0) {
      pfjets_bDiscriminatorNames_branch->GetEntry(index);
    } else {
      printf("branch pfjets_bDiscriminatorNames_branch does not exist!\n");
      exit(1);
    }
    pfjets_bDiscriminatorNames_isLoaded = true;
  }
  return pfjets_bDiscriminatorNames_;
}

const vector<TString> &CMS3::pfjets_puppi_bDiscriminatorNames() {
  if (not pfjets_puppi_bDiscriminatorNames_isLoaded) {
    if (pfjets_puppi_bDiscriminatorNames_branch != 0) {
      pfjets_puppi_bDiscriminatorNames_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_bDiscriminatorNames_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_bDiscriminatorNames_isLoaded = true;
  }
  return pfjets_puppi_bDiscriminatorNames_;
}

const vector<TString> &CMS3::taus_pf_IDnames() {
  if (not taus_pf_IDnames_isLoaded) {
    if (taus_pf_IDnames_branch != 0) {
      taus_pf_IDnames_branch->GetEntry(index);
    } else {
      printf("branch taus_pf_IDnames_branch does not exist!\n");
      exit(1);
    }
    taus_pf_IDnames_isLoaded = true;
  }
  return taus_pf_IDnames_;
}

const bool &CMS3::evt_cscTightHaloId() {
  if (not evt_cscTightHaloId_isLoaded) {
    if (evt_cscTightHaloId_branch != 0) {
      evt_cscTightHaloId_branch->GetEntry(index);
    } else {
      printf("branch evt_cscTightHaloId_branch does not exist!\n");
      exit(1);
    }
    evt_cscTightHaloId_isLoaded = true;
  }
  return evt_cscTightHaloId_;
}

const bool &CMS3::evt_hbheFilter() {
  if (not evt_hbheFilter_isLoaded) {
    if (evt_hbheFilter_branch != 0) {
      evt_hbheFilter_branch->GetEntry(index);
    } else {
      printf("branch evt_hbheFilter_branch does not exist!\n");
      exit(1);
    }
    evt_hbheFilter_isLoaded = true;
  }
  return evt_hbheFilter_;
}

const bool &CMS3::filt_chargedHadronTrackResolution() {
  if (not filt_chargedHadronTrackResolution_isLoaded) {
    if (filt_chargedHadronTrackResolution_branch != 0) {
      filt_chargedHadronTrackResolution_branch->GetEntry(index);
    } else {
      printf("branch filt_chargedHadronTrackResolution_branch does not exist!\n");
      exit(1);
    }
    filt_chargedHadronTrackResolution_isLoaded = true;
  }
  return filt_chargedHadronTrackResolution_;
}

const bool &CMS3::filt_cscBeamHalo() {
  if (not filt_cscBeamHalo_isLoaded) {
    if (filt_cscBeamHalo_branch != 0) {
      filt_cscBeamHalo_branch->GetEntry(index);
    } else {
      printf("branch filt_cscBeamHalo_branch does not exist!\n");
      exit(1);
    }
    filt_cscBeamHalo_isLoaded = true;
  }
  return filt_cscBeamHalo_;
}

const bool &CMS3::filt_cscBeamHalo2015() {
  if (not filt_cscBeamHalo2015_isLoaded) {
    if (filt_cscBeamHalo2015_branch != 0) {
      filt_cscBeamHalo2015_branch->GetEntry(index);
    } else {
      printf("branch filt_cscBeamHalo2015_branch does not exist!\n");
      exit(1);
    }
    filt_cscBeamHalo2015_isLoaded = true;
  }
  return filt_cscBeamHalo2015_;
}

const bool &CMS3::filt_cscBeamHaloTrkMuUnveto() {
  if (not filt_cscBeamHaloTrkMuUnveto_isLoaded) {
    if (filt_cscBeamHaloTrkMuUnveto_branch != 0) {
      filt_cscBeamHaloTrkMuUnveto_branch->GetEntry(index);
    } else {
      printf("branch filt_cscBeamHaloTrkMuUnveto_branch does not exist!\n");
      exit(1);
    }
    filt_cscBeamHaloTrkMuUnveto_isLoaded = true;
  }
  return filt_cscBeamHaloTrkMuUnveto_;
}

const bool &CMS3::filt_ecalBoundaryEnergy() {
  if (not filt_ecalBoundaryEnergy_isLoaded) {
    if (filt_ecalBoundaryEnergy_branch != 0) {
      filt_ecalBoundaryEnergy_branch->GetEntry(index);
    } else {
      printf("branch filt_ecalBoundaryEnergy_branch does not exist!\n");
      exit(1);
    }
    filt_ecalBoundaryEnergy_isLoaded = true;
  }
  return filt_ecalBoundaryEnergy_;
}

const bool &CMS3::filt_ecalLaser() {
  if (not filt_ecalLaser_isLoaded) {
    if (filt_ecalLaser_branch != 0) {
      filt_ecalLaser_branch->GetEntry(index);
    } else {
      printf("branch filt_ecalLaser_branch does not exist!\n");
      exit(1);
    }
    filt_ecalLaser_isLoaded = true;
  }
  return filt_ecalLaser_;
}

const bool &CMS3::filt_ecalTP() {
  if (not filt_ecalTP_isLoaded) {
    if (filt_ecalTP_branch != 0) {
      filt_ecalTP_branch->GetEntry(index);
    } else {
      printf("branch filt_ecalTP_branch does not exist!\n");
      exit(1);
    }
    filt_ecalTP_isLoaded = true;
  }
  return filt_ecalTP_;
}

const bool &CMS3::filt_eeBadSc() {
  if (not filt_eeBadSc_isLoaded) {
    if (filt_eeBadSc_branch != 0) {
      filt_eeBadSc_branch->GetEntry(index);
    } else {
      printf("branch filt_eeBadSc_branch does not exist!\n");
      exit(1);
    }
    filt_eeBadSc_isLoaded = true;
  }
  return filt_eeBadSc_;
}

const bool &CMS3::filt_globalSuperTightHalo2016() {
  if (not filt_globalSuperTightHalo2016_isLoaded) {
    if (filt_globalSuperTightHalo2016_branch != 0) {
      filt_globalSuperTightHalo2016_branch->GetEntry(index);
    } else {
      printf("branch filt_globalSuperTightHalo2016_branch does not exist!\n");
      exit(1);
    }
    filt_globalSuperTightHalo2016_isLoaded = true;
  }
  return filt_globalSuperTightHalo2016_;
}

const bool &CMS3::filt_globalTightHalo2016() {
  if (not filt_globalTightHalo2016_isLoaded) {
    if (filt_globalTightHalo2016_branch != 0) {
      filt_globalTightHalo2016_branch->GetEntry(index);
    } else {
      printf("branch filt_globalTightHalo2016_branch does not exist!\n");
      exit(1);
    }
    filt_globalTightHalo2016_isLoaded = true;
  }
  return filt_globalTightHalo2016_;
}

const bool &CMS3::filt_goodVertices() {
  if (not filt_goodVertices_isLoaded) {
    if (filt_goodVertices_branch != 0) {
      filt_goodVertices_branch->GetEntry(index);
    } else {
      printf("branch filt_goodVertices_branch does not exist!\n");
      exit(1);
    }
    filt_goodVertices_isLoaded = true;
  }
  return filt_goodVertices_;
}

const bool &CMS3::filt_hbheNoise() {
  if (not filt_hbheNoise_isLoaded) {
    if (filt_hbheNoise_branch != 0) {
      filt_hbheNoise_branch->GetEntry(index);
    } else {
      printf("branch filt_hbheNoise_branch does not exist!\n");
      exit(1);
    }
    filt_hbheNoise_isLoaded = true;
  }
  return filt_hbheNoise_;
}

const bool &CMS3::filt_hbheNoiseIso() {
  if (not filt_hbheNoiseIso_isLoaded) {
    if (filt_hbheNoiseIso_branch != 0) {
      filt_hbheNoiseIso_branch->GetEntry(index);
    } else {
      printf("branch filt_hbheNoiseIso_branch does not exist!\n");
      exit(1);
    }
    filt_hbheNoiseIso_isLoaded = true;
  }
  return filt_hbheNoiseIso_;
}

const bool &CMS3::filt_hcalLaser() {
  if (not filt_hcalLaser_isLoaded) {
    if (filt_hcalLaser_branch != 0) {
      filt_hcalLaser_branch->GetEntry(index);
    } else {
      printf("branch filt_hcalLaser_branch does not exist!\n");
      exit(1);
    }
    filt_hcalLaser_isLoaded = true;
  }
  return filt_hcalLaser_;
}

const bool &CMS3::filt_hcalStrip() {
  if (not filt_hcalStrip_isLoaded) {
    if (filt_hcalStrip_branch != 0) {
      filt_hcalStrip_branch->GetEntry(index);
    } else {
      printf("branch filt_hcalStrip_branch does not exist!\n");
      exit(1);
    }
    filt_hcalStrip_isLoaded = true;
  }
  return filt_hcalStrip_;
}

const bool &CMS3::filt_metfilter() {
  if (not filt_metfilter_isLoaded) {
    if (filt_metfilter_branch != 0) {
      filt_metfilter_branch->GetEntry(index);
    } else {
      printf("branch filt_metfilter_branch does not exist!\n");
      exit(1);
    }
    filt_metfilter_isLoaded = true;
  }
  return filt_metfilter_;
}

const bool &CMS3::filt_muonBadTrack() {
  if (not filt_muonBadTrack_isLoaded) {
    if (filt_muonBadTrack_branch != 0) {
      filt_muonBadTrack_branch->GetEntry(index);
    } else {
      printf("branch filt_muonBadTrack_branch does not exist!\n");
      exit(1);
    }
    filt_muonBadTrack_isLoaded = true;
  }
  return filt_muonBadTrack_;
}

const bool &CMS3::filt_trackingFailure() {
  if (not filt_trackingFailure_isLoaded) {
    if (filt_trackingFailure_branch != 0) {
      filt_trackingFailure_branch->GetEntry(index);
    } else {
      printf("branch filt_trackingFailure_branch does not exist!\n");
      exit(1);
    }
    filt_trackingFailure_isLoaded = true;
  }
  return filt_trackingFailure_;
}

const bool &CMS3::filt_trkPOGFilters() {
  if (not filt_trkPOGFilters_isLoaded) {
    if (filt_trkPOGFilters_branch != 0) {
      filt_trkPOGFilters_branch->GetEntry(index);
    } else {
      printf("branch filt_trkPOGFilters_branch does not exist!\n");
      exit(1);
    }
    filt_trkPOGFilters_isLoaded = true;
  }
  return filt_trkPOGFilters_;
}

const bool &CMS3::filt_trkPOG_logErrorTooManyClusters() {
  if (not filt_trkPOG_logErrorTooManyClusters_isLoaded) {
    if (filt_trkPOG_logErrorTooManyClusters_branch != 0) {
      filt_trkPOG_logErrorTooManyClusters_branch->GetEntry(index);
    } else {
      printf("branch filt_trkPOG_logErrorTooManyClusters_branch does not exist!\n");
      exit(1);
    }
    filt_trkPOG_logErrorTooManyClusters_isLoaded = true;
  }
  return filt_trkPOG_logErrorTooManyClusters_;
}

const bool &CMS3::filt_trkPOG_manystripclus53X() {
  if (not filt_trkPOG_manystripclus53X_isLoaded) {
    if (filt_trkPOG_manystripclus53X_branch != 0) {
      filt_trkPOG_manystripclus53X_branch->GetEntry(index);
    } else {
      printf("branch filt_trkPOG_manystripclus53X_branch does not exist!\n");
      exit(1);
    }
    filt_trkPOG_manystripclus53X_isLoaded = true;
  }
  return filt_trkPOG_manystripclus53X_;
}

const bool &CMS3::filt_trkPOG_toomanystripclus53X() {
  if (not filt_trkPOG_toomanystripclus53X_isLoaded) {
    if (filt_trkPOG_toomanystripclus53X_branch != 0) {
      filt_trkPOG_toomanystripclus53X_branch->GetEntry(index);
    } else {
      printf("branch filt_trkPOG_toomanystripclus53X_branch does not exist!\n");
      exit(1);
    }
    filt_trkPOG_toomanystripclus53X_isLoaded = true;
  }
  return filt_trkPOG_toomanystripclus53X_;
}

const vector<bool> &CMS3::els_conv_vtx_flag() {
  if (not els_conv_vtx_flag_isLoaded) {
    if (els_conv_vtx_flag_branch != 0) {
      els_conv_vtx_flag_branch->GetEntry(index);
    } else {
      printf("branch els_conv_vtx_flag_branch does not exist!\n");
      exit(1);
    }
    els_conv_vtx_flag_isLoaded = true;
  }
  return els_conv_vtx_flag_;
}

const vector<bool> &CMS3::els_isGsfCtfScPixChargeConsistent() {
  if (not els_isGsfCtfScPixChargeConsistent_isLoaded) {
    if (els_isGsfCtfScPixChargeConsistent_branch != 0) {
      els_isGsfCtfScPixChargeConsistent_branch->GetEntry(index);
    } else {
      printf("branch els_isGsfCtfScPixChargeConsistent_branch does not exist!\n");
      exit(1);
    }
    els_isGsfCtfScPixChargeConsistent_isLoaded = true;
  }
  return els_isGsfCtfScPixChargeConsistent_;
}

const vector<bool> &CMS3::genps_fromHardProcessBeforeFSR() {
  if (not genps_fromHardProcessBeforeFSR_isLoaded) {
    if (genps_fromHardProcessBeforeFSR_branch != 0) {
      genps_fromHardProcessBeforeFSR_branch->GetEntry(index);
    } else {
      printf("branch genps_fromHardProcessBeforeFSR_branch does not exist!\n");
      exit(1);
    }
    genps_fromHardProcessBeforeFSR_isLoaded = true;
  }
  return genps_fromHardProcessBeforeFSR_;
}

const vector<bool> &CMS3::genps_fromHardProcessDecayed() {
  if (not genps_fromHardProcessDecayed_isLoaded) {
    if (genps_fromHardProcessDecayed_branch != 0) {
      genps_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch genps_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    genps_fromHardProcessDecayed_isLoaded = true;
  }
  return genps_fromHardProcessDecayed_;
}

const vector<bool> &CMS3::genps_fromHardProcessFinalState() {
  if (not genps_fromHardProcessFinalState_isLoaded) {
    if (genps_fromHardProcessFinalState_branch != 0) {
      genps_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch genps_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    genps_fromHardProcessFinalState_isLoaded = true;
  }
  return genps_fromHardProcessFinalState_;
}

const vector<bool> &CMS3::genps_isDirectHardProcessTauDecayProductFinalState() {
  if (not genps_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
    if (genps_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
      genps_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
    } else {
      printf("branch genps_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
      exit(1);
    }
    genps_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
  }
  return genps_isDirectHardProcessTauDecayProductFinalState_;
}

const vector<bool> &CMS3::genps_isDirectPromptTauDecayProductFinalState() {
  if (not genps_isDirectPromptTauDecayProductFinalState_isLoaded) {
    if (genps_isDirectPromptTauDecayProductFinalState_branch != 0) {
      genps_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
    } else {
      printf("branch genps_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
      exit(1);
    }
    genps_isDirectPromptTauDecayProductFinalState_isLoaded = true;
  }
  return genps_isDirectPromptTauDecayProductFinalState_;
}

const vector<bool> &CMS3::genps_isHardProcess() {
  if (not genps_isHardProcess_isLoaded) {
    if (genps_isHardProcess_branch != 0) {
      genps_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch genps_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    genps_isHardProcess_isLoaded = true;
  }
  return genps_isHardProcess_;
}

const vector<bool> &CMS3::genps_isLastCopy() {
  if (not genps_isLastCopy_isLoaded) {
    if (genps_isLastCopy_branch != 0) {
      genps_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch genps_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    genps_isLastCopy_isLoaded = true;
  }
  return genps_isLastCopy_;
}

const vector<bool> &CMS3::genps_isLastCopyBeforeFSR() {
  if (not genps_isLastCopyBeforeFSR_isLoaded) {
    if (genps_isLastCopyBeforeFSR_branch != 0) {
      genps_isLastCopyBeforeFSR_branch->GetEntry(index);
    } else {
      printf("branch genps_isLastCopyBeforeFSR_branch does not exist!\n");
      exit(1);
    }
    genps_isLastCopyBeforeFSR_isLoaded = true;
  }
  return genps_isLastCopyBeforeFSR_;
}

const vector<bool> &CMS3::genps_isMostlyLikePythia6Status3() {
  if (not genps_isMostlyLikePythia6Status3_isLoaded) {
    if (genps_isMostlyLikePythia6Status3_branch != 0) {
      genps_isMostlyLikePythia6Status3_branch->GetEntry(index);
    } else {
      printf("branch genps_isMostlyLikePythia6Status3_branch does not exist!\n");
      exit(1);
    }
    genps_isMostlyLikePythia6Status3_isLoaded = true;
  }
  return genps_isMostlyLikePythia6Status3_;
}

const vector<bool> &CMS3::genps_isPromptDecayed() {
  if (not genps_isPromptDecayed_isLoaded) {
    if (genps_isPromptDecayed_branch != 0) {
      genps_isPromptDecayed_branch->GetEntry(index);
    } else {
      printf("branch genps_isPromptDecayed_branch does not exist!\n");
      exit(1);
    }
    genps_isPromptDecayed_isLoaded = true;
  }
  return genps_isPromptDecayed_;
}

const vector<bool> &CMS3::genps_isPromptFinalState() {
  if (not genps_isPromptFinalState_isLoaded) {
    if (genps_isPromptFinalState_branch != 0) {
      genps_isPromptFinalState_branch->GetEntry(index);
    } else {
      printf("branch genps_isPromptFinalState_branch does not exist!\n");
      exit(1);
    }
    genps_isPromptFinalState_isLoaded = true;
  }
  return genps_isPromptFinalState_;
}

const vector<bool> &CMS3::isotracks_isHighPurityTrack() {
  if (not isotracks_isHighPurityTrack_isLoaded) {
    if (isotracks_isHighPurityTrack_branch != 0) {
      isotracks_isHighPurityTrack_branch->GetEntry(index);
    } else {
      printf("branch isotracks_isHighPurityTrack_branch does not exist!\n");
      exit(1);
    }
    isotracks_isHighPurityTrack_isLoaded = true;
  }
  return isotracks_isHighPurityTrack_;
}

const vector<bool> &CMS3::isotracks_isPFCand() {
  if (not isotracks_isPFCand_isLoaded) {
    if (isotracks_isPFCand_branch != 0) {
      isotracks_isPFCand_branch->GetEntry(index);
    } else {
      printf("branch isotracks_isPFCand_branch does not exist!\n");
      exit(1);
    }
    isotracks_isPFCand_isLoaded = true;
  }
  return isotracks_isPFCand_;
}

const vector<bool> &CMS3::isotracks_isTightTrack() {
  if (not isotracks_isTightTrack_isLoaded) {
    if (isotracks_isTightTrack_branch != 0) {
      isotracks_isTightTrack_branch->GetEntry(index);
    } else {
      printf("branch isotracks_isTightTrack_branch does not exist!\n");
      exit(1);
    }
    isotracks_isTightTrack_isLoaded = true;
  }
  return isotracks_isTightTrack_;
}

const vector<bool> &CMS3::pfcands_isGlobalMuon() {
  if (not pfcands_isGlobalMuon_isLoaded) {
    if (pfcands_isGlobalMuon_branch != 0) {
      pfcands_isGlobalMuon_branch->GetEntry(index);
    } else {
      printf("branch pfcands_isGlobalMuon_branch does not exist!\n");
      exit(1);
    }
    pfcands_isGlobalMuon_isLoaded = true;
  }
  return pfcands_isGlobalMuon_;
}

const vector<bool> &CMS3::pfcands_isStandAloneMuon() {
  if (not pfcands_isStandAloneMuon_isLoaded) {
    if (pfcands_isStandAloneMuon_branch != 0) {
      pfcands_isStandAloneMuon_branch->GetEntry(index);
    } else {
      printf("branch pfcands_isStandAloneMuon_branch does not exist!\n");
      exit(1);
    }
    pfcands_isStandAloneMuon_isLoaded = true;
  }
  return pfcands_isStandAloneMuon_;
}

const vector<bool> &CMS3::pfcands_trackHighPurity() {
  if (not pfcands_trackHighPurity_isLoaded) {
    if (pfcands_trackHighPurity_branch != 0) {
      pfcands_trackHighPurity_branch->GetEntry(index);
    } else {
      printf("branch pfcands_trackHighPurity_branch does not exist!\n");
      exit(1);
    }
    pfcands_trackHighPurity_isLoaded = true;
  }
  return pfcands_trackHighPurity_;
}

const vector<bool> &CMS3::photons_haspixelSeed() {
  if (not photons_haspixelSeed_isLoaded) {
    if (photons_haspixelSeed_branch != 0) {
      photons_haspixelSeed_branch->GetEntry(index);
    } else {
      printf("branch photons_haspixelSeed_branch does not exist!\n");
      exit(1);
    }
    photons_haspixelSeed_isLoaded = true;
  }
  return photons_haspixelSeed_;
}

const vector<bool> &CMS3::photons_passElectronVeto() {
  if (not photons_passElectronVeto_isLoaded) {
    if (photons_passElectronVeto_branch != 0) {
      photons_passElectronVeto_branch->GetEntry(index);
    } else {
      printf("branch photons_passElectronVeto_branch does not exist!\n");
      exit(1);
    }
    photons_passElectronVeto_isLoaded = true;
  }
  return photons_passElectronVeto_;
}

const float &CMS3::evt_bField() {
  if (not evt_bField_isLoaded) {
    if (evt_bField_branch != 0) {
      evt_bField_branch->GetEntry(index);
    } else {
      printf("branch evt_bField_branch does not exist!\n");
      exit(1);
    }
    evt_bField_isLoaded = true;
  }
  return evt_bField_;
}

const float &CMS3::evt_instantLumi() {
  if (not evt_instantLumi_isLoaded) {
    if (evt_instantLumi_branch != 0) {
      evt_instantLumi_branch->GetEntry(index);
    } else {
      printf("branch evt_instantLumi_branch does not exist!\n");
      exit(1);
    }
    evt_instantLumi_isLoaded = true;
  }
  return evt_instantLumi_;
}

const float &CMS3::evt_instantLumiErr() {
  if (not evt_instantLumiErr_isLoaded) {
    if (evt_instantLumiErr_branch != 0) {
      evt_instantLumiErr_branch->GetEntry(index);
    } else {
      printf("branch evt_instantLumiErr_branch does not exist!\n");
      exit(1);
    }
    evt_instantLumiErr_isLoaded = true;
  }
  return evt_instantLumiErr_;
}

const float &CMS3::evt_lumiFill() {
  if (not evt_lumiFill_isLoaded) {
    if (evt_lumiFill_branch != 0) {
      evt_lumiFill_branch->GetEntry(index);
    } else {
      printf("branch evt_lumiFill_branch does not exist!\n");
      exit(1);
    }
    evt_lumiFill_isLoaded = true;
  }
  return evt_lumiFill_;
}

const float &CMS3::evt_lumiRun() {
  if (not evt_lumiRun_isLoaded) {
    if (evt_lumiRun_branch != 0) {
      evt_lumiRun_branch->GetEntry(index);
    } else {
      printf("branch evt_lumiRun_branch does not exist!\n");
      exit(1);
    }
    evt_lumiRun_isLoaded = true;
  }
  return evt_lumiRun_;
}

const float &CMS3::evt_pileup() {
  if (not evt_pileup_isLoaded) {
    if (evt_pileup_branch != 0) {
      evt_pileup_branch->GetEntry(index);
    } else {
      printf("branch evt_pileup_branch does not exist!\n");
      exit(1);
    }
    evt_pileup_isLoaded = true;
  }
  return evt_pileup_;
}

const float &CMS3::evt_pileupRMS() {
  if (not evt_pileupRMS_isLoaded) {
    if (evt_pileupRMS_branch != 0) {
      evt_pileupRMS_branch->GetEntry(index);
    } else {
      printf("branch evt_pileupRMS_branch does not exist!\n");
      exit(1);
    }
    evt_pileupRMS_isLoaded = true;
  }
  return evt_pileupRMS_;
}

const float &CMS3::evt_fixgrid_all_rho() {
  if (not evt_fixgrid_all_rho_isLoaded) {
    if (evt_fixgrid_all_rho_branch != 0) {
      evt_fixgrid_all_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgrid_all_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgrid_all_rho_isLoaded = true;
  }
  return evt_fixgrid_all_rho_;
}

const float &CMS3::evt_fixgridfastjet_allcalo_rho() {
  if (not evt_fixgridfastjet_allcalo_rho_isLoaded) {
    if (evt_fixgridfastjet_allcalo_rho_branch != 0) {
      evt_fixgridfastjet_allcalo_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgridfastjet_allcalo_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgridfastjet_allcalo_rho_isLoaded = true;
  }
  return evt_fixgridfastjet_allcalo_rho_;
}

const float &CMS3::evt_fixgridfastjet_central_rho() {
  if (not evt_fixgridfastjet_central_rho_isLoaded) {
    if (evt_fixgridfastjet_central_rho_branch != 0) {
      evt_fixgridfastjet_central_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgridfastjet_central_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgridfastjet_central_rho_isLoaded = true;
  }
  return evt_fixgridfastjet_central_rho_;
}

const float &CMS3::evt_fixgridfastjet_all_rho() {
  if (not evt_fixgridfastjet_all_rho_isLoaded) {
    if (evt_fixgridfastjet_all_rho_branch != 0) {
      evt_fixgridfastjet_all_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgridfastjet_all_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgridfastjet_all_rho_isLoaded = true;
  }
  return evt_fixgridfastjet_all_rho_;
}

const float &CMS3::evt_fixgridfastjet_centralcalo_rho() {
  if (not evt_fixgridfastjet_centralcalo_rho_isLoaded) {
    if (evt_fixgridfastjet_centralcalo_rho_branch != 0) {
      evt_fixgridfastjet_centralcalo_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgridfastjet_centralcalo_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgridfastjet_centralcalo_rho_isLoaded = true;
  }
  return evt_fixgridfastjet_centralcalo_rho_;
}

const float &CMS3::evt_fixgridfastjet_centralchargedpileup_rho() {
  if (not evt_fixgridfastjet_centralchargedpileup_rho_isLoaded) {
    if (evt_fixgridfastjet_centralchargedpileup_rho_branch != 0) {
      evt_fixgridfastjet_centralchargedpileup_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgridfastjet_centralchargedpileup_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgridfastjet_centralchargedpileup_rho_isLoaded = true;
  }
  return evt_fixgridfastjet_centralchargedpileup_rho_;
}

const float &CMS3::evt_fixgridfastjet_centralneutral_rho() {
  if (not evt_fixgridfastjet_centralneutral_rho_isLoaded) {
    if (evt_fixgridfastjet_centralneutral_rho_branch != 0) {
      evt_fixgridfastjet_centralneutral_rho_branch->GetEntry(index);
    } else {
      printf("branch evt_fixgridfastjet_centralneutral_rho_branch does not exist!\n");
      exit(1);
    }
    evt_fixgridfastjet_centralneutral_rho_isLoaded = true;
  }
  return evt_fixgridfastjet_centralneutral_rho_;
}

const float &CMS3::evt_kfactor() {
  if (not evt_kfactor_isLoaded) {
    if (evt_kfactor_branch != 0) {
      evt_kfactor_branch->GetEntry(index);
    } else {
      printf("branch evt_kfactor_branch does not exist!\n");
      exit(1);
    }
    evt_kfactor_isLoaded = true;
  }
  return evt_kfactor_;
}

const float &CMS3::evt_scale1fb() {
  if (not evt_scale1fb_isLoaded) {
    if (evt_scale1fb_branch != 0) {
      evt_scale1fb_branch->GetEntry(index);
    } else {
      printf("branch evt_scale1fb_branch does not exist!\n");
      exit(1);
    }
    evt_scale1fb_isLoaded = true;
  }
  return evt_scale1fb_;
}

const float &CMS3::evt_xsec_excl() {
  if (not evt_xsec_excl_isLoaded) {
    if (evt_xsec_excl_branch != 0) {
      evt_xsec_excl_branch->GetEntry(index);
    } else {
      printf("branch evt_xsec_excl_branch does not exist!\n");
      exit(1);
    }
    evt_xsec_excl_isLoaded = true;
  }
  return evt_xsec_excl_;
}

const float &CMS3::evt_xsec_incl() {
  if (not evt_xsec_incl_isLoaded) {
    if (evt_xsec_incl_branch != 0) {
      evt_xsec_incl_branch->GetEntry(index);
    } else {
      printf("branch evt_xsec_incl_branch does not exist!\n");
      exit(1);
    }
    evt_xsec_incl_isLoaded = true;
  }
  return evt_xsec_incl_;
}

const float &CMS3::genps_alphaQCD() {
  if (not genps_alphaQCD_isLoaded) {
    if (genps_alphaQCD_branch != 0) {
      genps_alphaQCD_branch->GetEntry(index);
    } else {
      printf("branch genps_alphaQCD_branch does not exist!\n");
      exit(1);
    }
    genps_alphaQCD_isLoaded = true;
  }
  return genps_alphaQCD_;
}

const float &CMS3::genps_pthat() {
  if (not genps_pthat_isLoaded) {
    if (genps_pthat_branch != 0) {
      genps_pthat_branch->GetEntry(index);
    } else {
      printf("branch genps_pthat_branch does not exist!\n");
      exit(1);
    }
    genps_pthat_isLoaded = true;
  }
  return genps_pthat_;
}

const float &CMS3::genps_qScale() {
  if (not genps_qScale_isLoaded) {
    if (genps_qScale_branch != 0) {
      genps_qScale_branch->GetEntry(index);
    } else {
      printf("branch genps_qScale_branch does not exist!\n");
      exit(1);
    }
    genps_qScale_isLoaded = true;
  }
  return genps_qScale_;
}

const float &CMS3::genps_weight() {
  if (not genps_weight_isLoaded) {
    if (genps_weight_branch != 0) {
      genps_weight_branch->GetEntry(index);
    } else {
      printf("branch genps_weight_branch does not exist!\n");
      exit(1);
    }
    genps_weight_isLoaded = true;
  }
  return genps_weight_;
}

const float &CMS3::gen_sumEt() {
  if (not gen_sumEt_isLoaded) {
    if (gen_sumEt_branch != 0) {
      gen_sumEt_branch->GetEntry(index);
    } else {
      printf("branch gen_sumEt_branch does not exist!\n");
      exit(1);
    }
    gen_sumEt_isLoaded = true;
  }
  return gen_sumEt_;
}

const float &CMS3::pdfinfo_pdf1() {
  if (not pdfinfo_pdf1_isLoaded) {
    if (pdfinfo_pdf1_branch != 0) {
      pdfinfo_pdf1_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_pdf1_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_pdf1_isLoaded = true;
  }
  return pdfinfo_pdf1_;
}

const float &CMS3::pdfinfo_pdf2() {
  if (not pdfinfo_pdf2_isLoaded) {
    if (pdfinfo_pdf2_branch != 0) {
      pdfinfo_pdf2_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_pdf2_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_pdf2_isLoaded = true;
  }
  return pdfinfo_pdf2_;
}

const float &CMS3::pdfinfo_scale() {
  if (not pdfinfo_scale_isLoaded) {
    if (pdfinfo_scale_branch != 0) {
      pdfinfo_scale_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_scale_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_scale_isLoaded = true;
  }
  return pdfinfo_scale_;
}

const float &CMS3::pdfinfo_x1() {
  if (not pdfinfo_x1_isLoaded) {
    if (pdfinfo_x1_branch != 0) {
      pdfinfo_x1_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_x1_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_x1_isLoaded = true;
  }
  return pdfinfo_x1_;
}

const float &CMS3::pdfinfo_x2() {
  if (not pdfinfo_x2_isLoaded) {
    if (pdfinfo_x2_branch != 0) {
      pdfinfo_x2_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_x2_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_x2_isLoaded = true;
  }
  return pdfinfo_x2_;
}

const float &CMS3::evt_calomet() {
  if (not evt_calomet_isLoaded) {
    if (evt_calomet_branch != 0) {
      evt_calomet_branch->GetEntry(index);
    } else {
      printf("branch evt_calomet_branch does not exist!\n");
      exit(1);
    }
    evt_calomet_isLoaded = true;
  }
  return evt_calomet_;
}

const float &CMS3::evt_calometPhi() {
  if (not evt_calometPhi_isLoaded) {
    if (evt_calometPhi_branch != 0) {
      evt_calometPhi_branch->GetEntry(index);
    } else {
      printf("branch evt_calometPhi_branch does not exist!\n");
      exit(1);
    }
    evt_calometPhi_isLoaded = true;
  }
  return evt_calometPhi_;
}

const float &CMS3::evt_pfmet() {
  if (not evt_pfmet_isLoaded) {
    if (evt_pfmet_branch != 0) {
      evt_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_isLoaded = true;
  }
  return evt_pfmet_;
}

const float &CMS3::evt_pfmet_ElectronEnDown() {
  if (not evt_pfmet_ElectronEnDown_isLoaded) {
    if (evt_pfmet_ElectronEnDown_branch != 0) {
      evt_pfmet_ElectronEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_ElectronEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_ElectronEnDown_isLoaded = true;
  }
  return evt_pfmet_ElectronEnDown_;
}

const float &CMS3::evt_pfmet_ElectronEnUp() {
  if (not evt_pfmet_ElectronEnUp_isLoaded) {
    if (evt_pfmet_ElectronEnUp_branch != 0) {
      evt_pfmet_ElectronEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_ElectronEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_ElectronEnUp_isLoaded = true;
  }
  return evt_pfmet_ElectronEnUp_;
}

const float &CMS3::evt_pfmet_JetEnDown() {
  if (not evt_pfmet_JetEnDown_isLoaded) {
    if (evt_pfmet_JetEnDown_branch != 0) {
      evt_pfmet_JetEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetEnDown_isLoaded = true;
  }
  return evt_pfmet_JetEnDown_;
}

const float &CMS3::evt_pfmet_JetEnUp() {
  if (not evt_pfmet_JetEnUp_isLoaded) {
    if (evt_pfmet_JetEnUp_branch != 0) {
      evt_pfmet_JetEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetEnUp_isLoaded = true;
  }
  return evt_pfmet_JetEnUp_;
}

const float &CMS3::evt_pfmet_JetResDown() {
  if (not evt_pfmet_JetResDown_isLoaded) {
    if (evt_pfmet_JetResDown_branch != 0) {
      evt_pfmet_JetResDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetResDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetResDown_isLoaded = true;
  }
  return evt_pfmet_JetResDown_;
}

const float &CMS3::evt_pfmet_JetResUp() {
  if (not evt_pfmet_JetResUp_isLoaded) {
    if (evt_pfmet_JetResUp_branch != 0) {
      evt_pfmet_JetResUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_JetResUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_JetResUp_isLoaded = true;
  }
  return evt_pfmet_JetResUp_;
}

const float &CMS3::evt_pfmet_MuonEnDown() {
  if (not evt_pfmet_MuonEnDown_isLoaded) {
    if (evt_pfmet_MuonEnDown_branch != 0) {
      evt_pfmet_MuonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_MuonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_MuonEnDown_isLoaded = true;
  }
  return evt_pfmet_MuonEnDown_;
}

const float &CMS3::evt_pfmet_MuonEnUp() {
  if (not evt_pfmet_MuonEnUp_isLoaded) {
    if (evt_pfmet_MuonEnUp_branch != 0) {
      evt_pfmet_MuonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_MuonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_MuonEnUp_isLoaded = true;
  }
  return evt_pfmet_MuonEnUp_;
}

const float &CMS3::evt_pfmetPhi() {
  if (not evt_pfmetPhi_isLoaded) {
    if (evt_pfmetPhi_branch != 0) {
      evt_pfmetPhi_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_isLoaded = true;
  }
  return evt_pfmetPhi_;
}

const float &CMS3::evt_pfmetPhi_ElectronEnDown() {
  if (not evt_pfmetPhi_ElectronEnDown_isLoaded) {
    if (evt_pfmetPhi_ElectronEnDown_branch != 0) {
      evt_pfmetPhi_ElectronEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_ElectronEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_ElectronEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_ElectronEnDown_;
}

const float &CMS3::evt_pfmetPhi_ElectronEnUp() {
  if (not evt_pfmetPhi_ElectronEnUp_isLoaded) {
    if (evt_pfmetPhi_ElectronEnUp_branch != 0) {
      evt_pfmetPhi_ElectronEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_ElectronEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_ElectronEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_ElectronEnUp_;
}

const float &CMS3::evt_pfmetPhi_JetEnDown() {
  if (not evt_pfmetPhi_JetEnDown_isLoaded) {
    if (evt_pfmetPhi_JetEnDown_branch != 0) {
      evt_pfmetPhi_JetEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_JetEnDown_;
}

const float &CMS3::evt_pfmetPhi_JetEnUp() {
  if (not evt_pfmetPhi_JetEnUp_isLoaded) {
    if (evt_pfmetPhi_JetEnUp_branch != 0) {
      evt_pfmetPhi_JetEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_JetEnUp_;
}

const float &CMS3::evt_pfmetPhi_JetResDown() {
  if (not evt_pfmetPhi_JetResDown_isLoaded) {
    if (evt_pfmetPhi_JetResDown_branch != 0) {
      evt_pfmetPhi_JetResDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetResDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetResDown_isLoaded = true;
  }
  return evt_pfmetPhi_JetResDown_;
}

const float &CMS3::evt_pfmetPhi_JetResUp() {
  if (not evt_pfmetPhi_JetResUp_isLoaded) {
    if (evt_pfmetPhi_JetResUp_branch != 0) {
      evt_pfmetPhi_JetResUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_JetResUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_JetResUp_isLoaded = true;
  }
  return evt_pfmetPhi_JetResUp_;
}

const float &CMS3::evt_pfmetPhi_MuonEnDown() {
  if (not evt_pfmetPhi_MuonEnDown_isLoaded) {
    if (evt_pfmetPhi_MuonEnDown_branch != 0) {
      evt_pfmetPhi_MuonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_MuonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_MuonEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_MuonEnDown_;
}

const float &CMS3::evt_pfmetPhi_MuonEnUp() {
  if (not evt_pfmetPhi_MuonEnUp_isLoaded) {
    if (evt_pfmetPhi_MuonEnUp_branch != 0) {
      evt_pfmetPhi_MuonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_MuonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_MuonEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_MuonEnUp_;
}

const float &CMS3::evt_pfmetPhi_PhotonEnDown() {
  if (not evt_pfmetPhi_PhotonEnDown_isLoaded) {
    if (evt_pfmetPhi_PhotonEnDown_branch != 0) {
      evt_pfmetPhi_PhotonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_PhotonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_PhotonEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_PhotonEnDown_;
}

const float &CMS3::evt_pfmetPhi_PhotonEnUp() {
  if (not evt_pfmetPhi_PhotonEnUp_isLoaded) {
    if (evt_pfmetPhi_PhotonEnUp_branch != 0) {
      evt_pfmetPhi_PhotonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_PhotonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_PhotonEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_PhotonEnUp_;
}

const float &CMS3::evt_pfmetPhi_TauEnDown() {
  if (not evt_pfmetPhi_TauEnDown_isLoaded) {
    if (evt_pfmetPhi_TauEnDown_branch != 0) {
      evt_pfmetPhi_TauEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_TauEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_TauEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_TauEnDown_;
}

const float &CMS3::evt_pfmetPhi_TauEnUp() {
  if (not evt_pfmetPhi_TauEnUp_isLoaded) {
    if (evt_pfmetPhi_TauEnUp_branch != 0) {
      evt_pfmetPhi_TauEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_TauEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_TauEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_TauEnUp_;
}

const float &CMS3::evt_pfmetPhi_UnclusteredEnDown() {
  if (not evt_pfmetPhi_UnclusteredEnDown_isLoaded) {
    if (evt_pfmetPhi_UnclusteredEnDown_branch != 0) {
      evt_pfmetPhi_UnclusteredEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_UnclusteredEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_UnclusteredEnDown_isLoaded = true;
  }
  return evt_pfmetPhi_UnclusteredEnDown_;
}

const float &CMS3::evt_pfmetPhi_UnclusteredEnUp() {
  if (not evt_pfmetPhi_UnclusteredEnUp_isLoaded) {
    if (evt_pfmetPhi_UnclusteredEnUp_branch != 0) {
      evt_pfmetPhi_UnclusteredEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_UnclusteredEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_UnclusteredEnUp_isLoaded = true;
  }
  return evt_pfmetPhi_UnclusteredEnUp_;
}

const float &CMS3::evt_pfmetPhi_raw() {
  if (not evt_pfmetPhi_raw_isLoaded) {
    if (evt_pfmetPhi_raw_branch != 0) {
      evt_pfmetPhi_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetPhi_raw_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetPhi_raw_isLoaded = true;
  }
  return evt_pfmetPhi_raw_;
}

const float &CMS3::evt_pfmet_PhotonEnDown() {
  if (not evt_pfmet_PhotonEnDown_isLoaded) {
    if (evt_pfmet_PhotonEnDown_branch != 0) {
      evt_pfmet_PhotonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_PhotonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_PhotonEnDown_isLoaded = true;
  }
  return evt_pfmet_PhotonEnDown_;
}

const float &CMS3::evt_pfmet_PhotonEnUp() {
  if (not evt_pfmet_PhotonEnUp_isLoaded) {
    if (evt_pfmet_PhotonEnUp_branch != 0) {
      evt_pfmet_PhotonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_PhotonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_PhotonEnUp_isLoaded = true;
  }
  return evt_pfmet_PhotonEnUp_;
}

const float &CMS3::evt_pfmetSig() {
  if (not evt_pfmetSig_isLoaded) {
    if (evt_pfmetSig_branch != 0) {
      evt_pfmetSig_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetSig_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetSig_isLoaded = true;
  }
  return evt_pfmetSig_;
}

const float &CMS3::evt_pfmetSignificance() {
  if (not evt_pfmetSignificance_isLoaded) {
    if (evt_pfmetSignificance_branch != 0) {
      evt_pfmetSignificance_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmetSignificance_branch does not exist!\n");
      exit(1);
    }
    evt_pfmetSignificance_isLoaded = true;
  }
  return evt_pfmetSignificance_;
}

const float &CMS3::evt_pfmet_TauEnDown() {
  if (not evt_pfmet_TauEnDown_isLoaded) {
    if (evt_pfmet_TauEnDown_branch != 0) {
      evt_pfmet_TauEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_TauEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_TauEnDown_isLoaded = true;
  }
  return evt_pfmet_TauEnDown_;
}

const float &CMS3::evt_pfmet_TauEnUp() {
  if (not evt_pfmet_TauEnUp_isLoaded) {
    if (evt_pfmet_TauEnUp_branch != 0) {
      evt_pfmet_TauEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_TauEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_TauEnUp_isLoaded = true;
  }
  return evt_pfmet_TauEnUp_;
}

const float &CMS3::evt_pfmet_UnclusteredEnDown() {
  if (not evt_pfmet_UnclusteredEnDown_isLoaded) {
    if (evt_pfmet_UnclusteredEnDown_branch != 0) {
      evt_pfmet_UnclusteredEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_UnclusteredEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_UnclusteredEnDown_isLoaded = true;
  }
  return evt_pfmet_UnclusteredEnDown_;
}

const float &CMS3::evt_pfmet_UnclusteredEnUp() {
  if (not evt_pfmet_UnclusteredEnUp_isLoaded) {
    if (evt_pfmet_UnclusteredEnUp_branch != 0) {
      evt_pfmet_UnclusteredEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_UnclusteredEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_UnclusteredEnUp_isLoaded = true;
  }
  return evt_pfmet_UnclusteredEnUp_;
}

const float &CMS3::evt_pfmet_raw() {
  if (not evt_pfmet_raw_isLoaded) {
    if (evt_pfmet_raw_branch != 0) {
      evt_pfmet_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_pfmet_raw_branch does not exist!\n");
      exit(1);
    }
    evt_pfmet_raw_isLoaded = true;
  }
  return evt_pfmet_raw_;
}

const float &CMS3::evt_pfsumet() {
  if (not evt_pfsumet_isLoaded) {
    if (evt_pfsumet_branch != 0) {
      evt_pfsumet_branch->GetEntry(index);
    } else {
      printf("branch evt_pfsumet_branch does not exist!\n");
      exit(1);
    }
    evt_pfsumet_isLoaded = true;
  }
  return evt_pfsumet_;
}

const float &CMS3::evt_pfsumet_raw() {
  if (not evt_pfsumet_raw_isLoaded) {
    if (evt_pfsumet_raw_branch != 0) {
      evt_pfsumet_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_pfsumet_raw_branch does not exist!\n");
      exit(1);
    }
    evt_pfsumet_raw_isLoaded = true;
  }
  return evt_pfsumet_raw_;
}

const float &CMS3::gen_met() {
  if (not gen_met_isLoaded) {
    if (gen_met_branch != 0) {
      gen_met_branch->GetEntry(index);
    } else {
      printf("branch gen_met_branch does not exist!\n");
      exit(1);
    }
    gen_met_isLoaded = true;
  }
  return gen_met_;
}

const float &CMS3::gen_metPhi() {
  if (not gen_metPhi_isLoaded) {
    if (gen_metPhi_branch != 0) {
      gen_metPhi_branch->GetEntry(index);
    } else {
      printf("branch gen_metPhi_branch does not exist!\n");
      exit(1);
    }
    gen_metPhi_isLoaded = true;
  }
  return gen_metPhi_;
}

const float &CMS3::evt_puppi_calomet() {
  if (not evt_puppi_calomet_isLoaded) {
    if (evt_puppi_calomet_branch != 0) {
      evt_puppi_calomet_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_calomet_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_calomet_isLoaded = true;
  }
  return evt_puppi_calomet_;
}

const float &CMS3::evt_puppi_calometPhi() {
  if (not evt_puppi_calometPhi_isLoaded) {
    if (evt_puppi_calometPhi_branch != 0) {
      evt_puppi_calometPhi_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_calometPhi_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_calometPhi_isLoaded = true;
  }
  return evt_puppi_calometPhi_;
}

const float &CMS3::evt_puppi_pfmet() {
  if (not evt_puppi_pfmet_isLoaded) {
    if (evt_puppi_pfmet_branch != 0) {
      evt_puppi_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_isLoaded = true;
  }
  return evt_puppi_pfmet_;
}

const float &CMS3::evt_puppi_pfmet_ElectronEnDown() {
  if (not evt_puppi_pfmet_ElectronEnDown_isLoaded) {
    if (evt_puppi_pfmet_ElectronEnDown_branch != 0) {
      evt_puppi_pfmet_ElectronEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_ElectronEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_ElectronEnDown_isLoaded = true;
  }
  return evt_puppi_pfmet_ElectronEnDown_;
}

const float &CMS3::evt_puppi_pfmet_ElectronEnUp() {
  if (not evt_puppi_pfmet_ElectronEnUp_isLoaded) {
    if (evt_puppi_pfmet_ElectronEnUp_branch != 0) {
      evt_puppi_pfmet_ElectronEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_ElectronEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_ElectronEnUp_isLoaded = true;
  }
  return evt_puppi_pfmet_ElectronEnUp_;
}

const float &CMS3::evt_puppi_pfmet_JetEnDown() {
  if (not evt_puppi_pfmet_JetEnDown_isLoaded) {
    if (evt_puppi_pfmet_JetEnDown_branch != 0) {
      evt_puppi_pfmet_JetEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_JetEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_JetEnDown_isLoaded = true;
  }
  return evt_puppi_pfmet_JetEnDown_;
}

const float &CMS3::evt_puppi_pfmet_JetEnUp() {
  if (not evt_puppi_pfmet_JetEnUp_isLoaded) {
    if (evt_puppi_pfmet_JetEnUp_branch != 0) {
      evt_puppi_pfmet_JetEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_JetEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_JetEnUp_isLoaded = true;
  }
  return evt_puppi_pfmet_JetEnUp_;
}

const float &CMS3::evt_puppi_pfmet_JetResDown() {
  if (not evt_puppi_pfmet_JetResDown_isLoaded) {
    if (evt_puppi_pfmet_JetResDown_branch != 0) {
      evt_puppi_pfmet_JetResDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_JetResDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_JetResDown_isLoaded = true;
  }
  return evt_puppi_pfmet_JetResDown_;
}

const float &CMS3::evt_puppi_pfmet_JetResUp() {
  if (not evt_puppi_pfmet_JetResUp_isLoaded) {
    if (evt_puppi_pfmet_JetResUp_branch != 0) {
      evt_puppi_pfmet_JetResUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_JetResUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_JetResUp_isLoaded = true;
  }
  return evt_puppi_pfmet_JetResUp_;
}

const float &CMS3::evt_puppi_pfmet_MuonEnDown() {
  if (not evt_puppi_pfmet_MuonEnDown_isLoaded) {
    if (evt_puppi_pfmet_MuonEnDown_branch != 0) {
      evt_puppi_pfmet_MuonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_MuonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_MuonEnDown_isLoaded = true;
  }
  return evt_puppi_pfmet_MuonEnDown_;
}

const float &CMS3::evt_puppi_pfmet_MuonEnUp() {
  if (not evt_puppi_pfmet_MuonEnUp_isLoaded) {
    if (evt_puppi_pfmet_MuonEnUp_branch != 0) {
      evt_puppi_pfmet_MuonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_MuonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_MuonEnUp_isLoaded = true;
  }
  return evt_puppi_pfmet_MuonEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi() {
  if (not evt_puppi_pfmetPhi_isLoaded) {
    if (evt_puppi_pfmetPhi_branch != 0) {
      evt_puppi_pfmetPhi_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_;
}

const float &CMS3::evt_puppi_pfmetPhi_ElectronEnDown() {
  if (not evt_puppi_pfmetPhi_ElectronEnDown_isLoaded) {
    if (evt_puppi_pfmetPhi_ElectronEnDown_branch != 0) {
      evt_puppi_pfmetPhi_ElectronEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_ElectronEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_ElectronEnDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_ElectronEnDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_ElectronEnUp() {
  if (not evt_puppi_pfmetPhi_ElectronEnUp_isLoaded) {
    if (evt_puppi_pfmetPhi_ElectronEnUp_branch != 0) {
      evt_puppi_pfmetPhi_ElectronEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_ElectronEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_ElectronEnUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_ElectronEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_JetEnDown() {
  if (not evt_puppi_pfmetPhi_JetEnDown_isLoaded) {
    if (evt_puppi_pfmetPhi_JetEnDown_branch != 0) {
      evt_puppi_pfmetPhi_JetEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_JetEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_JetEnDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_JetEnDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_JetEnUp() {
  if (not evt_puppi_pfmetPhi_JetEnUp_isLoaded) {
    if (evt_puppi_pfmetPhi_JetEnUp_branch != 0) {
      evt_puppi_pfmetPhi_JetEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_JetEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_JetEnUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_JetEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_JetResDown() {
  if (not evt_puppi_pfmetPhi_JetResDown_isLoaded) {
    if (evt_puppi_pfmetPhi_JetResDown_branch != 0) {
      evt_puppi_pfmetPhi_JetResDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_JetResDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_JetResDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_JetResDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_JetResUp() {
  if (not evt_puppi_pfmetPhi_JetResUp_isLoaded) {
    if (evt_puppi_pfmetPhi_JetResUp_branch != 0) {
      evt_puppi_pfmetPhi_JetResUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_JetResUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_JetResUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_JetResUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_MuonEnDown() {
  if (not evt_puppi_pfmetPhi_MuonEnDown_isLoaded) {
    if (evt_puppi_pfmetPhi_MuonEnDown_branch != 0) {
      evt_puppi_pfmetPhi_MuonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_MuonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_MuonEnDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_MuonEnDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_MuonEnUp() {
  if (not evt_puppi_pfmetPhi_MuonEnUp_isLoaded) {
    if (evt_puppi_pfmetPhi_MuonEnUp_branch != 0) {
      evt_puppi_pfmetPhi_MuonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_MuonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_MuonEnUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_MuonEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_PhotonEnDown() {
  if (not evt_puppi_pfmetPhi_PhotonEnDown_isLoaded) {
    if (evt_puppi_pfmetPhi_PhotonEnDown_branch != 0) {
      evt_puppi_pfmetPhi_PhotonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_PhotonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_PhotonEnDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_PhotonEnDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_PhotonEnUp() {
  if (not evt_puppi_pfmetPhi_PhotonEnUp_isLoaded) {
    if (evt_puppi_pfmetPhi_PhotonEnUp_branch != 0) {
      evt_puppi_pfmetPhi_PhotonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_PhotonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_PhotonEnUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_PhotonEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_TauEnDown() {
  if (not evt_puppi_pfmetPhi_TauEnDown_isLoaded) {
    if (evt_puppi_pfmetPhi_TauEnDown_branch != 0) {
      evt_puppi_pfmetPhi_TauEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_TauEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_TauEnDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_TauEnDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_TauEnUp() {
  if (not evt_puppi_pfmetPhi_TauEnUp_isLoaded) {
    if (evt_puppi_pfmetPhi_TauEnUp_branch != 0) {
      evt_puppi_pfmetPhi_TauEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_TauEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_TauEnUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_TauEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_UnclusteredEnDown() {
  if (not evt_puppi_pfmetPhi_UnclusteredEnDown_isLoaded) {
    if (evt_puppi_pfmetPhi_UnclusteredEnDown_branch != 0) {
      evt_puppi_pfmetPhi_UnclusteredEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_UnclusteredEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_UnclusteredEnDown_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_UnclusteredEnDown_;
}

const float &CMS3::evt_puppi_pfmetPhi_UnclusteredEnUp() {
  if (not evt_puppi_pfmetPhi_UnclusteredEnUp_isLoaded) {
    if (evt_puppi_pfmetPhi_UnclusteredEnUp_branch != 0) {
      evt_puppi_pfmetPhi_UnclusteredEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_UnclusteredEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_UnclusteredEnUp_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_UnclusteredEnUp_;
}

const float &CMS3::evt_puppi_pfmetPhi_raw() {
  if (not evt_puppi_pfmetPhi_raw_isLoaded) {
    if (evt_puppi_pfmetPhi_raw_branch != 0) {
      evt_puppi_pfmetPhi_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetPhi_raw_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetPhi_raw_isLoaded = true;
  }
  return evt_puppi_pfmetPhi_raw_;
}

const float &CMS3::evt_puppi_pfmet_PhotonEnDown() {
  if (not evt_puppi_pfmet_PhotonEnDown_isLoaded) {
    if (evt_puppi_pfmet_PhotonEnDown_branch != 0) {
      evt_puppi_pfmet_PhotonEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_PhotonEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_PhotonEnDown_isLoaded = true;
  }
  return evt_puppi_pfmet_PhotonEnDown_;
}

const float &CMS3::evt_puppi_pfmet_PhotonEnUp() {
  if (not evt_puppi_pfmet_PhotonEnUp_isLoaded) {
    if (evt_puppi_pfmet_PhotonEnUp_branch != 0) {
      evt_puppi_pfmet_PhotonEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_PhotonEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_PhotonEnUp_isLoaded = true;
  }
  return evt_puppi_pfmet_PhotonEnUp_;
}

const float &CMS3::evt_puppi_pfmetSig() {
  if (not evt_puppi_pfmetSig_isLoaded) {
    if (evt_puppi_pfmetSig_branch != 0) {
      evt_puppi_pfmetSig_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetSig_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetSig_isLoaded = true;
  }
  return evt_puppi_pfmetSig_;
}

const float &CMS3::evt_puppi_pfmetSignificance() {
  if (not evt_puppi_pfmetSignificance_isLoaded) {
    if (evt_puppi_pfmetSignificance_branch != 0) {
      evt_puppi_pfmetSignificance_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmetSignificance_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmetSignificance_isLoaded = true;
  }
  return evt_puppi_pfmetSignificance_;
}

const float &CMS3::evt_puppi_pfmet_TauEnDown() {
  if (not evt_puppi_pfmet_TauEnDown_isLoaded) {
    if (evt_puppi_pfmet_TauEnDown_branch != 0) {
      evt_puppi_pfmet_TauEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_TauEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_TauEnDown_isLoaded = true;
  }
  return evt_puppi_pfmet_TauEnDown_;
}

const float &CMS3::evt_puppi_pfmet_TauEnUp() {
  if (not evt_puppi_pfmet_TauEnUp_isLoaded) {
    if (evt_puppi_pfmet_TauEnUp_branch != 0) {
      evt_puppi_pfmet_TauEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_TauEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_TauEnUp_isLoaded = true;
  }
  return evt_puppi_pfmet_TauEnUp_;
}

const float &CMS3::evt_puppi_pfmet_UnclusteredEnDown() {
  if (not evt_puppi_pfmet_UnclusteredEnDown_isLoaded) {
    if (evt_puppi_pfmet_UnclusteredEnDown_branch != 0) {
      evt_puppi_pfmet_UnclusteredEnDown_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_UnclusteredEnDown_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_UnclusteredEnDown_isLoaded = true;
  }
  return evt_puppi_pfmet_UnclusteredEnDown_;
}

const float &CMS3::evt_puppi_pfmet_UnclusteredEnUp() {
  if (not evt_puppi_pfmet_UnclusteredEnUp_isLoaded) {
    if (evt_puppi_pfmet_UnclusteredEnUp_branch != 0) {
      evt_puppi_pfmet_UnclusteredEnUp_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_UnclusteredEnUp_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_UnclusteredEnUp_isLoaded = true;
  }
  return evt_puppi_pfmet_UnclusteredEnUp_;
}

const float &CMS3::evt_puppi_pfmet_raw() {
  if (not evt_puppi_pfmet_raw_isLoaded) {
    if (evt_puppi_pfmet_raw_branch != 0) {
      evt_puppi_pfmet_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfmet_raw_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfmet_raw_isLoaded = true;
  }
  return evt_puppi_pfmet_raw_;
}

const float &CMS3::evt_puppi_pfsumet() {
  if (not evt_puppi_pfsumet_isLoaded) {
    if (evt_puppi_pfsumet_branch != 0) {
      evt_puppi_pfsumet_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfsumet_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfsumet_isLoaded = true;
  }
  return evt_puppi_pfsumet_;
}

const float &CMS3::evt_puppi_pfsumet_raw() {
  if (not evt_puppi_pfsumet_raw_isLoaded) {
    if (evt_puppi_pfsumet_raw_branch != 0) {
      evt_puppi_pfsumet_raw_branch->GetEntry(index);
    } else {
      printf("branch evt_puppi_pfsumet_raw_branch does not exist!\n");
      exit(1);
    }
    evt_puppi_pfsumet_raw_isLoaded = true;
  }
  return evt_puppi_pfsumet_raw_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_mc_motherp4() {
  if (not els_mc_motherp4_isLoaded) {
    if (els_mc_motherp4_branch != 0) {
      els_mc_motherp4_branch->GetEntry(index);
    } else {
      printf("branch els_mc_motherp4_branch does not exist!\n");
      exit(1);
    }
    els_mc_motherp4_isLoaded = true;
  }
  return els_mc_motherp4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_mc_p4() {
  if (not els_mc_p4_isLoaded) {
    if (els_mc_p4_branch != 0) {
      els_mc_p4_branch->GetEntry(index);
    } else {
      printf("branch els_mc_p4_branch does not exist!\n");
      exit(1);
    }
    els_mc_p4_isLoaded = true;
  }
  return els_mc_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_mc_motherp4() {
  if (not mus_mc_motherp4_isLoaded) {
    if (mus_mc_motherp4_branch != 0) {
      mus_mc_motherp4_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_motherp4_branch does not exist!\n");
      exit(1);
    }
    mus_mc_motherp4_isLoaded = true;
  }
  return mus_mc_motherp4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_mc_p4() {
  if (not mus_mc_p4_isLoaded) {
    if (mus_mc_p4_branch != 0) {
      mus_mc_p4_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_p4_branch does not exist!\n");
      exit(1);
    }
    mus_mc_p4_isLoaded = true;
  }
  return mus_mc_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::pfjets_mc_p4() {
  if (not pfjets_mc_p4_isLoaded) {
    if (pfjets_mc_p4_branch != 0) {
      pfjets_mc_p4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_mc_p4_branch does not exist!\n");
      exit(1);
    }
    pfjets_mc_p4_isLoaded = true;
  }
  return pfjets_mc_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::photons_mc_motherp4() {
  if (not photons_mc_motherp4_isLoaded) {
    if (photons_mc_motherp4_branch != 0) {
      photons_mc_motherp4_branch->GetEntry(index);
    } else {
      printf("branch photons_mc_motherp4_branch does not exist!\n");
      exit(1);
    }
    photons_mc_motherp4_isLoaded = true;
  }
  return photons_mc_motherp4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::photons_mc_p4() {
  if (not photons_mc_p4_isLoaded) {
    if (photons_mc_p4_branch != 0) {
      photons_mc_p4_branch->GetEntry(index);
    } else {
      printf("branch photons_mc_p4_branch does not exist!\n");
      exit(1);
    }
    photons_mc_p4_isLoaded = true;
  }
  return photons_mc_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_mc_patMatch_p4() {
  if (not els_mc_patMatch_p4_isLoaded) {
    if (els_mc_patMatch_p4_branch != 0) {
      els_mc_patMatch_p4_branch->GetEntry(index);
    } else {
      printf("branch els_mc_patMatch_p4_branch does not exist!\n");
      exit(1);
    }
    els_mc_patMatch_p4_isLoaded = true;
  }
  return els_mc_patMatch_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_p4() {
  if (not els_p4_isLoaded) {
    if (els_p4_branch != 0) {
      els_p4_branch->GetEntry(index);
    } else {
      printf("branch els_p4_branch does not exist!\n");
      exit(1);
    }
    els_p4_isLoaded = true;
  }
  return els_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_p4In() {
  if (not els_p4In_isLoaded) {
    if (els_p4In_branch != 0) {
      els_p4In_branch->GetEntry(index);
    } else {
      printf("branch els_p4In_branch does not exist!\n");
      exit(1);
    }
    els_p4In_isLoaded = true;
  }
  return els_p4In_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_p4Out() {
  if (not els_p4Out_isLoaded) {
    if (els_p4Out_branch != 0) {
      els_p4Out_branch->GetEntry(index);
    } else {
      printf("branch els_p4Out_branch does not exist!\n");
      exit(1);
    }
    els_p4Out_isLoaded = true;
  }
  return els_p4Out_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_trk_p4() {
  if (not els_trk_p4_isLoaded) {
    if (els_trk_p4_branch != 0) {
      els_trk_p4_branch->GetEntry(index);
    } else {
      printf("branch els_trk_p4_branch does not exist!\n");
      exit(1);
    }
    els_trk_p4_isLoaded = true;
  }
  return els_trk_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_trk_vertex_p4() {
  if (not els_trk_vertex_p4_isLoaded) {
    if (els_trk_vertex_p4_branch != 0) {
      els_trk_vertex_p4_branch->GetEntry(index);
    } else {
      printf("branch els_trk_vertex_p4_branch does not exist!\n");
      exit(1);
    }
    els_trk_vertex_p4_isLoaded = true;
  }
  return els_trk_vertex_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::els_vertex_p4() {
  if (not els_vertex_p4_isLoaded) {
    if (els_vertex_p4_branch != 0) {
      els_vertex_p4_branch->GetEntry(index);
    } else {
      printf("branch els_vertex_p4_branch does not exist!\n");
      exit(1);
    }
    els_vertex_p4_isLoaded = true;
  }
  return els_vertex_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genjets_p4NoMuNoNu() {
  if (not genjets_p4NoMuNoNu_isLoaded) {
    if (genjets_p4NoMuNoNu_branch != 0) {
      genjets_p4NoMuNoNu_branch->GetEntry(index);
    } else {
      printf("branch genjets_p4NoMuNoNu_branch does not exist!\n");
      exit(1);
    }
    genjets_p4NoMuNoNu_isLoaded = true;
  }
  return genjets_p4NoMuNoNu_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genps_p4() {
  if (not genps_p4_isLoaded) {
    if (genps_p4_branch != 0) {
      genps_p4_branch->GetEntry(index);
    } else {
      printf("branch genps_p4_branch does not exist!\n");
      exit(1);
    }
    genps_p4_isLoaded = true;
  }
  return genps_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::hyp_ll_p4() {
  if (not hyp_ll_p4_isLoaded) {
    if (hyp_ll_p4_branch != 0) {
      hyp_ll_p4_branch->GetEntry(index);
    } else {
      printf("branch hyp_ll_p4_branch does not exist!\n");
      exit(1);
    }
    hyp_ll_p4_isLoaded = true;
  }
  return hyp_ll_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::hyp_lt_p4() {
  if (not hyp_lt_p4_isLoaded) {
    if (hyp_lt_p4_branch != 0) {
      hyp_lt_p4_branch->GetEntry(index);
    } else {
      printf("branch hyp_lt_p4_branch does not exist!\n");
      exit(1);
    }
    hyp_lt_p4_isLoaded = true;
  }
  return hyp_lt_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::hyp_p4() {
  if (not hyp_p4_isLoaded) {
    if (hyp_p4_branch != 0) {
      hyp_p4_branch->GetEntry(index);
    } else {
      printf("branch hyp_p4_branch does not exist!\n");
      exit(1);
    }
    hyp_p4_isLoaded = true;
  }
  return hyp_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::isotracks_p4() {
  if (not isotracks_p4_isLoaded) {
    if (isotracks_p4_branch != 0) {
      isotracks_p4_branch->GetEntry(index);
    } else {
      printf("branch isotracks_p4_branch does not exist!\n");
      exit(1);
    }
    isotracks_p4_isLoaded = true;
  }
  return isotracks_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_bfit_p4() {
  if (not mus_bfit_p4_isLoaded) {
    if (mus_bfit_p4_branch != 0) {
      mus_bfit_p4_branch->GetEntry(index);
    } else {
      printf("branch mus_bfit_p4_branch does not exist!\n");
      exit(1);
    }
    mus_bfit_p4_isLoaded = true;
  }
  return mus_bfit_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_gfit_p4() {
  if (not mus_gfit_p4_isLoaded) {
    if (mus_gfit_p4_branch != 0) {
      mus_gfit_p4_branch->GetEntry(index);
    } else {
      printf("branch mus_gfit_p4_branch does not exist!\n");
      exit(1);
    }
    mus_gfit_p4_isLoaded = true;
  }
  return mus_gfit_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_mc_patMatch_p4() {
  if (not mus_mc_patMatch_p4_isLoaded) {
    if (mus_mc_patMatch_p4_branch != 0) {
      mus_mc_patMatch_p4_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_patMatch_p4_branch does not exist!\n");
      exit(1);
    }
    mus_mc_patMatch_p4_isLoaded = true;
  }
  return mus_mc_patMatch_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_p4() {
  if (not mus_p4_isLoaded) {
    if (mus_p4_branch != 0) {
      mus_p4_branch->GetEntry(index);
    } else {
      printf("branch mus_p4_branch does not exist!\n");
      exit(1);
    }
    mus_p4_isLoaded = true;
  }
  return mus_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_pfp4() {
  if (not mus_pfp4_isLoaded) {
    if (mus_pfp4_branch != 0) {
      mus_pfp4_branch->GetEntry(index);
    } else {
      printf("branch mus_pfp4_branch does not exist!\n");
      exit(1);
    }
    mus_pfp4_isLoaded = true;
  }
  return mus_pfp4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::mus_trk_p4() {
  if (not mus_trk_p4_isLoaded) {
    if (mus_trk_p4_branch != 0) {
      mus_trk_p4_branch->GetEntry(index);
    } else {
      printf("branch mus_trk_p4_branch does not exist!\n");
      exit(1);
    }
    mus_trk_p4_isLoaded = true;
  }
  return mus_trk_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::pfcands_p4() {
  if (not pfcands_p4_isLoaded) {
    if (pfcands_p4_branch != 0) {
      pfcands_p4_branch->GetEntry(index);
    } else {
      printf("branch pfcands_p4_branch does not exist!\n");
      exit(1);
    }
    pfcands_p4_isLoaded = true;
  }
  return pfcands_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::pfjets_p4() {
  if (not pfjets_p4_isLoaded) {
    if (pfjets_p4_branch != 0) {
      pfjets_p4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_p4_branch does not exist!\n");
      exit(1);
    }
    pfjets_p4_isLoaded = true;
  }
  return pfjets_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::pfjets_puppi_p4() {
  if (not pfjets_puppi_p4_isLoaded) {
    if (pfjets_puppi_p4_branch != 0) {
      pfjets_puppi_p4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_p4_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_p4_isLoaded = true;
  }
  return pfjets_puppi_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::taus_pf_p4() {
  if (not taus_pf_p4_isLoaded) {
    if (taus_pf_p4_branch != 0) {
      taus_pf_p4_branch->GetEntry(index);
    } else {
      printf("branch taus_pf_p4_branch does not exist!\n");
      exit(1);
    }
    taus_pf_p4_isLoaded = true;
  }
  return taus_pf_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::photons_p4() {
  if (not photons_p4_isLoaded) {
    if (photons_p4_branch != 0) {
      photons_p4_branch->GetEntry(index);
    } else {
      printf("branch photons_p4_branch does not exist!\n");
      exit(1);
    }
    photons_p4_isLoaded = true;
  }
  return photons_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::svs_p4() {
  if (not svs_p4_isLoaded) {
    if (svs_p4_branch != 0) {
      svs_p4_branch->GetEntry(index);
    } else {
      printf("branch svs_p4_branch does not exist!\n");
      exit(1);
    }
    svs_p4_isLoaded = true;
  }
  return svs_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::svs_position() {
  if (not svs_position_isLoaded) {
    if (svs_position_branch != 0) {
      svs_position_branch->GetEntry(index);
    } else {
      printf("branch svs_position_branch does not exist!\n");
      exit(1);
    }
    svs_position_isLoaded = true;
  }
  return svs_position_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak8jets_p4() {
  if (not ak8jets_p4_isLoaded) {
    if (ak8jets_p4_branch != 0) {
      ak8jets_p4_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_p4_branch does not exist!\n");
      exit(1);
    }
    ak8jets_p4_isLoaded = true;
  }
  return ak8jets_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak8jets_softdropPuppiSubjet1() {
  if (not ak8jets_softdropPuppiSubjet1_isLoaded) {
    if (ak8jets_softdropPuppiSubjet1_branch != 0) {
      ak8jets_softdropPuppiSubjet1_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_softdropPuppiSubjet1_branch does not exist!\n");
      exit(1);
    }
    ak8jets_softdropPuppiSubjet1_isLoaded = true;
  }
  return ak8jets_softdropPuppiSubjet1_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak8jets_softdropPuppiSubjet2() {
  if (not ak8jets_softdropPuppiSubjet2_isLoaded) {
    if (ak8jets_softdropPuppiSubjet2_branch != 0) {
      ak8jets_softdropPuppiSubjet2_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_softdropPuppiSubjet2_branch does not exist!\n");
      exit(1);
    }
    ak8jets_softdropPuppiSubjet2_isLoaded = true;
  }
  return ak8jets_softdropPuppiSubjet2_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::vtxs_position() {
  if (not vtxs_position_isLoaded) {
    if (vtxs_position_branch != 0) {
      vtxs_position_branch->GetEntry(index);
    } else {
      printf("branch vtxs_position_branch does not exist!\n");
      exit(1);
    }
    vtxs_position_isLoaded = true;
  }
  return vtxs_position_;
}

const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::genps_lepdaughter_p4() {
  if (not genps_lepdaughter_p4_isLoaded) {
    if (genps_lepdaughter_p4_branch != 0) {
      genps_lepdaughter_p4_branch->GetEntry(index);
    } else {
      printf("branch genps_lepdaughter_p4_branch does not exist!\n");
      exit(1);
    }
    genps_lepdaughter_p4_isLoaded = true;
  }
  return genps_lepdaughter_p4_;
}

const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::pfjets_pfcandmup4() {
  if (not pfjets_pfcandmup4_isLoaded) {
    if (pfjets_pfcandmup4_branch != 0) {
      pfjets_pfcandmup4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfcandmup4_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfcandmup4_isLoaded = true;
  }
  return pfjets_pfcandmup4_;
}

const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::pfjets_puppi_pfcandmup4() {
  if (not pfjets_puppi_pfcandmup4_isLoaded) {
    if (pfjets_puppi_pfcandmup4_branch != 0) {
      pfjets_puppi_pfcandmup4_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_pfcandmup4_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_pfcandmup4_isLoaded = true;
  }
  return pfjets_puppi_pfcandmup4_;
}

const vector<float> &CMS3::els_mc3dr() {
  if (not els_mc3dr_isLoaded) {
    if (els_mc3dr_branch != 0) {
      els_mc3dr_branch->GetEntry(index);
    } else {
      printf("branch els_mc3dr_branch does not exist!\n");
      exit(1);
    }
    els_mc3dr_isLoaded = true;
  }
  return els_mc3dr_;
}

const vector<float> &CMS3::els_mcdr() {
  if (not els_mcdr_isLoaded) {
    if (els_mcdr_branch != 0) {
      els_mcdr_branch->GetEntry(index);
    } else {
      printf("branch els_mcdr_branch does not exist!\n");
      exit(1);
    }
    els_mcdr_isLoaded = true;
  }
  return els_mcdr_;
}

const vector<float> &CMS3::mus_mc3dr() {
  if (not mus_mc3dr_isLoaded) {
    if (mus_mc3dr_branch != 0) {
      mus_mc3dr_branch->GetEntry(index);
    } else {
      printf("branch mus_mc3dr_branch does not exist!\n");
      exit(1);
    }
    mus_mc3dr_isLoaded = true;
  }
  return mus_mc3dr_;
}

const vector<float> &CMS3::mus_mcdr() {
  if (not mus_mcdr_isLoaded) {
    if (mus_mcdr_branch != 0) {
      mus_mcdr_branch->GetEntry(index);
    } else {
      printf("branch mus_mcdr_branch does not exist!\n");
      exit(1);
    }
    mus_mcdr_isLoaded = true;
  }
  return mus_mcdr_;
}

const vector<float> &CMS3::pfjets_mc3dr() {
  if (not pfjets_mc3dr_isLoaded) {
    if (pfjets_mc3dr_branch != 0) {
      pfjets_mc3dr_branch->GetEntry(index);
    } else {
      printf("branch pfjets_mc3dr_branch does not exist!\n");
      exit(1);
    }
    pfjets_mc3dr_isLoaded = true;
  }
  return pfjets_mc3dr_;
}

const vector<float> &CMS3::pfjets_mcdr() {
  if (not pfjets_mcdr_isLoaded) {
    if (pfjets_mcdr_branch != 0) {
      pfjets_mcdr_branch->GetEntry(index);
    } else {
      printf("branch pfjets_mcdr_branch does not exist!\n");
      exit(1);
    }
    pfjets_mcdr_isLoaded = true;
  }
  return pfjets_mcdr_;
}

const vector<float> &CMS3::photons_mc3dr() {
  if (not photons_mc3dr_isLoaded) {
    if (photons_mc3dr_branch != 0) {
      photons_mc3dr_branch->GetEntry(index);
    } else {
      printf("branch photons_mc3dr_branch does not exist!\n");
      exit(1);
    }
    photons_mc3dr_isLoaded = true;
  }
  return photons_mc3dr_;
}

const vector<float> &CMS3::photons_mcdr() {
  if (not photons_mcdr_isLoaded) {
    if (photons_mcdr_branch != 0) {
      photons_mcdr_branch->GetEntry(index);
    } else {
      printf("branch photons_mcdr_branch does not exist!\n");
      exit(1);
    }
    photons_mcdr_isLoaded = true;
  }
  return photons_mcdr_;
}

const vector<float> &CMS3::els_VIDNonTrigMvaValue() {
  if (not els_VIDNonTrigMvaValue_isLoaded) {
    if (els_VIDNonTrigMvaValue_branch != 0) {
      els_VIDNonTrigMvaValue_branch->GetEntry(index);
    } else {
      printf("branch els_VIDNonTrigMvaValue_branch does not exist!\n");
      exit(1);
    }
    els_VIDNonTrigMvaValue_isLoaded = true;
  }
  return els_VIDNonTrigMvaValue_;
}

const vector<float> &CMS3::els_VIDSpring16GPMvaValue() {
  if (not els_VIDSpring16GPMvaValue_isLoaded) {
    if (els_VIDSpring16GPMvaValue_branch != 0) {
      els_VIDSpring16GPMvaValue_branch->GetEntry(index);
    } else {
      printf("branch els_VIDSpring16GPMvaValue_branch does not exist!\n");
      exit(1);
    }
    els_VIDSpring16GPMvaValue_isLoaded = true;
  }
  return els_VIDSpring16GPMvaValue_;
}

const vector<float> &CMS3::els_VIDSpring16HZZMvaValue() {
  if (not els_VIDSpring16HZZMvaValue_isLoaded) {
    if (els_VIDSpring16HZZMvaValue_branch != 0) {
      els_VIDSpring16HZZMvaValue_branch->GetEntry(index);
    } else {
      printf("branch els_VIDSpring16HZZMvaValue_branch does not exist!\n");
      exit(1);
    }
    els_VIDSpring16HZZMvaValue_isLoaded = true;
  }
  return els_VIDSpring16HZZMvaValue_;
}

const vector<float> &CMS3::els_VIDTrigMvaValue() {
  if (not els_VIDTrigMvaValue_isLoaded) {
    if (els_VIDTrigMvaValue_branch != 0) {
      els_VIDTrigMvaValue_branch->GetEntry(index);
    } else {
      printf("branch els_VIDTrigMvaValue_branch does not exist!\n");
      exit(1);
    }
    els_VIDTrigMvaValue_isLoaded = true;
  }
  return els_VIDTrigMvaValue_;
}

const vector<float> &CMS3::els_chi2() {
  if (not els_chi2_isLoaded) {
    if (els_chi2_branch != 0) {
      els_chi2_branch->GetEntry(index);
    } else {
      printf("branch els_chi2_branch does not exist!\n");
      exit(1);
    }
    els_chi2_isLoaded = true;
  }
  return els_chi2_;
}

const vector<float> &CMS3::els_ckf_chi2() {
  if (not els_ckf_chi2_isLoaded) {
    if (els_ckf_chi2_branch != 0) {
      els_ckf_chi2_branch->GetEntry(index);
    } else {
      printf("branch els_ckf_chi2_branch does not exist!\n");
      exit(1);
    }
    els_ckf_chi2_isLoaded = true;
  }
  return els_ckf_chi2_;
}

const vector<float> &CMS3::els_ckf_ndof() {
  if (not els_ckf_ndof_isLoaded) {
    if (els_ckf_ndof_branch != 0) {
      els_ckf_ndof_branch->GetEntry(index);
    } else {
      printf("branch els_ckf_ndof_branch does not exist!\n");
      exit(1);
    }
    els_ckf_ndof_isLoaded = true;
  }
  return els_ckf_ndof_;
}

const vector<float> &CMS3::els_conv_vtx_prob() {
  if (not els_conv_vtx_prob_isLoaded) {
    if (els_conv_vtx_prob_branch != 0) {
      els_conv_vtx_prob_branch->GetEntry(index);
    } else {
      printf("branch els_conv_vtx_prob_branch does not exist!\n");
      exit(1);
    }
    els_conv_vtx_prob_isLoaded = true;
  }
  return els_conv_vtx_prob_;
}

const vector<float> &CMS3::els_d0Err() {
  if (not els_d0Err_isLoaded) {
    if (els_d0Err_branch != 0) {
      els_d0Err_branch->GetEntry(index);
    } else {
      printf("branch els_d0Err_branch does not exist!\n");
      exit(1);
    }
    els_d0Err_isLoaded = true;
  }
  return els_d0Err_;
}

const vector<float> &CMS3::els_dEtaIn() {
  if (not els_dEtaIn_isLoaded) {
    if (els_dEtaIn_branch != 0) {
      els_dEtaIn_branch->GetEntry(index);
    } else {
      printf("branch els_dEtaIn_branch does not exist!\n");
      exit(1);
    }
    els_dEtaIn_isLoaded = true;
  }
  return els_dEtaIn_;
}

const vector<float> &CMS3::els_dEtaOut() {
  if (not els_dEtaOut_isLoaded) {
    if (els_dEtaOut_branch != 0) {
      els_dEtaOut_branch->GetEntry(index);
    } else {
      printf("branch els_dEtaOut_branch does not exist!\n");
      exit(1);
    }
    els_dEtaOut_isLoaded = true;
  }
  return els_dEtaOut_;
}

const vector<float> &CMS3::els_dPhiIn() {
  if (not els_dPhiIn_isLoaded) {
    if (els_dPhiIn_branch != 0) {
      els_dPhiIn_branch->GetEntry(index);
    } else {
      printf("branch els_dPhiIn_branch does not exist!\n");
      exit(1);
    }
    els_dPhiIn_isLoaded = true;
  }
  return els_dPhiIn_;
}

const vector<float> &CMS3::els_dPhiOut() {
  if (not els_dPhiOut_isLoaded) {
    if (els_dPhiOut_branch != 0) {
      els_dPhiOut_branch->GetEntry(index);
    } else {
      printf("branch els_dPhiOut_branch does not exist!\n");
      exit(1);
    }
    els_dPhiOut_isLoaded = true;
  }
  return els_dPhiOut_;
}

const vector<float> &CMS3::els_dxyPV() {
  if (not els_dxyPV_isLoaded) {
    if (els_dxyPV_branch != 0) {
      els_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch els_dxyPV_branch does not exist!\n");
      exit(1);
    }
    els_dxyPV_isLoaded = true;
  }
  return els_dxyPV_;
}

const vector<float> &CMS3::els_dzPV() {
  if (not els_dzPV_isLoaded) {
    if (els_dzPV_branch != 0) {
      els_dzPV_branch->GetEntry(index);
    } else {
      printf("branch els_dzPV_branch does not exist!\n");
      exit(1);
    }
    els_dzPV_isLoaded = true;
  }
  return els_dzPV_;
}

const vector<float> &CMS3::els_e1x5_full5x5() {
  if (not els_e1x5_full5x5_isLoaded) {
    if (els_e1x5_full5x5_branch != 0) {
      els_e1x5_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_e1x5_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_e1x5_full5x5_isLoaded = true;
  }
  return els_e1x5_full5x5_;
}

const vector<float> &CMS3::els_e2x5Max_full5x5() {
  if (not els_e2x5Max_full5x5_isLoaded) {
    if (els_e2x5Max_full5x5_branch != 0) {
      els_e2x5Max_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_e2x5Max_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_e2x5Max_full5x5_isLoaded = true;
  }
  return els_e2x5Max_full5x5_;
}

const vector<float> &CMS3::els_e5x5_full5x5() {
  if (not els_e5x5_full5x5_isLoaded) {
    if (els_e5x5_full5x5_branch != 0) {
      els_e5x5_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_e5x5_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_e5x5_full5x5_isLoaded = true;
  }
  return els_e5x5_full5x5_;
}

const vector<float> &CMS3::els_eOverPIn() {
  if (not els_eOverPIn_isLoaded) {
    if (els_eOverPIn_branch != 0) {
      els_eOverPIn_branch->GetEntry(index);
    } else {
      printf("branch els_eOverPIn_branch does not exist!\n");
      exit(1);
    }
    els_eOverPIn_isLoaded = true;
  }
  return els_eOverPIn_;
}

const vector<float> &CMS3::els_eOverPOut() {
  if (not els_eOverPOut_isLoaded) {
    if (els_eOverPOut_branch != 0) {
      els_eOverPOut_branch->GetEntry(index);
    } else {
      printf("branch els_eOverPOut_branch does not exist!\n");
      exit(1);
    }
    els_eOverPOut_isLoaded = true;
  }
  return els_eOverPOut_;
}

const vector<float> &CMS3::els_eSC() {
  if (not els_eSC_isLoaded) {
    if (els_eSC_branch != 0) {
      els_eSC_branch->GetEntry(index);
    } else {
      printf("branch els_eSC_branch does not exist!\n");
      exit(1);
    }
    els_eSC_isLoaded = true;
  }
  return els_eSC_;
}

const vector<float> &CMS3::els_eSCPresh() {
  if (not els_eSCPresh_isLoaded) {
    if (els_eSCPresh_branch != 0) {
      els_eSCPresh_branch->GetEntry(index);
    } else {
      printf("branch els_eSCPresh_branch does not exist!\n");
      exit(1);
    }
    els_eSCPresh_isLoaded = true;
  }
  return els_eSCPresh_;
}

const vector<float> &CMS3::els_eSCRaw() {
  if (not els_eSCRaw_isLoaded) {
    if (els_eSCRaw_branch != 0) {
      els_eSCRaw_branch->GetEntry(index);
    } else {
      printf("branch els_eSCRaw_branch does not exist!\n");
      exit(1);
    }
    els_eSCRaw_isLoaded = true;
  }
  return els_eSCRaw_;
}

const vector<float> &CMS3::els_eSeed() {
  if (not els_eSeed_isLoaded) {
    if (els_eSeed_branch != 0) {
      els_eSeed_branch->GetEntry(index);
    } else {
      printf("branch els_eSeed_branch does not exist!\n");
      exit(1);
    }
    els_eSeed_isLoaded = true;
  }
  return els_eSeed_;
}

const vector<float> &CMS3::els_ecalEnergy() {
  if (not els_ecalEnergy_isLoaded) {
    if (els_ecalEnergy_branch != 0) {
      els_ecalEnergy_branch->GetEntry(index);
    } else {
      printf("branch els_ecalEnergy_branch does not exist!\n");
      exit(1);
    }
    els_ecalEnergy_isLoaded = true;
  }
  return els_ecalEnergy_;
}

const vector<float> &CMS3::els_ecalEnergyError() {
  if (not els_ecalEnergyError_isLoaded) {
    if (els_ecalEnergyError_branch != 0) {
      els_ecalEnergyError_branch->GetEntry(index);
    } else {
      printf("branch els_ecalEnergyError_branch does not exist!\n");
      exit(1);
    }
    els_ecalEnergyError_isLoaded = true;
  }
  return els_ecalEnergyError_;
}

const vector<float> &CMS3::els_ecalIso() {
  if (not els_ecalIso_isLoaded) {
    if (els_ecalIso_branch != 0) {
      els_ecalIso_branch->GetEntry(index);
    } else {
      printf("branch els_ecalIso_branch does not exist!\n");
      exit(1);
    }
    els_ecalIso_isLoaded = true;
  }
  return els_ecalIso_;
}

const vector<float> &CMS3::els_ecalIso04() {
  if (not els_ecalIso04_isLoaded) {
    if (els_ecalIso04_branch != 0) {
      els_ecalIso04_branch->GetEntry(index);
    } else {
      printf("branch els_ecalIso04_branch does not exist!\n");
      exit(1);
    }
    els_ecalIso04_isLoaded = true;
  }
  return els_ecalIso04_;
}

const vector<float> &CMS3::els_ecalPFClusterIso() {
  if (not els_ecalPFClusterIso_isLoaded) {
    if (els_ecalPFClusterIso_branch != 0) {
      els_ecalPFClusterIso_branch->GetEntry(index);
    } else {
      printf("branch els_ecalPFClusterIso_branch does not exist!\n");
      exit(1);
    }
    els_ecalPFClusterIso_isLoaded = true;
  }
  return els_ecalPFClusterIso_;
}

const vector<float> &CMS3::els_etaSC() {
  if (not els_etaSC_isLoaded) {
    if (els_etaSC_branch != 0) {
      els_etaSC_branch->GetEntry(index);
    } else {
      printf("branch els_etaSC_branch does not exist!\n");
      exit(1);
    }
    els_etaSC_isLoaded = true;
  }
  return els_etaSC_;
}

const vector<float> &CMS3::els_etaSCwidth() {
  if (not els_etaSCwidth_isLoaded) {
    if (els_etaSCwidth_branch != 0) {
      els_etaSCwidth_branch->GetEntry(index);
    } else {
      printf("branch els_etaSCwidth_branch does not exist!\n");
      exit(1);
    }
    els_etaSCwidth_isLoaded = true;
  }
  return els_etaSCwidth_;
}

const vector<float> &CMS3::els_fbrem() {
  if (not els_fbrem_isLoaded) {
    if (els_fbrem_branch != 0) {
      els_fbrem_branch->GetEntry(index);
    } else {
      printf("branch els_fbrem_branch does not exist!\n");
      exit(1);
    }
    els_fbrem_isLoaded = true;
  }
  return els_fbrem_;
}

const vector<float> &CMS3::els_full5x5_hOverE() {
  if (not els_full5x5_hOverE_isLoaded) {
    if (els_full5x5_hOverE_branch != 0) {
      els_full5x5_hOverE_branch->GetEntry(index);
    } else {
      printf("branch els_full5x5_hOverE_branch does not exist!\n");
      exit(1);
    }
    els_full5x5_hOverE_isLoaded = true;
  }
  return els_full5x5_hOverE_;
}

const vector<float> &CMS3::els_hOverE() {
  if (not els_hOverE_isLoaded) {
    if (els_hOverE_branch != 0) {
      els_hOverE_branch->GetEntry(index);
    } else {
      printf("branch els_hOverE_branch does not exist!\n");
      exit(1);
    }
    els_hOverE_isLoaded = true;
  }
  return els_hOverE_;
}

const vector<float> &CMS3::els_hcalDepth1TowerSumEt() {
  if (not els_hcalDepth1TowerSumEt_isLoaded) {
    if (els_hcalDepth1TowerSumEt_branch != 0) {
      els_hcalDepth1TowerSumEt_branch->GetEntry(index);
    } else {
      printf("branch els_hcalDepth1TowerSumEt_branch does not exist!\n");
      exit(1);
    }
    els_hcalDepth1TowerSumEt_isLoaded = true;
  }
  return els_hcalDepth1TowerSumEt_;
}

const vector<float> &CMS3::els_hcalIso() {
  if (not els_hcalIso_isLoaded) {
    if (els_hcalIso_branch != 0) {
      els_hcalIso_branch->GetEntry(index);
    } else {
      printf("branch els_hcalIso_branch does not exist!\n");
      exit(1);
    }
    els_hcalIso_isLoaded = true;
  }
  return els_hcalIso_;
}

const vector<float> &CMS3::els_hcalIso04() {
  if (not els_hcalIso04_isLoaded) {
    if (els_hcalIso04_branch != 0) {
      els_hcalIso04_branch->GetEntry(index);
    } else {
      printf("branch els_hcalIso04_branch does not exist!\n");
      exit(1);
    }
    els_hcalIso04_isLoaded = true;
  }
  return els_hcalIso04_;
}

const vector<float> &CMS3::els_hcalPFClusterIso() {
  if (not els_hcalPFClusterIso_isLoaded) {
    if (els_hcalPFClusterIso_branch != 0) {
      els_hcalPFClusterIso_branch->GetEntry(index);
    } else {
      printf("branch els_hcalPFClusterIso_branch does not exist!\n");
      exit(1);
    }
    els_hcalPFClusterIso_isLoaded = true;
  }
  return els_hcalPFClusterIso_;
}

const vector<float> &CMS3::els_ip2d() {
  if (not els_ip2d_isLoaded) {
    if (els_ip2d_branch != 0) {
      els_ip2d_branch->GetEntry(index);
    } else {
      printf("branch els_ip2d_branch does not exist!\n");
      exit(1);
    }
    els_ip2d_isLoaded = true;
  }
  return els_ip2d_;
}

const vector<float> &CMS3::els_ip2derr() {
  if (not els_ip2derr_isLoaded) {
    if (els_ip2derr_branch != 0) {
      els_ip2derr_branch->GetEntry(index);
    } else {
      printf("branch els_ip2derr_branch does not exist!\n");
      exit(1);
    }
    els_ip2derr_isLoaded = true;
  }
  return els_ip2derr_;
}

const vector<float> &CMS3::els_ip3d() {
  if (not els_ip3d_isLoaded) {
    if (els_ip3d_branch != 0) {
      els_ip3d_branch->GetEntry(index);
    } else {
      printf("branch els_ip3d_branch does not exist!\n");
      exit(1);
    }
    els_ip3d_isLoaded = true;
  }
  return els_ip3d_;
}

const vector<float> &CMS3::els_ip3derr() {
  if (not els_ip3derr_isLoaded) {
    if (els_ip3derr_branch != 0) {
      els_ip3derr_branch->GetEntry(index);
    } else {
      printf("branch els_ip3derr_branch does not exist!\n");
      exit(1);
    }
    els_ip3derr_isLoaded = true;
  }
  return els_ip3derr_;
}

const vector<float> &CMS3::els_mc_patMatch_dr() {
  if (not els_mc_patMatch_dr_isLoaded) {
    if (els_mc_patMatch_dr_branch != 0) {
      els_mc_patMatch_dr_branch->GetEntry(index);
    } else {
      printf("branch els_mc_patMatch_dr_branch does not exist!\n");
      exit(1);
    }
    els_mc_patMatch_dr_isLoaded = true;
  }
  return els_mc_patMatch_dr_;
}

const vector<float> &CMS3::els_miniIso_ch() {
  if (not els_miniIso_ch_isLoaded) {
    if (els_miniIso_ch_branch != 0) {
      els_miniIso_ch_branch->GetEntry(index);
    } else {
      printf("branch els_miniIso_ch_branch does not exist!\n");
      exit(1);
    }
    els_miniIso_ch_isLoaded = true;
  }
  return els_miniIso_ch_;
}

const vector<float> &CMS3::els_miniIso_db() {
  if (not els_miniIso_db_isLoaded) {
    if (els_miniIso_db_branch != 0) {
      els_miniIso_db_branch->GetEntry(index);
    } else {
      printf("branch els_miniIso_db_branch does not exist!\n");
      exit(1);
    }
    els_miniIso_db_isLoaded = true;
  }
  return els_miniIso_db_;
}

const vector<float> &CMS3::els_miniIso_em() {
  if (not els_miniIso_em_isLoaded) {
    if (els_miniIso_em_branch != 0) {
      els_miniIso_em_branch->GetEntry(index);
    } else {
      printf("branch els_miniIso_em_branch does not exist!\n");
      exit(1);
    }
    els_miniIso_em_isLoaded = true;
  }
  return els_miniIso_em_;
}

const vector<float> &CMS3::els_miniIso_nh() {
  if (not els_miniIso_nh_isLoaded) {
    if (els_miniIso_nh_branch != 0) {
      els_miniIso_nh_branch->GetEntry(index);
    } else {
      printf("branch els_miniIso_nh_branch does not exist!\n");
      exit(1);
    }
    els_miniIso_nh_isLoaded = true;
  }
  return els_miniIso_nh_;
}

const vector<float> &CMS3::els_miniIso_uncor() {
  if (not els_miniIso_uncor_isLoaded) {
    if (els_miniIso_uncor_branch != 0) {
      els_miniIso_uncor_branch->GetEntry(index);
    } else {
      printf("branch els_miniIso_uncor_branch does not exist!\n");
      exit(1);
    }
    els_miniIso_uncor_isLoaded = true;
  }
  return els_miniIso_uncor_;
}

const vector<float> &CMS3::els_ndof() {
  if (not els_ndof_isLoaded) {
    if (els_ndof_branch != 0) {
      els_ndof_branch->GetEntry(index);
    } else {
      printf("branch els_ndof_branch does not exist!\n");
      exit(1);
    }
    els_ndof_isLoaded = true;
  }
  return els_ndof_;
}

const vector<float> &CMS3::els_pfChargedHadronIso() {
  if (not els_pfChargedHadronIso_isLoaded) {
    if (els_pfChargedHadronIso_branch != 0) {
      els_pfChargedHadronIso_branch->GetEntry(index);
    } else {
      printf("branch els_pfChargedHadronIso_branch does not exist!\n");
      exit(1);
    }
    els_pfChargedHadronIso_isLoaded = true;
  }
  return els_pfChargedHadronIso_;
}

const vector<float> &CMS3::els_pfNeutralHadronIso() {
  if (not els_pfNeutralHadronIso_isLoaded) {
    if (els_pfNeutralHadronIso_branch != 0) {
      els_pfNeutralHadronIso_branch->GetEntry(index);
    } else {
      printf("branch els_pfNeutralHadronIso_branch does not exist!\n");
      exit(1);
    }
    els_pfNeutralHadronIso_isLoaded = true;
  }
  return els_pfNeutralHadronIso_;
}

const vector<float> &CMS3::els_pfPUIso() {
  if (not els_pfPUIso_isLoaded) {
    if (els_pfPUIso_branch != 0) {
      els_pfPUIso_branch->GetEntry(index);
    } else {
      printf("branch els_pfPUIso_branch does not exist!\n");
      exit(1);
    }
    els_pfPUIso_isLoaded = true;
  }
  return els_pfPUIso_;
}

const vector<float> &CMS3::els_pfPhotonIso() {
  if (not els_pfPhotonIso_isLoaded) {
    if (els_pfPhotonIso_branch != 0) {
      els_pfPhotonIso_branch->GetEntry(index);
    } else {
      printf("branch els_pfPhotonIso_branch does not exist!\n");
      exit(1);
    }
    els_pfPhotonIso_isLoaded = true;
  }
  return els_pfPhotonIso_;
}

const vector<float> &CMS3::els_phiSC() {
  if (not els_phiSC_isLoaded) {
    if (els_phiSC_branch != 0) {
      els_phiSC_branch->GetEntry(index);
    } else {
      printf("branch els_phiSC_branch does not exist!\n");
      exit(1);
    }
    els_phiSC_isLoaded = true;
  }
  return els_phiSC_;
}

const vector<float> &CMS3::els_phiSCwidth() {
  if (not els_phiSCwidth_isLoaded) {
    if (els_phiSCwidth_branch != 0) {
      els_phiSCwidth_branch->GetEntry(index);
    } else {
      printf("branch els_phiSCwidth_branch does not exist!\n");
      exit(1);
    }
    els_phiSCwidth_isLoaded = true;
  }
  return els_phiSCwidth_;
}

const vector<float> &CMS3::els_ptErr() {
  if (not els_ptErr_isLoaded) {
    if (els_ptErr_branch != 0) {
      els_ptErr_branch->GetEntry(index);
    } else {
      printf("branch els_ptErr_branch does not exist!\n");
      exit(1);
    }
    els_ptErr_isLoaded = true;
  }
  return els_ptErr_;
}

const vector<float> &CMS3::els_ptErrGsf() {
  if (not els_ptErrGsf_isLoaded) {
    if (els_ptErrGsf_branch != 0) {
      els_ptErrGsf_branch->GetEntry(index);
    } else {
      printf("branch els_ptErrGsf_branch does not exist!\n");
      exit(1);
    }
    els_ptErrGsf_isLoaded = true;
  }
  return els_ptErrGsf_;
}

const vector<float> &CMS3::els_r9() {
  if (not els_r9_isLoaded) {
    if (els_r9_branch != 0) {
      els_r9_branch->GetEntry(index);
    } else {
      printf("branch els_r9_branch does not exist!\n");
      exit(1);
    }
    els_r9_isLoaded = true;
  }
  return els_r9_;
}

const vector<float> &CMS3::els_r9_full5x5() {
  if (not els_r9_full5x5_isLoaded) {
    if (els_r9_full5x5_branch != 0) {
      els_r9_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_r9_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_r9_full5x5_isLoaded = true;
  }
  return els_r9_full5x5_;
}

const vector<float> &CMS3::els_scSeedEta() {
  if (not els_scSeedEta_isLoaded) {
    if (els_scSeedEta_branch != 0) {
      els_scSeedEta_branch->GetEntry(index);
    } else {
      printf("branch els_scSeedEta_branch does not exist!\n");
      exit(1);
    }
    els_scSeedEta_isLoaded = true;
  }
  return els_scSeedEta_;
}

const vector<float> &CMS3::els_sigmaEtaEta_full5x5() {
  if (not els_sigmaEtaEta_full5x5_isLoaded) {
    if (els_sigmaEtaEta_full5x5_branch != 0) {
      els_sigmaEtaEta_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_sigmaEtaEta_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_sigmaEtaEta_full5x5_isLoaded = true;
  }
  return els_sigmaEtaEta_full5x5_;
}

const vector<float> &CMS3::els_sigmaIEtaIEta() {
  if (not els_sigmaIEtaIEta_isLoaded) {
    if (els_sigmaIEtaIEta_branch != 0) {
      els_sigmaIEtaIEta_branch->GetEntry(index);
    } else {
      printf("branch els_sigmaIEtaIEta_branch does not exist!\n");
      exit(1);
    }
    els_sigmaIEtaIEta_isLoaded = true;
  }
  return els_sigmaIEtaIEta_;
}

const vector<float> &CMS3::els_sigmaIEtaIEta_full5x5() {
  if (not els_sigmaIEtaIEta_full5x5_isLoaded) {
    if (els_sigmaIEtaIEta_full5x5_branch != 0) {
      els_sigmaIEtaIEta_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_sigmaIEtaIEta_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_sigmaIEtaIEta_full5x5_isLoaded = true;
  }
  return els_sigmaIEtaIEta_full5x5_;
}

const vector<float> &CMS3::els_sigmaIPhiIPhi() {
  if (not els_sigmaIPhiIPhi_isLoaded) {
    if (els_sigmaIPhiIPhi_branch != 0) {
      els_sigmaIPhiIPhi_branch->GetEntry(index);
    } else {
      printf("branch els_sigmaIPhiIPhi_branch does not exist!\n");
      exit(1);
    }
    els_sigmaIPhiIPhi_isLoaded = true;
  }
  return els_sigmaIPhiIPhi_;
}

const vector<float> &CMS3::els_sigmaIPhiIPhi_full5x5() {
  if (not els_sigmaIPhiIPhi_full5x5_isLoaded) {
    if (els_sigmaIPhiIPhi_full5x5_branch != 0) {
      els_sigmaIPhiIPhi_full5x5_branch->GetEntry(index);
    } else {
      printf("branch els_sigmaIPhiIPhi_full5x5_branch does not exist!\n");
      exit(1);
    }
    els_sigmaIPhiIPhi_full5x5_isLoaded = true;
  }
  return els_sigmaIPhiIPhi_full5x5_;
}

const vector<float> &CMS3::els_tkIso() {
  if (not els_tkIso_isLoaded) {
    if (els_tkIso_branch != 0) {
      els_tkIso_branch->GetEntry(index);
    } else {
      printf("branch els_tkIso_branch does not exist!\n");
      exit(1);
    }
    els_tkIso_isLoaded = true;
  }
  return els_tkIso_;
}

const vector<float> &CMS3::els_tkIso04() {
  if (not els_tkIso04_isLoaded) {
    if (els_tkIso04_branch != 0) {
      els_tkIso04_branch->GetEntry(index);
    } else {
      printf("branch els_tkIso04_branch does not exist!\n");
      exit(1);
    }
    els_tkIso04_isLoaded = true;
  }
  return els_tkIso04_;
}

const vector<float> &CMS3::els_trackMomentumError() {
  if (not els_trackMomentumError_isLoaded) {
    if (els_trackMomentumError_branch != 0) {
      els_trackMomentumError_branch->GetEntry(index);
    } else {
      printf("branch els_trackMomentumError_branch does not exist!\n");
      exit(1);
    }
    els_trackMomentumError_isLoaded = true;
  }
  return els_trackMomentumError_;
}

const vector<float> &CMS3::els_trkdr() {
  if (not els_trkdr_isLoaded) {
    if (els_trkdr_branch != 0) {
      els_trkdr_branch->GetEntry(index);
    } else {
      printf("branch els_trkdr_branch does not exist!\n");
      exit(1);
    }
    els_trkdr_isLoaded = true;
  }
  return els_trkdr_;
}

const vector<float> &CMS3::els_trkshFrac() {
  if (not els_trkshFrac_isLoaded) {
    if (els_trkshFrac_branch != 0) {
      els_trkshFrac_branch->GetEntry(index);
    } else {
      printf("branch els_trkshFrac_branch does not exist!\n");
      exit(1);
    }
    els_trkshFrac_isLoaded = true;
  }
  return els_trkshFrac_;
}

const vector<float> &CMS3::els_z0Err() {
  if (not els_z0Err_isLoaded) {
    if (els_z0Err_branch != 0) {
      els_z0Err_branch->GetEntry(index);
    } else {
      printf("branch els_z0Err_branch does not exist!\n");
      exit(1);
    }
    els_z0Err_isLoaded = true;
  }
  return els_z0Err_;
}

const vector<float> &CMS3::genps_charge() {
  if (not genps_charge_isLoaded) {
    if (genps_charge_branch != 0) {
      genps_charge_branch->GetEntry(index);
    } else {
      printf("branch genps_charge_branch does not exist!\n");
      exit(1);
    }
    genps_charge_isLoaded = true;
  }
  return genps_charge_;
}

const vector<float> &CMS3::genps_iso() {
  if (not genps_iso_isLoaded) {
    if (genps_iso_branch != 0) {
      genps_iso_branch->GetEntry(index);
    } else {
      printf("branch genps_iso_branch does not exist!\n");
      exit(1);
    }
    genps_iso_isLoaded = true;
  }
  return genps_iso_;
}

const vector<float> &CMS3::genweights() {
  if (not genweights_isLoaded) {
    if (genweights_branch != 0) {
      genweights_branch->GetEntry(index);
    } else {
      printf("branch genweights_branch does not exist!\n");
      exit(1);
    }
    genweights_isLoaded = true;
  }
  return genweights_;
}

const vector<float> &CMS3::isotracks_dEdxPixel() {
  if (not isotracks_dEdxPixel_isLoaded) {
    if (isotracks_dEdxPixel_branch != 0) {
      isotracks_dEdxPixel_branch->GetEntry(index);
    } else {
      printf("branch isotracks_dEdxPixel_branch does not exist!\n");
      exit(1);
    }
    isotracks_dEdxPixel_isLoaded = true;
  }
  return isotracks_dEdxPixel_;
}

const vector<float> &CMS3::isotracks_dEdxStrip() {
  if (not isotracks_dEdxStrip_isLoaded) {
    if (isotracks_dEdxStrip_branch != 0) {
      isotracks_dEdxStrip_branch->GetEntry(index);
    } else {
      printf("branch isotracks_dEdxStrip_branch does not exist!\n");
      exit(1);
    }
    isotracks_dEdxStrip_isLoaded = true;
  }
  return isotracks_dEdxStrip_;
}

const vector<float> &CMS3::isotracks_deltaEta() {
  if (not isotracks_deltaEta_isLoaded) {
    if (isotracks_deltaEta_branch != 0) {
      isotracks_deltaEta_branch->GetEntry(index);
    } else {
      printf("branch isotracks_deltaEta_branch does not exist!\n");
      exit(1);
    }
    isotracks_deltaEta_isLoaded = true;
  }
  return isotracks_deltaEta_;
}

const vector<float> &CMS3::isotracks_deltaPhi() {
  if (not isotracks_deltaPhi_isLoaded) {
    if (isotracks_deltaPhi_branch != 0) {
      isotracks_deltaPhi_branch->GetEntry(index);
    } else {
      printf("branch isotracks_deltaPhi_branch does not exist!\n");
      exit(1);
    }
    isotracks_deltaPhi_isLoaded = true;
  }
  return isotracks_deltaPhi_;
}

const vector<float> &CMS3::isotracks_dxy() {
  if (not isotracks_dxy_isLoaded) {
    if (isotracks_dxy_branch != 0) {
      isotracks_dxy_branch->GetEntry(index);
    } else {
      printf("branch isotracks_dxy_branch does not exist!\n");
      exit(1);
    }
    isotracks_dxy_isLoaded = true;
  }
  return isotracks_dxy_;
}

const vector<float> &CMS3::isotracks_dxyError() {
  if (not isotracks_dxyError_isLoaded) {
    if (isotracks_dxyError_branch != 0) {
      isotracks_dxyError_branch->GetEntry(index);
    } else {
      printf("branch isotracks_dxyError_branch does not exist!\n");
      exit(1);
    }
    isotracks_dxyError_isLoaded = true;
  }
  return isotracks_dxyError_;
}

const vector<float> &CMS3::isotracks_dz() {
  if (not isotracks_dz_isLoaded) {
    if (isotracks_dz_branch != 0) {
      isotracks_dz_branch->GetEntry(index);
    } else {
      printf("branch isotracks_dz_branch does not exist!\n");
      exit(1);
    }
    isotracks_dz_isLoaded = true;
  }
  return isotracks_dz_;
}

const vector<float> &CMS3::isotracks_dzError() {
  if (not isotracks_dzError_isLoaded) {
    if (isotracks_dzError_branch != 0) {
      isotracks_dzError_branch->GetEntry(index);
    } else {
      printf("branch isotracks_dzError_branch does not exist!\n");
      exit(1);
    }
    isotracks_dzError_isLoaded = true;
  }
  return isotracks_dzError_;
}

const vector<float> &CMS3::isotracks_matchedCaloJetEmEnergy() {
  if (not isotracks_matchedCaloJetEmEnergy_isLoaded) {
    if (isotracks_matchedCaloJetEmEnergy_branch != 0) {
      isotracks_matchedCaloJetEmEnergy_branch->GetEntry(index);
    } else {
      printf("branch isotracks_matchedCaloJetEmEnergy_branch does not exist!\n");
      exit(1);
    }
    isotracks_matchedCaloJetEmEnergy_isLoaded = true;
  }
  return isotracks_matchedCaloJetEmEnergy_;
}

const vector<float> &CMS3::isotracks_matchedCaloJetHadEnergy() {
  if (not isotracks_matchedCaloJetHadEnergy_isLoaded) {
    if (isotracks_matchedCaloJetHadEnergy_branch != 0) {
      isotracks_matchedCaloJetHadEnergy_branch->GetEntry(index);
    } else {
      printf("branch isotracks_matchedCaloJetHadEnergy_branch does not exist!\n");
      exit(1);
    }
    isotracks_matchedCaloJetHadEnergy_isLoaded = true;
  }
  return isotracks_matchedCaloJetHadEnergy_;
}

const vector<float> &CMS3::isotracks_miniIso_ch() {
  if (not isotracks_miniIso_ch_isLoaded) {
    if (isotracks_miniIso_ch_branch != 0) {
      isotracks_miniIso_ch_branch->GetEntry(index);
    } else {
      printf("branch isotracks_miniIso_ch_branch does not exist!\n");
      exit(1);
    }
    isotracks_miniIso_ch_isLoaded = true;
  }
  return isotracks_miniIso_ch_;
}

const vector<float> &CMS3::isotracks_miniIso_db() {
  if (not isotracks_miniIso_db_isLoaded) {
    if (isotracks_miniIso_db_branch != 0) {
      isotracks_miniIso_db_branch->GetEntry(index);
    } else {
      printf("branch isotracks_miniIso_db_branch does not exist!\n");
      exit(1);
    }
    isotracks_miniIso_db_isLoaded = true;
  }
  return isotracks_miniIso_db_;
}

const vector<float> &CMS3::isotracks_miniIso_em() {
  if (not isotracks_miniIso_em_isLoaded) {
    if (isotracks_miniIso_em_branch != 0) {
      isotracks_miniIso_em_branch->GetEntry(index);
    } else {
      printf("branch isotracks_miniIso_em_branch does not exist!\n");
      exit(1);
    }
    isotracks_miniIso_em_isLoaded = true;
  }
  return isotracks_miniIso_em_;
}

const vector<float> &CMS3::isotracks_miniIso_nh() {
  if (not isotracks_miniIso_nh_isLoaded) {
    if (isotracks_miniIso_nh_branch != 0) {
      isotracks_miniIso_nh_branch->GetEntry(index);
    } else {
      printf("branch isotracks_miniIso_nh_branch does not exist!\n");
      exit(1);
    }
    isotracks_miniIso_nh_isLoaded = true;
  }
  return isotracks_miniIso_nh_;
}

const vector<float> &CMS3::isotracks_pfIso_ch() {
  if (not isotracks_pfIso_ch_isLoaded) {
    if (isotracks_pfIso_ch_branch != 0) {
      isotracks_pfIso_ch_branch->GetEntry(index);
    } else {
      printf("branch isotracks_pfIso_ch_branch does not exist!\n");
      exit(1);
    }
    isotracks_pfIso_ch_isLoaded = true;
  }
  return isotracks_pfIso_ch_;
}

const vector<float> &CMS3::isotracks_pfIso_db() {
  if (not isotracks_pfIso_db_isLoaded) {
    if (isotracks_pfIso_db_branch != 0) {
      isotracks_pfIso_db_branch->GetEntry(index);
    } else {
      printf("branch isotracks_pfIso_db_branch does not exist!\n");
      exit(1);
    }
    isotracks_pfIso_db_isLoaded = true;
  }
  return isotracks_pfIso_db_;
}

const vector<float> &CMS3::isotracks_pfIso_em() {
  if (not isotracks_pfIso_em_isLoaded) {
    if (isotracks_pfIso_em_branch != 0) {
      isotracks_pfIso_em_branch->GetEntry(index);
    } else {
      printf("branch isotracks_pfIso_em_branch does not exist!\n");
      exit(1);
    }
    isotracks_pfIso_em_isLoaded = true;
  }
  return isotracks_pfIso_em_;
}

const vector<float> &CMS3::isotracks_pfIso_nh() {
  if (not isotracks_pfIso_nh_isLoaded) {
    if (isotracks_pfIso_nh_branch != 0) {
      isotracks_pfIso_nh_branch->GetEntry(index);
    } else {
      printf("branch isotracks_pfIso_nh_branch does not exist!\n");
      exit(1);
    }
    isotracks_pfIso_nh_isLoaded = true;
  }
  return isotracks_pfIso_nh_;
}

const vector<float> &CMS3::mus_bfit_ptErr() {
  if (not mus_bfit_ptErr_isLoaded) {
    if (mus_bfit_ptErr_branch != 0) {
      mus_bfit_ptErr_branch->GetEntry(index);
    } else {
      printf("branch mus_bfit_ptErr_branch does not exist!\n");
      exit(1);
    }
    mus_bfit_ptErr_isLoaded = true;
  }
  return mus_bfit_ptErr_;
}

const vector<float> &CMS3::mus_caloCompatibility() {
  if (not mus_caloCompatibility_isLoaded) {
    if (mus_caloCompatibility_branch != 0) {
      mus_caloCompatibility_branch->GetEntry(index);
    } else {
      printf("branch mus_caloCompatibility_branch does not exist!\n");
      exit(1);
    }
    mus_caloCompatibility_isLoaded = true;
  }
  return mus_caloCompatibility_;
}

const vector<float> &CMS3::mus_chi2LocalMomentum() {
  if (not mus_chi2LocalMomentum_isLoaded) {
    if (mus_chi2LocalMomentum_branch != 0) {
      mus_chi2LocalMomentum_branch->GetEntry(index);
    } else {
      printf("branch mus_chi2LocalMomentum_branch does not exist!\n");
      exit(1);
    }
    mus_chi2LocalMomentum_isLoaded = true;
  }
  return mus_chi2LocalMomentum_;
}

const vector<float> &CMS3::mus_chi2LocalPosition() {
  if (not mus_chi2LocalPosition_isLoaded) {
    if (mus_chi2LocalPosition_branch != 0) {
      mus_chi2LocalPosition_branch->GetEntry(index);
    } else {
      printf("branch mus_chi2LocalPosition_branch does not exist!\n");
      exit(1);
    }
    mus_chi2LocalPosition_isLoaded = true;
  }
  return mus_chi2LocalPosition_;
}

const vector<float> &CMS3::mus_d0Err() {
  if (not mus_d0Err_isLoaded) {
    if (mus_d0Err_branch != 0) {
      mus_d0Err_branch->GetEntry(index);
    } else {
      printf("branch mus_d0Err_branch does not exist!\n");
      exit(1);
    }
    mus_d0Err_isLoaded = true;
  }
  return mus_d0Err_;
}

const vector<float> &CMS3::mus_dxyPV() {
  if (not mus_dxyPV_isLoaded) {
    if (mus_dxyPV_branch != 0) {
      mus_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch mus_dxyPV_branch does not exist!\n");
      exit(1);
    }
    mus_dxyPV_isLoaded = true;
  }
  return mus_dxyPV_;
}

const vector<float> &CMS3::mus_dzPV() {
  if (not mus_dzPV_isLoaded) {
    if (mus_dzPV_branch != 0) {
      mus_dzPV_branch->GetEntry(index);
    } else {
      printf("branch mus_dzPV_branch does not exist!\n");
      exit(1);
    }
    mus_dzPV_isLoaded = true;
  }
  return mus_dzPV_;
}

const vector<float> &CMS3::mus_ecal_time() {
  if (not mus_ecal_time_isLoaded) {
    if (mus_ecal_time_branch != 0) {
      mus_ecal_time_branch->GetEntry(index);
    } else {
      printf("branch mus_ecal_time_branch does not exist!\n");
      exit(1);
    }
    mus_ecal_time_isLoaded = true;
  }
  return mus_ecal_time_;
}

const vector<float> &CMS3::mus_gfit_chi2() {
  if (not mus_gfit_chi2_isLoaded) {
    if (mus_gfit_chi2_branch != 0) {
      mus_gfit_chi2_branch->GetEntry(index);
    } else {
      printf("branch mus_gfit_chi2_branch does not exist!\n");
      exit(1);
    }
    mus_gfit_chi2_isLoaded = true;
  }
  return mus_gfit_chi2_;
}

const vector<float> &CMS3::mus_gfit_ptErr() {
  if (not mus_gfit_ptErr_isLoaded) {
    if (mus_gfit_ptErr_branch != 0) {
      mus_gfit_ptErr_branch->GetEntry(index);
    } else {
      printf("branch mus_gfit_ptErr_branch does not exist!\n");
      exit(1);
    }
    mus_gfit_ptErr_isLoaded = true;
  }
  return mus_gfit_ptErr_;
}

const vector<float> &CMS3::mus_hcal_time() {
  if (not mus_hcal_time_isLoaded) {
    if (mus_hcal_time_branch != 0) {
      mus_hcal_time_branch->GetEntry(index);
    } else {
      printf("branch mus_hcal_time_branch does not exist!\n");
      exit(1);
    }
    mus_hcal_time_isLoaded = true;
  }
  return mus_hcal_time_;
}

const vector<float> &CMS3::mus_ip2d() {
  if (not mus_ip2d_isLoaded) {
    if (mus_ip2d_branch != 0) {
      mus_ip2d_branch->GetEntry(index);
    } else {
      printf("branch mus_ip2d_branch does not exist!\n");
      exit(1);
    }
    mus_ip2d_isLoaded = true;
  }
  return mus_ip2d_;
}

const vector<float> &CMS3::mus_ip2derr() {
  if (not mus_ip2derr_isLoaded) {
    if (mus_ip2derr_branch != 0) {
      mus_ip2derr_branch->GetEntry(index);
    } else {
      printf("branch mus_ip2derr_branch does not exist!\n");
      exit(1);
    }
    mus_ip2derr_isLoaded = true;
  }
  return mus_ip2derr_;
}

const vector<float> &CMS3::mus_ip3d() {
  if (not mus_ip3d_isLoaded) {
    if (mus_ip3d_branch != 0) {
      mus_ip3d_branch->GetEntry(index);
    } else {
      printf("branch mus_ip3d_branch does not exist!\n");
      exit(1);
    }
    mus_ip3d_isLoaded = true;
  }
  return mus_ip3d_;
}

const vector<float> &CMS3::mus_ip3derr() {
  if (not mus_ip3derr_isLoaded) {
    if (mus_ip3derr_branch != 0) {
      mus_ip3derr_branch->GetEntry(index);
    } else {
      printf("branch mus_ip3derr_branch does not exist!\n");
      exit(1);
    }
    mus_ip3derr_isLoaded = true;
  }
  return mus_ip3derr_;
}

const vector<float> &CMS3::mus_iso03_emEt() {
  if (not mus_iso03_emEt_isLoaded) {
    if (mus_iso03_emEt_branch != 0) {
      mus_iso03_emEt_branch->GetEntry(index);
    } else {
      printf("branch mus_iso03_emEt_branch does not exist!\n");
      exit(1);
    }
    mus_iso03_emEt_isLoaded = true;
  }
  return mus_iso03_emEt_;
}

const vector<float> &CMS3::mus_iso03_hadEt() {
  if (not mus_iso03_hadEt_isLoaded) {
    if (mus_iso03_hadEt_branch != 0) {
      mus_iso03_hadEt_branch->GetEntry(index);
    } else {
      printf("branch mus_iso03_hadEt_branch does not exist!\n");
      exit(1);
    }
    mus_iso03_hadEt_isLoaded = true;
  }
  return mus_iso03_hadEt_;
}

const vector<float> &CMS3::mus_iso03_sumPt() {
  if (not mus_iso03_sumPt_isLoaded) {
    if (mus_iso03_sumPt_branch != 0) {
      mus_iso03_sumPt_branch->GetEntry(index);
    } else {
      printf("branch mus_iso03_sumPt_branch does not exist!\n");
      exit(1);
    }
    mus_iso03_sumPt_isLoaded = true;
  }
  return mus_iso03_sumPt_;
}

const vector<float> &CMS3::mus_isoR03_pf_ChargedHadronPt() {
  if (not mus_isoR03_pf_ChargedHadronPt_isLoaded) {
    if (mus_isoR03_pf_ChargedHadronPt_branch != 0) {
      mus_isoR03_pf_ChargedHadronPt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_ChargedHadronPt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_ChargedHadronPt_isLoaded = true;
  }
  return mus_isoR03_pf_ChargedHadronPt_;
}

const vector<float> &CMS3::mus_isoR03_pf_ChargedParticlePt() {
  if (not mus_isoR03_pf_ChargedParticlePt_isLoaded) {
    if (mus_isoR03_pf_ChargedParticlePt_branch != 0) {
      mus_isoR03_pf_ChargedParticlePt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_ChargedParticlePt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_ChargedParticlePt_isLoaded = true;
  }
  return mus_isoR03_pf_ChargedParticlePt_;
}

const vector<float> &CMS3::mus_isoR03_pf_NeutralHadronEt() {
  if (not mus_isoR03_pf_NeutralHadronEt_isLoaded) {
    if (mus_isoR03_pf_NeutralHadronEt_branch != 0) {
      mus_isoR03_pf_NeutralHadronEt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_NeutralHadronEt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_NeutralHadronEt_isLoaded = true;
  }
  return mus_isoR03_pf_NeutralHadronEt_;
}

const vector<float> &CMS3::mus_isoR03_pf_NeutralHadronEtHighThreshold() {
  if (not mus_isoR03_pf_NeutralHadronEtHighThreshold_isLoaded) {
    if (mus_isoR03_pf_NeutralHadronEtHighThreshold_branch != 0) {
      mus_isoR03_pf_NeutralHadronEtHighThreshold_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_NeutralHadronEtHighThreshold_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_NeutralHadronEtHighThreshold_isLoaded = true;
  }
  return mus_isoR03_pf_NeutralHadronEtHighThreshold_;
}

const vector<float> &CMS3::mus_isoR03_pf_PUPt() {
  if (not mus_isoR03_pf_PUPt_isLoaded) {
    if (mus_isoR03_pf_PUPt_branch != 0) {
      mus_isoR03_pf_PUPt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_PUPt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_PUPt_isLoaded = true;
  }
  return mus_isoR03_pf_PUPt_;
}

const vector<float> &CMS3::mus_isoR03_pf_PhotonEt() {
  if (not mus_isoR03_pf_PhotonEt_isLoaded) {
    if (mus_isoR03_pf_PhotonEt_branch != 0) {
      mus_isoR03_pf_PhotonEt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_PhotonEt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_PhotonEt_isLoaded = true;
  }
  return mus_isoR03_pf_PhotonEt_;
}

const vector<float> &CMS3::mus_isoR03_pf_PhotonEtHighThreshold() {
  if (not mus_isoR03_pf_PhotonEtHighThreshold_isLoaded) {
    if (mus_isoR03_pf_PhotonEtHighThreshold_branch != 0) {
      mus_isoR03_pf_PhotonEtHighThreshold_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR03_pf_PhotonEtHighThreshold_branch does not exist!\n");
      exit(1);
    }
    mus_isoR03_pf_PhotonEtHighThreshold_isLoaded = true;
  }
  return mus_isoR03_pf_PhotonEtHighThreshold_;
}

const vector<float> &CMS3::mus_isoR04_pf_ChargedHadronPt() {
  if (not mus_isoR04_pf_ChargedHadronPt_isLoaded) {
    if (mus_isoR04_pf_ChargedHadronPt_branch != 0) {
      mus_isoR04_pf_ChargedHadronPt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_ChargedHadronPt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_ChargedHadronPt_isLoaded = true;
  }
  return mus_isoR04_pf_ChargedHadronPt_;
}

const vector<float> &CMS3::mus_isoR04_pf_ChargedParticlePt() {
  if (not mus_isoR04_pf_ChargedParticlePt_isLoaded) {
    if (mus_isoR04_pf_ChargedParticlePt_branch != 0) {
      mus_isoR04_pf_ChargedParticlePt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_ChargedParticlePt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_ChargedParticlePt_isLoaded = true;
  }
  return mus_isoR04_pf_ChargedParticlePt_;
}

const vector<float> &CMS3::mus_isoR04_pf_NeutralHadronEt() {
  if (not mus_isoR04_pf_NeutralHadronEt_isLoaded) {
    if (mus_isoR04_pf_NeutralHadronEt_branch != 0) {
      mus_isoR04_pf_NeutralHadronEt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_NeutralHadronEt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_NeutralHadronEt_isLoaded = true;
  }
  return mus_isoR04_pf_NeutralHadronEt_;
}

const vector<float> &CMS3::mus_isoR04_pf_NeutralHadronEtHighThreshold() {
  if (not mus_isoR04_pf_NeutralHadronEtHighThreshold_isLoaded) {
    if (mus_isoR04_pf_NeutralHadronEtHighThreshold_branch != 0) {
      mus_isoR04_pf_NeutralHadronEtHighThreshold_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_NeutralHadronEtHighThreshold_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_NeutralHadronEtHighThreshold_isLoaded = true;
  }
  return mus_isoR04_pf_NeutralHadronEtHighThreshold_;
}

const vector<float> &CMS3::mus_isoR04_pf_PUPt() {
  if (not mus_isoR04_pf_PUPt_isLoaded) {
    if (mus_isoR04_pf_PUPt_branch != 0) {
      mus_isoR04_pf_PUPt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_PUPt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_PUPt_isLoaded = true;
  }
  return mus_isoR04_pf_PUPt_;
}

const vector<float> &CMS3::mus_isoR04_pf_PhotonEt() {
  if (not mus_isoR04_pf_PhotonEt_isLoaded) {
    if (mus_isoR04_pf_PhotonEt_branch != 0) {
      mus_isoR04_pf_PhotonEt_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_PhotonEt_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_PhotonEt_isLoaded = true;
  }
  return mus_isoR04_pf_PhotonEt_;
}

const vector<float> &CMS3::mus_isoR04_pf_PhotonEtHighThreshold() {
  if (not mus_isoR04_pf_PhotonEtHighThreshold_isLoaded) {
    if (mus_isoR04_pf_PhotonEtHighThreshold_branch != 0) {
      mus_isoR04_pf_PhotonEtHighThreshold_branch->GetEntry(index);
    } else {
      printf("branch mus_isoR04_pf_PhotonEtHighThreshold_branch does not exist!\n");
      exit(1);
    }
    mus_isoR04_pf_PhotonEtHighThreshold_isLoaded = true;
  }
  return mus_isoR04_pf_PhotonEtHighThreshold_;
}

const vector<float> &CMS3::mus_iso_ecalvetoDep() {
  if (not mus_iso_ecalvetoDep_isLoaded) {
    if (mus_iso_ecalvetoDep_branch != 0) {
      mus_iso_ecalvetoDep_branch->GetEntry(index);
    } else {
      printf("branch mus_iso_ecalvetoDep_branch does not exist!\n");
      exit(1);
    }
    mus_iso_ecalvetoDep_isLoaded = true;
  }
  return mus_iso_ecalvetoDep_;
}

const vector<float> &CMS3::mus_iso_hcalvetoDep() {
  if (not mus_iso_hcalvetoDep_isLoaded) {
    if (mus_iso_hcalvetoDep_branch != 0) {
      mus_iso_hcalvetoDep_branch->GetEntry(index);
    } else {
      printf("branch mus_iso_hcalvetoDep_branch does not exist!\n");
      exit(1);
    }
    mus_iso_hcalvetoDep_isLoaded = true;
  }
  return mus_iso_hcalvetoDep_;
}

const vector<float> &CMS3::mus_iso_hovetoDep() {
  if (not mus_iso_hovetoDep_isLoaded) {
    if (mus_iso_hovetoDep_branch != 0) {
      mus_iso_hovetoDep_branch->GetEntry(index);
    } else {
      printf("branch mus_iso_hovetoDep_branch does not exist!\n");
      exit(1);
    }
    mus_iso_hovetoDep_isLoaded = true;
  }
  return mus_iso_hovetoDep_;
}

const vector<float> &CMS3::mus_iso_trckvetoDep() {
  if (not mus_iso_trckvetoDep_isLoaded) {
    if (mus_iso_trckvetoDep_branch != 0) {
      mus_iso_trckvetoDep_branch->GetEntry(index);
    } else {
      printf("branch mus_iso_trckvetoDep_branch does not exist!\n");
      exit(1);
    }
    mus_iso_trckvetoDep_isLoaded = true;
  }
  return mus_iso_trckvetoDep_;
}

const vector<float> &CMS3::mus_mc_patMatch_dr() {
  if (not mus_mc_patMatch_dr_isLoaded) {
    if (mus_mc_patMatch_dr_branch != 0) {
      mus_mc_patMatch_dr_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_patMatch_dr_branch does not exist!\n");
      exit(1);
    }
    mus_mc_patMatch_dr_isLoaded = true;
  }
  return mus_mc_patMatch_dr_;
}

const vector<float> &CMS3::mus_miniIso_ch() {
  if (not mus_miniIso_ch_isLoaded) {
    if (mus_miniIso_ch_branch != 0) {
      mus_miniIso_ch_branch->GetEntry(index);
    } else {
      printf("branch mus_miniIso_ch_branch does not exist!\n");
      exit(1);
    }
    mus_miniIso_ch_isLoaded = true;
  }
  return mus_miniIso_ch_;
}

const vector<float> &CMS3::mus_miniIso_db() {
  if (not mus_miniIso_db_isLoaded) {
    if (mus_miniIso_db_branch != 0) {
      mus_miniIso_db_branch->GetEntry(index);
    } else {
      printf("branch mus_miniIso_db_branch does not exist!\n");
      exit(1);
    }
    mus_miniIso_db_isLoaded = true;
  }
  return mus_miniIso_db_;
}

const vector<float> &CMS3::mus_miniIso_em() {
  if (not mus_miniIso_em_isLoaded) {
    if (mus_miniIso_em_branch != 0) {
      mus_miniIso_em_branch->GetEntry(index);
    } else {
      printf("branch mus_miniIso_em_branch does not exist!\n");
      exit(1);
    }
    mus_miniIso_em_isLoaded = true;
  }
  return mus_miniIso_em_;
}

const vector<float> &CMS3::mus_miniIso_nh() {
  if (not mus_miniIso_nh_isLoaded) {
    if (mus_miniIso_nh_branch != 0) {
      mus_miniIso_nh_branch->GetEntry(index);
    } else {
      printf("branch mus_miniIso_nh_branch does not exist!\n");
      exit(1);
    }
    mus_miniIso_nh_isLoaded = true;
  }
  return mus_miniIso_nh_;
}

const vector<float> &CMS3::mus_miniIso_uncor() {
  if (not mus_miniIso_uncor_isLoaded) {
    if (mus_miniIso_uncor_branch != 0) {
      mus_miniIso_uncor_branch->GetEntry(index);
    } else {
      printf("branch mus_miniIso_uncor_branch does not exist!\n");
      exit(1);
    }
    mus_miniIso_uncor_isLoaded = true;
  }
  return mus_miniIso_uncor_;
}

const vector<float> &CMS3::mus_ptErr() {
  if (not mus_ptErr_isLoaded) {
    if (mus_ptErr_branch != 0) {
      mus_ptErr_branch->GetEntry(index);
    } else {
      printf("branch mus_ptErr_branch does not exist!\n");
      exit(1);
    }
    mus_ptErr_isLoaded = true;
  }
  return mus_ptErr_;
}

const vector<float> &CMS3::mus_segmCompatibility() {
  if (not mus_segmCompatibility_isLoaded) {
    if (mus_segmCompatibility_branch != 0) {
      mus_segmCompatibility_branch->GetEntry(index);
    } else {
      printf("branch mus_segmCompatibility_branch does not exist!\n");
      exit(1);
    }
    mus_segmCompatibility_isLoaded = true;
  }
  return mus_segmCompatibility_;
}

const vector<float> &CMS3::mus_trkKink() {
  if (not mus_trkKink_isLoaded) {
    if (mus_trkKink_branch != 0) {
      mus_trkKink_branch->GetEntry(index);
    } else {
      printf("branch mus_trkKink_branch does not exist!\n");
      exit(1);
    }
    mus_trkKink_isLoaded = true;
  }
  return mus_trkKink_;
}

const vector<float> &CMS3::mus_z0Err() {
  if (not mus_z0Err_isLoaded) {
    if (mus_z0Err_branch != 0) {
      mus_z0Err_branch->GetEntry(index);
    } else {
      printf("branch mus_z0Err_branch does not exist!\n");
      exit(1);
    }
    mus_z0Err_isLoaded = true;
  }
  return mus_z0Err_;
}

const vector<float> &CMS3::pfcands_dxy() {
  if (not pfcands_dxy_isLoaded) {
    if (pfcands_dxy_branch != 0) {
      pfcands_dxy_branch->GetEntry(index);
    } else {
      printf("branch pfcands_dxy_branch does not exist!\n");
      exit(1);
    }
    pfcands_dxy_isLoaded = true;
  }
  return pfcands_dxy_;
}

const vector<float> &CMS3::pfcands_dxyError() {
  if (not pfcands_dxyError_isLoaded) {
    if (pfcands_dxyError_branch != 0) {
      pfcands_dxyError_branch->GetEntry(index);
    } else {
      printf("branch pfcands_dxyError_branch does not exist!\n");
      exit(1);
    }
    pfcands_dxyError_isLoaded = true;
  }
  return pfcands_dxyError_;
}

const vector<float> &CMS3::pfcands_dz() {
  if (not pfcands_dz_isLoaded) {
    if (pfcands_dz_branch != 0) {
      pfcands_dz_branch->GetEntry(index);
    } else {
      printf("branch pfcands_dz_branch does not exist!\n");
      exit(1);
    }
    pfcands_dz_isLoaded = true;
  }
  return pfcands_dz_;
}

const vector<float> &CMS3::pfcands_dzAssociatedPV() {
  if (not pfcands_dzAssociatedPV_isLoaded) {
    if (pfcands_dzAssociatedPV_branch != 0) {
      pfcands_dzAssociatedPV_branch->GetEntry(index);
    } else {
      printf("branch pfcands_dzAssociatedPV_branch does not exist!\n");
      exit(1);
    }
    pfcands_dzAssociatedPV_isLoaded = true;
  }
  return pfcands_dzAssociatedPV_;
}

const vector<float> &CMS3::pfcands_dzError() {
  if (not pfcands_dzError_isLoaded) {
    if (pfcands_dzError_branch != 0) {
      pfcands_dzError_branch->GetEntry(index);
    } else {
      printf("branch pfcands_dzError_branch does not exist!\n");
      exit(1);
    }
    pfcands_dzError_isLoaded = true;
  }
  return pfcands_dzError_;
}

const vector<float> &CMS3::pfcands_mass() {
  if (not pfcands_mass_isLoaded) {
    if (pfcands_mass_branch != 0) {
      pfcands_mass_branch->GetEntry(index);
    } else {
      printf("branch pfcands_mass_branch does not exist!\n");
      exit(1);
    }
    pfcands_mass_isLoaded = true;
  }
  return pfcands_mass_;
}

const vector<float> &CMS3::pfcands_miniTrackIso() {
  if (not pfcands_miniTrackIso_isLoaded) {
    if (pfcands_miniTrackIso_branch != 0) {
      pfcands_miniTrackIso_branch->GetEntry(index);
    } else {
      printf("branch pfcands_miniTrackIso_branch does not exist!\n");
      exit(1);
    }
    pfcands_miniTrackIso_isLoaded = true;
  }
  return pfcands_miniTrackIso_;
}

const vector<float> &CMS3::pfcands_puppiWeight() {
  if (not pfcands_puppiWeight_isLoaded) {
    if (pfcands_puppiWeight_branch != 0) {
      pfcands_puppiWeight_branch->GetEntry(index);
    } else {
      printf("branch pfcands_puppiWeight_branch does not exist!\n");
      exit(1);
    }
    pfcands_puppiWeight_isLoaded = true;
  }
  return pfcands_puppiWeight_;
}

const vector<float> &CMS3::pfcands_puppiWeightNoLep() {
  if (not pfcands_puppiWeightNoLep_isLoaded) {
    if (pfcands_puppiWeightNoLep_branch != 0) {
      pfcands_puppiWeightNoLep_branch->GetEntry(index);
    } else {
      printf("branch pfcands_puppiWeightNoLep_branch does not exist!\n");
      exit(1);
    }
    pfcands_puppiWeightNoLep_isLoaded = true;
  }
  return pfcands_puppiWeightNoLep_;
}

const vector<float> &CMS3::pfcands_trackIso() {
  if (not pfcands_trackIso_isLoaded) {
    if (pfcands_trackIso_branch != 0) {
      pfcands_trackIso_branch->GetEntry(index);
    } else {
      printf("branch pfcands_trackIso_branch does not exist!\n");
      exit(1);
    }
    pfcands_trackIso_isLoaded = true;
  }
  return pfcands_trackIso_;
}

const vector<float> &CMS3::pfjets_area() {
  if (not pfjets_area_isLoaded) {
    if (pfjets_area_branch != 0) {
      pfjets_area_branch->GetEntry(index);
    } else {
      printf("branch pfjets_area_branch does not exist!\n");
      exit(1);
    }
    pfjets_area_isLoaded = true;
  }
  return pfjets_area_;
}

const vector<float> &CMS3::pfjets_axis1() {
  if (not pfjets_axis1_isLoaded) {
    if (pfjets_axis1_branch != 0) {
      pfjets_axis1_branch->GetEntry(index);
    } else {
      printf("branch pfjets_axis1_branch does not exist!\n");
      exit(1);
    }
    pfjets_axis1_isLoaded = true;
  }
  return pfjets_axis1_;
}

const vector<float> &CMS3::pfjets_chargedEmE() {
  if (not pfjets_chargedEmE_isLoaded) {
    if (pfjets_chargedEmE_branch != 0) {
      pfjets_chargedEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_chargedEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_chargedEmE_isLoaded = true;
  }
  return pfjets_chargedEmE_;
}

const vector<float> &CMS3::pfjets_chargedHadronE() {
  if (not pfjets_chargedHadronE_isLoaded) {
    if (pfjets_chargedHadronE_branch != 0) {
      pfjets_chargedHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_chargedHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_chargedHadronE_isLoaded = true;
  }
  return pfjets_chargedHadronE_;
}

const vector<float> &CMS3::pfjets_electronE() {
  if (not pfjets_electronE_isLoaded) {
    if (pfjets_electronE_branch != 0) {
      pfjets_electronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_electronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_electronE_isLoaded = true;
  }
  return pfjets_electronE_;
}

const vector<float> &CMS3::pfjets_hfEmE() {
  if (not pfjets_hfEmE_isLoaded) {
    if (pfjets_hfEmE_branch != 0) {
      pfjets_hfEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_hfEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_hfEmE_isLoaded = true;
  }
  return pfjets_hfEmE_;
}

const vector<float> &CMS3::pfjets_hfHadronE() {
  if (not pfjets_hfHadronE_isLoaded) {
    if (pfjets_hfHadronE_branch != 0) {
      pfjets_hfHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_hfHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_hfHadronE_isLoaded = true;
  }
  return pfjets_hfHadronE_;
}

const vector<float> &CMS3::pfjets_muonE() {
  if (not pfjets_muonE_isLoaded) {
    if (pfjets_muonE_branch != 0) {
      pfjets_muonE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_muonE_branch does not exist!\n");
      exit(1);
    }
    pfjets_muonE_isLoaded = true;
  }
  return pfjets_muonE_;
}

const vector<float> &CMS3::pfjets_neutralEmE() {
  if (not pfjets_neutralEmE_isLoaded) {
    if (pfjets_neutralEmE_branch != 0) {
      pfjets_neutralEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_neutralEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_neutralEmE_isLoaded = true;
  }
  return pfjets_neutralEmE_;
}

const vector<float> &CMS3::pfjets_neutralHadronE() {
  if (not pfjets_neutralHadronE_isLoaded) {
    if (pfjets_neutralHadronE_branch != 0) {
      pfjets_neutralHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_neutralHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_neutralHadronE_isLoaded = true;
  }
  return pfjets_neutralHadronE_;
}

const vector<float> &CMS3::pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag() {
  if (not pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded) {
    if (pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch != 0) {
      pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded = true;
  }
  return pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag_;
}

const vector<float> &CMS3::pfjets_pfDeepCSVJetTagsprobbPlusprobbb() {
  if (not pfjets_pfDeepCSVJetTagsprobbPlusprobbb_isLoaded) {
    if (pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch != 0) {
      pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pfDeepCSVJetTagsprobbPlusprobbb_branch does not exist!\n");
      exit(1);
    }
    pfjets_pfDeepCSVJetTagsprobbPlusprobbb_isLoaded = true;
  }
  return pfjets_pfDeepCSVJetTagsprobbPlusprobbb_;
}

const vector<float> &CMS3::pfjets_photonE() {
  if (not pfjets_photonE_isLoaded) {
    if (pfjets_photonE_branch != 0) {
      pfjets_photonE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_photonE_branch does not exist!\n");
      exit(1);
    }
    pfjets_photonE_isLoaded = true;
  }
  return pfjets_photonE_;
}

const vector<float> &CMS3::pfjets_pileupJetId() {
  if (not pfjets_pileupJetId_isLoaded) {
    if (pfjets_pileupJetId_branch != 0) {
      pfjets_pileupJetId_branch->GetEntry(index);
    } else {
      printf("branch pfjets_pileupJetId_branch does not exist!\n");
      exit(1);
    }
    pfjets_pileupJetId_isLoaded = true;
  }
  return pfjets_pileupJetId_;
}

const vector<float> &CMS3::pfjets_ptDistribution() {
  if (not pfjets_ptDistribution_isLoaded) {
    if (pfjets_ptDistribution_branch != 0) {
      pfjets_ptDistribution_branch->GetEntry(index);
    } else {
      printf("branch pfjets_ptDistribution_branch does not exist!\n");
      exit(1);
    }
    pfjets_ptDistribution_isLoaded = true;
  }
  return pfjets_ptDistribution_;
}

const vector<float> &CMS3::pfjets_undoJEC() {
  if (not pfjets_undoJEC_isLoaded) {
    if (pfjets_undoJEC_branch != 0) {
      pfjets_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch pfjets_undoJEC_branch does not exist!\n");
      exit(1);
    }
    pfjets_undoJEC_isLoaded = true;
  }
  return pfjets_undoJEC_;
}

const vector<float> &CMS3::pfjets_puppi_area() {
  if (not pfjets_puppi_area_isLoaded) {
    if (pfjets_puppi_area_branch != 0) {
      pfjets_puppi_area_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_area_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_area_isLoaded = true;
  }
  return pfjets_puppi_area_;
}

const vector<float> &CMS3::pfjets_puppi_axis1() {
  if (not pfjets_puppi_axis1_isLoaded) {
    if (pfjets_puppi_axis1_branch != 0) {
      pfjets_puppi_axis1_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_axis1_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_axis1_isLoaded = true;
  }
  return pfjets_puppi_axis1_;
}

const vector<float> &CMS3::pfjets_puppi_chargedEmE() {
  if (not pfjets_puppi_chargedEmE_isLoaded) {
    if (pfjets_puppi_chargedEmE_branch != 0) {
      pfjets_puppi_chargedEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_chargedEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_chargedEmE_isLoaded = true;
  }
  return pfjets_puppi_chargedEmE_;
}

const vector<float> &CMS3::pfjets_puppi_chargedHadronE() {
  if (not pfjets_puppi_chargedHadronE_isLoaded) {
    if (pfjets_puppi_chargedHadronE_branch != 0) {
      pfjets_puppi_chargedHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_chargedHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_chargedHadronE_isLoaded = true;
  }
  return pfjets_puppi_chargedHadronE_;
}

const vector<float> &CMS3::pfjets_puppi_electronE() {
  if (not pfjets_puppi_electronE_isLoaded) {
    if (pfjets_puppi_electronE_branch != 0) {
      pfjets_puppi_electronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_electronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_electronE_isLoaded = true;
  }
  return pfjets_puppi_electronE_;
}

const vector<float> &CMS3::pfjets_puppi_hfEmE() {
  if (not pfjets_puppi_hfEmE_isLoaded) {
    if (pfjets_puppi_hfEmE_branch != 0) {
      pfjets_puppi_hfEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_hfEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_hfEmE_isLoaded = true;
  }
  return pfjets_puppi_hfEmE_;
}

const vector<float> &CMS3::pfjets_puppi_hfHadronE() {
  if (not pfjets_puppi_hfHadronE_isLoaded) {
    if (pfjets_puppi_hfHadronE_branch != 0) {
      pfjets_puppi_hfHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_hfHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_hfHadronE_isLoaded = true;
  }
  return pfjets_puppi_hfHadronE_;
}

const vector<float> &CMS3::pfjets_puppi_muonE() {
  if (not pfjets_puppi_muonE_isLoaded) {
    if (pfjets_puppi_muonE_branch != 0) {
      pfjets_puppi_muonE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_muonE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_muonE_isLoaded = true;
  }
  return pfjets_puppi_muonE_;
}

const vector<float> &CMS3::pfjets_puppi_neutralEmE() {
  if (not pfjets_puppi_neutralEmE_isLoaded) {
    if (pfjets_puppi_neutralEmE_branch != 0) {
      pfjets_puppi_neutralEmE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_neutralEmE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_neutralEmE_isLoaded = true;
  }
  return pfjets_puppi_neutralEmE_;
}

const vector<float> &CMS3::pfjets_puppi_neutralHadronE() {
  if (not pfjets_puppi_neutralHadronE_isLoaded) {
    if (pfjets_puppi_neutralHadronE_branch != 0) {
      pfjets_puppi_neutralHadronE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_neutralHadronE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_neutralHadronE_isLoaded = true;
  }
  return pfjets_puppi_neutralHadronE_;
}

const vector<float> &CMS3::pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag() {
  if (not pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded) {
    if (pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch != 0) {
      pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_isLoaded = true;
  }
  return pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag_;
}

const vector<float> &CMS3::pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb() {
  if (not pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_isLoaded) {
    if (pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch != 0) {
      pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_isLoaded = true;
  }
  return pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb_;
}

const vector<float> &CMS3::pfjets_puppi_photonE() {
  if (not pfjets_puppi_photonE_isLoaded) {
    if (pfjets_puppi_photonE_branch != 0) {
      pfjets_puppi_photonE_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_photonE_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_photonE_isLoaded = true;
  }
  return pfjets_puppi_photonE_;
}

const vector<float> &CMS3::pfjets_puppi_pileupJetId() {
  if (not pfjets_puppi_pileupJetId_isLoaded) {
    if (pfjets_puppi_pileupJetId_branch != 0) {
      pfjets_puppi_pileupJetId_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_pileupJetId_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_pileupJetId_isLoaded = true;
  }
  return pfjets_puppi_pileupJetId_;
}

const vector<float> &CMS3::pfjets_puppi_ptDistribution() {
  if (not pfjets_puppi_ptDistribution_isLoaded) {
    if (pfjets_puppi_ptDistribution_branch != 0) {
      pfjets_puppi_ptDistribution_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_ptDistribution_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_ptDistribution_isLoaded = true;
  }
  return pfjets_puppi_ptDistribution_;
}

const vector<float> &CMS3::pfjets_puppi_undoJEC() {
  if (not pfjets_puppi_undoJEC_isLoaded) {
    if (pfjets_puppi_undoJEC_branch != 0) {
      pfjets_puppi_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_undoJEC_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_undoJEC_isLoaded = true;
  }
  return pfjets_puppi_undoJEC_;
}

const vector<float> &CMS3::photons_ecalPFClusterIso() {
  if (not photons_ecalPFClusterIso_isLoaded) {
    if (photons_ecalPFClusterIso_branch != 0) {
      photons_ecalPFClusterIso_branch->GetEntry(index);
    } else {
      printf("branch photons_ecalPFClusterIso_branch does not exist!\n");
      exit(1);
    }
    photons_ecalPFClusterIso_isLoaded = true;
  }
  return photons_ecalPFClusterIso_;
}

const vector<float> &CMS3::photons_full5x5_hOverE() {
  if (not photons_full5x5_hOverE_isLoaded) {
    if (photons_full5x5_hOverE_branch != 0) {
      photons_full5x5_hOverE_branch->GetEntry(index);
    } else {
      printf("branch photons_full5x5_hOverE_branch does not exist!\n");
      exit(1);
    }
    photons_full5x5_hOverE_isLoaded = true;
  }
  return photons_full5x5_hOverE_;
}

const vector<float> &CMS3::photons_full5x5_hOverEtowBC() {
  if (not photons_full5x5_hOverEtowBC_isLoaded) {
    if (photons_full5x5_hOverEtowBC_branch != 0) {
      photons_full5x5_hOverEtowBC_branch->GetEntry(index);
    } else {
      printf("branch photons_full5x5_hOverEtowBC_branch does not exist!\n");
      exit(1);
    }
    photons_full5x5_hOverEtowBC_isLoaded = true;
  }
  return photons_full5x5_hOverEtowBC_;
}

const vector<float> &CMS3::photons_full5x5_r9() {
  if (not photons_full5x5_r9_isLoaded) {
    if (photons_full5x5_r9_branch != 0) {
      photons_full5x5_r9_branch->GetEntry(index);
    } else {
      printf("branch photons_full5x5_r9_branch does not exist!\n");
      exit(1);
    }
    photons_full5x5_r9_isLoaded = true;
  }
  return photons_full5x5_r9_;
}

const vector<float> &CMS3::photons_full5x5_sigmaIEtaIEta() {
  if (not photons_full5x5_sigmaIEtaIEta_isLoaded) {
    if (photons_full5x5_sigmaIEtaIEta_branch != 0) {
      photons_full5x5_sigmaIEtaIEta_branch->GetEntry(index);
    } else {
      printf("branch photons_full5x5_sigmaIEtaIEta_branch does not exist!\n");
      exit(1);
    }
    photons_full5x5_sigmaIEtaIEta_isLoaded = true;
  }
  return photons_full5x5_sigmaIEtaIEta_;
}

const vector<float> &CMS3::photons_hOverE() {
  if (not photons_hOverE_isLoaded) {
    if (photons_hOverE_branch != 0) {
      photons_hOverE_branch->GetEntry(index);
    } else {
      printf("branch photons_hOverE_branch does not exist!\n");
      exit(1);
    }
    photons_hOverE_isLoaded = true;
  }
  return photons_hOverE_;
}

const vector<float> &CMS3::photons_hOverEtowBC() {
  if (not photons_hOverEtowBC_isLoaded) {
    if (photons_hOverEtowBC_branch != 0) {
      photons_hOverEtowBC_branch->GetEntry(index);
    } else {
      printf("branch photons_hOverEtowBC_branch does not exist!\n");
      exit(1);
    }
    photons_hOverEtowBC_isLoaded = true;
  }
  return photons_hOverEtowBC_;
}

const vector<float> &CMS3::photons_hcalPFClusterIso() {
  if (not photons_hcalPFClusterIso_isLoaded) {
    if (photons_hcalPFClusterIso_branch != 0) {
      photons_hcalPFClusterIso_branch->GetEntry(index);
    } else {
      printf("branch photons_hcalPFClusterIso_branch does not exist!\n");
      exit(1);
    }
    photons_hcalPFClusterIso_isLoaded = true;
  }
  return photons_hcalPFClusterIso_;
}

const vector<float> &CMS3::photons_ntkIsoHollow03() {
  if (not photons_ntkIsoHollow03_isLoaded) {
    if (photons_ntkIsoHollow03_branch != 0) {
      photons_ntkIsoHollow03_branch->GetEntry(index);
    } else {
      printf("branch photons_ntkIsoHollow03_branch does not exist!\n");
      exit(1);
    }
    photons_ntkIsoHollow03_isLoaded = true;
  }
  return photons_ntkIsoHollow03_;
}

const vector<float> &CMS3::photons_recoChargedHadronIso() {
  if (not photons_recoChargedHadronIso_isLoaded) {
    if (photons_recoChargedHadronIso_branch != 0) {
      photons_recoChargedHadronIso_branch->GetEntry(index);
    } else {
      printf("branch photons_recoChargedHadronIso_branch does not exist!\n");
      exit(1);
    }
    photons_recoChargedHadronIso_isLoaded = true;
  }
  return photons_recoChargedHadronIso_;
}

const vector<float> &CMS3::photons_recoNeutralHadronIso() {
  if (not photons_recoNeutralHadronIso_isLoaded) {
    if (photons_recoNeutralHadronIso_branch != 0) {
      photons_recoNeutralHadronIso_branch->GetEntry(index);
    } else {
      printf("branch photons_recoNeutralHadronIso_branch does not exist!\n");
      exit(1);
    }
    photons_recoNeutralHadronIso_isLoaded = true;
  }
  return photons_recoNeutralHadronIso_;
}

const vector<float> &CMS3::photons_recoPhotonIso() {
  if (not photons_recoPhotonIso_isLoaded) {
    if (photons_recoPhotonIso_branch != 0) {
      photons_recoPhotonIso_branch->GetEntry(index);
    } else {
      printf("branch photons_recoPhotonIso_branch does not exist!\n");
      exit(1);
    }
    photons_recoPhotonIso_isLoaded = true;
  }
  return photons_recoPhotonIso_;
}

const vector<float> &CMS3::photons_sigmaIEtaIEta() {
  if (not photons_sigmaIEtaIEta_isLoaded) {
    if (photons_sigmaIEtaIEta_branch != 0) {
      photons_sigmaIEtaIEta_branch->GetEntry(index);
    } else {
      printf("branch photons_sigmaIEtaIEta_branch does not exist!\n");
      exit(1);
    }
    photons_sigmaIEtaIEta_isLoaded = true;
  }
  return photons_sigmaIEtaIEta_;
}

const vector<float> &CMS3::photons_tkIsoHollow03() {
  if (not photons_tkIsoHollow03_isLoaded) {
    if (photons_tkIsoHollow03_branch != 0) {
      photons_tkIsoHollow03_branch->GetEntry(index);
    } else {
      printf("branch photons_tkIsoHollow03_branch does not exist!\n");
      exit(1);
    }
    photons_tkIsoHollow03_isLoaded = true;
  }
  return photons_tkIsoHollow03_;
}

const vector<float> &CMS3::puInfo_trueNumInteractions() {
  if (not puInfo_trueNumInteractions_isLoaded) {
    if (puInfo_trueNumInteractions_branch != 0) {
      puInfo_trueNumInteractions_branch->GetEntry(index);
    } else {
      printf("branch puInfo_trueNumInteractions_branch does not exist!\n");
      exit(1);
    }
    puInfo_trueNumInteractions_isLoaded = true;
  }
  return puInfo_trueNumInteractions_;
}

const vector<float> &CMS3::svs_anglePV() {
  if (not svs_anglePV_isLoaded) {
    if (svs_anglePV_branch != 0) {
      svs_anglePV_branch->GetEntry(index);
    } else {
      printf("branch svs_anglePV_branch does not exist!\n");
      exit(1);
    }
    svs_anglePV_isLoaded = true;
  }
  return svs_anglePV_;
}

const vector<float> &CMS3::svs_chi2() {
  if (not svs_chi2_isLoaded) {
    if (svs_chi2_branch != 0) {
      svs_chi2_branch->GetEntry(index);
    } else {
      printf("branch svs_chi2_branch does not exist!\n");
      exit(1);
    }
    svs_chi2_isLoaded = true;
  }
  return svs_chi2_;
}

const vector<float> &CMS3::svs_dist3Dsig() {
  if (not svs_dist3Dsig_isLoaded) {
    if (svs_dist3Dsig_branch != 0) {
      svs_dist3Dsig_branch->GetEntry(index);
    } else {
      printf("branch svs_dist3Dsig_branch does not exist!\n");
      exit(1);
    }
    svs_dist3Dsig_isLoaded = true;
  }
  return svs_dist3Dsig_;
}

const vector<float> &CMS3::svs_dist3Dval() {
  if (not svs_dist3Dval_isLoaded) {
    if (svs_dist3Dval_branch != 0) {
      svs_dist3Dval_branch->GetEntry(index);
    } else {
      printf("branch svs_dist3Dval_branch does not exist!\n");
      exit(1);
    }
    svs_dist3Dval_isLoaded = true;
  }
  return svs_dist3Dval_;
}

const vector<float> &CMS3::svs_distXYsig() {
  if (not svs_distXYsig_isLoaded) {
    if (svs_distXYsig_branch != 0) {
      svs_distXYsig_branch->GetEntry(index);
    } else {
      printf("branch svs_distXYsig_branch does not exist!\n");
      exit(1);
    }
    svs_distXYsig_isLoaded = true;
  }
  return svs_distXYsig_;
}

const vector<float> &CMS3::svs_distXYval() {
  if (not svs_distXYval_isLoaded) {
    if (svs_distXYval_branch != 0) {
      svs_distXYval_branch->GetEntry(index);
    } else {
      printf("branch svs_distXYval_branch does not exist!\n");
      exit(1);
    }
    svs_distXYval_isLoaded = true;
  }
  return svs_distXYval_;
}

const vector<float> &CMS3::svs_ndof() {
  if (not svs_ndof_isLoaded) {
    if (svs_ndof_branch != 0) {
      svs_ndof_branch->GetEntry(index);
    } else {
      printf("branch svs_ndof_branch does not exist!\n");
      exit(1);
    }
    svs_ndof_isLoaded = true;
  }
  return svs_ndof_;
}

const vector<float> &CMS3::svs_prob() {
  if (not svs_prob_isLoaded) {
    if (svs_prob_branch != 0) {
      svs_prob_branch->GetEntry(index);
    } else {
      printf("branch svs_prob_branch does not exist!\n");
      exit(1);
    }
    svs_prob_isLoaded = true;
  }
  return svs_prob_;
}

const vector<float> &CMS3::svs_xError() {
  if (not svs_xError_isLoaded) {
    if (svs_xError_branch != 0) {
      svs_xError_branch->GetEntry(index);
    } else {
      printf("branch svs_xError_branch does not exist!\n");
      exit(1);
    }
    svs_xError_isLoaded = true;
  }
  return svs_xError_;
}

const vector<float> &CMS3::svs_yError() {
  if (not svs_yError_isLoaded) {
    if (svs_yError_branch != 0) {
      svs_yError_branch->GetEntry(index);
    } else {
      printf("branch svs_yError_branch does not exist!\n");
      exit(1);
    }
    svs_yError_isLoaded = true;
  }
  return svs_yError_;
}

const vector<float> &CMS3::svs_zError() {
  if (not svs_zError_isLoaded) {
    if (svs_zError_branch != 0) {
      svs_zError_branch->GetEntry(index);
    } else {
      printf("branch svs_zError_branch does not exist!\n");
      exit(1);
    }
    svs_zError_isLoaded = true;
  }
  return svs_zError_;
}

const vector<float> &CMS3::ak8jets_area() {
  if (not ak8jets_area_isLoaded) {
    if (ak8jets_area_branch != 0) {
      ak8jets_area_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_area_branch does not exist!\n");
      exit(1);
    }
    ak8jets_area_isLoaded = true;
  }
  return ak8jets_area_;
}

const vector<float> &CMS3::ak8jets_mass() {
  if (not ak8jets_mass_isLoaded) {
    if (ak8jets_mass_branch != 0) {
      ak8jets_mass_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_mass_branch does not exist!\n");
      exit(1);
    }
    ak8jets_mass_isLoaded = true;
  }
  return ak8jets_mass_;
}

const vector<float> &CMS3::ak8jets_nJettinessTau1() {
  if (not ak8jets_nJettinessTau1_isLoaded) {
    if (ak8jets_nJettinessTau1_branch != 0) {
      ak8jets_nJettinessTau1_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_nJettinessTau1_branch does not exist!\n");
      exit(1);
    }
    ak8jets_nJettinessTau1_isLoaded = true;
  }
  return ak8jets_nJettinessTau1_;
}

const vector<float> &CMS3::ak8jets_nJettinessTau2() {
  if (not ak8jets_nJettinessTau2_isLoaded) {
    if (ak8jets_nJettinessTau2_branch != 0) {
      ak8jets_nJettinessTau2_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_nJettinessTau2_branch does not exist!\n");
      exit(1);
    }
    ak8jets_nJettinessTau2_isLoaded = true;
  }
  return ak8jets_nJettinessTau2_;
}

const vector<float> &CMS3::ak8jets_nJettinessTau3() {
  if (not ak8jets_nJettinessTau3_isLoaded) {
    if (ak8jets_nJettinessTau3_branch != 0) {
      ak8jets_nJettinessTau3_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_nJettinessTau3_branch does not exist!\n");
      exit(1);
    }
    ak8jets_nJettinessTau3_isLoaded = true;
  }
  return ak8jets_nJettinessTau3_;
}

const vector<float> &CMS3::ak8jets_prunedMass() {
  if (not ak8jets_prunedMass_isLoaded) {
    if (ak8jets_prunedMass_branch != 0) {
      ak8jets_prunedMass_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_prunedMass_branch does not exist!\n");
      exit(1);
    }
    ak8jets_prunedMass_isLoaded = true;
  }
  return ak8jets_prunedMass_;
}

const vector<float> &CMS3::ak8jets_puppi_eta() {
  if (not ak8jets_puppi_eta_isLoaded) {
    if (ak8jets_puppi_eta_branch != 0) {
      ak8jets_puppi_eta_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_eta_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_eta_isLoaded = true;
  }
  return ak8jets_puppi_eta_;
}

const vector<float> &CMS3::ak8jets_puppi_mass() {
  if (not ak8jets_puppi_mass_isLoaded) {
    if (ak8jets_puppi_mass_branch != 0) {
      ak8jets_puppi_mass_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_mass_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_mass_isLoaded = true;
  }
  return ak8jets_puppi_mass_;
}

const vector<float> &CMS3::ak8jets_puppi_nJettinessTau1() {
  if (not ak8jets_puppi_nJettinessTau1_isLoaded) {
    if (ak8jets_puppi_nJettinessTau1_branch != 0) {
      ak8jets_puppi_nJettinessTau1_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_nJettinessTau1_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_nJettinessTau1_isLoaded = true;
  }
  return ak8jets_puppi_nJettinessTau1_;
}

const vector<float> &CMS3::ak8jets_puppi_nJettinessTau2() {
  if (not ak8jets_puppi_nJettinessTau2_isLoaded) {
    if (ak8jets_puppi_nJettinessTau2_branch != 0) {
      ak8jets_puppi_nJettinessTau2_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_nJettinessTau2_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_nJettinessTau2_isLoaded = true;
  }
  return ak8jets_puppi_nJettinessTau2_;
}

const vector<float> &CMS3::ak8jets_puppi_nJettinessTau3() {
  if (not ak8jets_puppi_nJettinessTau3_isLoaded) {
    if (ak8jets_puppi_nJettinessTau3_branch != 0) {
      ak8jets_puppi_nJettinessTau3_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_nJettinessTau3_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_nJettinessTau3_isLoaded = true;
  }
  return ak8jets_puppi_nJettinessTau3_;
}

const vector<float> &CMS3::ak8jets_puppi_phi() {
  if (not ak8jets_puppi_phi_isLoaded) {
    if (ak8jets_puppi_phi_branch != 0) {
      ak8jets_puppi_phi_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_phi_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_phi_isLoaded = true;
  }
  return ak8jets_puppi_phi_;
}

const vector<float> &CMS3::ak8jets_puppi_pt() {
  if (not ak8jets_puppi_pt_isLoaded) {
    if (ak8jets_puppi_pt_branch != 0) {
      ak8jets_puppi_pt_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_pt_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_pt_isLoaded = true;
  }
  return ak8jets_puppi_pt_;
}

const vector<float> &CMS3::ak8jets_puppi_softdropMass() {
  if (not ak8jets_puppi_softdropMass_isLoaded) {
    if (ak8jets_puppi_softdropMass_branch != 0) {
      ak8jets_puppi_softdropMass_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_puppi_softdropMass_branch does not exist!\n");
      exit(1);
    }
    ak8jets_puppi_softdropMass_isLoaded = true;
  }
  return ak8jets_puppi_softdropMass_;
}

const vector<float> &CMS3::ak8jets_softdropMass() {
  if (not ak8jets_softdropMass_isLoaded) {
    if (ak8jets_softdropMass_branch != 0) {
      ak8jets_softdropMass_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_softdropMass_branch does not exist!\n");
      exit(1);
    }
    ak8jets_softdropMass_isLoaded = true;
  }
  return ak8jets_softdropMass_;
}

const vector<float> &CMS3::ak8jets_undoJEC() {
  if (not ak8jets_undoJEC_isLoaded) {
    if (ak8jets_undoJEC_branch != 0) {
      ak8jets_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_undoJEC_branch does not exist!\n");
      exit(1);
    }
    ak8jets_undoJEC_isLoaded = true;
  }
  return ak8jets_undoJEC_;
}

const vector<float> &CMS3::vtxs_ndof() {
  if (not vtxs_ndof_isLoaded) {
    if (vtxs_ndof_branch != 0) {
      vtxs_ndof_branch->GetEntry(index);
    } else {
      printf("branch vtxs_ndof_branch does not exist!\n");
      exit(1);
    }
    vtxs_ndof_isLoaded = true;
  }
  return vtxs_ndof_;
}

const vector<vector<float> > &CMS3::pfjets_bDiscriminators() {
  if (not pfjets_bDiscriminators_isLoaded) {
    if (pfjets_bDiscriminators_branch != 0) {
      pfjets_bDiscriminators_branch->GetEntry(index);
    } else {
      printf("branch pfjets_bDiscriminators_branch does not exist!\n");
      exit(1);
    }
    pfjets_bDiscriminators_isLoaded = true;
  }
  return pfjets_bDiscriminators_;
}

const vector<vector<float> > &CMS3::pfjets_puppi_bDiscriminators() {
  if (not pfjets_puppi_bDiscriminators_isLoaded) {
    if (pfjets_puppi_bDiscriminators_branch != 0) {
      pfjets_puppi_bDiscriminators_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_bDiscriminators_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_bDiscriminators_isLoaded = true;
  }
  return pfjets_puppi_bDiscriminators_;
}

const vector<vector<float> > &CMS3::taus_pf_IDs() {
  if (not taus_pf_IDs_isLoaded) {
    if (taus_pf_IDs_branch != 0) {
      taus_pf_IDs_branch->GetEntry(index);
    } else {
      printf("branch taus_pf_IDs_branch does not exist!\n");
      exit(1);
    }
    taus_pf_IDs_isLoaded = true;
  }
  return taus_pf_IDs_;
}

const vector<vector<float> > &CMS3::puInfo_instLumi() {
  if (not puInfo_instLumi_isLoaded) {
    if (puInfo_instLumi_branch != 0) {
      puInfo_instLumi_branch->GetEntry(index);
    } else {
      printf("branch puInfo_instLumi_branch does not exist!\n");
      exit(1);
    }
    puInfo_instLumi_isLoaded = true;
  }
  return puInfo_instLumi_;
}

const int &CMS3::evt_bunchCrossing() {
  if (not evt_bunchCrossing_isLoaded) {
    if (evt_bunchCrossing_branch != 0) {
      evt_bunchCrossing_branch->GetEntry(index);
    } else {
      printf("branch evt_bunchCrossing_branch does not exist!\n");
      exit(1);
    }
    evt_bunchCrossing_isLoaded = true;
  }
  return evt_bunchCrossing_;
}

const int &CMS3::evt_experimentType() {
  if (not evt_experimentType_isLoaded) {
    if (evt_experimentType_branch != 0) {
      evt_experimentType_branch->GetEntry(index);
    } else {
      printf("branch evt_experimentType_branch does not exist!\n");
      exit(1);
    }
    evt_experimentType_isLoaded = true;
  }
  return evt_experimentType_;
}

const int &CMS3::evt_isRealData() {
  if (not evt_isRealData_isLoaded) {
    if (evt_isRealData_branch != 0) {
      evt_isRealData_branch->GetEntry(index);
    } else {
      printf("branch evt_isRealData_branch does not exist!\n");
      exit(1);
    }
    evt_isRealData_isLoaded = true;
  }
  return evt_isRealData_;
}

const int &CMS3::evt_orbitNumber() {
  if (not evt_orbitNumber_isLoaded) {
    if (evt_orbitNumber_branch != 0) {
      evt_orbitNumber_branch->GetEntry(index);
    } else {
      printf("branch evt_orbitNumber_branch does not exist!\n");
      exit(1);
    }
    evt_orbitNumber_isLoaded = true;
  }
  return evt_orbitNumber_;
}

const int &CMS3::evt_storeNumber() {
  if (not evt_storeNumber_isLoaded) {
    if (evt_storeNumber_branch != 0) {
      evt_storeNumber_branch->GetEntry(index);
    } else {
      printf("branch evt_storeNumber_branch does not exist!\n");
      exit(1);
    }
    evt_storeNumber_isLoaded = true;
  }
  return evt_storeNumber_;
}

const int &CMS3::pdfinfo_id1() {
  if (not pdfinfo_id1_isLoaded) {
    if (pdfinfo_id1_branch != 0) {
      pdfinfo_id1_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_id1_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_id1_isLoaded = true;
  }
  return pdfinfo_id1_;
}

const int &CMS3::pdfinfo_id2() {
  if (not pdfinfo_id2_isLoaded) {
    if (pdfinfo_id2_branch != 0) {
      pdfinfo_id2_branch->GetEntry(index);
    } else {
      printf("branch pdfinfo_id2_branch does not exist!\n");
      exit(1);
    }
    pdfinfo_id2_isLoaded = true;
  }
  return pdfinfo_id2_;
}

const vector<int> &CMS3::els_mc3_id() {
  if (not els_mc3_id_isLoaded) {
    if (els_mc3_id_branch != 0) {
      els_mc3_id_branch->GetEntry(index);
    } else {
      printf("branch els_mc3_id_branch does not exist!\n");
      exit(1);
    }
    els_mc3_id_isLoaded = true;
  }
  return els_mc3_id_;
}

const vector<int> &CMS3::els_mc3idx() {
  if (not els_mc3idx_isLoaded) {
    if (els_mc3idx_branch != 0) {
      els_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch els_mc3idx_branch does not exist!\n");
      exit(1);
    }
    els_mc3idx_isLoaded = true;
  }
  return els_mc3idx_;
}

const vector<int> &CMS3::els_mc3_motherid() {
  if (not els_mc3_motherid_isLoaded) {
    if (els_mc3_motherid_branch != 0) {
      els_mc3_motherid_branch->GetEntry(index);
    } else {
      printf("branch els_mc3_motherid_branch does not exist!\n");
      exit(1);
    }
    els_mc3_motherid_isLoaded = true;
  }
  return els_mc3_motherid_;
}

const vector<int> &CMS3::els_mc3_motheridx() {
  if (not els_mc3_motheridx_isLoaded) {
    if (els_mc3_motheridx_branch != 0) {
      els_mc3_motheridx_branch->GetEntry(index);
    } else {
      printf("branch els_mc3_motheridx_branch does not exist!\n");
      exit(1);
    }
    els_mc3_motheridx_isLoaded = true;
  }
  return els_mc3_motheridx_;
}

const vector<int> &CMS3::els_mc_id() {
  if (not els_mc_id_isLoaded) {
    if (els_mc_id_branch != 0) {
      els_mc_id_branch->GetEntry(index);
    } else {
      printf("branch els_mc_id_branch does not exist!\n");
      exit(1);
    }
    els_mc_id_isLoaded = true;
  }
  return els_mc_id_;
}

const vector<int> &CMS3::els_mc_motherid() {
  if (not els_mc_motherid_isLoaded) {
    if (els_mc_motherid_branch != 0) {
      els_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch els_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    els_mc_motherid_isLoaded = true;
  }
  return els_mc_motherid_;
}

const vector<int> &CMS3::mus_mc3_id() {
  if (not mus_mc3_id_isLoaded) {
    if (mus_mc3_id_branch != 0) {
      mus_mc3_id_branch->GetEntry(index);
    } else {
      printf("branch mus_mc3_id_branch does not exist!\n");
      exit(1);
    }
    mus_mc3_id_isLoaded = true;
  }
  return mus_mc3_id_;
}

const vector<int> &CMS3::mus_mc3idx() {
  if (not mus_mc3idx_isLoaded) {
    if (mus_mc3idx_branch != 0) {
      mus_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch mus_mc3idx_branch does not exist!\n");
      exit(1);
    }
    mus_mc3idx_isLoaded = true;
  }
  return mus_mc3idx_;
}

const vector<int> &CMS3::mus_mc3_motherid() {
  if (not mus_mc3_motherid_isLoaded) {
    if (mus_mc3_motherid_branch != 0) {
      mus_mc3_motherid_branch->GetEntry(index);
    } else {
      printf("branch mus_mc3_motherid_branch does not exist!\n");
      exit(1);
    }
    mus_mc3_motherid_isLoaded = true;
  }
  return mus_mc3_motherid_;
}

const vector<int> &CMS3::mus_mc3_motheridx() {
  if (not mus_mc3_motheridx_isLoaded) {
    if (mus_mc3_motheridx_branch != 0) {
      mus_mc3_motheridx_branch->GetEntry(index);
    } else {
      printf("branch mus_mc3_motheridx_branch does not exist!\n");
      exit(1);
    }
    mus_mc3_motheridx_isLoaded = true;
  }
  return mus_mc3_motheridx_;
}

const vector<int> &CMS3::mus_mc_id() {
  if (not mus_mc_id_isLoaded) {
    if (mus_mc_id_branch != 0) {
      mus_mc_id_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_id_branch does not exist!\n");
      exit(1);
    }
    mus_mc_id_isLoaded = true;
  }
  return mus_mc_id_;
}

const vector<int> &CMS3::mus_mc_motherid() {
  if (not mus_mc_motherid_isLoaded) {
    if (mus_mc_motherid_branch != 0) {
      mus_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    mus_mc_motherid_isLoaded = true;
  }
  return mus_mc_motherid_;
}

const vector<int> &CMS3::pfjets_mc3_id() {
  if (not pfjets_mc3_id_isLoaded) {
    if (pfjets_mc3_id_branch != 0) {
      pfjets_mc3_id_branch->GetEntry(index);
    } else {
      printf("branch pfjets_mc3_id_branch does not exist!\n");
      exit(1);
    }
    pfjets_mc3_id_isLoaded = true;
  }
  return pfjets_mc3_id_;
}

const vector<int> &CMS3::pfjets_mc3idx() {
  if (not pfjets_mc3idx_isLoaded) {
    if (pfjets_mc3idx_branch != 0) {
      pfjets_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch pfjets_mc3idx_branch does not exist!\n");
      exit(1);
    }
    pfjets_mc3idx_isLoaded = true;
  }
  return pfjets_mc3idx_;
}

const vector<int> &CMS3::pfjets_mc_motherid() {
  if (not pfjets_mc_motherid_isLoaded) {
    if (pfjets_mc_motherid_branch != 0) {
      pfjets_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch pfjets_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    pfjets_mc_motherid_isLoaded = true;
  }
  return pfjets_mc_motherid_;
}

const vector<int> &CMS3::photons_mc3_id() {
  if (not photons_mc3_id_isLoaded) {
    if (photons_mc3_id_branch != 0) {
      photons_mc3_id_branch->GetEntry(index);
    } else {
      printf("branch photons_mc3_id_branch does not exist!\n");
      exit(1);
    }
    photons_mc3_id_isLoaded = true;
  }
  return photons_mc3_id_;
}

const vector<int> &CMS3::photons_mc3idx() {
  if (not photons_mc3idx_isLoaded) {
    if (photons_mc3idx_branch != 0) {
      photons_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch photons_mc3idx_branch does not exist!\n");
      exit(1);
    }
    photons_mc3idx_isLoaded = true;
  }
  return photons_mc3idx_;
}

const vector<int> &CMS3::photons_mc3_motherid() {
  if (not photons_mc3_motherid_isLoaded) {
    if (photons_mc3_motherid_branch != 0) {
      photons_mc3_motherid_branch->GetEntry(index);
    } else {
      printf("branch photons_mc3_motherid_branch does not exist!\n");
      exit(1);
    }
    photons_mc3_motherid_isLoaded = true;
  }
  return photons_mc3_motherid_;
}

const vector<int> &CMS3::photons_mc3_motheridx() {
  if (not photons_mc3_motheridx_isLoaded) {
    if (photons_mc3_motheridx_branch != 0) {
      photons_mc3_motheridx_branch->GetEntry(index);
    } else {
      printf("branch photons_mc3_motheridx_branch does not exist!\n");
      exit(1);
    }
    photons_mc3_motheridx_isLoaded = true;
  }
  return photons_mc3_motheridx_;
}

const vector<int> &CMS3::photons_mc_id() {
  if (not photons_mc_id_isLoaded) {
    if (photons_mc_id_branch != 0) {
      photons_mc_id_branch->GetEntry(index);
    } else {
      printf("branch photons_mc_id_branch does not exist!\n");
      exit(1);
    }
    photons_mc_id_isLoaded = true;
  }
  return photons_mc_id_;
}

const vector<int> &CMS3::photons_mc_motherid() {
  if (not photons_mc_motherid_isLoaded) {
    if (photons_mc_motherid_branch != 0) {
      photons_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch photons_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    photons_mc_motherid_isLoaded = true;
  }
  return photons_mc_motherid_;
}

const vector<int> &CMS3::els_VIDNonTrigMvaCat() {
  if (not els_VIDNonTrigMvaCat_isLoaded) {
    if (els_VIDNonTrigMvaCat_branch != 0) {
      els_VIDNonTrigMvaCat_branch->GetEntry(index);
    } else {
      printf("branch els_VIDNonTrigMvaCat_branch does not exist!\n");
      exit(1);
    }
    els_VIDNonTrigMvaCat_isLoaded = true;
  }
  return els_VIDNonTrigMvaCat_;
}

const vector<int> &CMS3::els_VIDSpring16GPMvaCat() {
  if (not els_VIDSpring16GPMvaCat_isLoaded) {
    if (els_VIDSpring16GPMvaCat_branch != 0) {
      els_VIDSpring16GPMvaCat_branch->GetEntry(index);
    } else {
      printf("branch els_VIDSpring16GPMvaCat_branch does not exist!\n");
      exit(1);
    }
    els_VIDSpring16GPMvaCat_isLoaded = true;
  }
  return els_VIDSpring16GPMvaCat_;
}

const vector<int> &CMS3::els_VIDSpring16HZZMvaCat() {
  if (not els_VIDSpring16HZZMvaCat_isLoaded) {
    if (els_VIDSpring16HZZMvaCat_branch != 0) {
      els_VIDSpring16HZZMvaCat_branch->GetEntry(index);
    } else {
      printf("branch els_VIDSpring16HZZMvaCat_branch does not exist!\n");
      exit(1);
    }
    els_VIDSpring16HZZMvaCat_isLoaded = true;
  }
  return els_VIDSpring16HZZMvaCat_;
}

const vector<int> &CMS3::els_VIDTrigMvaCat() {
  if (not els_VIDTrigMvaCat_isLoaded) {
    if (els_VIDTrigMvaCat_branch != 0) {
      els_VIDTrigMvaCat_branch->GetEntry(index);
    } else {
      printf("branch els_VIDTrigMvaCat_branch does not exist!\n");
      exit(1);
    }
    els_VIDTrigMvaCat_isLoaded = true;
  }
  return els_VIDTrigMvaCat_;
}

const vector<int> &CMS3::els_category() {
  if (not els_category_isLoaded) {
    if (els_category_branch != 0) {
      els_category_branch->GetEntry(index);
    } else {
      printf("branch els_category_branch does not exist!\n");
      exit(1);
    }
    els_category_isLoaded = true;
  }
  return els_category_;
}

const vector<int> &CMS3::els_charge() {
  if (not els_charge_isLoaded) {
    if (els_charge_branch != 0) {
      els_charge_branch->GetEntry(index);
    } else {
      printf("branch els_charge_branch does not exist!\n");
      exit(1);
    }
    els_charge_isLoaded = true;
  }
  return els_charge_;
}

const vector<int> &CMS3::els_ckf_charge() {
  if (not els_ckf_charge_isLoaded) {
    if (els_ckf_charge_branch != 0) {
      els_ckf_charge_branch->GetEntry(index);
    } else {
      printf("branch els_ckf_charge_branch does not exist!\n");
      exit(1);
    }
    els_ckf_charge_isLoaded = true;
  }
  return els_ckf_charge_;
}

const vector<int> &CMS3::els_ckf_laywithmeas() {
  if (not els_ckf_laywithmeas_isLoaded) {
    if (els_ckf_laywithmeas_branch != 0) {
      els_ckf_laywithmeas_branch->GetEntry(index);
    } else {
      printf("branch els_ckf_laywithmeas_branch does not exist!\n");
      exit(1);
    }
    els_ckf_laywithmeas_isLoaded = true;
  }
  return els_ckf_laywithmeas_;
}

const vector<int> &CMS3::els_exp_innerlayers() {
  if (not els_exp_innerlayers_isLoaded) {
    if (els_exp_innerlayers_branch != 0) {
      els_exp_innerlayers_branch->GetEntry(index);
    } else {
      printf("branch els_exp_innerlayers_branch does not exist!\n");
      exit(1);
    }
    els_exp_innerlayers_isLoaded = true;
  }
  return els_exp_innerlayers_;
}

const vector<int> &CMS3::els_exp_outerlayers() {
  if (not els_exp_outerlayers_isLoaded) {
    if (els_exp_outerlayers_branch != 0) {
      els_exp_outerlayers_branch->GetEntry(index);
    } else {
      printf("branch els_exp_outerlayers_branch does not exist!\n");
      exit(1);
    }
    els_exp_outerlayers_isLoaded = true;
  }
  return els_exp_outerlayers_;
}

const vector<int> &CMS3::els_isEB() {
  if (not els_isEB_isLoaded) {
    if (els_isEB_branch != 0) {
      els_isEB_branch->GetEntry(index);
    } else {
      printf("branch els_isEB_branch does not exist!\n");
      exit(1);
    }
    els_isEB_isLoaded = true;
  }
  return els_isEB_;
}

const vector<int> &CMS3::els_isEcalDriven() {
  if (not els_isEcalDriven_isLoaded) {
    if (els_isEcalDriven_branch != 0) {
      els_isEcalDriven_branch->GetEntry(index);
    } else {
      printf("branch els_isEcalDriven_branch does not exist!\n");
      exit(1);
    }
    els_isEcalDriven_isLoaded = true;
  }
  return els_isEcalDriven_;
}

const vector<int> &CMS3::els_isTrackerDriven() {
  if (not els_isTrackerDriven_isLoaded) {
    if (els_isTrackerDriven_branch != 0) {
      els_isTrackerDriven_branch->GetEntry(index);
    } else {
      printf("branch els_isTrackerDriven_branch does not exist!\n");
      exit(1);
    }
    els_isTrackerDriven_isLoaded = true;
  }
  return els_isTrackerDriven_;
}

const vector<int> &CMS3::els_lostHits() {
  if (not els_lostHits_isLoaded) {
    if (els_lostHits_branch != 0) {
      els_lostHits_branch->GetEntry(index);
    } else {
      printf("branch els_lostHits_branch does not exist!\n");
      exit(1);
    }
    els_lostHits_isLoaded = true;
  }
  return els_lostHits_;
}

const vector<int> &CMS3::els_lost_pixelhits() {
  if (not els_lost_pixelhits_isLoaded) {
    if (els_lost_pixelhits_branch != 0) {
      els_lost_pixelhits_branch->GetEntry(index);
    } else {
      printf("branch els_lost_pixelhits_branch does not exist!\n");
      exit(1);
    }
    els_lost_pixelhits_isLoaded = true;
  }
  return els_lost_pixelhits_;
}

const vector<int> &CMS3::els_mc_patMatch_id() {
  if (not els_mc_patMatch_id_isLoaded) {
    if (els_mc_patMatch_id_branch != 0) {
      els_mc_patMatch_id_branch->GetEntry(index);
    } else {
      printf("branch els_mc_patMatch_id_branch does not exist!\n");
      exit(1);
    }
    els_mc_patMatch_id_isLoaded = true;
  }
  return els_mc_patMatch_id_;
}

const vector<int> &CMS3::els_nlayers() {
  if (not els_nlayers_isLoaded) {
    if (els_nlayers_branch != 0) {
      els_nlayers_branch->GetEntry(index);
    } else {
      printf("branch els_nlayers_branch does not exist!\n");
      exit(1);
    }
    els_nlayers_isLoaded = true;
  }
  return els_nlayers_;
}

const vector<int> &CMS3::els_nlayers3D() {
  if (not els_nlayers3D_isLoaded) {
    if (els_nlayers3D_branch != 0) {
      els_nlayers3D_branch->GetEntry(index);
    } else {
      printf("branch els_nlayers3D_branch does not exist!\n");
      exit(1);
    }
    els_nlayers3D_isLoaded = true;
  }
  return els_nlayers3D_;
}

const vector<int> &CMS3::els_nlayersLost() {
  if (not els_nlayersLost_isLoaded) {
    if (els_nlayersLost_branch != 0) {
      els_nlayersLost_branch->GetEntry(index);
    } else {
      printf("branch els_nlayersLost_branch does not exist!\n");
      exit(1);
    }
    els_nlayersLost_isLoaded = true;
  }
  return els_nlayersLost_;
}

const vector<int> &CMS3::els_sccharge() {
  if (not els_sccharge_isLoaded) {
    if (els_sccharge_branch != 0) {
      els_sccharge_branch->GetEntry(index);
    } else {
      printf("branch els_sccharge_branch does not exist!\n");
      exit(1);
    }
    els_sccharge_isLoaded = true;
  }
  return els_sccharge_;
}

const vector<int> &CMS3::els_trk_charge() {
  if (not els_trk_charge_isLoaded) {
    if (els_trk_charge_branch != 0) {
      els_trk_charge_branch->GetEntry(index);
    } else {
      printf("branch els_trk_charge_branch does not exist!\n");
      exit(1);
    }
    els_trk_charge_isLoaded = true;
  }
  return els_trk_charge_;
}

const vector<int> &CMS3::els_type() {
  if (not els_type_isLoaded) {
    if (els_type_branch != 0) {
      els_type_branch->GetEntry(index);
    } else {
      printf("branch els_type_branch does not exist!\n");
      exit(1);
    }
    els_type_isLoaded = true;
  }
  return els_type_;
}

const vector<int> &CMS3::els_validHits() {
  if (not els_validHits_isLoaded) {
    if (els_validHits_branch != 0) {
      els_validHits_branch->GetEntry(index);
    } else {
      printf("branch els_validHits_branch does not exist!\n");
      exit(1);
    }
    els_validHits_isLoaded = true;
  }
  return els_validHits_;
}

const vector<int> &CMS3::els_valid_pixelhits() {
  if (not els_valid_pixelhits_isLoaded) {
    if (els_valid_pixelhits_branch != 0) {
      els_valid_pixelhits_branch->GetEntry(index);
    } else {
      printf("branch els_valid_pixelhits_branch does not exist!\n");
      exit(1);
    }
    els_valid_pixelhits_isLoaded = true;
  }
  return els_valid_pixelhits_;
}

const vector<int> &CMS3::els_passVIDNonTrigMvaWP80Id() {
  if (not els_passVIDNonTrigMvaWP80Id_isLoaded) {
    if (els_passVIDNonTrigMvaWP80Id_branch != 0) {
      els_passVIDNonTrigMvaWP80Id_branch->GetEntry(index);
    } else {
      printf("branch els_passVIDNonTrigMvaWP80Id_branch does not exist!\n");
      exit(1);
    }
    els_passVIDNonTrigMvaWP80Id_isLoaded = true;
  }
  return els_passVIDNonTrigMvaWP80Id_;
}

const vector<int> &CMS3::els_passVIDNonTrigMvaWP90Id() {
  if (not els_passVIDNonTrigMvaWP90Id_isLoaded) {
    if (els_passVIDNonTrigMvaWP90Id_branch != 0) {
      els_passVIDNonTrigMvaWP90Id_branch->GetEntry(index);
    } else {
      printf("branch els_passVIDNonTrigMvaWP90Id_branch does not exist!\n");
      exit(1);
    }
    els_passVIDNonTrigMvaWP90Id_isLoaded = true;
  }
  return els_passVIDNonTrigMvaWP90Id_;
}

const vector<int> &CMS3::els_passVIDTrigMvaWP80Id() {
  if (not els_passVIDTrigMvaWP80Id_isLoaded) {
    if (els_passVIDTrigMvaWP80Id_branch != 0) {
      els_passVIDTrigMvaWP80Id_branch->GetEntry(index);
    } else {
      printf("branch els_passVIDTrigMvaWP80Id_branch does not exist!\n");
      exit(1);
    }
    els_passVIDTrigMvaWP80Id_isLoaded = true;
  }
  return els_passVIDTrigMvaWP80Id_;
}

const vector<int> &CMS3::els_passVIDTrigMvaWP90Id() {
  if (not els_passVIDTrigMvaWP90Id_isLoaded) {
    if (els_passVIDTrigMvaWP90Id_branch != 0) {
      els_passVIDTrigMvaWP90Id_branch->GetEntry(index);
    } else {
      printf("branch els_passVIDTrigMvaWP90Id_branch does not exist!\n");
      exit(1);
    }
    els_passVIDTrigMvaWP90Id_isLoaded = true;
  }
  return els_passVIDTrigMvaWP90Id_;
}

const vector<int> &CMS3::genps_id() {
  if (not genps_id_isLoaded) {
    if (genps_id_branch != 0) {
      genps_id_branch->GetEntry(index);
    } else {
      printf("branch genps_id_branch does not exist!\n");
      exit(1);
    }
    genps_id_isLoaded = true;
  }
  return genps_id_;
}

const vector<int> &CMS3::genps_id_mother() {
  if (not genps_id_mother_isLoaded) {
    if (genps_id_mother_branch != 0) {
      genps_id_mother_branch->GetEntry(index);
    } else {
      printf("branch genps_id_mother_branch does not exist!\n");
      exit(1);
    }
    genps_id_mother_isLoaded = true;
  }
  return genps_id_mother_;
}

const vector<int> &CMS3::genps_id_simplegrandma() {
  if (not genps_id_simplegrandma_isLoaded) {
    if (genps_id_simplegrandma_branch != 0) {
      genps_id_simplegrandma_branch->GetEntry(index);
    } else {
      printf("branch genps_id_simplegrandma_branch does not exist!\n");
      exit(1);
    }
    genps_id_simplegrandma_isLoaded = true;
  }
  return genps_id_simplegrandma_;
}

const vector<int> &CMS3::genps_id_simplemother() {
  if (not genps_id_simplemother_isLoaded) {
    if (genps_id_simplemother_branch != 0) {
      genps_id_simplemother_branch->GetEntry(index);
    } else {
      printf("branch genps_id_simplemother_branch does not exist!\n");
      exit(1);
    }
    genps_id_simplemother_isLoaded = true;
  }
  return genps_id_simplemother_;
}

const vector<int> &CMS3::genps_idx_mother() {
  if (not genps_idx_mother_isLoaded) {
    if (genps_idx_mother_branch != 0) {
      genps_idx_mother_branch->GetEntry(index);
    } else {
      printf("branch genps_idx_mother_branch does not exist!\n");
      exit(1);
    }
    genps_idx_mother_isLoaded = true;
  }
  return genps_idx_mother_;
}

const vector<int> &CMS3::genps_idx_simplemother() {
  if (not genps_idx_simplemother_isLoaded) {
    if (genps_idx_simplemother_branch != 0) {
      genps_idx_simplemother_branch->GetEntry(index);
    } else {
      printf("branch genps_idx_simplemother_branch does not exist!\n");
      exit(1);
    }
    genps_idx_simplemother_isLoaded = true;
  }
  return genps_idx_simplemother_;
}

const vector<int> &CMS3::genps_status() {
  if (not genps_status_isLoaded) {
    if (genps_status_branch != 0) {
      genps_status_branch->GetEntry(index);
    } else {
      printf("branch genps_status_branch does not exist!\n");
      exit(1);
    }
    genps_status_isLoaded = true;
  }
  return genps_status_;
}

const vector<int> &CMS3::hyp_ll_charge() {
  if (not hyp_ll_charge_isLoaded) {
    if (hyp_ll_charge_branch != 0) {
      hyp_ll_charge_branch->GetEntry(index);
    } else {
      printf("branch hyp_ll_charge_branch does not exist!\n");
      exit(1);
    }
    hyp_ll_charge_isLoaded = true;
  }
  return hyp_ll_charge_;
}

const vector<int> &CMS3::hyp_ll_id() {
  if (not hyp_ll_id_isLoaded) {
    if (hyp_ll_id_branch != 0) {
      hyp_ll_id_branch->GetEntry(index);
    } else {
      printf("branch hyp_ll_id_branch does not exist!\n");
      exit(1);
    }
    hyp_ll_id_isLoaded = true;
  }
  return hyp_ll_id_;
}

const vector<int> &CMS3::hyp_ll_index() {
  if (not hyp_ll_index_isLoaded) {
    if (hyp_ll_index_branch != 0) {
      hyp_ll_index_branch->GetEntry(index);
    } else {
      printf("branch hyp_ll_index_branch does not exist!\n");
      exit(1);
    }
    hyp_ll_index_isLoaded = true;
  }
  return hyp_ll_index_;
}

const vector<int> &CMS3::hyp_lt_charge() {
  if (not hyp_lt_charge_isLoaded) {
    if (hyp_lt_charge_branch != 0) {
      hyp_lt_charge_branch->GetEntry(index);
    } else {
      printf("branch hyp_lt_charge_branch does not exist!\n");
      exit(1);
    }
    hyp_lt_charge_isLoaded = true;
  }
  return hyp_lt_charge_;
}

const vector<int> &CMS3::hyp_lt_id() {
  if (not hyp_lt_id_isLoaded) {
    if (hyp_lt_id_branch != 0) {
      hyp_lt_id_branch->GetEntry(index);
    } else {
      printf("branch hyp_lt_id_branch does not exist!\n");
      exit(1);
    }
    hyp_lt_id_isLoaded = true;
  }
  return hyp_lt_id_;
}

const vector<int> &CMS3::hyp_lt_index() {
  if (not hyp_lt_index_isLoaded) {
    if (hyp_lt_index_branch != 0) {
      hyp_lt_index_branch->GetEntry(index);
    } else {
      printf("branch hyp_lt_index_branch does not exist!\n");
      exit(1);
    }
    hyp_lt_index_isLoaded = true;
  }
  return hyp_lt_index_;
}

const vector<int> &CMS3::hyp_type() {
  if (not hyp_type_isLoaded) {
    if (hyp_type_branch != 0) {
      hyp_type_branch->GetEntry(index);
    } else {
      printf("branch hyp_type_branch does not exist!\n");
      exit(1);
    }
    hyp_type_isLoaded = true;
  }
  return hyp_type_;
}

const vector<int> &CMS3::isotracks_charge() {
  if (not isotracks_charge_isLoaded) {
    if (isotracks_charge_branch != 0) {
      isotracks_charge_branch->GetEntry(index);
    } else {
      printf("branch isotracks_charge_branch does not exist!\n");
      exit(1);
    }
    isotracks_charge_isLoaded = true;
  }
  return isotracks_charge_;
}

const vector<int> &CMS3::isotracks_fromPV() {
  if (not isotracks_fromPV_isLoaded) {
    if (isotracks_fromPV_branch != 0) {
      isotracks_fromPV_branch->GetEntry(index);
    } else {
      printf("branch isotracks_fromPV_branch does not exist!\n");
      exit(1);
    }
    isotracks_fromPV_isLoaded = true;
  }
  return isotracks_fromPV_;
}

const vector<int> &CMS3::isotracks_numberOfLostHitsInner() {
  if (not isotracks_numberOfLostHitsInner_isLoaded) {
    if (isotracks_numberOfLostHitsInner_branch != 0) {
      isotracks_numberOfLostHitsInner_branch->GetEntry(index);
    } else {
      printf("branch isotracks_numberOfLostHitsInner_branch does not exist!\n");
      exit(1);
    }
    isotracks_numberOfLostHitsInner_isLoaded = true;
  }
  return isotracks_numberOfLostHitsInner_;
}

const vector<int> &CMS3::isotracks_numberOfLostHitsOuter() {
  if (not isotracks_numberOfLostHitsOuter_isLoaded) {
    if (isotracks_numberOfLostHitsOuter_branch != 0) {
      isotracks_numberOfLostHitsOuter_branch->GetEntry(index);
    } else {
      printf("branch isotracks_numberOfLostHitsOuter_branch does not exist!\n");
      exit(1);
    }
    isotracks_numberOfLostHitsOuter_isLoaded = true;
  }
  return isotracks_numberOfLostHitsOuter_;
}

const vector<int> &CMS3::isotracks_numberOfLostPixelHitsInner() {
  if (not isotracks_numberOfLostPixelHitsInner_isLoaded) {
    if (isotracks_numberOfLostPixelHitsInner_branch != 0) {
      isotracks_numberOfLostPixelHitsInner_branch->GetEntry(index);
    } else {
      printf("branch isotracks_numberOfLostPixelHitsInner_branch does not exist!\n");
      exit(1);
    }
    isotracks_numberOfLostPixelHitsInner_isLoaded = true;
  }
  return isotracks_numberOfLostPixelHitsInner_;
}

const vector<int> &CMS3::isotracks_numberOfValidPixelHits() {
  if (not isotracks_numberOfValidPixelHits_isLoaded) {
    if (isotracks_numberOfValidPixelHits_branch != 0) {
      isotracks_numberOfValidPixelHits_branch->GetEntry(index);
    } else {
      printf("branch isotracks_numberOfValidPixelHits_branch does not exist!\n");
      exit(1);
    }
    isotracks_numberOfValidPixelHits_isLoaded = true;
  }
  return isotracks_numberOfValidPixelHits_;
}

const vector<int> &CMS3::isotracks_particleId() {
  if (not isotracks_particleId_isLoaded) {
    if (isotracks_particleId_branch != 0) {
      isotracks_particleId_branch->GetEntry(index);
    } else {
      printf("branch isotracks_particleId_branch does not exist!\n");
      exit(1);
    }
    isotracks_particleId_isLoaded = true;
  }
  return isotracks_particleId_;
}

const vector<int> &CMS3::isotracks_pixelLayersWithMeasurement() {
  if (not isotracks_pixelLayersWithMeasurement_isLoaded) {
    if (isotracks_pixelLayersWithMeasurement_branch != 0) {
      isotracks_pixelLayersWithMeasurement_branch->GetEntry(index);
    } else {
      printf("branch isotracks_pixelLayersWithMeasurement_branch does not exist!\n");
      exit(1);
    }
    isotracks_pixelLayersWithMeasurement_isLoaded = true;
  }
  return isotracks_pixelLayersWithMeasurement_;
}

const vector<int> &CMS3::isotracks_trackerLayersWithMeasurement() {
  if (not isotracks_trackerLayersWithMeasurement_isLoaded) {
    if (isotracks_trackerLayersWithMeasurement_branch != 0) {
      isotracks_trackerLayersWithMeasurement_branch->GetEntry(index);
    } else {
      printf("branch isotracks_trackerLayersWithMeasurement_branch does not exist!\n");
      exit(1);
    }
    isotracks_trackerLayersWithMeasurement_isLoaded = true;
  }
  return isotracks_trackerLayersWithMeasurement_;
}

const vector<int> &CMS3::mus_algo() {
  if (not mus_algo_isLoaded) {
    if (mus_algo_branch != 0) {
      mus_algo_branch->GetEntry(index);
    } else {
      printf("branch mus_algo_branch does not exist!\n");
      exit(1);
    }
    mus_algo_isLoaded = true;
  }
  return mus_algo_;
}

const vector<int> &CMS3::mus_algoOrig() {
  if (not mus_algoOrig_isLoaded) {
    if (mus_algoOrig_branch != 0) {
      mus_algoOrig_branch->GetEntry(index);
    } else {
      printf("branch mus_algoOrig_branch does not exist!\n");
      exit(1);
    }
    mus_algoOrig_isLoaded = true;
  }
  return mus_algoOrig_;
}

const vector<int> &CMS3::mus_bfit_algo() {
  if (not mus_bfit_algo_isLoaded) {
    if (mus_bfit_algo_branch != 0) {
      mus_bfit_algo_branch->GetEntry(index);
    } else {
      printf("branch mus_bfit_algo_branch does not exist!\n");
      exit(1);
    }
    mus_bfit_algo_isLoaded = true;
  }
  return mus_bfit_algo_;
}

const vector<int> &CMS3::mus_charge() {
  if (not mus_charge_isLoaded) {
    if (mus_charge_branch != 0) {
      mus_charge_branch->GetEntry(index);
    } else {
      printf("branch mus_charge_branch does not exist!\n");
      exit(1);
    }
    mus_charge_isLoaded = true;
  }
  return mus_charge_;
}

const vector<int> &CMS3::mus_exp_innerlayers() {
  if (not mus_exp_innerlayers_isLoaded) {
    if (mus_exp_innerlayers_branch != 0) {
      mus_exp_innerlayers_branch->GetEntry(index);
    } else {
      printf("branch mus_exp_innerlayers_branch does not exist!\n");
      exit(1);
    }
    mus_exp_innerlayers_isLoaded = true;
  }
  return mus_exp_innerlayers_;
}

const vector<int> &CMS3::mus_exp_outerlayers() {
  if (not mus_exp_outerlayers_isLoaded) {
    if (mus_exp_outerlayers_branch != 0) {
      mus_exp_outerlayers_branch->GetEntry(index);
    } else {
      printf("branch mus_exp_outerlayers_branch does not exist!\n");
      exit(1);
    }
    mus_exp_outerlayers_isLoaded = true;
  }
  return mus_exp_outerlayers_;
}

const vector<int> &CMS3::mus_gfit_algo() {
  if (not mus_gfit_algo_isLoaded) {
    if (mus_gfit_algo_branch != 0) {
      mus_gfit_algo_branch->GetEntry(index);
    } else {
      printf("branch mus_gfit_algo_branch does not exist!\n");
      exit(1);
    }
    mus_gfit_algo_isLoaded = true;
  }
  return mus_gfit_algo_;
}

const vector<int> &CMS3::mus_gfit_ndof() {
  if (not mus_gfit_ndof_isLoaded) {
    if (mus_gfit_ndof_branch != 0) {
      mus_gfit_ndof_branch->GetEntry(index);
    } else {
      printf("branch mus_gfit_ndof_branch does not exist!\n");
      exit(1);
    }
    mus_gfit_ndof_isLoaded = true;
  }
  return mus_gfit_ndof_;
}

const vector<int> &CMS3::mus_gfit_validSTAHits() {
  if (not mus_gfit_validSTAHits_isLoaded) {
    if (mus_gfit_validSTAHits_branch != 0) {
      mus_gfit_validSTAHits_branch->GetEntry(index);
    } else {
      printf("branch mus_gfit_validSTAHits_branch does not exist!\n");
      exit(1);
    }
    mus_gfit_validSTAHits_isLoaded = true;
  }
  return mus_gfit_validSTAHits_;
}

const vector<int> &CMS3::mus_iso03_ntrk() {
  if (not mus_iso03_ntrk_isLoaded) {
    if (mus_iso03_ntrk_branch != 0) {
      mus_iso03_ntrk_branch->GetEntry(index);
    } else {
      printf("branch mus_iso03_ntrk_branch does not exist!\n");
      exit(1);
    }
    mus_iso03_ntrk_isLoaded = true;
  }
  return mus_iso03_ntrk_;
}

const vector<int> &CMS3::mus_lostHits() {
  if (not mus_lostHits_isLoaded) {
    if (mus_lostHits_branch != 0) {
      mus_lostHits_branch->GetEntry(index);
    } else {
      printf("branch mus_lostHits_branch does not exist!\n");
      exit(1);
    }
    mus_lostHits_isLoaded = true;
  }
  return mus_lostHits_;
}

const vector<int> &CMS3::mus_mc_patMatch_id() {
  if (not mus_mc_patMatch_id_isLoaded) {
    if (mus_mc_patMatch_id_branch != 0) {
      mus_mc_patMatch_id_branch->GetEntry(index);
    } else {
      printf("branch mus_mc_patMatch_id_branch does not exist!\n");
      exit(1);
    }
    mus_mc_patMatch_id_isLoaded = true;
  }
  return mus_mc_patMatch_id_;
}

const vector<int> &CMS3::mus_nlayers() {
  if (not mus_nlayers_isLoaded) {
    if (mus_nlayers_branch != 0) {
      mus_nlayers_branch->GetEntry(index);
    } else {
      printf("branch mus_nlayers_branch does not exist!\n");
      exit(1);
    }
    mus_nlayers_isLoaded = true;
  }
  return mus_nlayers_;
}

const vector<int> &CMS3::mus_numberOfMatchedStations() {
  if (not mus_numberOfMatchedStations_isLoaded) {
    if (mus_numberOfMatchedStations_branch != 0) {
      mus_numberOfMatchedStations_branch->GetEntry(index);
    } else {
      printf("branch mus_numberOfMatchedStations_branch does not exist!\n");
      exit(1);
    }
    mus_numberOfMatchedStations_isLoaded = true;
  }
  return mus_numberOfMatchedStations_;
}

const vector<int> &CMS3::mus_pfcharge() {
  if (not mus_pfcharge_isLoaded) {
    if (mus_pfcharge_branch != 0) {
      mus_pfcharge_branch->GetEntry(index);
    } else {
      printf("branch mus_pfcharge_branch does not exist!\n");
      exit(1);
    }
    mus_pfcharge_isLoaded = true;
  }
  return mus_pfcharge_;
}

const vector<int> &CMS3::mus_pfidx() {
  if (not mus_pfidx_isLoaded) {
    if (mus_pfidx_branch != 0) {
      mus_pfidx_branch->GetEntry(index);
    } else {
      printf("branch mus_pfidx_branch does not exist!\n");
      exit(1);
    }
    mus_pfidx_isLoaded = true;
  }
  return mus_pfidx_;
}

const vector<int> &CMS3::mus_pfparticleId() {
  if (not mus_pfparticleId_isLoaded) {
    if (mus_pfparticleId_branch != 0) {
      mus_pfparticleId_branch->GetEntry(index);
    } else {
      printf("branch mus_pfparticleId_branch does not exist!\n");
      exit(1);
    }
    mus_pfparticleId_isLoaded = true;
  }
  return mus_pfparticleId_;
}

const vector<int> &CMS3::mus_pid_PFMuon() {
  if (not mus_pid_PFMuon_isLoaded) {
    if (mus_pid_PFMuon_branch != 0) {
      mus_pid_PFMuon_branch->GetEntry(index);
    } else {
      printf("branch mus_pid_PFMuon_branch does not exist!\n");
      exit(1);
    }
    mus_pid_PFMuon_isLoaded = true;
  }
  return mus_pid_PFMuon_;
}

const vector<int> &CMS3::mus_pid_TM2DCompatibilityLoose() {
  if (not mus_pid_TM2DCompatibilityLoose_isLoaded) {
    if (mus_pid_TM2DCompatibilityLoose_branch != 0) {
      mus_pid_TM2DCompatibilityLoose_branch->GetEntry(index);
    } else {
      printf("branch mus_pid_TM2DCompatibilityLoose_branch does not exist!\n");
      exit(1);
    }
    mus_pid_TM2DCompatibilityLoose_isLoaded = true;
  }
  return mus_pid_TM2DCompatibilityLoose_;
}

const vector<int> &CMS3::mus_pid_TM2DCompatibilityTight() {
  if (not mus_pid_TM2DCompatibilityTight_isLoaded) {
    if (mus_pid_TM2DCompatibilityTight_branch != 0) {
      mus_pid_TM2DCompatibilityTight_branch->GetEntry(index);
    } else {
      printf("branch mus_pid_TM2DCompatibilityTight_branch does not exist!\n");
      exit(1);
    }
    mus_pid_TM2DCompatibilityTight_isLoaded = true;
  }
  return mus_pid_TM2DCompatibilityTight_;
}

const vector<int> &CMS3::mus_pid_TMLastStationLoose() {
  if (not mus_pid_TMLastStationLoose_isLoaded) {
    if (mus_pid_TMLastStationLoose_branch != 0) {
      mus_pid_TMLastStationLoose_branch->GetEntry(index);
    } else {
      printf("branch mus_pid_TMLastStationLoose_branch does not exist!\n");
      exit(1);
    }
    mus_pid_TMLastStationLoose_isLoaded = true;
  }
  return mus_pid_TMLastStationLoose_;
}

const vector<int> &CMS3::mus_pid_TMLastStationTight() {
  if (not mus_pid_TMLastStationTight_isLoaded) {
    if (mus_pid_TMLastStationTight_branch != 0) {
      mus_pid_TMLastStationTight_branch->GetEntry(index);
    } else {
      printf("branch mus_pid_TMLastStationTight_branch does not exist!\n");
      exit(1);
    }
    mus_pid_TMLastStationTight_isLoaded = true;
  }
  return mus_pid_TMLastStationTight_;
}

const vector<int> &CMS3::mus_pid_TMOneStationTight() {
  if (not mus_pid_TMOneStationTight_isLoaded) {
    if (mus_pid_TMOneStationTight_branch != 0) {
      mus_pid_TMOneStationTight_branch->GetEntry(index);
    } else {
      printf("branch mus_pid_TMOneStationTight_branch does not exist!\n");
      exit(1);
    }
    mus_pid_TMOneStationTight_isLoaded = true;
  }
  return mus_pid_TMOneStationTight_;
}

const vector<int> &CMS3::mus_type() {
  if (not mus_type_isLoaded) {
    if (mus_type_branch != 0) {
      mus_type_branch->GetEntry(index);
    } else {
      printf("branch mus_type_branch does not exist!\n");
      exit(1);
    }
    mus_type_isLoaded = true;
  }
  return mus_type_;
}

const vector<int> &CMS3::mus_validHits() {
  if (not mus_validHits_isLoaded) {
    if (mus_validHits_branch != 0) {
      mus_validHits_branch->GetEntry(index);
    } else {
      printf("branch mus_validHits_branch does not exist!\n");
      exit(1);
    }
    mus_validHits_isLoaded = true;
  }
  return mus_validHits_;
}

const vector<int> &CMS3::mus_validPixelHits() {
  if (not mus_validPixelHits_isLoaded) {
    if (mus_validPixelHits_branch != 0) {
      mus_validPixelHits_branch->GetEntry(index);
    } else {
      printf("branch mus_validPixelHits_branch does not exist!\n");
      exit(1);
    }
    mus_validPixelHits_isLoaded = true;
  }
  return mus_validPixelHits_;
}

const vector<int> &CMS3::pfcands_IdAssociatedPV() {
  if (not pfcands_IdAssociatedPV_isLoaded) {
    if (pfcands_IdAssociatedPV_branch != 0) {
      pfcands_IdAssociatedPV_branch->GetEntry(index);
    } else {
      printf("branch pfcands_IdAssociatedPV_branch does not exist!\n");
      exit(1);
    }
    pfcands_IdAssociatedPV_isLoaded = true;
  }
  return pfcands_IdAssociatedPV_;
}

const vector<int> &CMS3::pfcands_charge() {
  if (not pfcands_charge_isLoaded) {
    if (pfcands_charge_branch != 0) {
      pfcands_charge_branch->GetEntry(index);
    } else {
      printf("branch pfcands_charge_branch does not exist!\n");
      exit(1);
    }
    pfcands_charge_isLoaded = true;
  }
  return pfcands_charge_;
}

const vector<int> &CMS3::pfcands_numberOfHits() {
  if (not pfcands_numberOfHits_isLoaded) {
    if (pfcands_numberOfHits_branch != 0) {
      pfcands_numberOfHits_branch->GetEntry(index);
    } else {
      printf("branch pfcands_numberOfHits_branch does not exist!\n");
      exit(1);
    }
    pfcands_numberOfHits_isLoaded = true;
  }
  return pfcands_numberOfHits_;
}

const vector<int> &CMS3::pfcands_numberOfPixelHits() {
  if (not pfcands_numberOfPixelHits_isLoaded) {
    if (pfcands_numberOfPixelHits_branch != 0) {
      pfcands_numberOfPixelHits_branch->GetEntry(index);
    } else {
      printf("branch pfcands_numberOfPixelHits_branch does not exist!\n");
      exit(1);
    }
    pfcands_numberOfPixelHits_isLoaded = true;
  }
  return pfcands_numberOfPixelHits_;
}

const vector<int> &CMS3::pfcands_particleId() {
  if (not pfcands_particleId_isLoaded) {
    if (pfcands_particleId_branch != 0) {
      pfcands_particleId_branch->GetEntry(index);
    } else {
      printf("branch pfcands_particleId_branch does not exist!\n");
      exit(1);
    }
    pfcands_particleId_isLoaded = true;
  }
  return pfcands_particleId_;
}

const vector<int> &CMS3::pfcands_pixelLayersWithMeasurement() {
  if (not pfcands_pixelLayersWithMeasurement_isLoaded) {
    if (pfcands_pixelLayersWithMeasurement_branch != 0) {
      pfcands_pixelLayersWithMeasurement_branch->GetEntry(index);
    } else {
      printf("branch pfcands_pixelLayersWithMeasurement_branch does not exist!\n");
      exit(1);
    }
    pfcands_pixelLayersWithMeasurement_isLoaded = true;
  }
  return pfcands_pixelLayersWithMeasurement_;
}

const vector<int> &CMS3::pfcands_stripLayersWithMeasurement() {
  if (not pfcands_stripLayersWithMeasurement_isLoaded) {
    if (pfcands_stripLayersWithMeasurement_branch != 0) {
      pfcands_stripLayersWithMeasurement_branch->GetEntry(index);
    } else {
      printf("branch pfcands_stripLayersWithMeasurement_branch does not exist!\n");
      exit(1);
    }
    pfcands_stripLayersWithMeasurement_isLoaded = true;
  }
  return pfcands_stripLayersWithMeasurement_;
}

const vector<int> &CMS3::pfjets_chargedHadronMultiplicity() {
  if (not pfjets_chargedHadronMultiplicity_isLoaded) {
    if (pfjets_chargedHadronMultiplicity_branch != 0) {
      pfjets_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_chargedHadronMultiplicity_isLoaded = true;
  }
  return pfjets_chargedHadronMultiplicity_;
}

const vector<int> &CMS3::pfjets_chargedMultiplicity() {
  if (not pfjets_chargedMultiplicity_isLoaded) {
    if (pfjets_chargedMultiplicity_branch != 0) {
      pfjets_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_chargedMultiplicity_isLoaded = true;
  }
  return pfjets_chargedMultiplicity_;
}

const vector<int> &CMS3::pfjets_electronMultiplicity() {
  if (not pfjets_electronMultiplicity_isLoaded) {
    if (pfjets_electronMultiplicity_branch != 0) {
      pfjets_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_electronMultiplicity_isLoaded = true;
  }
  return pfjets_electronMultiplicity_;
}

const vector<int> &CMS3::pfjets_hadronFlavour() {
  if (not pfjets_hadronFlavour_isLoaded) {
    if (pfjets_hadronFlavour_branch != 0) {
      pfjets_hadronFlavour_branch->GetEntry(index);
    } else {
      printf("branch pfjets_hadronFlavour_branch does not exist!\n");
      exit(1);
    }
    pfjets_hadronFlavour_isLoaded = true;
  }
  return pfjets_hadronFlavour_;
}

const vector<int> &CMS3::pfjets_muonMultiplicity() {
  if (not pfjets_muonMultiplicity_isLoaded) {
    if (pfjets_muonMultiplicity_branch != 0) {
      pfjets_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_muonMultiplicity_isLoaded = true;
  }
  return pfjets_muonMultiplicity_;
}

const vector<int> &CMS3::pfjets_neutralHadronMultiplicity() {
  if (not pfjets_neutralHadronMultiplicity_isLoaded) {
    if (pfjets_neutralHadronMultiplicity_branch != 0) {
      pfjets_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_neutralHadronMultiplicity_isLoaded = true;
  }
  return pfjets_neutralHadronMultiplicity_;
}

const vector<int> &CMS3::pfjets_neutralMultiplicity() {
  if (not pfjets_neutralMultiplicity_isLoaded) {
    if (pfjets_neutralMultiplicity_branch != 0) {
      pfjets_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_neutralMultiplicity_isLoaded = true;
  }
  return pfjets_neutralMultiplicity_;
}

const vector<int> &CMS3::pfjets_npfcands() {
  if (not pfjets_npfcands_isLoaded) {
    if (pfjets_npfcands_branch != 0) {
      pfjets_npfcands_branch->GetEntry(index);
    } else {
      printf("branch pfjets_npfcands_branch does not exist!\n");
      exit(1);
    }
    pfjets_npfcands_isLoaded = true;
  }
  return pfjets_npfcands_;
}

const vector<int> &CMS3::pfjets_partonFlavour() {
  if (not pfjets_partonFlavour_isLoaded) {
    if (pfjets_partonFlavour_branch != 0) {
      pfjets_partonFlavour_branch->GetEntry(index);
    } else {
      printf("branch pfjets_partonFlavour_branch does not exist!\n");
      exit(1);
    }
    pfjets_partonFlavour_isLoaded = true;
  }
  return pfjets_partonFlavour_;
}

const vector<int> &CMS3::pfjets_photonMultiplicity() {
  if (not pfjets_photonMultiplicity_isLoaded) {
    if (pfjets_photonMultiplicity_branch != 0) {
      pfjets_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_photonMultiplicity_isLoaded = true;
  }
  return pfjets_photonMultiplicity_;
}

const vector<int> &CMS3::pfjets_totalMultiplicity() {
  if (not pfjets_totalMultiplicity_isLoaded) {
    if (pfjets_totalMultiplicity_branch != 0) {
      pfjets_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_totalMultiplicity_isLoaded = true;
  }
  return pfjets_totalMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_chargedHadronMultiplicity() {
  if (not pfjets_puppi_chargedHadronMultiplicity_isLoaded) {
    if (pfjets_puppi_chargedHadronMultiplicity_branch != 0) {
      pfjets_puppi_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_chargedHadronMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_chargedHadronMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_chargedMultiplicity() {
  if (not pfjets_puppi_chargedMultiplicity_isLoaded) {
    if (pfjets_puppi_chargedMultiplicity_branch != 0) {
      pfjets_puppi_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_chargedMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_chargedMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_electronMultiplicity() {
  if (not pfjets_puppi_electronMultiplicity_isLoaded) {
    if (pfjets_puppi_electronMultiplicity_branch != 0) {
      pfjets_puppi_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_electronMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_electronMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_hadronFlavour() {
  if (not pfjets_puppi_hadronFlavour_isLoaded) {
    if (pfjets_puppi_hadronFlavour_branch != 0) {
      pfjets_puppi_hadronFlavour_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_hadronFlavour_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_hadronFlavour_isLoaded = true;
  }
  return pfjets_puppi_hadronFlavour_;
}

const vector<int> &CMS3::pfjets_puppi_muonMultiplicity() {
  if (not pfjets_puppi_muonMultiplicity_isLoaded) {
    if (pfjets_puppi_muonMultiplicity_branch != 0) {
      pfjets_puppi_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_muonMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_muonMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_neutralHadronMultiplicity() {
  if (not pfjets_puppi_neutralHadronMultiplicity_isLoaded) {
    if (pfjets_puppi_neutralHadronMultiplicity_branch != 0) {
      pfjets_puppi_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_neutralHadronMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_neutralHadronMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_neutralMultiplicity() {
  if (not pfjets_puppi_neutralMultiplicity_isLoaded) {
    if (pfjets_puppi_neutralMultiplicity_branch != 0) {
      pfjets_puppi_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_neutralMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_neutralMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_npfcands() {
  if (not pfjets_puppi_npfcands_isLoaded) {
    if (pfjets_puppi_npfcands_branch != 0) {
      pfjets_puppi_npfcands_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_npfcands_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_npfcands_isLoaded = true;
  }
  return pfjets_puppi_npfcands_;
}

const vector<int> &CMS3::pfjets_puppi_partonFlavour() {
  if (not pfjets_puppi_partonFlavour_isLoaded) {
    if (pfjets_puppi_partonFlavour_branch != 0) {
      pfjets_puppi_partonFlavour_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_partonFlavour_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_partonFlavour_isLoaded = true;
  }
  return pfjets_puppi_partonFlavour_;
}

const vector<int> &CMS3::pfjets_puppi_photonMultiplicity() {
  if (not pfjets_puppi_photonMultiplicity_isLoaded) {
    if (pfjets_puppi_photonMultiplicity_branch != 0) {
      pfjets_puppi_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_photonMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_photonMultiplicity_;
}

const vector<int> &CMS3::pfjets_puppi_totalMultiplicity() {
  if (not pfjets_puppi_totalMultiplicity_isLoaded) {
    if (pfjets_puppi_totalMultiplicity_branch != 0) {
      pfjets_puppi_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch pfjets_puppi_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    pfjets_puppi_totalMultiplicity_isLoaded = true;
  }
  return pfjets_puppi_totalMultiplicity_;
}

const vector<int> &CMS3::taus_pf_charge() {
  if (not taus_pf_charge_isLoaded) {
    if (taus_pf_charge_branch != 0) {
      taus_pf_charge_branch->GetEntry(index);
    } else {
      printf("branch taus_pf_charge_branch does not exist!\n");
      exit(1);
    }
    taus_pf_charge_isLoaded = true;
  }
  return taus_pf_charge_;
}

const vector<int> &CMS3::photons_photonID_loose() {
  if (not photons_photonID_loose_isLoaded) {
    if (photons_photonID_loose_branch != 0) {
      photons_photonID_loose_branch->GetEntry(index);
    } else {
      printf("branch photons_photonID_loose_branch does not exist!\n");
      exit(1);
    }
    photons_photonID_loose_isLoaded = true;
  }
  return photons_photonID_loose_;
}

const vector<int> &CMS3::photons_photonID_tight() {
  if (not photons_photonID_tight_isLoaded) {
    if (photons_photonID_tight_branch != 0) {
      photons_photonID_tight_branch->GetEntry(index);
    } else {
      printf("branch photons_photonID_tight_branch does not exist!\n");
      exit(1);
    }
    photons_photonID_tight_isLoaded = true;
  }
  return photons_photonID_tight_;
}

const vector<int> &CMS3::puInfo_bunchCrossing() {
  if (not puInfo_bunchCrossing_isLoaded) {
    if (puInfo_bunchCrossing_branch != 0) {
      puInfo_bunchCrossing_branch->GetEntry(index);
    } else {
      printf("branch puInfo_bunchCrossing_branch does not exist!\n");
      exit(1);
    }
    puInfo_bunchCrossing_isLoaded = true;
  }
  return puInfo_bunchCrossing_;
}

const vector<int> &CMS3::puInfo_nPUvertices() {
  if (not puInfo_nPUvertices_isLoaded) {
    if (puInfo_nPUvertices_branch != 0) {
      puInfo_nPUvertices_branch->GetEntry(index);
    } else {
      printf("branch puInfo_nPUvertices_branch does not exist!\n");
      exit(1);
    }
    puInfo_nPUvertices_isLoaded = true;
  }
  return puInfo_nPUvertices_;
}

const vector<int> &CMS3::svs_nTrks() {
  if (not svs_nTrks_isLoaded) {
    if (svs_nTrks_branch != 0) {
      svs_nTrks_branch->GetEntry(index);
    } else {
      printf("branch svs_nTrks_branch does not exist!\n");
      exit(1);
    }
    svs_nTrks_isLoaded = true;
  }
  return svs_nTrks_;
}

const vector<int> &CMS3::_npfcands() {
  if (not _npfcands_isLoaded) {
    if (_npfcands_branch != 0) {
      _npfcands_branch->GetEntry(index);
    } else {
      printf("branch _npfcands_branch does not exist!\n");
      exit(1);
    }
    _npfcands_isLoaded = true;
  }
  return _npfcands_;
}

const vector<int> &CMS3::ak8jets_partonFlavour() {
  if (not ak8jets_partonFlavour_isLoaded) {
    if (ak8jets_partonFlavour_branch != 0) {
      ak8jets_partonFlavour_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_partonFlavour_branch does not exist!\n");
      exit(1);
    }
    ak8jets_partonFlavour_isLoaded = true;
  }
  return ak8jets_partonFlavour_;
}

const vector<int> &CMS3::vtxs_isFake() {
  if (not vtxs_isFake_isLoaded) {
    if (vtxs_isFake_branch != 0) {
      vtxs_isFake_branch->GetEntry(index);
    } else {
      printf("branch vtxs_isFake_branch does not exist!\n");
      exit(1);
    }
    vtxs_isFake_isLoaded = true;
  }
  return vtxs_isFake_;
}

const vector<int> &CMS3::vtxs_isValid() {
  if (not vtxs_isValid_isLoaded) {
    if (vtxs_isValid_branch != 0) {
      vtxs_isValid_branch->GetEntry(index);
    } else {
      printf("branch vtxs_isValid_branch does not exist!\n");
      exit(1);
    }
    vtxs_isValid_isLoaded = true;
  }
  return vtxs_isValid_;
}

const vector<vector<int> > &CMS3::genps_lepdaughter_id() {
  if (not genps_lepdaughter_id_isLoaded) {
    if (genps_lepdaughter_id_branch != 0) {
      genps_lepdaughter_id_branch->GetEntry(index);
    } else {
      printf("branch genps_lepdaughter_id_branch does not exist!\n");
      exit(1);
    }
    genps_lepdaughter_id_isLoaded = true;
  }
  return genps_lepdaughter_id_;
}

const vector<vector<int> > &CMS3::genps_lepdaughter_idx() {
  if (not genps_lepdaughter_idx_isLoaded) {
    if (genps_lepdaughter_idx_branch != 0) {
      genps_lepdaughter_idx_branch->GetEntry(index);
    } else {
      printf("branch genps_lepdaughter_idx_branch does not exist!\n");
      exit(1);
    }
    genps_lepdaughter_idx_isLoaded = true;
  }
  return genps_lepdaughter_idx_;
}

const vector<vector<int> > &CMS3::photons_PFCand_idx() {
  if (not photons_PFCand_idx_isLoaded) {
    if (photons_PFCand_idx_branch != 0) {
      photons_PFCand_idx_branch->GetEntry(index);
    } else {
      printf("branch photons_PFCand_idx_branch does not exist!\n");
      exit(1);
    }
    photons_PFCand_idx_isLoaded = true;
  }
  return photons_PFCand_idx_;
}

const vector<unsigned char> &CMS3::pfcands_fromPV() {
  if (not pfcands_fromPV_isLoaded) {
    if (pfcands_fromPV_branch != 0) {
      pfcands_fromPV_branch->GetEntry(index);
    } else {
      printf("branch pfcands_fromPV_branch does not exist!\n");
      exit(1);
    }
    pfcands_fromPV_isLoaded = true;
  }
  return pfcands_fromPV_;
}

const vector<unsigned char> &CMS3::pfcands_normalizedChi2() {
  if (not pfcands_normalizedChi2_isLoaded) {
    if (pfcands_normalizedChi2_branch != 0) {
      pfcands_normalizedChi2_branch->GetEntry(index);
    } else {
      printf("branch pfcands_normalizedChi2_branch does not exist!\n");
      exit(1);
    }
    pfcands_normalizedChi2_isLoaded = true;
  }
  return pfcands_normalizedChi2_;
}

const vector<unsigned char> &CMS3::pfcands_packedHits() {
  if (not pfcands_packedHits_isLoaded) {
    if (pfcands_packedHits_branch != 0) {
      pfcands_packedHits_branch->GetEntry(index);
    } else {
      printf("branch pfcands_packedHits_branch does not exist!\n");
      exit(1);
    }
    pfcands_packedHits_isLoaded = true;
  }
  return pfcands_packedHits_;
}

const vector<unsigned char> &CMS3::pfcands_packedLayers() {
  if (not pfcands_packedLayers_isLoaded) {
    if (pfcands_packedLayers_branch != 0) {
      pfcands_packedLayers_branch->GetEntry(index);
    } else {
      printf("branch pfcands_packedLayers_branch does not exist!\n");
      exit(1);
    }
    pfcands_packedLayers_isLoaded = true;
  }
  return pfcands_packedLayers_;
}

const vector<unsigned char> &CMS3::pfcands_pvAssociationQuality() {
  if (not pfcands_pvAssociationQuality_isLoaded) {
    if (pfcands_pvAssociationQuality_branch != 0) {
      pfcands_pvAssociationQuality_branch->GetEntry(index);
    } else {
      printf("branch pfcands_pvAssociationQuality_branch does not exist!\n");
      exit(1);
    }
    pfcands_pvAssociationQuality_isLoaded = true;
  }
  return pfcands_pvAssociationQuality_;
}

const unsigned int &CMS3::evt_nels() {
  if (not evt_nels_isLoaded) {
    if (evt_nels_branch != 0) {
      evt_nels_branch->GetEntry(index);
    } else {
      printf("branch evt_nels_branch does not exist!\n");
      exit(1);
    }
    evt_nels_isLoaded = true;
  }
  return evt_nels_;
}

const unsigned int &CMS3::evt_detectorStatus() {
  if (not evt_detectorStatus_isLoaded) {
    if (evt_detectorStatus_branch != 0) {
      evt_detectorStatus_branch->GetEntry(index);
    } else {
      printf("branch evt_detectorStatus_branch does not exist!\n");
      exit(1);
    }
    evt_detectorStatus_isLoaded = true;
  }
  return evt_detectorStatus_;
}

const unsigned int &CMS3::evt_lumiBlock() {
  if (not evt_lumiBlock_isLoaded) {
    if (evt_lumiBlock_branch != 0) {
      evt_lumiBlock_branch->GetEntry(index);
    } else {
      printf("branch evt_lumiBlock_branch does not exist!\n");
      exit(1);
    }
    evt_lumiBlock_isLoaded = true;
  }
  return evt_lumiBlock_;
}

const unsigned int &CMS3::evt_run() {
  if (not evt_run_isLoaded) {
    if (evt_run_branch != 0) {
      evt_run_branch->GetEntry(index);
    } else {
      printf("branch evt_run_branch does not exist!\n");
      exit(1);
    }
    evt_run_isLoaded = true;
  }
  return evt_run_;
}

const unsigned int &CMS3::evt_ngenjetsNoMuNoNu() {
  if (not evt_ngenjetsNoMuNoNu_isLoaded) {
    if (evt_ngenjetsNoMuNoNu_branch != 0) {
      evt_ngenjetsNoMuNoNu_branch->GetEntry(index);
    } else {
      printf("branch evt_ngenjetsNoMuNoNu_branch does not exist!\n");
      exit(1);
    }
    evt_ngenjetsNoMuNoNu_isLoaded = true;
  }
  return evt_ngenjetsNoMuNoNu_;
}

const unsigned int &CMS3::genps_signalProcessID() {
  if (not genps_signalProcessID_isLoaded) {
    if (genps_signalProcessID_branch != 0) {
      genps_signalProcessID_branch->GetEntry(index);
    } else {
      printf("branch genps_signalProcessID_branch does not exist!\n");
      exit(1);
    }
    genps_signalProcessID_isLoaded = true;
  }
  return genps_signalProcessID_;
}

const unsigned int &CMS3::evt_nphotons() {
  if (not evt_nphotons_isLoaded) {
    if (evt_nphotons_branch != 0) {
      evt_nphotons_branch->GetEntry(index);
    } else {
      printf("branch evt_nphotons_branch does not exist!\n");
      exit(1);
    }
    evt_nphotons_isLoaded = true;
  }
  return evt_nphotons_;
}

const unsigned int &CMS3::evt_nvtxs() {
  if (not evt_nvtxs_isLoaded) {
    if (evt_nvtxs_branch != 0) {
      evt_nvtxs_branch->GetEntry(index);
    } else {
      printf("branch evt_nvtxs_branch does not exist!\n");
      exit(1);
    }
    evt_nvtxs_isLoaded = true;
  }
  return evt_nvtxs_;
}

const vector<unsigned int> &CMS3::hlt_l1prescales() {
  if (not hlt_l1prescales_isLoaded) {
    if (hlt_l1prescales_branch != 0) {
      hlt_l1prescales_branch->GetEntry(index);
    } else {
      printf("branch hlt_l1prescales_branch does not exist!\n");
      exit(1);
    }
    hlt_l1prescales_isLoaded = true;
  }
  return hlt_l1prescales_;
}

const vector<unsigned int> &CMS3::hlt_prescales() {
  if (not hlt_prescales_isLoaded) {
    if (hlt_prescales_branch != 0) {
      hlt_prescales_branch->GetEntry(index);
    } else {
      printf("branch hlt_prescales_branch does not exist!\n");
      exit(1);
    }
    hlt_prescales_isLoaded = true;
  }
  return hlt_prescales_;
}

const vector<vector<unsigned int> > &CMS3::isotracks_crossedHcalStatus() {
  if (not isotracks_crossedHcalStatus_isLoaded) {
    if (isotracks_crossedHcalStatus_branch != 0) {
      isotracks_crossedHcalStatus_branch->GetEntry(index);
    } else {
      printf("branch isotracks_crossedHcalStatus_branch does not exist!\n");
      exit(1);
    }
    isotracks_crossedHcalStatus_isLoaded = true;
  }
  return isotracks_crossedHcalStatus_;
}

const ULong64_t &CMS3::evt_event() {
  if (not evt_event_isLoaded) {
    if (evt_event_branch != 0) {
      evt_event_branch->GetEntry(index);
    } else {
      printf("branch evt_event_branch does not exist!\n");
      exit(1);
    }
    evt_event_isLoaded = true;
  }
  return evt_event_;
}

const vector<ULong64_t> &CMS3::evt_timestamp() {
  if (not evt_timestamp_isLoaded) {
    if (evt_timestamp_branch != 0) {
      evt_timestamp_branch->GetEntry(index);
    } else {
      printf("branch evt_timestamp_branch does not exist!\n");
      exit(1);
    }
    evt_timestamp_isLoaded = true;
  }
  return evt_timestamp_;
}

  bool CMS3::passHLTTrigger(TString trigName) {
    int trigIndx;
    vector<TString>::const_iterator begin_it = hlt_trigNames().begin();
    vector<TString>::const_iterator end_it = hlt_trigNames().end();
    vector<TString>::const_iterator found_it = find(begin_it, end_it, trigName);
    if (found_it != end_it)
      trigIndx = found_it - begin_it;
    else {
      cout << "Cannot find Trigger " << trigName << endl; 
      return 0;
    }

  return hlt_bits().TestBitNumber(trigIndx);
  }
  float CMS3::passTauID(TString idName, unsigned int tauIndx) {
    int idIndx;
    vector<TString>::const_iterator begin_it = taus_pf_IDnames().begin();
    vector<TString>::const_iterator end_it = taus_pf_IDnames().end();
    vector<TString>::const_iterator found_it = find(begin_it, end_it, idName);
    if (found_it != end_it)
      idIndx = found_it - begin_it;
    else {
      cout << "Cannot find Tau ID " << idName << endl; 
      return 0;
    }

    if (tauIndx < taus_pf_IDs().size()) 
      return taus_pf_IDs().at(tauIndx).at(idIndx);
    else {
      cout << "Cannot find tau # "<< tauIndx << endl;
      return 0;
    }
  }
  float CMS3::getbtagvalue(TString bDiscriminatorName, unsigned int jetIndx) {
    size_t bDiscriminatorIndx;
    vector<TString>::const_iterator begin_it = pfjets_bDiscriminatorNames().begin();
    vector<TString>::const_iterator end_it = pfjets_bDiscriminatorNames().end();
    vector<TString>::const_iterator found_it = find(begin_it, end_it, bDiscriminatorName);
    if (found_it != end_it)
      bDiscriminatorIndx = found_it - begin_it;
    else {
      cout << "Cannot find b discriminator " << bDiscriminatorName << endl; 
      return 0;
    }

    if (jetIndx < pfjets_bDiscriminators().size()) 
      return pfjets_bDiscriminators().at(jetIndx).at(bDiscriminatorIndx);
    else {
      cout << "Cannot find jet # "<< jetIndx << endl;
      return 0;
    }
  }

void CMS3::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

const vector<string> &genweightsID() { return cms3.genweightsID(); }
const TBits &hlt_bits() { return cms3.hlt_bits(); }
const vector<TString> &evt_CMS3tag() { return cms3.evt_CMS3tag(); }
const vector<TString> &evt_dataset() { return cms3.evt_dataset(); }
const vector<TString> &hlt_trigNames() { return cms3.hlt_trigNames(); }
const vector<TString> &pfjets_bDiscriminatorNames() { return cms3.pfjets_bDiscriminatorNames(); }
const vector<TString> &pfjets_puppi_bDiscriminatorNames() { return cms3.pfjets_puppi_bDiscriminatorNames(); }
const vector<TString> &taus_pf_IDnames() { return cms3.taus_pf_IDnames(); }
const bool &evt_cscTightHaloId() { return cms3.evt_cscTightHaloId(); }
const bool &evt_hbheFilter() { return cms3.evt_hbheFilter(); }
const bool &filt_chargedHadronTrackResolution() { return cms3.filt_chargedHadronTrackResolution(); }
const bool &filt_cscBeamHalo() { return cms3.filt_cscBeamHalo(); }
const bool &filt_cscBeamHalo2015() { return cms3.filt_cscBeamHalo2015(); }
const bool &filt_cscBeamHaloTrkMuUnveto() { return cms3.filt_cscBeamHaloTrkMuUnveto(); }
const bool &filt_ecalBoundaryEnergy() { return cms3.filt_ecalBoundaryEnergy(); }
const bool &filt_ecalLaser() { return cms3.filt_ecalLaser(); }
const bool &filt_ecalTP() { return cms3.filt_ecalTP(); }
const bool &filt_eeBadSc() { return cms3.filt_eeBadSc(); }
const bool &filt_globalSuperTightHalo2016() { return cms3.filt_globalSuperTightHalo2016(); }
const bool &filt_globalTightHalo2016() { return cms3.filt_globalTightHalo2016(); }
const bool &filt_goodVertices() { return cms3.filt_goodVertices(); }
const bool &filt_hbheNoise() { return cms3.filt_hbheNoise(); }
const bool &filt_hbheNoiseIso() { return cms3.filt_hbheNoiseIso(); }
const bool &filt_hcalLaser() { return cms3.filt_hcalLaser(); }
const bool &filt_hcalStrip() { return cms3.filt_hcalStrip(); }
const bool &filt_metfilter() { return cms3.filt_metfilter(); }
const bool &filt_muonBadTrack() { return cms3.filt_muonBadTrack(); }
const bool &filt_trackingFailure() { return cms3.filt_trackingFailure(); }
const bool &filt_trkPOGFilters() { return cms3.filt_trkPOGFilters(); }
const bool &filt_trkPOG_logErrorTooManyClusters() { return cms3.filt_trkPOG_logErrorTooManyClusters(); }
const bool &filt_trkPOG_manystripclus53X() { return cms3.filt_trkPOG_manystripclus53X(); }
const bool &filt_trkPOG_toomanystripclus53X() { return cms3.filt_trkPOG_toomanystripclus53X(); }
const vector<bool> &els_conv_vtx_flag() { return cms3.els_conv_vtx_flag(); }
const vector<bool> &els_isGsfCtfScPixChargeConsistent() { return cms3.els_isGsfCtfScPixChargeConsistent(); }
const vector<bool> &genps_fromHardProcessBeforeFSR() { return cms3.genps_fromHardProcessBeforeFSR(); }
const vector<bool> &genps_fromHardProcessDecayed() { return cms3.genps_fromHardProcessDecayed(); }
const vector<bool> &genps_fromHardProcessFinalState() { return cms3.genps_fromHardProcessFinalState(); }
const vector<bool> &genps_isDirectHardProcessTauDecayProductFinalState() { return cms3.genps_isDirectHardProcessTauDecayProductFinalState(); }
const vector<bool> &genps_isDirectPromptTauDecayProductFinalState() { return cms3.genps_isDirectPromptTauDecayProductFinalState(); }
const vector<bool> &genps_isHardProcess() { return cms3.genps_isHardProcess(); }
const vector<bool> &genps_isLastCopy() { return cms3.genps_isLastCopy(); }
const vector<bool> &genps_isLastCopyBeforeFSR() { return cms3.genps_isLastCopyBeforeFSR(); }
const vector<bool> &genps_isMostlyLikePythia6Status3() { return cms3.genps_isMostlyLikePythia6Status3(); }
const vector<bool> &genps_isPromptDecayed() { return cms3.genps_isPromptDecayed(); }
const vector<bool> &genps_isPromptFinalState() { return cms3.genps_isPromptFinalState(); }
const vector<bool> &isotracks_isHighPurityTrack() { return cms3.isotracks_isHighPurityTrack(); }
const vector<bool> &isotracks_isPFCand() { return cms3.isotracks_isPFCand(); }
const vector<bool> &isotracks_isTightTrack() { return cms3.isotracks_isTightTrack(); }
const vector<bool> &pfcands_isGlobalMuon() { return cms3.pfcands_isGlobalMuon(); }
const vector<bool> &pfcands_isStandAloneMuon() { return cms3.pfcands_isStandAloneMuon(); }
const vector<bool> &pfcands_trackHighPurity() { return cms3.pfcands_trackHighPurity(); }
const vector<bool> &photons_haspixelSeed() { return cms3.photons_haspixelSeed(); }
const vector<bool> &photons_passElectronVeto() { return cms3.photons_passElectronVeto(); }
const float &evt_bField() { return cms3.evt_bField(); }
const float &evt_instantLumi() { return cms3.evt_instantLumi(); }
const float &evt_instantLumiErr() { return cms3.evt_instantLumiErr(); }
const float &evt_lumiFill() { return cms3.evt_lumiFill(); }
const float &evt_lumiRun() { return cms3.evt_lumiRun(); }
const float &evt_pileup() { return cms3.evt_pileup(); }
const float &evt_pileupRMS() { return cms3.evt_pileupRMS(); }
const float &evt_fixgrid_all_rho() { return cms3.evt_fixgrid_all_rho(); }
const float &evt_fixgridfastjet_allcalo_rho() { return cms3.evt_fixgridfastjet_allcalo_rho(); }
const float &evt_fixgridfastjet_central_rho() { return cms3.evt_fixgridfastjet_central_rho(); }
const float &evt_fixgridfastjet_all_rho() { return cms3.evt_fixgridfastjet_all_rho(); }
const float &evt_fixgridfastjet_centralcalo_rho() { return cms3.evt_fixgridfastjet_centralcalo_rho(); }
const float &evt_fixgridfastjet_centralchargedpileup_rho() { return cms3.evt_fixgridfastjet_centralchargedpileup_rho(); }
const float &evt_fixgridfastjet_centralneutral_rho() { return cms3.evt_fixgridfastjet_centralneutral_rho(); }
const float &evt_kfactor() { return cms3.evt_kfactor(); }
const float &evt_scale1fb() { return cms3.evt_scale1fb(); }
const float &evt_xsec_excl() { return cms3.evt_xsec_excl(); }
const float &evt_xsec_incl() { return cms3.evt_xsec_incl(); }
const float &genps_alphaQCD() { return cms3.genps_alphaQCD(); }
const float &genps_pthat() { return cms3.genps_pthat(); }
const float &genps_qScale() { return cms3.genps_qScale(); }
const float &genps_weight() { return cms3.genps_weight(); }
const float &gen_sumEt() { return cms3.gen_sumEt(); }
const float &pdfinfo_pdf1() { return cms3.pdfinfo_pdf1(); }
const float &pdfinfo_pdf2() { return cms3.pdfinfo_pdf2(); }
const float &pdfinfo_scale() { return cms3.pdfinfo_scale(); }
const float &pdfinfo_x1() { return cms3.pdfinfo_x1(); }
const float &pdfinfo_x2() { return cms3.pdfinfo_x2(); }
const float &evt_calomet() { return cms3.evt_calomet(); }
const float &evt_calometPhi() { return cms3.evt_calometPhi(); }
const float &evt_pfmet() { return cms3.evt_pfmet(); }
const float &evt_pfmet_ElectronEnDown() { return cms3.evt_pfmet_ElectronEnDown(); }
const float &evt_pfmet_ElectronEnUp() { return cms3.evt_pfmet_ElectronEnUp(); }
const float &evt_pfmet_JetEnDown() { return cms3.evt_pfmet_JetEnDown(); }
const float &evt_pfmet_JetEnUp() { return cms3.evt_pfmet_JetEnUp(); }
const float &evt_pfmet_JetResDown() { return cms3.evt_pfmet_JetResDown(); }
const float &evt_pfmet_JetResUp() { return cms3.evt_pfmet_JetResUp(); }
const float &evt_pfmet_MuonEnDown() { return cms3.evt_pfmet_MuonEnDown(); }
const float &evt_pfmet_MuonEnUp() { return cms3.evt_pfmet_MuonEnUp(); }
const float &evt_pfmetPhi() { return cms3.evt_pfmetPhi(); }
const float &evt_pfmetPhi_ElectronEnDown() { return cms3.evt_pfmetPhi_ElectronEnDown(); }
const float &evt_pfmetPhi_ElectronEnUp() { return cms3.evt_pfmetPhi_ElectronEnUp(); }
const float &evt_pfmetPhi_JetEnDown() { return cms3.evt_pfmetPhi_JetEnDown(); }
const float &evt_pfmetPhi_JetEnUp() { return cms3.evt_pfmetPhi_JetEnUp(); }
const float &evt_pfmetPhi_JetResDown() { return cms3.evt_pfmetPhi_JetResDown(); }
const float &evt_pfmetPhi_JetResUp() { return cms3.evt_pfmetPhi_JetResUp(); }
const float &evt_pfmetPhi_MuonEnDown() { return cms3.evt_pfmetPhi_MuonEnDown(); }
const float &evt_pfmetPhi_MuonEnUp() { return cms3.evt_pfmetPhi_MuonEnUp(); }
const float &evt_pfmetPhi_PhotonEnDown() { return cms3.evt_pfmetPhi_PhotonEnDown(); }
const float &evt_pfmetPhi_PhotonEnUp() { return cms3.evt_pfmetPhi_PhotonEnUp(); }
const float &evt_pfmetPhi_TauEnDown() { return cms3.evt_pfmetPhi_TauEnDown(); }
const float &evt_pfmetPhi_TauEnUp() { return cms3.evt_pfmetPhi_TauEnUp(); }
const float &evt_pfmetPhi_UnclusteredEnDown() { return cms3.evt_pfmetPhi_UnclusteredEnDown(); }
const float &evt_pfmetPhi_UnclusteredEnUp() { return cms3.evt_pfmetPhi_UnclusteredEnUp(); }
const float &evt_pfmetPhi_raw() { return cms3.evt_pfmetPhi_raw(); }
const float &evt_pfmet_PhotonEnDown() { return cms3.evt_pfmet_PhotonEnDown(); }
const float &evt_pfmet_PhotonEnUp() { return cms3.evt_pfmet_PhotonEnUp(); }
const float &evt_pfmetSig() { return cms3.evt_pfmetSig(); }
const float &evt_pfmetSignificance() { return cms3.evt_pfmetSignificance(); }
const float &evt_pfmet_TauEnDown() { return cms3.evt_pfmet_TauEnDown(); }
const float &evt_pfmet_TauEnUp() { return cms3.evt_pfmet_TauEnUp(); }
const float &evt_pfmet_UnclusteredEnDown() { return cms3.evt_pfmet_UnclusteredEnDown(); }
const float &evt_pfmet_UnclusteredEnUp() { return cms3.evt_pfmet_UnclusteredEnUp(); }
const float &evt_pfmet_raw() { return cms3.evt_pfmet_raw(); }
const float &evt_pfsumet() { return cms3.evt_pfsumet(); }
const float &evt_pfsumet_raw() { return cms3.evt_pfsumet_raw(); }
const float &gen_met() { return cms3.gen_met(); }
const float &gen_metPhi() { return cms3.gen_metPhi(); }
const float &evt_puppi_calomet() { return cms3.evt_puppi_calomet(); }
const float &evt_puppi_calometPhi() { return cms3.evt_puppi_calometPhi(); }
const float &evt_puppi_pfmet() { return cms3.evt_puppi_pfmet(); }
const float &evt_puppi_pfmet_ElectronEnDown() { return cms3.evt_puppi_pfmet_ElectronEnDown(); }
const float &evt_puppi_pfmet_ElectronEnUp() { return cms3.evt_puppi_pfmet_ElectronEnUp(); }
const float &evt_puppi_pfmet_JetEnDown() { return cms3.evt_puppi_pfmet_JetEnDown(); }
const float &evt_puppi_pfmet_JetEnUp() { return cms3.evt_puppi_pfmet_JetEnUp(); }
const float &evt_puppi_pfmet_JetResDown() { return cms3.evt_puppi_pfmet_JetResDown(); }
const float &evt_puppi_pfmet_JetResUp() { return cms3.evt_puppi_pfmet_JetResUp(); }
const float &evt_puppi_pfmet_MuonEnDown() { return cms3.evt_puppi_pfmet_MuonEnDown(); }
const float &evt_puppi_pfmet_MuonEnUp() { return cms3.evt_puppi_pfmet_MuonEnUp(); }
const float &evt_puppi_pfmetPhi() { return cms3.evt_puppi_pfmetPhi(); }
const float &evt_puppi_pfmetPhi_ElectronEnDown() { return cms3.evt_puppi_pfmetPhi_ElectronEnDown(); }
const float &evt_puppi_pfmetPhi_ElectronEnUp() { return cms3.evt_puppi_pfmetPhi_ElectronEnUp(); }
const float &evt_puppi_pfmetPhi_JetEnDown() { return cms3.evt_puppi_pfmetPhi_JetEnDown(); }
const float &evt_puppi_pfmetPhi_JetEnUp() { return cms3.evt_puppi_pfmetPhi_JetEnUp(); }
const float &evt_puppi_pfmetPhi_JetResDown() { return cms3.evt_puppi_pfmetPhi_JetResDown(); }
const float &evt_puppi_pfmetPhi_JetResUp() { return cms3.evt_puppi_pfmetPhi_JetResUp(); }
const float &evt_puppi_pfmetPhi_MuonEnDown() { return cms3.evt_puppi_pfmetPhi_MuonEnDown(); }
const float &evt_puppi_pfmetPhi_MuonEnUp() { return cms3.evt_puppi_pfmetPhi_MuonEnUp(); }
const float &evt_puppi_pfmetPhi_PhotonEnDown() { return cms3.evt_puppi_pfmetPhi_PhotonEnDown(); }
const float &evt_puppi_pfmetPhi_PhotonEnUp() { return cms3.evt_puppi_pfmetPhi_PhotonEnUp(); }
const float &evt_puppi_pfmetPhi_TauEnDown() { return cms3.evt_puppi_pfmetPhi_TauEnDown(); }
const float &evt_puppi_pfmetPhi_TauEnUp() { return cms3.evt_puppi_pfmetPhi_TauEnUp(); }
const float &evt_puppi_pfmetPhi_UnclusteredEnDown() { return cms3.evt_puppi_pfmetPhi_UnclusteredEnDown(); }
const float &evt_puppi_pfmetPhi_UnclusteredEnUp() { return cms3.evt_puppi_pfmetPhi_UnclusteredEnUp(); }
const float &evt_puppi_pfmetPhi_raw() { return cms3.evt_puppi_pfmetPhi_raw(); }
const float &evt_puppi_pfmet_PhotonEnDown() { return cms3.evt_puppi_pfmet_PhotonEnDown(); }
const float &evt_puppi_pfmet_PhotonEnUp() { return cms3.evt_puppi_pfmet_PhotonEnUp(); }
const float &evt_puppi_pfmetSig() { return cms3.evt_puppi_pfmetSig(); }
const float &evt_puppi_pfmetSignificance() { return cms3.evt_puppi_pfmetSignificance(); }
const float &evt_puppi_pfmet_TauEnDown() { return cms3.evt_puppi_pfmet_TauEnDown(); }
const float &evt_puppi_pfmet_TauEnUp() { return cms3.evt_puppi_pfmet_TauEnUp(); }
const float &evt_puppi_pfmet_UnclusteredEnDown() { return cms3.evt_puppi_pfmet_UnclusteredEnDown(); }
const float &evt_puppi_pfmet_UnclusteredEnUp() { return cms3.evt_puppi_pfmet_UnclusteredEnUp(); }
const float &evt_puppi_pfmet_raw() { return cms3.evt_puppi_pfmet_raw(); }
const float &evt_puppi_pfsumet() { return cms3.evt_puppi_pfsumet(); }
const float &evt_puppi_pfsumet_raw() { return cms3.evt_puppi_pfsumet_raw(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_motherp4() { return cms3.els_mc_motherp4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_p4() { return cms3.els_mc_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_motherp4() { return cms3.mus_mc_motherp4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_p4() { return cms3.mus_mc_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_p4() { return cms3.pfjets_mc_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_motherp4() { return cms3.photons_mc_motherp4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_p4() { return cms3.photons_mc_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_patMatch_p4() { return cms3.els_mc_patMatch_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4() { return cms3.els_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4In() { return cms3.els_p4In(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4Out() { return cms3.els_p4Out(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_p4() { return cms3.els_trk_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_vertex_p4() { return cms3.els_trk_vertex_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_vertex_p4() { return cms3.els_vertex_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4NoMuNoNu() { return cms3.genjets_p4NoMuNoNu(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return cms3.genps_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_p4() { return cms3.hyp_ll_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_p4() { return cms3.hyp_lt_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_p4() { return cms3.hyp_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isotracks_p4() { return cms3.isotracks_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_bfit_p4() { return cms3.mus_bfit_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_p4() { return cms3.mus_gfit_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_patMatch_p4() { return cms3.mus_mc_patMatch_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_p4() { return cms3.mus_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfp4() { return cms3.mus_pfp4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_trk_p4() { return cms3.mus_trk_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfcands_p4() { return cms3.pfcands_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_p4() { return cms3.pfjets_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_puppi_p4() { return cms3.pfjets_puppi_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_p4() { return cms3.taus_pf_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_p4() { return cms3.photons_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_p4() { return cms3.svs_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_position() { return cms3.svs_position(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8jets_p4() { return cms3.ak8jets_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8jets_softdropPuppiSubjet1() { return cms3.ak8jets_softdropPuppiSubjet1(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8jets_softdropPuppiSubjet2() { return cms3.ak8jets_softdropPuppiSubjet2(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &vtxs_position() { return cms3.vtxs_position(); }
const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &genps_lepdaughter_p4() { return cms3.genps_lepdaughter_p4(); }
const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &pfjets_pfcandmup4() { return cms3.pfjets_pfcandmup4(); }
const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &pfjets_puppi_pfcandmup4() { return cms3.pfjets_puppi_pfcandmup4(); }
const vector<float> &els_mc3dr() { return cms3.els_mc3dr(); }
const vector<float> &els_mcdr() { return cms3.els_mcdr(); }
const vector<float> &mus_mc3dr() { return cms3.mus_mc3dr(); }
const vector<float> &mus_mcdr() { return cms3.mus_mcdr(); }
const vector<float> &pfjets_mc3dr() { return cms3.pfjets_mc3dr(); }
const vector<float> &pfjets_mcdr() { return cms3.pfjets_mcdr(); }
const vector<float> &photons_mc3dr() { return cms3.photons_mc3dr(); }
const vector<float> &photons_mcdr() { return cms3.photons_mcdr(); }
const vector<float> &els_VIDNonTrigMvaValue() { return cms3.els_VIDNonTrigMvaValue(); }
const vector<float> &els_VIDSpring16GPMvaValue() { return cms3.els_VIDSpring16GPMvaValue(); }
const vector<float> &els_VIDSpring16HZZMvaValue() { return cms3.els_VIDSpring16HZZMvaValue(); }
const vector<float> &els_VIDTrigMvaValue() { return cms3.els_VIDTrigMvaValue(); }
const vector<float> &els_chi2() { return cms3.els_chi2(); }
const vector<float> &els_ckf_chi2() { return cms3.els_ckf_chi2(); }
const vector<float> &els_ckf_ndof() { return cms3.els_ckf_ndof(); }
const vector<float> &els_conv_vtx_prob() { return cms3.els_conv_vtx_prob(); }
const vector<float> &els_d0Err() { return cms3.els_d0Err(); }
const vector<float> &els_dEtaIn() { return cms3.els_dEtaIn(); }
const vector<float> &els_dEtaOut() { return cms3.els_dEtaOut(); }
const vector<float> &els_dPhiIn() { return cms3.els_dPhiIn(); }
const vector<float> &els_dPhiOut() { return cms3.els_dPhiOut(); }
const vector<float> &els_dxyPV() { return cms3.els_dxyPV(); }
const vector<float> &els_dzPV() { return cms3.els_dzPV(); }
const vector<float> &els_e1x5_full5x5() { return cms3.els_e1x5_full5x5(); }
const vector<float> &els_e2x5Max_full5x5() { return cms3.els_e2x5Max_full5x5(); }
const vector<float> &els_e5x5_full5x5() { return cms3.els_e5x5_full5x5(); }
const vector<float> &els_eOverPIn() { return cms3.els_eOverPIn(); }
const vector<float> &els_eOverPOut() { return cms3.els_eOverPOut(); }
const vector<float> &els_eSC() { return cms3.els_eSC(); }
const vector<float> &els_eSCPresh() { return cms3.els_eSCPresh(); }
const vector<float> &els_eSCRaw() { return cms3.els_eSCRaw(); }
const vector<float> &els_eSeed() { return cms3.els_eSeed(); }
const vector<float> &els_ecalEnergy() { return cms3.els_ecalEnergy(); }
const vector<float> &els_ecalEnergyError() { return cms3.els_ecalEnergyError(); }
const vector<float> &els_ecalIso() { return cms3.els_ecalIso(); }
const vector<float> &els_ecalIso04() { return cms3.els_ecalIso04(); }
const vector<float> &els_ecalPFClusterIso() { return cms3.els_ecalPFClusterIso(); }
const vector<float> &els_etaSC() { return cms3.els_etaSC(); }
const vector<float> &els_etaSCwidth() { return cms3.els_etaSCwidth(); }
const vector<float> &els_fbrem() { return cms3.els_fbrem(); }
const vector<float> &els_full5x5_hOverE() { return cms3.els_full5x5_hOverE(); }
const vector<float> &els_hOverE() { return cms3.els_hOverE(); }
const vector<float> &els_hcalDepth1TowerSumEt() { return cms3.els_hcalDepth1TowerSumEt(); }
const vector<float> &els_hcalIso() { return cms3.els_hcalIso(); }
const vector<float> &els_hcalIso04() { return cms3.els_hcalIso04(); }
const vector<float> &els_hcalPFClusterIso() { return cms3.els_hcalPFClusterIso(); }
const vector<float> &els_ip2d() { return cms3.els_ip2d(); }
const vector<float> &els_ip2derr() { return cms3.els_ip2derr(); }
const vector<float> &els_ip3d() { return cms3.els_ip3d(); }
const vector<float> &els_ip3derr() { return cms3.els_ip3derr(); }
const vector<float> &els_mc_patMatch_dr() { return cms3.els_mc_patMatch_dr(); }
const vector<float> &els_miniIso_ch() { return cms3.els_miniIso_ch(); }
const vector<float> &els_miniIso_db() { return cms3.els_miniIso_db(); }
const vector<float> &els_miniIso_em() { return cms3.els_miniIso_em(); }
const vector<float> &els_miniIso_nh() { return cms3.els_miniIso_nh(); }
const vector<float> &els_miniIso_uncor() { return cms3.els_miniIso_uncor(); }
const vector<float> &els_ndof() { return cms3.els_ndof(); }
const vector<float> &els_pfChargedHadronIso() { return cms3.els_pfChargedHadronIso(); }
const vector<float> &els_pfNeutralHadronIso() { return cms3.els_pfNeutralHadronIso(); }
const vector<float> &els_pfPUIso() { return cms3.els_pfPUIso(); }
const vector<float> &els_pfPhotonIso() { return cms3.els_pfPhotonIso(); }
const vector<float> &els_phiSC() { return cms3.els_phiSC(); }
const vector<float> &els_phiSCwidth() { return cms3.els_phiSCwidth(); }
const vector<float> &els_ptErr() { return cms3.els_ptErr(); }
const vector<float> &els_ptErrGsf() { return cms3.els_ptErrGsf(); }
const vector<float> &els_r9() { return cms3.els_r9(); }
const vector<float> &els_r9_full5x5() { return cms3.els_r9_full5x5(); }
const vector<float> &els_scSeedEta() { return cms3.els_scSeedEta(); }
const vector<float> &els_sigmaEtaEta_full5x5() { return cms3.els_sigmaEtaEta_full5x5(); }
const vector<float> &els_sigmaIEtaIEta() { return cms3.els_sigmaIEtaIEta(); }
const vector<float> &els_sigmaIEtaIEta_full5x5() { return cms3.els_sigmaIEtaIEta_full5x5(); }
const vector<float> &els_sigmaIPhiIPhi() { return cms3.els_sigmaIPhiIPhi(); }
const vector<float> &els_sigmaIPhiIPhi_full5x5() { return cms3.els_sigmaIPhiIPhi_full5x5(); }
const vector<float> &els_tkIso() { return cms3.els_tkIso(); }
const vector<float> &els_tkIso04() { return cms3.els_tkIso04(); }
const vector<float> &els_trackMomentumError() { return cms3.els_trackMomentumError(); }
const vector<float> &els_trkdr() { return cms3.els_trkdr(); }
const vector<float> &els_trkshFrac() { return cms3.els_trkshFrac(); }
const vector<float> &els_z0Err() { return cms3.els_z0Err(); }
const vector<float> &genps_charge() { return cms3.genps_charge(); }
const vector<float> &genps_iso() { return cms3.genps_iso(); }
const vector<float> &genweights() { return cms3.genweights(); }
const vector<float> &isotracks_dEdxPixel() { return cms3.isotracks_dEdxPixel(); }
const vector<float> &isotracks_dEdxStrip() { return cms3.isotracks_dEdxStrip(); }
const vector<float> &isotracks_deltaEta() { return cms3.isotracks_deltaEta(); }
const vector<float> &isotracks_deltaPhi() { return cms3.isotracks_deltaPhi(); }
const vector<float> &isotracks_dxy() { return cms3.isotracks_dxy(); }
const vector<float> &isotracks_dxyError() { return cms3.isotracks_dxyError(); }
const vector<float> &isotracks_dz() { return cms3.isotracks_dz(); }
const vector<float> &isotracks_dzError() { return cms3.isotracks_dzError(); }
const vector<float> &isotracks_matchedCaloJetEmEnergy() { return cms3.isotracks_matchedCaloJetEmEnergy(); }
const vector<float> &isotracks_matchedCaloJetHadEnergy() { return cms3.isotracks_matchedCaloJetHadEnergy(); }
const vector<float> &isotracks_miniIso_ch() { return cms3.isotracks_miniIso_ch(); }
const vector<float> &isotracks_miniIso_db() { return cms3.isotracks_miniIso_db(); }
const vector<float> &isotracks_miniIso_em() { return cms3.isotracks_miniIso_em(); }
const vector<float> &isotracks_miniIso_nh() { return cms3.isotracks_miniIso_nh(); }
const vector<float> &isotracks_pfIso_ch() { return cms3.isotracks_pfIso_ch(); }
const vector<float> &isotracks_pfIso_db() { return cms3.isotracks_pfIso_db(); }
const vector<float> &isotracks_pfIso_em() { return cms3.isotracks_pfIso_em(); }
const vector<float> &isotracks_pfIso_nh() { return cms3.isotracks_pfIso_nh(); }
const vector<float> &mus_bfit_ptErr() { return cms3.mus_bfit_ptErr(); }
const vector<float> &mus_caloCompatibility() { return cms3.mus_caloCompatibility(); }
const vector<float> &mus_chi2LocalMomentum() { return cms3.mus_chi2LocalMomentum(); }
const vector<float> &mus_chi2LocalPosition() { return cms3.mus_chi2LocalPosition(); }
const vector<float> &mus_d0Err() { return cms3.mus_d0Err(); }
const vector<float> &mus_dxyPV() { return cms3.mus_dxyPV(); }
const vector<float> &mus_dzPV() { return cms3.mus_dzPV(); }
const vector<float> &mus_ecal_time() { return cms3.mus_ecal_time(); }
const vector<float> &mus_gfit_chi2() { return cms3.mus_gfit_chi2(); }
const vector<float> &mus_gfit_ptErr() { return cms3.mus_gfit_ptErr(); }
const vector<float> &mus_hcal_time() { return cms3.mus_hcal_time(); }
const vector<float> &mus_ip2d() { return cms3.mus_ip2d(); }
const vector<float> &mus_ip2derr() { return cms3.mus_ip2derr(); }
const vector<float> &mus_ip3d() { return cms3.mus_ip3d(); }
const vector<float> &mus_ip3derr() { return cms3.mus_ip3derr(); }
const vector<float> &mus_iso03_emEt() { return cms3.mus_iso03_emEt(); }
const vector<float> &mus_iso03_hadEt() { return cms3.mus_iso03_hadEt(); }
const vector<float> &mus_iso03_sumPt() { return cms3.mus_iso03_sumPt(); }
const vector<float> &mus_isoR03_pf_ChargedHadronPt() { return cms3.mus_isoR03_pf_ChargedHadronPt(); }
const vector<float> &mus_isoR03_pf_ChargedParticlePt() { return cms3.mus_isoR03_pf_ChargedParticlePt(); }
const vector<float> &mus_isoR03_pf_NeutralHadronEt() { return cms3.mus_isoR03_pf_NeutralHadronEt(); }
const vector<float> &mus_isoR03_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoR03_pf_NeutralHadronEtHighThreshold(); }
const vector<float> &mus_isoR03_pf_PUPt() { return cms3.mus_isoR03_pf_PUPt(); }
const vector<float> &mus_isoR03_pf_PhotonEt() { return cms3.mus_isoR03_pf_PhotonEt(); }
const vector<float> &mus_isoR03_pf_PhotonEtHighThreshold() { return cms3.mus_isoR03_pf_PhotonEtHighThreshold(); }
const vector<float> &mus_isoR04_pf_ChargedHadronPt() { return cms3.mus_isoR04_pf_ChargedHadronPt(); }
const vector<float> &mus_isoR04_pf_ChargedParticlePt() { return cms3.mus_isoR04_pf_ChargedParticlePt(); }
const vector<float> &mus_isoR04_pf_NeutralHadronEt() { return cms3.mus_isoR04_pf_NeutralHadronEt(); }
const vector<float> &mus_isoR04_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoR04_pf_NeutralHadronEtHighThreshold(); }
const vector<float> &mus_isoR04_pf_PUPt() { return cms3.mus_isoR04_pf_PUPt(); }
const vector<float> &mus_isoR04_pf_PhotonEt() { return cms3.mus_isoR04_pf_PhotonEt(); }
const vector<float> &mus_isoR04_pf_PhotonEtHighThreshold() { return cms3.mus_isoR04_pf_PhotonEtHighThreshold(); }
const vector<float> &mus_iso_ecalvetoDep() { return cms3.mus_iso_ecalvetoDep(); }
const vector<float> &mus_iso_hcalvetoDep() { return cms3.mus_iso_hcalvetoDep(); }
const vector<float> &mus_iso_hovetoDep() { return cms3.mus_iso_hovetoDep(); }
const vector<float> &mus_iso_trckvetoDep() { return cms3.mus_iso_trckvetoDep(); }
const vector<float> &mus_mc_patMatch_dr() { return cms3.mus_mc_patMatch_dr(); }
const vector<float> &mus_miniIso_ch() { return cms3.mus_miniIso_ch(); }
const vector<float> &mus_miniIso_db() { return cms3.mus_miniIso_db(); }
const vector<float> &mus_miniIso_em() { return cms3.mus_miniIso_em(); }
const vector<float> &mus_miniIso_nh() { return cms3.mus_miniIso_nh(); }
const vector<float> &mus_miniIso_uncor() { return cms3.mus_miniIso_uncor(); }
const vector<float> &mus_ptErr() { return cms3.mus_ptErr(); }
const vector<float> &mus_segmCompatibility() { return cms3.mus_segmCompatibility(); }
const vector<float> &mus_trkKink() { return cms3.mus_trkKink(); }
const vector<float> &mus_z0Err() { return cms3.mus_z0Err(); }
const vector<float> &pfcands_dxy() { return cms3.pfcands_dxy(); }
const vector<float> &pfcands_dxyError() { return cms3.pfcands_dxyError(); }
const vector<float> &pfcands_dz() { return cms3.pfcands_dz(); }
const vector<float> &pfcands_dzAssociatedPV() { return cms3.pfcands_dzAssociatedPV(); }
const vector<float> &pfcands_dzError() { return cms3.pfcands_dzError(); }
const vector<float> &pfcands_mass() { return cms3.pfcands_mass(); }
const vector<float> &pfcands_miniTrackIso() { return cms3.pfcands_miniTrackIso(); }
const vector<float> &pfcands_puppiWeight() { return cms3.pfcands_puppiWeight(); }
const vector<float> &pfcands_puppiWeightNoLep() { return cms3.pfcands_puppiWeightNoLep(); }
const vector<float> &pfcands_trackIso() { return cms3.pfcands_trackIso(); }
const vector<float> &pfjets_area() { return cms3.pfjets_area(); }
const vector<float> &pfjets_axis1() { return cms3.pfjets_axis1(); }
const vector<float> &pfjets_chargedEmE() { return cms3.pfjets_chargedEmE(); }
const vector<float> &pfjets_chargedHadronE() { return cms3.pfjets_chargedHadronE(); }
const vector<float> &pfjets_electronE() { return cms3.pfjets_electronE(); }
const vector<float> &pfjets_hfEmE() { return cms3.pfjets_hfEmE(); }
const vector<float> &pfjets_hfHadronE() { return cms3.pfjets_hfHadronE(); }
const vector<float> &pfjets_muonE() { return cms3.pfjets_muonE(); }
const vector<float> &pfjets_neutralEmE() { return cms3.pfjets_neutralEmE(); }
const vector<float> &pfjets_neutralHadronE() { return cms3.pfjets_neutralHadronE(); }
const vector<float> &pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag() { return cms3.pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag(); }
const vector<float> &pfjets_pfDeepCSVJetTagsprobbPlusprobbb() { return cms3.pfjets_pfDeepCSVJetTagsprobbPlusprobbb(); }
const vector<float> &pfjets_photonE() { return cms3.pfjets_photonE(); }
const vector<float> &pfjets_pileupJetId() { return cms3.pfjets_pileupJetId(); }
const vector<float> &pfjets_ptDistribution() { return cms3.pfjets_ptDistribution(); }
const vector<float> &pfjets_undoJEC() { return cms3.pfjets_undoJEC(); }
const vector<float> &pfjets_puppi_area() { return cms3.pfjets_puppi_area(); }
const vector<float> &pfjets_puppi_axis1() { return cms3.pfjets_puppi_axis1(); }
const vector<float> &pfjets_puppi_chargedEmE() { return cms3.pfjets_puppi_chargedEmE(); }
const vector<float> &pfjets_puppi_chargedHadronE() { return cms3.pfjets_puppi_chargedHadronE(); }
const vector<float> &pfjets_puppi_electronE() { return cms3.pfjets_puppi_electronE(); }
const vector<float> &pfjets_puppi_hfEmE() { return cms3.pfjets_puppi_hfEmE(); }
const vector<float> &pfjets_puppi_hfHadronE() { return cms3.pfjets_puppi_hfHadronE(); }
const vector<float> &pfjets_puppi_muonE() { return cms3.pfjets_puppi_muonE(); }
const vector<float> &pfjets_puppi_neutralEmE() { return cms3.pfjets_puppi_neutralEmE(); }
const vector<float> &pfjets_puppi_neutralHadronE() { return cms3.pfjets_puppi_neutralHadronE(); }
const vector<float> &pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag() { return cms3.pfjets_puppi_pfCombinedInclusiveSecondaryVertexV2BJetTag(); }
const vector<float> &pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb() { return cms3.pfjets_puppi_pfDeepCSVJetTagsprobbPlusprobbb(); }
const vector<float> &pfjets_puppi_photonE() { return cms3.pfjets_puppi_photonE(); }
const vector<float> &pfjets_puppi_pileupJetId() { return cms3.pfjets_puppi_pileupJetId(); }
const vector<float> &pfjets_puppi_ptDistribution() { return cms3.pfjets_puppi_ptDistribution(); }
const vector<float> &pfjets_puppi_undoJEC() { return cms3.pfjets_puppi_undoJEC(); }
const vector<float> &photons_ecalPFClusterIso() { return cms3.photons_ecalPFClusterIso(); }
const vector<float> &photons_full5x5_hOverE() { return cms3.photons_full5x5_hOverE(); }
const vector<float> &photons_full5x5_hOverEtowBC() { return cms3.photons_full5x5_hOverEtowBC(); }
const vector<float> &photons_full5x5_r9() { return cms3.photons_full5x5_r9(); }
const vector<float> &photons_full5x5_sigmaIEtaIEta() { return cms3.photons_full5x5_sigmaIEtaIEta(); }
const vector<float> &photons_hOverE() { return cms3.photons_hOverE(); }
const vector<float> &photons_hOverEtowBC() { return cms3.photons_hOverEtowBC(); }
const vector<float> &photons_hcalPFClusterIso() { return cms3.photons_hcalPFClusterIso(); }
const vector<float> &photons_ntkIsoHollow03() { return cms3.photons_ntkIsoHollow03(); }
const vector<float> &photons_recoChargedHadronIso() { return cms3.photons_recoChargedHadronIso(); }
const vector<float> &photons_recoNeutralHadronIso() { return cms3.photons_recoNeutralHadronIso(); }
const vector<float> &photons_recoPhotonIso() { return cms3.photons_recoPhotonIso(); }
const vector<float> &photons_sigmaIEtaIEta() { return cms3.photons_sigmaIEtaIEta(); }
const vector<float> &photons_tkIsoHollow03() { return cms3.photons_tkIsoHollow03(); }
const vector<float> &puInfo_trueNumInteractions() { return cms3.puInfo_trueNumInteractions(); }
const vector<float> &svs_anglePV() { return cms3.svs_anglePV(); }
const vector<float> &svs_chi2() { return cms3.svs_chi2(); }
const vector<float> &svs_dist3Dsig() { return cms3.svs_dist3Dsig(); }
const vector<float> &svs_dist3Dval() { return cms3.svs_dist3Dval(); }
const vector<float> &svs_distXYsig() { return cms3.svs_distXYsig(); }
const vector<float> &svs_distXYval() { return cms3.svs_distXYval(); }
const vector<float> &svs_ndof() { return cms3.svs_ndof(); }
const vector<float> &svs_prob() { return cms3.svs_prob(); }
const vector<float> &svs_xError() { return cms3.svs_xError(); }
const vector<float> &svs_yError() { return cms3.svs_yError(); }
const vector<float> &svs_zError() { return cms3.svs_zError(); }
const vector<float> &ak8jets_area() { return cms3.ak8jets_area(); }
const vector<float> &ak8jets_mass() { return cms3.ak8jets_mass(); }
const vector<float> &ak8jets_nJettinessTau1() { return cms3.ak8jets_nJettinessTau1(); }
const vector<float> &ak8jets_nJettinessTau2() { return cms3.ak8jets_nJettinessTau2(); }
const vector<float> &ak8jets_nJettinessTau3() { return cms3.ak8jets_nJettinessTau3(); }
const vector<float> &ak8jets_prunedMass() { return cms3.ak8jets_prunedMass(); }
const vector<float> &ak8jets_puppi_eta() { return cms3.ak8jets_puppi_eta(); }
const vector<float> &ak8jets_puppi_mass() { return cms3.ak8jets_puppi_mass(); }
const vector<float> &ak8jets_puppi_nJettinessTau1() { return cms3.ak8jets_puppi_nJettinessTau1(); }
const vector<float> &ak8jets_puppi_nJettinessTau2() { return cms3.ak8jets_puppi_nJettinessTau2(); }
const vector<float> &ak8jets_puppi_nJettinessTau3() { return cms3.ak8jets_puppi_nJettinessTau3(); }
const vector<float> &ak8jets_puppi_phi() { return cms3.ak8jets_puppi_phi(); }
const vector<float> &ak8jets_puppi_pt() { return cms3.ak8jets_puppi_pt(); }
const vector<float> &ak8jets_puppi_softdropMass() { return cms3.ak8jets_puppi_softdropMass(); }
const vector<float> &ak8jets_softdropMass() { return cms3.ak8jets_softdropMass(); }
const vector<float> &ak8jets_undoJEC() { return cms3.ak8jets_undoJEC(); }
const vector<float> &vtxs_ndof() { return cms3.vtxs_ndof(); }
const vector<vector<float> > &pfjets_bDiscriminators() { return cms3.pfjets_bDiscriminators(); }
const vector<vector<float> > &pfjets_puppi_bDiscriminators() { return cms3.pfjets_puppi_bDiscriminators(); }
const vector<vector<float> > &taus_pf_IDs() { return cms3.taus_pf_IDs(); }
const vector<vector<float> > &puInfo_instLumi() { return cms3.puInfo_instLumi(); }
const int &evt_bunchCrossing() { return cms3.evt_bunchCrossing(); }
const int &evt_experimentType() { return cms3.evt_experimentType(); }
const int &evt_isRealData() { return cms3.evt_isRealData(); }
const int &evt_orbitNumber() { return cms3.evt_orbitNumber(); }
const int &evt_storeNumber() { return cms3.evt_storeNumber(); }
const int &pdfinfo_id1() { return cms3.pdfinfo_id1(); }
const int &pdfinfo_id2() { return cms3.pdfinfo_id2(); }
const vector<int> &els_mc3_id() { return cms3.els_mc3_id(); }
const vector<int> &els_mc3idx() { return cms3.els_mc3idx(); }
const vector<int> &els_mc3_motherid() { return cms3.els_mc3_motherid(); }
const vector<int> &els_mc3_motheridx() { return cms3.els_mc3_motheridx(); }
const vector<int> &els_mc_id() { return cms3.els_mc_id(); }
const vector<int> &els_mc_motherid() { return cms3.els_mc_motherid(); }
const vector<int> &mus_mc3_id() { return cms3.mus_mc3_id(); }
const vector<int> &mus_mc3idx() { return cms3.mus_mc3idx(); }
const vector<int> &mus_mc3_motherid() { return cms3.mus_mc3_motherid(); }
const vector<int> &mus_mc3_motheridx() { return cms3.mus_mc3_motheridx(); }
const vector<int> &mus_mc_id() { return cms3.mus_mc_id(); }
const vector<int> &mus_mc_motherid() { return cms3.mus_mc_motherid(); }
const vector<int> &pfjets_mc3_id() { return cms3.pfjets_mc3_id(); }
const vector<int> &pfjets_mc3idx() { return cms3.pfjets_mc3idx(); }
const vector<int> &pfjets_mc_motherid() { return cms3.pfjets_mc_motherid(); }
const vector<int> &photons_mc3_id() { return cms3.photons_mc3_id(); }
const vector<int> &photons_mc3idx() { return cms3.photons_mc3idx(); }
const vector<int> &photons_mc3_motherid() { return cms3.photons_mc3_motherid(); }
const vector<int> &photons_mc3_motheridx() { return cms3.photons_mc3_motheridx(); }
const vector<int> &photons_mc_id() { return cms3.photons_mc_id(); }
const vector<int> &photons_mc_motherid() { return cms3.photons_mc_motherid(); }
const vector<int> &els_VIDNonTrigMvaCat() { return cms3.els_VIDNonTrigMvaCat(); }
const vector<int> &els_VIDSpring16GPMvaCat() { return cms3.els_VIDSpring16GPMvaCat(); }
const vector<int> &els_VIDSpring16HZZMvaCat() { return cms3.els_VIDSpring16HZZMvaCat(); }
const vector<int> &els_VIDTrigMvaCat() { return cms3.els_VIDTrigMvaCat(); }
const vector<int> &els_category() { return cms3.els_category(); }
const vector<int> &els_charge() { return cms3.els_charge(); }
const vector<int> &els_ckf_charge() { return cms3.els_ckf_charge(); }
const vector<int> &els_ckf_laywithmeas() { return cms3.els_ckf_laywithmeas(); }
const vector<int> &els_exp_innerlayers() { return cms3.els_exp_innerlayers(); }
const vector<int> &els_exp_outerlayers() { return cms3.els_exp_outerlayers(); }
const vector<int> &els_isEB() { return cms3.els_isEB(); }
const vector<int> &els_isEcalDriven() { return cms3.els_isEcalDriven(); }
const vector<int> &els_isTrackerDriven() { return cms3.els_isTrackerDriven(); }
const vector<int> &els_lostHits() { return cms3.els_lostHits(); }
const vector<int> &els_lost_pixelhits() { return cms3.els_lost_pixelhits(); }
const vector<int> &els_mc_patMatch_id() { return cms3.els_mc_patMatch_id(); }
const vector<int> &els_nlayers() { return cms3.els_nlayers(); }
const vector<int> &els_nlayers3D() { return cms3.els_nlayers3D(); }
const vector<int> &els_nlayersLost() { return cms3.els_nlayersLost(); }
const vector<int> &els_sccharge() { return cms3.els_sccharge(); }
const vector<int> &els_trk_charge() { return cms3.els_trk_charge(); }
const vector<int> &els_type() { return cms3.els_type(); }
const vector<int> &els_validHits() { return cms3.els_validHits(); }
const vector<int> &els_valid_pixelhits() { return cms3.els_valid_pixelhits(); }
const vector<int> &els_passVIDNonTrigMvaWP80Id() { return cms3.els_passVIDNonTrigMvaWP80Id(); }
const vector<int> &els_passVIDNonTrigMvaWP90Id() { return cms3.els_passVIDNonTrigMvaWP90Id(); }
const vector<int> &els_passVIDTrigMvaWP80Id() { return cms3.els_passVIDTrigMvaWP80Id(); }
const vector<int> &els_passVIDTrigMvaWP90Id() { return cms3.els_passVIDTrigMvaWP90Id(); }
const vector<int> &genps_id() { return cms3.genps_id(); }
const vector<int> &genps_id_mother() { return cms3.genps_id_mother(); }
const vector<int> &genps_id_simplegrandma() { return cms3.genps_id_simplegrandma(); }
const vector<int> &genps_id_simplemother() { return cms3.genps_id_simplemother(); }
const vector<int> &genps_idx_mother() { return cms3.genps_idx_mother(); }
const vector<int> &genps_idx_simplemother() { return cms3.genps_idx_simplemother(); }
const vector<int> &genps_status() { return cms3.genps_status(); }
const vector<int> &hyp_ll_charge() { return cms3.hyp_ll_charge(); }
const vector<int> &hyp_ll_id() { return cms3.hyp_ll_id(); }
const vector<int> &hyp_ll_index() { return cms3.hyp_ll_index(); }
const vector<int> &hyp_lt_charge() { return cms3.hyp_lt_charge(); }
const vector<int> &hyp_lt_id() { return cms3.hyp_lt_id(); }
const vector<int> &hyp_lt_index() { return cms3.hyp_lt_index(); }
const vector<int> &hyp_type() { return cms3.hyp_type(); }
const vector<int> &isotracks_charge() { return cms3.isotracks_charge(); }
const vector<int> &isotracks_fromPV() { return cms3.isotracks_fromPV(); }
const vector<int> &isotracks_numberOfLostHitsInner() { return cms3.isotracks_numberOfLostHitsInner(); }
const vector<int> &isotracks_numberOfLostHitsOuter() { return cms3.isotracks_numberOfLostHitsOuter(); }
const vector<int> &isotracks_numberOfLostPixelHitsInner() { return cms3.isotracks_numberOfLostPixelHitsInner(); }
const vector<int> &isotracks_numberOfValidPixelHits() { return cms3.isotracks_numberOfValidPixelHits(); }
const vector<int> &isotracks_particleId() { return cms3.isotracks_particleId(); }
const vector<int> &isotracks_pixelLayersWithMeasurement() { return cms3.isotracks_pixelLayersWithMeasurement(); }
const vector<int> &isotracks_trackerLayersWithMeasurement() { return cms3.isotracks_trackerLayersWithMeasurement(); }
const vector<int> &mus_algo() { return cms3.mus_algo(); }
const vector<int> &mus_algoOrig() { return cms3.mus_algoOrig(); }
const vector<int> &mus_bfit_algo() { return cms3.mus_bfit_algo(); }
const vector<int> &mus_charge() { return cms3.mus_charge(); }
const vector<int> &mus_exp_innerlayers() { return cms3.mus_exp_innerlayers(); }
const vector<int> &mus_exp_outerlayers() { return cms3.mus_exp_outerlayers(); }
const vector<int> &mus_gfit_algo() { return cms3.mus_gfit_algo(); }
const vector<int> &mus_gfit_ndof() { return cms3.mus_gfit_ndof(); }
const vector<int> &mus_gfit_validSTAHits() { return cms3.mus_gfit_validSTAHits(); }
const vector<int> &mus_iso03_ntrk() { return cms3.mus_iso03_ntrk(); }
const vector<int> &mus_lostHits() { return cms3.mus_lostHits(); }
const vector<int> &mus_mc_patMatch_id() { return cms3.mus_mc_patMatch_id(); }
const vector<int> &mus_nlayers() { return cms3.mus_nlayers(); }
const vector<int> &mus_numberOfMatchedStations() { return cms3.mus_numberOfMatchedStations(); }
const vector<int> &mus_pfcharge() { return cms3.mus_pfcharge(); }
const vector<int> &mus_pfidx() { return cms3.mus_pfidx(); }
const vector<int> &mus_pfparticleId() { return cms3.mus_pfparticleId(); }
const vector<int> &mus_pid_PFMuon() { return cms3.mus_pid_PFMuon(); }
const vector<int> &mus_pid_TM2DCompatibilityLoose() { return cms3.mus_pid_TM2DCompatibilityLoose(); }
const vector<int> &mus_pid_TM2DCompatibilityTight() { return cms3.mus_pid_TM2DCompatibilityTight(); }
const vector<int> &mus_pid_TMLastStationLoose() { return cms3.mus_pid_TMLastStationLoose(); }
const vector<int> &mus_pid_TMLastStationTight() { return cms3.mus_pid_TMLastStationTight(); }
const vector<int> &mus_pid_TMOneStationTight() { return cms3.mus_pid_TMOneStationTight(); }
const vector<int> &mus_type() { return cms3.mus_type(); }
const vector<int> &mus_validHits() { return cms3.mus_validHits(); }
const vector<int> &mus_validPixelHits() { return cms3.mus_validPixelHits(); }
const vector<int> &pfcands_IdAssociatedPV() { return cms3.pfcands_IdAssociatedPV(); }
const vector<int> &pfcands_charge() { return cms3.pfcands_charge(); }
const vector<int> &pfcands_numberOfHits() { return cms3.pfcands_numberOfHits(); }
const vector<int> &pfcands_numberOfPixelHits() { return cms3.pfcands_numberOfPixelHits(); }
const vector<int> &pfcands_particleId() { return cms3.pfcands_particleId(); }
const vector<int> &pfcands_pixelLayersWithMeasurement() { return cms3.pfcands_pixelLayersWithMeasurement(); }
const vector<int> &pfcands_stripLayersWithMeasurement() { return cms3.pfcands_stripLayersWithMeasurement(); }
const vector<int> &pfjets_chargedHadronMultiplicity() { return cms3.pfjets_chargedHadronMultiplicity(); }
const vector<int> &pfjets_chargedMultiplicity() { return cms3.pfjets_chargedMultiplicity(); }
const vector<int> &pfjets_electronMultiplicity() { return cms3.pfjets_electronMultiplicity(); }
const vector<int> &pfjets_hadronFlavour() { return cms3.pfjets_hadronFlavour(); }
const vector<int> &pfjets_muonMultiplicity() { return cms3.pfjets_muonMultiplicity(); }
const vector<int> &pfjets_neutralHadronMultiplicity() { return cms3.pfjets_neutralHadronMultiplicity(); }
const vector<int> &pfjets_neutralMultiplicity() { return cms3.pfjets_neutralMultiplicity(); }
const vector<int> &pfjets_npfcands() { return cms3.pfjets_npfcands(); }
const vector<int> &pfjets_partonFlavour() { return cms3.pfjets_partonFlavour(); }
const vector<int> &pfjets_photonMultiplicity() { return cms3.pfjets_photonMultiplicity(); }
const vector<int> &pfjets_totalMultiplicity() { return cms3.pfjets_totalMultiplicity(); }
const vector<int> &pfjets_puppi_chargedHadronMultiplicity() { return cms3.pfjets_puppi_chargedHadronMultiplicity(); }
const vector<int> &pfjets_puppi_chargedMultiplicity() { return cms3.pfjets_puppi_chargedMultiplicity(); }
const vector<int> &pfjets_puppi_electronMultiplicity() { return cms3.pfjets_puppi_electronMultiplicity(); }
const vector<int> &pfjets_puppi_hadronFlavour() { return cms3.pfjets_puppi_hadronFlavour(); }
const vector<int> &pfjets_puppi_muonMultiplicity() { return cms3.pfjets_puppi_muonMultiplicity(); }
const vector<int> &pfjets_puppi_neutralHadronMultiplicity() { return cms3.pfjets_puppi_neutralHadronMultiplicity(); }
const vector<int> &pfjets_puppi_neutralMultiplicity() { return cms3.pfjets_puppi_neutralMultiplicity(); }
const vector<int> &pfjets_puppi_npfcands() { return cms3.pfjets_puppi_npfcands(); }
const vector<int> &pfjets_puppi_partonFlavour() { return cms3.pfjets_puppi_partonFlavour(); }
const vector<int> &pfjets_puppi_photonMultiplicity() { return cms3.pfjets_puppi_photonMultiplicity(); }
const vector<int> &pfjets_puppi_totalMultiplicity() { return cms3.pfjets_puppi_totalMultiplicity(); }
const vector<int> &taus_pf_charge() { return cms3.taus_pf_charge(); }
const vector<int> &photons_photonID_loose() { return cms3.photons_photonID_loose(); }
const vector<int> &photons_photonID_tight() { return cms3.photons_photonID_tight(); }
const vector<int> &puInfo_bunchCrossing() { return cms3.puInfo_bunchCrossing(); }
const vector<int> &puInfo_nPUvertices() { return cms3.puInfo_nPUvertices(); }
const vector<int> &svs_nTrks() { return cms3.svs_nTrks(); }
const vector<int> &_npfcands() { return cms3._npfcands(); }
const vector<int> &ak8jets_partonFlavour() { return cms3.ak8jets_partonFlavour(); }
const vector<int> &vtxs_isFake() { return cms3.vtxs_isFake(); }
const vector<int> &vtxs_isValid() { return cms3.vtxs_isValid(); }
const vector<vector<int> > &genps_lepdaughter_id() { return cms3.genps_lepdaughter_id(); }
const vector<vector<int> > &genps_lepdaughter_idx() { return cms3.genps_lepdaughter_idx(); }
const vector<vector<int> > &photons_PFCand_idx() { return cms3.photons_PFCand_idx(); }
const vector<unsigned char> &pfcands_fromPV() { return cms3.pfcands_fromPV(); }
const vector<unsigned char> &pfcands_normalizedChi2() { return cms3.pfcands_normalizedChi2(); }
const vector<unsigned char> &pfcands_packedHits() { return cms3.pfcands_packedHits(); }
const vector<unsigned char> &pfcands_packedLayers() { return cms3.pfcands_packedLayers(); }
const vector<unsigned char> &pfcands_pvAssociationQuality() { return cms3.pfcands_pvAssociationQuality(); }
const unsigned int &evt_nels() { return cms3.evt_nels(); }
const unsigned int &evt_detectorStatus() { return cms3.evt_detectorStatus(); }
const unsigned int &evt_lumiBlock() { return cms3.evt_lumiBlock(); }
const unsigned int &evt_run() { return cms3.evt_run(); }
const unsigned int &evt_ngenjetsNoMuNoNu() { return cms3.evt_ngenjetsNoMuNoNu(); }
const unsigned int &genps_signalProcessID() { return cms3.genps_signalProcessID(); }
const unsigned int &evt_nphotons() { return cms3.evt_nphotons(); }
const unsigned int &evt_nvtxs() { return cms3.evt_nvtxs(); }
const vector<unsigned int> &hlt_l1prescales() { return cms3.hlt_l1prescales(); }
const vector<unsigned int> &hlt_prescales() { return cms3.hlt_prescales(); }
const vector<vector<unsigned int> > &isotracks_crossedHcalStatus() { return cms3.isotracks_crossedHcalStatus(); }
const ULong64_t &evt_event() { return cms3.evt_event(); }
const vector<ULong64_t> &evt_timestamp() { return cms3.evt_timestamp(); }
bool passHLTTrigger(TString trigName) { return cms3.passHLTTrigger(trigName); }
float passTauID(TString idName, unsigned int tauIndx) { return cms3.passTauID(idName, tauIndx); }
float getbtagvalue(TString bDiscriminatorName, unsigned int jetIndx) { return cms3.getbtagvalue( bDiscriminatorName, jetIndx); }

}
