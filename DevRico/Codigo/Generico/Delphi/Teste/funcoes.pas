unit Funcoes;

interface

(* {$R *.DFM} *)
uses SysUtils;

procedure imprima(msg:string);

implementation

procedure imprima(msg:string);
begin
	Writeln(msg);
end;

end.