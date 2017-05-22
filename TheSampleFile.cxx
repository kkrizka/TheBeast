#include "TheSampleFile.h"

TheSampleFile::TheSampleFile(const std::string& path, const std::string& tree)
  : TheSample()
{
  m_fh=TFile::Open(path.c_str());
  m_tree=dynamic_cast<TTree*>(m_fh->Get(tree.c_str()));
}

TheSampleFile::~TheSampleFile()
{
  m_tree=0;
  m_fh->Close();
}
