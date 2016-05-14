unit ITeste;

interface

uses SysUtils;

Type Persistente = class(TObject)
public
	constructor Create;
	destructor Destroy;virtual;
	function Identifica: string; virtual; 
end;

Type pPersistente = ^Persistente;
	
Type Pessoa = class(Persistente)
public
	constructor Create;
	destructor Destroy;virtual;
	function Identifica: string; override; 
	class function novoObjeto:pPersistente;
	class procedure deletaObjeto(obj:pPersistente);
end;	

Type pPessoa = ^Pessoa;

implementation

constructor Persistente.Create;
begin
	inherited; 
	Writeln('Persistente.Create');	
end;
destructor Persistente.Destroy;
begin
	inherited; 
	Writeln('Persistente.Destroy');	
end;
function Persistente.Identifica: string;
begin
	Result := 'Persistente';
end;

class function Pessoa.novoObjeto:pPersistente;
	var ptr:pPessoa;
begin
	New( ptr );
	Result := ptr as pPersistente; 
end;
constructor Pessoa.Create;
begin
	inherited; 
	Writeln('Pessoa.Create');	
end;
destructor Pessoa.Destroy;
begin
	inherited; 
	Writeln('Pessoa.Destroy');	
end;
function Pessoa.Identifica: string;
begin
	Result := 'Pessoa';
end;
class procedure Pessoa.deletaObjeto(obj:pPersistente);
	var ptr:pPessoa;
begin
	Writeln('metodo destrutor');	
	ptr := (pPessoa) obj;
	Dispose( ptr ); 
end;

end.