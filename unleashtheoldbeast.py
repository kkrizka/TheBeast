import ROOT

from prot import plottools

ROOT.gSystem.Load('src/libTheBeast.so')
ROOT.gSystem.Load('src/xAH/libxAH.so')
ROOT.gSystem.Load('src/DijetISR/libDijetISR.so')
thebeast=ROOT.TheBeast.rawr()

def main():
    testevent=ROOT.DijetISR.Event(True, False)
    testevent.initializeJets   ('jet','kinematic useTheS')
    testevent.initializePhotons('ph' ,'kinematic')
    
    selection_ystar=ROOT.DijetISR.ZprimeGammaJetJetSelection()
    selection_ystar.m_minPhotonPt=200;
    
    #
    # small sample
    testsample=ROOT.TheSampleFile("user.kkrizka.mc15_13TeV.305159.MGPy8EG_N30LO_A14N23LO_dmA_jja_Ph100_mRp1_mD10_gSp3_gD1.gammajet.20170301-01_tree.root","outTree",testevent)
    thebeast.addSample('test',testsample)
    
    redsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    redsample.runSelection()
    thebeast.addSample('red',redsample)

    #
    # data16 sample
    dataevent=ROOT.DijetISR.Event(False, False)
    dataevent.initializeJets   ('jet','kinematic clean layer trackPV energy flavTag')
    dataevent.initializePhotons('ph' ,'kinematic')

    bigsample=ROOT.TheSampleList('filelists/data16.gammajet.NTUP.txt',"outTree",dataevent)
    thebeast.addSample('big',bigsample)

    bigredsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    bigredsample.runSelection()
    thebeast.addSample('bigred',bigredsample)    

    #
    # histograms
    thebeast.ratPack().addHists("event", ROOT.DijetISR.EventHists());
    thebeast.ratPack().addHists("reso" , ROOT.DijetISR.ZprimeResonanceHists());
    thebeast.ratPack().addHists("jet0" , ROOT.DijetISR.JetHists(ROOT.DijetISR.Event.jet, 0, "leading jet"));
    thebeast.ratPack().addHists("jet1" , ROOT.DijetISR.JetHists(ROOT.DijetISR.Event.jet, 1, "subleading jet"));
    thebeast.ratPack().addHists("jet2" , ROOT.DijetISR.JetHists(ROOT.DijetISR.Event.jet, 2, "third jet"));

    #
    # plot
    h=thebeast.get('test','jet0/Pt')
    plottools.plot(h)

