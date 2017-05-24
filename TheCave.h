#ifndef THECAVE_H_
#define THECAVE_H_

#include <TFile.h>
#include <TH1.h>

#include <vector>
#include <map>

class TheCave
{
public:
  TheCave();
  ~TheCave();

  void openFile(const std::string& sample);

  TDirectory* output(const std::string& sample) const;

  TObject* get(const std::string&sample, const std::string& histname);

private:
  std::map<std::string, TFile*> m_fhs;
  std::map<std::string, TDirectory*> m_outputs;
};

#endif // THECAVE_H_
