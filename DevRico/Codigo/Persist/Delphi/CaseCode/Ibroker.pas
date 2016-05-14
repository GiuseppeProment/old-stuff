unit IBrokerUnit;

interface

uses IUtil,Enums;

type

  IColecaoPersistenteBase = class ;
  IPersistente            = class ;
  IInsertStatement        = class ;
  IUpdateStatement        = class ;
  IDeleteStatement        = class ;
  IModifyStatement        = class ;
  IStatement              = class ;
  IMapClassTable          = class ;
  IClassMap               = class ;
  IDataStore              = class ;

 {## Class: IBroker
    Responsavel pelas operações DDL e DML e suas trascrições
    entre os meios persistentes e as respectivas classes
    persistentes.}

type
IBroker = class
public
  procedure inicialize;
  procedure addDataStore( dataStore:IDataStore);
  procedure saveMe(anPersist:IPersistente);
  procedure deleteMe(anPersiste:IPersistente);
  procedure regDataStoreForClass(anPersiste:IPersistente; dataStoreName:string);
  procedure apresento( anPersistente:IPersistente);
  procedure newColecao(anColecao:IColecaoPersistenteBase);
  procedure processeColecao(anColecao:IColecaoPersistenteBase);
  procedure libereColecao(anColecao:IColecaoPersistenteBase);
  procedure requisitaObjeto(anColecao:IColecaoPersistenteBase; direcao:IDirecaoFetch = proximo);
  procedure criarBasePara(anPersistente:IPersistente);
  function TabelaRelacao():string;
  function DefaultDataStore():IDataStore;
  function asDebug():string;
  function nomeColunaID():string;
  { ## Get and Set Operations for Has Relationships (generated) }
  function ListaDataStore():Lista ;
  procedure setListaDataStore(const value:Lista );
protected
private
  procedure preenchaMapa(anPersist:IPersistente; anStatement:IModifyStatement; mapa:IMapClassTable);
  { ## Get and Set Operations for Class Attributes (generated) }
  function UsarDataStoreDefault():bool ;
  procedure setUsarDataStoreDefault(const value:bool );
  { ## Attribute: estado }
  function estado():IEstadoGenerico ;
  procedure setestado(const value:IEstadoGenerico );
  { ## Attribute: ixDStoreDefault }
  function ixDStoreDefault():integer;
  procedure setixDStoreDefault(const value:integer);
private { ## implementation }
  { Data Members for Has Relationships }
  m_ListaDataStore:Lista ;
  m_theColecoes:ListaPointer;
  { Data Members for Class Attributes }
  m_UsarDataStoreDefault:boolean;
  m_estado:IEstadoGenerico ;
  m_ixDStoreDefault:integer;
end;

implementation

end.
