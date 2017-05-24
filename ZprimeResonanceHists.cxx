#include "ZprimeResonanceHists.h"

ZprimeResonanceHists :: ZprimeResonanceHists ()
  : TheHists()
{ }

void ZprimeResonanceHists::initialize(TheEvent *event)
{
  m_event=dynamic_cast<DijetISREvent*>(event);

  // Define variable mjj bins
  static const double mjj_var_bins[] = {169.0, 180.0, 191.0, 203.0, 216.0, 229.0, 243.0, 257.0, 272.0, 287.0, 303.0, 319.0, 335.0, 352.0, 369.0, 387.0, 405.0, 424.0, 443.0, 462.0, 482.0, 502.0, 523.0, 544.0, 566.0, 588.0, 611.0, 634.0, 657.0, 681.0, 705.0, 730.0, 755.0, 781.0, 807.0, 834.0, 861.0, 889.0, 917.0, 946.0, 976.0, 1006.0, 1037.0, 1068.0, 1100.0, 1133.0, 1166.0, 1200.0, 1234.0, 1269.0, 1305.0, 1341.0, 1378.0, 1416.0, 1454.0, 1493.0, 1533.0, 1573.0, 1614.0, 1656.0, 1698.0, 1741.0, 1785.0, 1830.0, 1875.0, 1921.0, 1968.0, 2016.0, 2065.0, 2114.0, 2164.0, 2215.0, 2267.0, 2320.0, 2374.0, 2429.0, 2485.0, 2542.0, 2600.0, 2659.0, 2719.0, 2780.0, 2842.0, 2905.0, 2969.0, 3034.0, 3100.0, 3167.0, 3235.0, 3305.0, 3376.0, 3448.0, 3521.0, 3596.0, 3672.0, 3749.0, 3827.0, 3907.0, 3988.0, 4070.0, 4154.0, 4239.0, 4326.0, 4414.0, 4504.0, 4595.0, 4688.0, 4782.0, 4878.0, 4975.0, 5074.0, 5175.0, 5277.0, 5381.0, 5487.0, 5595.0, 5705.0, 5817.0, 5931.0, 6047.0, 6165.0, 6285.0, 6407.0, 6531.0, 6658.0, 6787.0, 6918.0, 7052.0, 7188.0, 7326.0, 7467.0, 7610.0, 7756.0, 7904.0, 8055.0, 8208.0, 8364.0, 8523.0, 8685.0, 8850.0, 9019.0, 9191.0, 9366.0, 9544.0, 9726.0, 9911.0, 10100.0, 10292.0, 10488.0, 10688.0, 10892.0, 11100.0, 11312.0, 11528.0, 11748.0, 11972.0, 12200.0, 12432.0, 12669.0, 12910.0, 13156.0};
  static int binnum = sizeof(mjj_var_bins)/sizeof(double) - 1; 

  // These plots are always made
  h_ptjj     = book("ptjj",      "p_{T,jj} [GeV]", 100,            0,     500   );
  h_ptjj_l   = book("ptjj_l",    "p_{T,jj} [GeV]", 100,            0,    1000   );
  h_etajj    = book("etajj",     "#eta_{jj}",      100,           -4,       4   );
  h_phijj    = book("phijj",     "#phi_{jj}",      100, -TMath::Pi(),TMath::Pi());

  h_mjj      = book("mjj",       "m_{jj} [GeV]",      500,           0,    5000 );
  //h_mjj_fine = book("mjj_fine",  "m_{jj} [GeV]",      250,           0,    5000 );
  //h_mjj_var  = book("mjj_var",   "m_{jj} [GeV]",   binnum,     mjj_var_bins     );

  h_dEtajj        = book("dEtajj", "|#Delta#eta_{jj}|", 100, 0,           4);
  h_dPhijj        = book("dPhijj", "|#Delta#phi_{jj}|", 100, 0, TMath::Pi());
  h_dRjj          = book("dRjj"  , "#DeltaR_{jj}"     , 100, 0,           5);

  h_yStarjj       = book("ystarjj"       , "y^{*}_{jj}"         ,  90,  0  ,  3);
  h_yBoostjj      = book("yboostjj"      , "y^{boost}_{jj}"     ,  90,  0  ,  3);
  h_chijj         = book("chijj"         , "#chi_{jj}"          , 120,  0  , 60);

  // deboosted
  h_yStarjjBoostjj= book("yStarjjBoostjj"  ,"y^{*}_{jj, jj boost}",  90,  0  ,  3);

  h_asymjj        = book("asymjj",     "(|p_{T}^{1}|-|p_{T}^{2}|)/(|p_{T}^{1}|+|p_{T}^{2}|)",    120,  0, 1);
  h_vecasymjj     = book("vecasymjj",  "|#vec{p}_{T}^{1}-#vec{p}_{T}^{2}|/|#vec{p}_{T}^{1}+#vec{p}_{T}^{2}|",120, 0, 7);
  h_projasymjj    = book("projasymjj", "(#vec{p}_{T}^{1}-#vec{p}_{T}^{2})#upoint#hat{p}_{T}^{jj}/p_{T}^{jj}", 50, 0, 5);

  h_chargediff    = book("chargediff", "|Q_{1}-Q_{2}|", 50, 0, 10);
  h_chargesum     = book("chargesum",  "|Q_{1}+Q_{2}|", 50, 0, 10);

  //
  // 2D plots
  //
  h_mjj_vs_reso0    = book("mjj_vs_reso0", "Leading Resonance Jet p_{T} [GeV]"   , 100, 0, 500,
			                   "m_{jj} [GeV]"                        , 500, 0, 2000 );
  h_mjj_vs_reso1    = book("mjj_vs_reso1", "Subleading Resonance Jet p_{T} [GeV]", 100, 0, 500,
			                   "m_{jj} [GeV]"                        , 500, 0, 2000 );

  h_mjj_vs_dEtajj   = book("mjj_vs_dEtajj", "|#Delta#eta_{jj}|", 100, 0, 4,
			                    "m_{jj} [GeV]"     , 200, 0, 2000);
  h_mjj_vs_dPhijj   = book("mjj_vs_dPhijj", "|#Delta#phi_{jj}|", 100, 0, TMath::Pi(),
			                    "m_{jj} [GeV]"     , 200, 0, 2000 );
  h_mjj_vs_dRjj     = book("mjj_vs_dRjj"  , "|#DeltaR_{jj}|"   , 100, 0, 5,
			                    "m_{jj} [GeV]"     , 200, 0, 2000 );

  h_dPhijj_vs_dEtajj= book("dPhijj_vs_dEtajj", "|#Delta#eta_{jj}|", 100, 0, 4,
			                       "|#Delta#phi_{jj}|", 100, 0, TMath::Pi());
}

