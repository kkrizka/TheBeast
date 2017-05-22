import ROOT

from prot import plottools

thebeast=ROOT.TheBeast.rawr()

def main():
    ROOT.gSystem.Load('libTheBeast.so')

    testsample=ROOT.TheSampleFile("user.kkrizka.10914515._000001.tree.root","outTree",ROOT.DijetISREvent(True, False))
    thebeast.addSample('test',testsample)

    thebeast.ratPack().addHists("event", ROOT.EventHists());

    h=thebeast.get('test','event/mu_ave')
    plottools.plot(h)

