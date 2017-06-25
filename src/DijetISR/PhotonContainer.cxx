#include "PhotonContainer.h"

PhotonContainer::PhotonContainer(const std::string& name, const std::string& detailStr, float units, bool mc)
  : ParticleContainer(name, detailStr, units, mc, true)
{
  if(m_infoSwitch.m_isolation){
    m_isIsolated_FixedCutTightCaloOnly = new std::vector<int>   ();
    m_isIsolated_FixedCutTight         = new std::vector<int>   ();
    m_isIsolated_FixedCutLoose         = new std::vector<int>   ();
    m_ptcone20                         = new std::vector<float> ();
    m_ptcone30                         = new std::vector<float> ();
    m_ptcone40                         = new std::vector<float> ();
    m_ptvarcone20                      = new std::vector<float> ();
    m_ptvarcone30                      = new std::vector<float> ();
    m_ptvarcone40                      = new std::vector<float> ();
    m_topoetcone20                     = new std::vector<float> ();
    m_topoetcone30                     = new std::vector<float> ();
    m_topoetcone40                     = new std::vector<float> ();
  }    

      // PID
  if(m_infoSwitch.m_PID){
    m_n_IsLoose  = 0;
    m_n_IsMedium = 0;
    m_n_IsTight  = 0;  

    m_PhotonID_Loose    = new std::vector<int>   ();
    m_PhotonID_Medium   = new std::vector<int>   ();
    m_PhotonID_Tight    = new std::vector<int>   ();
  }

  if(m_infoSwitch.m_purity){
      //Purity
      m_Rhad1    = new std::vector<float> ();
      m_Rhad     = new std::vector<float> ();
      m_e277	 = new std::vector<float> ();
      m_Reta	 = new std::vector<float> ();
      m_Rphi	 = new std::vector<float> ();
      m_weta2    = new std::vector<float> ();
      m_f1	 = new std::vector<float> ();
      m_wtots1	 = new std::vector<float> ();
      m_DeltaE   = new std::vector<float> ();
      m_Eratio   = new std::vector<float> ();
      //std::vector<float> m_w1
  }

  if(m_infoSwitch.m_effSF && m_mc){
    m_PhotonID_Loose_EffSF =new std::vector<float>();
    m_PhotonID_Medium_EffSF=new std::vector<float>();
    m_PhotonID_Tight_EffSF =new std::vector<float>();

    m_PhotonID_Loose_EffSF_Error =new std::vector<float>();
    m_PhotonID_Medium_EffSF_Error=new std::vector<float>();
    m_PhotonID_Tight_EffSF_Error =new std::vector<float>();
  }

  if(m_infoSwitch.m_trigger){
    m_trigMatched=new std::vector<std::vector<std::string> >();
  }
}

PhotonContainer::~PhotonContainer()
{
  if(m_infoSwitch.m_isolation){
    delete m_isIsolated_FixedCutTightCaloOnly;
    delete m_isIsolated_FixedCutTight	     ;
    delete m_isIsolated_FixedCutLoose	     ;
    delete m_ptcone20		             ;
    delete m_ptcone30		             ;
    delete m_ptcone40		             ;
    delete m_ptvarcone20	             ;
    delete m_ptvarcone30	             ;
    delete m_ptvarcone40	             ;
    delete m_topoetcone20	             ;
    delete m_topoetcone30	             ;
    delete m_topoetcone40                    ;
  }    

  // PID
  if(m_infoSwitch.m_PID){
    delete m_PhotonID_Loose;
    delete m_PhotonID_Medium;
    delete m_PhotonID_Tight;
  }

  if(m_infoSwitch.m_purity){
    delete m_Rhad1 ;
    delete m_Rhad  ;
    delete m_e277  ;
    delete m_Reta  ;
    delete m_Rphi  ;
    delete m_weta2 ;
    delete m_f1	   ;
    delete m_wtots1;
    delete m_DeltaE;
    delete m_Eratio;
  }

  if(m_infoSwitch.m_effSF){
    delete m_PhotonID_Loose_EffSF;
    delete m_PhotonID_Medium_EffSF;
    delete m_PhotonID_Tight_EffSF;

    delete m_PhotonID_Loose_EffSF_Error;
    delete m_PhotonID_Medium_EffSF_Error;
    delete m_PhotonID_Tight_EffSF_Error;
  }

  if(m_infoSwitch.m_trigger){
    delete m_trigMatched;
  }
}

