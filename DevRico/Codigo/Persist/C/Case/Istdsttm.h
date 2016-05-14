//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IEstadoStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\istdsttm.h


#ifndef IstdSttm_h
#define IstdSttm_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IEstadoStatement
//	enum {
//	novo, incompleto, completo, executando,
//	executado ,falhou ,terminado }
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum { 
novo, 
incompleto, 
completo, 
executando, 
executado ,
falhou ,
terminado }
 IEstadoStatement;
// Class IEstadoStatement 





#endif


