FIND_PACKAGE(ROOT REQUIRED)
INCLUDE(${ROOT_USE_FILE})

SET(HEADERS
  TheBeast.h
  TheRatPack.h
  TheSampleFile.h
  TheSampleList.h
  TheSampleSelection.h
  TheSelection.h

  DijetISREvent.h
  Particle.h
  Jet.h
  EventHists.h
  IParticleHists.h
  JetHists.h
  ZprimeResonanceHists.h
  ZprimeGammaJetJetSelection.h)

SET(SRCS TheBeast.cxx
  TheRatPack.cxx
  TheCave.cxx
  TheEvent.cxx
  TheSample.cxx
  TheSampleFile.cxx
  TheSampleList.cxx
  TheSampleSelection.cxx
  TheSelection.cxx
  TheHists.cxx

  InfoSwitch.cxx
  DijetISREvent.cxx  
  JetContainer.cxx
  MuonContainer.cxx
  PhotonContainer.cxx
  Jet.cxx
  Photon.cxx
  EventHists.cxx
  IParticleHists.cxx
  JetHists.cxx
  ZprimeResonanceHists.cxx
  ZprimeGammaJetJetSelection.cxx)

ROOT_GENERATE_DICTIONARY(G__TheBeast ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(TheBeast SHARED ${SRCS} G__TheBeast.cxx)
TARGET_LINK_LIBRARIES(TheBeast ${ROOT_LIBRARIES})
