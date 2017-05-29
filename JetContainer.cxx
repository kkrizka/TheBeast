#include "JetContainer.h"

JetContainer::JetContainer(const std::string& name, const std::string& detailStr, float units, bool mc)
  : ParticleContainer(name,detailStr,units,mc)
{
  // rapidity
  if(m_infoSwitch.m_rapidity) {
    m_rapidity                    =new std::vector<float>();
  }

  // clean
  if(m_infoSwitch.m_clean) {
    m_Timing                    =new std::vector<float>();
    m_LArQuality                =new std::vector<float>();
    m_HECQuality                =new std::vector<float>();
    m_NegativeE                 =new std::vector<float>();
    m_AverageLArQF              =new std::vector<float>();
    m_BchCorrCell               =new std::vector<float>();
    m_N90Constituents           =new std::vector<float>();
    m_LArBadHVEnergyFrac        =new std::vector<float>();  
    m_LArBadHVNCell             =new std::vector<int>();
    m_OotFracClusters5          =new std::vector<float>();
    m_OotFracClusters10         =new std::vector<float>();
    m_LeadingClusterPt          =new std::vector<float>();
    m_LeadingClusterSecondLambda=new std::vector<float>();
    m_LeadingClusterCenterLambda=new std::vector<float>();
    m_LeadingClusterSecondR     =new std::vector<float>();
    m_clean_passLooseBad        =new std::vector<int>();
    m_clean_passLooseBadUgly    =new std::vector<int>();
    m_clean_passTightBad        =new std::vector<int>();
    m_clean_passTightBadUgly    =new std::vector<int>();
  }

  // energy
  if ( m_infoSwitch.m_energy ) {
    m_HECFrac               = new std::vector<float>();
    m_EMFrac                = new std::vector<float>();
    m_CentroidR             = new std::vector<float>();
    m_FracSamplingMax       = new std::vector<float>();
    m_FracSamplingMaxIndex  = new std::vector<float>();
    m_LowEtConstituentsFrac = new std::vector<float>();
    m_GhostMuonSegmentCount = new std::vector<float>();
    m_Width                 = new std::vector<float>();
  }

  // scales
  if ( m_infoSwitch.m_scales ) {
    m_emScalePt               = new std::vector<float>(); 
    m_constScalePt	    = new std::vector<float>(); 
    m_pileupScalePt		    = new std::vector<float>(); 
    m_originConstitScalePt    = new std::vector<float>(); 
    m_etaJESScalePt	    = new std::vector<float>(); 
    m_gscScalePt		    = new std::vector<float>(); 
    m_insituScalePt	    = new std::vector<float>(); 
  }

  // constscale eta
  if ( m_infoSwitch.m_constscaleEta ) {
    m_constScaleEta               = new std::vector<float>(); 
  }

  // layer
  if ( m_infoSwitch.m_layer ) {
    m_EnergyPerSampling       = new std::vector< std::vector<float> >();
  }

  // tracksAll
  if ( m_infoSwitch.m_trackAll ) {
    m_NumTrkPt1000             = new std::vector< std::vector<int> >    ();
    m_SumPtTrkPt1000           = new std::vector< std::vector<float> >  ();
    m_TrackWidthPt1000         = new std::vector< std::vector<float> >  ();
    m_NumTrkPt500              = new std::vector< std::vector<int> >    ();
    m_SumPtTrkPt500            = new std::vector< std::vector<float> >  ();
    m_TrackWidthPt500          = new std::vector< std::vector<float> >  ();
    m_JVF                      = new std::vector< std::vector<float> >  ();
  }

  // trackPV
  if ( m_infoSwitch.m_trackPV ) {
    m_NumTrkPt1000PV       =new std::vector<float>();
    m_SumPtTrkPt1000PV     =new std::vector<float>();
    m_TrackWidthPt1000PV   =new std::vector<float>();
    m_NumTrkPt500PV        =new std::vector<float>();
    m_SumPtTrkPt500PV      =new std::vector<float>();
    m_TrackWidthPt500PV    =new std::vector<float>();
    m_JVFPV                =new std::vector<float>();
    m_Jvt                = new std::vector<float>();
    m_JvtJvfcorr         = new std::vector<float>();
    m_JvtRpt             = new std::vector<float>();
    if( m_mc ){
      m_JvtEff_SF_Loose    = new std::vector< std::vector<float> > ();
      m_JvtEff_SF_Medium   = new std::vector< std::vector<float> > ();
      m_JvtEff_SF_Tight    = new std::vector< std::vector<float> > ();
    }
  }


  // allTrack
  // trackAll or trackPV
  if ( m_infoSwitch.m_allTrack ) {
    m_GhostTrackCount     = new std::vector<int>                  ();
    m_GhostTrackPt        = new std::vector<float>                ();
    m_GhostTrack_pt       = new std::vector< std::vector<float> > ();
    m_GhostTrack_qOverP   = new std::vector< std::vector<float> > ();
    m_GhostTrack_eta      = new std::vector< std::vector<float> > ();
    m_GhostTrack_phi      = new std::vector< std::vector<float> > ();
    m_GhostTrack_e        = new std::vector< std::vector<float> > ();
    m_GhostTrack_d0       = new std::vector< std::vector<float> > ();
    m_GhostTrack_z0       = new std::vector< std::vector<float> > ();
    

    // allTrackDetail
    if(m_infoSwitch.m_allTrackDetail){
      m_GhostTrack_nPixelHits                               = new std::vector< std::vector<int> >();   
      m_GhostTrack_nSCTHits                                 = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nTRTHits                                 = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nPixelSharedHits                         = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nPixelSplitHits                          = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nInnermostPixelLayerHits                 = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nInnermostPixelLayerSharedHits           = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nInnermostPixelLayerSplitHits            = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nNextToInnermostPixelLayerHits           = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nNextToInnermostPixelLayerSharedHits     = new std::vector< std::vector<int> >(); 
      m_GhostTrack_nNextToInnermostPixelLayerSplitHits      = new std::vector< std::vector<int> >(); 
    }
  }

  // constituent
  if ( m_infoSwitch.m_constituent ) {
    m_numConstituents        = new  std::vector< int >                ();
  }

  if ( m_infoSwitch.m_constituentAll ) {
    m_constituentWeights     = new  std::vector< std::vector<float> > ();
    m_constituent_pt         = new  std::vector< std::vector<float> > ();
    m_constituent_eta        = new  std::vector< std::vector<float> > ();
    m_constituent_phi        = new  std::vector< std::vector<float> > ();
    m_constituent_e          = new  std::vector< std::vector<float> > ();
  }

  // flavTag
  if( m_infoSwitch.m_flavTag  || m_infoSwitch.m_flavTagHLT  ) {
    
    //m_MV1                       =new std::vector<float>();
    m_MV2c00                    =new std::vector<float>();
    m_MV2c10                    =new std::vector<float>();
    m_MV2c20                    =new std::vector<float>();
    m_MV2c100                   =new std::vector<float>();
    m_MV2                       =new std::vector<float>();
    m_HadronConeExclTruthLabelID=new std::vector<int>();

    // Jet Fitter 
    if( m_infoSwitch.m_jetFitterDetails){
      m_JetFitter_nVTX             = new std::vector<float>();
      m_JetFitter_nSingleTracks    = new std::vector<float>();
      m_JetFitter_nTracksAtVtx     = new std::vector<float>();
      m_JetFitter_mass             = new std::vector<float>();
      m_JetFitter_energyFraction   = new std::vector<float>();
      m_JetFitter_significance3d   = new std::vector<float>();
      m_JetFitter_deltaeta         = new std::vector<float>();
      m_JetFitter_deltaphi         = new std::vector<float>();
      m_JetFitter_N2Tpar           = new std::vector<float>();
    }

    // SV Details
    if( m_infoSwitch.m_svDetails){

      m_SV0               = new      std::vector<float>();


      m_sv0_NGTinSvx      = new     std::vector<float>(); 
      m_sv0_N2Tpair       = new     std::vector<float>(); 
      m_sv0_massvx        = new     std::vector<float>(); 
      m_sv0_efracsvx      = new     std::vector<float>(); 
      m_sv0_normdist      = new     std::vector<float>(); 

      m_SV1               = new     std::vector<float>();
      m_SV1IP3D           = new     std::vector<float>();
      m_sv1_pu            = new     std::vector<float>(); 
      m_sv1_pb            = new     std::vector<float>(); 
      m_sv1_pc            = new     std::vector<float>(); 
      m_sv1_c             = new     std::vector<float>(); 
      m_sv1_cu            = new     std::vector<float>(); 
      m_sv1_NGTinSvx      = new     std::vector<float>(); 
      m_sv1_N2Tpair       = new     std::vector<float>(); 
      m_sv1_massvx        = new     std::vector<float>(); 
      m_sv1_efracsvx      = new     std::vector<float>(); 
      m_sv1_normdist      = new     std::vector<float>(); 
      m_sv1_Lxy           = new     std::vector<float>(); 
      m_sv1_L3d           = new     std::vector<float>(); 
      m_sv1_distmatlay    = new     std::vector<float>(); 
      m_sv1_dR            = new     std::vector<float>(); 
    }

    // IP3D
    if( m_infoSwitch.m_ipDetails){    
      m_IP2D_pu        = new std::vector<float>(); 
      m_IP2D_pb        = new std::vector<float>(); 
      m_IP2D_pc        = new std::vector<float>(); 
      m_IP2D           = new std::vector<float>(); 
      m_IP2D_c         = new std::vector<float>(); 
      m_IP2D_cu        = new std::vector<float>(); 
      m_nIP2DTracks    = new std::vector<float>(); 
      
      m_IP2D_gradeOfTracks              = new std::vector<std::vector<float> >(); 
      m_IP2D_flagFromV0ofTracks         = new std::vector<std::vector<float> >(); 
      m_IP2D_valD0wrtPVofTracks         = new std::vector<std::vector<float> >(); 
      m_IP2D_sigD0wrtPVofTracks         = new std::vector<std::vector<float> >(); 
      m_IP2D_weightBofTracks            = new std::vector<std::vector<float> >(); 
      m_IP2D_weightCofTracks            = new std::vector<std::vector<float> >(); 
      m_IP2D_weightUofTracks            = new std::vector<std::vector<float> >(); 

      m_IP3D         = new std::vector<float>();
      m_IP3D_pu      = new std::vector<float>(); 
      m_IP3D_pb      = new std::vector<float>(); 
      m_IP3D_pc      = new std::vector<float>(); 
      m_IP3D_c       = new std::vector<float>(); 
      m_IP3D_cu      = new std::vector<float>(); 
      m_nIP3DTracks  = new std::vector<float>(); 
      m_IP3D_gradeOfTracks        = new  std::vector<std::vector<float> >();
      m_IP3D_flagFromV0ofTracks   = new  std::vector<std::vector<float> >();
      m_IP3D_valD0wrtPVofTracks   = new  std::vector<std::vector<float> >();
      m_IP3D_sigD0wrtPVofTracks   = new  std::vector<std::vector<float> >();
      m_IP3D_valZ0wrtPVofTracks   = new  std::vector<std::vector<float> >();
      m_IP3D_sigZ0wrtPVofTracks   = new  std::vector<std::vector<float> >();
      m_IP3D_weightBofTracks      = new  std::vector<std::vector<float> >();
      m_IP3D_weightCofTracks      = new  std::vector<std::vector<float> >();
      m_IP3D_weightUofTracks      = new  std::vector<std::vector<float> >();
    }

    if( m_infoSwitch.m_JVC ) {
      m_JetVertexCharge_discriminant = new std::vector<double>();
    }

  }

  //  flavTagHLT
  if( m_infoSwitch.m_flavTagHLT  ) {
    m_vtxOnlineValid     = new  std::vector<float>(); 
    m_vtxHadDummy        = new  std::vector<float>();

    m_bs_online_vx       = new  std::vector<float>(); 
    m_bs_online_vy       = new  std::vector<float>(); 
    m_bs_online_vz       = new  std::vector<float>(); 
    
    m_vtx_offline_x0     = new  std::vector<float>(); 
    m_vtx_offline_y0     = new  std::vector<float>(); 
    m_vtx_offline_z0     = new  std::vector<float>(); 
                                              
    m_vtx_online_x0      = new  std::vector<float>(); 
    m_vtx_online_y0      = new  std::vector<float>(); 
    m_vtx_online_z0      = new  std::vector<float>(); 
                                              
    m_vtx_online_bkg_x0  = new  std::vector<float>(); 
    m_vtx_online_bkg_y0  = new  std::vector<float>(); 
    m_vtx_online_bkg_z0  = new  std::vector<float>(); 
  }

  if( !m_infoSwitch.m_sfFTagFix.empty() ) {
    m_btag_Fix30   = new  btagOpPoint("Fix30",m_mc, "FixedCutBEff_30");
    m_btag_Fix50   = new  btagOpPoint("Fix50",m_mc, "FixedCutBEff_50");
    m_btag_Fix60   = new  btagOpPoint("Fix60",m_mc, "FixedCutBEff_60");
    m_btag_Fix70   = new  btagOpPoint("Fix70",m_mc, "FixedCutBEff_70");
    m_btag_Fix77   = new  btagOpPoint("Fix77",m_mc, "FixedCutBEff_77");
    m_btag_Fix80   = new  btagOpPoint("Fix80",m_mc, "FixedCutBEff_80");
    m_btag_Fix85   = new  btagOpPoint("Fix85",m_mc, "FixedCutBEff_85");
    m_btag_Fix90   = new  btagOpPoint("Fix90",m_mc, "FixedCutBEff_90");
  }

  if( !m_infoSwitch.m_sfFTagFlt.empty() ) {
    m_btag_Flt30   = new  btagOpPoint("Flt30",m_mc,"FlatBEff_30");
    m_btag_Flt50   = new  btagOpPoint("Flt50",m_mc,"FlatBEff_50");
    m_btag_Flt60   = new  btagOpPoint("Flt60",m_mc,"FlatBEff_60");
    m_btag_Flt70   = new  btagOpPoint("Flt70",m_mc,"FlatBEff_70");
    m_btag_Flt77   = new  btagOpPoint("Flt77",m_mc,"FlatBEff_77");
    m_btag_Flt85   = new  btagOpPoint("Flt85",m_mc,"FlatBEff_85");
    m_btag_Flt90   = new  btagOpPoint("Flt90",m_mc,"FlatBEff_90");
  }

  // area
  if( m_infoSwitch.m_area ) {
    m_GhostArea          = new std::vector<float>();
    m_ActiveArea         = new std::vector<float>();
    m_VoronoiArea        = new std::vector<float>();
    m_ActiveArea4vec_pt  = new std::vector<float>();
    m_ActiveArea4vec_eta = new std::vector<float>();
    m_ActiveArea4vec_phi = new std::vector<float>();
    m_ActiveArea4vec_m   = new std::vector<float>();
  }


  // truth
  if ( m_infoSwitch.m_truth && m_mc ) {
    m_ConeTruthLabelID  =new std::vector<int>();
    m_TruthCount        =new std::vector<int>();
    m_TruthLabelDeltaR_B=new std::vector<float>;
    m_TruthLabelDeltaR_C=new std::vector<float>;
    m_TruthLabelDeltaR_T=new std::vector<float>;
    m_PartonTruthLabelID=new std::vector<int>();
    m_GhostTruthAssociationFraction=new std::vector<float>;
    m_truth_E  =new std::vector<float>;
    m_truth_pt =new std::vector<float>;
    m_truth_phi=new std::vector<float>;
    m_truth_eta=new std::vector<float>;
  }

  // truth detail
  if ( m_infoSwitch.m_truthDetails ) {
    m_GhostBHadronsFinalCount       = new       std::vector<int>   ();
    m_GhostBHadronsInitialCount     = new       std::vector<int>   ();
    m_GhostBQuarksFinalCount        = new       std::vector<int>   ();
    m_GhostBHadronsFinalPt          = new       std::vector<float> ();
    m_GhostBHadronsInitialPt        = new       std::vector<float> ();
    m_GhostBQuarksFinalPt           = new       std::vector<float> ();

    m_GhostCHadronsFinalCount       = new       std::vector<int>   ();
    m_GhostCHadronsInitialCount     = new       std::vector<int>   ();
    m_GhostCQuarksFinalCount        = new       std::vector<int>   ();
    m_GhostCHadronsFinalPt          = new       std::vector<float> ();
    m_GhostCHadronsInitialPt        = new       std::vector<float> ();
    m_GhostCQuarksFinalPt           = new       std::vector<float> ();
    
    m_GhostTausFinalCount           = new       std::vector<int>   ();
    m_GhostTausFinalPt              = new       std::vector<float> ();
    
    m_truth_pdgId                   = new       std::vector<int>   ();
    m_truth_partonPt                = new       std::vector<float> ();
    m_truth_partonDR                = new      std::vector<float>  ();
  }

  // charge
  if ( m_infoSwitch.m_charge ) {
    m_charge   =new std::vector<double>();
  }

}

