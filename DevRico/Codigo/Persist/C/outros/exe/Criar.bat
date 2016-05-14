@ECHO OFF
rem criar tabelas
s "create table pessoa ( ID number, nome char(30), idade number)"
s "create table endereco ( ID number, rua char(30), numero number)"
s "create table relacao ( AgregandoID number, AgregadoID number )"

