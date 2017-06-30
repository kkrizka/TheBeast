#ifndef Event_H_
#define Event_H_

#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>

#include "../TheEvent.h"

#include "InfoSwitch.h"
#include "JetContainer.h"
#include "PhotonContainer.h"

namespace DijetISR
{
  class Event : public TheEvent
  {
  public:
    enum Container {jet, photon};

    Event(bool mc, bool truthOnly);
    virtual ~Event();

    void setReader(TTreeReader *reader);
    void updateEntry();

    void setTriggerDetail(const std::string& detailStr);

    void initializeJets    (const std::string& name, const std::string& detailStr);
    void initializePhotons (const std::string& name, const std::string& detailStr);
    void initializeTruth   (const std::string& name, const std::string& detailStr);
    void initializeTrigJets(const std::string& name, const std::string& detailStr);

  public:
    // Event variables
    TTreeReaderValue<float> m_ht;
    TTreeReaderValue<int  > m_NPV;
    TTreeReaderValue<float> m_actualInteractionsPerCrossing;
    TTreeReaderValue<float> m_averageInteractionsPerCrossing;
    TTreeReaderValue<int  > m_runNumber;
    TTreeReaderValue<long long> m_eventNumber;
    TTreeReaderValue<int  > m_lumiBlock;

    TTreeReaderValue<int  > m_mcEventNumber;
    TTreeReaderValue<int  > m_mcChannelNumber;
    TTreeReaderValue<float> m_mcEventWeight;

    // trigger
    TTreeReaderValue<std::vector<std::string> > m_passedTriggers;
    TTreeReaderValue<std::vector<float> >       m_triggerPrescales;

    // weights
    TTreeReaderValue<float> m_weight;
    TTreeReaderValue<float> m_weight_xs;
    TTreeReaderValue<float> m_weight_pileup;

    // particles
    JetContainer    *m_jets;
    PhotonContainer *m_photons;
    //xAH::TruthContainer  *m_truth;
    //xAH::JetContainer    *m_trigJets;

    // custom
    bool m_haveZprime;
    TTreeReaderValue<float> m_Zprime_pt;
    TTreeReaderValue<float> m_Zprime_eta;
    TTreeReaderValue<float> m_Zprime_phi;
    TTreeReaderValue<float> m_Zprime_m;

    TLorentzVector m_Zprime;

  private:
    bool m_truthOnly;
    bool m_mc;

    TriggerInfoSwitch *m_triggerInfoSwitch;
  };
}

#endif // Event_H_
