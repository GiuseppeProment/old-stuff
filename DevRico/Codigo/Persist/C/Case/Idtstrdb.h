//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDataStoreODBC; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\idtstrdb.h


#ifndef IDtStrDB_h
#define IDtStrDB_h 1

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
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

#ifndef CBUILDER
  #pragma comment(lib,"odbc32.lib")
#else
  #pragma comment(lib,"b_odbc32.lib")
#endif

#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif


//## end module.additionalDeclarations


//## Class: IDataStoreODBC
//	14.11.99 - temos problemas com alguns drivres de odbc
//	que não os da microsoft. Que invariavelmente não tem
//	capacidade para cursores rolaveis, e outras
//	características como cursores dinamicos. Temos que
//	prover mecanismos
//	para suporta-los. A Solução seria:
//	1. identificar a versão suportada de ODBC ( 2 ou 3 )
//	2. identificar o suporte a cursor rolavel ou somente
//	para frente
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IModifyStatement { -> F}
//## Uses: <unnamed>; friend IStatement { -> F}
//## Uses: <unnamed>; IQueryStatement { -> F}

class IDataStoreODBC : public IDataStore  //## Inherits: <unnamed>

{
  //## begin IDataStoreODBC.initialDeclarations preserve=yes
  //## end IDataStoreODBC.initialDeclarations

  public:
    //## Constructors (generated)
      IDataStoreODBC();

      IDataStoreODBC(const IDataStoreODBC &right);

    //## Destructor (generated)
      virtual ~IDataStoreODBC();


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
      //	IQueryStatement.lowLayerSlo
      IDataStore& libereQuery(IQueryStatement& anQuery);

      //## Operation: ligar%910153638
      //	conecta ao banco ou prepara-se para servir. dispara
      //	execessao.
      IDataStore& ligar();

      //## Operation: desligar%910153639
      IDataStore& desligar();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: DSN
      //	Data Source Name
      IString DSN();
      void setDSN(const IString value);

    // Additional Public Declarations
      //## begin IDataStoreODBC.public preserve=yes
      //## end IDataStoreODBC.public


  protected:
    // Additional Protected Declarations
      //## begin IDataStoreODBC.protected preserve=yes
      //## end IDataStoreODBC.protected


  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nVersaoODBC
      //	Versão de ODBC suportado pelo Driver em uso.
      int nVersaoODBC();
      void setnVersaoODBC(const int value);

      //## Attribute: IsCursorRolavelSuportado
      //	Indica se o driver em uso suporta Cursor Rolavel.
      //	Se não suportar vamos ter que prover ação compativel com
      //	navegação ou disparar excessão ou warning.
      bool IsCursorRolavelSuportado();
      void setIsCursorRolavelSuportado(const bool value);

    // Additional Private Declarations
      //## begin IDataStoreODBC.private preserve=yes
      //## end IDataStoreODBC.private


  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: aloqueENV%910153640
      void aloqueENV();

      //## Operation: aloqueDBC%910153641
      void aloqueDBC();

      //## Operation: conectar%910153642
      void conectar();

      //## Operation: freeHandles%910153643
      void freeHandles();

      //## Operation: aloqueStatementUmaLinha%910153640
      void aloqueStatementUmaLinha();

    // Data Members for Class Attributes

      //## begin IDataStoreODBC::DSN.attr preserve=no  public: IString {V} 
      IString m_DSN;
      //## end IDataStoreODBC::DSN.attr

      //## Attribute: hConnection
      //	SQL handle DataBase Connection.
      //## begin IDataStoreODBC::hConnection.attr preserve=no  private: SQLHDBC {V} 
      SQLHDBC m_hConnection;
      //## end IDataStoreODBC::hConnection.attr

      //## Attribute: hEnvironment
      //	SQL Handle Environment.
      //## begin IDataStoreODBC::hEnvironment.attr preserve=no  private: SQLHENV {V} 
      SQLHENV m_hEnvironment;
      //## end IDataStoreODBC::hEnvironment.attr

      //## Attribute: hStatement
      //	SQL Handle Statement para operações de uma linha.
      //## begin IDataStoreODBC::hStatement.attr preserve=no  private: SQLHSTMT {V} 
      SQLHSTMT m_hStatement;
      //## end IDataStoreODBC::hStatement.attr

      //## Attribute: IshConnection
      //## begin IDataStoreODBC::IshConnection.attr preserve=no  private: bool {V} false
      bool m_IshConnection;
      //## end IDataStoreODBC::IshConnection.attr

      //## Attribute: IshEnvironment
      //## begin IDataStoreODBC::IshEnvironment.attr preserve=no  private: bool {V} false
      bool m_IshEnvironment;
      //## end IDataStoreODBC::IshEnvironment.attr

      //## Attribute: IsConectado
      //## begin IDataStoreODBC::IsConectado.attr preserve=no  private: bool {V} false
      bool m_IsConectado;
      //## end IDataStoreODBC::IsConectado.attr

      //## Attribute: IshStatement
      //## begin IDataStoreODBC::IshStatement.attr preserve=no  private: bool {V} false
      bool m_IshStatement;
      //## end IDataStoreODBC::IshStatement.attr

      //## begin IDataStoreODBC::nVersaoODBC.attr preserve=no  private: int {V} 0
      int m_nVersaoODBC;
      //## end IDataStoreODBC::nVersaoODBC.attr

      //## begin IDataStoreODBC::IsCursorRolavelSuportado.attr preserve=no  private: bool {V} 
      bool m_IsCursorRolavelSuportado;
      //## end IDataStoreODBC::IsCursorRolavelSuportado.attr

      //## Attribute: queries
      //	lista de
      //## begin IDataStoreODBC::queries.attr preserve=no  private: ListaPointer<void> {U} 
      ListaPointer<void> m_queries;
      //## end IDataStoreODBC::queries.attr

    // Additional Implementation Declarations
      //## begin IDataStoreODBC.implementation preserve=yes
#undef class
      //## end IDataStoreODBC.implementation

};

// Class IDataStoreODBC 





#endif


