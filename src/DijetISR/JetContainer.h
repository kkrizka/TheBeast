#ifndef JETCONTAINER_H_
#define JETCONTAINER_H_

#include <TTree.h>
#include <TLorentzVector.h>
#include <TTreeReader.h>

#include <vector>
#include <string>

#include "InfoSwitch.h"

#include "ParticleContainer.h"
#include "../xAH/Jet.h"

class JetContainer : public ParticleContainer<xAH::Jet,JetInfoSwitch>
{
public:
  JetContainer(const std::string& name = "jet", const std::string& detailStr="", float units = 1e3, bool mc = false);
  virtual ~JetContainer();
    
  virtual void setReader  (TTreeReader *reader);
  virtual void setReader  (TTreeReader *reader, const std::string& tagger/*="MV2c10"*/);

  virtual void updateParticle(uint idx);

private:

  bool findBTagSF(const std::vector<int>& sfList, int workingPt);
      
  //
  // Vector branches
    
  // rapidity
  TTreeReaderArray<float> m_rapidity;
  
  // clean
  TTreeReaderArray<float> m_Timing;
  TTreeReaderArray<float> m_LArQuality;
  TTreeReaderArray<float> m_HECQuality;
  TTreeReaderArray<float> m_NegativeE;
  TTreeReaderArray<float> m_AverageLArQF;
  TTreeReaderArray<float> m_BchCorrCell;
  TTreeReaderArray<float> m_N90Constituents;
  TTreeReaderArray<float> m_LArBadHVEnergyFrac;
  TTreeReaderArray<int  > m_LArBadHVNCell;
  TTreeReaderArray<float> m_OotFracClusters5;
  TTreeReaderArray<float> m_OotFracClusters10;
  TTreeReaderArray<float> m_LeadingClusterPt;
  TTreeReaderArray<float> m_LeadingClusterSecondLambda;
  TTreeReaderArray<float> m_LeadingClusterCenterLambda;
  TTreeReaderArray<float> m_LeadingClusterSecondR;
  TTreeReaderArray<int  > m_clean_passLooseBad;
  TTreeReaderArray<int  > m_clean_passLooseBadUgly;
  TTreeReaderArray<int  > m_clean_passTightBad;
  TTreeReaderArray<int  > m_clean_passTightBadUgly;

  // energy
  TTreeReaderArray<float> m_HECFrac;
  TTreeReaderArray<float> m_EMFrac;
  TTreeReaderArray<float> m_CentroidR;
  TTreeReaderArray<float> m_FracSamplingMax;
  TTreeReaderArray<float> m_FracSamplingMaxIndex;
  TTreeReaderArray<float> m_LowEtConstituentsFrac;
  TTreeReaderArray<float> m_GhostMuonSegmentCount;
  TTreeReaderArray<float> m_Width;

  // sclaes
  TTreeReaderArray<float> m_emScalePt;
  TTreeReaderArray<float> m_constScalePt;
  TTreeReaderArray<float> m_pileupScalePt;
  TTreeReaderArray<float> m_originConstitScalePt;
  TTreeReaderArray<float> m_etaJESScalePt;
  TTreeReaderArray<float> m_gscScalePt;
  TTreeReaderArray<float> m_insituScalePt;

  // constScale Eta
  TTreeReaderArray<float> m_constScaleEta;


  // layer
  TTreeReaderArray<std::vector<float>> m_EnergyPerSampling;

  // tracksAll
  TTreeReaderArray<std::vector<int  >> m_NumTrkPt1000;
  TTreeReaderArray<std::vector<float>> m_SumPtTrkPt1000;
  TTreeReaderArray<std::vector<float>> m_TrackWidthPt1000;
  TTreeReaderArray<std::vector<int  >> m_NumTrkPt500;
  TTreeReaderArray<std::vector<float>> m_SumPtTrkPt500;
  TTreeReaderArray<std::vector<float>> m_TrackWidthPt500;
  TTreeReaderArray<std::vector<float>> m_JVF;

