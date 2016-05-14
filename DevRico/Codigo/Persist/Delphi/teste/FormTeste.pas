unit FormTeste;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls,TypInfo;

type
  TForm1 = class(TForm)
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    pInfo: PPropInfo;
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

uses Colecao;

{$R *.DFM}

procedure TForm1.Button1Click(Sender: TObject);
begin
  pInfo := GetPropInfo( Carro , 'letra' );
  //if pInfo <> nil then
  //begin
  //  Write('pInfo.Name=');
  //  Writeln(pInfo^.Name);
end;

end.
