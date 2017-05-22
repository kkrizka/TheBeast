import ROOT

from prot import plottools

thebeast=ROOT.TheBeast.rawr()

def main():
    ROOT.gSystem.Load('libTheBeast.so')

    thebeast.ratPack().defineHistogram("jet0_pt_s", "Leading Jet p_{T} [GeV]", 100, 0,  200, "jet_pt[0]");
    thebeast.ratPack().defineHistogram("jet0_pt_m", "Leading Jet p_{T} [GeV]", 100, 0,  500, "jet_pt[0]");
    thebeast.ratPack().defineHistogram("jet0_pt",   "Leading Jet p_{T} [GeV]", 100, 0, 1000, "jet_pt[0]");    
    thebeast.ratPack().defineHistogram("jet0_pt_l", "Leading Jet p_{T} [GeV]", 100, 0, 5000, "jet_pt[0]");

    testsample=ROOT.TheSampleFile("user.kkrizka.10914515._000001.tree.root","outTree")
    thebeast.addSample('test',testsample)

    h=thebeast.get('test','jet0_pt')
    plottools.plot(h)

