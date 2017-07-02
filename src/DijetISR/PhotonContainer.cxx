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
    m_isIsolated_FixedCutTightCaloOnly=new TTreeReaderArray<int  >(*reader, branchName("isIsolated_Cone40CaloOnly").c_str());
    m_isIsolated_FixedCutTight        =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_Cone40"        ).c_str());
    m_isIsolated_FixedCutLoose        =new TTreeReaderArray<int  >(*reader, branchName("isIsolated_Cone20"        ).c_str());
    m_ptcone20                        =new TTreeReaderArray<float>(*reader, branchName("ptcone20"                 ).c_str());
    m_ptcone30                        =new TTreeReaderArray<float>(*reader, branchName("ptcone30"                 ).c_str());
    m_ptcone40                        =new TTreeReaderArray<float>(*reader, branchName("ptcone40"                 ).c_str());
    m_ptvarcone20                     =new TTreeReaderArray<float>(*reader, branchName("ptvarcone20"              ).c_str());
    m_ptvarcone30                     =new TTreeReaderArray<float>(*reader, branchName("ptvarcone30"              ).c_str());
    m_ptvarcone40                     =new TTreeReaderArray<float>(*reader, branchName("ptvarcone40"              ).c_str());
    m_topoetcone20                    =new TTreeReaderArray<float>(*reader, branchName("topoetcone20"             ).c_str());
    m_topoetcone30                    =new TTreeReaderArray<float>(*reader, branchName("topoetcone30"             ).c_str());
    m_topoetcone40                    =new TTreeReaderArray<float>(*reader, branchName("topoetcone40"             ).c_str());
  }

  // PID
  if(m_infoSwitch.m_PID){
    m_n_IsLoose      =new TTreeReaderValue<int>(*reader, ("n"+m_name+"_IsLoose" ).c_str());
    m_PhotonID_Loose =new TTreeReaderArray<int>(*reader,  branchName("IsLoose"  ).c_str());

    m_n_IsMedium     =new TTreeReaderValue<int>(*reader, ("n"+m_name+"_IsMedium").c_str());
    m_PhotonID_Medium=new TTreeReaderArray<int>(*reader,  branchName("IsMedium" ).c_str());

    m_n_IsTight      =new TTreeReaderValue<int>(*reader, ("n"+m_name+"_IsTight" ).c_str());
    m_PhotonID_Tight =new TTreeReaderArray<int>(*reader,  branchName("IsTight"  ).c_str());
  }

  
  if(m_infoSwitch.m_purity){
    m_Rhad1 =new TTreeReaderArray<float>(*reader, branchName("radhad1").c_str());
    m_Rhad  =new TTreeReaderArray<float>(*reader, branchName("radhad" ).c_str());
    m_e277  =new TTreeReaderArray<float>(*reader, branchName("e277"   ).c_str());
    m_Reta  =new TTreeReaderArray<float>(*reader, branchName("reta"   ).c_str());
    m_Rphi  =new TTreeReaderArray<float>(*reader, branchName("rphi"   ).c_str());
    m_weta2 =new TTreeReaderArray<float>(*reader, branchName("weta2"  ).c_str());
    m_f1    =new TTreeReaderArray<float>(*reader, branchName("f1"     ).c_str());
    m_wtots1=new TTreeReaderArray<float>(*reader, branchName("wtot"   ).c_str());
    m_DeltaE=new TTreeReaderArray<float>(*reader, branchName("deltae" ).c_str());
    m_Eratio=new TTreeReaderArray<float>(*reader, branchName("eratio" ).c_str());
  }

  if(m_infoSwitch.m_effSF && m_mc)
    {
      m_PhotonID_Loose_EffSF =new TTreeReaderArray<float>(*reader, branchName("LooseEffSF" ).c_str());
      m_PhotonID_Medium_EffSF=new TTreeReaderArray<float>(*reader, branchName("MediumEffSF").c_str());
      m_PhotonID_Tight_EffSF =new TTreeReaderArray<float>(*reader, branchName("TightEffSF" ).c_str());

      m_PhotonID_Loose_EffSF_Error =new TTreeReaderArray<float>(*reader, branchName("LooseEffSF_Error" ).c_str());
      m_PhotonID_Medium_EffSF_Error=new TTreeReaderArray<float>(*reader, branchName("MediumEffSF_Error").c_str());
      m_PhotonID_Tight_EffSF_Error =new TTreeReaderArray<float>(*reader, branchName("TightEffSF_Error" ).c_str());
    }

  if(m_infoSwitch.m_trigger)
    {
      m_trigMatched=new TTreeReaderArray<std::vector<std::string> >(*reader, branchName("trigMatched").c_str());
    }

}

void PhotonContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);

  if(m_infoSwitch.m_isolation){
    m_particles[idx].isIsolated_FixedCutTightCaloOnly =  m_isIsolated_FixedCutTightCaloOnly ->At(idx);
    m_particles[idx].isIsolated_FixedCutTight =          m_isIsolated_FixedCutTight         ->At(idx);
    m_particles[idx].isIsolated_FixedCutLoose =          m_isIsolated_FixedCutLoose         ->At(idx);
    m_particles[idx].ptcone20 =                          m_ptcone20                         ->At(idx);
    m_particles[idx].ptcone30 =                          m_ptcone30                         ->At(idx);
    m_particles[idx].ptcone40 =                          m_ptcone40                         ->At(idx);
    m_particles[idx].ptvarcone20 =                       m_ptvarcone20                      ->At(idx);
    m_particles[idx].ptvarcone30 =                       m_ptvarcone30                      ->At(idx);
    m_particles[idx].ptvarcone40 =                       m_ptvarcone40                      ->At(idx);
    m_particles[idx].topoetcone20 =                      m_topoetcone20                     ->At(idx);
    m_particles[idx].topoetcone30 =                      m_topoetcone30                     ->At(idx);
    m_particles[idx].topoetcone40 =                      m_topoetcone40                     ->At(idx);
  }    

  // PID
  if(m_infoSwitch.m_PID){
    m_particles[idx].PhotonID_Loose =   m_PhotonID_Loose ->At(idx);
    m_particles[idx].PhotonID_Medium =  m_PhotonID_Medium->At(idx);
    m_particles[idx].PhotonID_Tight =   m_PhotonID_Tight ->At(idx);
  }

  
  if(m_infoSwitch.m_purity){
    m_particles[idx].Rhad1  = m_Rhad1  ->At(idx);
    m_particles[idx].Rhad   = m_Rhad   ->At(idx);
    m_particles[idx].e277   = m_e277   ->At(idx);
    m_particles[idx].Reta   = m_Reta   ->At(idx);
    m_particles[idx].Rphi   = m_Rphi   ->At(idx);
    m_particles[idx].weta2  = m_weta2  ->At(idx);
    m_particles[idx].f1     = m_f1     ->At(idx);
    m_particles[idx].wtots1 = m_wtots1 ->At(idx);
    m_particles[idx].DeltaE = m_DeltaE ->At(idx);
    m_particles[idx].Eratio = m_Eratio ->At(idx);
  }

  if(m_infoSwitch.m_effSF && m_mc){
    m_particles[idx].PhotonID_Loose_EffSF =m_PhotonID_Loose_EffSF ->At(idx);
    m_particles[idx].PhotonID_Medium_EffSF=m_PhotonID_Medium_EffSF->At(idx);
    m_particles[idx].PhotonID_Tight_EffSF =m_PhotonID_Tight_EffSF ->At(idx);

    m_particles[idx].PhotonID_Loose_EffSF_Error =m_PhotonID_Loose_EffSF_Error ->At(idx);
    m_particles[idx].PhotonID_Medium_EffSF_Error=m_PhotonID_Medium_EffSF_Error->At(idx);
    m_particles[idx].PhotonID_Tight_EffSF_Error =m_PhotonID_Tight_EffSF_Error ->At(idx);
  }

  if(m_infoSwitch.m_trigger){
    m_particles[idx].trigMatched =m_trigMatched->At(idx);
  }

}
