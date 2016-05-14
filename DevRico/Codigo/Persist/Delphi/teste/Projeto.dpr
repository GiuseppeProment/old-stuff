program Projeto;

uses
  Forms,
  FormTeste in 'FormTeste.pas' {Form1},
  Colecao in 'colecao.pas';

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
