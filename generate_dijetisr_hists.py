#!/usr/bin/env python

import argparse
parser = argparse.ArgumentParser(description="Generate IParticle hists class")
parser.add_argument('config',help="Config defining the histograms.")
parser.add_argument('name',help="Name of particle.")
args = parser.parse_args()

import json
with open(args.config) as data_file:    
    data = json.load(data_file)

#
# Print header
fh_header = open('%sHists.h'%args.name,'w')

fh_header.write('#ifndef %sHISTS_H_\n'%args.name.upper())
fh_header.write('#define %sHISTS_H_\n'%args.name.upper())
fh_header.write('\n')
fh_header.write('#include "IParticleHists.h"\n')
fh_header.write('\n')
fh_header.write('class %sHists : public IParticleHists\n'%args.name)
fh_header.write('{\n')
fh_header.write('public:\n')
fh_header.write('  %sHists(DijetISREvent::Container container, int idx, const std::string& titleprefix="%s");\n'%(args.name,args.name.lower()))
fh_header.write('  virtual ~%sHists() ;\n'%(args.name))
fh_header.write('  \n')
fh_header.write('  virtual void initialize(TheEvent *event);\n')
fh_header.write('  virtual void execute();\n')
fh_header.write('\n')
fh_header.write('private:\n')

# stuff
for key,values in data.items():
    fh_header.write('  // %s\n'%key)
    for value in values:
        fh_header.write('  TH1 *h_%s;\n'%value)

fh_header.write('};\n')
fh_header.write('\n')
fh_header.write('#endif // %sHISTS_H_\n'%(args.name.upper()))

fh_header.close()

#
# Print cxx
fh_source = open('%sHists.cxx'%args.name,'w')

fh_source.write('#include "%sHists.h"\n'%args.name)
fh_source.write('#include <sstream>\n')
fh_source.write('#include <math.h>\n')
fh_source.write('\n')
fh_source.write('%sHists::%sHists(DijetISREvent::Container container, int idx, const std::string& title)\n'%(args.name,args.name))
fh_source.write('  : IParticleHists(container, idx, title)\n')
fh_source.write('{ }\n')
fh_source.write('\n')
fh_source.write('%sHists::~%sHists()\n'%(args.name,args.name))
fh_source.write('{ }\n')
fh_source.write('\n')
fh_source.write('void %sHists::initialize(TheEvent *event)\n'%(args.name))
fh_source.write('{\n')
fh_source.write('  IParticleHists::initialize(event);\n')
fh_source.write('\n')
#fh_source.write('  %sInfoSwitch *infoSwitch=&dynamic_cast<DijetISREvent*>(event)->m_%ss->m_infoSwitch;\n'%(args.name,args.name.lower()))
#fh_source.write('\n')

# stuff
for key,values in data.items():
    fh_source.write('  // %s\n'%key)
    #fh_source.write('  if( infoSwitch->m_%s ) {\n'%key)
    for histname,histinfo in values.items():
        fh_source.write('  h_%s = book("%s", m_title+"%s", %d, %f, %f);\n'%(histname,histname,histinfo[0],int(histinfo[1]),float(histinfo[2]),float(histinfo[3])))
    #fh_source.write('  }\n')
fh_source.write('}\n')

fh_source.write('void JetHists::execute()\n')
fh_source.write('{\n')
fh_source.write('  IParticleHists::execute();\n')
fh_source.write('\n')
fh_source.write('  %sInfoSwitch *infoSwitch;\n'%(args.name))
fh_source.write('  const %s *particle=0;\n'%args.name)
fh_source.write('  switch(m_container)\n')
fh_source.write('    {\n')
fh_source.write('    case DijetISREvent::%s:\n'%args.name.lower())
fh_source.write('      particle=&m_event->m_%ss->at(m_idx);\n'%args.name.lower())
fh_source.write('      infoSwitch=&m_event->m_%ss->m_infoSwitch;\n'%args.name.lower())
fh_source.write('      break;\n')
fh_source.write('    default:\n')
fh_source.write('      std::cerr << "Not a %s container." << std::endl;\n'%args.name.lower())
fh_source.write('      return;\n')
fh_source.write('      break;\n')
fh_source.write('    }\n')
fh_source.write('\n')
fh_source.write('  double eventWeight=1.;  \n')
fh_source.write('\n')
# stuff
for key,values in data.items():
    fh_source.write('  // %s\n'%key)
    fh_source.write('  if( infoSwitch->m_%s ) {\n'%key)
    for histname,histinfo in values.items():
        fh_source.write('      h_%s->Fill(particle->%s,eventWeight);\n'%(histname,histname))
    fh_source.write('  }\n')
fh_source.write('}\n')
fh_source.write('\n')

fh_source.close()