void ZprimeResonanceHists::execute()
{
  //
  // Figure out event stuff
  double eventWeight=1.;

  if(m_event->m_jets->size()<2) return;
  const Jet *reso0=&m_event->m_jets->at(0);
  const Jet *reso1=&m_event->m_jets->at(1);

  //
  // Fill histograms
  TLorentzVector p4_Zprime=reso0->p4+reso1->p4;

  h_ptjj    ->Fill(p4_Zprime.Pt() , eventWeight);
  h_ptjj_l  ->Fill(p4_Zprime.Pt() , eventWeight);
  h_etajj   ->Fill(p4_Zprime.Eta(), eventWeight);
  h_phijj   ->Fill(p4_Zprime.Phi(), eventWeight);
  h_mjj     ->Fill(p4_Zprime.M()  , eventWeight);
  //h_mjj_var ->Fill(p4_Zprime.M()  , eventWeight);
  //h_mjj_fine->Fill(p4_Zprime.M()  , eventWeight);

  // Deltas
  float dEtajj = fabs(reso0->p4.Eta()-reso1->p4.Eta());
  h_dEtajj ->Fill(dEtajj , eventWeight);

  float dPhijj = fabs(reso0->p4.DeltaPhi(reso1->p4));
  h_dPhijj ->Fill(dPhijj , eventWeight);

  float dRjj = reso0->p4.DeltaR(reso1->p4);
  h_dRjj   ->Fill(dRjj  , eventWeight);

  // Y's
  double yStarjj =fabs(reso0->p4.Rapidity()-reso1->p4.Rapidity())/2.;
  h_yStarjj ->Fill(yStarjj                   , eventWeight);

  double yBoostjj=fabs(reso0->p4.Rapidity()+reso1->p4.Rapidity())/2.;
  h_yBoostjj->Fill(yBoostjj                  , eventWeight);

  double chijj=exp(2*fabs(yStarjj));
  h_chijj   ->Fill(chijj                     , eventWeight);

  TLorentzVector p4_reso0deboostjj=reso0->p4;
  p4_reso0deboostjj.Boost(-p4_Zprime.BoostVector());
  TLorentzVector p4_reso1deboostjj=reso1->p4;
  p4_reso1deboostjj.Boost(-p4_Zprime.BoostVector());

  float yStarjjBoostjj    = fabs(p4_reso0deboostjj.Rapidity()-p4_reso1deboostjj.Rapidity())/2.;
  h_yStarjjBoostjj  ->Fill( yStarjjBoostjj, eventWeight);

  // Asym
  double asymjj = (reso0->p4.Pt()-reso1->p4.Pt())/(reso0->p4.Pt()+reso1->p4.Pt());
  h_asymjj->Fill( asymjj, eventWeight);

  double vecasymjj = (reso0->p4-reso1->p4).Pt()/(reso0->p4+reso1->p4).Pt();
  h_vecasymjj->Fill( vecasymjj, eventWeight);

  TVector3 p3_Zprime=p4_Zprime.Vect();
  p3_Zprime.SetZ(0);
  p3_Zprime.SetMag(1.);
  double projasymjj = ((reso0->p4-reso1->p4).Vect().Dot(p3_Zprime))/p4_Zprime.Pt();
  h_projasymjj->Fill( projasymjj, eventWeight);

  h_chargediff->Fill(fabs(reso0->charge-reso1->charge), eventWeight);
  h_chargesum ->Fill(fabs(reso0->charge+reso1->charge), eventWeight);

  //
  // 2D plots
  //
  h_mjj_vs_reso0->Fill(reso0->p4.Pt(),p4_Zprime.M(), eventWeight);
  h_mjj_vs_reso1->Fill(reso1->p4.Pt(),p4_Zprime.M(), eventWeight);

  h_mjj_vs_dEtajj->Fill(dEtajj, p4_Zprime.M(), eventWeight);
  h_mjj_vs_dPhijj->Fill(dPhijj, p4_Zprime.M(), eventWeight);
  h_mjj_vs_dRjj  ->Fill(dRjj  , p4_Zprime.M(), eventWeight);

  h_dPhijj_vs_dEtajj->Fill(dEtajj, dPhijj, eventWeight);
}
