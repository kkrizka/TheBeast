#include "ZprimeGammaJetJetSelection.h"

#include "../xAH/Photon.h"

using namespace TCA;

ZprimeGammaJetJetSelection::ZprimeGammaJetJetSelection ()
  : TheSelection()
{
  m_minPhotonPt       = 10;
  m_doBarrelEndCap    = 3;
  m_phTrigMatch       = false;
  m_emuTrigJet        = false;
  m_emuTrigJetOverlap = false;
}

void ZprimeGammaJetJetSelection::initialize(TheEvent *event)
{
  m_event=dynamic_cast<Event*>(event);
}

bool ZprimeGammaJetJetSelection::passes()
{
  //
  // dijet+gamma
  uint njets    = m_event->m_jets->GetEntries();
  uint nphotons = m_event->m_photons->GetEntries();

  if(njets < 2)
    return false;
  //m_cutflow->execute(m_cf_njets,m_eventWeight);

  if(nphotons < 1)
    return false;
  //m_cutflow->execute(m_cf_nphotons,m_eventWeight);

  const xAH::Photon* photon0=dynamic_cast<xAH::Photon*>(m_event->m_photons->At(0));

  //
  // photon
  if(photon0->p4.Pt() < m_minPhotonPt)
    return false;
  //if(m_mc) m_eventWeight*=photon0.TightEffSF;
  //m_cutflow->execute(m_cf_photon,m_eventWeight);

  //
  // trigger matching
  // if(m_phTrigMatch)
  //   {
  //     bool passTrigMatch=true;
  //     for(const std::string& trigger : m_triggers)
  // 	passTrigMatch &= (std::find(photon0.trigMatched.begin(), photon0.trigMatched.end(), trigger ) != photon0.trigMatched.end());

  //     if(!passTrigMatch)
  // 	return false;
  //     //m_cutflow->execute(m_cf_phTrigMatch, m_eventWeight);
  //   }

  // if(m_emuTrigJet)
  //   {
  //     unsigned int nTrigJets=0;
  //     for(unsigned int idx=0; idx<m_event->m_trigJets->size(); idx++)
  // 	if(m_event->m_trigJets->at(idx).p4.Pt()>50) nTrigJets++;
      
  //     if(nTrigJets<3)
  // 	return false;
  //     //m_cutflow->execute(m_cf_emuTrigJet, m_eventWeight);
  //   }

  // if(m_emuTrigJetOverlap)
  //   {
  //     bool passTrigJetOverlap=false;
  //     for(unsigned int idx=0; idx<std::min<uint>(3,m_event->m_trigJets->size()); idx++)
  // 	if(photon0.p4.DeltaR(m_event->m_trigJets->at(idx).p4)<0.2) { passTrigJetOverlap=true; break; }
      
  //     if(!passTrigJetOverlap)
  // 	return false;
  //     //m_cutflow->execute(m_cf_emuTrigJetOverlap, m_eventWeight);
  //   }


  //
  // Barrel vs endcap
 switch(m_doBarrelEndCap)
   {
   case 1:
     if(!(fabs(photon0->p4.Eta())<1.37))
       return false;
     //m_cutflow->execute(m_cf_barrelendcap,m_eventWeight);
     break;
   case 2:
     if(!(1.52<fabs(photon0->p4.Eta()) && fabs(photon0->p4.Eta())<2.37))
       return false;
     //m_cutflow->execute(m_cf_barrelendcap,m_eventWeight);
     break;
   default:
     break;
   }

  //
  // Setup objects
  //
  //m_reso0=&m_event->m_jets->at(0);
  //m_reso1=&m_event->m_jets->at(1);
  //m_isr  =&photon0;

  return true;
}
