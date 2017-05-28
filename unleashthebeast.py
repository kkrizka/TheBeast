import ROOT

from prot import plottools

thebeast=ROOT.TheBeast.rawr()

def main():
    ROOT.gSystem.Load('libTheBeast.so')

    event=ROOT.DijetISREvent(True, False)
    event.initializeJets   ('jet','kinematic useTheS')
    event.initializePhotons('ph' ,'kinematic')
    
    testsample=ROOT.TheSampleFile("user.kkrizka.10914515._000001.tree.root","outTree",event)
    thebeast.addSample('test',testsample)

    selection_ystar=ROOT.ZprimeGammaJetJetSelection()
    selection_ystar.m_minPhotonPt=200;
    
    redsample=ROOT.TheSampleSelection(testsample,selection_ystar)
    redsample.runSelection()
    thebeast.addSample('red',redsample)
    
    thebeast.ratPack().addHists("event", ROOT.EventHists());
    thebeast.ratPack().addHists("reso" , ROOT.ZprimeResonanceHists());

    h=thebeast.get('red','reso/mjj')
    plottools.plot(h)

