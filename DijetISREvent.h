#ifndef DijetISREvent_H_
#define DijetISREvent_H_

#include <TTree.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>

#include "TheEvent.h"

#include "InfoSwitch.h"
#include "JetContainer.h"

class DijetISREvent : public TheEvent
{
public:
  DijetISREvent(bool mc, bool truthOnly);
  virtual ~DijetISREvent();

  void setTree(TTree *t);
  void updateEntry();

  void setTriggerDetail(const std::string& detailStr);

  void initializeJets    (const std::string& name, const std::string& detailStr);
  void initializePhotons (const std::string& name, const std::string& detailStr);
  void initializeTruth   (const std::string& name, const std::string& detailStr);
  void initializeTrigJets(const std::string& name, const std::string& detailStr);

public:
  // Event variables
  float m_ht;
  int m_NPV;
  float m_actualInteractionsPerCrossing;
  float m_averageInteractionsPerCrossing;
  int m_runNumber;
  long long m_eventNumber;
  int m_lumiBlock;

  int m_mcEventNumber;
  int m_mcChannelNumber;
  float m_mcEventWeight;

  // trigger
  std::vector<std::string> *m_passedTriggers;
  std::vector<float>       *m_triggerPrescales;

  // weights
  float m_weight;
  float m_weight_xs;
  float m_weight_pileup;

  // particles
  JetContainer    *m_jets;
  //xAH::PhotonContainer *m_photons;
  //xAH::TruthContainer  *m_truth;
  //xAH::JetContainer    *m_trigJets;

  // custom
  float m_Zprime_pt;
  float m_Zprime_eta;
  float m_Zprime_phi;
  float m_Zprime_m;

  TLorentzVector m_Zprime;

private:
  bool m_truthOnly;
  bool m_mc;
  
  TriggerInfoSwitch *m_triggerInfoSwitch;
};

#endif // DijetISREvent_H_
