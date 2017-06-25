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
  EventHists.cxx
  IParticleHists.cxx
  JetHists.cxx
  ZprimeResonanceHists.cxx
  ZprimeGammaJetJetSelection.cxx)

ROOT_GENERATE_DICTIONARY(G__TCA ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(TCA SHARED ${SRCS} G__TCA.cxx)
TARGET_LINK_LIBRARIES(TCA ${ROOT_LIBRARIES} TheBeast xAH)
