program Rico;

{$APPTYPE CONSOLE}

type
  CorPrimaria = (vermelho,verde,azul);
var
  Cor:CorPrimaria;
 begin
  Cor := verde;
  if Cor in [verde,vermelho] then
  begin
    writeln('Cor is Verde');
  end;
end.

