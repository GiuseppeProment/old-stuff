program Console;

uses colecao;

{$APPTYPE CONSOLE}

(* Teste de Pascal *)

begin
Write('Pointer    =');Writeln(SizeOf(Pointer    ));
Write('Integer    =');Writeln(SizeOf(Integer    ));
Write('Cardinal   =');Writeln(SizeOf(Cardinal   ));
Write('Shortint   =');Writeln(SizeOf(Shortint   ));
Write('Smallint   =');Writeln(SizeOf(Smallint   ));
Write('Longint    =');Writeln(SizeOf(Longint    ));
Write('Int64      =');Writeln(SizeOf(Int64      ));
Write('Byte       =');Writeln(SizeOf(Byte       ));
Write('Word       =');Writeln(SizeOf(Word       ));
Write('Longword   =');Writeln(SizeOf(Longword   ));
Write('AnsiChar   =');Writeln(SizeOf(AnsiChar   ));
Write('WideChar   =');Writeln(SizeOf(WideChar   ));
Write('Char       =');Writeln(SizeOf(Char       ));
Write('Boolean    =');Writeln(SizeOf(Boolean    ));
Write('Real48     =');Writeln(SizeOf(Real48     ));
Write('Single     =');Writeln(SizeOf(Single     ));
Write('Double     =');Writeln(SizeOf(Double     ));
Write('Extended   =');Writeln(SizeOf(Extended   ));
Write('Comp       =');Writeln(SizeOf(Comp       ));
Write('Currency   =');Writeln(SizeOf(Currency   ));
Write('Real       =');Writeln(SizeOf(Real       ));
Write('ShortString=');Writeln(SizeOf(ShortString));
Write('AnsiString =');Writeln(SizeOf(AnsiString ));
Write('WideString =');Writeln(SizeOf(WideString ));
Write('string     =');Writeln(SizeOf(string     ));
Write('Carro      =');Writeln(SizeOf(Carro(nil)    ));
Write('IPersistent=');Writeln(SizeOf(IPersistente(nil)));
Write('IColecao   =');Writeln(SizeOf(IColecao(nil)));
end.