JetContainer::~JetContainer()
{
  if(m_infoSwitch.m_rapidity) {
    delete m_rapidity;
  }

  // clean
  if(m_infoSwitch.m_clean) {
    delete m_Timing;
    delete m_LArQuality;
    delete m_HECQuality;
    delete m_NegativeE;
    delete m_AverageLArQF;
    delete m_BchCorrCell;
    delete m_N90Constituents;
    delete m_LArBadHVEnergyFrac;
    delete m_LArBadHVNCell;
    delete m_OotFracClusters5;
    delete m_OotFracClusters10;
    delete m_LeadingClusterPt;
    delete m_LeadingClusterSecondLambda;
    delete m_LeadingClusterCenterLambda;
    delete m_LeadingClusterSecondR;
    delete m_clean_passLooseBad;
    delete m_clean_passLooseBadUgly;
    delete m_clean_passTightBad;
    delete m_clean_passTightBadUgly;
  }

  // energy
  if ( m_infoSwitch.m_energy ) {
    delete m_HECFrac;
    delete m_EMFrac;
    delete m_CentroidR;
    delete m_FracSamplingMax;
    delete m_FracSamplingMaxIndex;
    delete m_LowEtConstituentsFrac;
    delete m_GhostMuonSegmentCount;
    delete m_Width;
  }

  // scales
  if ( m_infoSwitch.m_scales ) {
    delete m_emScalePt             ;
    delete m_constScalePt	   ;
    delete m_pileupScalePt		   ;
    delete m_originConstitScalePt  ;
    delete m_etaJESScalePt	   ;
    delete m_gscScalePt		   ;
    delete m_insituScalePt	   ;
  }

  // constscale eta 
  if ( m_infoSwitch.m_constscaleEta ) {
    delete m_constScaleEta         ;
  }


  // layer
  if ( m_infoSwitch.m_layer ) {
    delete m_EnergyPerSampling;
  }

  // tracksAll
  if ( m_infoSwitch.m_trackAll ) {
    delete m_NumTrkPt1000     ;
    delete m_SumPtTrkPt1000   ;
    delete m_TrackWidthPt1000 ;
    delete m_NumTrkPt500      ;
    delete m_SumPtTrkPt500    ;
    delete m_TrackWidthPt500  ;
    delete m_JVF              ;
  }


  // trackPV
  if ( m_infoSwitch.m_trackPV ) {
    delete m_NumTrkPt1000PV;
    delete m_SumPtTrkPt1000PV;
    delete m_TrackWidthPt1000PV;
    delete m_NumTrkPt500PV;
    delete m_SumPtTrkPt500PV;
    delete m_TrackWidthPt500PV;
    delete m_JVFPV;
    delete m_Jvt;
    delete m_JvtJvfcorr;
    delete m_JvtRpt;
    if(m_mc){
      delete m_JvtEff_SF_Loose  ;
      delete m_JvtEff_SF_Medium ;
      delete m_JvtEff_SF_Tight  ;
    }
  }

  // allTrack
  // trackAll or trackPV
  if ( m_infoSwitch.m_allTrack ) {
    delete m_GhostTrackCount    ;
    delete m_GhostTrackPt       ;
    delete m_GhostTrack_pt      ;
    delete m_GhostTrack_qOverP  ;
    delete m_GhostTrack_eta     ;
    delete m_GhostTrack_phi     ;
    delete m_GhostTrack_e       ;
    delete m_GhostTrack_d0      ;
    delete m_GhostTrack_z0      ;


    // allTrackDetail
    if(m_infoSwitch.m_allTrackDetail){
      delete m_GhostTrack_nPixelHits                               ;   
      delete m_GhostTrack_nSCTHits                                 ; 
      delete m_GhostTrack_nTRTHits                                 ; 
      delete m_GhostTrack_nPixelSharedHits                         ; 
      delete m_GhostTrack_nPixelSplitHits                          ; 
      delete m_GhostTrack_nInnermostPixelLayerHits                 ; 
      delete m_GhostTrack_nInnermostPixelLayerSharedHits           ; 
      delete m_GhostTrack_nInnermostPixelLayerSplitHits            ; 
      delete m_GhostTrack_nNextToInnermostPixelLayerHits           ; 
      delete m_GhostTrack_nNextToInnermostPixelLayerSharedHits     ; 
      delete m_GhostTrack_nNextToInnermostPixelLayerSplitHits      ; 
    }
  }

  // constituent
  if ( m_infoSwitch.m_constituent ) {
    delete m_numConstituents;
  }

  if ( m_infoSwitch.m_constituentAll ) {
    delete m_constituentWeights;
    delete m_constituent_pt    ;
    delete m_constituent_eta   ;
    delete m_constituent_phi   ;
    delete m_constituent_e     ;
  }


  // flavTag
  if( m_infoSwitch.m_flavTag  || m_infoSwitch.m_flavTagHLT  ) {
    // flavTag

    //delete m_MV1;
    delete m_MV2;
    delete m_MV2c00;
    delete m_MV2c10;
    delete m_MV2c20;
    delete m_MV2c100;

    delete m_HadronConeExclTruthLabelID;

    // Jet Fitter 
    if( m_infoSwitch.m_jetFitterDetails){
      delete m_JetFitter_nVTX          ;
      delete m_JetFitter_nSingleTracks ;
      delete m_JetFitter_nTracksAtVtx  ;
      delete m_JetFitter_mass          ;
      delete m_JetFitter_energyFraction;
      delete m_JetFitter_significance3d;
      delete m_JetFitter_deltaeta      ;
      delete m_JetFitter_deltaphi      ;
      delete m_JetFitter_N2Tpar        ;
    }
    // SV Details
    if( m_infoSwitch.m_svDetails){

      delete m_SV0;
      delete m_sv0_NGTinSvx  ; 
      delete m_sv0_N2Tpair   ; 
      delete m_sv0_massvx    ; 
      delete m_sv0_efracsvx  ; 
      delete m_sv0_normdist  ; 

      delete m_SV1;
      delete m_SV1IP3D;
      delete m_sv1_pu        ; 
      delete m_sv1_pb        ; 
      delete m_sv1_pc        ; 
      delete m_sv1_c         ; 
      delete m_sv1_cu        ; 
      delete m_sv1_NGTinSvx  ; 
      delete m_sv1_N2Tpair   ; 
      delete m_sv1_massvx    ; 
      delete m_sv1_efracsvx  ; 
      delete m_sv1_normdist  ; 
      delete m_sv1_Lxy       ; 
      delete m_sv1_L3d       ; 
      delete m_sv1_distmatlay; 
      delete m_sv1_dR        ; 
    }

    // IP3D
    if( m_infoSwitch.m_ipDetails){    

      delete m_IP2D_pu     ; 
      delete m_IP2D_pb     ; 
      delete m_IP2D_pc     ; 
      delete m_IP2D        ; 
      delete m_IP2D_c      ; 
      delete m_IP2D_cu     ; 
      delete m_nIP2DTracks ; 

      delete m_IP2D_gradeOfTracks     ; 
      delete m_IP2D_flagFromV0ofTracks; 
      delete m_IP2D_valD0wrtPVofTracks; 
      delete m_IP2D_sigD0wrtPVofTracks; 
      delete m_IP2D_weightBofTracks   ; 
      delete m_IP2D_weightCofTracks   ; 
      delete m_IP2D_weightUofTracks   ; 

      delete m_IP3D;
      delete m_IP3D_pu     ; 
      delete m_IP3D_pb     ; 
      delete m_IP3D_pc     ; 
      delete m_IP3D_c      ; 
      delete m_IP3D_cu     ; 

      delete m_nIP3DTracks ; 
      delete m_IP3D_gradeOfTracks       ;
      delete m_IP3D_flagFromV0ofTracks  ;
      delete m_IP3D_valD0wrtPVofTracks  ;
      delete m_IP3D_sigD0wrtPVofTracks  ;
      delete m_IP3D_valZ0wrtPVofTracks  ;
      delete m_IP3D_sigZ0wrtPVofTracks  ;
      delete m_IP3D_weightBofTracks     ;
      delete m_IP3D_weightCofTracks     ;
      delete m_IP3D_weightUofTracks     ;

    }

    if( m_infoSwitch.m_JVC ) {
      delete m_JetVertexCharge_discriminant          ;
    }

  }

    //  flavTagHLT
  if( m_infoSwitch.m_flavTagHLT  ) {
    delete m_vtxOnlineValid     ; 
    delete m_vtxHadDummy        ; 
    delete m_bs_online_vx       ; 
    delete m_bs_online_vy       ; 
    delete m_bs_online_vz       ; 

    delete m_vtx_offline_x0     ; 
    delete m_vtx_offline_y0     ; 
    delete m_vtx_offline_z0     ; 

    delete m_vtx_online_x0      ; 
    delete m_vtx_online_y0      ; 
    delete m_vtx_online_z0      ; 

    delete m_vtx_online_bkg_x0  ; 
    delete m_vtx_online_bkg_y0  ; 
    delete m_vtx_online_bkg_z0  ; 
  }

  if( !m_infoSwitch.m_sfFTagFix.empty() ) {
    delete m_btag_Fix30;
    delete m_btag_Fix50;
    delete m_btag_Fix60;
    delete m_btag_Fix70;
    delete m_btag_Fix77;
    delete m_btag_Fix80;
    delete m_btag_Fix85;
    delete m_btag_Fix90;
  }


  if( !m_infoSwitch.m_sfFTagFlt.empty() ) {
    delete m_btag_Flt30;
    delete m_btag_Flt50;
    delete m_btag_Flt60;
    delete m_btag_Flt70;
    delete m_btag_Flt77;
    delete m_btag_Flt85;
    delete m_btag_Flt90;
  }

  // area
  if( m_infoSwitch.m_area ) {
    delete m_GhostArea          ;
    delete m_ActiveArea         ;
    delete m_VoronoiArea        ;
    delete m_ActiveArea4vec_pt  ;
    delete m_ActiveArea4vec_eta ;
    delete m_ActiveArea4vec_phi ;
    delete m_ActiveArea4vec_m   ;
  }


  // truth
  if ( m_infoSwitch.m_truth && m_mc ) {
    delete m_ConeTruthLabelID;
    delete m_TruthCount;
    delete m_TruthLabelDeltaR_B;
    delete m_TruthLabelDeltaR_C;
    delete m_TruthLabelDeltaR_T;
    delete m_PartonTruthLabelID;
    delete m_GhostTruthAssociationFraction;
    delete m_truth_E;
    delete m_truth_pt;
    delete m_truth_phi;
    delete m_truth_eta;
  }
  
    // truth detail
  if ( m_infoSwitch.m_truthDetails ) {
    delete m_GhostBHadronsFinalCount   ;
    delete m_GhostBHadronsInitialCount ;
    delete m_GhostBQuarksFinalCount    ;
    delete m_GhostBHadronsFinalPt      ;
    delete m_GhostBHadronsInitialPt    ;
    delete m_GhostBQuarksFinalPt       ;

    delete m_GhostCHadronsFinalCount   ;
    delete m_GhostCHadronsInitialCount ;
    delete m_GhostCQuarksFinalCount    ;
    delete m_GhostCHadronsFinalPt      ;
    delete m_GhostCHadronsInitialPt    ;
    delete m_GhostCQuarksFinalPt       ;

    delete m_GhostTausFinalCount       ;
    delete m_GhostTausFinalPt          ;

    delete m_truth_pdgId               ;
    delete m_truth_partonPt            ;
    delete m_truth_partonDR            ;
  }


  // charge
  if ( m_infoSwitch.m_charge ) {
    delete m_charge;
  }

}

