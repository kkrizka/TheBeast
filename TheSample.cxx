#include "TheSample.h"

TheSample::TheSample()
  : m_tree(0)
{ }

TH1* TheSample::histogram(const HistDefinition& histDef)
{
  if(m_hists.find(histDef.name)==m_hists.end())
    {
      TH1F *hist=new TH1F(histDef.name.c_str(),"",histDef.nbins,histDef.minval,histDef.maxval);
      hist->GetXaxis()->SetTitle(histDef.xtitle.c_str());

      m_tree->Draw((histDef.branch+">>"+histDef.name).c_str());

      m_hists[histDef.name]=hist;
    }
  return m_hists[histDef.name];
}
