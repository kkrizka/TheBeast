#include "TheBeast.h"

#include <iostream>

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
  m_cave.openFile(name);
}

TH1* TheBeast::get(const std::string& samplename, const std::string& histname)
{
  TH1 *hist=m_cave.get(samplename, histname);
  if(!hist)
    {
      std::cout << "Remake " << samplename << "/" << histname << std::endl;

      std::string::size_type pos = histname.find('/');
      if(pos == std::string::npos)
	{
	  std::cerr << "Histogram name must be histmaker/hist" << std::endl;
	  return 0;
	}
      std::string histmaker=histname.substr(0, pos);
      TheSample *sample=m_samples[samplename];
      m_ratpack.execute(histmaker, sample, m_cave.output(samplename));
    }
  return m_cave.get(samplename, histname);
}
