#include "Event.h"

#include <iostream>

using namespace TCA;

Event::Event(bool mc, bool truthOnly)
  : TheEvent(),
    m_truthOnly(truthOnly), m_mc(mc),
    m_jets(0), m_photons(0), // m_truth(0), m_trigJets(0),
    m_triggerInfoSwitch(0)
{
  setTriggerDetail("");

  m_passedTriggers  =new std::vector<std::string>();
  m_triggerPrescales=new std::vector<float>();

  m_jets    = new TClonesArray("xAH::Jet");
  m_photons = new TClonesArray("xAH::Photon");
}

Event::~Event()
{
  if(m_triggerInfoSwitch) delete m_triggerInfoSwitch;

  delete m_passedTriggers;
  delete m_triggerPrescales;

  if(m_jets)     delete m_jets;
  if(m_photons)  delete m_photons;
  //if(m_truth)    delete m_truth;
  //if(m_trigJets) delete m_trigJets;
}

void Event::setTree(TTree *tree)
{
  TheEvent::setTree(tree);

  // Event info
  setBranchAddress("runNumber",  &m_runNumber);
  setBranchAddress("eventNumber",&m_eventNumber);

  if(!m_truthOnly)
    {
      setBranchAddress ("lumiBlock",                     &m_lumiBlock);
      setBranchAddress ("NPV",                           &m_NPV);
      setBranchAddress ("actualInteractionsPerCrossing", &m_actualInteractionsPerCrossing);
      setBranchAddress ("averageInteractionsPerCrossing",&m_averageInteractionsPerCrossing);
      setBranchAddress ("weight_pileup",                 &m_weight_pileup);
    }

  if(m_mc)
    {
      setBranchAddress ("mcEventNumber",  &m_mcEventNumber);
      setBranchAddress ("mcChannelNumber",&m_mcChannelNumber);
      setBranchAddress ("mcEventWeight",  &m_mcEventWeight);
    }

  if(m_triggerInfoSwitch->m_passTriggers)
    {
      setBranchAddress ("passedTriggers",  &m_passedTriggers);
      setBranchAddress ("triggerPrescales",&m_triggerPrescales);
    }

  // weights
  setBranchAddress ("weight",   &m_weight);
  setBranchAddress ("weight_xs",&m_weight_xs);

  // particles
  if(m_jets)
    {
      tree->GetBranch("jet")->SetAutoDelete(false);
      setBranchAddress("jet", &m_jets);
    }
  if(m_photons)
    {
      tree->GetBranch("ph") ->SetAutoDelete(false);
      setBranchAddress("ph" , &m_photons);
    }

  // custom
  if(tree->GetBranch("Zprime_pt")) 
    setBranchAddress("Zprime_pt", &m_Zprime_pt);

  if(tree->GetBranch("Zprime_eta")) 
    setBranchAddress("Zprime_eta", &m_Zprime_eta);

  if(tree->GetBranch("Zprime_phi")) 
    setBranchAddress("Zprime_phi", &m_Zprime_phi);

  if(tree->GetBranch("Zprime_m")) 
    setBranchAddress("Zprime_m",   &m_Zprime_m);
}

void Event::updateEntry()
{
  //if(m_jets)     m_jets    ->updateEntry();
  //if(m_photons)  m_photons ->updateEntry();
  // if(m_truth)    m_truth   ->updateEntry();
  // if(m_trigJets) m_trigJets->updateEntry();

  m_Zprime.SetPtEtaPhiM(m_Zprime_pt,m_Zprime_eta,m_Zprime_phi,m_Zprime_m);
}

void Event::setTriggerDetail(const std::string &detailStr)
{
  if(m_triggerInfoSwitch) delete m_triggerInfoSwitch;
  m_triggerInfoSwitch=new TriggerInfoSwitch(detailStr);
}

