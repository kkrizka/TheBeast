#ifndef TRACKPARTICLE_H_
#define TRACKPARTICLE_H_

#include "Particle.h"

namespace xAH {
  class TrackParticle : public Particle
  {
    ClassDef(TrackParticle, 1);
  public:
    TrackParticle() : Particle() {};
    virtual ~TrackParticle() {};
  };
};

#endif // TRACKPARTICLE_H_
