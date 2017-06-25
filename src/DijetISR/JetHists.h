#ifndef DIJETISRJETHISTS_H_
#define DIJETISRJETHISTS_H_

#include "IParticleHists.h"

namespace DijetISR
{
  class JetHists : public IParticleHists
  {
  public:
    JetHists(Event::Container container, int idx, const std::string& titleprefix="jet");
    virtual ~JetHists() ;

    virtual void initialize(TheEvent *event);
    virtual void execute();

  private:
    // clean
    TH1 *h_LeadingClusterSecondR;
    TH1 *h_HECQuality;
    TH1 *h_N90Constituents;
    TH1 *h_Timing;
    TH1 *h_LArBadHVEFrac;
    TH1 *h_AverageLArQF;
    TH1 *h_LeadingClusterSecondLambda;
    TH1 *h_LeadingClusterPt;
    TH1 *h_LeadingClusterCenterLambda;
    TH1 *h_LArBadHVNCell;
    TH1 *h_OotFracClusters10;
    TH1 *h_NegativeE;
    TH1 *h_OotFracClusters5;
    TH1 *h_LArQuality;
    TH1 *h_clean_passLooseBadUgly;
    TH1 *h_clean_passTightBad;
    TH1 *h_BchCorrCell;
    TH1 *h_clean_passTightBadUgly;
    TH1 *h_clean_passLooseBad;
    // rapidity
    TH1 *h_rapidity;
    // energy
    TH1 *h_Width;
    TH1 *h_EMFrac;
    TH1 *h_LowEtConstituentsFrac;
    TH1 *h_HECFrac;
    TH1 *h_GhostMuonSegmentCount;
    TH1 *h_CentroidR;
    TH1 *h_FracSamplingMaxIndex;
    TH1 *h_FracSamplingMax;
  };
}

#endif // JETHISTS_H_
