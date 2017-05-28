#ifndef THESELECTION_H_
#define THESELECTION_H_

#include "TheEvent.h"

class TheSelection
{
public:
  TheSelection();

  virtual void initialize(TheEvent *event) =0;
  virtual bool passes() =0;
};

#endif // THESELECTION_H_
