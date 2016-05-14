//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IBroker; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\ibroker.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IColecaoPersistenteBase
#include "IClcPrss.h"
// IStatement
#include "ISttment.h"
// IInsertStatement
#include "InsrtStt.h"
// IUpdateStatement
#include "IpdtSttm.h"
// IDeleteStatement
#include "IDltSttm.h"
// IModifyStatement
#include "IMdfyStt.h"
// IMapClassTable
#include "IMpClssT.h"
// IClassMap
#include "IClssMap.h"
// IDataStore
#include "IDtStore.h"
// IBroker
#include "IBroker.h"
// IPersistente
#include "IPrsstnt.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IBroker

//## begin IBroker::ListaDataStore.has preserve=no  public: static IDataStore { -> 1..nVFO}
Lista<IDataStore> IBroker::m_ListaDataStore;
//## end IBroker::ListaDataStore.has

//## begin IBroker::theColecoes.has preserve=no  public: static IColecaoPersistenteBase { -> 1..nRFO}
ListaPointer<IColecaoPersistenteBase> IBroker::m_theColecoes;
//## end IBroker::theColecoes.has

//## begin IBroker::UsarDataStoreDefault.attr preserve=no  private: static bool {U} true
bool IBroker::m_UsarDataStoreDefault = true;
//## end IBroker::UsarDataStoreDefault.attr

//## begin IBroker::estado.attr preserve=no  public: static IEstadoGenerico {V} gInicial
IEstadoGenerico IBroker::m_estado = gInicial;
//## end IBroker::estado.attr

//## begin IBroker::ixDStoreDefault.attr preserve=no  private: static int {V} -1
int IBroker::m_ixDStoreDefault = -1;
//## end IBroker::ixDStoreDefault.attr


//## Other Operations (implementation)
void IBroker::inicialize()
{
  //## begin IBroker::inicialize%909189395.body preserve=yes
  if ( estado() == gInicial )
  {
    // separar datastore default
    #pragma message(":-/ IBroker::inicialize() imp. rot. DS default...")
    setixDStoreDefault(1);

    setestado(gInicializado);

    IClassMap::inicialize();
  }
  //## end IBroker::inicialize%909189395.body
}

void IBroker::addDataStore(IDataStore& dataStore)
{
  //## begin IBroker::addDataStore%908596375.body preserve=yes
  //if ( estado() != gInicial ) {
  //  throw(
  //    IErro("IBroker::addDataStore() nao pode ser chamado apos inicializacao")
  //    ); }

  // adicionar na lista
  m_ListaDataStore.adiciona( dataStore );
  //## end IBroker::addDataStore%908596375.body
}

void IBroker::saveMe(IPersistente& anPersist)
{
  //## begin IBroker::saveMe%907292337.body preserve=yes
  //:-> pegar mapa
  // chegou ate'aqui
  IMapClassTable& mapa = IClassMap::getMapaFor( anPersist );
  IDataStore* anDataStore = mapa.DataStore();
  //:-> decidir entre insert/update
  if ( anPersist.isPersistido() == true )
  {
    IUpdateStatement theStatement;
    theStatement.settabelaAlvo(mapa.nomeTabela());
    theStatement.setID( anPersist.ID() );
    //:-\ adicionar mapa
    preenchaMapa(anPersist,theStatement,mapa);
    if ( anDataStore->execute( theStatement ) )
    ;
  }else
  {
    IInsertStatement theStatement;
    theStatement.settabelaAlvo(mapa.nomeTabela());
    //:-> solicitar geracao ID
    IPersistID newID;
    newID.generate();
    anPersist.setID(newID);
    theStatement.setID( anPersist.ID() );
    //:-\ adicionar mapa
    preenchaMapa(anPersist,theStatement,mapa);
    if ( anDataStore->execute( theStatement ) )
      anPersist.setisPersistido(true);
  }
  //## end IBroker::saveMe%907292337.body
}

void IBroker::deleteMe(IPersistente& anPersiste)
{
  //## begin IBroker::deleteMe%908596376.body preserve=yes
  if ( anPersiste.isPersistido() == true )
  {
		IMapClassTable& mapa = IClassMap::getMapaFor( anPersiste );
		IDataStore* anDataStore = mapa.DataStore();
    IDeleteStatement theStatement;
    theStatement.settabelaAlvo(mapa.nomeTabela());
    theStatement.setID( anPersiste.ID() );
    if ( anDataStore->execute( theStatement ) )
      anPersiste.setisPersistido(false);
  }else
		throw(
      IErro("IBroker::deleteMe objeto não persistido."));
  //## end IBroker::deleteMe%908596376.body
}

