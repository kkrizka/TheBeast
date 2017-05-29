#include "PhotonContainer.h"

PhotonContainer::PhotonContainer(const std::string& name, const std::string& detailStr, float units, bool mc)
  : ParticleContainer(name, detailStr, units, mc, true)
{
  if(m_infoSwitch.m_isolation){
    m_isIsolated_Cone40CaloOnly   = new std::vector<int>   ();
    m_isIsolated_Cone40           = new std::vector<int>   ();
    m_isIsolated_Cone20           = new std::vector<int>   ();
    m_ptcone20                    = new std::vector<float> ();
    m_ptcone30                    = new std::vector<float> ();
    m_ptcone40                    = new std::vector<float> ();
    m_ptvarcone20                 = new std::vector<float> ();
    m_ptvarcone30                 = new std::vector<float> ();
    m_ptvarcone40                 = new std::vector<float> ();
    m_topoetcone20                = new std::vector<float> ();
    m_topoetcone30                = new std::vector<float> ();
    m_topoetcone40                = new std::vector<float> ();
  }    

      // PID
  if(m_infoSwitch.m_PID){
    m_n_IsLoose  = 0;
    m_n_IsMedium = 0;
    m_n_IsTight  = 0;  

    m_IsLoose    = new std::vector<int>   ();
    m_IsMedium   = new std::vector<int>   ();
    m_IsTight    = new std::vector<int>   ();
  }

  if(m_infoSwitch.m_purity){
      //Purity
      m_radhad1    = new std::vector<float> ();
      m_radhad     = new std::vector<float> ();
      m_e277	   = new std::vector<float> ();
      m_reta	   = new std::vector<float> ();
      m_rphi	   = new std::vector<float> ();
      m_weta2      = new std::vector<float> ();
      m_f1	   = new std::vector<float> ();
      m_wtot	   = new std::vector<float> ();
      m_deltae     = new std::vector<float> ();
      m_eratio     = new std::vector<float> ();
      //std::vector<float> m_w1
  }
  
  if(m_infoSwitch.m_effSF && m_mc){
    m_LooseEffSF =new std::vector<float>();
    m_MediumEffSF=new std::vector<float>();
    m_TightEffSF =new std::vector<float>();

    m_LooseEffSF_Error =new std::vector<float>();
    m_MediumEffSF_Error=new std::vector<float>();
    m_TightEffSF_Error =new std::vector<float>();
  }

  if(m_infoSwitch.m_trigger){
    m_trigMatched=new std::vector<std::vector<std::string> >();
  }
}

