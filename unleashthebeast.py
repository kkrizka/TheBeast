import ROOT

import timeit

from prot import plottools

ROOT.gSystem.Load('src/libTheBeast.so')
ROOT.gSystem.Load('src/xAH/libxAH.so')
ROOT.gSystem.Load('src/TCA/libTCA.so')
thebeast=ROOT.TheBeast.rawr()

def main():
    testevent=ROOT.TCA.Event(True, False)
    
    selection_ystar=ROOT.TCA.ZprimeGammaJetJetSelection()
    selection_ystar.m_minPhotonPt=200;
    
    #
    # small sample
    testsample=ROOT.TheSampleFile("mc15_13TeV.305159.MGPy8EG_N30LO_A14N23LO_dmA_jja_Ph100_mRp1_mD10_gSp3_gD1.merge.DAOD_EXOT6.e4900_s2726_r7772_r7676_p2952.root","outTree",testevent)
    thebeast.addSample('test',testsample)
    
    redsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    redsample.runSelection()
    thebeast.addSample('red',redsample)

    #
    # histograms
    thebeast.ratPack().addHists("event", ROOT.TCA.EventHists());
    thebeast.ratPack().addHists("reso" , ROOT.TCA.ZprimeResonanceHists());
    thebeast.ratPack().addHists("jet0" , ROOT.TCA.JetHists(ROOT.TCA.Event.jet, 0, "leading jet"));
    thebeast.ratPack().addHists("jet1" , ROOT.TCA.JetHists(ROOT.TCA.Event.jet, 1, "subleading jet"));
    thebeast.ratPack().addHists("jet2" , ROOT.TCA.JetHists(ROOT.TCA.Event.jet, 2, "third jet"));

    #
    # data16 sample
    dataevent=ROOT.TCA.Event(False, False)

    bigsample=ROOT.TheSampleList('filelists/data16.gammajet.TCA.txt',"outTree",dataevent)
    thebeast.addSample('big',bigsample)

    bigredsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    bigredsample.runSelection()
    thebeast.addSample('bigred',bigredsample)
    
    #
    # plot
    print(timeit.timeit(lambda:thebeast.get('big','jet0/Pt'),number=1))
    h=thebeast.get('big','jet0/Pt')
    plottools.plot(h)

