@ECHO OFF
rem criar indices
s "create index chaveID on pessoa ( ID )"
s "create index chaveID on endereco ( ID )"
s "create index chaveID on relacao ( AgregandoID )"