PhotonContainer::~PhotonContainer()
{
  if(m_infoSwitch.m_isolation){
    delete m_isIsolated_Cone40CaloOnly;
    delete m_isIsolated_Cone40	   ;
    delete m_isIsolated_Cone20	   ;
    delete m_ptcone20		   ;
    delete m_ptcone30		   ;
    delete m_ptcone40		   ;
    delete m_ptvarcone20	   ;
    delete m_ptvarcone30	   ;
    delete m_ptvarcone40	   ;
    delete m_topoetcone20	   ;
    delete m_topoetcone30	   ;
    delete m_topoetcone40          ;
  }    

  // PID
  if(m_infoSwitch.m_PID){
    delete m_IsLoose;
    delete m_IsMedium;
    delete m_IsTight;
  }

  if(m_infoSwitch.m_purity){
    delete m_radhad1;
    delete m_radhad ;
    delete m_e277	;
    delete m_reta	;
    delete m_rphi	;
    delete m_weta2	;
    delete m_f1	;
    delete m_wtot	;
    delete m_deltae;
    delete m_eratio;
    //std::vector<float> m_w1
  }

  if(m_infoSwitch.m_effSF){
    delete m_LooseEffSF;
    delete m_MediumEffSF;
    delete m_TightEffSF;

    delete m_LooseEffSF_Error;
    delete m_MediumEffSF_Error;
    delete m_TightEffSF_Error;
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
    connectBranch<int>  (tree, "isIsolated_Cone40CaloOnly", &m_isIsolated_Cone40CaloOnly );
    connectBranch<int>  (tree, "isIsolated_Cone40",         &m_isIsolated_Cone40         );
    connectBranch<int>  (tree, "isIsolated_Cone20",         &m_isIsolated_Cone20         );
    connectBranch<float>(tree, "ptcone20",                  &m_ptcone20                  );
    connectBranch<float>(tree, "ptcone30",                  &m_ptcone30                  );
    connectBranch<float>(tree, "ptcone40",                  &m_ptcone40                  );
    connectBranch<float>(tree, "ptvarcone20",               &m_ptvarcone20               );
    connectBranch<float>(tree, "ptvarcone30",               &m_ptvarcone30               );
    connectBranch<float>(tree, "ptvarcone40",               &m_ptvarcone40               );
    connectBranch<float>(tree, "topoetcone20",              &m_topoetcone20              );
    connectBranch<float>(tree, "topoetcone30",              &m_topoetcone30              );
    connectBranch<float>(tree, "topoetcone40",              &m_topoetcone40              );
  }    

  // PID
  if(m_infoSwitch.m_PID){
    tree->SetBranchStatus (("n"+m_name+"_IsLoose").c_str(),     1);
    tree->SetBranchAddress(("n"+m_name+"_IsLoose").c_str(),      &m_n_IsLoose);
    connectBranch<int>(tree,  "IsLoose"  , &m_IsLoose );

    tree->SetBranchStatus (("n"+m_name+"_IsMedium").c_str(),     1);
    tree->SetBranchAddress(("n"+m_name+"_IsMedium").c_str(),      &m_n_IsMedium);
    connectBranch<int>(tree,  "IsMedium" , &m_IsMedium);

    tree->SetBranchStatus (("n"+m_name+"_IsTight").c_str(),     1);
    tree->SetBranchAddress(("n"+m_name+"_IsTight").c_str(),      &m_n_IsTight);
    connectBranch<int>(tree,  "IsTight"  , &m_IsTight );
  }

  
  if(m_infoSwitch.m_purity){
    connectBranch<float>(tree,"radhad1", &m_radhad1);
    connectBranch<float>(tree,"radhad" , &m_radhad );
    connectBranch<float>(tree,"e277"   , &m_e277   );
    connectBranch<float>(tree,"reta"   , &m_reta   );
    connectBranch<float>(tree,"rphi"   , &m_rphi   );
    connectBranch<float>(tree,"weta2"  , &m_weta2  );
    connectBranch<float>(tree,"f1"     , &m_f1     );
    connectBranch<float>(tree,"wtot"   , &m_wtot   );
    connectBranch<float>(tree,"deltae" , &m_deltae );
    connectBranch<float>(tree,"eratio" , &m_eratio );
  }

  if(m_infoSwitch.m_effSF && m_mc)
    {
      connectBranch<float>(tree, "LooseEffSF", &m_LooseEffSF);
      connectBranch<float>(tree, "MediumEffSF",&m_MediumEffSF);
      connectBranch<float>(tree, "TightEffSF", &m_TightEffSF);

      connectBranch<float>(tree, "LooseEffSF_Error", &m_LooseEffSF_Error);
      connectBranch<float>(tree, "MediumEffSF_Error",&m_MediumEffSF_Error);
      connectBranch<float>(tree, "TightEffSF_Error", &m_TightEffSF_Error);
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
    m_particles[idx].isIsolated_Cone40CaloOnly =  m_isIsolated_Cone40CaloOnly ->at(idx);
    m_particles[idx].isIsolated_Cone40 =          m_isIsolated_Cone40         ->at(idx);
    m_particles[idx].isIsolated_Cone20 =          m_isIsolated_Cone20         ->at(idx);
    m_particles[idx].ptcone20 =                   m_ptcone20                  ->at(idx);
    m_particles[idx].ptcone30 =                   m_ptcone30                  ->at(idx);
    m_particles[idx].ptcone40 =                   m_ptcone40                  ->at(idx);
    m_particles[idx].ptvarcone20 =                m_ptvarcone20               ->at(idx);
    m_particles[idx].ptvarcone30 =                m_ptvarcone30               ->at(idx);
    m_particles[idx].ptvarcone40 =                m_ptvarcone40               ->at(idx);
    m_particles[idx].topoetcone20 =               m_topoetcone20              ->at(idx);
    m_particles[idx].topoetcone30 =               m_topoetcone30              ->at(idx);
    m_particles[idx].topoetcone40 =               m_topoetcone40              ->at(idx);
  }    

  // PID
  if(m_infoSwitch.m_PID){
    m_particles[idx].IsLoose =   m_IsLoose ->at(idx);
    m_particles[idx].IsMedium =  m_IsMedium->at(idx);
    m_particles[idx].IsTight =   m_IsTight ->at(idx);
  }

  
  if(m_infoSwitch.m_purity){
    m_particles[idx].radhad1 = m_radhad1->at(idx);
    m_particles[idx].radhad =  m_radhad ->at(idx);
    m_particles[idx].e277 =    m_e277   ->at(idx);
    m_particles[idx].reta =    m_reta   ->at(idx);
    m_particles[idx].rphi =    m_rphi   ->at(idx);
    m_particles[idx].weta2 =   m_weta2  ->at(idx);
    m_particles[idx].f1 =      m_f1     ->at(idx);
    m_particles[idx].wtot =    m_wtot   ->at(idx);
    m_particles[idx].deltae =  m_deltae ->at(idx);
    m_particles[idx].eratio =  m_eratio ->at(idx);
  }

  if(m_infoSwitch.m_effSF && m_mc){
    m_particles[idx].LooseEffSF =m_LooseEffSF ->at(idx);
    m_particles[idx].MediumEffSF=m_MediumEffSF->at(idx);
    m_particles[idx].TightEffSF =m_TightEffSF ->at(idx);

    m_particles[idx].LooseEffSF_Error =m_LooseEffSF_Error ->at(idx);
    m_particles[idx].MediumEffSF_Error=m_MediumEffSF_Error->at(idx);
    m_particles[idx].TightEffSF_Error =m_TightEffSF_Error ->at(idx);
  }

  if(m_infoSwitch.m_trigger){
    m_particles[idx].trigMatched =m_trigMatched->at(idx);
  }

}


