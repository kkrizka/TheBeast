#ifndef THEEVENT_H_
#define THEEVENT_H_

#include <TTree.h>

class TheEvent
{
public:
  TheEvent();  
  virtual ~TheEvent();

  virtual void setTree(TTree *t);
  virtual void updateEntry();

protected:
  void setBranchAddress(const std::string& branch, void *addr);
  
  TTree *m_tree;
};

#endif // THEEVENT_H_