  // trackPV
  TTreeReaderArray<float> m_NumTrkPt1000PV;
  TTreeReaderArray<float> m_SumPtTrkPt1000PV;
  TTreeReaderArray<float> m_TrackWidthPt1000PV;
  TTreeReaderArray<float> m_NumTrkPt500PV;
  TTreeReaderArray<float> m_SumPtTrkPt500PV;
  TTreeReaderArray<float> m_TrackWidthPt500PV;
  TTreeReaderArray<float> m_JVFPV;

  // trackAll or trackPV
  TTreeReaderArray<float> m_Jvt;
  TTreeReaderArray<std::vector<float> > m_JvtEff_SF_Loose;
  TTreeReaderArray<std::vector<float> > m_JvtEff_SF_Medium;
  TTreeReaderArray<std::vector<float> > m_JvtEff_SF_Tight;
  TTreeReaderArray<float> m_JvtJvfcorr;
  TTreeReaderArray<float> m_JvtRpt;

  // allTrack
  TTreeReaderArray<int  >              m_GhostTrackCount;
  TTreeReaderArray<float>              m_GhostTrackPt;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_pt;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_qOverP;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_eta;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_phi;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_e;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_d0;
  TTreeReaderArray<std::vector<float>> m_GhostTrack_z0;

  // allTrackDetail
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nPixelHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nSCTHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nTRTHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nPixelSharedHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nPixelSplitHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nInnermostPixelLayerHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nInnermostPixelLayerSharedHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nInnermostPixelLayerSplitHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nNextToInnermostPixelLayerHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nNextToInnermostPixelLayerSharedHits;
  TTreeReaderArray<std::vector<int> > m_GhostTrack_nNextToInnermostPixelLayerSplitHits;

  // constituent
  TTreeReaderArray< int >              m_numConstituents;
  TTreeReaderArray<std::vector<float>> m_constituentWeights;
  TTreeReaderArray<std::vector<float>> m_constituent_pt;
  TTreeReaderArray<std::vector<float>> m_constituent_eta;
  TTreeReaderArray<std::vector<float>> m_constituent_phi;
  TTreeReaderArray<std::vector<float>> m_constituent_e;

  // flavTag
  TTreeReaderArray<float> m_MV2c00;
  TTreeReaderArray<float> m_MV2c10;
  TTreeReaderArray<float> m_MV2c20;
  TTreeReaderArray<float> m_MV2c100;
  TTreeReaderArray<float> m_MV2;
  TTreeReaderArray<int  > m_HadronConeExclTruthLabelID;
    
  // Jet Fitter 
  TTreeReaderArray<float> m_JetFitter_nVTX           ;
  TTreeReaderArray<float> m_JetFitter_nSingleTracks  ;
  TTreeReaderArray<float> m_JetFitter_nTracksAtVtx   ;
  TTreeReaderArray<float> m_JetFitter_mass           ;
  TTreeReaderArray<float> m_JetFitter_energyFraction ;
  TTreeReaderArray<float> m_JetFitter_significance3d ;
  TTreeReaderArray<float> m_JetFitter_deltaeta       ;
  TTreeReaderArray<float> m_JetFitter_deltaphi       ;
  TTreeReaderArray<float> m_JetFitter_N2Tpar         ;

  // SV Details
  TTreeReaderArray<float> m_SV0                     ;
  TTreeReaderArray<float> m_SV0_NGTinSvx            ;
  TTreeReaderArray<float> m_SV0_N2Tpair             ;
  TTreeReaderArray<float> m_SV0_masssvx             ;
  TTreeReaderArray<float> m_SV0_efracsvx            ;
  TTreeReaderArray<float> m_SV0_normdist            ;

