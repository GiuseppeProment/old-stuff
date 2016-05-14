//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IModifyStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\imdfystt.h


#ifndef IMdfyStt_h
#define IMdfyStt_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IStatement
#include "ISttment.h"
// IPersistID
#include "IPrsstID.h"

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IModifyStatement
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IModifyStatement : public IStatement  //## Inherits: <unnamed>

{
  //## begin IModifyStatement.initialDeclarations preserve=yes
  //## end IModifyStatement.initialDeclarations

  public:
    //## Constructors (generated)
      IModifyStatement();

      IModifyStatement(const IModifyStatement &right);

    //## Destructor (generated)
      ~IModifyStatement();


    //## Other Operations (specified)
      //## Operation: addColunaValor%908596356
      //	adiciona coluna,valor nas respectivas listas, é apenas
      //	um facilitador já que usará o AddColuna herdado e
      //	acessará o theValues[].
      IModifyStatement& addColunaValor(IString& coluna, IString& valor);

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IModifyStatement::ID.has
      //	exigido por Delete e Update e ignorado por Insert
      IPersistID ID();
      void setID(const IPersistID value);

    // Additional Public Declarations
      //## begin IModifyStatement.public preserve=yes
      //## end IModifyStatement.public


  protected:

    //## Other Operations (specified)
      //## Operation: getParteWhereID%908596357
      //	retorna algo similar a "WHERE ID=345234534" é o id do
      //	objeto sendo manipulado.
      IString getParteWhereID();

    // Additional Protected Declarations
      //## begin IModifyStatement.protected preserve=yes
      //## end IModifyStatement.protected


  private:
    // Additional Private Declarations
      //## begin IModifyStatement.private preserve=yes
      //## end IModifyStatement.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IModifyStatement::ID.has preserve=no  public: IPersistID { -> 1VO}
      IPersistID m_ID;
      //## end IModifyStatement::ID.has

    // Additional Implementation Declarations
      //## begin IModifyStatement.implementation preserve=yes
#undef class
      //## end IModifyStatement.implementation

};

// Class IModifyStatement





#endif


