#include "MuonContainer.h"


MuonContainer::MuonContainer(const std::string& name, const std::string& detailStr, float units, bool mc)
  : ParticleContainer(name, detailStr, units, mc, true)
{ }

MuonContainer::~MuonContainer()
{ }

void MuonContainer::setReader(TTreeReader *reader)
{
  //
  // Connect branches
  ParticleContainer::setReader(reader);

  if ( m_infoSwitch.m_trigger )
    {
      m_isTrigMatched       =TTreeReaderArray<int             >(*reader, branchName("isTrigMatched"       ).c_str());
      m_isTrigMatchedToChain=TTreeReaderArray<std::vector<int>>(*reader, branchName("isTrigMatchedToChain").c_str());
      m_listTrigChains      =TTreeReaderArray<std::string     >(*reader, branchName("listTrigChains"      ).c_str());
    }

  if ( m_infoSwitch.m_isolation )
    {
      m_isIsolated_LooseTrackOnly          =TTreeReaderArray<int  >(*reader, branchName("isIsolated_LooseTrackOnly"          ).c_str());
      m_isIsolated_Loose                   =TTreeReaderArray<int  >(*reader, branchName("isIsolated_Loose"                   ).c_str());
      m_isIsolated_Tight                   =TTreeReaderArray<int  >(*reader, branchName("isIsolated_Tight"                   ).c_str());
      m_isIsolated_Gradient                =TTreeReaderArray<int  >(*reader, branchName("isIsolated_Gradient"                ).c_str());
      m_isIsolated_GradientLoose           =TTreeReaderArray<int  >(*reader, branchName("isIsolated_GradientLoose"           ).c_str());
      m_isIsolated_FixedCutLoose           =TTreeReaderArray<int  >(*reader, branchName("isIsolated_FixedCutLoose"           ).c_str());
      m_isIsolated_FixedCutTightTrackOnly  =TTreeReaderArray<int  >(*reader, branchName("isIsolated_FixedCutTightTrackOnly"  ).c_str());
      m_isIsolated_UserDefinedFixEfficiency=TTreeReaderArray<int  >(*reader, branchName("isIsolated_UserDefinedFixEfficiency").c_str());
      m_isIsolated_UserDefinedCut          =TTreeReaderArray<int  >(*reader, branchName("isIsolated_UserDefinedCut"          ).c_str());
      m_ptcone20                           =TTreeReaderArray<float>(*reader, branchName("ptcone20"                           ).c_str());
      m_ptcone30                           =TTreeReaderArray<float>(*reader, branchName("ptcone30"                           ).c_str());
      m_ptcone40                           =TTreeReaderArray<float>(*reader, branchName("ptcone40"                           ).c_str());
      m_ptvarcone20                        =TTreeReaderArray<float>(*reader, branchName("ptvarcone20"                        ).c_str());
      m_ptvarcone30                        =TTreeReaderArray<float>(*reader, branchName("ptvarcone30"                        ).c_str());
      m_ptvarcone40                        =TTreeReaderArray<float>(*reader, branchName("ptvarcone40"                        ).c_str());
      m_topoetcone20                       =TTreeReaderArray<float>(*reader, branchName("topoetcone20"                       ).c_str());
      m_topoetcone30                       =TTreeReaderArray<float>(*reader, branchName("topoetcone30"                       ).c_str());
      m_topoetcone40                       =TTreeReaderArray<float>(*reader, branchName("topoetcone40"                       ).c_str());
    }

  if ( m_infoSwitch.m_effSF && m_mc )
    {
      for (auto& reco : m_infoSwitch.m_recoWPs)
	{
	  std::string recoEffSF = "muon_RecoEff_SF_" + reco; 
	  m_RecoEff_SF[ reco ] = TTreeReaderArray<std::vector<float>>( *reader, recoEffSF.c_str() );
	}

      for (auto& isol : m_infoSwitch.m_isolWPs)
	{
	  std::string isolEffSF = "muon_IsoEff_SF_" + isol; 
	  m_IsoEff_SF[ isol ]  = TTreeReaderArray<std::vector<float>>( *reader, isolEffSF.c_str() );
	}

      for (auto& trig : m_infoSwitch.m_trigWPs)
	{
	  std::string trigEffSF = "muon_TrigEff_SF_" + trig; 
	  m_TrigEff_SF[ trig ] = TTreeReaderArray<std::vector<float>>( *reader, trigEffSF.c_str() );


	  std::string trigMCEff = "muon_TrigMCEff_" + trig;
	  m_TrigMCEff[ trig ]  = TTreeReaderArray<std::vector<float>>( *reader, trigMCEff.c_str() );
	}

      m_TTVAEff_SF=TTreeReaderArray<std::vector<float> >(*reader, branchName("TTVAEff_SF").c_str());
    }

  if ( m_infoSwitch.m_quality )
    {
      m_isVeryLoose=TTreeReaderArray<int  >(*reader, branchName("isVeryLoose").c_str());
      m_isLoose    =TTreeReaderArray<int  >(*reader, branchName("isLoose"    ).c_str());
      m_isMedium   =TTreeReaderArray<int  >(*reader, branchName("isMedium"   ).c_str());
      m_isTight    =TTreeReaderArray<int  >(*reader, branchName("isTight"    ).c_str());
    }

  if ( m_infoSwitch.m_trackparams )
    {
      m_trkd0        =TTreeReaderArray<float>(*reader, branchName("trkd0"        ).c_str());
      m_trkd0sig     =TTreeReaderArray<float>(*reader, branchName("trkd0sig"     ).c_str());
      m_trkz0        =TTreeReaderArray<float>(*reader, branchName("trkz0"        ).c_str());
      m_trkz0sintheta=TTreeReaderArray<float>(*reader, branchName("trkz0sintheta").c_str());
      m_trkphi0      =TTreeReaderArray<float>(*reader, branchName("trkphi0"      ).c_str());
      m_trktheta     =TTreeReaderArray<float>(*reader, branchName("trktheta"     ).c_str());
      m_trkcharge    =TTreeReaderArray<float>(*reader, branchName("trkcharge"    ).c_str());
      m_trkqOverP    =TTreeReaderArray<float>(*reader, branchName("trkqOverP"    ).c_str());
    }

  if ( m_infoSwitch.m_trackhitcont )
    {
      m_trknSiHits             =TTreeReaderArray<int  >(*reader, branchName("trknSiHits"             ).c_str());
      m_trknPixHits            =TTreeReaderArray<int  >(*reader, branchName("trknPixHits"            ).c_str());
      m_trknPixHoles           =TTreeReaderArray<int  >(*reader, branchName("trknPixHoles"           ).c_str());
      m_trknSCTHits            =TTreeReaderArray<int  >(*reader, branchName("trknSCTHits"            ).c_str());
      m_trknSCTHoles           =TTreeReaderArray<int  >(*reader, branchName("trknSCTHoles"           ).c_str());
      m_trknTRTHits            =TTreeReaderArray<int  >(*reader, branchName("trknTRTHits"            ).c_str());
      m_trknTRTHoles           =TTreeReaderArray<int  >(*reader, branchName("trknTRTHoles"           ).c_str());
      m_trknBLayerHits         =TTreeReaderArray<int  >(*reader, branchName("trknBLayerHits"         ).c_str());
      m_trknInnermostPixLayHits=TTreeReaderArray<int  >(*reader, branchName("trknInnermostPixLayHits").c_str());
      m_trkPixdEdX             =TTreeReaderArray<float>(*reader, branchName("trkPixdEdX"             ).c_str());
  }

  if(m_infoSwitch.m_energyLoss )
    {
      m_EnergyLoss               =TTreeReaderArray<float        >(*reader, branchName("EnergyLoss"               ).c_str());
      m_EnergyLossSigma          =TTreeReaderArray<float        >(*reader, branchName("EnergyLossSigma"          ).c_str());
      m_energyLossType           =TTreeReaderArray<unsigned char>(*reader, branchName("energyLossType"           ).c_str());
      m_MeasEnergyLoss           =TTreeReaderArray<float        >(*reader, branchName("MeasEnergyLoss"           ).c_str());
      m_MeasEnergyLossSigma      =TTreeReaderArray<float        >(*reader, branchName("MeasEnergyLossSigma"      ).c_str());
      m_ParamEnergyLoss          =TTreeReaderArray<float        >(*reader, branchName("ParamEnergyLoss"          ).c_str());
      m_ParamEnergyLossSigmaMinus=TTreeReaderArray<float        >(*reader, branchName("ParamEnergyLossSigmaMinus").c_str());
      m_ParamEnergyLossSigmaPlus =TTreeReaderArray<float        >(*reader, branchName("ParamEnergyLossSigmaPlus" ).c_str());
    }
}

void MuonContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);  

  // trigger
  if ( m_infoSwitch.m_trigger ) {
    m_particles[idx].isTrigMatched         =     m_isTrigMatched       [idx];
    m_particles[idx].isTrigMatchedToChain  =     m_isTrigMatchedToChain[idx];
    m_particles[idx].listTrigChains        =     m_listTrigChains      [idx];
  }
    
  // isolation
  if ( m_infoSwitch.m_isolation ) {
    m_particles[idx].isIsolated_LooseTrackOnly                =     m_isIsolated_LooseTrackOnly                [idx];
    m_particles[idx].isIsolated_Loose                         =     m_isIsolated_Loose                         [idx];
    m_particles[idx].isIsolated_Tight                         =     m_isIsolated_Tight                         [idx];
    m_particles[idx].isIsolated_Gradient                      =     m_isIsolated_Gradient                      [idx];
    m_particles[idx].isIsolated_GradientLoose                 =     m_isIsolated_GradientLoose                 [idx];
    m_particles[idx].isIsolated_FixedCutLoose                 =     m_isIsolated_FixedCutLoose                 [idx];
    m_particles[idx].isIsolated_FixedCutTightTrackOnly        =     m_isIsolated_FixedCutTightTrackOnly        [idx];
    m_particles[idx].isIsolated_UserDefinedFixEfficiency      =     m_isIsolated_UserDefinedFixEfficiency      [idx];
    m_particles[idx].isIsolated_UserDefinedCut                =     m_isIsolated_UserDefinedCut                [idx];
    m_particles[idx].ptcone20                                 =     m_ptcone20                                 [idx];
    m_particles[idx].ptcone30                                 =     m_ptcone30                                 [idx];
    m_particles[idx].ptcone40                                 =     m_ptcone40                                 [idx];
    m_particles[idx].ptvarcone20                              =     m_ptvarcone20                              [idx];
    m_particles[idx].ptvarcone30                              =     m_ptvarcone30                              [idx];
    m_particles[idx].ptvarcone40                              =     m_ptvarcone40                              [idx];
    m_particles[idx].topoetcone20                             =     m_topoetcone20                             [idx];
    m_particles[idx].topoetcone30                             =     m_topoetcone30                             [idx];
    m_particles[idx].topoetcone40                             =     m_topoetcone40                             [idx];
  }
  
  // quality
  if ( m_infoSwitch.m_quality ) {
    m_particles[idx].isVeryLoose    = m_isVeryLoose[idx];   
    m_particles[idx].isLoose        = m_isLoose    [idx];   
    m_particles[idx].isMedium       = m_isMedium   [idx];   
    m_particles[idx].isTight        = m_isTight    [idx];   
  }
  
  // scale factors w/ sys
  // per object
  if ( m_infoSwitch.m_effSF && m_mc ) {
    
    for (auto& reco : m_infoSwitch.m_recoWPs) {
      m_particles[idx].RecoEff_SF[ reco ] = m_RecoEff_SF[ reco ][idx];
    }
    
    for (auto& isol : m_infoSwitch.m_isolWPs) {
      m_particles[idx].IsoEff_SF[ isol ]  = m_IsoEff_SF [ isol ][idx];
    }
    
    for (auto& trig : m_infoSwitch.m_trigWPs) {
      m_particles[idx].TrigEff_SF[ trig ] = m_TrigEff_SF[ trig ][idx];
      m_particles[idx].TrigMCEff [ trig ] = m_TrigMCEff [ trig ][idx];
    }

    m_particles[idx].TTVAEff_SF = m_TTVAEff_SF[idx];
  }
      // track parameters
  if ( m_infoSwitch.m_trackparams ) {
    m_particles[idx].trkd0             = m_trkd0          [idx];
    m_particles[idx].trkd0sig          = m_trkd0sig       [idx];
    m_particles[idx].trkz0             = m_trkz0          [idx];
    m_particles[idx].trkz0sintheta     = m_trkz0sintheta  [idx];
    m_particles[idx].trkphi0           = m_trkphi0        [idx];
    m_particles[idx].trktheta          = m_trktheta       [idx];
    m_particles[idx].trkcharge         = m_trkcharge      [idx];
    m_particles[idx].trkqOverP         = m_trkqOverP      [idx];
  }

      // track hit content
  if ( m_infoSwitch.m_trackhitcont ) {
    m_particles[idx].trknSiHits                 = m_trknSiHits              [idx];
    m_particles[idx].trknPixHits                = m_trknPixHits             [idx];
    m_particles[idx].trknPixHoles               = m_trknPixHoles            [idx];
    m_particles[idx].trknSCTHits                = m_trknSCTHits             [idx];
    m_particles[idx].trknSCTHoles               = m_trknSCTHoles            [idx];
    m_particles[idx].trknTRTHits                = m_trknTRTHits             [idx];
    m_particles[idx].trknTRTHoles               = m_trknTRTHoles            [idx];
    m_particles[idx].trknBLayerHits             = m_trknBLayerHits          [idx];
    m_particles[idx].trknInnermostPixLayHits    = m_trknInnermostPixLayHits [idx];         // not available in DC14
    m_particles[idx].trkPixdEdX                 = m_trkPixdEdX              [idx];         // not available in DC14
  }

  if ( m_infoSwitch.m_energyLoss ) {
    m_particles[idx].EnergyLoss                    = m_EnergyLoss               [idx];
    m_particles[idx].EnergyLossSigma               = m_EnergyLossSigma          [idx];
    m_particles[idx].energyLossType                = m_energyLossType           [idx];
    m_particles[idx].MeasEnergyLoss                = m_MeasEnergyLoss           [idx];
    m_particles[idx].MeasEnergyLossSigma           = m_MeasEnergyLossSigma      [idx];
    m_particles[idx].ParamEnergyLoss               = m_ParamEnergyLoss          [idx];
    m_particles[idx].ParamEnergyLossSigmaMinus     = m_ParamEnergyLossSigmaMinus[idx];
    m_particles[idx].ParamEnergyLossSigmaPlus      = m_ParamEnergyLossSigmaPlus [idx];
  }

}
