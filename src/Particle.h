#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <TLorentzVector.h>

class Particle : public TObject
{
  ClassDef(Particle, 1);
public:

  Particle() {};
  virtual ~Particle() {}

  TLorentzVector p4;
};

#endif // PARTICLE_H_
