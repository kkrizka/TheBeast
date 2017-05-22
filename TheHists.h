#ifndef THEHISTS_H_
#define THEHISTS_H_

#include <TDirectory.h>
#include <TH1.h>

#include "TheEvent.h"

class TheHists
{
public:
  TheHists();

  void setOutput(TDirectory *output);
  
  virtual void initialize(TheEvent *event) =0;
  virtual void execute() =0;

protected:
  TH1* book(const std::string &name, const std::string &xtitle, uint nbins, double minval, double maxval);
  
private:
  TDirectory *m_output;
};

#endif // THEHISTS_H_