void PhotonContainer::setBranches(TTree *tree)
{
  ParticleContainer::setBranches(tree);


  if(m_infoSwitch.m_isolation){
    setBranch<int>  (tree, "isIsolated_Cone40CaloOnly", m_isIsolated_Cone40CaloOnly );
    setBranch<int>  (tree, "isIsolated_Cone40",         m_isIsolated_Cone40         );
    setBranch<int>  (tree, "isIsolated_Cone20",         m_isIsolated_Cone20         );
    setBranch<float>(tree, "ptcone20",                  m_ptcone20                  );
    setBranch<float>(tree, "ptcone30",                  m_ptcone30                  );
    setBranch<float>(tree, "ptcone40",                  m_ptcone40                  );
    setBranch<float>(tree, "ptvarcone20",               m_ptvarcone20               );
    setBranch<float>(tree, "ptvarcone30",               m_ptvarcone30               );
    setBranch<float>(tree, "ptvarcone40",               m_ptvarcone40               );
    setBranch<float>(tree, "topoetcone20",              m_topoetcone20              );
    setBranch<float>(tree, "topoetcone30",              m_topoetcone30              );
    setBranch<float>(tree, "topoetcone40",              m_topoetcone40              );
  }    

  // PID
  if(m_infoSwitch.m_PID){
    tree->Branch(("n"+m_name+"_IsLoose").c_str(),      &m_n_IsLoose);
    setBranch<int>(tree,  "IsLoose"  , m_IsLoose );

    tree->Branch(("n"+m_name+"_IsMedium").c_str(),      &m_n_IsMedium);
    setBranch<int>(tree,  "IsMedium" , m_IsMedium);

    tree->Branch(("n"+m_name+"_IsTight").c_str(),      &m_n_IsTight);
    setBranch<int>(tree,  "IsTight"  , m_IsTight );
  }

  // purity
  if(m_infoSwitch.m_purity){
    setBranch<float>(tree,"radhad1", m_radhad1);
    setBranch<float>(tree,"radhad" , m_radhad );
    setBranch<float>(tree,"e277"   , m_e277   );
    setBranch<float>(tree,"reta"   , m_reta   );
    setBranch<float>(tree,"rphi"   , m_rphi   );
    setBranch<float>(tree,"weta2"  , m_weta2  );
    setBranch<float>(tree,"f1"     , m_f1     );
    setBranch<float>(tree,"wtot"   , m_wtot   );
    setBranch<float>(tree,"deltae" , m_deltae );
    setBranch<float>(tree,"eratio" , m_eratio );
  }

  // effSF
  if(m_infoSwitch.m_effSF && m_mc){
    setBranch<float>(tree, "LooseEffSF" , m_LooseEffSF);
    setBranch<float>(tree, "MediumEffSF", m_MediumEffSF);
    setBranch<float>(tree, "TightEffSF" , m_TightEffSF);

    setBranch<float>(tree, "LooseEffSF_Error" , m_LooseEffSF_Error);
    setBranch<float>(tree, "MediumEffSF_Error", m_MediumEffSF_Error);
    setBranch<float>(tree, "TightEffSF_Error" , m_TightEffSF_Error);
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
    m_isIsolated_Cone40CaloOnly-> clear();
    m_isIsolated_Cone40	  -> clear() ;
    m_isIsolated_Cone20	  -> clear() ;
    m_ptcone20		  -> clear() ;
    m_ptcone30		  -> clear() ;
    m_ptcone40		  -> clear() ;
    m_ptvarcone20	  -> clear() ;
    m_ptvarcone30	  -> clear() ;
    m_ptvarcone40	  -> clear() ;
    m_topoetcone20	  -> clear() ;
    m_topoetcone30	  -> clear() ;
    m_topoetcone40        -> clear();
  }    

  // PID
  if(m_infoSwitch.m_PID){
    m_n_IsLoose = 0;
    m_IsLoose -> clear();

    m_n_IsMedium = 0;
    m_IsMedium-> clear();

    m_n_IsTight = 0;
    m_IsTight -> clear();
  }

  // purity
  if(m_infoSwitch.m_purity){
    m_radhad1-> clear();
    m_radhad -> clear();
    m_e277   -> clear()	;
    m_reta   -> clear()	;
    m_rphi   -> clear()	;
    m_weta2  -> clear()	;
    m_f1     -> clear()	;
    m_wtot   -> clear()	;
    m_deltae -> clear();
    m_eratio -> clear();
    //std::vector<float> m_w1
  }

  // effSF
  if(m_infoSwitch.m_effSF && m_mc){
    m_LooseEffSF ->clear();
    m_MediumEffSF->clear();
    m_TightEffSF ->clear();

    m_LooseEffSF_Error ->clear();
    m_MediumEffSF_Error->clear();
    m_TightEffSF_Error ->clear();
  }

  // trigger
  if(m_infoSwitch.m_trigger){
    m_trigMatched->clear();
  }

}
