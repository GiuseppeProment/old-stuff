@ECHO OFF
rem criar tabelas
sqlOra "create table Cadastro (ID char(5),numero number,endereco varchar2(20),nome varchar2(40),pesso number(5,2)  )"
