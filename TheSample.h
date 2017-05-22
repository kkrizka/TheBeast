#ifndef THESAMPLE_H_
#define THESAMPLE_H_

#include <TTree.h>

#include "TheRatPack.h"

class TheSample
{
public:
  TheSample();

  TH1* histogram(const HistDefinition& histDef);

protected:
  TTree *m_tree;

  std::map<std::string, TH1*> m_hists;
};

#endif // THESAMPLE_H_
