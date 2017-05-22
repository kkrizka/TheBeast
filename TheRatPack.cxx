#include "TheRatPack.h"

TheRatPack::TheRatPack()
{ }

void TheRatPack::defineHistogram(const std::string& name, const std::string& xtitle, int nbins, double minval, double maxval, const std::string& branch)
{
  HistDefinition def;
  def.name=name;

  def.nbins=nbins;
  def.minval=minval;
  def.maxval=maxval;

  def.xtitle=xtitle;

  def.branch=(branch.empty())?name:branch;

  m_histDefinitions[name]=def;
}

HistDefinition TheRatPack::histDefinition(const std::string& name) const
{ return m_histDefinitions.at(name); }
