#include "TheSampleSelection.h"

#include "DijetISREvent.h"
#include <iostream>

TheSampleSelection::TheSampleSelection(TheSample *source, TheSelection *selection)
  : TheSample(), m_source(source), m_selection(selection)
{ }

TheSampleSelection::~TheSampleSelection()
{ }

TheEvent* TheSampleSelection::event() const
{ return m_source->event(); }

uint TheSampleSelection::nEvents() const
{ return m_eventIdxs.size(); }

void TheSampleSelection::loadEvent(uint eidx) const
{ m_source->loadEvent(m_eventIdxs[eidx]); }

void TheSampleSelection::runSelection()
{
  m_eventIdxs.clear();

  m_selection->initialize(m_source->event());
  for(uint eidx=0; eidx<m_source->nEvents(); eidx++)
    {
      m_source->loadEvent(eidx);
      if(m_selection->passes()) m_eventIdxs.push_back(eidx);
    }
}

bool TheSampleSelection::passes()
{
  DijetISREvent *anevent=dynamic_cast<DijetISREvent*>(event());
  std::cout << "FOUND EVENT " << anevent << " " << event() << std::endl;
  if(anevent->m_jets->size()<2) return false;
  return true;
}