void IBroker::preenchaMapa(IPersistente& anPersist, IModifyStatement& anStatement, IMapClassTable& mapa)
{
  //## begin IBroker::preenchaMapa%909032151.body preserve=yes
  //:-) ler as lista de IMapAtrColuna do mapa e inserir coluna e valor
  //    no statement
  for (int i=1; i<=mapa.ListaAtributos().count(); i++ )
  {
    anStatement.
      addColunaValor(
#pragma message("IBroker::preenchaMapa erro. nomeMembro não é nomeColuna!")
        mapa.ListaAtributos()[i]->nomeMembro(),
        mapa.ListaAtributos()[i]->asString(anPersist) );
  }
  //## end IBroker::preenchaMapa%909032151.body
}

void IBroker::regDataStoreForClass(IPersistente& anPersiste, char* dataStoreName)
{
  //## begin IBroker::regDataStoreForClass%908596377.body preserve=yes
  // var. aux
  int Posicao=-1;
  int i;
  //
  for( i=1; i<=m_ListaDataStore.count(); i++ )
  {
     if ( (m_ListaDataStore[Posicao].nome()==dataStoreName)==true )
     { Posicao=i;
       break;
     }
  }
  if ( Posicao==-1 )
  {
    throw(
      IErro("IBroker::regDataStoreForClass DataStore nao existe."));
  }
  IClassMap::setDataStoreFor(anPersiste,m_ListaDataStore[Posicao]);
  //## end IBroker::regDataStoreForClass%908596377.body
}

void IBroker::apresento(IPersistente& anPersistente)
{
  //## begin IBroker::apresento%908596378.body preserve=yes
  // :-| ficou com funcao duvidosa pois o IClassMap::getMapaFor
  //     j  cuida da apresenta‡Æo
  IClassMap::getMapaFor( anPersistente );
  //## end IBroker::apresento%908596378.body
}

void IBroker::newColecao(IColecaoPersistenteBase& anColecao)
{
  //## begin IBroker::newColecao%908596379.body preserve=yes
	// apresentar
  if ( estado() != gInicializado  )
  {
    throw(
      IErro("IBroker::newColecao() Broker nao inicializado!")
      );
  }
  IPersistente* pNulo = anColecao.createDummy( );
  IMapClassTable& mapa = IClassMap::getMapaFor( *pNulo );
	anColecao.releaseDummy( pNulo );
	// inserir na lista
	m_theColecoes.adiciona( &anColecao );
	//	criar o query
	IQueryStatement & theQuery= anColecao.theQuery();
	// dizer tabela
  theQuery.settabelaAlvo(mapa.nomeTabela());
	// adicionar colunas
	// e espaco para os valores
  for (int i=1; i<=mapa.ListaAtributos().count(); i++ )
  {
    theQuery.
      addColuna(
        mapa.ListaAtributos()[i]->nomeMembro() );

		IString* buffer = new IString();
		buffer->setLenTo( mapa.ListaAtributos()[i]->tamanho() );
		theQuery.theValues().adiciona( *buffer );

  }
	#pragma message(":-/ IBroker::newColecao - falta tradução dos criterios ")
	// traduzir criterios e ordens
	// passa-las para o theQuery
	// passar dados para a colecao
	anColecao.settheDataStore( mapa.DataStore() );

  //## end IBroker::newColecao%908596379.body
}

void IBroker::processeColecao(IColecaoPersistenteBase& anColecao)
{
  //## begin IBroker::processeColecao%908596380.body preserve=yes

	anColecao.theDataStore()->execute( anColecao.theQuery() );

  //## end IBroker::processeColecao%908596380.body
}

void IBroker::libereColecao(IColecaoPersistenteBase& anColecao)
{
  //## begin IBroker::libereColecao%908596381.body preserve=yes
	anColecao.theDataStore()->libereQuery( anColecao.theQuery() );
  //## end IBroker::libereColecao%908596381.body
}

void IBroker::requisitaObjeto(IColecaoPersistenteBase& anColecao, IDirecaoFetch direcao)
{
  //## begin IBroker::requisitaObjeto%908596382.body preserve=yes

	// :-) Pegar Objetos para trabalhar

	IDataStore &dataStore =
		*( anColecao.theDataStore() );

	IQueryStatement &theQuery =
		anColecao.theQuery();

	// :-> solicitar criação de objeto persistente

	IPersistente &thePersistente =
		anColecao.crieInstancia();

  IMapClassTable& mapa =
		IClassMap::getMapaFor( thePersistente );

	// :-) Solicitar serviço de mais baixo nível

	dataStore.requisitaDados(theQuery,direcao);

	// :-) transcrever dados para o objeto persistente

  for (int i=1; i<=mapa.ListaAtributos().count(); i++ )
  {
    mapa.ListaAtributos()[i]->
			setValue( thePersistente,
								theQuery.theValues()[i]
							);
  }

  // :-) esta persistido sim
  thePersistente.setisPersistido(true);
  // :-) ajustar o ID real
	IPersistID newID;
	newID.setValue(theQuery.ValueID());
  thePersistente.setID( newID );

  //## end IBroker::requisitaObjeto%908596382.body
}

