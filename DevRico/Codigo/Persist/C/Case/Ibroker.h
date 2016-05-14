//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IBroker; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\ibroker.h


#ifndef IBroker_h
#define IBroker_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IDirecaoFetch
#include "IDrcFtch.h"

class IColecaoPersistenteBase;
class IStatement;
class IInsertStatement;
class IUpdateStatement;
class IDeleteStatement;
class IModifyStatement;
class IMapClassTable;
class IClassMap;
class IDataStore;
class IPersistente;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IBroker
//	Responsavel pelas operações DDL e DML e suas trascrições
//	entre os meios persistentes e as respectivas classes
//	persistentes.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; friend IClassMap {1 -> 1F}
//## Uses: <unnamed>; friend IStatement { -> F}
//## Uses: <unnamed>; IDirecaoFetch { -> }
//## Uses: <unnamed>; IInsertStatement { -> F}
//## Uses: <unnamed>; IUpdateStatement { -> F}
//## Uses: <unnamed>; IDeleteStatement { -> F}
//## Uses: <unnamed>; IMapClassTable { -> F}
//## Uses: <unnamed>; IPersistente { -> F}
//## Uses: <unnamed>; IModifyStatement { -> F}

class IBroker 
{
  //## begin IBroker.initialDeclarations preserve=yes
  //## end IBroker.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: inicialize%909189395
      //	processo de inicialização.
      static void inicialize();

      //## Operation: addDataStore%908596375
      //	adiciona o datastore a lista e passa a ser seu dono.
      //	deve sempre haver um datastore default. seguira o
      //	seguinte critério :
      //	1. se a listaDataStore estiver vazia quando de alguma
      //	operação que necessite dispara uma excessão.
      //	1. se houver somente um DataStore, será automáticamente
      //	DEFAULT
      //	2. se houver vários o primeiro que se chamar DEFAULT
      //	3. se houver vários e nenhum se chamar DEFAULT, será o
      //	primeiro da lista
      static void addDataStore(IDataStore& dataStore);

      //## Operation: saveMe%907292337
      //## Semantics:
      //	1. se objeto.isPersistido : cria IUpdateStatement e
      //	chama setID do Statement
      //	2. se ! objeto.isPersistido: cria IInsertStatement
      //	3. pega o DataStore do IPersistente com o IMapClassTable
      //	4. invoca DataStore.execute( IModifyStatement)
      //	5. altera o estado do IPersistente se deu tudo certo
      //	para Persistido.
      //	6. destroi IInsert ou IUpdate.
      static void saveMe(IPersistente& anPersist);

      //## Operation: deleteMe%908596376
      //## Preconditions:
      //	somente se objeto.isPersistido
      //## Semantics:
      //	1. monta IDeleteStatement de ac. com isPersistido
      //	2. pega o DataStore do IPersistente com o IMapClassTable
      //	3. invoca DataStore.execute( IModifyStatement)
      //	4. altera o estado do IPersistente se deu tudo certo
      //	para ! isPersistido.
      //	5. destroi IDelete.
      static void deleteMe(IPersistente& anPersiste);

      //## Operation: regDataStoreForClass%908596377
      //	registra o dataStore identificado pelo nome para a
      //	classe especificada.
      //	0. chama apresentoPersistente em self
      //	1. procura pelo dataStore em ListaDataStore
      //	2. se nao achar dispara um erro IPersistenteErro
      //	3. se achou pega uma referencia se chama
      //	IClassMap::setDataStoreFor
      static void regDataStoreForClass(IPersistente& anPersiste, char* dataStoreName);

      //## Operation: apresento%908596378
      //	serve para antecipar o reconhecimento das subclasses
      //	persistentes, faz o classmap ser inicializado com as
      //	informações do persistente.
      static void apresento(IPersistente& anPersistente);

      //## Operation: newColecao%908596379
      //	reconhece a nova coleção e insere-a na lista de coleções
      static void newColecao(IColecaoPersistenteBase& anColecao);

