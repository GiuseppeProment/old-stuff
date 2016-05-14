program Console;

{$APPTYPE CONSOLE}

(* Teste de Pascal *)

uses Colecao;

var oPessoa:Pessoa;
begin
  Writeln('** inicio  **');
  oPessoa := Pessoa.Create();
  oPessoa.identifica;
  oPessoa.setNome('Man‚ da Silva dos Santos');
  oPessoa.Free;
end.
