#include "TheEvent.h"

#include <iostream>

TheEvent::TheEvent()
  : m_tree(0)
{ }

TheEvent::~TheEvent()
{ }

void TheEvent::setTree(TTree *tree)
{
  m_tree=tree;
}

void TheEvent::setBranchAddress(const std::string& branch, void *addr)
{
  m_tree->SetBranchStatus (branch.c_str(), 1);
  m_tree->SetBranchAddress(branch.c_str(), addr);
}

void TheEvent::updateEntry()
{ }

