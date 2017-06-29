#ifndef THESAMPLELIST_H_
#define THESAMPLELIST_H_

#include <TFile.h>
#include <TChain.h>
#include <TTreeReader.h>

#include "TheSample.h"
#include "TheEvent.h"

class TheSampleList : public TheSample
{
public:
  TheSampleList(const std::string& path, const std::string& tree, TheEvent* event);
  ~TheSampleList();

  TheEvent* event() const;

  uint nEvents() const;
  void loadEvent(uint eidx) const;

private:
  TTreeReader *m_reader;
  TChain *m_chain;
  TheEvent *m_event;
};

#endif // THESAMPLEFILE_H_
