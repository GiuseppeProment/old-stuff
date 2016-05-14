unit ScktSvc;

interface

uses
  Windows, Messages, SvcMgr, Classes, ScktComp;

type
  TSocketService = class(TService)
    procedure SocketServiceStop(Sender: TService; var Stopped: Boolean);
    procedure SocketServiceStart(Sender: TService; var Started: Boolean);
    procedure SocketServiceCreate(Sender: TObject);
    procedure SocketServiceDestroy(Sender: TObject);
  public
    function GetServiceController: PServiceController; override;
    function Hook(var Message: TMessage): Boolean;
  end;

var
  SocketService: TSocketService;

implementation

{$R *.DFM}

uses
  MSrvr, ScktMain, SysUtils, Forms;

procedure ServiceController(CtrlCode: DWord); stdcall;
begin
  SocketService.Controller(CtrlCode);
end;

function TSocketService.Hook(var Message: TMessage): Boolean;
begin
  Result := Message.Msg = WM_ENDSESSION;
end;

function TSocketService.GetServiceController: PServiceController;
begin
  Result := @ServiceController;
end;

procedure TSocketService.SocketServiceStart(Sender: TService;
  var Started: Boolean);
begin
  SocketForm.Initialize(True);
  Started := True;
end;

procedure TSocketService.SocketServiceStop(Sender: TService;
  var Stopped: Boolean);
begin
  SocketForm.Free;
  Stopped := True;
end;

procedure TSocketService.SocketServiceCreate(Sender: TObject);
begin
  Forms.Application.HookMainWindow(Hook);
end;

procedure TSocketService.SocketServiceDestroy(Sender: TObject);
begin
  Forms.Application.UnhookMainWindow(Hook);
end;

end.
