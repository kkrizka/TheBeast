#ifndef THERATPACK_H_
#define THERATPACK_H_

#include <map>

#include "TheHists.h"
#include "TheSample.h"

#include <TDirectory.h>
#include <TH1.h>

class TheRatPack
{
public:
  TheRatPack();

  void addHists(const std::string& name, TheHists *hists);

  void execute(const std::string& histname, TheSample *sample, TDirectory *output);

private:
  std::map<std::string, TheHists*> m_hists;
};

#endif // THERATPACK_H_
