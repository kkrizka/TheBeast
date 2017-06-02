#include "JetHists.h"
#include <sstream>
#include <math.h>

JetHists::JetHists(DijetISREvent::Container container, int idx, const std::string& title)
  : IParticleHists(container, idx, title)
{ }

JetHists::~JetHists()
{ }

void JetHists::initialize(TheEvent *event)
{
  IParticleHists::initialize(event);

  JetInfoSwitch *infoSwitch=&dynamic_cast<DijetISREvent*>(event)->m_jets->m_infoSwitch;

  // clean
  if( infoSwitch->m_clean ) {
    h_LeadingClusterSecondR = book("LeadingClusterSecondR", m_title+"LeadingClusterSecondR", 120, 0.000000, 300000.000000);
    h_HECQuality = book("HECQuality", m_title+"HEC Quality", 120, -10.000000, 10.000000);
    h_N90Constituents = book("N90Constituents", m_title+"N90 Constituents", 120, 0.000000, 40.000000);
    h_Timing = book("Timing", m_title+"Timming", 120, -80.000000, 80.000000);
    h_LArBadHVEFrac = book("LArBadHVEFrac", m_title+"LAr Bad HV Energy Fraction", 120, 0.000000, 1.000000);
    h_AverageLArQF = book("AverageLArQF", m_title+"<LAr Quality Factor>", 120, 0.000000, 1000.000000);
    h_LeadingClusterSecondLambda = book("LeadingClusterSecondLambda", m_title+"LeadingClusterSecondLambda", 20, 0.000000, 1000000.000000);
    h_LeadingClusterPt = book("LeadingClusterPt", m_title+"Leading Cluster P_{T}", 120, 0.000000, 1000.000000);
    h_LeadingClusterCenterLambda = book("LeadingClusterCenterLambda", m_title+"LeadingClusterCenterLambda", 120, 0.000000, 5000.000000);
    h_LArBadHVNCell = book("LArBadHVNCell", m_title+"LAr Bad HV N_{cells}", 120, -0.500000, 499.500000);
    h_OotFracClusters10 = book("OotFracClusters10", m_title+"OotFracClusters10", 120, 0.000000, 1.000000);
    h_NegativeE = book("NegativeE", m_title+"Negative Energy", 120, -10.000000, 10.000000);
    h_OotFracClusters5 = book("OotFracClusters5", m_title+"OotFracClusters5", 120, 0.000000, 1.000000);
    h_LArQuality = book("LArQuality", m_title+"LAr Quality", 120, -600.000000, 600.000000);
    h_clean_passLooseBadUgly = book("clean_passLooseBadUgly", m_title+"LooseBadUgly Cleaning Flag", 2, -0.500000, 1.500000);
    h_clean_passTightBad = book("clean_passTightBad", m_title+"TightBad Cleaning Flag", 2, -0.500000, 1.500000);
    h_BchCorrCell = book("BchCorrCell", m_title+"BCH Corr Cell", 120, 0.000000, 600.000000);
    h_clean_passTightBadUgly = book("clean_passTightBadUgly", m_title+"TightBadUgly Cleaning Flag", 2, -0.500000, 1.500000);
    h_clean_passLooseBad = book("clean_passLooseBad", m_title+"LooseBad Cleaning Flag", 2, -0.500000, 1.500000);
  }
  // rapidity
  if( infoSwitch->m_rapidity ) {
    h_rapidity = book("rapidity", m_title+"rapidity", 120, -3.000000, 3.000000);
  }
  // energy
  if( infoSwitch->m_energy ) {
    h_Width = book("Width", m_title+"Width", 100, 0.000000, 0.500000);
    h_EMFrac = book("EMFrac", m_title+"EM Fraction", 120, 0.000000, 2.000000);
    h_LowEtConstituentsFrac = book("LowEtConstituentsFrac", m_title+"LowEtConstituentsFrac", 120, 0.000000, 1.000000);
    h_HECFrac = book("HECFrac", m_title+"HEC Fraction", 120, 0.000000, 5.000000);
    h_GhostMuonSegmentCount = book("GhostMuonSegmentCount", m_title+"GhostMuonSegmentCount", 10, -0.500000, 9.500000);
    h_CentroidR = book("CentroidR", m_title+"CentroidR", 120, 0.000000, 600.000000);
    h_FracSamplingMaxIndex = book("FracSamplingMaxIndex", m_title+"FracSamplingMaxIndex", 22, -0.500000, 21.500000);
    h_FracSamplingMax = book("FracSamplingMax", m_title+"FracSamplingMax", 120, 0.000000, 1.000000);
  }
}
void JetHists::execute()
{
  IParticleHists::execute();

  JetInfoSwitch *infoSwitch;
  const Jet *particle=0;
  switch(m_container)
    {
    case DijetISREvent::jet:
      particle=&m_event->m_jets->at(m_idx);
      infoSwitch=&m_event->m_jets->m_infoSwitch;
      break;
    default:
      std::cerr << "Not a jet container." << std::endl;
      return;
      break;
    }

  double eventWeight=1.;  

  // clean
  if( infoSwitch->m_clean ) {
      h_LeadingClusterSecondR->Fill(particle->LeadingClusterSecondR,eventWeight);
      h_HECQuality->Fill(particle->HECQuality,eventWeight);
      h_N90Constituents->Fill(particle->N90Constituents,eventWeight);
      h_Timing->Fill(particle->Timing,eventWeight);
      h_LArBadHVEFrac->Fill(particle->LArBadHVEFrac,eventWeight);
      h_AverageLArQF->Fill(particle->AverageLArQF,eventWeight);
      h_LeadingClusterSecondLambda->Fill(particle->LeadingClusterSecondLambda,eventWeight);
      h_LeadingClusterPt->Fill(particle->LeadingClusterPt,eventWeight);
      h_LeadingClusterCenterLambda->Fill(particle->LeadingClusterCenterLambda,eventWeight);
      h_LArBadHVNCell->Fill(particle->LArBadHVNCell,eventWeight);
      h_OotFracClusters10->Fill(particle->OotFracClusters10,eventWeight);
      h_NegativeE->Fill(particle->NegativeE,eventWeight);
      h_OotFracClusters5->Fill(particle->OotFracClusters5,eventWeight);
      h_LArQuality->Fill(particle->LArQuality,eventWeight);
      h_clean_passLooseBadUgly->Fill(particle->clean_passLooseBadUgly,eventWeight);
      h_clean_passTightBad->Fill(particle->clean_passTightBad,eventWeight);
      h_BchCorrCell->Fill(particle->BchCorrCell,eventWeight);
      h_clean_passTightBadUgly->Fill(particle->clean_passTightBadUgly,eventWeight);
      h_clean_passLooseBad->Fill(particle->clean_passLooseBad,eventWeight);
  }
  // rapidity
  if( infoSwitch->m_rapidity ) {
      h_rapidity->Fill(particle->rapidity,eventWeight);
  }
  // energy
  if( infoSwitch->m_energy ) {
      h_Width->Fill(particle->Width,eventWeight);
      h_EMFrac->Fill(particle->EMFrac,eventWeight);
      h_LowEtConstituentsFrac->Fill(particle->LowEtConstituentsFrac,eventWeight);
      h_HECFrac->Fill(particle->HECFrac,eventWeight);
      h_GhostMuonSegmentCount->Fill(particle->GhostMuonSegmentCount,eventWeight);
      h_CentroidR->Fill(particle->CentroidR,eventWeight);
      h_FracSamplingMaxIndex->Fill(particle->FracSamplingMaxIndex,eventWeight);
      h_FracSamplingMax->Fill(particle->FracSamplingMax,eventWeight);
  }
}