void PhotonContainer::setTree(TTree *tree)
{
  //
  // Connect branches
  ParticleContainer::setTree(tree);

  tree->SetBranchStatus  ("nph" , 1);
  tree->SetBranchAddress ("nph" , &m_n);

  if(m_infoSwitch.m_isolation){
    connectBranch<int>  (tree, "isIsolated_Cone40CaloOnly", &m_isIsolated_FixedCutTightCaloOnly );
    connectBranch<int>  (tree, "isIsolated_Cone40",         &m_isIsolated_FixedCutTight         );
    connectBranch<int>  (tree, "isIsolated_Cone20",         &m_isIsolated_FixedCutLoose         );
    connectBranch<float>(tree, "ptcone20",                  &m_ptcone20                         );
    connectBranch<float>(tree, "ptcone30",                  &m_ptcone30                         );
    connectBranch<float>(tree, "ptcone40",                  &m_ptcone40                         );
    connectBranch<float>(tree, "ptvarcone20",               &m_ptvarcone20                      );
    connectBranch<float>(tree, "ptvarcone30",               &m_ptvarcone30                      );
    connectBranch<float>(tree, "ptvarcone40",               &m_ptvarcone40                      );
    connectBranch<float>(tree, "topoetcone20",              &m_topoetcone20                     );
    connectBranch<float>(tree, "topoetcone30",              &m_topoetcone30                     );
    connectBranch<float>(tree, "topoetcone40",              &m_topoetcone40                     );
  }

  // PID
  if(m_infoSwitch.m_PID){
    tree->SetBranchStatus (("n"+m_name+"_IsLoose").c_str(),     1);
    tree->SetBranchAddress(("n"+m_name+"_IsLoose").c_str(),      &m_n_IsLoose);
    connectBranch<int>(tree,  "IsLoose"  , &m_PhotonID_Loose );

    tree->SetBranchStatus (("n"+m_name+"_IsMedium").c_str(),     1);
    tree->SetBranchAddress(("n"+m_name+"_IsMedium").c_str(),      &m_n_IsMedium);
    connectBranch<int>(tree,  "IsMedium" , &m_PhotonID_Medium);

    tree->SetBranchStatus (("n"+m_name+"_IsTight").c_str(),     1);
    tree->SetBranchAddress(("n"+m_name+"_IsTight").c_str(),      &m_n_IsTight);
    connectBranch<int>(tree,  "IsTight"  , &m_PhotonID_Tight );
  }

  
  if(m_infoSwitch.m_purity){
    connectBranch<float>(tree,"radhad1", &m_Rhad1 );
    connectBranch<float>(tree,"radhad" , &m_Rhad  );
    connectBranch<float>(tree,"e277"   , &m_e277  );
    connectBranch<float>(tree,"reta"   , &m_Reta  );
    connectBranch<float>(tree,"rphi"   , &m_Rphi  );
    connectBranch<float>(tree,"weta2"  , &m_weta2 );
    connectBranch<float>(tree,"f1"     , &m_f1    );
    connectBranch<float>(tree,"wtot"   , &m_wtots1);
    connectBranch<float>(tree,"deltae" , &m_DeltaE);
    connectBranch<float>(tree,"eratio" , &m_Eratio);
  }

  if(m_infoSwitch.m_effSF && m_mc)
    {
      connectBranch<float>(tree, "LooseEffSF", &m_PhotonID_Loose_EffSF);
      connectBranch<float>(tree, "MediumEffSF",&m_PhotonID_Medium_EffSF);
      connectBranch<float>(tree, "TightEffSF", &m_PhotonID_Tight_EffSF);

      connectBranch<float>(tree, "LooseEffSF_Error", &m_PhotonID_Loose_EffSF_Error);
      connectBranch<float>(tree, "MediumEffSF_Error",&m_PhotonID_Medium_EffSF_Error);
      connectBranch<float>(tree, "TightEffSF_Error", &m_PhotonID_Tight_EffSF_Error);
    }

  if(m_infoSwitch.m_trigger)
    {
      connectBranch<std::vector<std::string> >(tree, "trigMatched", &m_trigMatched);
    }

}

