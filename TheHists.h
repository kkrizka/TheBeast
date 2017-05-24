#ifndef THEHISTS_H_
#define THEHISTS_H_

#include <TDirectory.h>
#include <TH1.h>
#include <TH2.h>

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
  TH2* book(const std::string &name, const std::string &xtitle, uint nxbins, double minxval, double maxxval,
	                             const std::string &ytitle, uint nybins, double minyval, double maxyval);
  
private:
  TDirectory *m_output;
};

#endif // THEHISTS_H_
