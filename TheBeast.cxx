#include "TheBeast.h"

TheBeast* TheBeast::m_beast=new TheBeast();

TheBeast *TheBeast::rawr()
{ return m_beast; }

TheBeast::TheBeast()
{ }

TheRatPack* TheBeast::ratPack()
{ return &m_ratpack; }

void TheBeast::addSample(const std::string& name, TheSample *sample)
{
  m_samples[name]=sample;
}

TH1* TheBeast::get(const std::string& samplename, const std::string& histname)
{
  TheSample *sample=m_samples[samplename];
  const HistDefinition& def=m_ratpack.histDefinition(histname);

  return sample->histogram(def);
}
