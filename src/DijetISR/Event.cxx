#include "Event.h"

#include <iostream>

using namespace DijetISR;

Event::Event(bool mc, bool truthOnly)
  : TheEvent(),
    m_haveZprime(false),
    m_truthOnly(truthOnly), m_mc(mc),
    // m_truth(0), m_trigJets(0),
    m_triggerInfoSwitch(0)
{
  setTriggerDetail("");
}

Event::~Event()
{
  if(m_triggerInfoSwitch) delete m_triggerInfoSwitch;

  //if(m_truth)    delete m_truth;
  //if(m_trigJets) delete m_trigJets;
}

void Event::setReader(TTreeReader *reader)
{
  TheEvent::setReader(reader);

  // Event info
  m_runNumber  =TTreeReaderValue<int      >(*reader, "runNumber"  );
  m_eventNumber=TTreeReaderValue<long long>(*reader, "eventNumber");

  if(!m_truthOnly)
    {
      m_lumiBlock                     =TTreeReaderValue<int  >(*reader, "lumiBlock");
      m_NPV                           =TTreeReaderValue<int  >(*reader, "NPV");
      m_actualInteractionsPerCrossing =TTreeReaderValue<float>(*reader, "actualInteractionsPerCrossing");
      m_averageInteractionsPerCrossing=TTreeReaderValue<float>(*reader, "averageInteractionsPerCrossing");
      m_weight_pileup                 =TTreeReaderValue<float>(*reader, "weight_pileup");
    }

  if(m_mc)
    {
      m_mcEventNumber  =TTreeReaderValue<int  >(*reader, "mcEventNumber");
      m_mcChannelNumber=TTreeReaderValue<int  >(*reader, "mcChannelNumber");
      m_mcEventWeight  =TTreeReaderValue<float>(*reader, "mcEventWeight");
    }

  if(m_triggerInfoSwitch->m_passTriggers)
    {
      m_passedTriggers  =TTreeReaderValue<std::vector<std::string>>(*reader, "passedTriggers");
      m_triggerPrescales=TTreeReaderValue<std::vector<float>      >(*reader, "triggerPrescales");
    }

  // weights
  m_weight   =TTreeReaderValue<float>(*reader, "weight");
  m_weight_xs=TTreeReaderValue<float>(*reader, "weight_xs");

  // particles
  if(m_jets)     m_jets    ->setReader(reader);
  if(m_photons)  m_photons ->setReader(reader);

  // custom
  if(reader->GetTree()->Branch("Zprime_pt") &&
     reader->GetTree()->Branch("Zprime_eat") &&
     reader->GetTree()->Branch("Zprime_phi") &&
     reader->GetTree()->Branch("Zprime_m"))
    {
      m_haveZprime=true;
      m_Zprime_pt =TTreeReaderValue<float>(*reader, "Zprime_pt");
      m_Zprime_eta=TTreeReaderValue<float>(*reader, "Zprime_eta");
      m_Zprime_phi=TTreeReaderValue<float>(*reader, "Zprime_phi");
      m_Zprime_m  =TTreeReaderValue<float>(*reader, "Zprime_m");
    }
}

void Event::updateEntry()
{
  if(m_jets   ) m_jets   ->updateEntry();
  if(m_photons) m_photons->updateEntry();

  if(m_haveZprime)
    m_Zprime.SetPtEtaPhiM(*m_Zprime_pt,*m_Zprime_eta,*m_Zprime_phi,*m_Zprime_m);
}

void Event::setTriggerDetail(const std::string &detailStr)
{
  if(m_triggerInfoSwitch) delete m_triggerInfoSwitch;
  m_triggerInfoSwitch=new TriggerInfoSwitch(detailStr);
}

void Event::initializeJets(const std::string& name, const std::string& detailStr)
{
  m_jets    =new JetContainer   (name, detailStr, 1e3, m_mc);
}

void Event::initializePhotons(const std::string& name, const std::string& detailStr)
{
  m_photons =new PhotonContainer(name, detailStr,1e3,m_mc);
}

void Event::initializeTruth(const std::string& name, const std::string& detailStr)
{
  //m_truth   =new xAH::TruthContainer(name, detailStr);
}

void Event::initializeTrigJets(const std::string& name, const std::string& detailStr)
{
  //m_trigJets=new xAH::JetContainer   (name, detailStr, 1e3, m_mc);
}

