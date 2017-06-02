import ROOT

from prot import plottools

thebeast=ROOT.TheBeast.rawr()

def main():
    ROOT.gSystem.Load('src/libTheBeast.so')

    testevent=ROOT.DijetISREvent(True, False)
    testevent.initializeJets   ('jet','kinematic useTheS')
    testevent.initializePhotons('ph' ,'kinematic')

    #
    # small sample
    testsample=ROOT.TheSampleFile("user.kkrizka.10914515._000001.tree.root","outTree",testevent)
    thebeast.addSample('test',testsample)

    selection_ystar=ROOT.ZprimeGammaJetJetSelection()
    selection_ystar.m_minPhotonPt=200;
    
    redsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    redsample.runSelection()
    thebeast.addSample('red',redsample)

    #
    # data16 sample
    dataevent=ROOT.DijetISREvent(False, False)
    dataevent.initializeJets   ('jet','kinematic clean layer trackPV energy flavTag')
    dataevent.initializePhotons('ph' ,'kinematic')

    bigsample=ROOT.TheSampleList('filelists/data16.gammajet.NTUP.txt',"outTree",dataevent)
    thebeast.addSample('big',bigsample)

    bigredsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    bigredsample.runSelection()
    thebeast.addSample('bigred',bigredsample)    

    #
    # histograms
    thebeast.ratPack().addHists("event", ROOT.EventHists());
    thebeast.ratPack().addHists("reso" , ROOT.ZprimeResonanceHists());
    thebeast.ratPack().addHists("jet0" , ROOT.JetHists(ROOT.DijetISREvent.jet, 0, "leading jet"));
    thebeast.ratPack().addHists("jet1" , ROOT.JetHists(ROOT.DijetISREvent.jet, 1, "subleading jet"));
    thebeast.ratPack().addHists("jet2" , ROOT.JetHists(ROOT.DijetISREvent.jet, 2, "third jet"));

    #
    # plot
    h=thebeast.get('big','jet0/Pt')
    plottools.plot(h)

