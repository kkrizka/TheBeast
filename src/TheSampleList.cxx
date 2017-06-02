#include "TheSampleList.h"

#include <iostream>
#include <fstream>

TheSampleList::TheSampleList(const std::string& path, const std::string& tree, TheEvent *event)
  : TheSample(), m_event(event)
{
  // Create the chain
  m_chain=new TChain(tree.c_str());
  std::ifstream ifs(path);
  std::string line;
  while(std::getline(ifs, line))
    {
      std::cout << line << std::endl;
      m_chain->Add(line.c_str());
    }
  m_event->setTree(m_chain);

  m_chain->SetCacheSize(128*1024*1024);
  m_chain->SetCacheLearnEntries(10000);
  m_chain->AddBranchToCache("*");
}

TheSampleList::~TheSampleList()
{
  delete m_chain; m_chain=0;
}

TheEvent* TheSampleList::event() const
{ return m_event; }

uint TheSampleList::nEvents() const
{ return m_chain->GetEntries(); }

void TheSampleList::loadEvent(uint eidx) const
{
  m_chain->GetEntry(eidx);
  m_event->updateEntry();
}
