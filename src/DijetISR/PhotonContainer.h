#ifndef PHOTONCONTAINER_H_
#define PHOTONCONTAINER_H_

#include <TTree.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>

#include "../xAH/Photon.h"

#include "InfoSwitch.h"
#include "ParticleContainer.h"

class PhotonContainer : public ParticleContainer<xAH::Photon,PhotonInfoSwitch>
{
public:
  PhotonContainer(const std::string& name = "ph", const std::string& detailStr="", float units = 1e3, bool mc = false);
  virtual ~PhotonContainer();

  virtual void setReader(TTreeReader *reader);

protected:
  virtual void updateParticle(uint idx);
    
private:

  // isolation
  TTreeReaderArray<int  > m_isIsolated_FixedCutTightCaloOnly;
  TTreeReaderArray<int  > m_isIsolated_FixedCutTight;
  TTreeReaderArray<int  > m_isIsolated_FixedCutLoose;
  //TTreeReaderArray<float> m_etcone20;
  TTreeReaderArray<float> m_ptcone20;
  TTreeReaderArray<float> m_ptcone30;
  TTreeReaderArray<float> m_ptcone40;
  TTreeReaderArray<float> m_ptvarcone20;
  TTreeReaderArray<float> m_ptvarcone30;
  TTreeReaderArray<float> m_ptvarcone40;
  TTreeReaderArray<float> m_topoetcone20;
  TTreeReaderArray<float> m_topoetcone30;
  TTreeReaderArray<float> m_topoetcone40;

  // PID
  TTreeReaderValue<int  > m_n_IsLoose;
  TTreeReaderArray<int  > m_PhotonID_Loose;
  TTreeReaderValue<int  > m_n_IsMedium;
  TTreeReaderArray<int  > m_PhotonID_Medium;
  TTreeReaderValue<int  > m_n_IsTight;
  TTreeReaderArray<int  > m_PhotonID_Tight;

  //Purity
  TTreeReaderArray<float> m_Rhad1;
  TTreeReaderArray<float> m_Rhad;
  TTreeReaderArray<float> m_e277;
  TTreeReaderArray<float> m_Reta;
  TTreeReaderArray<float> m_Rphi;
  TTreeReaderArray<float> m_weta2;
  TTreeReaderArray<float> m_f1;
  TTreeReaderArray<float> m_wtots1;
  //TTreeReaderArray<float> m_w1;
  TTreeReaderArray<float> m_DeltaE;
  TTreeReaderArray<float> m_Eratio;

  // effSF
  TTreeReaderArray<float> m_PhotonID_Loose_EffSF;
  TTreeReaderArray<float> m_PhotonID_Medium_EffSF;
  TTreeReaderArray<float> m_PhotonID_Tight_EffSF;

  TTreeReaderArray<float> m_PhotonID_Loose_EffSF_Error;
  TTreeReaderArray<float> m_PhotonID_Medium_EffSF_Error;
  TTreeReaderArray<float> m_PhotonID_Tight_EffSF_Error;

  // trigger
  TTreeReaderArray<std::vector<std::string> > m_trigMatched;
};

#endif // PHOTONCONTAINER_H_
