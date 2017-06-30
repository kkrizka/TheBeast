#include "PhotonContainer.h"

PhotonContainer::PhotonContainer(const std::string& name, const std::string& detailStr, float units, bool mc)
  : ParticleContainer(name, detailStr, units, mc, true)
{ }

PhotonContainer::~PhotonContainer()
{ }

void PhotonContainer::setReader(TTreeReader *reader)
{
  //
  // Connect branches
  ParticleContainer::setReader(reader);

  if(m_infoSwitch.m_isolation){
    m_isIsolated_FixedCutTightCaloOnly=TTreeReaderArray<int  >(*reader, branchName("isIsolated_Cone40CaloOnly").c_str());
    m_isIsolated_FixedCutTight        =TTreeReaderArray<int  >(*reader, branchName("isIsolated_Cone40"        ).c_str());
    m_isIsolated_FixedCutLoose        =TTreeReaderArray<int  >(*reader, branchName("isIsolated_Cone20"        ).c_str());
    m_ptcone20                        =TTreeReaderArray<float>(*reader, branchName("ptcone20"                 ).c_str());
    m_ptcone30                        =TTreeReaderArray<float>(*reader, branchName("ptcone30"                 ).c_str());
    m_ptcone40                        =TTreeReaderArray<float>(*reader, branchName("ptcone40"                 ).c_str());
    m_ptvarcone20                     =TTreeReaderArray<float>(*reader, branchName("ptvarcone20"              ).c_str());
    m_ptvarcone30                     =TTreeReaderArray<float>(*reader, branchName("ptvarcone30"              ).c_str());
    m_ptvarcone40                     =TTreeReaderArray<float>(*reader, branchName("ptvarcone40"              ).c_str());
    m_topoetcone20                    =TTreeReaderArray<float>(*reader, branchName("topoetcone20"             ).c_str());
    m_topoetcone30                    =TTreeReaderArray<float>(*reader, branchName("topoetcone30"             ).c_str());
    m_topoetcone40                    =TTreeReaderArray<float>(*reader, branchName("topoetcone40"             ).c_str());
  }

  // PID
  if(m_infoSwitch.m_PID){
    m_n_IsLoose      =TTreeReaderValue<int>(*reader, ("n"+m_name+"_IsLoose" ).c_str());
    m_PhotonID_Loose =TTreeReaderArray<int>(*reader,  branchName("IsLoose"  ).c_str());

    m_n_IsMedium     =TTreeReaderValue<int>(*reader, ("n"+m_name+"_IsMedium").c_str());
    m_PhotonID_Medium=TTreeReaderArray<int>(*reader,  branchName("IsMedium" ).c_str());

    m_n_IsTight      =TTreeReaderValue<int>(*reader, ("n"+m_name+"_IsTight" ).c_str());
    m_PhotonID_Tight =TTreeReaderArray<int>(*reader,  branchName("IsTight"  ).c_str());
  }

  
  if(m_infoSwitch.m_purity){
    m_Rhad1 =TTreeReaderArray<float>(*reader, branchName("radhad1").c_str());
    m_Rhad  =TTreeReaderArray<float>(*reader, branchName("radhad" ).c_str());
    m_e277  =TTreeReaderArray<float>(*reader, branchName("e277"   ).c_str());
    m_Reta  =TTreeReaderArray<float>(*reader, branchName("reta"   ).c_str());
    m_Rphi  =TTreeReaderArray<float>(*reader, branchName("rphi"   ).c_str());
    m_weta2 =TTreeReaderArray<float>(*reader, branchName("weta2"  ).c_str());
    m_f1    =TTreeReaderArray<float>(*reader, branchName("f1"     ).c_str());
    m_wtots1=TTreeReaderArray<float>(*reader, branchName("wtot"   ).c_str());
    m_DeltaE=TTreeReaderArray<float>(*reader, branchName("deltae" ).c_str());
    m_Eratio=TTreeReaderArray<float>(*reader, branchName("eratio" ).c_str());
  }

  if(m_infoSwitch.m_effSF && m_mc)
    {
      m_PhotonID_Loose_EffSF =TTreeReaderArray<float>(*reader, branchName("LooseEffSF" ).c_str());
      m_PhotonID_Medium_EffSF=TTreeReaderArray<float>(*reader, branchName("MediumEffSF").c_str());
      m_PhotonID_Tight_EffSF =TTreeReaderArray<float>(*reader, branchName("TightEffSF" ).c_str());

      m_PhotonID_Loose_EffSF_Error =TTreeReaderArray<float>(*reader, branchName("LooseEffSF_Error" ).c_str());
      m_PhotonID_Medium_EffSF_Error=TTreeReaderArray<float>(*reader, branchName("MediumEffSF_Error").c_str());
      m_PhotonID_Tight_EffSF_Error =TTreeReaderArray<float>(*reader, branchName("TightEffSF_Error" ).c_str());
    }

  if(m_infoSwitch.m_trigger)
    {
      m_trigMatched=TTreeReaderArray<std::vector<std::string> >(*reader, branchName("trigMatched").c_str());
    }

}

void PhotonContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);

  if(m_infoSwitch.m_isolation){
    m_particles[idx].isIsolated_FixedCutTightCaloOnly =  m_isIsolated_FixedCutTightCaloOnly [idx];
    m_particles[idx].isIsolated_FixedCutTight =          m_isIsolated_FixedCutTight         [idx];
    m_particles[idx].isIsolated_FixedCutLoose =          m_isIsolated_FixedCutLoose         [idx];
    m_particles[idx].ptcone20 =                          m_ptcone20                         [idx];
    m_particles[idx].ptcone30 =                          m_ptcone30                         [idx];
    m_particles[idx].ptcone40 =                          m_ptcone40                         [idx];
    m_particles[idx].ptvarcone20 =                       m_ptvarcone20                      [idx];
    m_particles[idx].ptvarcone30 =                       m_ptvarcone30                      [idx];
    m_particles[idx].ptvarcone40 =                       m_ptvarcone40                      [idx];
    m_particles[idx].topoetcone20 =                      m_topoetcone20                     [idx];
    m_particles[idx].topoetcone30 =                      m_topoetcone30                     [idx];
    m_particles[idx].topoetcone40 =                      m_topoetcone40                     [idx];
  }    

  // PID
  if(m_infoSwitch.m_PID){
    m_particles[idx].PhotonID_Loose =   m_PhotonID_Loose [idx];
    m_particles[idx].PhotonID_Medium =  m_PhotonID_Medium[idx];
    m_particles[idx].PhotonID_Tight =   m_PhotonID_Tight [idx];
  }

  
  if(m_infoSwitch.m_purity){
    m_particles[idx].Rhad1  = m_Rhad1  [idx];
    m_particles[idx].Rhad   = m_Rhad   [idx];
    m_particles[idx].e277   = m_e277   [idx];
    m_particles[idx].Reta   = m_Reta   [idx];
    m_particles[idx].Rphi   = m_Rphi   [idx];
    m_particles[idx].weta2  = m_weta2  [idx];
    m_particles[idx].f1     = m_f1     [idx];
    m_particles[idx].wtots1 = m_wtots1 [idx];
    m_particles[idx].DeltaE = m_DeltaE [idx];
    m_particles[idx].Eratio = m_Eratio [idx];
  }

  if(m_infoSwitch.m_effSF && m_mc){
    m_particles[idx].PhotonID_Loose_EffSF =m_PhotonID_Loose_EffSF [idx];
    m_particles[idx].PhotonID_Medium_EffSF=m_PhotonID_Medium_EffSF[idx];
    m_particles[idx].PhotonID_Tight_EffSF =m_PhotonID_Tight_EffSF [idx];

    m_particles[idx].PhotonID_Loose_EffSF_Error =m_PhotonID_Loose_EffSF_Error [idx];
    m_particles[idx].PhotonID_Medium_EffSF_Error=m_PhotonID_Medium_EffSF_Error[idx];
    m_particles[idx].PhotonID_Tight_EffSF_Error =m_PhotonID_Tight_EffSF_Error [idx];
  }

  if(m_infoSwitch.m_trigger){
    m_particles[idx].trigMatched =m_trigMatched[idx];
  }

}
