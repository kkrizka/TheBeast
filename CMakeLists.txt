CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(TheBeast)

FIND_PACKAGE(ROOT REQUIRED)
INCLUDE(${ROOT_USE_FILE})



SET(HEADERS
  TheBeast.h
  TheRatPack.h
  TheSampleFile.h
  TheSampleSelection.h
  TheSelection.h

  DijetISREvent.h
  EventHists.h
  ZprimeResonanceHists.h
  ZprimeGammaJetJetSelection.h)

SET(SRCS TheBeast.cxx
  TheRatPack.cxx
  TheCave.cxx
  TheEvent.cxx
  TheSample.cxx
  TheSampleFile.cxx
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
  ZprimeResonanceHists.cxx
  ZprimeGammaJetJetSelection.cxx)

ROOT_GENERATE_DICTIONARY(G__TheBeast ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(TheBeast SHARED ${SRCS} G__TheBeast.cxx)
TARGET_LINK_LIBRARIES(TheBeast ${ROOT_LIBRARIES})
