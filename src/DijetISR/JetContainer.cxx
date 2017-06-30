#include "JetContainer.h"

JetContainer::JetContainer(const std::string& name, const std::string& detailStr, float units, bool mc)
  : ParticleContainer(name,detailStr,units,mc)
{ }

JetContainer::~JetContainer()
{ }

void JetContainer::setReader(TTreeReader *reader)
{
  JetContainer::setReader(reader, "");
}

void JetContainer::setReader(TTreeReader *reader, const std::string& tagger)
{
  //
  // Connect branches
  ParticleContainer::setReader(reader);

  if(m_infoSwitch.m_rapidity)
    {
      m_rapidity=TTreeReaderArray<float>(*reader,"rapidity");
    }

  if(m_infoSwitch.m_clean)
    {
      m_Timing                    =TTreeReaderArray<float>(*reader,branchName("Timing"                    ).c_str());
      m_LArQuality                =TTreeReaderArray<float>(*reader,branchName("LArQuality"                ).c_str());

      m_LArBadHVNCell             =TTreeReaderArray<int  >(*reader,branchName("LArBadHVNCell"             ).c_str());

      m_LArQuality                =TTreeReaderArray<float>(*reader,branchName("LArQuality"                ).c_str());
      m_HECQuality                =TTreeReaderArray<float>(*reader,branchName("HECQuality"                ).c_str());
      m_NegativeE                 =TTreeReaderArray<float>(*reader,branchName("NegativeE"                 ).c_str());
      m_AverageLArQF              =TTreeReaderArray<float>(*reader,branchName("AverageLArQF"              ).c_str());
      m_BchCorrCell               =TTreeReaderArray<float>(*reader,branchName("BchCorrCell"               ).c_str());
      m_N90Constituents           =TTreeReaderArray<float>(*reader,branchName("N90Constituents"           ).c_str());
      m_LArBadHVEnergyFrac        =TTreeReaderArray<float>(*reader,branchName("LArBadHVEnergyFrac"        ).c_str());
      m_OotFracClusters5          =TTreeReaderArray<float>(*reader,branchName("OotFracClusters5"          ).c_str());
      m_OotFracClusters10         =TTreeReaderArray<float>(*reader,branchName("OotFracClusters10"         ).c_str());
      m_LeadingClusterPt          =TTreeReaderArray<float>(*reader,branchName("LeadingClusterPt"          ).c_str());
      m_LeadingClusterSecondLambda=TTreeReaderArray<float>(*reader,branchName("LeadingClusterSecondLambda").c_str());
      m_LeadingClusterCenterLambda=TTreeReaderArray<float>(*reader,branchName("LeadingClusterCenterLambda").c_str());
      m_LeadingClusterSecondR     =TTreeReaderArray<float>(*reader,branchName("LeadingClusterSecondR"     ).c_str());
      m_clean_passLooseBad        =TTreeReaderArray<int  >(*reader,branchName("clean_passLooseBad"        ).c_str());
      m_clean_passLooseBadUgly    =TTreeReaderArray<int  >(*reader,branchName("clean_passLooseBadUgly"    ).c_str());
      m_clean_passTightBad        =TTreeReaderArray<int  >(*reader,branchName("clean_passTightBad"        ).c_str());
      m_clean_passTightBadUgly    =TTreeReaderArray<int  >(*reader,branchName("clean_passTightBadUgly"    ).c_str());
    }

  if(m_infoSwitch.m_energy)
    {
      m_HECFrac              =TTreeReaderArray<float>(*reader,branchName("HECFrac"              ).c_str());
      m_EMFrac               =TTreeReaderArray<float>(*reader,branchName("EMFrac"               ).c_str());
      m_CentroidR            =TTreeReaderArray<float>(*reader,branchName("CentroidR"            ).c_str());
      m_FracSamplingMax      =TTreeReaderArray<float>(*reader,branchName("FracSamplingMax"      ).c_str());
      m_FracSamplingMaxIndex =TTreeReaderArray<float>(*reader,branchName("FracSamplingMaxIndex" ).c_str());
      m_LowEtConstituentsFrac=TTreeReaderArray<float>(*reader,branchName("LowEtConstituentsFrac").c_str());
      m_GhostMuonSegmentCount=TTreeReaderArray<float>(*reader,branchName("GhostMuonSegmentCount").c_str());
      m_Width                =TTreeReaderArray<float>(*reader,branchName("Width"                ).c_str());
    }

  if(m_infoSwitch.m_trackPV)
    {
      m_NumTrkPt1000PV    =TTreeReaderArray<float>(*reader,branchName("NumTrkPt1000PV"    ).c_str());
      m_SumPtTrkPt1000PV  =TTreeReaderArray<float>(*reader,branchName("SumPtTrkPt1000PV"  ).c_str());
      m_TrackWidthPt1000PV=TTreeReaderArray<float>(*reader,branchName("TrackWidthPt1000PV").c_str());
      m_NumTrkPt500PV     =TTreeReaderArray<float>(*reader,branchName("NumTrkPt500PV"     ).c_str());
      m_SumPtTrkPt500PV   =TTreeReaderArray<float>(*reader,branchName("SumPtTrkPt500PV"   ).c_str());
      m_TrackWidthPt500PV =TTreeReaderArray<float>(*reader,branchName("TrackWidthPt500PV" ).c_str());
      m_JVFPV             =TTreeReaderArray<float>(*reader,branchName("JVFPV"             ).c_str());
    }

  if(m_infoSwitch.m_trackAll || m_infoSwitch.m_trackPV)
    {
      m_Jvt       =TTreeReaderArray<float>(*reader,branchName("Jvt"       ).c_str());
      m_JvtJvfcorr=TTreeReaderArray<float>(*reader,branchName("JvtJvfcorr").c_str());
      m_JvtRpt    =TTreeReaderArray<float>(*reader,branchName("JvtRpt"    ).c_str());
    }

  if(m_infoSwitch.m_JVC)
    {
      m_JetVertexCharge_discriminant=TTreeReaderArray<double>(*reader,branchName("JetVertexCharge_discriminant").c_str());
    }

  if(m_infoSwitch.m_flavTag || m_infoSwitch.m_flavTagHLT)
    {
      m_MV2c00                    =TTreeReaderArray<float>(*reader,branchName("MV2c00"                    ).c_str());
      m_MV2c10                    =TTreeReaderArray<float>(*reader,branchName("MV2c10"                    ).c_str());
      m_MV2c20                    =TTreeReaderArray<float>(*reader,branchName("MV2c20"                    ).c_str());
      m_MV2c100                   =TTreeReaderArray<float>(*reader,branchName("MV2c100"                   ).c_str());
      m_HadronConeExclTruthLabelID=TTreeReaderArray<int  >(*reader,branchName("HadronConeExclTruthLabelID").c_str());

      if(tagger == "MV2c20")  m_MV2 = m_MV2c20;
      if(tagger == "MV2c10")  m_MV2 = m_MV2c10;

    }

  if(m_infoSwitch.m_flavTagHLT)
    {
      m_vtxHadDummy   =TTreeReaderArray<float>(*reader,branchName("vtxHadDummy"   ).c_str());
      m_bs_online_vx  =TTreeReaderArray<float>(*reader,branchName("bs_online_vx"  ).c_str());
      m_bs_online_vy  =TTreeReaderArray<float>(*reader,branchName("bs_online_vy"  ).c_str());
      m_bs_online_vz  =TTreeReaderArray<float>(*reader,branchName("bs_online_vz"  ).c_str());
                     
      m_vtx_offline_x0=TTreeReaderArray<float>(*reader,branchName("vtx_offline_x0").c_str());
      m_vtx_offline_y0=TTreeReaderArray<float>(*reader,branchName("vtx_offline_y0").c_str());
      m_vtx_offline_z0=TTreeReaderArray<float>(*reader,branchName("vtx_offline_z0").c_str());
                     
      m_vtx_online_x0 =TTreeReaderArray<float>(*reader,branchName("vtx_online_x0" ).c_str());
      m_vtx_online_y0 =TTreeReaderArray<float>(*reader,branchName("vtx_online_y0" ).c_str());
      m_vtx_online_z0 =TTreeReaderArray<float>(*reader,branchName("vtx_online_z0" ).c_str());
    }

  if(m_infoSwitch.m_jetFitterDetails)
    {
      m_JetFitter_nVTX          =TTreeReaderArray<float>(*reader,branchName("JetFitter_nVTX"          ).c_str());
      m_JetFitter_nSingleTracks =TTreeReaderArray<float>(*reader,branchName("JetFitter_nSingleTracks" ).c_str());
      m_JetFitter_nTracksAtVtx  =TTreeReaderArray<float>(*reader,branchName("JetFitter_nTracksAtVtx"  ).c_str());
      m_JetFitter_mass          =TTreeReaderArray<float>(*reader,branchName("JetFitter_mass"          ).c_str());
      m_JetFitter_energyFraction=TTreeReaderArray<float>(*reader,branchName("JetFitter_energyFraction").c_str());
      m_JetFitter_significance3d=TTreeReaderArray<float>(*reader,branchName("JetFitter_significance3d").c_str());
      m_JetFitter_deltaeta      =TTreeReaderArray<float>(*reader,branchName("JetFitter_deltaeta"      ).c_str());
      m_JetFitter_deltaphi      =TTreeReaderArray<float>(*reader,branchName("JetFitter_deltaphi"      ).c_str());
      m_JetFitter_N2Tpar        =TTreeReaderArray<float>(*reader,branchName("JetFitter_N2Tpair"       ).c_str());
    }

    if( m_infoSwitch.m_svDetails){

      m_SV0                     =TTreeReaderArray<float>(*reader,branchName("SV0"           ).c_str());
      m_SV0_NGTinSvx            =TTreeReaderArray<float>(*reader,branchName("SV0_NGTinSvx"  ).c_str());
      m_SV0_N2Tpair             =TTreeReaderArray<float>(*reader,branchName("SV0_N2Tpair"   ).c_str());
      m_SV0_masssvx             =TTreeReaderArray<float>(*reader,branchName("SV0_massvx"    ).c_str());
      m_SV0_efracsvx            =TTreeReaderArray<float>(*reader,branchName("SV0_efracsvx"  ).c_str());
      m_SV0_normdist            =TTreeReaderArray<float>(*reader,branchName("SV0_normdist"  ).c_str());

      m_SV1                     =TTreeReaderArray<float>(*reader,branchName("SV1"           ).c_str());
      m_SV1plusIP3D_discriminant=TTreeReaderArray<float>(*reader,branchName("SV1IP3D"       ).c_str());
      m_SV1_pu                  =TTreeReaderArray<float>(*reader,branchName("SV1_pu"        ).c_str());
      m_SV1_pb                  =TTreeReaderArray<float>(*reader,branchName("SV1_pb"        ).c_str());
      m_SV1_pc                  =TTreeReaderArray<float>(*reader,branchName("SV1_pc"        ).c_str());
      m_SV1_c                   =TTreeReaderArray<float>(*reader,branchName("SV1_c"         ).c_str());
      m_SV1_cu                  =TTreeReaderArray<float>(*reader,branchName("SV1_cu"        ).c_str());
      m_SV1_NGTinSvx            =TTreeReaderArray<float>(*reader,branchName("SV1_NGTinSvx"  ).c_str());
      m_SV1_N2Tpair             =TTreeReaderArray<float>(*reader,branchName("SV1_N2Tpair"   ).c_str());
      m_SV1_masssvx             =TTreeReaderArray<float>(*reader,branchName("SV1_massvx"    ).c_str());
      m_SV1_efracsvx            =TTreeReaderArray<float>(*reader,branchName("SV1_efracsvx"  ).c_str());
      m_SV1_normdist            =TTreeReaderArray<float>(*reader,branchName("SV1_normdist"  ).c_str());
      m_SV1_Lxy                 =TTreeReaderArray<float>(*reader,branchName("SV1_Lxy"       ).c_str());
      m_SV1_L3d                 =TTreeReaderArray<float>(*reader,branchName("SV1_L3d"       ).c_str());
      m_SV1_distmatlay          =TTreeReaderArray<float>(*reader,branchName("SV1_distmatlay").c_str());
      m_SV1_dR                  =TTreeReaderArray<float>(*reader,branchName("SV1_dR"        ).c_str());
    }

    if( m_infoSwitch.m_ipDetails){    

      m_IP2D_pu                =TTreeReaderArray<float>             (*reader, branchName("IP2D_pu"                ).c_str());
      m_IP2D_pb                =TTreeReaderArray<float>             (*reader, branchName("IP2D_pb"                ).c_str());
      m_IP2D_pc                =TTreeReaderArray<float>             (*reader, branchName("IP2D_pc"                ).c_str());
      m_IP2D                   =TTreeReaderArray<float>             (*reader, branchName("IP2D"                   ).c_str());
      m_IP2D_c                 =TTreeReaderArray<float>             (*reader, branchName("IP2D_c"                 ).c_str());
      m_IP2D_cu                =TTreeReaderArray<float>             (*reader, branchName("IP2D_cu"                ).c_str());
      m_IP2D_gradeOfTracks     =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_gradeOfTracks"     ).c_str());
      m_IP2D_flagFromV0ofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_flagFromV0ofTracks").c_str());
      m_IP2D_valD0wrtPVofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_valD0wrtPVofTracks").c_str());
      m_IP2D_sigD0wrtPVofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_sigD0wrtPVofTracks").c_str());
      m_IP2D_weightBofTracks   =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_weightBofTracks"   ).c_str());
      m_IP2D_weightCofTracks   =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_weightCofTracks"   ).c_str());
      m_IP2D_weightUofTracks   =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_weightUofTracks"   ).c_str());

      m_IP3D                   =TTreeReaderArray<float>             (*reader, branchName("IP3D"   ).c_str());
      m_IP3D_pu                =TTreeReaderArray<float>             (*reader, branchName("IP3D_pu").c_str());
      m_IP3D_pb                =TTreeReaderArray<float>             (*reader, branchName("IP3D_pb").c_str());
      m_IP3D_pc                =TTreeReaderArray<float>             (*reader, branchName("IP3D_pc").c_str());
      m_IP3D_c                 =TTreeReaderArray<float>             (*reader, branchName("IP3D_c" ).c_str());
      m_IP3D_cu                =TTreeReaderArray<float>             (*reader, branchName("IP3D_cu").c_str());
      m_IP3D_gradeOfTracks     =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_gradeOfTracks"     ).c_str());
      m_IP3D_flagFromV0ofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_flagFromV0ofTracks").c_str());
      m_IP3D_valD0wrtPVofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_valD0wrtPVofTracks").c_str());
      m_IP3D_sigD0wrtPVofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_sigD0wrtPVofTracks").c_str());
      m_IP3D_valZ0wrtPVofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_valZ0wrtPVofTracks").c_str());
      m_IP3D_sigZ0wrtPVofTracks=TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_sigZ0wrtPVofTracks").c_str());
      m_IP3D_weightBofTracks   =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_weightBofTracks"   ).c_str());
      m_IP3D_weightCofTracks   =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_weightCofTracks"   ).c_str());
      m_IP3D_weightUofTracks   =TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_weightUofTracks"   ).c_str());

    }


  for(uint i=0; i<m_infoSwitch.m_sfFTagFix.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFix[i] ) 
        {
        case 30: m_btag_Fix30->setReader(reader, m_name); break;
        case 50: m_btag_Fix50->setReader(reader, m_name); break;
        case 60: m_btag_Fix60->setReader(reader, m_name); break;
        case 70: m_btag_Fix70->setReader(reader, m_name); break;
        case 77: m_btag_Fix77->setReader(reader, m_name); break;
        case 80: m_btag_Fix80->setReader(reader, m_name); break;
        case 85: m_btag_Fix85->setReader(reader, m_name); break;         
        case 90: m_btag_Fix90->setReader(reader, m_name); break;
      }
    }

  for(uint i=0; i<m_infoSwitch.m_sfFTagFlt.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFlt[i] ) 
        {
        case 30: m_btag_Flt30->setReader(reader, m_name); break;
        case 50: m_btag_Flt50->setReader(reader, m_name); break;
        case 60: m_btag_Flt60->setReader(reader, m_name); break;              
        case 70: m_btag_Flt70->setReader(reader, m_name); break;
        case 77: m_btag_Flt77->setReader(reader, m_name); break;
        case 85: m_btag_Flt85->setReader(reader, m_name); break;
        }
    }


  // truth
  if(m_infoSwitch.m_truth)
    {
      m_ConeTruthLabelID  =TTreeReaderArray<int  >(*reader,branchName("ConeTruthLabelID"  ).c_str());
      m_TruthCount        =TTreeReaderArray<int  >(*reader,branchName("TruthCount"        ).c_str());
      m_TruthLabelDeltaR_B=TTreeReaderArray<float>(*reader,branchName("TruthLabelDeltaR_B").c_str());
      m_TruthLabelDeltaR_C=TTreeReaderArray<float>(*reader,branchName("TruthLabelDeltaR_C").c_str());
      m_TruthLabelDeltaR_T=TTreeReaderArray<float>(*reader,branchName("TruthLabelDeltaR_T").c_str());
      m_PartonTruthLabelID=TTreeReaderArray<int  >(*reader,branchName("PartonTruthLabelID").c_str());
      m_GhostTruthAssociationFraction=TTreeReaderArray<float>(*reader,branchName("GhostTruthAssociationFraction").c_str());
      m_truth_E  =TTreeReaderArray<float>(*reader,branchName("truth_E"  ).c_str());
      m_truth_pt =TTreeReaderArray<float>(*reader,branchName("truth_pt" ).c_str());
      m_truth_phi=TTreeReaderArray<float>(*reader,branchName("truth_phi").c_str());
      m_truth_eta=TTreeReaderArray<float>(*reader,branchName("truth_eta").c_str());
    }

  // charge
  if(m_infoSwitch.m_charge)
    {
      m_charge=TTreeReaderArray<double>(*reader,branchName("charge").c_str());
    }
}

void JetContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);  

  if(m_infoSwitch.m_rapidity)
    {
      m_particles[idx].rapidity                  =m_rapidity                  [idx];
    }

  if(m_infoSwitch.m_clean)
    {
      m_particles[idx].Timing                    =m_Timing                    [idx];
      m_particles[idx].LArQuality                =m_LArQuality                [idx];
      m_particles[idx].HECQuality                =m_HECQuality                [idx];
      m_particles[idx].NegativeE                 =m_NegativeE                 [idx];
      m_particles[idx].AverageLArQF              =m_AverageLArQF              [idx];
      m_particles[idx].BchCorrCell               =m_BchCorrCell               [idx];
      m_particles[idx].N90Constituents           =m_N90Constituents           [idx];
      m_particles[idx].LArBadHVEnergyFrac        =m_LArBadHVEnergyFrac        [idx];
      m_particles[idx].LArBadHVNCell             =m_LArBadHVNCell             [idx];
      m_particles[idx].OotFracClusters5          =m_OotFracClusters5          [idx];
      m_particles[idx].OotFracClusters10         =m_OotFracClusters10         [idx];
      m_particles[idx].LeadingClusterPt          =m_LeadingClusterPt          [idx];
      m_particles[idx].LeadingClusterSecondLambda=m_LeadingClusterSecondLambda[idx];
      m_particles[idx].LeadingClusterCenterLambda=m_LeadingClusterCenterLambda[idx];
      m_particles[idx].LeadingClusterSecondR     =m_LeadingClusterSecondR     [idx];
      m_particles[idx].clean_passLooseBad        =m_clean_passLooseBad        [idx];
      m_particles[idx].clean_passLooseBadUgly    =m_clean_passLooseBadUgly    [idx];
      m_particles[idx].clean_passTightBad        =m_clean_passTightBad        [idx];
      m_particles[idx].clean_passTightBadUgly    =m_clean_passTightBadUgly    [idx];
    }

  if(m_infoSwitch.m_energy)
    {
      m_particles[idx].HECFrac              =m_HECFrac              [idx];
      m_particles[idx].EMFrac               =m_EMFrac               [idx];
      m_particles[idx].CentroidR            =m_CentroidR            [idx];
      m_particles[idx].FracSamplingMax      =m_FracSamplingMax      [idx];
      m_particles[idx].FracSamplingMaxIndex =m_FracSamplingMaxIndex [idx];
      m_particles[idx].LowEtConstituentsFrac=m_LowEtConstituentsFrac[idx];
      m_particles[idx].GhostMuonSegmentCount=m_GhostMuonSegmentCount[idx];
      m_particles[idx].Width                =m_Width                [idx];
    }
  
  if(m_infoSwitch.m_trackPV)
    {
      m_particles[idx].NumTrkPt1000PV    =m_NumTrkPt1000PV    [idx];
      m_particles[idx].SumPtTrkPt1000PV  =m_SumPtTrkPt1000PV  [idx];
      m_particles[idx].TrackWidthPt1000PV=m_TrackWidthPt1000PV[idx];
      m_particles[idx].NumTrkPt500PV     =m_NumTrkPt500PV     [idx];
      m_particles[idx].SumPtTrkPt500PV   =m_SumPtTrkPt500PV   [idx];
      m_particles[idx].TrackWidthPt500PV =m_TrackWidthPt500PV [idx];
      m_particles[idx].JVFPV             =m_JVFPV             [idx];
    }

  if(m_infoSwitch.m_trackPV || m_infoSwitch.m_trackAll)
    {
      m_particles[idx].Jvt       =m_Jvt       [idx];
      m_particles[idx].JvtJvfcorr=m_JvtJvfcorr[idx];
      m_particles[idx].JvtRpt    =m_JvtRpt    [idx];
    }
  
  if( m_infoSwitch.m_JVC ) {
    m_particles[idx].JetVertexCharge_discriminant = m_JetVertexCharge_discriminant[idx];
  }

  if(m_infoSwitch.m_flavTag  || m_infoSwitch.m_flavTagHLT)
    {
      m_particles[idx].MV2c00                    =m_MV2c00               [idx];
      m_particles[idx].MV2c10                    =m_MV2c10               [idx];
      m_particles[idx].MV2c20                    =m_MV2c20               [idx];
      m_particles[idx].MV2c100                   =m_MV2c100              [idx];
      m_particles[idx].MV2                       =m_MV2                  [idx];

      m_particles[idx].HadronConeExclTruthLabelID=m_HadronConeExclTruthLabelID[idx];
    }


  if(m_infoSwitch.m_flavTagHLT)
    {
      m_particles[idx].bs_online_vx                      =m_bs_online_vx                  [idx];
      m_particles[idx].bs_online_vy                      =m_bs_online_vy                  [idx];
      m_particles[idx].bs_online_vz                      =m_bs_online_vz                  [idx];
      m_particles[idx].vtxHadDummy                       =m_vtxHadDummy                   [idx];
      m_particles[idx].vtx_offline_x0                    =m_vtx_offline_x0                [idx];
      m_particles[idx].vtx_offline_y0                    =m_vtx_offline_y0                [idx];
      m_particles[idx].vtx_offline_z0                    =m_vtx_offline_z0                [idx];

      m_particles[idx].vtx_online_x0                     =m_vtx_online_x0                 [idx];
      m_particles[idx].vtx_online_y0                     =m_vtx_online_y0                 [idx];
      m_particles[idx].vtx_online_z0                     =m_vtx_online_z0                 [idx];

    }

  if(m_infoSwitch.m_jetFitterDetails)
    {
      m_particles[idx].JetFitter_nVTX                  =m_JetFitter_nVTX           [idx];
      m_particles[idx].JetFitter_nSingleTracks         =m_JetFitter_nSingleTracks  [idx];
      m_particles[idx].JetFitter_nTracksAtVtx          =m_JetFitter_nTracksAtVtx   [idx];
      m_particles[idx].JetFitter_mass                  =m_JetFitter_mass           [idx];
      m_particles[idx].JetFitter_energyFraction        =m_JetFitter_energyFraction [idx];
      m_particles[idx].JetFitter_significance3d        =m_JetFitter_significance3d [idx];
      m_particles[idx].JetFitter_deltaeta              =m_JetFitter_deltaeta       [idx];
      m_particles[idx].JetFitter_deltaphi              =m_JetFitter_deltaphi       [idx];
      m_particles[idx].JetFitter_N2Tpar                =m_JetFitter_N2Tpar         [idx];

    }

  if(m_infoSwitch.m_svDetails){

    m_particles[idx].SV0                      = m_SV0           [idx];
    m_particles[idx].SV0_NGTinSvx             = m_SV0_NGTinSvx  [idx];
    m_particles[idx].SV0_N2Tpair              = m_SV0_N2Tpair   [idx];
    m_particles[idx].SV0_masssvx              = m_SV0_masssvx   [idx];
    m_particles[idx].SV0_efracsvx             = m_SV0_efracsvx  [idx];
    m_particles[idx].SV0_normdist             = m_SV0_normdist  [idx];

    m_particles[idx].SV1                      = m_SV1           [idx];
    m_particles[idx].SV1plusIP3D_discriminant = m_SV1plusIP3D_discriminant       [idx];
    m_particles[idx].SV1_pu                   = m_SV1_pu        [idx];
    m_particles[idx].SV1_pb                   = m_SV1_pb        [idx];
    m_particles[idx].SV1_pc                   = m_SV1_pc        [idx];
    m_particles[idx].SV1_c                    = m_SV1_c         [idx];
    m_particles[idx].SV1_cu                   = m_SV1_cu        [idx];
    m_particles[idx].SV1_NGTinSvx             = m_SV1_NGTinSvx  [idx];
    m_particles[idx].SV1_N2Tpair              = m_SV1_N2Tpair   [idx];
    m_particles[idx].SV1_masssvx              = m_SV1_masssvx   [idx];
    m_particles[idx].SV1_efracsvx             = m_SV1_efracsvx  [idx];
    m_particles[idx].SV1_normdist             = m_SV1_normdist  [idx];
    m_particles[idx].SV1_Lxy                  = m_SV1_Lxy       [idx];
    m_particles[idx].SV1_L3d                  = m_SV1_L3d       [idx];
    m_particles[idx].SV1_distmatlay           = m_SV1_distmatlay[idx];
    m_particles[idx].SV1_dR                   = m_SV1_dR        [idx];
  }

  if(m_infoSwitch.m_ipDetails){
    m_particles[idx].IP2D_pu                          = m_IP2D_pu                   [idx];
    m_particles[idx].IP2D_pb                          = m_IP2D_pb                   [idx];
    m_particles[idx].IP2D_pc                          = m_IP2D_pc                   [idx];
    m_particles[idx].IP2D                             = m_IP2D                      [idx];
    m_particles[idx].IP2D_c                           = m_IP2D_c                    [idx];
    m_particles[idx].IP2D_cu                          = m_IP2D_cu                   [idx];
    m_particles[idx].nIP2DTracks                      = m_IP2D_gradeOfTracks        [idx].size();

    //m_particles[idx].IP2D_gradeOfTracks               = m_IP2D_gradeOfTracks        [idx];
    //m_particles[idx].IP2D_flagFromV0ofTracks          = m_IP2D_flagFromV0ofTracks   [idx];
    m_particles[idx].IP2D_valD0wrtPVofTracks          = m_IP2D_valD0wrtPVofTracks   [idx];
    m_particles[idx].IP2D_sigD0wrtPVofTracks          = m_IP2D_sigD0wrtPVofTracks   [idx];
    m_particles[idx].IP2D_weightBofTracks             = m_IP2D_weightBofTracks      [idx];
    m_particles[idx].IP2D_weightCofTracks             = m_IP2D_weightCofTracks      [idx];
    m_particles[idx].IP2D_weightUofTracks             = m_IP2D_weightUofTracks      [idx];

    m_particles[idx].IP3D                             = m_IP3D                      [idx];
    m_particles[idx].IP3D_pu                          = m_IP3D_pu                   [idx];
    m_particles[idx].IP3D_pb                          = m_IP3D_pb                   [idx];
    m_particles[idx].IP3D_pc                          = m_IP3D_pc                   [idx];
    m_particles[idx].IP3D_c                           = m_IP3D_c                    [idx];
    m_particles[idx].IP3D_cu                          = m_IP3D_cu                   [idx];
    m_particles[idx].nIP3DTracks                      = m_IP3D_gradeOfTracks        [idx].size();
    //m_particles[idx].IP3D_gradeOfTracks               = m_IP3D_gradeOfTracks        [idx];
    //m_particles[idx].IP3D_flagFromV0ofTracks          = m_IP3D_flagFromV0ofTracks   [idx];
    m_particles[idx].IP3D_valD0wrtPVofTracks          = m_IP3D_valD0wrtPVofTracks   [idx];
    m_particles[idx].IP3D_sigD0wrtPVofTracks          = m_IP3D_sigD0wrtPVofTracks   [idx];
    m_particles[idx].IP3D_valZ0wrtPVofTracks          = m_IP3D_valZ0wrtPVofTracks   [idx];
    m_particles[idx].IP3D_sigZ0wrtPVofTracks          = m_IP3D_sigZ0wrtPVofTracks   [idx];
    m_particles[idx].IP3D_weightBofTracks             = m_IP3D_weightBofTracks      [idx];
    m_particles[idx].IP3D_weightCofTracks             = m_IP3D_weightCofTracks      [idx];
    m_particles[idx].IP3D_weightUofTracks             = m_IP3D_weightUofTracks      [idx];
  }

  static const std::vector<float> dummy1 = {1.};
  for(uint i=0; i<m_infoSwitch.m_sfFTagFix.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFix[i] ) 
        {
        case 30:
          m_particles[idx].isFix30       =m_btag_Fix30->m_isTag[idx];
          m_particles[idx].sfFix30       =(m_mc)?m_btag_Fix30->m_sf[idx]:dummy1;
          break;
        case 50:
          m_particles[idx].isFix50       =m_btag_Fix50->m_isTag[idx];
          m_particles[idx].sfFix50       =(m_mc)?m_btag_Fix50->m_sf[idx]:dummy1;
          break;
        case 60:
          m_particles[idx].isFix60       =m_btag_Fix60->m_isTag[idx];
          m_particles[idx].sfFix60       =(m_mc)?m_btag_Fix60->m_sf[idx]:dummy1;
          break;
        case 70: 
          m_particles[idx].isFix70       =m_btag_Fix70->m_isTag[idx];
          m_particles[idx].sfFix70       =(m_mc)?m_btag_Fix70->m_sf[idx]:dummy1;
          break;
        case 77:
          m_particles[idx].isFix77       =m_btag_Fix77->m_isTag[idx];
          m_particles[idx].sfFix77       =(m_mc)?m_btag_Fix77->m_sf[idx]:dummy1;
          break;
        case 80:
          m_particles[idx].isFix80       =m_btag_Fix80->m_isTag[idx];
          m_particles[idx].sfFix80       =(m_mc)?m_btag_Fix80->m_sf[idx]:dummy1;
          break;
        case 85:
          m_particles[idx].isFix85       =m_btag_Fix85->m_isTag [idx];
          m_particles[idx].sfFix85       =(m_mc)?m_btag_Fix85->m_sf[idx]:dummy1;
          break;
        case 90:
          m_particles[idx].isFix90       =m_btag_Fix90->m_isTag       [idx];
          m_particles[idx].sfFix90       =(m_mc)?m_btag_Fix90->m_sf[idx]:dummy1;
          break;
        }
    }

  for(uint i=0; i<m_infoSwitch.m_sfFTagFlt.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFlt[i] ) 
        {
        case 30:
          m_particles[idx].isFlt30       =m_btag_Flt30->m_isTag       [idx];
          m_particles[idx].sfFlt30       =(m_mc)?m_btag_Flt30->m_sf[idx]:dummy1;
          break;
        case 50:
          m_particles[idx].isFlt50       =m_btag_Flt50->m_isTag       [idx];
          m_particles[idx].sfFlt50       =(m_mc)?m_btag_Flt50->m_sf[idx]:dummy1;
          break;
        case 60:
          m_particles[idx].isFlt60       =m_btag_Flt60->m_isTag       [idx];
          m_particles[idx].sfFlt60       =(m_mc)?m_btag_Flt60->m_sf[idx]:dummy1;
          break;
        case 70:
          m_particles[idx].isFlt70       =m_btag_Flt70->m_isTag       [idx];
          m_particles[idx].sfFlt70       =(m_mc)?m_btag_Flt70->m_sf[idx]:dummy1;
          break;
        case 77:
          m_particles[idx].isFlt77       =m_btag_Flt77->m_isTag       [idx];
          m_particles[idx].sfFlt77       =(m_mc)?m_btag_Flt77->m_sf[idx]:dummy1;
          break;
        case 85:
          m_particles[idx].isFlt85       =m_btag_Flt85->m_isTag       [idx];
          m_particles[idx].sfFlt85       =(m_mc)?m_btag_Flt85->m_sf[idx]:dummy1;
          break;
        }
    }


  // truth
  if(m_infoSwitch.m_truth)
    {
      m_particles[idx].ConeTruthLabelID  =m_ConeTruthLabelID[idx];
      m_particles[idx].TruthCount        =m_TruthCount      [idx];
      m_particles[idx].TruthLabelDeltaR_B=m_TruthLabelDeltaR_B[idx];
      m_particles[idx].TruthLabelDeltaR_C=m_TruthLabelDeltaR_C[idx];
      m_particles[idx].TruthLabelDeltaR_T=m_TruthLabelDeltaR_T[idx];
      m_particles[idx].PartonTruthLabelID=m_PartonTruthLabelID[idx];
      m_particles[idx].GhostTruthAssociationFraction= m_GhostTruthAssociationFraction[idx];

      m_particles[idx].truth_p4.SetPtEtaPhiE(m_truth_pt [idx],
                                m_truth_eta[idx],
                                m_truth_phi[idx],
                                m_truth_E  [idx]);
    }

  // charge
  if(m_infoSwitch.m_charge)
    {
      m_particles[idx].charge=m_charge[idx];
    }

  return;
}

bool JetContainer::findBTagSF(const std::vector<int>& sfList, int workingPt)
{
  return (std::find(sfList.begin(), sfList.end(),workingPt ) != sfList.end());
}

