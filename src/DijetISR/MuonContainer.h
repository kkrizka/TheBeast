#ifndef MUONCONTAINER_H_
#define MUONCONTAINER_H_

#include <TTree.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>

#include "../xAH/Muon.h"

#include "ParticleContainer.h"
#include "InfoSwitch.h"

class MuonContainer : public ParticleContainer<xAH::Muon,MuonInfoSwitch>
{
public:
  MuonContainer(const std::string& name = "muon", const std::string& detailStr="", float units = 1e3, bool mc = false);
  virtual ~MuonContainer();
    
  virtual void setReader(TTreeReader *reader);

protected:
  virtual void updateParticle(uint idx);
    
private:

  // trigger
  TTreeReaderArray<int             >* m_isTrigMatched;
  TTreeReaderArray<std::vector<int>>* m_isTrigMatchedToChain;
  TTreeReaderArray<std::string     >* m_listTrigChains;
    
  // isolation
  TTreeReaderArray<int  >* m_isIsolated_LooseTrackOnly;
  TTreeReaderArray<int  >* m_isIsolated_Loose;
  TTreeReaderArray<int  >* m_isIsolated_Tight;
  TTreeReaderArray<int  >* m_isIsolated_Gradient;
  TTreeReaderArray<int  >* m_isIsolated_GradientLoose;
  TTreeReaderArray<int  >* m_isIsolated_FixedCutLoose;
  TTreeReaderArray<int  >* m_isIsolated_FixedCutTightTrackOnly;
  TTreeReaderArray<int  >* m_isIsolated_UserDefinedFixEfficiency;
  TTreeReaderArray<int  >* m_isIsolated_UserDefinedCut;
  TTreeReaderArray<float>* m_ptcone20;
  TTreeReaderArray<float>* m_ptcone30;
  TTreeReaderArray<float>* m_ptcone40;
  TTreeReaderArray<float>* m_ptvarcone20;
  TTreeReaderArray<float>* m_ptvarcone30;
  TTreeReaderArray<float>* m_ptvarcone40;
  TTreeReaderArray<float>* m_topoetcone20;
  TTreeReaderArray<float>* m_topoetcone30;
  TTreeReaderArray<float>* m_topoetcone40;
    
  // quality
  TTreeReaderArray<int  >* m_isVeryLoose;
  TTreeReaderArray<int  >* m_isLoose;
  TTreeReaderArray<int  >* m_isMedium;
  TTreeReaderArray<int  >* m_isTight;
    
  // scale factors w/ sys
  // per object
  TTreeReaderArray<std::vector<float>>* m_TTVAEff_SF;

  std::map< std::string, TTreeReaderArray< std::vector< float > >* > m_RecoEff_SF;
  std::map< std::string, TTreeReaderArray< std::vector< float > >* > m_IsoEff_SF;
  std::map< std::string, TTreeReaderArray< std::vector< float > >* > m_TrigEff_SF;
  std::map< std::string, TTreeReaderArray< std::vector< float > >* > m_TrigMCEff;

  // track parameters
  TTreeReaderArray<float>* m_trkd0;
  TTreeReaderArray<float>* m_trkd0sig;
  TTreeReaderArray<float>* m_trkz0;
  TTreeReaderArray<float>* m_trkz0sintheta;
  TTreeReaderArray<float>* m_trkphi0;
  TTreeReaderArray<float>* m_trktheta;
  TTreeReaderArray<float>* m_trkcharge;
  TTreeReaderArray<float>* m_trkqOverP;

  // track hit content
  TTreeReaderArray<int  >* m_trknSiHits;
  TTreeReaderArray<int  >* m_trknPixHits;
  TTreeReaderArray<int  >* m_trknPixHoles;
  TTreeReaderArray<int  >* m_trknSCTHits;
  TTreeReaderArray<int  >* m_trknSCTHoles;
  TTreeReaderArray<int  >* m_trknTRTHits;
  TTreeReaderArray<int  >* m_trknTRTHoles;
  TTreeReaderArray<int  >* m_trknBLayerHits;
  TTreeReaderArray<int  >* m_trknInnermostPixLayHits; // not available in DC14
  TTreeReaderArray<float>* m_trkPixdEdX;            // not available in DC14

  TTreeReaderArray<float>*         m_EnergyLoss;
  TTreeReaderArray<float>*         m_EnergyLossSigma;
  TTreeReaderArray<unsigned char>* m_energyLossType;
  TTreeReaderArray<float>*         m_MeasEnergyLoss;
  TTreeReaderArray<float>*         m_MeasEnergyLossSigma;
  TTreeReaderArray<float>*         m_ParamEnergyLoss;
  TTreeReaderArray<float>*         m_ParamEnergyLossSigmaMinus;
  TTreeReaderArray<float>*         m_ParamEnergyLossSigmaPlus;

};
#endif // MUONCONTAINER_H_
