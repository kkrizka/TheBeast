#ifndef THESAMPLEFILE_H_
#define THESAMPLEFILE_H_

#include <TFile.h>

#include "TheSample.h"

class TheSampleFile : public TheSample
{
public:
  TheSampleFile(const std::string& path, const std::string& tree);
  ~TheSampleFile();

private:
  TFile *m_fh;
};

#endif // THESAMPLEFILE_H_