void JetContainer::setTree(TTree *tree)
{
  JetContainer::setTree(tree, "");
}

void JetContainer::setTree(TTree *tree, const std::string& tagger)
{
  //
  // Connect branches
  ParticleContainer::setTree(tree);

  if(m_infoSwitch.m_rapidity)
    {
      connectBranch<float>(tree,"rapidity",                      &m_rapidity);
    }

  if(m_infoSwitch.m_clean)
    {
      connectBranch<float>(tree,"Timing",                      &m_Timing);
      connectBranch<float>(tree,"LArQuality",                  &m_LArQuality);


      connectBranch<int>  (tree, "LArBadHVNCell",              &m_LArBadHVNCell);

      connectBranch<float>(tree, "LArQuality",                 &m_LArQuality);
      connectBranch<float>(tree, "HECQuality",                 &m_HECQuality);
      connectBranch<float>(tree, "NegativeE",                  &m_NegativeE);
      connectBranch<float>(tree, "AverageLArQF",               &m_AverageLArQF);
      connectBranch<float>(tree, "BchCorrCell",                &m_BchCorrCell);
      connectBranch<float>(tree, "N90Constituents",            &m_N90Constituents);
      connectBranch<float>(tree, "LArBadHVEnergyFrac",         &m_LArBadHVEnergyFrac);
      connectBranch<float>(tree, "OotFracClusters5",           &m_OotFracClusters5);
      connectBranch<float>(tree, "OotFracClusters10",          &m_OotFracClusters10);
      connectBranch<float>(tree, "LeadingClusterPt",           &m_LeadingClusterPt);
      connectBranch<float>(tree, "LeadingClusterSecondLambda", &m_LeadingClusterSecondLambda);
      connectBranch<float>(tree, "LeadingClusterCenterLambda", &m_LeadingClusterCenterLambda);
      connectBranch<float>(tree, "LeadingClusterSecondR",      &m_LeadingClusterSecondR);
      connectBranch<int>  (tree, "clean_passLooseBad",         &m_clean_passLooseBad);
      connectBranch<int>  (tree, "clean_passLooseBadUgly",     &m_clean_passLooseBadUgly);
      connectBranch<int>  (tree, "clean_passTightBad",         &m_clean_passTightBad);
      connectBranch<int>  (tree, "clean_passTightBadUgly",     &m_clean_passTightBadUgly);
    }

  if(m_infoSwitch.m_energy)
    {
      connectBranch<float>(tree, "HECFrac",               &m_HECFrac);
      connectBranch<float>(tree, "EMFrac",                &m_EMFrac);
      connectBranch<float>(tree, "CentroidR",             &m_CentroidR);
      connectBranch<float>(tree, "FracSamplingMax",       &m_FracSamplingMax);
      connectBranch<float>(tree, "FracSamplingMaxIndex",  &m_FracSamplingMaxIndex);
      connectBranch<float>(tree, "LowEtConstituentsFrac", &m_LowEtConstituentsFrac);
      connectBranch<float>(tree, "GhostMuonSegmentCount", &m_GhostMuonSegmentCount);
      connectBranch<float>(tree, "Width",                 &m_Width);
    }

  if(m_infoSwitch.m_trackPV)
    {
      connectBranch<float>(tree, "NumTrkPt1000PV",     &m_NumTrkPt1000PV);
      connectBranch<float>(tree, "SumPtTrkPt1000PV",   &m_SumPtTrkPt1000PV);
      connectBranch<float>(tree, "TrackWidthPt1000PV", &m_TrackWidthPt1000PV);
      connectBranch<float>(tree, "NumTrkPt500PV",      &m_NumTrkPt500PV);
      connectBranch<float>(tree, "SumPtTrkPt500PV",    &m_SumPtTrkPt500PV);
      connectBranch<float>(tree, "TrackWidthPt500PV",  &m_TrackWidthPt500PV);
      connectBranch<float>(tree, "JVFPV",              &m_JVFPV);
    }

  if(m_infoSwitch.m_trackAll || m_infoSwitch.m_trackPV)
    {
      connectBranch<float>(tree, "Jvt",        &m_Jvt);
      connectBranch<float>(tree, "JvtJvfcorr", &m_JvtJvfcorr);
      connectBranch<float>(tree, "JvtRpt",     &m_JvtRpt);
    }

  if(m_infoSwitch.m_JVC)
    {
      connectBranch<double>(tree,"JetVertexCharge_discriminant", &m_JetVertexCharge_discriminant);
    }

  if(m_infoSwitch.m_flavTag || m_infoSwitch.m_flavTagHLT)
    {
      connectBranch<float>(tree,"MV2c00",               &m_MV2c00);
      connectBranch<float>(tree,"MV2c10",               &m_MV2c10);
      connectBranch<float>(tree,"MV2c20",               &m_MV2c20);
      connectBranch<float>(tree,"MV2c100",              &m_MV2c100);
      connectBranch<int>  (tree,"HadronConeExclTruthLabelID",&m_HadronConeExclTruthLabelID);

      if(tagger == "MV2c20")  m_MV2 = m_MV2c20;
      if(tagger == "MV2c10")  m_MV2 = m_MV2c10;

    }

  if(m_infoSwitch.m_flavTagHLT)
    {
      connectBranch<float>(tree,"vtxHadDummy",    &m_vtxHadDummy);
      connectBranch<float>(tree,"bs_online_vx",   &m_bs_online_vx);
      connectBranch<float>(tree,"bs_online_vy",   &m_bs_online_vy);
      connectBranch<float>(tree,"bs_online_vz",   &m_bs_online_vz);
     
      connectBranch<float>(tree,"vtx_offline_x0", &m_vtx_offline_x0);
      connectBranch<float>(tree,"vtx_offline_y0", &m_vtx_offline_y0);
      connectBranch<float>(tree,"vtx_offline_z0", &m_vtx_offline_z0);

      connectBranch<float>(tree,"vtx_online_x0",  &m_vtx_online_x0);
      connectBranch<float>(tree,"vtx_online_y0",  &m_vtx_online_y0);
      connectBranch<float>(tree,"vtx_online_z0",  &m_vtx_online_z0);
    }

  if(m_infoSwitch.m_jetFitterDetails)
    {
      connectBranch<float>(tree,"JetFitter_nVTX"          ,  &m_JetFitter_nVTX           );
      connectBranch<float>(tree,"JetFitter_nSingleTracks" ,  &m_JetFitter_nSingleTracks  );
      connectBranch<float>(tree,"JetFitter_nTracksAtVtx"  ,  &m_JetFitter_nTracksAtVtx   );
      connectBranch<float>(tree,"JetFitter_mass"          ,  &m_JetFitter_mass           );
      connectBranch<float>(tree,"JetFitter_energyFraction",  &m_JetFitter_energyFraction );
      connectBranch<float>(tree,"JetFitter_significance3d",  &m_JetFitter_significance3d );
      connectBranch<float>(tree,"JetFitter_deltaeta"      ,  &m_JetFitter_deltaeta       );
      connectBranch<float>(tree,"JetFitter_deltaphi"      ,  &m_JetFitter_deltaphi       );
      connectBranch<float>(tree,"JetFitter_N2Tpair"       ,  &m_JetFitter_N2Tpar         );

    }

    if( m_infoSwitch.m_svDetails){

      connectBranch<float>(tree, "SV0",               &m_SV0);
      connectBranch<float>(tree, "sv0_NGTinSvx",      &m_sv0_NGTinSvx  );
      connectBranch<float>(tree, "sv0_N2Tpair",       &m_sv0_N2Tpair   );
      connectBranch<float>(tree, "sv0_massvx",        &m_sv0_massvx    );
      connectBranch<float>(tree, "sv0_efracsvx",      &m_sv0_efracsvx  );
      connectBranch<float>(tree, "sv0_normdist",      &m_sv0_normdist  );

      connectBranch<float>(tree, "SV1",               &m_SV1);
      connectBranch<float>(tree, "SV1IP3D",           &m_SV1IP3D);
      connectBranch<float>(tree, "sv1_pu",            &m_sv1_pu        );
      connectBranch<float>(tree, "sv1_pb",            &m_sv1_pb        );
      connectBranch<float>(tree, "sv1_pc",            &m_sv1_pc        );
      connectBranch<float>(tree, "sv1_c",             &m_sv1_c         );
      connectBranch<float>(tree, "sv1_cu",            &m_sv1_cu        );
      connectBranch<float>(tree, "sv1_NGTinSvx",      &m_sv1_NGTinSvx  );
      connectBranch<float>(tree, "sv1_N2Tpair",       &m_sv1_N2Tpair   );
      connectBranch<float>(tree, "sv1_massvx",        &m_sv1_massvx    );
      connectBranch<float>(tree, "sv1_efracsvx",      &m_sv1_efracsvx  );
      connectBranch<float>(tree, "sv1_normdist",      &m_sv1_normdist  );
      connectBranch<float>(tree, "sv1_Lxy",           &m_sv1_Lxy       );
      connectBranch<float>(tree, "sv1_L3d",           &m_sv1_L3d       );
      connectBranch<float>(tree, "sv1_distmatlay",    &m_sv1_distmatlay);
      connectBranch<float>(tree, "sv1_dR",            &m_sv1_dR        );

    }

    if( m_infoSwitch.m_ipDetails){    

      connectBranch<float>              (tree,  "IP2D_pu",                   &m_IP2D_pu                   );
      connectBranch<float>              (tree,  "IP2D_pb",                   &m_IP2D_pb                   );
      connectBranch<float>              (tree,  "IP2D_pc",                   &m_IP2D_pc                   );
      connectBranch<float>              (tree,  "IP2D",                      &m_IP2D                      );
      connectBranch<float>              (tree,  "IP2D_c",                    &m_IP2D_c                    );
      connectBranch<float>              (tree,  "IP2D_cu",                   &m_IP2D_cu                   );
      connectBranch<std::vector<float> >(tree,  "IP2D_gradeOfTracks"       , &m_IP2D_gradeOfTracks        );
      connectBranch<std::vector<float> >(tree,  "IP2D_flagFromV0ofTracks"  , &m_IP2D_flagFromV0ofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP2D_valD0wrtPVofTracks"  , &m_IP2D_valD0wrtPVofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP2D_sigD0wrtPVofTracks"  , &m_IP2D_sigD0wrtPVofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP2D_weightBofTracks"     , &m_IP2D_weightBofTracks      );
      connectBranch<std::vector<float> >(tree,  "IP2D_weightCofTracks"     , &m_IP2D_weightCofTracks      );
      connectBranch<std::vector<float> >(tree,  "IP2D_weightUofTracks"     , &m_IP2D_weightUofTracks      );

      connectBranch<float>              (tree,  "IP3D",                      &m_IP3D);
      connectBranch<float>              (tree,  "IP3D_pu",                   &m_IP3D_pu                   );
      connectBranch<float>              (tree,  "IP3D_pb",                   &m_IP3D_pb                   );
      connectBranch<float>              (tree,  "IP3D_pc",                   &m_IP3D_pc                   );
      connectBranch<float>              (tree,  "IP3D_c",                    &m_IP3D_c                    );
      connectBranch<float>              (tree,  "IP3D_cu",                   &m_IP3D_cu                   );
      connectBranch<std::vector<float> >(tree,  "IP3D_gradeOfTracks"       , &m_IP3D_gradeOfTracks        );
      connectBranch<std::vector<float> >(tree,  "IP3D_flagFromV0ofTracks"  , &m_IP3D_flagFromV0ofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP3D_valD0wrtPVofTracks"  , &m_IP3D_valD0wrtPVofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP3D_sigD0wrtPVofTracks"  , &m_IP3D_sigD0wrtPVofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP3D_valZ0wrtPVofTracks"  , &m_IP3D_valZ0wrtPVofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP3D_sigZ0wrtPVofTracks"  , &m_IP3D_sigZ0wrtPVofTracks   );
      connectBranch<std::vector<float> >(tree,  "IP3D_weightBofTracks"     , &m_IP3D_weightBofTracks      );
      connectBranch<std::vector<float> >(tree,  "IP3D_weightCofTracks"     , &m_IP3D_weightCofTracks      );
      connectBranch<std::vector<float> >(tree,  "IP3D_weightUofTracks"     , &m_IP3D_weightUofTracks      );

    }


  for(uint i=0; i<m_infoSwitch.m_sfFTagFix.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFix[i] ) 
        {
        case 30: m_btag_Fix30->setTree(tree, m_name); break;
        case 50: m_btag_Fix50->setTree(tree, m_name); break;
        case 60: m_btag_Fix60->setTree(tree, m_name); break;
        case 70: m_btag_Fix70->setTree(tree, m_name); break;
        case 77: m_btag_Fix77->setTree(tree, m_name); break;
        case 80: m_btag_Fix80->setTree(tree, m_name); break;
        case 85: m_btag_Fix85->setTree(tree, m_name); break;         
        case 90: m_btag_Fix90->setTree(tree, m_name); break;
      }
    }

  for(uint i=0; i<m_infoSwitch.m_sfFTagFlt.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFlt[i] ) 
        {
        case 30: m_btag_Flt30->setTree(tree, m_name); break;
        case 50: m_btag_Flt50->setTree(tree, m_name); break;
        case 60: m_btag_Flt60->setTree(tree, m_name); break;              
        case 70: m_btag_Flt70->setTree(tree, m_name); break;
        case 77: m_btag_Flt77->setTree(tree, m_name); break;
        case 85: m_btag_Flt85->setTree(tree, m_name); break;
        }
    }


  // truth
  if(m_infoSwitch.m_truth)
    {
      connectBranch<int>  (tree,"ConeTruthLabelID",   &m_ConeTruthLabelID);
      connectBranch<int>  (tree,"TruthCount",         &m_TruthCount);
      connectBranch<float>(tree,"TruthLabelDeltaR_B", &m_TruthLabelDeltaR_B);
      connectBranch<float>(tree,"TruthLabelDeltaR_C", &m_TruthLabelDeltaR_C);
      connectBranch<float>(tree,"TruthLabelDeltaR_T", &m_TruthLabelDeltaR_T);
      connectBranch<int>  (tree,"PartonTruthLabelID", &m_PartonTruthLabelID);
      connectBranch<float>(tree,"GhostTruthAssociationFraction", &m_GhostTruthAssociationFraction);
      connectBranch<float>(tree,"truth_E",   &m_truth_E);
      connectBranch<float>(tree,"truth_pt",  &m_truth_pt);
      connectBranch<float>(tree,"truth_phi", &m_truth_phi);
      connectBranch<float>(tree,"truth_eta", &m_truth_eta);
    }

  // charge
  if(m_infoSwitch.m_charge)
    {
      connectBranch<double>(tree,"charge", &m_charge);
    }
}

void JetContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);  

  if(m_infoSwitch.m_rapidity)
    {
      m_particles[idx].rapidity                    =m_rapidity                    ->at(idx);
    }

  if(m_infoSwitch.m_clean)
    {
      m_particles[idx].Timing                    =m_Timing                    ->at(idx);
      m_particles[idx].LArQuality                =m_LArQuality                ->at(idx);
      m_particles[idx].HECQuality                =m_HECQuality                ->at(idx);
      m_particles[idx].NegativeE                 =m_NegativeE                 ->at(idx);
      m_particles[idx].AverageLArQF              =m_AverageLArQF              ->at(idx);
      m_particles[idx].BchCorrCell               =m_BchCorrCell               ->at(idx);
      m_particles[idx].N90Constituents           =m_N90Constituents           ->at(idx);
      m_particles[idx].LArBadHVEFrac             =m_LArBadHVEnergyFrac       ->at(idx);
      m_particles[idx].LArBadHVNCell             =m_LArBadHVNCell             ->at(idx);
      m_particles[idx].OotFracClusters5          =m_OotFracClusters5          ->at(idx);
      m_particles[idx].OotFracClusters10         =m_OotFracClusters10         ->at(idx);
      m_particles[idx].LeadingClusterPt          =m_LeadingClusterPt          ->at(idx);
      m_particles[idx].LeadingClusterSecondLambda=m_LeadingClusterSecondLambda->at(idx);
      m_particles[idx].LeadingClusterCenterLambda=m_LeadingClusterCenterLambda->at(idx);
      m_particles[idx].LeadingClusterSecondR     =m_LeadingClusterSecondR     ->at(idx);
      m_particles[idx].clean_passLooseBad        =m_clean_passLooseBad        ->at(idx);
      m_particles[idx].clean_passLooseBadUgly    =m_clean_passLooseBadUgly    ->at(idx);
      m_particles[idx].clean_passTightBad        =m_clean_passTightBad        ->at(idx);
      m_particles[idx].clean_passTightBadUgly    =m_clean_passTightBadUgly    ->at(idx);
    }

  if(m_infoSwitch.m_energy)
    {
      m_particles[idx].HECFrac              =m_HECFrac              ->at(idx);
      m_particles[idx].EMFrac               =m_EMFrac               ->at(idx);
      m_particles[idx].CentroidR            =m_CentroidR            ->at(idx);
      m_particles[idx].FracSamplingMax      =m_FracSamplingMax      ->at(idx);
      m_particles[idx].FracSamplingMaxIndex =m_FracSamplingMaxIndex ->at(idx);
      m_particles[idx].LowEtConstituentsFrac=m_LowEtConstituentsFrac->at(idx);
      m_particles[idx].GhostMuonSegmentCount=m_GhostMuonSegmentCount->at(idx);
      m_particles[idx].Width                =m_Width                ->at(idx);
    }
  
  if(m_infoSwitch.m_trackPV)
    {
      m_particles[idx].NumTrkPt1000PV    =m_NumTrkPt1000PV    ->at(idx);
      m_particles[idx].SumPtTrkPt1000PV  =m_SumPtTrkPt1000PV  ->at(idx);
      m_particles[idx].TrackWidthPt1000PV=m_TrackWidthPt1000PV->at(idx);
      m_particles[idx].NumTrkPt500PV     =m_NumTrkPt500PV     ->at(idx);
      m_particles[idx].SumPtTrkPt500PV   =m_SumPtTrkPt500PV   ->at(idx);
      m_particles[idx].TrackWidthPt500PV =m_TrackWidthPt500PV ->at(idx);
      m_particles[idx].JVFPV             =m_JVFPV             ->at(idx);
    }

  if(m_infoSwitch.m_trackPV || m_infoSwitch.m_trackAll)
    {
      m_particles[idx].Jvt       =m_Jvt       ->at(idx);
      m_particles[idx].JvtJvfcorr=m_JvtJvfcorr->at(idx);
      m_particles[idx].JvtRpt    =m_JvtRpt    ->at(idx);
    }
  
  if( m_infoSwitch.m_JVC ) {
    m_particles[idx].JVC = m_JetVertexCharge_discriminant->at(idx);
  }

  if(m_infoSwitch.m_flavTag  || m_infoSwitch.m_flavTagHLT)
    {
      m_particles[idx].MV2c00                    =m_MV2c00               ->at(idx);
      m_particles[idx].MV2c10                    =m_MV2c10               ->at(idx);
      m_particles[idx].MV2c20                    =m_MV2c20               ->at(idx);
      m_particles[idx].MV2c100                   =m_MV2c100              ->at(idx);
      m_particles[idx].MV2                       =m_MV2                  ->at(idx);

      m_particles[idx].HadronConeExclTruthLabelID=m_HadronConeExclTruthLabelID->at(idx);
    }


  if(m_infoSwitch.m_flavTagHLT)
    {
      m_particles[idx].bs_online_vx                      =m_bs_online_vx                  ->at(idx);
      m_particles[idx].bs_online_vy                      =m_bs_online_vy                  ->at(idx);
      m_particles[idx].bs_online_vz                      =m_bs_online_vz                  ->at(idx);
      m_particles[idx].vtxHadDummy                       =m_vtxHadDummy                   ->at(idx);
      m_particles[idx].vtx_offline_x0                    =m_vtx_offline_x0                  ->at(idx);
      m_particles[idx].vtx_offline_y0                    =m_vtx_offline_y0                  ->at(idx);
      m_particles[idx].vtx_offline_z0                    =m_vtx_offline_z0                  ->at(idx);

      m_particles[idx].vtx_online_x0                     =m_vtx_online_x0                  ->at(idx);
      m_particles[idx].vtx_online_y0                     =m_vtx_online_y0                  ->at(idx);
      m_particles[idx].vtx_online_z0                     =m_vtx_online_z0                  ->at(idx);

    }

  if(m_infoSwitch.m_jetFitterDetails)
    {
      m_particles[idx].JetFitter_nVTX                  =m_JetFitter_nVTX           ->at(idx);
      m_particles[idx].JetFitter_nSingleTracks         =m_JetFitter_nSingleTracks  ->at(idx);
      m_particles[idx].JetFitter_nTracksAtVtx          =m_JetFitter_nTracksAtVtx   ->at(idx);
      m_particles[idx].JetFitter_mass                  =m_JetFitter_mass           ->at(idx);
      m_particles[idx].JetFitter_energyFraction        =m_JetFitter_energyFraction ->at(idx);
      m_particles[idx].JetFitter_significance3d        =m_JetFitter_significance3d ->at(idx);
      m_particles[idx].JetFitter_deltaeta              =m_JetFitter_deltaeta       ->at(idx);
      m_particles[idx].JetFitter_deltaphi              =m_JetFitter_deltaphi       ->at(idx);
      m_particles[idx].JetFitter_N2Tpar                =m_JetFitter_N2Tpar         ->at(idx);

    }

  if(m_infoSwitch.m_svDetails){

    m_particles[idx].SV0            = m_SV0           ->at(idx);
    m_particles[idx].sv0_NGTinSvx   = m_sv0_NGTinSvx  ->at(idx);
    m_particles[idx].sv0_N2Tpair    = m_sv0_N2Tpair   ->at(idx);
    m_particles[idx].sv0_massvx     = m_sv0_massvx    ->at(idx);
    m_particles[idx].sv0_efracsvx   = m_sv0_efracsvx  ->at(idx);
    m_particles[idx].sv0_normdist   = m_sv0_normdist  ->at(idx);

    m_particles[idx].SV1            = m_SV1           ->at(idx);
    m_particles[idx].SV1IP3D        = m_SV1IP3D       ->at(idx);
    m_particles[idx].sv1_pu         = m_sv1_pu        ->at(idx);
    m_particles[idx].sv1_pb         = m_sv1_pb        ->at(idx);
    m_particles[idx].sv1_pc         = m_sv1_pc        ->at(idx);
    m_particles[idx].sv1_c          = m_sv1_c         ->at(idx);
    m_particles[idx].sv1_cu         = m_sv1_cu        ->at(idx);
    m_particles[idx].sv1_NGTinSvx   = m_sv1_NGTinSvx  ->at(idx);
    m_particles[idx].sv1_N2Tpair    = m_sv1_N2Tpair   ->at(idx);
    m_particles[idx].sv1_massvx     = m_sv1_massvx    ->at(idx);
    m_particles[idx].sv1_efracsvx   = m_sv1_efracsvx  ->at(idx);
    m_particles[idx].sv1_normdist   = m_sv1_normdist  ->at(idx);
    m_particles[idx].sv1_Lxy        = m_sv1_Lxy       ->at(idx);
    m_particles[idx].sv1_L3d        = m_sv1_L3d       ->at(idx);
    m_particles[idx].sv1_distmatlay = m_sv1_distmatlay->at(idx);
    m_particles[idx].sv1_dR         = m_sv1_dR        ->at(idx);
  }

  if(m_infoSwitch.m_ipDetails){
    m_particles[idx].IP2D_pu                          = m_IP2D_pu                   ->at(idx);
    m_particles[idx].IP2D_pb                          = m_IP2D_pb                   ->at(idx);
    m_particles[idx].IP2D_pc                          = m_IP2D_pc                   ->at(idx);
    m_particles[idx].IP2D                             = m_IP2D                      ->at(idx);
    m_particles[idx].IP2D_c                           = m_IP2D_c                    ->at(idx);
    m_particles[idx].IP2D_cu                          = m_IP2D_cu                   ->at(idx);
    m_particles[idx].nIP2DTracks                      = m_IP2D_gradeOfTracks        ->at(idx).size();

    m_particles[idx].IP2D_gradeOfTracks               = m_IP2D_gradeOfTracks        ->at(idx);
    m_particles[idx].IP2D_flagFromV0ofTracks          = m_IP2D_flagFromV0ofTracks   ->at(idx);
    m_particles[idx].IP2D_valD0wrtPVofTracks          = m_IP2D_valD0wrtPVofTracks   ->at(idx);
    m_particles[idx].IP2D_sigD0wrtPVofTracks          = m_IP2D_sigD0wrtPVofTracks   ->at(idx);
    m_particles[idx].IP2D_weightBofTracks             = m_IP2D_weightBofTracks      ->at(idx);
    m_particles[idx].IP2D_weightCofTracks             = m_IP2D_weightCofTracks      ->at(idx);
    m_particles[idx].IP2D_weightUofTracks             = m_IP2D_weightUofTracks      ->at(idx);

    m_particles[idx].IP3D                             = m_IP3D                      ->at(idx);
    m_particles[idx].IP3D_pu                          = m_IP3D_pu                   ->at(idx);
    m_particles[idx].IP3D_pb                          = m_IP3D_pb                   ->at(idx);
    m_particles[idx].IP3D_pc                          = m_IP3D_pc                   ->at(idx);
    m_particles[idx].IP3D_c                           = m_IP3D_c                    ->at(idx);
    m_particles[idx].IP3D_cu                          = m_IP3D_cu                   ->at(idx);
    m_particles[idx].nIP3DTracks                      = m_IP3D_gradeOfTracks        ->at(idx).size();
    m_particles[idx].IP3D_gradeOfTracks               = m_IP3D_gradeOfTracks        ->at(idx);
    m_particles[idx].IP3D_flagFromV0ofTracks          = m_IP3D_flagFromV0ofTracks   ->at(idx);
    m_particles[idx].IP3D_valD0wrtPVofTracks          = m_IP3D_valD0wrtPVofTracks   ->at(idx);
    m_particles[idx].IP3D_sigD0wrtPVofTracks          = m_IP3D_sigD0wrtPVofTracks   ->at(idx);
    m_particles[idx].IP3D_valZ0wrtPVofTracks          = m_IP3D_valZ0wrtPVofTracks   ->at(idx);
    m_particles[idx].IP3D_sigZ0wrtPVofTracks          = m_IP3D_sigZ0wrtPVofTracks   ->at(idx);
    m_particles[idx].IP3D_weightBofTracks             = m_IP3D_weightBofTracks      ->at(idx);
    m_particles[idx].IP3D_weightCofTracks             = m_IP3D_weightCofTracks      ->at(idx);
    m_particles[idx].IP3D_weightUofTracks             = m_IP3D_weightUofTracks      ->at(idx);
  }

  static const std::vector<float> dummy1 = {1.};
  for(uint i=0; i<m_infoSwitch.m_sfFTagFix.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFix[i] ) 
        {
        case 30:
          m_particles[idx].MV2c20_isFix30       =m_btag_Fix30->m_isTag->at(idx);
          m_particles[idx].MV2c20_sfFix30       =(m_mc)?m_btag_Fix30->m_sf->at(idx):dummy1;
          break;
        case 50:
          m_particles[idx].MV2c20_isFix50       =m_btag_Fix50->m_isTag->at(idx);
          m_particles[idx].MV2c20_sfFix50       =(m_mc)?m_btag_Fix50->m_sf->at(idx):dummy1;
          break;
        case 60:
          m_particles[idx].MV2c20_isFix60       =m_btag_Fix60->m_isTag->at(idx);
          m_particles[idx].MV2c20_sfFix60       =(m_mc)?m_btag_Fix60->m_sf->at(idx):dummy1;
          break;
        case 70: 
          m_particles[idx].MV2c20_isFix70       =m_btag_Fix70->m_isTag->at(idx);
          m_particles[idx].MV2c20_sfFix70       =(m_mc)?m_btag_Fix70->m_sf->at(idx):dummy1;
          break;
        case 77:
          m_particles[idx].MV2c20_isFix77       =m_btag_Fix77->m_isTag->at(idx);
          m_particles[idx].MV2c20_sfFix77       =(m_mc)?m_btag_Fix77->m_sf->at(idx):dummy1;
          break;
        case 80:
          m_particles[idx].MV2c20_isFix80       =m_btag_Fix80->m_isTag->at(idx);
          m_particles[idx].MV2c20_sfFix80       =(m_mc)?m_btag_Fix80->m_sf->at(idx):dummy1;
          break;
        case 85:
          m_particles[idx].MV2c20_isFix85       =m_btag_Fix85->m_isTag ->at(idx);
          m_particles[idx].MV2c20_sfFix85       =(m_mc)?m_btag_Fix85->m_sf->at(idx):dummy1;
          break;
        case 90:
          m_particles[idx].MV2c20_isFix90       =m_btag_Fix90->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFix90       =(m_mc)?m_btag_Fix90->m_sf->at(idx):dummy1;
          break;
        }
    }

  for(uint i=0; i<m_infoSwitch.m_sfFTagFlt.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFlt[i] ) 
        {
        case 30:
          m_particles[idx].MV2c20_isFlt30       =m_btag_Flt30->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFlt30       =(m_mc)?m_btag_Flt30->m_sf->at(idx):dummy1;
          break;
        case 50:
          m_particles[idx].MV2c20_isFlt50       =m_btag_Flt50->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFlt50       =(m_mc)?m_btag_Flt50->m_sf->at(idx):dummy1;
          break;
        case 60:
          m_particles[idx].MV2c20_isFlt60       =m_btag_Flt60->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFlt60       =(m_mc)?m_btag_Flt60->m_sf->at(idx):dummy1;
          break;
        case 70:
          m_particles[idx].MV2c20_isFlt70       =m_btag_Flt70->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFlt70       =(m_mc)?m_btag_Flt70->m_sf->at(idx):dummy1;
          break;
        case 77:
          m_particles[idx].MV2c20_isFlt77       =m_btag_Flt77->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFlt77       =(m_mc)?m_btag_Flt77->m_sf->at(idx):dummy1;
          break;
        case 85:
          m_particles[idx].MV2c20_isFlt85       =m_btag_Flt85->m_isTag       ->at(idx);
          m_particles[idx].MV2c20_sfFlt85       =(m_mc)?m_btag_Flt85->m_sf->at(idx):dummy1;
          break;
        }
    }


  // truth
  if(m_infoSwitch.m_truth)
    {
      m_particles[idx].ConeTruthLabelID  =m_ConeTruthLabelID->at(idx);
      m_particles[idx].TruthCount        =m_TruthCount      ->at(idx);
      m_particles[idx].TruthLabelDeltaR_B=m_TruthLabelDeltaR_B->at(idx);
      m_particles[idx].TruthLabelDeltaR_C=m_TruthLabelDeltaR_C->at(idx);
      m_particles[idx].TruthLabelDeltaR_T=m_TruthLabelDeltaR_T->at(idx);
      m_particles[idx].PartonTruthLabelID=m_PartonTruthLabelID->at(idx);
      m_particles[idx].GhostTruthAssociationFraction= m_GhostTruthAssociationFraction->at(idx);

      m_particles[idx].truth_p4.SetPtEtaPhiE(m_truth_pt ->at(idx),
                                m_truth_eta->at(idx),
                                m_truth_phi->at(idx),
                                m_truth_E  ->at(idx));
    }

  // charge
  if(m_infoSwitch.m_charge)
    {
      m_particles[idx].charge=m_charge->at(idx);
    }

  return;
}



