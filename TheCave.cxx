#include "TheCave.h"

TheCave::TheCave()
{ }

TheCave::~TheCave()
{
  for(auto kv : m_fhs)
    {
      kv.second->Close();
    }
}

void TheCave::openFile(const std::string& sample)
{
  m_fhs[sample]=TFile::Open(("output/OUT_"+sample+".root").c_str(),"RECREATE");
  m_outputs[sample]=m_fhs[sample];
}

TDirectory* TheCave::output(const std::string& sample) const
{ return m_outputs.at(sample); }

TObject* TheCave::get(const std::string&sample, const std::string& histname)
{ return m_outputs[sample]->Get(histname.c_str()); }
