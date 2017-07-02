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
      m_isTrigMatched       =new TTreeReaderArray<int             >(*reader, branchName("isTrigMatched"       ).c_str());
      m_isTrigMatchedToChain=new TTreeReaderArray<std::vector<int>>(*reader, branchName("isTrigMatchedToChain").c_str());
      m_listTrigChains      =new TTreeReaderArray<std::string     >(*reader, branchName("listTrigChains"      ).c_str());
    }

  if ( m_infoSwitch.m_isolation )
    {
      m_isIsolated_LooseTrackOnly          =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_LooseTrackOnly"          ).c_str());
      m_isIsolated_Loose                   =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_Loose"                   ).c_str());
      m_isIsolated_Tight                   =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_Tight"                   ).c_str());
      m_isIsolated_Gradient                =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_Gradient"                ).c_str());
      m_isIsolated_GradientLoose           =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_GradientLoose"           ).c_str());
      m_isIsolated_FixedCutLoose           =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_FixedCutLoose"           ).c_str());
      m_isIsolated_FixedCutTightTrackOnly  =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_FixedCutTightTrackOnly"  ).c_str());
      m_isIsolated_UserDefinedFixEfficiency=new TTreeReaderArray<int  >(*reader, branchName("isIsolated_UserDefinedFixEfficiency").c_str());
      m_isIsolated_UserDefinedCut          =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_UserDefinedCut"          ).c_str());
      m_ptcone20                           =new TTreeReaderArray<float>(*reader, branchName("ptcone20"                           ).c_str());
      m_ptcone30                           =new TTreeReaderArray<float>(*reader, branchName("ptcone30"                           ).c_str());
      m_ptcone40                           =new TTreeReaderArray<float>(*reader, branchName("ptcone40"                           ).c_str());
      m_ptvarcone20                        =new TTreeReaderArray<float>(*reader, branchName("ptvarcone20"                        ).c_str());
      m_ptvarcone30                        =new TTreeReaderArray<float>(*reader, branchName("ptvarcone30"                        ).c_str());
      m_ptvarcone40                        =new TTreeReaderArray<float>(*reader, branchName("ptvarcone40"                        ).c_str());
      m_topoetcone20                       =new TTreeReaderArray<float>(*reader, branchName("topoetcone20"                       ).c_str());
      m_topoetcone30                       =new TTreeReaderArray<float>(*reader, branchName("topoetcone30"                       ).c_str());
      m_topoetcone40                       =new TTreeReaderArray<float>(*reader, branchName("topoetcone40"                       ).c_str());
    }

  if ( m_infoSwitch.m_effSF && m_mc )
    {
      for (auto& reco : m_infoSwitch.m_recoWPs)
	{
	  std::string recoEffSF = "muon_RecoEff_SF_" + reco; 
	  m_RecoEff_SF[ reco ] = new TTreeReaderArray<std::vector<float>>( *reader, recoEffSF.c_str() );
	}

      for (auto& isol : m_infoSwitch.m_isolWPs)
	{
	  std::string isolEffSF = "muon_IsoEff_SF_" + isol; 
	  m_IsoEff_SF[ isol ]  = new TTreeReaderArray<std::vector<float>>( *reader, isolEffSF.c_str() );
	}

      for (auto& trig : m_infoSwitch.m_trigWPs)
	{
	  std::string trigEffSF = "muon_TrigEff_SF_" + trig; 
	  m_TrigEff_SF[ trig ] = new TTreeReaderArray<std::vector<float>>( *reader, trigEffSF.c_str() );


	  std::string trigMCEff = "muon_TrigMCEff_" + trig;
	  m_TrigMCEff[ trig ]  = new TTreeReaderArray<std::vector<float>>( *reader, trigMCEff.c_str() );
	}

      m_TTVAEff_SF=new TTreeReaderArray<std::vector<float> >(*reader, branchName("TTVAEff_SF").c_str());
    }

  if ( m_infoSwitch.m_quality )
    {
      m_isVeryLoose=new TTreeReaderArray<int  >(*reader, branchName("isVeryLoose").c_str());
      m_isLoose    =new TTreeReaderArray<int  >(*reader, branchName("isLoose"    ).c_str());
      m_isMedium   =new TTreeReaderArray<int  >(*reader, branchName("isMedium"   ).c_str());
      m_isTight    =new TTreeReaderArray<int  >(*reader, branchName("isTight"    ).c_str());
    }

  if ( m_infoSwitch.m_trackparams )
    {
      m_trkd0        =new TTreeReaderArray<float>(*reader, branchName("trkd0"        ).c_str());
      m_trkd0sig     =new TTreeReaderArray<float>(*reader, branchName("trkd0sig"     ).c_str());
      m_trkz0        =new TTreeReaderArray<float>(*reader, branchName("trkz0"        ).c_str());
      m_trkz0sintheta=new TTreeReaderArray<float>(*reader, branchName("trkz0sintheta").c_str());
      m_trkphi0      =new TTreeReaderArray<float>(*reader, branchName("trkphi0"      ).c_str());
      m_trktheta     =new TTreeReaderArray<float>(*reader, branchName("trktheta"     ).c_str());
      m_trkcharge    =new TTreeReaderArray<float>(*reader, branchName("trkcharge"    ).c_str());
      m_trkqOverP    =new TTreeReaderArray<float>(*reader, branchName("trkqOverP"    ).c_str());
    }

  if ( m_infoSwitch.m_trackhitcont )
    {
      m_trknSiHits             =new TTreeReaderArray<int  >(*reader, branchName("trknSiHits"             ).c_str());
      m_trknPixHits            =new TTreeReaderArray<int  >(*reader, branchName("trknPixHits"            ).c_str());
      m_trknPixHoles           =new TTreeReaderArray<int  >(*reader, branchName("trknPixHoles"           ).c_str());
      m_trknSCTHits            =new TTreeReaderArray<int  >(*reader, branchName("trknSCTHits"            ).c_str());
      m_trknSCTHoles           =new TTreeReaderArray<int  >(*reader, branchName("trknSCTHoles"           ).c_str());
      m_trknTRTHits            =new TTreeReaderArray<int  >(*reader, branchName("trknTRTHits"            ).c_str());
      m_trknTRTHoles           =new TTreeReaderArray<int  >(*reader, branchName("trknTRTHoles"           ).c_str());
      m_trknBLayerHits         =new TTreeReaderArray<int  >(*reader, branchName("trknBLayerHits"         ).c_str());
      m_trknInnermostPixLayHits=new TTreeReaderArray<int  >(*reader, branchName("trknInnermostPixLayHits").c_str());
      m_trkPixdEdX             =new TTreeReaderArray<float>(*reader, branchName("trkPixdEdX"             ).c_str());
  }

  if(m_infoSwitch.m_energyLoss )
    {
      m_EnergyLoss               =new TTreeReaderArray<float        >(*reader, branchName("EnergyLoss"               ).c_str());
      m_EnergyLossSigma          =new TTreeReaderArray<float        >(*reader, branchName("EnergyLossSigma"          ).c_str());
      m_energyLossType           =new TTreeReaderArray<unsigned char>(*reader, branchName("energyLossType"           ).c_str());
      m_MeasEnergyLoss           =new TTreeReaderArray<float        >(*reader, branchName("MeasEnergyLoss"           ).c_str());
      m_MeasEnergyLossSigma      =new TTreeReaderArray<float        >(*reader, branchName("MeasEnergyLossSigma"      ).c_str());
      m_ParamEnergyLoss          =new TTreeReaderArray<float        >(*reader, branchName("ParamEnergyLoss"          ).c_str());
      m_ParamEnergyLossSigmaMinus=new TTreeReaderArray<float        >(*reader, branchName("ParamEnergyLossSigmaMinus").c_str());
      m_ParamEnergyLossSigmaPlus =new TTreeReaderArray<float        >(*reader, branchName("ParamEnergyLossSigmaPlus" ).c_str());
    }
}

void MuonContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);  

  // trigger
  if ( m_infoSwitch.m_trigger ) {
    m_particles[idx].isTrigMatched         =     m_isTrigMatched       ->At(idx);
    m_particles[idx].isTrigMatchedToChain  =     m_isTrigMatchedToChain->At(idx);
    m_particles[idx].listTrigChains        =     m_listTrigChains      ->At(idx);
  }
    
  // isolation
  if ( m_infoSwitch.m_isolation ) {
    m_particles[idx].isIsolated_LooseTrackOnly                =     m_isIsolated_LooseTrackOnly                ->At(idx);
    m_particles[idx].isIsolated_Loose                         =     m_isIsolated_Loose                         ->At(idx);
    m_particles[idx].isIsolated_Tight                         =     m_isIsolated_Tight                         ->At(idx);
    m_particles[idx].isIsolated_Gradient                      =     m_isIsolated_Gradient                      ->At(idx);
    m_particles[idx].isIsolated_GradientLoose                 =     m_isIsolated_GradientLoose                 ->At(idx);
    m_particles[idx].isIsolated_FixedCutLoose                 =     m_isIsolated_FixedCutLoose                 ->At(idx);
    m_particles[idx].isIsolated_FixedCutTightTrackOnly        =     m_isIsolated_FixedCutTightTrackOnly        ->At(idx);
    m_particles[idx].isIsolated_UserDefinedFixEfficiency      =     m_isIsolated_UserDefinedFixEfficiency      ->At(idx);
    m_particles[idx].isIsolated_UserDefinedCut                =     m_isIsolated_UserDefinedCut                ->At(idx);
    m_particles[idx].ptcone20                                 =     m_ptcone20                                 ->At(idx);
    m_particles[idx].ptcone30                                 =     m_ptcone30                                 ->At(idx);
    m_particles[idx].ptcone40                                 =     m_ptcone40                                 ->At(idx);
    m_particles[idx].ptvarcone20                              =     m_ptvarcone20                              ->At(idx);
    m_particles[idx].ptvarcone30                              =     m_ptvarcone30                              ->At(idx);
    m_particles[idx].ptvarcone40                              =     m_ptvarcone40                              ->At(idx);
    m_particles[idx].topoetcone20                             =     m_topoetcone20                             ->At(idx);
    m_particles[idx].topoetcone30                             =     m_topoetcone30                             ->At(idx);
    m_particles[idx].topoetcone40                             =     m_topoetcone40                             ->At(idx);
  }
  
  // quality
  if ( m_infoSwitch.m_quality ) {
    m_particles[idx].isVeryLoose    = m_isVeryLoose->At(idx);   
    m_particles[idx].isLoose        = m_isLoose    ->At(idx);   
    m_particles[idx].isMedium       = m_isMedium   ->At(idx);   
    m_particles[idx].isTight        = m_isTight    ->At(idx);   
  }
  
  // scale factors w/ sys
  // per object
  if ( m_infoSwitch.m_effSF && m_mc ) {
    
    for (auto& reco : m_infoSwitch.m_recoWPs) {
      m_particles[idx].RecoEff_SF[ reco ] = m_RecoEff_SF[ reco ]->At(idx);
    }
    
    for (auto& isol : m_infoSwitch.m_isolWPs) {
      m_particles[idx].IsoEff_SF[ isol ]  = m_IsoEff_SF [ isol ]->At(idx);
    }
    
    for (auto& trig : m_infoSwitch.m_trigWPs) {
      m_particles[idx].TrigEff_SF[ trig ] = m_TrigEff_SF[ trig ]->At(idx);
      m_particles[idx].TrigMCEff [ trig ] = m_TrigMCEff [ trig ]->At(idx);
    }

    m_particles[idx].TTVAEff_SF = m_TTVAEff_SF->At(idx);
  }
      // track parameters
  if ( m_infoSwitch.m_trackparams ) {
    m_particles[idx].trkd0             = m_trkd0          ->At(idx);
    m_particles[idx].trkd0sig          = m_trkd0sig       ->At(idx);
    m_particles[idx].trkz0             = m_trkz0          ->At(idx);
    m_particles[idx].trkz0sintheta     = m_trkz0sintheta  ->At(idx);
    m_particles[idx].trkphi0           = m_trkphi0        ->At(idx);
    m_particles[idx].trktheta          = m_trktheta       ->At(idx);
    m_particles[idx].trkcharge         = m_trkcharge      ->At(idx);
    m_particles[idx].trkqOverP         = m_trkqOverP      ->At(idx);
  }

      // track hit content
  if ( m_infoSwitch.m_trackhitcont ) {
    m_particles[idx].trknSiHits                 = m_trknSiHits              ->At(idx);
    m_particles[idx].trknPixHits                = m_trknPixHits             ->At(idx);
    m_particles[idx].trknPixHoles               = m_trknPixHoles            ->At(idx);
    m_particles[idx].trknSCTHits                = m_trknSCTHits             ->At(idx);
    m_particles[idx].trknSCTHoles               = m_trknSCTHoles            ->At(idx);
    m_particles[idx].trknTRTHits                = m_trknTRTHits             ->At(idx);
    m_particles[idx].trknTRTHoles               = m_trknTRTHoles            ->At(idx);
    m_particles[idx].trknBLayerHits             = m_trknBLayerHits          ->At(idx);
    m_particles[idx].trknInnermostPixLayHits    = m_trknInnermostPixLayHits ->At(idx);         // not available in DC14
    m_particles[idx].trkPixdEdX                 = m_trkPixdEdX              ->At(idx);         // not available in DC14
  }

  if ( m_infoSwitch.m_energyLoss ) {
    m_particles[idx].EnergyLoss                    = m_EnergyLoss               ->At(idx);
    m_particles[idx].EnergyLossSigma               = m_EnergyLossSigma          ->At(idx);
    m_particles[idx].energyLossType                = m_energyLossType           ->At(idx);
    m_particles[idx].MeasEnergyLoss                = m_MeasEnergyLoss           ->At(idx);
    m_particles[idx].MeasEnergyLossSigma           = m_MeasEnergyLossSigma      ->At(idx);
    m_particles[idx].ParamEnergyLoss               = m_ParamEnergyLoss          ->At(idx);
    m_particles[idx].ParamEnergyLossSigmaMinus     = m_ParamEnergyLossSigmaMinus->At(idx);
    m_particles[idx].ParamEnergyLossSigmaPlus      = m_ParamEnergyLossSigmaPlus ->At(idx);
  }

}
