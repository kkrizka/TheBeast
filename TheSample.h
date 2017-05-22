#ifndef THESAMPLE_H_
#define THESAMPLE_H_

#include <TDirectory.h>
#include <TTree.h>

#include "TheEvent.h"

class TheSample
{
public:
  TheSample();

  virtual TheEvent* event() const =0;

  virtual uint nEvents() const =0;
  virtual void loadEvent(uint eidx) const =0;

protected:
  TTree *m_tree;
};

#endif // THESAMPLE_H_
