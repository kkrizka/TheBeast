#!/usr/bin/env python

import array
import sys
import ROOT

if len(sys.argv)!=3:
    print('usage: %s input output'%sys.argv[0])
    sys.exit(-1)

ROOT.gSystem.Load('/home/kkrizka/Code/jupyroot/src/libTheBeast.so')

rename_jet={}
rename_jet['jet_LArBadHVEnergyFrac']='LArBadHVEFrac'
rename_jet['jet_LArBadHVEFracnergyFrac']='LArBadHVEFrac'
rename_jet['jet_isFix30']='MV2c20_isFix30'
rename_jet['jet_SFFix30']='MV2c20_sfFix30'
rename_jet['jet_isFix50']='MV2c20_isFix50'
rename_jet['jet_SFFix50']='MV2c20_sfFix50'
rename_jet['jet_isFix60']='MV2c20_isFix60'
rename_jet['jet_SFFix60']='MV2c20_sfFix60'
rename_jet['jet_isFix70']='MV2c20_isFix70'
rename_jet['jet_SFFix70']='MV2c20_sfFix70'
rename_jet['jet_isFix77']='MV2c20_isFix77'
rename_jet['jet_SFFix77']='MV2c20_sfFix77'
rename_jet['jet_isFix85']='MV2c20_isFix85'
rename_jet['jet_SFFix85']='MV2c20_sfFix85'

def copyTree(tree):
    tree.SetBranchStatus('jet_*',0)
    outTree=tree.CopyTree('','',0)
    tree.SetBranchStatus('jet_*',1)

    jets=ROOT.TClonesArray('Jet',1024)
    outTree.Branch('jet','TClonesArray',ROOT.AddressOf(jets))
    jetbranches=[]
    for branch in tree.GetListOfBranches():
        if not branch.GetName().startswith('jet_'): continue
        jetbranches.append(branch.GetName())

    tree.GetEntry(0)
    jet=ROOT.Jet()
    #jet.p4.SetPtEtaPhiE(tree.jet_pt[i],tree.jet_eta[i],tree.jet_phi[i],tree.jet_E[i])
    for jetbranch in jetbranches:
        newjetbranch=rename_jet.get(jetbranch,jetbranch[4:])
        if hasattr(jet,newjetbranch):
            setattr(jet,newjetbranch,getattr(tree,jetbranch)[0])
        else:
            print('missing %s'%jetbranch)
        
    print(jetbranches)
    print(tree.GetBranch('njet'))
    for e in tree:
        # jet
        jets.Clear()
        for i in range(tree.njet if tree.GetBranch('njet')!=0 else tree.njets):
            jet=ROOT.Jet()
            jet.p4.SetPtEtaPhiE(tree.jet_pt[i],tree.jet_eta[i],tree.jet_phi[i],tree.jet_E[i])
            if tree.Branch('jet_truth_E')!=0: jet.truth_p4.SetPtEtaPhiE(tree.jet_truth_pt[i],tree.jet_truth_eta[i],tree.jet_truth_phi[i],tree.jet_truth_E[i])
            for jetbranch in jetbranches:
                setattr(jet,jetbranch[4:],getattr(tree,jetbranch)[i])
            jets[i]=jet

        #
        outTree.Fill()

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


