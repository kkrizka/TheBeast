#include "TheHists.h"

#include <TH1F.h>
#include <TH2F.h>

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

TH2* TheHists::book(const std::string &name, const std::string &xtitle, uint nxbins, double minxval, double maxxval,
	                                     const std::string &ytitle, uint nybins, double minyval, double maxyval)
{
  TH2 *hist2d=new TH2F(name.c_str(),"",nxbins,minxval,maxxval,nybins,minyval,maxyval);
  hist2d->GetXaxis()->SetTitle(xtitle.c_str());
  hist2d->GetYaxis()->SetTitle(ytitle.c_str());
  hist2d->SetDirectory(m_output);
  return hist2d;
}

