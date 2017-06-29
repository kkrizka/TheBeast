FIND_PACKAGE(ROOT REQUIRED)
INCLUDE(${ROOT_USE_FILE})

SET(HEADERS
  TheBeast.h
  TheRatPack.h
  TheSampleFile.h
  TheSampleList.h
  TheSampleSelection.h
  TheSelection.h
  )

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
  )

ROOT_GENERATE_DICTIONARY(G__TheBeast ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(TheBeast SHARED ${SRCS} G__TheBeast.cxx)
TARGET_LINK_LIBRARIES(TheBeast ${ROOT_LIBRARIES} TreePlayer)

ADD_SUBDIRECTORY(xAH)
ADD_SUBDIRECTORY(DijetISR)
ADD_SUBDIRECTORY(TCA)