      //## Operation: processeColecao%908596380
      //	solicita processamento da
      //	IColecaoPersistenteBase.theQuery ao
      //	IColecaoPersistenteBase.theDataStore e muda o estado da
      //	colecao.
      static void processeColecao(IColecaoPersistenteBase& anColecao);

      //## Operation: libereColecao%908596381
      //	solicita processamento da
      //	IColecaoPersistenteBase.theQuery ao
      //	IColecaoPersistenteBase.theDataStore e muda o estado da
      //	colecao.
      static void libereColecao(IColecaoPersistenteBase& anColecao);

      //## Operation: requisitaObjeto%908596382
      //	processar requisicao de objeto na direcao especificada.
      static void requisitaObjeto(IColecaoPersistenteBase& anColecao, IDirecaoFetch direcao = proximo);

      //## Operation: TabelaRelacao%908938911
      //	retorna o nome da tabela relacao obtido do ClassMap
      static IString TabelaRelacao();

      //## Operation: DefaultDataStore%909457534
      //	Retorna o DataStore Default.
      static IDataStore& DefaultDataStore();

      //## Operation: asDebug%909457535
      //	retorna informações para debug.
      static IString asDebug();

      //## Operation: nomeColunaID%909724212
      static IString nomeColunaID();

      //## Operation: criarBasePara%910406193
      //	cria a base de dados para o persistente especifico.
      static void criarBasePara(IPersistente& anPersistente);

      //## Operation: removeDataStore%958533754
      //	remove o datastore da lista do mapa se estiver la.
      static void removeDataStore(IDataStore& dataStore);

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IBroker::ListaDataStore.has
      static Lista<IDataStore> ListaDataStore();
      static void setListaDataStore(const Lista<IDataStore> value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: estado
      static IEstadoGenerico estado();
      static void setestado(const IEstadoGenerico value);

    // Additional Public Declarations
      //## begin IBroker.public preserve=yes
      //## end IBroker.public


  protected:
    // Additional Protected Declarations
      //## begin IBroker.protected preserve=yes
      //## end IBroker.protected


  private:

    //## Other Operations (specified)
      //## Operation: preenchaMapa%909032151
      static void preenchaMapa(IPersistente& anPersist, IModifyStatement& anStatement, IMapClassTable& mapa);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: UsarDataStoreDefault
      //	usar o datastore default caso não seja especificado um.
      static bool UsarDataStoreDefault();
      static void setUsarDataStoreDefault(const bool value);

      //## Attribute: ixDStoreDefault
      //	guarda o indice do dataStore default.
      static int ixDStoreDefault();
      static void setixDStoreDefault(const int value);

    // Additional Private Declarations
      //## begin IBroker.private preserve=yes
      //## end IBroker.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IBroker::ListaDataStore.has preserve=no  public: static IDataStore { -> 1..nVFO}
      static Lista<IDataStore> m_ListaDataStore;
      //## end IBroker::ListaDataStore.has

      //## Documentation IBroker::theColecoes.has
      //## begin IBroker::theColecoes.has preserve=no  public: static IColecaoPersistenteBase { -> 1..nRFO}
      static ListaPointer<IColecaoPersistenteBase> m_theColecoes;
      //## end IBroker::theColecoes.has

    // Data Members for Class Attributes

      //## begin IBroker::UsarDataStoreDefault.attr preserve=no  private: static bool {U} true
      static bool m_UsarDataStoreDefault;
      //## end IBroker::UsarDataStoreDefault.attr

      //## begin IBroker::estado.attr preserve=no  public: static IEstadoGenerico {V} gInicial
      static IEstadoGenerico m_estado;
      //## end IBroker::estado.attr

      //## begin IBroker::ixDStoreDefault.attr preserve=no  private: static int {V} -1
      static int m_ixDStoreDefault;
      //## end IBroker::ixDStoreDefault.attr

    // Additional Implementation Declarations
      //## begin IBroker.implementation preserve=yes
#undef class
      //## end IBroker.implementation

};

// Class IBroker 





#endif


