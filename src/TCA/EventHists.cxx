#include "EventHists.h"

using namespace TCA;

EventHists :: EventHists ()
  : TheHists()
{ }

void EventHists::initialize(TheEvent *event)
{
  m_event=dynamic_cast<Event*>(event);
  
  //
  // Event Level
  //
  h_NPV      = book("NPV",    "NPV",             50,     -0.5,    49   );
  h_mu_ave   = book("mu_ave", "#mu_{ave}",       50,     -0.5,    49   );
  h_mu_act   = book("mu_act", "#mu_{act}",       50,     -0.5,    49   );

  h_weight   = book("weight", "MC Event Weight", 100,     -100,   100   );
}

void EventHists::execute()
{
  double eventWeight=1.;

  h_NPV    ->Fill(*m_event->m_NPV                           , eventWeight);
  h_mu_ave ->Fill(*m_event->m_averageInteractionsPerCrossing, eventWeight);
  h_mu_act ->Fill(*m_event->m_actualInteractionsPerCrossing , eventWeight);

  h_weight ->Fill(*m_event->m_weight/(*m_event->m_weight_xs), eventWeight);
}