void JetContainer::setBranches(TTree *tree)
{
  ParticleContainer::setBranches(tree);

  if ( m_infoSwitch.m_rapidity ) {
    setBranch<float>(tree,"rapidity",                      m_rapidity              );
  }


  if( m_infoSwitch.m_clean ) {
    setBranch<float>(tree,"Timing",                        m_Timing               );
    setBranch<float>(tree,"LArQuality",                    m_LArQuality         );
    setBranch<float>(tree,"HECQuality",                    m_HECQuality               );
    setBranch<float>(tree,"NegativeE",                     m_NegativeE               );
    setBranch<float>(tree,"AverageLArQF",                  m_AverageLArQF            );
    setBranch<float>(tree,"BchCorrCell",                   m_BchCorrCell        );
    setBranch<float>(tree,"N90Constituents",               m_N90Constituents           );
    setBranch<float>(tree,"LArBadHVEnergyFrac",            m_LArBadHVEnergyFrac   );
    setBranch<int>  (tree,"LArBadHVNCell",                 m_LArBadHVNCell  	  );
    setBranch<float>(tree,"OotFracClusters5",              m_OotFracClusters5  	    );
    setBranch<float>(tree,"OotFracClusters10",             m_OotFracClusters10  	  );
    setBranch<float>(tree,"LeadingClusterPt",              m_LeadingClusterPt  	            );
    setBranch<float>(tree,"LeadingClusterSecondLambda",    m_LeadingClusterSecondLambda  	  );
    setBranch<float>(tree,"LeadingClusterCenterLambda",    m_LeadingClusterCenterLambda  	  );
    setBranch<float>(tree,"LeadingClusterSecondR",         m_LeadingClusterSecondR  	      );
    setBranch<int>  (tree,"clean_passLooseBad",            m_clean_passLooseBad             );
    setBranch<int>  (tree,"clean_passLooseBadUgly",        m_clean_passLooseBadUgly         );
    setBranch<int>  (tree,"clean_passTightBad",            m_clean_passTightBad             );
    setBranch<int>  (tree,"clean_passTightBadUgly",        m_clean_passTightBadUgly         );
  }


  if ( m_infoSwitch.m_energy ) {
    setBranch<float>(tree,"HECFrac",                   m_HECFrac            );
    setBranch<float>(tree,"EMFrac",                    m_EMFrac     );
    setBranch<float>(tree,"CentroidR",                 m_CentroidR      );
    setBranch<float>(tree,"FracSamplingMax",           m_FracSamplingMax    );
    setBranch<float>(tree,"FracSamplingMaxIndex",      m_FracSamplingMaxIndex );
    setBranch<float>(tree,"LowEtConstituentsFrac",     m_LowEtConstituentsFrac      );
    setBranch<float>(tree,"GhostMuonSegmentCount",     m_GhostMuonSegmentCount   );
    setBranch<float>(tree,"Width",                     m_Width          );
  }

  if ( m_infoSwitch.m_scales ) {
    setBranch<float>(tree,"emScalePt",              m_emScalePt            );
    setBranch<float>(tree,"constScalePt",           m_constScalePt         );
    setBranch<float>(tree,"pileupScalePt",          m_pileupScalePt        );
    setBranch<float>(tree,"originConstitScalePt",   m_originConstitScalePt );
    setBranch<float>(tree,"etaJESScalePt",          m_etaJESScalePt        );
    setBranch<float>(tree,"gscScalePt",             m_gscScalePt           );
    setBranch<float>(tree,"insituScalePt",          m_insituScalePt        );
  }

  if ( m_infoSwitch.m_constscaleEta ) {
    setBranch<float>(tree,"constScaleEta",              m_constScaleEta            );
  }

  if ( m_infoSwitch.m_layer ) {
    setBranch<std::vector<float> >(tree,"EnergyPerSampling",     m_EnergyPerSampling   );
  }

  if ( m_infoSwitch.m_trackAll ) {
    setBranch<std::vector<int  > >(tree,"NumTrkPt1000",      m_NumTrkPt1000   );
    setBranch<std::vector<float> >(tree,"SumPtTrkPt1000",    m_SumPtTrkPt1000  );
    setBranch<std::vector<float> >(tree,"TrackWidthPt1000",  m_TrackWidthPt1000   );
    setBranch<std::vector<int  > >(tree,"NumTrkPt500",       m_NumTrkPt500    );
    setBranch<std::vector<float> >(tree,"SumPtTrkPt500",     m_SumPtTrkPt500  );
    setBranch<std::vector<float> >(tree,"TrackWidthPt500",   m_TrackWidthPt500    );
    setBranch<std::vector<float> >(tree,"JVF",               m_JVF         );
  }

  if ( m_infoSwitch.m_trackPV ) {
    setBranch<float>(tree,"NumTrkPt1000PV",       m_NumTrkPt1000PV   );
    setBranch<float>(tree,"SumPtTrkPt1000PV",     m_SumPtTrkPt1000PV  );
    setBranch<float>(tree,"TrackWidthPt1000PV",   m_TrackWidthPt1000PV   );
    setBranch<float>(tree,"NumTrkPt500PV",        m_NumTrkPt500PV    );
    setBranch<float>(tree,"SumPtTrkPt500PV",      m_SumPtTrkPt500PV   );
    setBranch<float>(tree,"TrackWidthPt500PV",    m_TrackWidthPt500PV    );
    setBranch<float>(tree,"JVFPV",                m_JVFPV             );
    setBranch<float>(tree,"Jvt",                  m_Jvt                 );
    setBranch<float>(tree,"JvtJvfcorr",           m_JvtJvfcorr     );
    setBranch<float>(tree,"JvtRpt",               m_JvtRpt         );
    if ( m_mc ) {
      setBranch<std::vector<float> >(tree,"JvtEff_SF_Loose",     m_JvtEff_SF_Loose );
      setBranch<std::vector<float> >(tree,"JvtEff_SF_Medium",    m_JvtEff_SF_Medium );
      setBranch<std::vector<float> >(tree,"JvtEff_SF_Tight",     m_JvtEff_SF_Tight );
    }
    //setBranch<float>(tree,"GhostTrackAssociationFraction", m_ghostTrackAssFrac);
  }


  if ( m_infoSwitch.m_allTrack ) {
    // if want to apply the selection of the PV then need to setup track selection tool
    // this applies the JVF/JVT selection cuts
    // https://twiki.cern.ch/twiki/bin/view/AtlasProtected/JvtManualRecalculation

    setBranch<int  >(tree,"GhostTrackCount",  m_GhostTrackCount );
    setBranch<float>(tree,"GhostTrackPt",     m_GhostTrackPt    );
    setBranch<std::vector<float> >(tree,"GhostTrack_pt",    m_GhostTrack_pt   );
    setBranch<std::vector<float> >(tree,"GhostTrack_qOverP",m_GhostTrack_qOverP);
    setBranch<std::vector<float> >(tree,"GhostTrack_eta",   m_GhostTrack_eta  );
    setBranch<std::vector<float> >(tree,"GhostTrack_phi",   m_GhostTrack_phi  );
    setBranch<std::vector<float> >(tree,"GhostTrack_e",     m_GhostTrack_e    );
    setBranch<std::vector<float> >(tree,"GhostTrack_d0",    m_GhostTrack_d0   );
    setBranch<std::vector<float> >(tree,"GhostTrack_z0",    m_GhostTrack_z0   );
    if ( m_infoSwitch.m_allTrackDetail ) {
      setBranch<std::vector<int> >(tree,"GhostTrack_nPixelHits",                           m_GhostTrack_nPixelHits);
      setBranch<std::vector<int> >(tree,"GhostTrack_nSCTHits",                             m_GhostTrack_nSCTHits);
      setBranch<std::vector<int> >(tree,"GhostTrack_nTRTHits",                             m_GhostTrack_nTRTHits);
      setBranch<std::vector<int> >(tree,"GhostTrack_nPixelSharedHits",                     m_GhostTrack_nPixelSharedHits);
      setBranch<std::vector<int> >(tree,"GhostTrack_nPixelSplitHits",                      m_GhostTrack_nPixelSplitHits);
      setBranch<std::vector<int> >(tree,"m_GhostTrack_nInnermostPixelLayerHits",             m_GhostTrack_nInnermostPixelLayerHits);
      setBranch<std::vector<int> >(tree,"m_GhostTrack_nInnermostPixelLayerSharedHits",       m_GhostTrack_nInnermostPixelLayerSharedHits);
      setBranch<std::vector<int> >(tree,"m_GhostTrack_nInnermostPixelLayerSplitHits",        m_GhostTrack_nInnermostPixelLayerSplitHits);
      setBranch<std::vector<int> >(tree,"m_GhostTrack_nNextToInnermostPixelLayerHits",       m_GhostTrack_nNextToInnermostPixelLayerHits);
      setBranch<std::vector<int> >(tree,"m_GhostTrack_nNextToInnermostPixelLayerSharedHits", m_GhostTrack_nNextToInnermostPixelLayerSharedHits);
      setBranch<std::vector<int> >(tree,"m_GhostTrack_nNextToInnermostPixelLayerSplitHits",  m_GhostTrack_nNextToInnermostPixelLayerSplitHits);
    }
  }

  if ( m_infoSwitch.m_constituent ) {
    setBranch<int  >(tree,"numConstituents",   m_numConstituents);
  }

  if ( m_infoSwitch.m_constituentAll ) {
    setBranch<std::vector<float> >(tree,"constituentWeights", m_constituentWeights);
    setBranch<std::vector<float> >(tree,"constituent_pt",     m_constituent_pt    );
    setBranch<std::vector<float> >(tree,"constituent_eta",    m_constituent_eta   );
    setBranch<std::vector<float> >(tree,"constituent_phi",    m_constituent_pt   );
    setBranch<std::vector<float> >(tree,"constituent_e",      m_constituent_e     );
  }

  if( m_infoSwitch.m_flavTag  || m_infoSwitch.m_flavTagHLT  ) {

    setBranch<float>(tree,"MV2c00",        m_MV2c00);
    setBranch<float>(tree,"MV2c10",        m_MV2c10);
    setBranch<float>(tree,"MV2c20",    m_MV2c20);
    setBranch<float>(tree,"MV2c100",    m_MV2c100);

    setBranch<int  >(tree,"HadronConeExclTruthLabelID", m_HadronConeExclTruthLabelID);


    if( m_infoSwitch.m_jetFitterDetails){

      setBranch<float>(tree, "JetFitter_nVTX"          ,   m_JetFitter_nVTX            );
      setBranch<float>(tree, "JetFitter_nSingleTracks" ,   m_JetFitter_nSingleTracks   );
      setBranch<float>(tree, "JetFitter_nTracksAtVtx"  ,   m_JetFitter_nTracksAtVtx    );
      setBranch<float>(tree, "JetFitter_mass"          ,   m_JetFitter_mass            );
      setBranch<float>(tree, "JetFitter_energyFraction",   m_JetFitter_energyFraction  );
      setBranch<float>(tree, "JetFitter_significance3d",   m_JetFitter_significance3d  );
      setBranch<float>(tree, "JetFitter_deltaeta"      ,   m_JetFitter_deltaeta        );
      setBranch<float>(tree, "JetFitter_deltaphi"      ,   m_JetFitter_deltaphi        );
      setBranch<float>(tree, "JetFitter_N2Tpair"       ,   m_JetFitter_N2Tpar          );
      //setBranch<float>(tree, "JetFitter_pb"            ,   m_JetFitter_pb              );
      //setBranch<float>(tree, "JetFitter_pc"            ,   m_JetFitter_pc              );
      //setBranch<float>(tree, "JetFitter_pu"            ,   m_JetFitter_pu              );
      
    }

    if( m_infoSwitch.m_svDetails){
      setBranch<float>(tree, "SV0",               m_SV0);
      setBranch<float>(tree, "sv0_NGTinSvx",      m_sv0_NGTinSvx  );
      setBranch<float>(tree, "sv0_N2Tpair",       m_sv0_N2Tpair   );
      setBranch<float>(tree, "sv0_massvx",        m_sv0_massvx    );
      setBranch<float>(tree, "sv0_efracsvx",      m_sv0_efracsvx  );
      setBranch<float>(tree, "sv0_normdist",      m_sv0_normdist  );

      setBranch<float>(tree, "SV1",               m_SV1);
      setBranch<float>(tree, "SV1IP3D",           m_SV1IP3D);
      setBranch<float>(tree, "sv1_pu",            m_sv1_pu        );
      setBranch<float>(tree, "sv1_pb",            m_sv1_pb        );
      setBranch<float>(tree, "sv1_pc",            m_sv1_pc        );
      setBranch<float>(tree, "sv1_c",             m_sv1_c         );
      setBranch<float>(tree, "sv1_cu",            m_sv1_cu        );
      setBranch<float>(tree, "sv1_NGTinSvx",      m_sv1_NGTinSvx  );
      setBranch<float>(tree, "sv1_N2Tpair",       m_sv1_N2Tpair   );
      setBranch<float>(tree, "sv1_massvx",        m_sv1_massvx    );
      setBranch<float>(tree, "sv1_efracsvx",      m_sv1_efracsvx  );
      setBranch<float>(tree, "sv1_normdist",      m_sv1_normdist  );
      setBranch<float>(tree, "sv1_Lxy",           m_sv1_Lxy       );
      setBranch<float>(tree, "sv1_L3d",           m_sv1_L3d       );
      setBranch<float>(tree, "sv1_distmatlay",    m_sv1_distmatlay);
      setBranch<float>(tree, "sv1_dR",            m_sv1_dR        );
    }

    if( m_infoSwitch.m_ipDetails){    

      setBranch<float>(tree,  "IP2D_pu",                   m_IP2D_pu                   );
      setBranch<float>(tree,  "IP2D_pb",                   m_IP2D_pb                   );
      setBranch<float>(tree,  "IP2D_pc",                   m_IP2D_pc                   );
      setBranch<float>(tree,  "IP2D",                      m_IP2D                      );
      setBranch<float>(tree,  "IP2D_c",                    m_IP2D_c                    );
      setBranch<float>(tree,  "IP2D_cu",                   m_IP2D_cu                   );
      setBranch<float>(tree,  "nIP2DTracks"              , m_nIP2DTracks               );
      setBranch<std::vector<float> >(tree,  "IP2D_gradeOfTracks"       , m_IP2D_gradeOfTracks        );
      setBranch<std::vector<float> >(tree,  "IP2D_flagFromV0ofTracks"  , m_IP2D_flagFromV0ofTracks   );
      setBranch<std::vector<float> >(tree,  "IP2D_valD0wrtPVofTracks"  , m_IP2D_valD0wrtPVofTracks   );
      setBranch<std::vector<float> >(tree,  "IP2D_sigD0wrtPVofTracks"  , m_IP2D_sigD0wrtPVofTracks   );
      setBranch<std::vector<float> >(tree,  "IP2D_weightBofTracks"     , m_IP2D_weightBofTracks      );
      setBranch<std::vector<float> >(tree,  "IP2D_weightCofTracks"     , m_IP2D_weightCofTracks      );
      setBranch<std::vector<float> >(tree,  "IP2D_weightUofTracks"     , m_IP2D_weightUofTracks      );

      setBranch<float>(tree,  "IP3D",                      m_IP3D);
      setBranch<float>(tree,  "IP3D_pu",                   m_IP3D_pu                   );
      setBranch<float>(tree,  "IP3D_pb",                   m_IP3D_pb                   );
      setBranch<float>(tree,  "IP3D_pc",                   m_IP3D_pc                   );
      setBranch<float>(tree,  "IP3D",                      m_IP3D                      );
      setBranch<float>(tree,  "IP3D_c",                    m_IP3D_c                    );
      setBranch<float>(tree,  "IP3D_cu",                   m_IP3D_cu                   );
      setBranch<float>(tree,  "nIP3DTracks"              , m_nIP3DTracks               );
      setBranch<std::vector<float> >(tree,  "IP3D_gradeOfTracks"       , m_IP3D_gradeOfTracks        );
      setBranch<std::vector<float> >(tree,  "IP3D_flagFromV0ofTracks"  , m_IP3D_flagFromV0ofTracks   );
      setBranch<std::vector<float> >(tree,  "IP3D_valD0wrtPVofTracks"  , m_IP3D_valD0wrtPVofTracks   );
      setBranch<std::vector<float> >(tree,  "IP3D_sigD0wrtPVofTracks"  , m_IP3D_sigD0wrtPVofTracks   );
      setBranch<std::vector<float> >(tree,  "IP3D_valZ0wrtPVofTracks"  , m_IP3D_valZ0wrtPVofTracks   );
      setBranch<std::vector<float> >(tree,  "IP3D_sigZ0wrtPVofTracks"  , m_IP3D_sigZ0wrtPVofTracks   );
      setBranch<std::vector<float> >(tree,  "IP3D_weightBofTracks"     , m_IP3D_weightBofTracks      );
      setBranch<std::vector<float> >(tree,  "IP3D_weightCofTracks"     , m_IP3D_weightCofTracks      );
      setBranch<std::vector<float> >(tree,  "IP3D_weightUofTracks"     , m_IP3D_weightUofTracks      );

    }

    if( m_infoSwitch.m_JVC ) {
      setBranch<double>(tree,"JetVertexCharge_discriminant",     m_JetVertexCharge_discriminant);
    }
  }

  if( m_infoSwitch.m_flavTagHLT  ) {

    setBranch<float>(tree,"vtxOnlineValid",m_vtxOnlineValid);
    setBranch<float>(tree,"vtxHadDummy"   ,m_vtxHadDummy   );
    setBranch<float>(tree,"bs_online_vx"   ,m_bs_online_vx   );
    setBranch<float>(tree,"bs_online_vy"   ,m_bs_online_vy   );
    setBranch<float>(tree,"bs_online_vz"   ,m_bs_online_vz   );

    setBranch<float>(tree,"vtx_offline_x0"     ,m_vtx_offline_x0     );
    setBranch<float>(tree,"vtx_offline_y0"     ,m_vtx_offline_y0     );
    setBranch<float>(tree,"vtx_offline_z0"     ,m_vtx_offline_z0     );

    setBranch<float>(tree,"vtx_online_x0"      ,m_vtx_online_x0     );
    setBranch<float>(tree,"vtx_online_y0"      ,m_vtx_online_y0     );
    setBranch<float>(tree,"vtx_online_z0"      ,m_vtx_online_z0     );
                                                 
    setBranch<float>(tree,"vtx_online_bkg_x0"  ,m_vtx_online_bkg_x0     );
    setBranch<float>(tree,"vtx_online_bkg_y0"  ,m_vtx_online_bkg_y0     );
    setBranch<float>(tree,"vtx_online_bkg_z0"  ,m_vtx_online_bkg_z0     );

  }

  if( !m_infoSwitch.m_sfFTagFix.empty() ) {

    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 30)) m_btag_Fix30->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 50)) m_btag_Fix50->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 60)) m_btag_Fix60->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 70)) m_btag_Fix70->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 77)) m_btag_Fix77->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 80)) m_btag_Fix80->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 85)) m_btag_Fix85->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFix, 90)) m_btag_Fix90->setBranch(tree, m_name);
 
  }


  if( !m_infoSwitch.m_sfFTagFlt.empty() ) {

    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 30)) m_btag_Flt30->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 50)) m_btag_Flt50->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 60)) m_btag_Flt60->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 70)) m_btag_Flt70->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 77)) m_btag_Flt77->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 85)) m_btag_Flt85->setBranch(tree, m_name);
    if (findBTagSF(m_infoSwitch.m_sfFTagFlt, 90)) m_btag_Flt90->setBranch(tree, m_name);

  }// if sfFTagFlt


  if( m_infoSwitch.m_area ) {
    setBranch<float>(tree,"GhostArea",     m_GhostArea);
    setBranch<float>(tree,"ActiveArea",    m_ActiveArea);
    setBranch<float>(tree,"VoronoiArea",   m_VoronoiArea);
    setBranch<float>(tree,"ActiveArea4vec_pt", m_ActiveArea4vec_pt);
    setBranch<float>(tree,"ActiveArea4vec_eta", m_ActiveArea4vec_eta);
    setBranch<float>(tree,"ActiveArea4vec_phi", m_ActiveArea4vec_phi);
    setBranch<float>(tree,"ActiveArea4vec_m",   m_ActiveArea4vec_m);
  }

  if ( m_infoSwitch.m_truth && m_mc ) {
    setBranch<int  >(tree,"ConeTruthLabelID",   m_ConeTruthLabelID );
    setBranch<int  >(tree,"TruthCount",         m_TruthCount     );
    setBranch<float>(tree,"TruthLabelDeltaR_B", m_TruthLabelDeltaR_B     );
    setBranch<float>(tree,"TruthLabelDeltaR_C", m_TruthLabelDeltaR_C      );
    setBranch<float>(tree,"TruthLabelDeltaR_T", m_TruthLabelDeltaR_T      );
    setBranch<int  >(tree,"PartonTruthLabelID", m_PartonTruthLabelID  );
    setBranch<float>(tree,"GhostTruthAssociationFraction", m_GhostTruthAssociationFraction);
    setBranch<float>(tree,"truth_E",   m_truth_E);
    setBranch<float>(tree,"truth_pt",  m_truth_pt);
    setBranch<float>(tree,"truth_phi", m_truth_phi);
    setBranch<float>(tree,"truth_eta", m_truth_eta);
  }


  if ( m_infoSwitch.m_truthDetails ) {
    setBranch<int  >(tree,"GhostBHadronsFinalCount",   m_GhostBHadronsFinalCount   );
    setBranch<int  >(tree,"GhostBHadronsInitialCount", m_GhostBHadronsInitialCount );
    setBranch<int  >(tree,"GhostBQuarksFinalCount",    m_GhostBQuarksFinalCount    );
    setBranch<float>(tree,"GhostBHadronsFinalPt",      m_GhostBHadronsFinalPt      );
    setBranch<float>(tree,"GhostBHadronsInitialPt",    m_GhostBHadronsInitialPt    );
    setBranch<float>(tree,"GhostBQuarksFinalPt",       m_GhostBQuarksFinalPt       );

    setBranch<int  >(tree,"GhostCHadronsFinalCount"  , m_GhostCHadronsFinalCount  );
    setBranch<int  >(tree,"GhostCHadronsInitialCount", m_GhostCHadronsInitialCount);
    setBranch<int  >(tree,"GhostCQuarksFinalCount"   , m_GhostCQuarksFinalCount   );
    setBranch<float>(tree,"GhostCHadronsFinalPt"     , m_GhostCHadronsFinalPt     );
    setBranch<float>(tree,"GhostCHadronsInitialPt"   , m_GhostCHadronsInitialPt   );
    setBranch<float>(tree,"GhostCQuarksFinalPt"      , m_GhostCQuarksFinalPt      );

    setBranch<int  >(tree,"GhostTausFinalCount",       m_GhostTausFinalCount );
    setBranch<float>(tree,"GhostTausFinalPt"   ,       m_GhostTausFinalPt    );

    setBranch<int  >(tree,"truth_pdgId"   , m_truth_pdgId);
    setBranch<float>(tree,"truth_partonPt", m_truth_partonPt);
    setBranch<float>(tree,"truth_partonDR", m_truth_partonDR);
  }

  if ( m_infoSwitch.m_charge ) {
    setBranch<double>(tree,"charge", m_charge);
  }
  
  return;
}
    

