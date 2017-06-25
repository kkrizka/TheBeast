#!/usr/bin/env python

import ROOT
import csv
import sys
import glob
import os, os.path

if len(sys.argv)!=2:
    print('usage: %s dirpath'%sys.argv[0])
    sys.exit(-1)

def get_stats(filepath):
    fh=ROOT.TFile(filepath)
    outTree=fh.Get('outTree')
    if outTree==None: return None

    complevel=fh.GetCompressionLevel()
    filesize =fh.GetSize()
    compfact =fh.GetCompressionFactor()

    outTree=fh.Get('outTree')
    nEvents=outTree.GetEntries()
    
    fh.Close()

    dsname=os.path.basename(filepath)
    parts=dsname.split('.')
    scope=parts[2]
    selection=parts[5] if 'mc' in scope else parts[4]

    stat={'dsname'   :dsname,
          'scope'    :scope,
          'selection':selection,
          'size'     :filesize,
          'nevents'  :nEvents,
          'complevel':complevel,
          'compfact':compfact}

    return stat

csvfile=open('dsstat.csv', 'w')
csvwriter = csv.DictWriter(csvfile, fieldnames=['dsname','scope','selection','size','nevents','complevel','compfact'])
csvwriter.writeheader()

for filepath in glob.glob('%s/*root'%sys.argv[1]):
    if 'debugrec' in filepath: continue

    info=get_stats(filepath)
    if info==None: continue

    csvwriter.writerow(get_stats(filepath))
