//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IOperComparacao; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iprcmprc.h


#ifndef IprCmprc_h
#define IprCmprc_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IOperComparacao
//	enum {
//	maior,menor,maiorOuIgual,menorOuIgual,igual,diferente,sim
//	ilar,
//	entre,dentro }
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum {
maior,
menor,
maiorOuIgual,
menorOuIgual,
igual,
diferente,
similar,
entre,
dentro }
 IOperComparacao;
// Class IOperComparacao 





#endif