IString IBroker::TabelaRelacao()
{
  //## begin IBroker::TabelaRelacao%908938911.body preserve=yes
  //## end IBroker::TabelaRelacao%908938911.body

  return IClassMap::TabelaRelacao();
}

IDataStore& IBroker::DefaultDataStore()
{
  //## begin IBroker::DefaultDataStore%909457534.body preserve=yes
  if ( estado() != gInicializado  )
  {
    throw(
      IErro("IBroker::DefaultDataStore() Broker nao inicializado!")
      );
  }

  if ( m_UsarDataStoreDefault != true )
  {
    throw(
      IErro("IBroker::DefaultDataStore() UsarDataStoreDefault Nao Habilitado")
      );
  }

  // checar datastores
  if ( m_ListaDataStore.count() == 0  )
  {
    throw(
      IErro("IBroker::DefaultDataStore() Lista de DataStore esta vazia!")
      );
  }

  return m_ListaDataStore[m_ixDStoreDefault];
  //## end IBroker::DefaultDataStore%909457534.body
}

IString IBroker::asDebug()
{
  //## begin IBroker::asDebug%909457535.body preserve=yes
	IString cRet;
	cRet = "\n**Informações de Debug\n**";
	cRet+=IClassMap::asDebug();
  return cRet;
  //## end IBroker::asDebug%909457535.body
}

IString IBroker::nomeColunaID()
{
  //## begin IBroker::nomeColunaID%909724212.body preserve=yes
  //## end IBroker::nomeColunaID%909724212.body

  return IClassMap::ColunaId();
}

void IBroker::criarBasePara(IPersistente& anPersistente)
{
  //## begin IBroker::criarBasePara%910406193.body preserve=yes
  //## end IBroker::criarBasePara%910406193.body
}

void IBroker::removeDataStore(IDataStore& dataStore)
{
  //## begin IBroker::removeDataStore%958533754.body preserve=yes
  m_ListaDataStore.removeObjeto( dataStore );
  IClassMap::removeDataStore( dataStore );
  //## end IBroker::removeDataStore%958533754.body
}

//## Get and Set Operations for Has Relationships (implementation)

Lista<IDataStore> IBroker::ListaDataStore()
{
  //## begin IBroker::ListaDataStore%.get preserve=no
  return m_ListaDataStore;
  //## end IBroker::ListaDataStore%.get
}

void IBroker::setListaDataStore(const Lista<IDataStore> value)
{
  //## begin IBroker::setListaDataStore%.set preserve=no
  m_ListaDataStore = value;
  //## end IBroker::setListaDataStore%.set
}

//## Get and Set Operations for Class Attributes (implementation)

bool IBroker::UsarDataStoreDefault()
{
  //## begin IBroker::UsarDataStoreDefault%.get preserve=no
  return m_UsarDataStoreDefault;
  //## end IBroker::UsarDataStoreDefault%.get
}

void IBroker::setUsarDataStoreDefault(const bool value)
{
  //## begin IBroker::setUsarDataStoreDefault%.set preserve=no
  m_UsarDataStoreDefault = value;
  //## end IBroker::setUsarDataStoreDefault%.set
}

IEstadoGenerico IBroker::estado()
{
  //## begin IBroker::estado%.get preserve=no
  return m_estado;
  //## end IBroker::estado%.get
}

void IBroker::setestado(const IEstadoGenerico value)
{
  //## begin IBroker::setestado%.set preserve=no
  m_estado = value;
  //## end IBroker::setestado%.set
}

int IBroker::ixDStoreDefault()
{
  //## begin IBroker::ixDStoreDefault%.get preserve=no
  return m_ixDStoreDefault;
  //## end IBroker::ixDStoreDefault%.get
}

void IBroker::setixDStoreDefault(const int value)
{
  //## begin IBroker::setixDStoreDefault%.set preserve=no
  m_ixDStoreDefault = value;
  //## end IBroker::setixDStoreDefault%.set
}


// Additional Declarations
//## begin IBroker.declarations preserve=yes
//## end IBroker.declarations




