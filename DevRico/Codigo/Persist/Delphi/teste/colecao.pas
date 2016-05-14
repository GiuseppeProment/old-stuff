unit Colecao;

{$M+}

interface

uses SysUtils;


Type PInteger = ^integer;
     PString = ^string;
     PReal = ^real;
     PCurrency = ^currency;

Type
{ Classe IPersistID }
  IPersistID = class(TObject)
  public
    RAP:byte;
    CRAE:byte;
    chave:string[16];
  end;


{ IPersistente class }
  IPersistente = class(TObject)
  public
    Id:IPersistID;
    constructor Create; virtual;
    destructor Destroy; override; { chamar inherited }
    function Identifica: string;virtual;
  end;

{ Carro class }
  Carro = class(IPersistente)
  public
    dado:integer;
    nome:string;
    peso:real;
    altura:currency;
    ano:integer;
    km:integer;
  end;

  PCarro = ^Carro;

  CarroClass = class of Carro;


{ Pessoa class }
  Pessoa = class(IPersistente)
  public
    fNome:string;
    constructor Create; override;
    destructor Destroy; override; { chamar inherited }
    function Identifica: string;override;
    procedure setNome( nome:string );
  end;

{MetaClasse de IPersistente}

  IPersistenteClass = class of IPersistente;

{ IColecao class }

  IColecao = class(TObject)
  public
    FItemClass: IPersistenteClass;
    constructor Create(ItemClass: IPersistenteClass);
    destructor Destroy; override;
    function getObjeto: IPersistente;
    procedure teste;
  end;

procedure copiaOuReferencia( var UmCarro:Carro );
procedure testePar1( var valor:integer);


implementation

{ IPersistente class }

constructor IPersistente.Create;
begin
  inherited Create;
  Writeln('IPersistente.Create');
end;
destructor IPersistente.Destroy;
begin
  Writeln('IPersistente.Destroy');
  inherited Destroy;
end;
function IPersistente.Identifica: string;
begin
  Writeln('IPersistente.Identifica');
end;

{ Pessoa class }
constructor Pessoa.Create;
begin
  inherited Create;
  Writeln('Pessoa.Create');
  fNome := 'Giuseppe Enrico Proment Jr.';
end;
destructor Pessoa.Destroy; { chamar inherited }
begin
  Writeln('Pessoa.Destroy');
  inherited Destroy;
end;
function Pessoa.Identifica: string;
begin
  Write('Pessoa.Identifica =');
  Writeln(fNome);
end;
procedure Pessoa.setNome( nome:string );
begin
  fNome := nome;
end;

{ IColecao class }
constructor IColecao.Create(ItemClass: IPersistenteClass);
begin
  Writeln('IColecao.Create');
  FItemClass := ItemClass;
end;
destructor IColecao.Destroy;
begin
  Writeln('IColecao.Destroy');
  inherited Destroy;
end;
function IColecao.getObjeto: IPersistente;
begin
  Result := FItemClass.Create();
end;
procedure IColecao.teste;
var pObj:IPersistente;
begin
  pObj := FItemClass.Create();
  Write('IColecao.teste=');
  Writeln(pObj.Identifica);
  pObj.Free;
end;
procedure testePar1( var valor:integer );
begin
  valor := 999;
end;
procedure copiaOuReferencia( var UmCarro:Carro );
begin
  write('nomein+');writeln(UmCarro.nome);
  UmCarro.nome := 'nome modificado';
  write('nomein-');writeln(UmCarro.nome);
end;
end.

