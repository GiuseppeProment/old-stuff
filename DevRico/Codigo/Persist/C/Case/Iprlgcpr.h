//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IOperLogicoPrecedencia; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iprlgcpr.h


#ifndef IprLgcPr_h
#define IprLgcPr_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IOperLogicoPrecedencia
//	enum {AND,OR,AbreParentesis,FechaParentesis}
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum {
AND,
OR 
} IOperLogicoPrecedencia;
// Class IOperLogicoPrecedencia 





#endif


