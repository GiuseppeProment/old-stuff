//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IUpdateStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ipdtsttm.h


#ifndef IpdtSttm_h
#define IpdtSttm_h 1

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


//## Class: IUpdateStatement
//	UPDATE <tabela> SET (nomeColuna)=exp,...
//	WHERE [ CURRENT OF <cursorName> | where_clausula ]
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IUpdateStatement : public IModifyStatement  //## Inherits: <unnamed>

{
  //## begin IUpdateStatement.initialDeclarations preserve=yes
  //## end IUpdateStatement.initialDeclarations

  public:
    //## Constructors (generated)
      IUpdateStatement();

      IUpdateStatement(const IUpdateStatement &right);

    //## Destructor (generated)
      ~IUpdateStatement();


    //## Other Operations (specified)
      //## Operation: asSentencaSQL%908596355
      IString asSentencaSQL();

    // Additional Public Declarations
      //## begin IUpdateStatement.public preserve=yes
      //## end IUpdateStatement.public


  protected:
    // Additional Protected Declarations
      //## begin IUpdateStatement.protected preserve=yes
      //## end IUpdateStatement.protected


  private:
    // Additional Private Declarations
      //## begin IUpdateStatement.private preserve=yes
      //## end IUpdateStatement.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IUpdateStatement.implementation preserve=yes
#undef class
      //## end IUpdateStatement.implementation

};

// Class IUpdateStatement





#endif


