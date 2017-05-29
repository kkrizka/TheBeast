#ifndef THESAMPLEFILE_H_
#define THESAMPLEFILE_H_

#include <TFile.h>
#include <TTree.h>

#include "TheSample.h"
#include "TheEvent.h"

class TheSampleFile : public TheSample
{
public:
  TheSampleFile(const std::string& path, const std::string& tree, TheEvent* event);
  ~TheSampleFile();

  TheEvent* event() const;

  uint nEvents() const;
  void loadEvent(uint eidx) const;

private:
  TFile *m_fh;
  TTree *m_tree;
  TheEvent *m_event;
};

#endif // THESAMPLEFILE_H_
