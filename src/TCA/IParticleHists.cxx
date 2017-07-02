#include "IParticleHists.h"

#include <sstream>

using namespace TCA;

IParticleHists::IParticleHists(Event::Container container, int idx, const std::string& title) :
  TheHists(),
  m_container(container),m_idx(idx),m_title(title)
{ }

IParticleHists::~IParticleHists ()
{ }

void IParticleHists::initialize(TheEvent *event)
{
  m_event=dynamic_cast<Event*>(event);

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
  const xAH::Particle *particle=0;
  switch(m_container)
    {
    case Event::jet:
      particle = dynamic_cast<xAH::Particle*>(&m_event->m_jets   ->At(m_idx));
      break;
    case Event::photon:
      particle = dynamic_cast<xAH::Particle*>(&m_event->m_photons->At(m_idx));
      break;
    }
  if(particle==0) return;
  TLorentzVector partP4=particle->p4;
  
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
  m_Px   ->Fill( partP4.Px(),  eventWeight );
  m_Py   ->Fill( partP4.Py(),  eventWeight );
  m_Pz   ->Fill( partP4.Pz(),  eventWeight );

  m_Et   ->Fill( partP4.Et(),  eventWeight );
  m_Et_m ->Fill( partP4.Et(),  eventWeight );
  m_Et_s ->Fill( partP4.Et(),  eventWeight );
}

