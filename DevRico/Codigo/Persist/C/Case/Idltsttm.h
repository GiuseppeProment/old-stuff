//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDeleteStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\idltsttm.h


#ifndef IDltSttm_h
#define IDltSttm_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IModifyStatement
#include "IMdfyStt.h"

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IDeleteStatement
//	DELETE <tabela>
//	WHERE [ CURRENT OF <cursorName> | where_clausula ]
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IDeleteStatement : public IModifyStatement  //## Inherits: <unnamed>

{
  //## begin IDeleteStatement.initialDeclarations preserve=yes
  //## end IDeleteStatement.initialDeclarations

  public:
    //## Constructors (generated)
      IDeleteStatement();

      IDeleteStatement(const IDeleteStatement &right);

    //## Destructor (generated)
      ~IDeleteStatement();


    //## Other Operations (specified)
      //## Operation: asSentencaSQL%908596362
      IString asSentencaSQL();

    // Additional Public Declarations
      //## begin IDeleteStatement.public preserve=yes
      //## end IDeleteStatement.public


  protected:
    // Additional Protected Declarations
      //## begin IDeleteStatement.protected preserve=yes
      //## end IDeleteStatement.protected


  private:
    // Additional Private Declarations
      //## begin IDeleteStatement.private preserve=yes
      //## end IDeleteStatement.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IDeleteStatement.implementation preserve=yes
#undef class
      //## end IDeleteStatement.implementation

};

// Class IDeleteStatement





#endif


