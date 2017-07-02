#include "Event.h"

#include <iostream>

using namespace TCA;

Event::Event(bool mc, bool truthOnly)
  : TheEvent(),
    m_haveZprime(false),
    m_truthOnly(truthOnly), m_mc(mc),
    m_jets(0), m_photons(0),
    m_triggerInfoSwitch(0)
{
  setTriggerDetail("");
}

Event::~Event()
{
  if(m_triggerInfoSwitch) delete m_triggerInfoSwitch;

  if(m_jets)    delete m_jets;
  if(m_photons) delete m_photons;
  //if(m_truth)    delete m_truth;
  //if(m_trigJets) delete m_trigJets;
}

void Event::setReader(TTreeReader *reader)
{
  TheEvent::setReader(reader);

  // Event info
  m_runNumber=TTreeReaderValue<int>(*reader, "runNumber");
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
  m_jets   =new TTreeReaderArray<xAH::Jet   >(*reader, "jet");
  m_photons=new TTreeReaderArray<xAH::Photon>(*reader, "ph");

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
  // if(m_truth)    m_truth   ->updateEntry();
  // if(m_trigJets) m_trigJets->updateEntry();

  if(m_haveZprime)
    m_Zprime.SetPtEtaPhiM(*m_Zprime_pt,*m_Zprime_eta,*m_Zprime_phi,*m_Zprime_m);
}

void Event::setTriggerDetail(const std::string &detailStr)
{
  if(m_triggerInfoSwitch) delete m_triggerInfoSwitch;
  m_triggerInfoSwitch=new TriggerInfoSwitch(detailStr);
}

