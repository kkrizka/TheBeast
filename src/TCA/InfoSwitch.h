#ifndef INFOSWITCH_H_
#define INFOSWITCH_H_

#include <set>
#include <map>
#include <iostream>
#include <sstream>

#include "TString.h"

/**
  @brief A struct that is used for parsing configuration strings and assigning booleans to various properties. Currently used in plotting code.

  @rst
      Strings are used to turn on and off histograms and branches in the tree The following structs hold the bools used to control the content and also have the string which is necessary to turn a set on.
      See the derived members for more information about what is supported. Each derived member should provide a table of parameters, patterns, and type of matching scheme used. The pattern will use standard PCRE-syntax when appropriate.

      We support two major matching schemes:

          Exact
              If a variable is matched exactly to a string, then a boolean is set to True or False based on whether an exact match exists or not.

          Partial
              If a variable is partially matched to a string, then there is some specific pattern we are extracting that will succeed the partial match that determines what the variable will be set to (usually not a bool).

  @endrst
 */
class InfoSwitch {
protected:
  /**
      The input configuration string from which we split up into tokens.
   */
  const std::string m_configStr;
  /**
      The vector of tokens from which we search through for finding matches.
   */
  std::set<std::string> m_configDetails;
public:
  /**
      @brief Constructor. Take in input string, create vector of tokens.
      @param configStr        The configuration string to split up.
   */
  InfoSwitch(const std::string configStr) : m_configStr(configStr) {
      // parse and split by space
      std::string token;
      std::istringstream ss(m_configStr);
      while ( std::getline(ss, token, ' ') )
          m_configDetails.insert(token);
  };
  /**
      @rst
          .. deprecated:: 00-03-26
             Use :cpp:func:`~HelperClasses::InfoSwitch::has_match` instead.

      @endrst
      @param flag     The string we search for.
   */
  bool parse(const std::string flag) { std::cout << "InfoSwitch::parse() deprecated soon!" << std::endl; return has_match(flag); };
  /**
      @rst
          Search for an exact match in :cpp:member:`~HelperClasses::InfoSwitch::m_configDetails`.

      @endrst
      @param flag     The string we search for.
   */
  bool has_exact(const std::string flag) { return m_configDetails.find(flag) != m_configDetails.end(); };
  /**
      @rst
          Search for a partial match in :cpp:member:`~HelperClasses::InfoSwitch::m_configStr`.

      @endrst
      @param flag     The string we search for.
   */
  bool has_match(const std::string flag) { return m_configStr.find(flag) != std::string::npos; };
};

/**
  @rst
      The :cpp:class:`HelperClasses::InfoSwitch` struct for Trigger Information.

      ============== ============ =======
      Parameter      Pattern      Match
      ============== ============ =======
      m_basic        basic        exact
      m_menuKeys     menuKeys     exact
      m_passTriggers passTriggers exact
      m_passTrigBits passTrigBits exact
      ============== ============ =======

  @endrst
 */
class TriggerInfoSwitch : public InfoSwitch {
public:
  bool m_basic;
  bool m_menuKeys;
  bool m_passTriggers;
  bool m_passTrigBits;
  TriggerInfoSwitch(const std::string configStr) : InfoSwitch(configStr) { initialize(); };
protected:
  void initialize();
};

#endif // INFOSWITCH_H_
