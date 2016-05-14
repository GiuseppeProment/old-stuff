//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: ListaString; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\lststrng.h


#ifndef LstStrng_h
#define LstStrng_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// Lista
#include "Lista.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: ListaString; Instantiated Class
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef Lista<IString> ListaString;
// Instantiated Class ListaString 





#endif


