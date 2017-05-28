#ifndef PHOTON_H_
#define PHOTON_H_

#include "Particle.h"

class Photon : public Particle
{
public:
  // isolation
  int    isIsolated_Cone40CaloOnly;
  int    isIsolated_Cone40;
  int    isIsolated_Cone20;
  float  ptcone20;
  float  ptcone30;
  float  ptcone40;
  float  ptvarcone20;
  float  ptvarcone30;
  float  ptvarcone40;
  float  topoetcone20;
  float  topoetcone30;
  float  topoetcone40;
  
  // PID
  int   IsLoose;
  int   IsMedium;
  int   IsTight;
  
  //Purity
  float  radhad1;
  float  radhad;
  float  e277;
  float  reta;
  float  rphi;
  float  weta2;
  float  f1;
  float  wtot;
  float  deltae;
  float  eratio;

  // effSF
  float LooseEffSF;
  float MediumEffSF;
  float TightEffSF;

  float LooseEffSF_Error;
  float MediumEffSF_Error;
  float TightEffSF_Error;

  // trigger
  std::vector<std::string> trigMatched;
};

#endif // PHOTON_H_