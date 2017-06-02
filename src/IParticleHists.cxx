#include "IParticleHists.h"

#include <sstream>

IParticleHists::IParticleHists(DijetISREvent::Container container, int idx, const std::string& title) :
  TheHists(),
  m_container(container),m_idx(idx),m_title(title)
{ }

IParticleHists::~IParticleHists ()
{ }

void IParticleHists::initialize(TheEvent *event)
{
  m_event=dynamic_cast<DijetISREvent*>(event);

  // These plots are always made
  m_Pt_l      = book("Pt_l",     m_title+" p_{T} [GeV]", 120, 0, 3000.);
  m_Pt        = book("Pt",       m_title+" p_{T} [GeV]", 100, 0, 1000.);
  m_Pt_m      = book("Pt_m",     m_title+" p_{T} [GeV]", 100, 0,  500.);
  m_Pt_s      = book("Pt_s",     m_title+" p_{T} [GeV]", 200, 0,  200.);
  m_Eta       = book("Eta",      m_title+" #eta",         80, -4, 4);
  m_Phi       = book("Phi",      m_title+" Phi",         120, -TMath::Pi(), TMath::Pi() );
  m_M         = book("Mass",     m_title+" Mass [GeV]",  120, 0, 400);
  m_E         = book("Energy",   m_title+" Energy [GeV]",120, 0, 4000.);
  m_Rapidity  = book("Rapidity", m_title+" Rapidity",    120, -10, 10);

  // details of the particle kinematics
  m_Px        = book("Px",       m_title+" Px [GeV]",    120, 0, 1000);
  m_Py        = book("Py",       m_title+" Py [GeV]",    120, 0, 1000);
  m_Pz        = book("Pz",       m_title+" Pz [GeV]",    120, 0, 4000);

  m_Et        = book("Et",       m_title+" E_{T} [GeV]", 100, 0, 1000.);
  m_Et_m      = book("Et_m",     m_title+" E_{T} [GeV]", 100, 0,  500.);
  m_Et_s      = book("Et_s",     m_title+" E_{T} [GeV]", 100, 0,  100.);
}

void IParticleHists::execute()
{
  IParticleInfoSwitch *infoSwitch;
  TLorentzVector partP4;
  switch(m_container)
    {
    case DijetISREvent::jet:
      partP4    = m_event->m_jets   ->at(m_idx).p4;
      infoSwitch=&m_event->m_jets   ->m_infoSwitch;
      break;
    case DijetISREvent::photon:
      partP4    = m_event->m_photons->at(m_idx).p4;
      infoSwitch=&m_event->m_photons->m_infoSwitch;
      break;
    }
  
  //
  // Figure out event stuff
  double eventWeight=1.;

  //basic
  m_Pt_l ->      Fill( partP4.Pt(),       eventWeight );
  m_Pt ->        Fill( partP4.Pt(),       eventWeight );
  m_Pt_m ->      Fill( partP4.Pt(),       eventWeight );
  m_Pt_s ->      Fill( partP4.Pt(),       eventWeight );
  m_Eta->        Fill( partP4.Eta(),      eventWeight );
  m_Phi->        Fill( partP4.Phi(),      eventWeight );
  m_M->          Fill( partP4.M(),        eventWeight );
  m_E->          Fill( partP4.E(),        eventWeight );
  m_Rapidity->   Fill( partP4.Rapidity(), eventWeight );

  // kinematic
  if( infoSwitch->m_kinematic ) {
    m_Px   ->Fill( partP4.Px(),  eventWeight );
    m_Py   ->Fill( partP4.Py(),  eventWeight );
    m_Pz   ->Fill( partP4.Pz(),  eventWeight );

    m_Et   ->Fill( partP4.Et(),  eventWeight );
    m_Et_m ->Fill( partP4.Et(),  eventWeight );
    m_Et_s ->Fill( partP4.Et(),  eventWeight );
  } // fillKinematic
}

