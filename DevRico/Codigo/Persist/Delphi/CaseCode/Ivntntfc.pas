unit IEventoNotificacaoUnit;

interface

uses IUtil,Enums,INtfcdor;

Type

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

  IObservador = interface
      procedure quandoEventoNotificacao(evento:IEventoNotificacao);
  end;

Implementation

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
