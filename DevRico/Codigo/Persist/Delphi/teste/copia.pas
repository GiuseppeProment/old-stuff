program CopiaRef;

{$APPTYPE CONSOLE}

uses Colecao;

var
  UmCarro:Carro;
  nDado:integer;
begin
  UmCarro := Carro.Create;
  UmCarro.nome := 'Palio';
  copiaOuReferencia( UmCarro );
  write('nome do carro=');writeln(UmCarro.nome);
  nDado := 100;
  testePar1( nDado );
  write('nDado=');writeln(nDado);
  UmCarro.Free;
end.

