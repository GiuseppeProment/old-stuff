//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IKnowType; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iknwtype.h


#ifndef IKnwType_h
#define IKnwType_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IKnowType
//	ISTO É UM ENUM DOS TIPOS CONHECIDOS.
//	Existe uma brecha que é IsUnknow e IsUnknowPointe
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum 
 { IsDouble,
   IsFloat,
   IsInt,
   IsShortInt,
   IsChar,
   IsCharArray,
   IsTimestamp,
   IsStringBlob,
   IsStringVar,
   IsStringFix,
   IsUnknow,
   // ponteiros
   IsDoublePointer,
   IsFloatPointer,
   IsIntPointer,
   IsShortIntPointer,
   IsCharPointer,
   IsCharArrayPointer,
   IsTimestampPointer,
   IsStringBlobPointer,
   IsStringVarPointer,
   IsStringFixPointer,
   IsUnknowPointer }
 IKnowType;
// Class IKnowType 





#endif


