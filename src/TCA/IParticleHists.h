#ifndef IPARTICLEHISTS_H_
#define IPARTICLEHISTS_H_

#include "../TheHists.h"

#include "../xAH/Particle.h"

#include "Event.h"

namespace TCA
{
  class IParticleHists : public TheHists
  {
  public:

    IParticleHists(Event::Container container, int idx, const std::string& title="");
    virtual ~IParticleHists() ;

    virtual void initialize(TheEvent *event);
    virtual void execute();

  protected:
    Event *m_event;

    Event::Container m_container;
    int m_idx;
    std::string m_title;

  private:
    //basic
    TH1* m_Pt_l;                //!
    TH1* m_Pt;                  //!
    TH1* m_Pt_m;                //!
    TH1* m_Pt_s;                //!
    TH1* m_Eta;                 //!
    TH1* m_Phi;                 //!
    TH1* m_M;                   //!
    TH1* m_E;                   //!
    TH1* m_Rapidity;            //!

    // kinematic
    TH1* m_Px;                  //!
    TH1* m_Py;                  //!
    TH1* m_Pz;                  //!
    TH1* m_Et;                  //!
    TH1* m_Et_m;                //!
    TH1* m_Et_s;                //!
  };
}

#endif // IPARTICLEHISTS_H_
