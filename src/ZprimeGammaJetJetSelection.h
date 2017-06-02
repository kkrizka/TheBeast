#ifndef ZPRIMEGAMMAJETJETSELECTION_H_
#define ZPRIMEGAMMAJETJETSELECTION_H_

#include "TheSelection.h"

#include "DijetISREvent.h"

class ZprimeGammaJetJetSelection : public TheSelection
{
public:
  double m_minPhotonPt;     // minimum photon pt
  uint m_doBarrelEndCap;    // include barrel (bit 0)/endcap (bit 1) photons
  bool m_phTrigMatch;       // photon must be matched to a trigger object
  bool m_emuTrigJet;        // Emulate 50 GeV cut on the trigger jets
  bool m_emuTrigJetOverlap; // Require that one of the trigger jets overlaps with the photon

public:
  ZprimeGammaJetJetSelection();

  virtual void initialize(TheEvent *event);
  virtual bool passes();

private:
  DijetISREvent *m_event;
};

#endif // ZPRIMEGAMMAJETJETSELECTION_H_
