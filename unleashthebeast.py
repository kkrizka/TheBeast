import ROOT

from prot import plottools

thebeast=ROOT.TheBeast.rawr()

def main():
    ROOT.gSystem.Load('libTheBeast.so')

    event=ROOT.DijetISREvent(True, False)
    event.initializeJets('jet','kinematic useTheS')
    
    testsample=ROOT.TheSampleFile("user.kkrizka.10914515._000001.tree.root","outTree",event)
    thebeast.addSample('test',testsample)

    thebeast.ratPack().addHists("event", ROOT.EventHists());
    thebeast.ratPack().addHists("reso" , ROOT.ZprimeResonanceHists());

    h=thebeast.get('test','reso/mjj')
    plottools.plot(h)