  TTreeReaderArray<float> m_SV1                     ;
  TTreeReaderArray<float> m_SV1plusIP3D_discriminant;
  TTreeReaderArray<float> m_SV1_pu                  ;
  TTreeReaderArray<float> m_SV1_pb                  ;
  TTreeReaderArray<float> m_SV1_pc                  ;
  TTreeReaderArray<float> m_SV1_c                   ;
  TTreeReaderArray<float> m_SV1_cu                  ;
  TTreeReaderArray<float> m_SV1_NGTinSvx            ;
  TTreeReaderArray<float> m_SV1_N2Tpair             ;
  TTreeReaderArray<float> m_SV1_masssvx             ;
  TTreeReaderArray<float> m_SV1_efracsvx            ;
  TTreeReaderArray<float> m_SV1_normdist            ;
  TTreeReaderArray<float> m_SV1_Lxy                 ;
  TTreeReaderArray<float> m_SV1_L3d                 ;
  TTreeReaderArray<float> m_SV1_distmatlay          ;
  TTreeReaderArray<float> m_SV1_dR                  ;

  // IP3D
  TTreeReaderArray<float> m_IP2D_pu                   ;
  TTreeReaderArray<float> m_IP2D_pb                   ;
  TTreeReaderArray<float> m_IP2D_pc                   ;
  TTreeReaderArray<float> m_IP2D                      ;
  TTreeReaderArray<float> m_IP2D_c                    ;
  TTreeReaderArray<float> m_IP2D_cu                   ;
  TTreeReaderArray<float> m_nIP2DTracks               ;

  TTreeReaderArray<std::vector<float> > m_IP2D_gradeOfTracks        ;
  TTreeReaderArray<std::vector<float> > m_IP2D_flagFromV0ofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP2D_valD0wrtPVofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP2D_sigD0wrtPVofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP2D_weightBofTracks      ;
  TTreeReaderArray<std::vector<float> > m_IP2D_weightCofTracks      ;
  TTreeReaderArray<std::vector<float> > m_IP2D_weightUofTracks      ;

  TTreeReaderArray<float> m_IP3D_pu                   ;
  TTreeReaderArray<float> m_IP3D_pb                   ;
  TTreeReaderArray<float> m_IP3D_pc                   ;
  TTreeReaderArray<float> m_IP3D                      ;
  TTreeReaderArray<float> m_IP3D_c                    ;
  TTreeReaderArray<float> m_IP3D_cu                   ;
  TTreeReaderArray<float> m_nIP3DTracks               ;
  TTreeReaderArray<std::vector<float> > m_IP3D_gradeOfTracks        ;
  TTreeReaderArray<std::vector<float> > m_IP3D_flagFromV0ofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP3D_valD0wrtPVofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP3D_sigD0wrtPVofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP3D_valZ0wrtPVofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP3D_sigZ0wrtPVofTracks   ;
  TTreeReaderArray<std::vector<float> > m_IP3D_weightBofTracks      ;
  TTreeReaderArray<std::vector<float> > m_IP3D_weightCofTracks      ;
  TTreeReaderArray<std::vector<float> > m_IP3D_weightUofTracks      ;

  TTreeReaderArray<float> m_vtxOnlineValid;
  TTreeReaderArray<float> m_vtxHadDummy;

      
  TTreeReaderArray<float> m_bs_online_vx;
  TTreeReaderArray<float> m_bs_online_vy;
  TTreeReaderArray<float> m_bs_online_vz;


  TTreeReaderArray<float> m_vtx_offline_x0;
  TTreeReaderArray<float> m_vtx_offline_y0;
  TTreeReaderArray<float> m_vtx_offline_z0;

  TTreeReaderArray<float> m_vtx_online_x0;
  TTreeReaderArray<float> m_vtx_online_y0;
  TTreeReaderArray<float> m_vtx_online_z0;

  TTreeReaderArray<float> m_vtx_online_bkg_x0;
  TTreeReaderArray<float> m_vtx_online_bkg_y0;
  TTreeReaderArray<float> m_vtx_online_bkg_z0;

  struct btagOpPoint {
    std::string m_name;
    bool m_mc;
    std::string m_acessorName;
    std::string m_tagger;
    TTreeReaderValue<int> m_njets;
    TTreeReaderArray<int>                m_isTag;
    TTreeReaderArray<std::vector<float>> m_sf;
    TTreeReaderArray<float>              m_weight_sf;

