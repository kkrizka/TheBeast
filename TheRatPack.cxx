#include "TheRatPack.h"

TheRatPack::TheRatPack()
{ }

void TheRatPack::addHists(const std::string& name, TheHists *hists)
{
  m_hists[name]=hists;
}

void TheRatPack::execute(const std::string& histname, TheSample *sample, TDirectory *output)
{
  TheHists *hists=m_hists[histname];
  TDirectory *outdir=output->mkdir(histname.c_str());
  hists->setOutput(outdir);

  hists->initialize(sample->event());

  for(uint eidx=0; eidx<sample->nEvents(); eidx++)
    {
      sample->loadEvent(eidx);
      hists->execute();
    }

  outdir->Write();
}
