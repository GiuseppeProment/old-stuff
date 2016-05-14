unit IPersistenteUnit;

interface

uses IUtil,Enums,IPrsstID,INtfcdor;

type
  IBroker = class;
  IEventoNotificacao = class;
  IClassMap = class;

//## Uses: delega funcoes a ; IBroker {n -> 1F}
//## Uses: mapeado por; IClassMap {n -> 1F}

const evtSalvando='IPersistente::Salvando';

type
  IPersistente = class( INotificador )
  public
      constructor Create; virtual;
      constructor Create( right:IPersistente );virtual;overload;
      destructor Destroy;override;
      procedure save;
      procedure erase;
      function getNomeClasse:string; virtual;
      procedure OnClassInfo;virtual;
      function ID:IPersistID ;
      procedure setID(const value:IPersistID );
      function isPersistido:bool ;
      procedure setisPersistido(const value:bool );
  protected
      function registraMembro(nomeMembro:string; offSet:int; tamanho:int; tipoMembro:IKnowType  = IsStringFix; varSizeMax:int = 0; isProxy:bool  = false):IPersistente ;virtual;
  private
      function isProxy:bool ;
      procedure setisProxy(const value:bool );
  private  //## implementation
      m_ID:IPersistID ;
      m_isPersistido:bool ;
      m_isProxy:bool ;
end;
{ pascal nao tem friend :-( friend class IColecaoPersistenteBase; }

implementation

end.