void PhotonContainer::updateParticle(uint idx)
{
  ParticleContainer::updateParticle(idx);

  if(m_infoSwitch.m_isolation){
    m_particles[idx].isIsolated_FixedCutTightCaloOnly =  m_isIsolated_FixedCutTightCaloOnly ->at(idx);
    m_particles[idx].isIsolated_FixedCutTight =          m_isIsolated_FixedCutTight         ->at(idx);
    m_particles[idx].isIsolated_FixedCutLoose =          m_isIsolated_FixedCutLoose         ->at(idx);
    m_particles[idx].ptcone20 =                          m_ptcone20                         ->at(idx);
    m_particles[idx].ptcone30 =                          m_ptcone30                         ->at(idx);
    m_particles[idx].ptcone40 =                          m_ptcone40                         ->at(idx);
    m_particles[idx].ptvarcone20 =                       m_ptvarcone20                      ->at(idx);
    m_particles[idx].ptvarcone30 =                       m_ptvarcone30                      ->at(idx);
    m_particles[idx].ptvarcone40 =                       m_ptvarcone40                      ->at(idx);
    m_particles[idx].topoetcone20 =                      m_topoetcone20                     ->at(idx);
    m_particles[idx].topoetcone30 =                      m_topoetcone30                     ->at(idx);
    m_particles[idx].topoetcone40 =                      m_topoetcone40                     ->at(idx);
  }    

  // PID
  if(m_infoSwitch.m_PID){
    m_particles[idx].PhotonID_Loose =   m_PhotonID_Loose ->at(idx);
    m_particles[idx].PhotonID_Medium =  m_PhotonID_Medium->at(idx);
    m_particles[idx].PhotonID_Tight =   m_PhotonID_Tight ->at(idx);
  }

  
  if(m_infoSwitch.m_purity){
    m_particles[idx].Rhad1  = m_Rhad1  ->at(idx);
    m_particles[idx].Rhad   = m_Rhad   ->at(idx);
    m_particles[idx].e277   = m_e277   ->at(idx);
    m_particles[idx].Reta   = m_Reta   ->at(idx);
    m_particles[idx].Rphi   = m_Rphi   ->at(idx);
    m_particles[idx].weta2  = m_weta2  ->at(idx);
    m_particles[idx].f1     = m_f1     ->at(idx);
    m_particles[idx].wtots1 = m_wtots1 ->at(idx);
    m_particles[idx].DeltaE = m_DeltaE ->at(idx);
    m_particles[idx].Eratio = m_Eratio ->at(idx);
  }

  if(m_infoSwitch.m_effSF && m_mc){
    m_particles[idx].PhotonID_Loose_EffSF =m_PhotonID_Loose_EffSF ->at(idx);
    m_particles[idx].PhotonID_Medium_EffSF=m_PhotonID_Medium_EffSF->at(idx);
    m_particles[idx].PhotonID_Tight_EffSF =m_PhotonID_Tight_EffSF ->at(idx);

    m_particles[idx].PhotonID_Loose_EffSF_Error =m_PhotonID_Loose_EffSF_Error ->at(idx);
    m_particles[idx].PhotonID_Medium_EffSF_Error=m_PhotonID_Medium_EffSF_Error->at(idx);
    m_particles[idx].PhotonID_Tight_EffSF_Error =m_PhotonID_Tight_EffSF_Error ->at(idx);
  }

  if(m_infoSwitch.m_trigger){
    m_particles[idx].trigMatched =m_trigMatched->at(idx);
  }

}


