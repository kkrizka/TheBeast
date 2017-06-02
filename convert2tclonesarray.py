#!/usr/bin/env python

import array
import sys
import ROOT

if len(sys.argv)!=3:
    print('usage: %s input output'%sys.argv[0])
    sys.exit(-1)

ROOT.gSystem.Load('src/libTheBeast.so')

def copyTree(tree):
    tree.SetBranchStatus('*jet*',0)
    outTree=tree.CopyTree('','',0)
    tree.SetBranchStatus('*jet*',1)

    jets=ROOT.TClonesArray('Jet',1000)
    outTree.Branch('jet','TClonesArray',ROOT.AddressOf(jets))
    jetbranches=[]
    for branch in tree.GetListOfBranches():
        if not branch.GetName().startswith('jet_'): continue
        jetbranches.append(branch.GetName())

    tree.GetEntry(0)
    jet=ROOT.Jet()
    #jet.p4.SetPtEtaPhiE(tree.jet_pt[i],tree.jet_eta[i],tree.jet_phi[i],tree.jet_E[i])
    for jetbranch in jetbranches:
        if hasattr(jet,jetbranch[4:]):
            setattr(jet,jetbranch[4:],getattr(tree,jetbranch)[0])
        else:
            print('missing %s'%jetbranch)
        
    print(jetbranches)
    # for e in tree:
    #     # jet
    #     jets.Clear()
    #     for i in range(tree.njet):
    #         jet=ROOT.Jet()
    #         jet.p4.SetPtEtaPhiE(tree.jet_pt[i],tree.jet_eta[i],tree.jet_phi[i],tree.jet_E[i])
    #         for jetbranch in jetbranches:
    #             setattr(jet,jetbranch[4:],getattr(tree,jetbranch)[i])
    #         jets[i]=jet

    #     #
    #     outTree.Fill()

    return outTree
    
fh_in =ROOT.TFile.Open(sys.argv[1])
fh_out=ROOT.TFile.Open(sys.argv[2],'RECREATE')

for key in fh_in.GetListOfKeys():
    obj=key.ReadObj()
    fh_out.cd()
    if key.GetName()=='outTree':
        copyTree(obj) #.Write()
    else:
        obj.Write()

fh_out.Close()
fh_in.Close()


