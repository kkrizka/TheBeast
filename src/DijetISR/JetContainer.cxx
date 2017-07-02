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
      m_rapidity=new TTreeReaderArray<float>(*reader,"rapidity");
    }

  if(m_infoSwitch.m_clean)
    {
      m_Timing                    =new TTreeReaderArray<float>(*reader,branchName("Timing"                    ).c_str());
      m_LArQuality                =new TTreeReaderArray<float>(*reader,branchName("LArQuality"                ).c_str());

      m_LArBadHVNCell             =new TTreeReaderArray<int  >(*reader,branchName("LArBadHVNCell"             ).c_str());

      m_LArQuality                =new TTreeReaderArray<float>(*reader,branchName("LArQuality"                ).c_str());
      m_HECQuality                =new TTreeReaderArray<float>(*reader,branchName("HECQuality"                ).c_str());
      m_NegativeE                 =new TTreeReaderArray<float>(*reader,branchName("NegativeE"                 ).c_str());
      m_AverageLArQF              =new TTreeReaderArray<float>(*reader,branchName("AverageLArQF"              ).c_str());
      m_BchCorrCell               =new TTreeReaderArray<float>(*reader,branchName("BchCorrCell"               ).c_str());
      m_N90Constituents           =new TTreeReaderArray<float>(*reader,branchName("N90Constituents"           ).c_str());
      m_LArBadHVEnergyFrac        =new TTreeReaderArray<float>(*reader,branchName("LArBadHVEnergyFrac"        ).c_str());
      m_OotFracClusters5          =new TTreeReaderArray<float>(*reader,branchName("OotFracClusters5"          ).c_str());
      m_OotFracClusters10         =new TTreeReaderArray<float>(*reader,branchName("OotFracClusters10"         ).c_str());
      m_LeadingClusterPt          =new TTreeReaderArray<float>(*reader,branchName("LeadingClusterPt"          ).c_str());
      m_LeadingClusterSecondLambda=new TTreeReaderArray<float>(*reader,branchName("LeadingClusterSecondLambda").c_str());
      m_LeadingClusterCenterLambda=new TTreeReaderArray<float>(*reader,branchName("LeadingClusterCenterLambda").c_str());
      m_LeadingClusterSecondR     =new TTreeReaderArray<float>(*reader,branchName("LeadingClusterSecondR"     ).c_str());
      m_clean_passLooseBad        =new TTreeReaderArray<int  >(*reader,branchName("clean_passLooseBad"        ).c_str());
      m_clean_passLooseBadUgly    =new TTreeReaderArray<int  >(*reader,branchName("clean_passLooseBadUgly"    ).c_str());
      m_clean_passTightBad        =new TTreeReaderArray<int  >(*reader,branchName("clean_passTightBad"        ).c_str());
      m_clean_passTightBadUgly    =new TTreeReaderArray<int  >(*reader,branchName("clean_passTightBadUgly"    ).c_str());
    }

  if(m_infoSwitch.m_energy)
    {
      m_HECFrac              =new TTreeReaderArray<float>(*reader,branchName("HECFrac"              ).c_str());
      m_EMFrac               =new TTreeReaderArray<float>(*reader,branchName("EMFrac"               ).c_str());
      m_CentroidR            =new TTreeReaderArray<float>(*reader,branchName("CentroidR"            ).c_str());
      m_FracSamplingMax      =new TTreeReaderArray<float>(*reader,branchName("FracSamplingMax"      ).c_str());
      m_FracSamplingMaxIndex =new TTreeReaderArray<float>(*reader,branchName("FracSamplingMaxIndex" ).c_str());
      m_LowEtConstituentsFrac=new TTreeReaderArray<float>(*reader,branchName("LowEtConstituentsFrac").c_str());
      m_GhostMuonSegmentCount=new TTreeReaderArray<float>(*reader,branchName("GhostMuonSegmentCount").c_str());
      m_Width                =new TTreeReaderArray<float>(*reader,branchName("Width"                ).c_str());
    }

  if(m_infoSwitch.m_trackPV)
    {
      m_NumTrkPt1000PV    =new TTreeReaderArray<float>(*reader,branchName("NumTrkPt1000PV"    ).c_str());
      m_SumPtTrkPt1000PV  =new TTreeReaderArray<float>(*reader,branchName("SumPtTrkPt1000PV"  ).c_str());
      m_TrackWidthPt1000PV=new TTreeReaderArray<float>(*reader,branchName("TrackWidthPt1000PV").c_str());
      m_NumTrkPt500PV     =new TTreeReaderArray<float>(*reader,branchName("NumTrkPt500PV"     ).c_str());
      m_SumPtTrkPt500PV   =new TTreeReaderArray<float>(*reader,branchName("SumPtTrkPt500PV"   ).c_str());
      m_TrackWidthPt500PV =new TTreeReaderArray<float>(*reader,branchName("TrackWidthPt500PV" ).c_str());
      m_JVFPV             =new TTreeReaderArray<float>(*reader,branchName("JVFPV"             ).c_str());
    }

  if(m_infoSwitch.m_trackAll || m_infoSwitch.m_trackPV)
    {
      m_Jvt       =new TTreeReaderArray<float>(*reader,branchName("Jvt"       ).c_str());
      m_JvtJvfcorr=new TTreeReaderArray<float>(*reader,branchName("JvtJvfcorr").c_str());
      m_JvtRpt    =new TTreeReaderArray<float>(*reader,branchName("JvtRpt"    ).c_str());
    }

  if(m_infoSwitch.m_JVC)
    {
      m_JetVertexCharge_discriminant=new TTreeReaderArray<double>(*reader,branchName("JetVertexCharge_discriminant").c_str());
    }

  if(m_infoSwitch.m_flavTag || m_infoSwitch.m_flavTagHLT)
    {
      m_MV2c00                    =new TTreeReaderArray<float>(*reader,branchName("MV2c00"                    ).c_str());
      m_MV2c10                    =new TTreeReaderArray<float>(*reader,branchName("MV2c10"                    ).c_str());
      m_MV2c20                    =new TTreeReaderArray<float>(*reader,branchName("MV2c20"                    ).c_str());
      m_MV2c100                   =new TTreeReaderArray<float>(*reader,branchName("MV2c100"                   ).c_str());
      m_HadronConeExclTruthLabelID=new TTreeReaderArray<int  >(*reader,branchName("HadronConeExclTruthLabelID").c_str());

      if(tagger == "MV2c20")  m_MV2 = m_MV2c20;
      if(tagger == "MV2c10")  m_MV2 = m_MV2c10;

    }

  if(m_infoSwitch.m_flavTagHLT)
    {
      m_vtxHadDummy   =new TTreeReaderArray<float>(*reader,branchName("vtxHadDummy"   ).c_str());
      m_bs_online_vx  =new TTreeReaderArray<float>(*reader,branchName("bs_online_vx"  ).c_str());
      m_bs_online_vy  =new TTreeReaderArray<float>(*reader,branchName("bs_online_vy"  ).c_str());
      m_bs_online_vz  =new TTreeReaderArray<float>(*reader,branchName("bs_online_vz"  ).c_str());
                     
      m_vtx_offline_x0=new TTreeReaderArray<float>(*reader,branchName("vtx_offline_x0").c_str());
      m_vtx_offline_y0=new TTreeReaderArray<float>(*reader,branchName("vtx_offline_y0").c_str());
      m_vtx_offline_z0=new TTreeReaderArray<float>(*reader,branchName("vtx_offline_z0").c_str());
                     
      m_vtx_online_x0 =new TTreeReaderArray<float>(*reader,branchName("vtx_online_x0" ).c_str());
      m_vtx_online_y0 =new TTreeReaderArray<float>(*reader,branchName("vtx_online_y0" ).c_str());
      m_vtx_online_z0 =new TTreeReaderArray<float>(*reader,branchName("vtx_online_z0" ).c_str());
    }

  if(m_infoSwitch.m_jetFitterDetails)
    {
      m_JetFitter_nVTX          =new TTreeReaderArray<float>(*reader,branchName("JetFitter_nVTX"          ).c_str());
      m_JetFitter_nSingleTracks =new TTreeReaderArray<float>(*reader,branchName("JetFitter_nSingleTracks" ).c_str());
      m_JetFitter_nTracksAtVtx  =new TTreeReaderArray<float>(*reader,branchName("JetFitter_nTracksAtVtx"  ).c_str());
      m_JetFitter_mass          =new TTreeReaderArray<float>(*reader,branchName("JetFitter_mass"          ).c_str());
      m_JetFitter_energyFraction=new TTreeReaderArray<float>(*reader,branchName("JetFitter_energyFraction").c_str());
      m_JetFitter_significance3d=new TTreeReaderArray<float>(*reader,branchName("JetFitter_significance3d").c_str());
      m_JetFitter_deltaeta      =new TTreeReaderArray<float>(*reader,branchName("JetFitter_deltaeta"      ).c_str());
      m_JetFitter_deltaphi      =new TTreeReaderArray<float>(*reader,branchName("JetFitter_deltaphi"      ).c_str());
      m_JetFitter_N2Tpar        =new TTreeReaderArray<float>(*reader,branchName("JetFitter_N2Tpair"       ).c_str());
    }

    if( m_infoSwitch.m_svDetails){

      m_SV0                     =new TTreeReaderArray<float>(*reader,branchName("SV0"           ).c_str());
      m_SV0_NGTinSvx            =new TTreeReaderArray<float>(*reader,branchName("SV0_NGTinSvx"  ).c_str());
      m_SV0_N2Tpair             =new TTreeReaderArray<float>(*reader,branchName("SV0_N2Tpair"   ).c_str());
      m_SV0_masssvx             =new TTreeReaderArray<float>(*reader,branchName("SV0_massvx"    ).c_str());
      m_SV0_efracsvx            =new TTreeReaderArray<float>(*reader,branchName("SV0_efracsvx"  ).c_str());
      m_SV0_normdist            =new TTreeReaderArray<float>(*reader,branchName("SV0_normdist"  ).c_str());

      m_SV1                     =new TTreeReaderArray<float>(*reader,branchName("SV1"           ).c_str());
      m_SV1plusIP3D_discriminant=new TTreeReaderArray<float>(*reader,branchName("SV1IP3D"       ).c_str());
      m_SV1_pu                  =new TTreeReaderArray<float>(*reader,branchName("SV1_pu"        ).c_str());
      m_SV1_pb                  =new TTreeReaderArray<float>(*reader,branchName("SV1_pb"        ).c_str());
      m_SV1_pc                  =new TTreeReaderArray<float>(*reader,branchName("SV1_pc"        ).c_str());
      m_SV1_c                   =new TTreeReaderArray<float>(*reader,branchName("SV1_c"         ).c_str());
      m_SV1_cu                  =new TTreeReaderArray<float>(*reader,branchName("SV1_cu"        ).c_str());
      m_SV1_NGTinSvx            =new TTreeReaderArray<float>(*reader,branchName("SV1_NGTinSvx"  ).c_str());
      m_SV1_N2Tpair             =new TTreeReaderArray<float>(*reader,branchName("SV1_N2Tpair"   ).c_str());
      m_SV1_masssvx             =new TTreeReaderArray<float>(*reader,branchName("SV1_massvx"    ).c_str());
      m_SV1_efracsvx            =new TTreeReaderArray<float>(*reader,branchName("SV1_efracsvx"  ).c_str());
      m_SV1_normdist            =new TTreeReaderArray<float>(*reader,branchName("SV1_normdist"  ).c_str());
      m_SV1_Lxy                 =new TTreeReaderArray<float>(*reader,branchName("SV1_Lxy"       ).c_str());
      m_SV1_L3d                 =new TTreeReaderArray<float>(*reader,branchName("SV1_L3d"       ).c_str());
      m_SV1_distmatlay          =new TTreeReaderArray<float>(*reader,branchName("SV1_distmatlay").c_str());
      m_SV1_dR                  =new TTreeReaderArray<float>(*reader,branchName("SV1_dR"        ).c_str());
    }

    if( m_infoSwitch.m_ipDetails){    

      m_IP2D_pu                =new TTreeReaderArray<float>             (*reader, branchName("IP2D_pu"                ).c_str());
      m_IP2D_pb                =new TTreeReaderArray<float>             (*reader, branchName("IP2D_pb"                ).c_str());
      m_IP2D_pc                =new TTreeReaderArray<float>             (*reader, branchName("IP2D_pc"                ).c_str());
      m_IP2D                   =new TTreeReaderArray<float>             (*reader, branchName("IP2D"                   ).c_str());
      m_IP2D_c                 =new TTreeReaderArray<float>             (*reader, branchName("IP2D_c"                 ).c_str());
      m_IP2D_cu                =new TTreeReaderArray<float>             (*reader, branchName("IP2D_cu"                ).c_str());
      m_IP2D_gradeOfTracks     =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_gradeOfTracks"     ).c_str());
      m_IP2D_flagFromV0ofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_flagFromV0ofTracks").c_str());
      m_IP2D_valD0wrtPVofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_valD0wrtPVofTracks").c_str());
      m_IP2D_sigD0wrtPVofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_sigD0wrtPVofTracks").c_str());
      m_IP2D_weightBofTracks   =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_weightBofTracks"   ).c_str());
      m_IP2D_weightCofTracks   =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_weightCofTracks"   ).c_str());
      m_IP2D_weightUofTracks   =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP2D_weightUofTracks"   ).c_str());

      m_IP3D                   =new TTreeReaderArray<float>             (*reader, branchName("IP3D"   ).c_str());
      m_IP3D_pu                =new TTreeReaderArray<float>             (*reader, branchName("IP3D_pu").c_str());
      m_IP3D_pb                =new TTreeReaderArray<float>             (*reader, branchName("IP3D_pb").c_str());
      m_IP3D_pc                =new TTreeReaderArray<float>             (*reader, branchName("IP3D_pc").c_str());
      m_IP3D_c                 =new TTreeReaderArray<float>             (*reader, branchName("IP3D_c" ).c_str());
      m_IP3D_cu                =new TTreeReaderArray<float>             (*reader, branchName("IP3D_cu").c_str());
      m_IP3D_gradeOfTracks     =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_gradeOfTracks"     ).c_str());
      m_IP3D_flagFromV0ofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_flagFromV0ofTracks").c_str());
      m_IP3D_valD0wrtPVofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_valD0wrtPVofTracks").c_str());
      m_IP3D_sigD0wrtPVofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_sigD0wrtPVofTracks").c_str());
      m_IP3D_valZ0wrtPVofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_valZ0wrtPVofTracks").c_str());
      m_IP3D_sigZ0wrtPVofTracks=new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_sigZ0wrtPVofTracks").c_str());
      m_IP3D_weightBofTracks   =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_weightBofTracks"   ).c_str());
      m_IP3D_weightCofTracks   =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_weightCofTracks"   ).c_str());
      m_IP3D_weightUofTracks   =new TTreeReaderArray<std::vector<float>>(*reader, branchName("IP3D_weightUofTracks"   ).c_str());

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
      m_ConeTruthLabelID  =new TTreeReaderArray<int  >(*reader,branchName("ConeTruthLabelID"  ).c_str());
      m_TruthCount        =new TTreeReaderArray<int  >(*reader,branchName("TruthCount"        ).c_str());
      m_TruthLabelDeltaR_B=new TTreeReaderArray<float>(*reader,branchName("TruthLabelDeltaR_B").c_str());
      m_TruthLabelDeltaR_C=new TTreeReaderArray<float>(*reader,branchName("TruthLabelDeltaR_C").c_str());
      m_TruthLabelDeltaR_T=new TTreeReaderArray<float>(*reader,branchName("TruthLabelDeltaR_T").c_str());
      m_PartonTruthLabelID=new TTreeReaderArray<int  >(*reader,branchName("PartonTruthLabelID").c_str());
      m_GhostTruthAssociationFraction=new TTreeReaderArray<float>(*reader,branchName("GhostTruthAssociationFraction").c_str());
      m_truth_E  =new TTreeReaderArray<float>(*reader,branchName("truth_E"  ).c_str());
      m_truth_pt =new TTreeReaderArray<float>(*reader,branchName("truth_pt" ).c_str());
      m_truth_phi=new TTreeReaderArray<float>(*reader,branchName("truth_phi").c_str());
      m_truth_eta=new TTreeReaderArray<float>(*reader,branchName("truth_eta").c_str());
    }

  // charge
  if(m_infoSwitch.m_charge)
    {
      m_charge=new TTreeReaderArray<double>(*reader,branchName("charge").c_str());
    }
}

void JetContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);  

  if(m_infoSwitch.m_rapidity)
    {
      m_particles[idx].rapidity                  =m_rapidity                  ->At(idx);
    }

  if(m_infoSwitch.m_clean)
    {
      m_particles[idx].Timing                    =m_Timing                    ->At(idx);
      m_particles[idx].LArQuality                =m_LArQuality                ->At(idx);
      m_particles[idx].HECQuality                =m_HECQuality                ->At(idx);
      m_particles[idx].NegativeE                 =m_NegativeE                 ->At(idx);
      m_particles[idx].AverageLArQF              =m_AverageLArQF              ->At(idx);
      m_particles[idx].BchCorrCell               =m_BchCorrCell               ->At(idx);
      m_particles[idx].N90Constituents           =m_N90Constituents           ->At(idx);
      m_particles[idx].LArBadHVEnergyFrac        =m_LArBadHVEnergyFrac        ->At(idx);
      m_particles[idx].LArBadHVNCell             =m_LArBadHVNCell             ->At(idx);
      m_particles[idx].OotFracClusters5          =m_OotFracClusters5          ->At(idx);
      m_particles[idx].OotFracClusters10         =m_OotFracClusters10         ->At(idx);
      m_particles[idx].LeadingClusterPt          =m_LeadingClusterPt          ->At(idx);
      m_particles[idx].LeadingClusterSecondLambda=m_LeadingClusterSecondLambda->At(idx);
      m_particles[idx].LeadingClusterCenterLambda=m_LeadingClusterCenterLambda->At(idx);
      m_particles[idx].LeadingClusterSecondR     =m_LeadingClusterSecondR     ->At(idx);
      m_particles[idx].clean_passLooseBad        =m_clean_passLooseBad        ->At(idx);
      m_particles[idx].clean_passLooseBadUgly    =m_clean_passLooseBadUgly    ->At(idx);
      m_particles[idx].clean_passTightBad        =m_clean_passTightBad        ->At(idx);
      m_particles[idx].clean_passTightBadUgly    =m_clean_passTightBadUgly    ->At(idx);
    }

  if(m_infoSwitch.m_energy)
    {
      m_particles[idx].HECFrac              =m_HECFrac              ->At(idx);
      m_particles[idx].EMFrac               =m_EMFrac               ->At(idx);
      m_particles[idx].CentroidR            =m_CentroidR            ->At(idx);
      m_particles[idx].FracSamplingMax      =m_FracSamplingMax      ->At(idx);
      m_particles[idx].FracSamplingMaxIndex =m_FracSamplingMaxIndex ->At(idx);
      m_particles[idx].LowEtConstituentsFrac=m_LowEtConstituentsFrac->At(idx);
      m_particles[idx].GhostMuonSegmentCount=m_GhostMuonSegmentCount->At(idx);
      m_particles[idx].Width                =m_Width                ->At(idx);
    }
  
  if(m_infoSwitch.m_trackPV)
    {
      m_particles[idx].NumTrkPt1000PV    =m_NumTrkPt1000PV    ->At(idx);
      m_particles[idx].SumPtTrkPt1000PV  =m_SumPtTrkPt1000PV  ->At(idx);
      m_particles[idx].TrackWidthPt1000PV=m_TrackWidthPt1000PV->At(idx);
      m_particles[idx].NumTrkPt500PV     =m_NumTrkPt500PV     ->At(idx);
      m_particles[idx].SumPtTrkPt500PV   =m_SumPtTrkPt500PV   ->At(idx);
      m_particles[idx].TrackWidthPt500PV =m_TrackWidthPt500PV ->At(idx);
      m_particles[idx].JVFPV             =m_JVFPV             ->At(idx);
    }

  if(m_infoSwitch.m_trackPV || m_infoSwitch.m_trackAll)
    {
      m_particles[idx].Jvt       =m_Jvt       ->At(idx);
      m_particles[idx].JvtJvfcorr=m_JvtJvfcorr->At(idx);
      m_particles[idx].JvtRpt    =m_JvtRpt    ->At(idx);
    }
  
  if( m_infoSwitch.m_JVC ) {
    m_particles[idx].JetVertexCharge_discriminant = m_JetVertexCharge_discriminant->At(idx);
  }

  if(m_infoSwitch.m_flavTag  || m_infoSwitch.m_flavTagHLT)
    {
      m_particles[idx].MV2c00                    =m_MV2c00               ->At(idx);
      m_particles[idx].MV2c10                    =m_MV2c10               ->At(idx);
      m_particles[idx].MV2c20                    =m_MV2c20               ->At(idx);
      m_particles[idx].MV2c100                   =m_MV2c100              ->At(idx);
      m_particles[idx].MV2                       =m_MV2                  ->At(idx);

      m_particles[idx].HadronConeExclTruthLabelID=m_HadronConeExclTruthLabelID->At(idx);
    }


  if(m_infoSwitch.m_flavTagHLT)
    {
      m_particles[idx].bs_online_vx                      =m_bs_online_vx                  ->At(idx);
      m_particles[idx].bs_online_vy                      =m_bs_online_vy                  ->At(idx);
      m_particles[idx].bs_online_vz                      =m_bs_online_vz                  ->At(idx);
      m_particles[idx].vtxHadDummy                       =m_vtxHadDummy                   ->At(idx);
      m_particles[idx].vtx_offline_x0                    =m_vtx_offline_x0                ->At(idx);
      m_particles[idx].vtx_offline_y0                    =m_vtx_offline_y0                ->At(idx);
      m_particles[idx].vtx_offline_z0                    =m_vtx_offline_z0                ->At(idx);

      m_particles[idx].vtx_online_x0                     =m_vtx_online_x0                 ->At(idx);
      m_particles[idx].vtx_online_y0                     =m_vtx_online_y0                 ->At(idx);
      m_particles[idx].vtx_online_z0                     =m_vtx_online_z0                 ->At(idx);

    }

  if(m_infoSwitch.m_jetFitterDetails)
    {
      m_particles[idx].JetFitter_nVTX                  =m_JetFitter_nVTX           ->At(idx);
      m_particles[idx].JetFitter_nSingleTracks         =m_JetFitter_nSingleTracks  ->At(idx);
      m_particles[idx].JetFitter_nTracksAtVtx          =m_JetFitter_nTracksAtVtx   ->At(idx);
      m_particles[idx].JetFitter_mass                  =m_JetFitter_mass           ->At(idx);
      m_particles[idx].JetFitter_energyFraction        =m_JetFitter_energyFraction ->At(idx);
      m_particles[idx].JetFitter_significance3d        =m_JetFitter_significance3d ->At(idx);
      m_particles[idx].JetFitter_deltaeta              =m_JetFitter_deltaeta       ->At(idx);
      m_particles[idx].JetFitter_deltaphi              =m_JetFitter_deltaphi       ->At(idx);
      m_particles[idx].JetFitter_N2Tpar                =m_JetFitter_N2Tpar         ->At(idx);

    }

  if(m_infoSwitch.m_svDetails){

    m_particles[idx].SV0                      = m_SV0           ->At(idx);
    m_particles[idx].SV0_NGTinSvx             = m_SV0_NGTinSvx  ->At(idx);
    m_particles[idx].SV0_N2Tpair              = m_SV0_N2Tpair   ->At(idx);
    m_particles[idx].SV0_masssvx              = m_SV0_masssvx   ->At(idx);
    m_particles[idx].SV0_efracsvx             = m_SV0_efracsvx  ->At(idx);
    m_particles[idx].SV0_normdist             = m_SV0_normdist  ->At(idx);

    m_particles[idx].SV1                      = m_SV1           ->At(idx);
    m_particles[idx].SV1plusIP3D_discriminant = m_SV1plusIP3D_discriminant       ->At(idx);
    m_particles[idx].SV1_pu                   = m_SV1_pu        ->At(idx);
    m_particles[idx].SV1_pb                   = m_SV1_pb        ->At(idx);
    m_particles[idx].SV1_pc                   = m_SV1_pc        ->At(idx);
    m_particles[idx].SV1_c                    = m_SV1_c         ->At(idx);
    m_particles[idx].SV1_cu                   = m_SV1_cu        ->At(idx);
    m_particles[idx].SV1_NGTinSvx             = m_SV1_NGTinSvx  ->At(idx);
    m_particles[idx].SV1_N2Tpair              = m_SV1_N2Tpair   ->At(idx);
    m_particles[idx].SV1_masssvx              = m_SV1_masssvx   ->At(idx);
    m_particles[idx].SV1_efracsvx             = m_SV1_efracsvx  ->At(idx);
    m_particles[idx].SV1_normdist             = m_SV1_normdist  ->At(idx);
    m_particles[idx].SV1_Lxy                  = m_SV1_Lxy       ->At(idx);
    m_particles[idx].SV1_L3d                  = m_SV1_L3d       ->At(idx);
    m_particles[idx].SV1_distmatlay           = m_SV1_distmatlay->At(idx);
    m_particles[idx].SV1_dR                   = m_SV1_dR        ->At(idx);
  }

  if(m_infoSwitch.m_ipDetails){
    m_particles[idx].IP2D_pu                          = m_IP2D_pu                   ->At(idx);
    m_particles[idx].IP2D_pb                          = m_IP2D_pb                   ->At(idx);
    m_particles[idx].IP2D_pc                          = m_IP2D_pc                   ->At(idx);
    m_particles[idx].IP2D                             = m_IP2D                      ->At(idx);
    m_particles[idx].IP2D_c                           = m_IP2D_c                    ->At(idx);
    m_particles[idx].IP2D_cu                          = m_IP2D_cu                   ->At(idx);
    m_particles[idx].nIP2DTracks                      = m_IP2D_gradeOfTracks        ->At(idx).size();

    //m_particles[idx].IP2D_gradeOfTracks               = m_IP2D_gradeOfTracks        ->At(idx);
    //m_particles[idx].IP2D_flagFromV0ofTracks          = m_IP2D_flagFromV0ofTracks   ->At(idx);
    m_particles[idx].IP2D_valD0wrtPVofTracks          = m_IP2D_valD0wrtPVofTracks   ->At(idx);
    m_particles[idx].IP2D_sigD0wrtPVofTracks          = m_IP2D_sigD0wrtPVofTracks   ->At(idx);
    m_particles[idx].IP2D_weightBofTracks             = m_IP2D_weightBofTracks      ->At(idx);
    m_particles[idx].IP2D_weightCofTracks             = m_IP2D_weightCofTracks      ->At(idx);
    m_particles[idx].IP2D_weightUofTracks             = m_IP2D_weightUofTracks      ->At(idx);

    m_particles[idx].IP3D                             = m_IP3D                      ->At(idx);
    m_particles[idx].IP3D_pu                          = m_IP3D_pu                   ->At(idx);
    m_particles[idx].IP3D_pb                          = m_IP3D_pb                   ->At(idx);
    m_particles[idx].IP3D_pc                          = m_IP3D_pc                   ->At(idx);
    m_particles[idx].IP3D_c                           = m_IP3D_c                    ->At(idx);
    m_particles[idx].IP3D_cu                          = m_IP3D_cu                   ->At(idx);
    m_particles[idx].nIP3DTracks                      = m_IP3D_gradeOfTracks        ->At(idx).size();
    //m_particles[idx].IP3D_gradeOfTracks               = m_IP3D_gradeOfTracks        ->At(idx);
    //m_particles[idx].IP3D_flagFromV0ofTracks          = m_IP3D_flagFromV0ofTracks   ->At(idx);
    m_particles[idx].IP3D_valD0wrtPVofTracks          = m_IP3D_valD0wrtPVofTracks   ->At(idx);
    m_particles[idx].IP3D_sigD0wrtPVofTracks          = m_IP3D_sigD0wrtPVofTracks   ->At(idx);
    m_particles[idx].IP3D_valZ0wrtPVofTracks          = m_IP3D_valZ0wrtPVofTracks   ->At(idx);
    m_particles[idx].IP3D_sigZ0wrtPVofTracks          = m_IP3D_sigZ0wrtPVofTracks   ->At(idx);
    m_particles[idx].IP3D_weightBofTracks             = m_IP3D_weightBofTracks      ->At(idx);
    m_particles[idx].IP3D_weightCofTracks             = m_IP3D_weightCofTracks      ->At(idx);
    m_particles[idx].IP3D_weightUofTracks             = m_IP3D_weightUofTracks      ->At(idx);
  }

  static const std::vector<float> dummy1 = {1.};
  for(uint i=0; i<m_infoSwitch.m_sfFTagFix.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFix[i] ) 
        {
        case 30:
          m_particles[idx].isFix30       =m_btag_Fix30->m_isTag->At(idx);
          m_particles[idx].sfFix30       =(m_mc)?m_btag_Fix30->m_sf->At(idx):dummy1;
          break;
        case 50:
          m_particles[idx].isFix50       =m_btag_Fix50->m_isTag->At(idx);
          m_particles[idx].sfFix50       =(m_mc)?m_btag_Fix50->m_sf->At(idx):dummy1;
          break;
        case 60:
          m_particles[idx].isFix60       =m_btag_Fix60->m_isTag->At(idx);
          m_particles[idx].sfFix60       =(m_mc)?m_btag_Fix60->m_sf->At(idx):dummy1;
          break;
        case 70: 
          m_particles[idx].isFix70       =m_btag_Fix70->m_isTag->At(idx);
          m_particles[idx].sfFix70       =(m_mc)?m_btag_Fix70->m_sf->At(idx):dummy1;
          break;
        case 77:
          m_particles[idx].isFix77       =m_btag_Fix77->m_isTag->At(idx);
          m_particles[idx].sfFix77       =(m_mc)?m_btag_Fix77->m_sf->At(idx):dummy1;
          break;
        case 80:
          m_particles[idx].isFix80       =m_btag_Fix80->m_isTag->At(idx);
          m_particles[idx].sfFix80       =(m_mc)?m_btag_Fix80->m_sf->At(idx):dummy1;
          break;
        case 85:
          m_particles[idx].isFix85       =m_btag_Fix85->m_isTag ->At(idx);
          m_particles[idx].sfFix85       =(m_mc)?m_btag_Fix85->m_sf->At(idx):dummy1;
          break;
        case 90:
          m_particles[idx].isFix90       =m_btag_Fix90->m_isTag       ->At(idx);
          m_particles[idx].sfFix90       =(m_mc)?m_btag_Fix90->m_sf->At(idx):dummy1;
          break;
        }
    }

  for(uint i=0; i<m_infoSwitch.m_sfFTagFlt.size(); i++ ) 
    {
      switch( m_infoSwitch.m_sfFTagFlt[i] ) 
        {
        case 30:
          m_particles[idx].isFlt30       =m_btag_Flt30->m_isTag       ->At(idx);
          m_particles[idx].sfFlt30       =(m_mc)?m_btag_Flt30->m_sf->At(idx):dummy1;
          break;
        case 50:
          m_particles[idx].isFlt50       =m_btag_Flt50->m_isTag       ->At(idx);
          m_particles[idx].sfFlt50       =(m_mc)?m_btag_Flt50->m_sf->At(idx):dummy1;
          break;
        case 60:
          m_particles[idx].isFlt60       =m_btag_Flt60->m_isTag       ->At(idx);
          m_particles[idx].sfFlt60       =(m_mc)?m_btag_Flt60->m_sf->At(idx):dummy1;
          break;
        case 70:
          m_particles[idx].isFlt70       =m_btag_Flt70->m_isTag       ->At(idx);
          m_particles[idx].sfFlt70       =(m_mc)?m_btag_Flt70->m_sf->At(idx):dummy1;
          break;
        case 77:
          m_particles[idx].isFlt77       =m_btag_Flt77->m_isTag       ->At(idx);
          m_particles[idx].sfFlt77       =(m_mc)?m_btag_Flt77->m_sf->At(idx):dummy1;
          break;
        case 85:
          m_particles[idx].isFlt85       =m_btag_Flt85->m_isTag       ->At(idx);
          m_particles[idx].sfFlt85       =(m_mc)?m_btag_Flt85->m_sf->At(idx):dummy1;
          break;
        }
    }


  // truth
  if(m_infoSwitch.m_truth)
    {
      m_particles[idx].ConeTruthLabelID  =m_ConeTruthLabelID->At(idx);
      m_particles[idx].TruthCount        =m_TruthCount      ->At(idx);
      m_particles[idx].TruthLabelDeltaR_B=m_TruthLabelDeltaR_B->At(idx);
      m_particles[idx].TruthLabelDeltaR_C=m_TruthLabelDeltaR_C->At(idx);
      m_particles[idx].TruthLabelDeltaR_T=m_TruthLabelDeltaR_T->At(idx);
      m_particles[idx].PartonTruthLabelID=m_PartonTruthLabelID->At(idx);
      m_particles[idx].GhostTruthAssociationFraction= m_GhostTruthAssociationFraction->At(idx);

      m_particles[idx].truth_p4.SetPtEtaPhiE(m_truth_pt ->At(idx),
                                m_truth_eta->At(idx),
                                m_truth_phi->At(idx),
                                m_truth_E  ->At(idx));
    }

  // charge
  if(m_infoSwitch.m_charge)
    {
      m_particles[idx].charge=m_charge->At(idx);
    }

  return;
}

bool JetContainer::findBTagSF(const std::vector<int>& sfList, int workingPt)
{
  return (std::find(sfList.begin(), sfList.end(),workingPt ) != sfList.end());
}

