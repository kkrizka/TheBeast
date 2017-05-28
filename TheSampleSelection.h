#ifndef THESAMPLESELECTION_H_
#define THESAMPLESELECTION_H_

#include "TheSample.h"
#include "TheSelection.h"
#include "TheEvent.h"

class TheSampleSelection : public TheSample
{
public:
  TheSampleSelection(TheSample *source, TheSelection *selection);
  ~TheSampleSelection();

  TheEvent* event() const;

  uint nEvents() const;
  void loadEvent(uint eidx) const;

  void runSelection();

protected:
  virtual bool passes();
  
private:
  TheSample *m_source;
  TheSelection *m_selection;
  std::vector<uint> m_eventIdxs;
};

#endif // THESAMPLESELECTION_H_
