#include "TheHists.h"

#include <TH1F.h>

TheHists::TheHists()
  : m_output(0)
{ }

void TheHists::setOutput(TDirectory *output)
{ m_output=output; }

TH1* TheHists::book(const std::string &name, const std::string &xtitle, uint nbins, double minval, double maxval)
{
  TH1 *hist=new TH1F(name.c_str(),"",nbins,minval,maxval);
  hist->GetXaxis()->SetTitle(xtitle.c_str());
  hist->SetDirectory(m_output);
  return hist;
}
