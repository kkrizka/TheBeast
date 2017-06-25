#include "InfoSwitch.h"

void TriggerInfoSwitch::initialize(){
  m_basic             = has_exact("basic");
  m_menuKeys          = has_exact("menuKeys");
  m_passTriggers      = has_exact("passTriggers");
  m_passTrigBits      = has_exact("passTrigBits");
}