void PhotonContainer::setBranches(TTree *tree)
{
  ParticleContainer::setBranches(tree);


  if(m_infoSwitch.m_isolation){
    setBranch<int>  (tree, "isIsolated_Cone40CaloOnly", m_isIsolated_FixedCutTightCaloOnly );
    setBranch<int>  (tree, "isIsolated_Cone40",         m_isIsolated_FixedCutTight         );
    setBranch<int>  (tree, "isIsolated_Cone20",         m_isIsolated_FixedCutLoose         );
    setBranch<float>(tree, "ptcone20",                  m_ptcone20                         );
    setBranch<float>(tree, "ptcone30",                  m_ptcone30                         );
    setBranch<float>(tree, "ptcone40",                  m_ptcone40                         );
    setBranch<float>(tree, "ptvarcone20",               m_ptvarcone20                      );
    setBranch<float>(tree, "ptvarcone30",               m_ptvarcone30                      );
    setBranch<float>(tree, "ptvarcone40",               m_ptvarcone40                      );
    setBranch<float>(tree, "topoetcone20",              m_topoetcone20                     );
    setBranch<float>(tree, "topoetcone30",              m_topoetcone30                     );
    setBranch<float>(tree, "topoetcone40",              m_topoetcone40                     );
  }

  // PID
  if(m_infoSwitch.m_PID){
    tree->Branch(("n"+m_name+"_IsLoose").c_str(),      &m_n_IsLoose);
    setBranch<int>(tree,  "IsLoose"  , m_PhotonID_Loose );

    tree->Branch(("n"+m_name+"_IsMedium").c_str(),      &m_n_IsMedium);
    setBranch<int>(tree,  "IsMedium" , m_PhotonID_Medium);

    tree->Branch(("n"+m_name+"_IsTight").c_str(),      &m_n_IsTight);
    setBranch<int>(tree,  "IsTight"  , m_PhotonID_Tight );
  }

  // purity
  if(m_infoSwitch.m_purity){
    setBranch<float>(tree,"radhad1", m_Rhad1  );
    setBranch<float>(tree,"radhad" , m_Rhad   );
    setBranch<float>(tree,"e277"   , m_e277   );
    setBranch<float>(tree,"reta"   , m_Reta   );
    setBranch<float>(tree,"rphi"   , m_Rphi   );
    setBranch<float>(tree,"weta2"  , m_weta2  );
    setBranch<float>(tree,"f1"     , m_f1     );
    setBranch<float>(tree,"wtot"   , m_wtots1 );
    setBranch<float>(tree,"deltae" , m_DeltaE );
    setBranch<float>(tree,"eratio" , m_Eratio );
  }

  // effSF
  if(m_infoSwitch.m_effSF && m_mc){
    setBranch<float>(tree, "LooseEffSF" , m_PhotonID_Loose_EffSF);
    setBranch<float>(tree, "MediumEffSF", m_PhotonID_Medium_EffSF);
    setBranch<float>(tree, "TightEffSF" , m_PhotonID_Tight_EffSF);

    setBranch<float>(tree, "LooseEffSF_Error" , m_PhotonID_Loose_EffSF_Error);
    setBranch<float>(tree, "MediumEffSF_Error", m_PhotonID_Medium_EffSF_Error);
    setBranch<float>(tree, "TightEffSF_Error" , m_PhotonID_Tight_EffSF_Error);
  }

  // trigger
  if(m_infoSwitch.m_trigger){
    setBranch<std::vector<std::string> >(tree, "trigMatched", m_trigMatched);
  }

  return;
}



void PhotonContainer::clear()
{
  
  ParticleContainer::clear();

  if(m_infoSwitch.m_isolation){
    m_isIsolated_FixedCutTightCaloOnly-> clear();
    m_isIsolated_FixedCutTight        -> clear();
    m_isIsolated_FixedCutLoose	      -> clear();
    m_ptcone20                        -> clear();
    m_ptcone30		              -> clear();
    m_ptcone40		              -> clear();
    m_ptvarcone20	              -> clear();
    m_ptvarcone30	              -> clear();
    m_ptvarcone40	              -> clear();
    m_topoetcone20	              -> clear();
    m_topoetcone30	              -> clear();
    m_topoetcone40                    -> clear();
  }    

  // PID
  if(m_infoSwitch.m_PID){
    m_n_IsLoose = 0;
    m_PhotonID_Loose -> clear();

    m_n_IsMedium = 0;
    m_PhotonID_Medium-> clear();

    m_n_IsTight = 0;
    m_PhotonID_Tight -> clear();
  }

  // purity
  if(m_infoSwitch.m_purity){
    m_Rhad1  -> clear();
    m_Rhad   -> clear();
    m_e277   -> clear()	;
    m_Reta   -> clear()	;
    m_Rphi   -> clear()	;
    m_weta2  -> clear()	;
    m_f1     -> clear()	;
    m_wtots1 -> clear()	;
    m_DeltaE -> clear();
    m_Eratio -> clear();
    //std::vector<float> m_w1
  }

  // effSF
  if(m_infoSwitch.m_effSF && m_mc){
    m_PhotonID_Loose_EffSF ->clear();
    m_PhotonID_Medium_EffSF->clear();
    m_PhotonID_Tight_EffSF ->clear();

    m_PhotonID_Loose_EffSF_Error ->clear();
    m_PhotonID_Medium_EffSF_Error->clear();
    m_PhotonID_Tight_EffSF_Error ->clear();
  }

  // trigger
  if(m_infoSwitch.m_trigger){
    m_trigMatched->clear();
  }

}
