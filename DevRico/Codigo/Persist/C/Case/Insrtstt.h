//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IInsertStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\insrtstt.h


#ifndef InsrtStt_h
#define InsrtStt_h 1

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


//## Class: IInsertStatement
//	INSERT INTO <tabela>  (nomeColuna),...  VALUES (exp,...)
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IInsertStatement : public IModifyStatement  //## Inherits: <unnamed>

{
  //## begin IInsertStatement.initialDeclarations preserve=yes
  //## end IInsertStatement.initialDeclarations

  public:
    //## Constructors (generated)
      IInsertStatement();

      IInsertStatement(const IInsertStatement &right);

    //## Destructor (generated)
      ~IInsertStatement();


    //## Other Operations (specified)
      //## Operation: asSentencaSQL%908596361
      IString asSentencaSQL();

    // Additional Public Declarations
      //## begin IInsertStatement.public preserve=yes
      //## end IInsertStatement.public


  protected:
    // Additional Protected Declarations
      //## begin IInsertStatement.protected preserve=yes
      //## end IInsertStatement.protected


  private:
    // Additional Private Declarations
      //## begin IInsertStatement.private preserve=yes
      //## end IInsertStatement.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IInsertStatement.implementation preserve=yes
#undef class
      //## end IInsertStatement.implementation

};

// Class IInsertStatement





#endif


