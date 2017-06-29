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

  m_chain->SetCacheSize(128*1024*1024);
  m_chain->SetCacheLearnEntries(10000);
  m_chain->AddBranchToCache("*");

  // Create the reader
  m_reader=new TTreeReader(m_chain);
  m_event->setReader(m_reader);
}

TheSampleList::~TheSampleList()
{
  delete m_chain;
  delete m_reader;
}

TheEvent* TheSampleList::event() const
{ return m_event; }

uint TheSampleList::nEvents() const
{ return m_reader->GetEntries(false); }

void TheSampleList::loadEvent(uint eidx) const
{
  //m_chain->GetEntry(eidx);
  m_reader->SetEntry(eidx);
  m_event->updateEntry();
}
