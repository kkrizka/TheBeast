#include "TheSampleFile.h"

#include <iostream>

TheSampleFile::TheSampleFile(const std::string& path, const std::string& tree, TheEvent *event)
  : TheSample(),m_event(event)
{
  // Open the tree
  m_fh=TFile::Open(path.c_str());
  m_tree=dynamic_cast<TTree*>(m_fh->Get(tree.c_str()));
  m_event->setTree(m_tree);
}

TheSampleFile::~TheSampleFile()
{
  m_tree=0;
  m_fh->Close();
}

TheEvent* TheSampleFile::event() const
{ return m_event; }

uint TheSampleFile::nEvents() const
{ return m_tree->GetEntries(); }

void TheSampleFile::loadEvent(uint eidx) const
{ m_tree->GetEntry(eidx); }
