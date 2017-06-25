#ifndef ZPRIMERESONANCEHISTS_H_
#define ZPRIMERESONANCEHISTS_H_

#include "../TheHists.h"

#include "Event.h"

namespace TCA {
  class ZprimeResonanceHists : public TheHists
  {
  public:
    ZprimeResonanceHists();

    virtual void initialize(TheEvent *event);
    virtual void execute();

  private:
    Event *m_event;

    //basic
    TH1* h_ptjj;
    TH1* h_ptjj_l;
    TH1* h_etajj;
    TH1* h_phijj;
    TH1* h_mjj;
    TH1* h_mjj_var;
    TH1* h_mjj_fine;

    TH1* h_dEtajj;
    TH1* h_dPhijj;
    TH1* h_dRjj;

    TH1* h_yStarjj;
    TH1* h_yBoostjj;
    TH1* h_chijj;
    TH1* h_yStarjjBoostjj;

    TH1* h_asymjj;
    TH1* h_vecasymjj;
    TH1* h_projasymjj;

    TH1* h_chargediff;
    TH1* h_chargesum;

    // 2d
    TH2* h_mjj_vs_reso0;
    TH2* h_mjj_vs_reso1;

    TH2* h_mjj_vs_dEtajj;
    TH2* h_mjj_vs_dPhijj;
    TH2* h_mjj_vs_dRjj;

    TH2* h_dPhijj_vs_dEtajj;
  };
}

#endif // ZPRIMERESONANCEHISTS_H_
