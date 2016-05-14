//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDirecaoFetch; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\idrcftch.h


#ifndef IDrcFtch_h
#define IDrcFtch_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IDirecaoFetch
//	enum dos tipos de fetch
//	primeiro,ultimo
//	proximo,previo
//	reavalia
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum {
primeiro,ultimo,
proximo,previo,
reavalia } IDirecaoFetch;
// Class IDirecaoFetch 





#endif


