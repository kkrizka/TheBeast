SET(HEADERS
  Particle.h
  Jet.h
  FatJet.h
  Photon.h
  Muon.h
  TrackParticle.h
  JetConstituent.h
)

SET(SRCS)

ROOT_GENERATE_DICTIONARY(G__xAH ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(xAH SHARED ${SRCS} G__xAH.cxx)
TARGET_LINK_LIBRARIES(xAH ${ROOT_LIBRARIES} TheBeast)
