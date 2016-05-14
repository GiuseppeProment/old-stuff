program Teste;

{$APPTYPE CONSOLE} 

uses SysUtils,ITeste;

{ Main }
begin
	var objPtr:^Pessoa;
	Writeln('*** Inicio ***');
	{ Colecao ColecaoPessoa(&Pessoa::novoObjeto,&Pessoa::deletaObjeto); 
	Pessoa *objPessoa;
	objPessoa = (Pessoa*) ColecaoPessoa.Crie();
	cout << ((Persistente*)objPessoa)->Identifica() << endl;
	cout << objPessoa->Identifica() << endl; }
	Writeln('*** teste    ***');
	objPtr := New(^Pessoa);
	Write('identifica=');
 	Writeln(objPtr->Identifica());
	Dispose(objPtr);
	Writeln('*** Fim      ***');
end.