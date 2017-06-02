#include "TheRatPack.h"

#include <iostream>
#include <ctime>

TheRatPack::TheRatPack()
{ }

void TheRatPack::addHists(const std::string& name, TheHists *hists)
{
  m_hists[name]=hists;
}

void TheRatPack::execute(const std::string& histname, TheSample *sample, TDirectory *output)
{
  // for(auto kv : m_hists)
  //   {
  //     std::string histname=kv.first;
  //     TheHists *hists=kv.second;
  //     TDirectory *outdir=output->mkdir(histname.c_str());
  //     hists->setOutput(outdir);
  //     hists->initialize(sample->event());
  //   }
  TheHists *hists=m_hists[histname];
  TDirectory *outdir=output->mkdir(histname.c_str());
  hists->setOutput(outdir);
  hists->initialize(sample->event());


  std::clock_t begin;

  for(uint eidx=0; eidx<sample->nEvents(); eidx++)
    {
      sample->loadEvent(eidx);
      //for(auto kv : m_hists)
      //kv.second->execute();
      hists->execute();

      if(eidx%10000==0)
	{
	  std::cout << "Processing event " << eidx;
	  if(eidx>0)
	    {
	      std::clock_t end = std::clock();
	      double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	      std::cout << " (rate: " << 10./elapsed_secs << " kHz)";
	    }
	  std::cout << std::endl;
	  begin = std::clock();
	}
    }

  outdir->Write();
}
