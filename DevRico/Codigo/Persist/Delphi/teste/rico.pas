(*�� Program ���������������������������������������������������������������Ŀ
  �  Application: Camada de Persistencia - IFrameWork(c)                     �
  �    File Name: RICO.PAS                                                   �
  �       Author: Giuseppe Enrico Proment Jr                                 �
  � Date created: 24/02/00              Date updated: �24/02/00              �
  � Time created: 18:55:02              Time updated: �18:55:02              �
  �    Copyright: (c) 2000 by Giuseppe Enrico Proment Jr.                    �
  �    Cessao de direito de uso para Universidade S�o Judas                  �
  �    E-Mail to:  gProment@sti.com.br                                 �
  ����������������������������������������������������������������������������*)
program Rico;

{$APPTYPE CONSOLE}

(* Teste de Pascal *)

uses Colecao;
(* Teste de offset *)
{

var theCarro:Carro;
var pObjeto:Pointer;
var m_offSet:Integer;
begin
  theCarro := Carro.Create;
  theCarro.ano := 1997; // marcardor de fim p/ ver se nao deu merda
  theCarro.dado := 100;

  (* palavra de maquina � sempre o integer (pelo menos em c++) *)
  Writeln('** teste com (acesso direto a objeto) **');
  (* pega referencia *)
  pObjeto := Pointer(theCarro);
  (* dado:integer *)
  m_offSet := Integer(@Carro(nil).dado);
  PInteger(Integer(pObjeto)+m_offSet)^ := 1;
  Write('theCarro.dado=');Writeln( theCarro.dado );
  (* nome:string *)
  m_offSet := Integer(@Carro(nil).nome);
  PString(Integer(pObjeto)+m_offSet)^ := 'Carmen & Giuseppe';
  Write('theCarro.nome=');Writeln( theCarro.nome );
  (* peso:real *)
  m_offSet := Integer(@Carro(nil).peso);
  PReal(Integer(pObjeto)+m_offSet)^ := 53.60;
  Write('theCarro.peso=');Writeln( theCarro.peso );
  (* altura:currency *)
  m_offSet := Integer(@Carro(nil).altura);
  PCurrency(Integer(pObjeto)+m_offSet)^ := 11000.50;
  Write('theCarro.altura=');Writeln( theCarro.altura );

  Write('theCarro.ano=');Writeln( theCarro.ano );

  theCarro.nome := theCarro.nome+' & Carmen Maria';
  Writeln( theCarro.nome );

  theCarro.Free;
end.
}

(* Teste de Meta Classe *)

var
  anColecao:IColecao;
begin
  anColecao := IColecao.Create( Pessoa ); {cria a colecao de pessoas}
  anColecao.teste;
  anColecao.Free;
end.

