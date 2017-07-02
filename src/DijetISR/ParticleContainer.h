#ifndef PARTICLECONTAINER_H_
#define PARTICLECONTAINER_H_

#include <TTree.h>
#include <TLorentzVector.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>

#include <vector>
#include <string>
#include <iostream>

#include "../xAH/Particle.h"

#define MAX_PARTICLES 100

template <class T_PARTICLE, class T_INFOSWITCH>
class ParticleContainer
{
public:
  ParticleContainer(const std::string& name, 
		    const std::string& detailStr="", 
		    float units = 1e3, 
		    bool mc = false, 
		    bool useMass=false, 
		    const std::string& suffix="")
    : m_name(name), 
      m_infoSwitch(detailStr), 
      m_mc(mc), 
      m_debug(false), 
      m_units(units), 
      m_useMass(useMass), 
      m_suffix(suffix)
  { }
    
  virtual ~ParticleContainer()
  { }
    
  virtual void setReader(TTreeReader *reader)
  {

    std::string                   counterName = "n"+m_name;
    if (!m_suffix.empty())        counterName += "_" + m_suffix;
    if (m_infoSwitch.m_useTheS) { counterName += "s";
      std::cerr << "WARNING! The useTheS option is depricated in ParticleContainer." << std::endl;
    }

    m_n=TTreeReaderValue<int>(*reader, counterName.c_str());

    if(m_infoSwitch.m_kinematic)
      {
	// Determine whether mass or energy is saved
	std::string mname = branchName("m");
	m_useMass=reader->GetTree()->GetBranch(mname.c_str())!=0;

	m_pt =new TTreeReaderArray<float>(*reader,branchName("pt" ).c_str());
	m_eta=new TTreeReaderArray<float>(*reader,branchName("eta").c_str());
	m_phi=new TTreeReaderArray<float>(*reader,branchName("phi").c_str());
	if(m_useMass) m_M=new TTreeReaderArray<float>(*reader,branchName("m").c_str());
	else          m_E=new TTreeReaderArray<float>(*reader,branchName("E").c_str());
      }
  }

  void updateEntry()
  {
    for(int i=0;i<*m_n;i++)
      updateParticle(i);
  }
    
  T_PARTICLE& at_nonConst(uint idx)
  { return m_particles[idx]; }

  const T_PARTICLE& at(uint idx) const
  { return m_particles[idx]; }
  
  const T_PARTICLE& operator[](uint idx) const
  { return m_particles[idx]; }


protected:
  std::string branchName(const std::string& varName)
  {
    std::string name = m_name + "_" + varName;
    if (! m_suffix.empty()) { name += "_" + m_suffix; }
    return name;
  }

  virtual void updateParticle(uint idx)
  {
    if(m_infoSwitch.m_kinematic)
      {
	if(m_useMass){	  
	  m_particles[idx].p4.SetPtEtaPhiM(m_pt ->At(idx),
					   m_eta->At(idx),
					   m_phi->At(idx),
					   m_M  ->At(idx));

	} else{
	  m_particles[idx].p4.SetPtEtaPhiE(m_pt ->At(idx),
					   m_eta->At(idx),
					   m_phi->At(idx),
					   m_E  ->At(idx));
	}
      }
  }
    
  std::string m_name;

  T_PARTICLE m_particles[MAX_PARTICLES];
    
public:
  T_INFOSWITCH m_infoSwitch;
  bool m_mc;
  bool m_debug;
  float m_units;

  TTreeReaderValue<int> m_n;

private:
  bool        m_useMass;
  std::string m_suffix;

  //
  // Vector branches

  // kinematic
  TTreeReaderArray<float>* m_pt;
  TTreeReaderArray<float>* m_eta;
  TTreeReaderArray<float>* m_phi;
  TTreeReaderArray<float>* m_E;
  TTreeReaderArray<float>* m_M;
};

#endif // PARTICLECONTAINER_H_
