program Console;

{$APPTYPE CONSOLE}

(* Teste de Pascal *)

uses Colecao,TypInfo;


//var oPessoa:Pessoa;
//var theColecao:IColecao;
var theCarro:Carro;
//var x:integer;
//var pt:Pointer;
var ptInt: PInteger;
var pinfo:PPropInfo;
begin
{
  Writeln('** Inicio **');
  theColecao := IColecao.Create( Pessoa );
  // criar 1 pessoa
  oPessoa := theColecao.getObjeto as Pessoa;
  oPessoa.identifica;
  Writeln('-- setando nome --');
  oPessoa.setNome('Man‚ da Silva dos Santos');
  oPessoa.identifica;
  Writeln('---');
  theColecao.Free;
  oPessoa.Free;
  Writeln('** Fim    **');
  oPessoa := Pessoa.Create();
  oPessoa.identifica;
  oPessoa.Free;

  theCarro := Carro.Create;
  Write('SizeOf(theCarro)=');Writeln( SizeOf( @theCarro ) );
  Write('SizeOf(Carro)   =');Writeln( SizeOf( Carro ) );
  Write('SizeOf(integer) =');Writeln( SizeOf( integer ) );
  Write('SizeOf(char)    =');Writeln( SizeOf( char ) );
  Write('SizeOf(^char)    =');Writeln( SizeOf( pChar ) );

  pt := theCarro.FieldAddress('km') ;
  if pt = nil then
  begin
    Writeln('*** pt ‚ nulo ***');
  end;
  Write('pt=');Writeln(integer(pt));
  x := integer(pt);
  Write('Address(Carro.letra)=');Writeln(  x );

  theCarro.letra := 'G';
  Write('Carro.letra=');Writeln(  theCarro.letra );

  theCarro.Free;
  }

  { GetPropInfo(AClass: TClass; const PropName: string; AKinds: TTypeKinds = []): PPropInfo; }
  {
  PPropInfo = ^TPropInfo;
  TPropInfo = packed record
    PropType: PPTypeInfo;
    GetProc: Pointer;
    SetProc: Pointer;
    StoredProc: Pointer;
    Index: Integer;
    Default: Longint;
    NameIndex: SmallInt;
    Name: ShortString;
  end;}
  pInfo := GetPropInfo( Carro , 'letra' );
  if pInfo <> nil then
  begin
    Write('pInfo.Name=');
    Writeln(pInfo^.Name);
    Write('pInfo.PropType^^.Name=');
    Writeln(pInfo.PropType^^.Name);
  end;
  { estrutura da classe
  4 bytes --> deve ser o this
  dado1
  dado2
  dado3
  }
  theCarro := Carro.Create;
  theCarro.ano := 1997; // marcardor de fim p/ ver se nao deu merda

  (* palavra de maquina ‚ sempre o integer (pelo menos em c++) *)
  Writeln('** teste com (acesso direto a objeto) **');
  (* pega ponteiro generico para theCarro *)
  ptInt := PInteger(Pointer(theCarro));
  (* avanca 1 palavra de maquina para inicio dos dados  *)
  (* e mais 1 palavra para o agregado-id da classe IPersistente *)
  {obrigatorio cast p/ integer pois nao existe artimetica de ponteiros em pascal }
  ptInt := PInteger( integer(ptInt) + (2*SizeOf(integer)) );
  (* 1. dado ‚ dado:integer *)
  ptInt^ := 20;
  Write('dado=');Writeln( ptInt^ );
  Write('theCarro.dado=');Writeln( theCarro.dado );
  (* avanca sizeof(tipo_membro_anterior) *)
  ptInt := PInteger( integer(ptInt) + SizeOf(integer) );
  (* 2. dado ‚ nome:string *)
  PString(Pointer(ptInt))^ := 'Giuseppe Enrico';
  Write('nome=');Writeln( PString(Pointer(ptInt))^ );
  Write('theCarro.nome=');Writeln( theCarro.nome );
  (* avanca sizeof(tipo_membro_anterior) *)
  ptInt := PInteger( integer(ptInt) + SizeOf(string) );
  (* 3. dado ‚ peso:real *)
  PReal(Pointer(ptInt))^ := 53.60;
  Write('peso=');Writeln( PReal(Pointer(ptInt))^ );
  Write('theCarro.peso=');Writeln( theCarro.peso );
  (* avanca sizeof(tipo_membro_anterior) *)
  ptInt := PInteger( integer(ptInt) + SizeOf(real) );
  (* 4. dado ‚ altura:currency *)
  PCurrency(Pointer(ptInt))^ := 1.73;
  Write('altura=');Writeln( PCurrency(Pointer(ptInt))^ );
  Write('theCarro.altura=');Writeln( theCarro.altura );
  (* avanca sizeof(tipo_membro_anterior) *)
  ptInt := PInteger( integer(ptInt) + SizeOf(currency) );
  (* 5. dado ‚ ano:integer *)
  Write('ano=');Writeln( PInteger(Pointer(ptInt))^ );
  Write('theCarro.ano=');Writeln( theCarro.ano );

  theCarro.nome := theCarro.nome+' & Carmen Maria';
  Writeln( theCarro.nome );

  theCarro.Free;
end.
