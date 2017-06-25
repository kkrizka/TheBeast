#ifndef JETCONSTITUENT_H_
#define JETCONSTITUENT_H_

#include "Particle.h"

namespace xAH {
  class JetConstituent : public Particle
  {
    ClassDef(JetConstituent, 1);
  public:
    JetConstituent() : Particle() {};
    virtual ~JetConstituent() {};
  };
};

#endif // JETCONSTITUENT_H_
