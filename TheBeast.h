#ifndef THEBEAST_H_
#define THEBEAST_H_

#include <map>

#include "TheCave.h"
#include "TheRatPack.h"
#include "TheSample.h"

class TheBeast
{
public:
  static TheBeast *rawr();

  TheRatPack* ratPack();

  void addSample(const std::string& name, TheSample *sample);

  TH1* get(const std::string& samplename, const std::string& histname);

private:
  static TheBeast *m_beast;
  
  TheBeast();

  TheCave m_cave;
  TheRatPack m_ratpack;
  std::map<std::string, TheSample*> m_samples;
};

#endif // THEBEAST_H_
