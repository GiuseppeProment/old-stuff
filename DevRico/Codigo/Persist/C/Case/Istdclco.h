//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IEstadoColecao; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\istdclco.h


#ifndef IstdClco_h
#define IstdClco_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IEstadoColecao
//	enum : novo,pronto,terminado,erro
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum { nova,pronta,terminada,erro }
 IEstadoColecao;
// Class IEstadoColecao 





#endif


