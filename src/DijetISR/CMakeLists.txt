SET(HEADERS
  Event.h
  EventHists.h
  IParticleHists.h
  JetHists.h
  ZprimeResonanceHists.h
  ZprimeGammaJetJetSelection.h)

SET(SRCS
  InfoSwitch.cxx
  Event.cxx  
  JetContainer.cxx
  MuonContainer.cxx
  PhotonContainer.cxx
  EventHists.cxx
  IParticleHists.cxx
  JetHists.cxx
  ZprimeResonanceHists.cxx
  ZprimeGammaJetJetSelection.cxx)

ROOT_GENERATE_DICTIONARY(G__DijetISR ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(DijetISR SHARED ${SRCS} G__DijetISR.cxx)
TARGET_LINK_LIBRARIES(DijetISR ${ROOT_LIBRARIES} TheBeast xAH)
