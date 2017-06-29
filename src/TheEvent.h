#ifndef THEEVENT_H_
#define THEEVENT_H_

#include <TTreeReader.h>

class TheEvent
{
public:
  TheEvent();  
  virtual ~TheEvent();

  virtual void setReader(TTreeReader *reader);
  virtual void updateEntry();

protected:
  TTreeReader *m_reader;
};

#endif // THEEVENT_H_
