#ifndef EVENTHISTS_H_
#define EVENTHISTS_H_

#include "../TheHists.h"

#include "Event.h"

namespace TCA
{
  class EventHists : public TheHists
  {
  public:
    EventHists();

    virtual void initialize(TheEvent *event);
    virtual void execute();

  private:
    Event *m_event;

    //histograms
    TH1* h_NPV;
    TH1* h_mu_ave;
    TH1* h_mu_act;

    TH1* h_weight;
  };
}

#endif // EVENTHISTS_H_
