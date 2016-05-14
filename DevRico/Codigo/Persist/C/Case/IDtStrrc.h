//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDataStoreOracleActivex; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\idtstrrc.h


#ifndef IDtStrrc_h
#define IDtStrrc_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IDataStore
#include "IDtStore.h"

class IStatement;
class IQueryStatement;
class IModifyStatement;

//## begin module.additionalDeclarations preserve=yes
#ifndef CBUILDER
  #include "oracl.h"
  #pragma comment(lib,"oraclm32")
#else
  #include "CORA_B.h"
#endif
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IDataStoreOracleActivex
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IQueryStatement { -> F}
//## Uses: <unnamed>; IModifyStatement { -> F}
//## Uses: <unnamed>; friend IStatement { -> F}

class IDataStoreOracleActivex : public IDataStore  //## Inherits: <unnamed>

{
  //## begin IDataStoreOracleActivex.initialDeclarations preserve=yes
  //## end IDataStoreOracleActivex.initialDeclarations

  public:
    //## Constructors (generated)
      IDataStoreOracleActivex();

      IDataStoreOracleActivex(const IDataStoreOracleActivex &right);

    //## Destructor (generated)
      ~IDataStoreOracleActivex();


    //## Other Operations (specified)
      //## Operation: execute%908596370
      //	deve afetar somente 1 linha, senão é merda.
      bool execute(IModifyStatement& setenca);

      //## Operation: execute%908596371
      bool execute(IQueryStatement& anQuery);

      //## Operation: requisitaDados%908596372
      //## Semantics:
      //	utiliza o lowLayerSlot :
      //	1. checa se não é 0
      //	2. checa o estado do Statement
      //	3. obtem os dados de canal do lowLayerSlot que são
      //	dependentes da implementação.
      //	4. copia os dados do canal para o theValues no IQuery
      //	5. se não há dados (eof/bof) ajusta isFim do Query para
      //	true. não muda os dados.
      IDataStore& requisitaDados(IQueryStatement& theQuery, IDirecaoFetch tipo = proximo);

      //## Operation: isFim%908596373
      //	retorna true se a operação de moveCursor encontra o
      //	inicio ou fim dos dados.
      bool isFim(IQueryStatement& theQuery);

      //## Operation: libereQuery%908596374
      //	libera alocações que estão guardadas no
      //	IQueryStatement.lowLayerSlot
      IDataStore& libereQuery(IQueryStatement& anQuery);

      //## Operation: ligar%910153638
      //	conecta ao banco ou prepara-se para servir.
      IDataStore& ligar();

      //## Operation: desligar%910153639
      IDataStore& desligar();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nomeDb
      //	nome do banco de dados a trabalhar (ou serviço).
      IString nomeDb();
      void setnomeDb(const IString value);

    // Additional Public Declarations
      //## begin IDataStoreOracleActivex.public preserve=yes
      //## end IDataStoreOracleActivex.public


  protected:

    //## Other Operations (specified)
      //## Operation: PegueDados%923520300
      //	Transfere os dados vindos do Banco Dados Oracle para o
      //	objeto temporario.
      void PegueDados(ODynaset* pDyn, IQueryStatement& theQuery);

    // Additional Protected Declarations
      //## begin IDataStoreOracleActivex.protected preserve=yes
      //## end IDataStoreOracleActivex.protected


  private:
    // Additional Private Declarations
      //## begin IDataStoreOracleActivex.private preserve=yes
      //## end IDataStoreOracleActivex.private


  private:  //## implementation
    // Data Members for Class Attributes

      //## begin IDataStoreOracleActivex::nomeDb.attr preserve=no  public: IString {V}
      IString m_nomeDb;
      //## end IDataStoreOracleActivex::nomeDb.attr

      //## Attribute: dataBase
      //	Instancia da classe ODatabase providenciada pela Oracle
      //	Co. para acesso ao banco de dados.
      //## begin IDataStoreOracleActivex::dataBase.attr preserve=no  private: ODatabase {V}
      ODatabase m_dataBase;
      //## end IDataStoreOracleActivex::dataBase.attr

    // Additional Implementation Declarations
      //## begin IDataStoreOracleActivex.implementation preserve=yes
#undef class
      //## end IDataStoreOracleActivex.implementation

};

// Class IDataStoreOracleActivex





#endif


