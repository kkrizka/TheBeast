#include "TheEvent.h"

#include <iostream>

TheEvent::TheEvent()
  : m_reader(0)
{ }

TheEvent::~TheEvent()
{ }

void TheEvent::setReader(TTreeReader *reader)
{
  m_reader=reader;
}

void TheEvent::updateEntry()
{ }

