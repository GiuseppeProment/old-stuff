//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IQuandoEventoClosure; Pseudo Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\iqndvntc.h


#ifndef IQndvntC_h
#define IQndvntC_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IQuandoEventoClosure
//	é apenas
//	typedef void (__closure *IQuandoEventoClosure ) (
//	IEventoNotificacaoBuilder& );
//	somente para simplificar os tipos.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef void (__closure *  IQuandoEventoClosure) ( IEventoNotificacaoBuilder& );
// Class IQuandoEventoClosure 





#endif


