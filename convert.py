#!/usr/bin/env python

import sys
import ROOT

if len(sys.argv)!=3:
    print('usage: %s input output'%sys.argv[0])
    sys.exit(-1)

def copyTree(tree):
    outTree=ROOT.TTree(tree.GetName(),tree.GetTitle())
    for branch in tree.GetListOfBranches():
        if branch.GetClassName()=='':
            leaf=branch.GetListOfLeaves()[0]
            print(branch.GetName(),leaf.GetTypeName())
        else:
            print(branch.GetName(),branch.GetClassName())
    return outTree
    
fh_in =ROOT.TFile.Open(sys.argv[1])
fh_out=ROOT.TFile.Open(sys.argv[2],'RECREATE')

for key in fh_in.GetListOfKeys():
    obj=key.ReadObj()
    fh_out.cd()
    if key.GetName()=='outTree':
        copyTree(obj).Write()
    else:
        obj.Write()

fh_out.Close()
fh_in.Close()


