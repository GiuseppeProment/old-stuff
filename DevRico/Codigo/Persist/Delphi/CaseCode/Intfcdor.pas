unit INotificadorUnit;

interface

uses IUtil,Enums;

const evtDefault='INotificador::Default';

type

  IEventoNotificacao = class; {declaracao forward}

  (* Interface IObservador *)
  IObservador = interface
      procedure quandoEventoNotificacao(evento:IEventoNotificacao);
  end;

  (* Classe INotificador *)
  INotificador = class
  public
      constructor Create; overload; virtual;
      constructor Create(const right:INotificador ); overload; virtual;
      destructor Destroy;override;
      function ligaNotificarObservadores:INotificador;
      function desligaNotificarObservadores:INotificador;
      function NotificarEventosPara(Observador:IObservador ):INotificador;
      function notificarObservadores( evento:IEventoNotificacao ):INotificador;
      function PararNotificarEventosPara( Observador:IObservador):INotificador;
      function nomeClasse:String ;
      procedure setnomeClasse(const value:String );
      { static TypeEvento evtDefault; }
  private  //## implementation
      m_Observadores:ListaPointer ;
      m_notificarObservadores:bool ;
      m_nomeClasse:IString ;
  end;

  (* sinonimo de ponteiro *)
  PINotificador = ^INotificador;

  (* Classe IEventoNotificacao *)
  IEventoNotificacao = class
  public
    constructor Create(notificador:INotificador;evento:TypeEvento=INotificadorUnit.evtDefault); virtual;
    destructor Destroy;override;
    function Notificador:INotificador;
    function evento:TypeEvento ;
  private  //## implementation
      m_Notificador:INotificador ;
      m_evento:TypeEvento ;
  end;


implementation


(*  INotificador *)
constructor INotificador.Create;
begin
  m_notificarObservadores := true;
  m_nomeClasse := 'INotificador';
end;

constructor INotificador.Create(const right:INotificador );
begin
  m_notificarObservadores := true;
  m_nomeClasse := 'INotificador';
end;

destructor INotificador.Destroy;
begin
  inherited Destroy;
end;

function INotificador.ligaNotificarObservadores:INotificador;
begin
  Result := Self;
end;

function INotificador.desligaNotificarObservadores:INotificador;
begin
  Result := Self;
end;

function INotificador.NotificarEventosPara(Observador:IObservador ):INotificador;
begin
  Result := Self;
end;

function INotificador.notificarObservadores( evento:IEventoNotificacao ):INotificador;
begin
  Result := Self;
end;

function INotificador.PararNotificarEventosPara( Observador:IObservador):INotificador;
begin
  Result := Self;
end;

function INotificador.nomeClasse:String ;
begin
  Result := m_nomeClasse;
end;

procedure INotificador.setnomeClasse(const value:String );
begin
  m_nomeClasse:=value;
end;

(* IEventoNotificacao *)
constructor IEventoNotificacao.Create(notificador:INotificador;evento:TypeEvento);
begin
  m_Notificador := notificador;
  m_evento := evento;
end;

destructor IEventoNotificacao.Destroy;
begin
  inherited Destroy;
end;

function IEventoNotificacao.Notificador:INotificador;
begin
  Result := m_Notificador;
end;

function IEventoNotificacao.evento:TypeEvento ;
begin
  Result := m_evento;
end;


end.
