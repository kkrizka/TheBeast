CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(TheBeast)

FIND_PACKAGE(ROOT REQUIRED)
INCLUDE(${ROOT_USE_FILE})



SET(HEADERS
  TheBeast.h
  TheRatPack.h
  TheSampleFile.h

  DijetISREvent.h
  EventHists.h)

SET(SRCS TheBeast.cxx
  TheRatPack.cxx
  TheCave.cxx
  TheEvent.cxx
  TheSample.cxx
  TheSampleFile.cxx
  TheHists.cxx

  InfoSwitch.cxx
  DijetISREvent.cxx
  EventHists.cxx)

ROOT_GENERATE_DICTIONARY(G__TheBeast ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(TheBeast SHARED ${SRCS} G__TheBeast.cxx)
TARGET_LINK_LIBRARIES(TheBeast ${ROOT_LIBRARIES})
