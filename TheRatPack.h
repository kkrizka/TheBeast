#ifndef THERATPACK_H_
#define THERATPACK_H_

#include <map>

#include <TH1.h>

struct HistDefinition
{
  std::string name;
  std::string branch;

  std::string xtitle;

  int nbins;
  double minval;
  double maxval;
};

class TheRatPack
{
public:
  TheRatPack();

  void defineHistogram(const std::string& name, const std::string& xtitle, int nbins, double minval, double maxval, const std::string& branch="");

  HistDefinition histDefinition(const std::string& name) const;

private:
  std::map<std::string, HistDefinition> m_histDefinitions;
};

#endif // THERATPACK_H_