void JetContainer::clear()
{
  
  ParticleContainer::clear();

  // rapidity
  if( m_infoSwitch.m_rapidity ) {
    m_rapidity->clear();
  }

  // clean
  if( m_infoSwitch.m_clean ) {
    m_Timing                    ->clear();
    m_LArQuality                ->clear();
    m_HECQuality                ->clear();
    m_NegativeE                 ->clear();
    m_AverageLArQF              ->clear();
    m_BchCorrCell               ->clear();
    m_N90Constituents           ->clear();
    m_LArBadHVEnergyFrac        ->clear();  
    m_LArBadHVNCell             ->clear();
    m_OotFracClusters5          ->clear();
    m_OotFracClusters10         ->clear();
    m_LeadingClusterPt          ->clear();
    m_LeadingClusterSecondLambda->clear();
    m_LeadingClusterCenterLambda->clear();
    m_LeadingClusterSecondR     ->clear();
    m_clean_passLooseBad        ->clear();
    m_clean_passLooseBadUgly    ->clear();
    m_clean_passTightBad        ->clear();
    m_clean_passTightBadUgly    ->clear();
  }


  // energy
  if ( m_infoSwitch.m_energy ) {
    m_HECFrac               ->clear();
    m_EMFrac                ->clear();
    m_CentroidR             ->clear();
    m_FracSamplingMax       ->clear();
    m_FracSamplingMaxIndex  ->clear();
    m_LowEtConstituentsFrac ->clear();
    m_GhostMuonSegmentCount ->clear();
    m_Width                 ->clear();
  }

  // each step of the calibration sequence
  if ( m_infoSwitch.m_scales ) {
    m_emScalePt             ->clear();
    m_constScalePt	    ->clear();
    m_pileupScalePt	    ->clear(); 
    m_originConstitScalePt  ->clear();
    m_etaJESScalePt	    ->clear();
    m_gscScalePt	    ->clear(); 
    m_insituScalePt	    ->clear();
  }

  // eta at constScale
  if ( m_infoSwitch.m_constscaleEta ) {
    m_constScaleEta	    ->clear();
  }

  // layer
  if ( m_infoSwitch.m_layer ) {
    m_EnergyPerSampling->clear();
  }

  // trackAll
  if ( m_infoSwitch.m_trackAll ) {
    m_NumTrkPt1000             ->clear();
    m_SumPtTrkPt1000           ->clear();
    m_TrackWidthPt1000         ->clear();
    m_NumTrkPt500              ->clear();
    m_SumPtTrkPt500            ->clear();
    m_TrackWidthPt500          ->clear();
    m_JVF                      ->clear();
  }

  // trackPV
  if ( m_infoSwitch.m_trackPV ) {
    m_NumTrkPt1000PV    ->clear();
    m_SumPtTrkPt1000PV  ->clear();
    m_TrackWidthPt1000PV->clear();
    m_NumTrkPt500PV     ->clear();
    m_SumPtTrkPt500PV   ->clear();
    m_TrackWidthPt500PV ->clear();
    m_JVFPV             ->clear();
    m_Jvt               ->clear();
    m_JvtJvfcorr        ->clear();
    m_JvtRpt            ->clear();
    if( m_mc ){
      m_JvtEff_SF_Loose   ->clear();
      m_JvtEff_SF_Medium  ->clear();
      m_JvtEff_SF_Tight   ->clear();
    }

  }


  if ( m_infoSwitch.m_allTrack ) {
    m_GhostTrackCount     ->clear();
    m_GhostTrackPt        ->clear();
    m_GhostTrack_pt       ->clear();
    m_GhostTrack_qOverP   ->clear();
    m_GhostTrack_eta      ->clear();
    m_GhostTrack_phi      ->clear();
    m_GhostTrack_e        ->clear();
    m_GhostTrack_d0       ->clear();
    m_GhostTrack_z0       ->clear();

    if ( m_infoSwitch.m_allTrackDetail ) {
      m_GhostTrack_nPixelHits                               ->clear();   
      m_GhostTrack_nSCTHits                                 ->clear(); 
      m_GhostTrack_nTRTHits                                 ->clear(); 
      m_GhostTrack_nPixelSharedHits                         ->clear(); 
      m_GhostTrack_nPixelSplitHits                          ->clear(); 
      m_GhostTrack_nInnermostPixelLayerHits                 ->clear(); 
      m_GhostTrack_nInnermostPixelLayerSharedHits           ->clear(); 
      m_GhostTrack_nInnermostPixelLayerSplitHits            ->clear(); 
      m_GhostTrack_nNextToInnermostPixelLayerHits           ->clear(); 
      m_GhostTrack_nNextToInnermostPixelLayerSharedHits     ->clear(); 
      m_GhostTrack_nNextToInnermostPixelLayerSplitHits      ->clear(); 
    }
  }

  if( m_infoSwitch.m_constituent ) {
    m_numConstituents->clear();
  }

  if( m_infoSwitch.m_constituentAll ) {
    m_constituentWeights ->clear();
    m_constituent_pt     ->clear();
    m_constituent_eta    ->clear();
    m_constituent_phi    ->clear();
    m_constituent_e      ->clear();
  }

  // flavor tag
  if ( m_infoSwitch.m_flavTag || m_infoSwitch.m_flavTagHLT  ) {

    m_MV2c00                    ->clear();
    m_MV2c10                    ->clear();
    m_MV2c20                    ->clear();
    m_MV2c100                   ->clear();
    m_MV2                       ->clear();
    m_HadronConeExclTruthLabelID->clear();


    if( m_infoSwitch.m_jetFitterDetails){
      m_JetFitter_nVTX             ->clear();
      m_JetFitter_nSingleTracks    ->clear();
      m_JetFitter_nTracksAtVtx     ->clear();
      m_JetFitter_mass             ->clear();
      m_JetFitter_energyFraction   ->clear();
      m_JetFitter_significance3d   ->clear();
      m_JetFitter_deltaeta         ->clear();
      m_JetFitter_deltaphi         ->clear();
      m_JetFitter_N2Tpar           ->clear();
    }

    if( m_infoSwitch.m_svDetails){
      m_SV0               ->clear();
      m_sv0_NGTinSvx      ->clear(); 
      m_sv0_N2Tpair       ->clear(); 
      m_sv0_massvx        ->clear(); 
      m_sv0_efracsvx      ->clear(); 
      m_sv0_normdist      ->clear(); 
      
      m_SV1               ->clear();
      m_SV1IP3D           ->clear();
      m_sv1_pu            ->clear(); 
      m_sv1_pb            ->clear(); 
      m_sv1_pc            ->clear(); 
      m_sv1_c             ->clear(); 
      m_sv1_cu            ->clear(); 
      m_sv1_NGTinSvx      ->clear(); 
      m_sv1_N2Tpair       ->clear(); 
      m_sv1_massvx        ->clear(); 
      m_sv1_efracsvx      ->clear(); 
      m_sv1_normdist      ->clear(); 
      m_sv1_Lxy           ->clear(); 
      m_sv1_L3d           ->clear(); 
      m_sv1_distmatlay    ->clear(); 
      m_sv1_dR            ->clear(); 
    }

    if( m_infoSwitch.m_ipDetails){
      m_IP2D_pu        ->clear(); 
      m_IP2D_pb        ->clear(); 
      m_IP2D_pc        ->clear(); 
      m_IP2D           ->clear(); 
      m_IP2D_c         ->clear(); 
      m_IP2D_cu        ->clear(); 
      m_nIP2DTracks    ->clear(); 
      
      m_IP2D_gradeOfTracks              ->clear(); 
      m_IP2D_flagFromV0ofTracks         ->clear(); 
      m_IP2D_valD0wrtPVofTracks         ->clear(); 
      m_IP2D_sigD0wrtPVofTracks         ->clear(); 
      m_IP2D_weightBofTracks            ->clear(); 
      m_IP2D_weightCofTracks            ->clear(); 
      m_IP2D_weightUofTracks            ->clear(); 

      m_IP3D         ->clear();
      m_IP3D_pu      ->clear(); 
      m_IP3D_pb      ->clear(); 
      m_IP3D_pc      ->clear(); 
      m_IP3D         ->clear(); 
      m_IP3D_c       ->clear(); 
      m_IP3D_cu      ->clear(); 
      m_nIP3DTracks  ->clear(); 
      m_IP3D_gradeOfTracks        ->clear();
      m_IP3D_flagFromV0ofTracks   ->clear();
      m_IP3D_valD0wrtPVofTracks   ->clear();
      m_IP3D_sigD0wrtPVofTracks   ->clear();
      m_IP3D_valZ0wrtPVofTracks   ->clear();
      m_IP3D_sigZ0wrtPVofTracks   ->clear();
      m_IP3D_weightBofTracks      ->clear();
      m_IP3D_weightCofTracks      ->clear();
      m_IP3D_weightUofTracks      ->clear();
    }
    
    if( m_infoSwitch.m_JVC ){
      m_JetVertexCharge_discriminant->clear();
    }
  }

  if ( m_infoSwitch.m_flavTagHLT  ) {
    m_vtxOnlineValid->clear();
    m_vtxHadDummy->clear();
    m_bs_online_vx->clear();
    m_bs_online_vy->clear();
    m_bs_online_vz->clear();

    m_vtx_offline_x0->clear();
    m_vtx_offline_y0->clear();
    m_vtx_offline_z0->clear();

    m_vtx_online_x0->clear();
    m_vtx_online_y0->clear();
    m_vtx_online_z0->clear();

    m_vtx_online_bkg_x0->clear();
    m_vtx_online_bkg_y0->clear();
    m_vtx_online_bkg_z0->clear();

  }


  if( !m_infoSwitch.m_sfFTagFix.empty() ) { // just clear them all....
    m_btag_Fix30->clear();
    m_btag_Fix50->clear();
    m_btag_Fix60->clear();
    m_btag_Fix70->clear();
    m_btag_Fix77->clear();
    m_btag_Fix80->clear();
    m_btag_Fix85->clear();
    m_btag_Fix90->clear();
  }
  

  if( !m_infoSwitch.m_sfFTagFlt.empty() ) { // just clear them all....
    
    m_btag_Flt30->clear();
    m_btag_Flt50->clear();
    m_btag_Flt60->clear();
    m_btag_Flt70->clear();
    m_btag_Flt77->clear();
    m_btag_Flt85->clear();
    m_btag_Flt90->clear();
  
  }
  

  if ( m_infoSwitch.m_area ) {
    m_GhostArea          ->clear();
    m_ActiveArea         ->clear();
    m_VoronoiArea        ->clear();
    m_ActiveArea4vec_pt  ->clear();
    m_ActiveArea4vec_eta ->clear();
    m_ActiveArea4vec_phi ->clear();
    m_ActiveArea4vec_m   ->clear();
  }

  // truth
  if ( m_infoSwitch.m_truth && m_mc ) {
    m_ConeTruthLabelID  ->clear();
    m_TruthCount        ->clear();
    m_TruthLabelDeltaR_B->clear();
    m_TruthLabelDeltaR_C->clear();
    m_TruthLabelDeltaR_T->clear();
    m_PartonTruthLabelID->clear();
    m_GhostTruthAssociationFraction->clear();
    m_truth_E  ->clear();
    m_truth_pt ->clear();
    m_truth_phi->clear();
    m_truth_eta->clear();
  }

  // truth_detail
  if ( m_infoSwitch.m_truthDetails ) {
    m_GhostBHadronsFinalCount       ->clear();
    m_GhostBHadronsInitialCount     ->clear();
    m_GhostBQuarksFinalCount        ->clear();
    m_GhostBHadronsFinalPt          ->clear();
    m_GhostBHadronsInitialPt        ->clear();
    m_GhostBQuarksFinalPt           ->clear();

    m_GhostCHadronsFinalCount       ->clear();
    m_GhostCHadronsInitialCount     ->clear();
    m_GhostCQuarksFinalCount        ->clear();
    m_GhostCHadronsFinalPt          ->clear();
    m_GhostCHadronsInitialPt        ->clear();
    m_GhostCQuarksFinalPt           ->clear();

    m_GhostTausFinalCount           ->clear();
    m_GhostTausFinalPt              ->clear();
    				    
    m_truth_pdgId                   ->clear();
    m_truth_partonPt                ->clear();
    m_truth_partonDR                ->clear();

  }

  if( m_infoSwitch.m_charge ) {
    m_charge->clear();
  }

  return;
}

bool JetContainer::findBTagSF(const std::vector<int>& sfList, int workingPt){
  return (std::find(sfList.begin(), sfList.end(),workingPt ) != sfList.end());
 }