    btagOpPoint(std::string name, bool mc, std::string acessorName, std::string tagger="mv2c10"): m_name(name), m_mc(mc), m_acessorName(acessorName), m_tagger(tagger) { }

    ~btagOpPoint() { }

    void setReader(TTreeReader *reader, const std::string& jetName)
    {
      m_njets=TTreeReaderValue<int>(*reader, ("n"+jetName+"s_"+m_name).c_str());
      m_isTag=TTreeReaderArray<int>(*reader, (jetName+"_is"+m_name).c_str());

      if(m_mc)
	m_sf=TTreeReaderArray<std::vector<float> >(*reader, (jetName+"_SF"+m_name).c_str());
    }
  };  //struct btagOpPoint
      
  btagOpPoint* m_btag_Fix30;
  btagOpPoint* m_btag_Fix50;
  btagOpPoint* m_btag_Fix60;
  btagOpPoint* m_btag_Fix70;
  btagOpPoint* m_btag_Fix77;
  btagOpPoint* m_btag_Fix80;
  btagOpPoint* m_btag_Fix85;
  btagOpPoint* m_btag_Fix90;

  btagOpPoint* m_btag_Flt30;
  btagOpPoint* m_btag_Flt50;
  btagOpPoint* m_btag_Flt60;
  btagOpPoint* m_btag_Flt70;
  btagOpPoint* m_btag_Flt77;
  btagOpPoint* m_btag_Flt85;
  btagOpPoint* m_btag_Flt90;

  // JVC
  TTreeReaderArray<double> m_JetVertexCharge_discriminant;

  // area
  TTreeReaderArray<float> m_GhostArea;
  TTreeReaderArray<float> m_ActiveArea;
  TTreeReaderArray<float> m_VoronoiArea;
  TTreeReaderArray<float> m_ActiveArea4vec_pt;
  TTreeReaderArray<float> m_ActiveArea4vec_eta;
  TTreeReaderArray<float> m_ActiveArea4vec_phi;
  TTreeReaderArray<float> m_ActiveArea4vec_m;

  // truth
  TTreeReaderArray<int  > m_ConeTruthLabelID;
  TTreeReaderArray<int  > m_TruthCount;
  TTreeReaderArray<float> m_TruthLabelDeltaR_B;
  TTreeReaderArray<float> m_TruthLabelDeltaR_C;
  TTreeReaderArray<float> m_TruthLabelDeltaR_T;
  TTreeReaderArray<int  > m_PartonTruthLabelID;
  TTreeReaderArray<float> m_GhostTruthAssociationFraction;
  TTreeReaderArray<float> m_truth_E;
  TTreeReaderArray<float> m_truth_pt;
  TTreeReaderArray<float> m_truth_phi;
  TTreeReaderArray<float> m_truth_eta;


  // truth detail
  TTreeReaderArray<int  > m_GhostBHadronsFinalCount;
  TTreeReaderArray<int  > m_GhostBHadronsInitialCount;
  TTreeReaderArray<int  > m_GhostBQuarksFinalCount;
  TTreeReaderArray<float> m_GhostBHadronsFinalPt;
  TTreeReaderArray<float> m_GhostBHadronsInitialPt;
  TTreeReaderArray<float> m_GhostBQuarksFinalPt;

  TTreeReaderArray<int  > m_GhostCHadronsFinalCount;
  TTreeReaderArray<int  > m_GhostCHadronsInitialCount;
  TTreeReaderArray<int  > m_GhostCQuarksFinalCount;
  TTreeReaderArray<float> m_GhostCHadronsFinalPt;
  TTreeReaderArray<float> m_GhostCHadronsInitialPt;
  TTreeReaderArray<float> m_GhostCQuarksFinalPt;

  TTreeReaderArray<int  > m_GhostTausFinalCount;
  TTreeReaderArray<float> m_GhostTausFinalPt;

  TTreeReaderArray<int  > m_truth_pdgId;
  TTreeReaderArray<float> m_truth_partonPt;
  TTreeReaderArray<float> m_truth_partonDR;

  // charge
  TTreeReaderArray<double> m_charge;
};

#endif // JETCONTAINER_H_
