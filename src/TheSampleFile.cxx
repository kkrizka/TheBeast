#include "TheSampleFile.h"

#include <iostream>

TheSampleFile::TheSampleFile(const std::string& path, const std::string& tree, TheEvent *event)
  : TheSample(),m_event(event)
{
  // Open the tree
  m_fh=TFile::Open(path.c_str());
  m_tree=dynamic_cast<TTree*>(m_fh->Get(tree.c_str()));

  // Create the reader
  m_reader=new TTreeReader(m_tree);
  m_event->setReader(m_reader);
}

TheSampleFile::~TheSampleFile()
{
  delete m_reader;
  m_fh->Close();
}

TheEvent* TheSampleFile::event() const
{ return m_event; }

uint TheSampleFile::nEvents() const
{ return m_reader->GetEntries(false); }

void TheSampleFile::loadEvent(uint eidx) const
{
  m_reader->SetEntry(eidx);
  m_event->updateEntry();
}
