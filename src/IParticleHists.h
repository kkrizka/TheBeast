#ifndef IPARTICLEHISTS_H_
#define IPARTICLEHISTS_H_

#include "TheHists.h"

#include "DijetISREvent.h"
#include "Particle.h"

class IParticleHists : public TheHists
{
public:

  IParticleHists(DijetISREvent::Container container, int idx, const std::string& title="");
  virtual ~IParticleHists() ;

  virtual void initialize(TheEvent *event);
  virtual void execute();

protected:
  DijetISREvent *m_event;

  DijetISREvent::Container m_container;
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

#endif // IPARTICLEHISTS_H_
