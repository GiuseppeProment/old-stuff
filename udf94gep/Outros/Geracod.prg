#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "Recoma.ch"
#Include "PTWindow.ch"

#DEFINE EMPRESA_SERVICO "50.996.479"
#DEFINE EMPRESA_VENDA "51.212.348"

MemVar sCorJ,sCorF,sCorT,sCorL,sCorM
MemVar aPict, nTmp
FUNCTION GERACOD(sTipo) // Gera Codigos
	Local sRet
	Config->(Rec_Lock(0))
	Do Case

	Case sTipo == "CL" // Novo Codigo p/ Cliente

		Config->CfCodCli := Config->CfCodCli + 01
		sRet := Config->CfCodCli

	Case sTipo =="CLEst" //Sequencialp/ Estabeleimentos de Cliente

		Config->CfCodEst := Config->CfCodEst + 01
		sRet := Config->CfCodEst

	Case sTipo =="CLTel" //Sequencial p/No. de Telefones

		Config->CfCodTel := Config->CfCodTel + 01
		sRet := Config->CfCodTel

	Case sTipo == "IE" // Novo Codigo p/ Indice Economico

		Config->CfIndeCon := Config->CfIndeCon + 01
		sRet := Config->CfIndeCon

	Case sTipo == "FN" // Novo Codigo p/ Fornecedor

		Config->CfCodFor := Config->CfCodFor + 01
		sRet := Config->CfCodFor

	Case sTipo == "CD" // Novo Codigo p/ Cidade

		Config->CfCodCid := Config->CfCodCid + 01
		sRet := Config->CfCodCid

	Case sTipo == "GRC" // Novo Codigo p/ Grupo de Fornecedores

		Config->CfGrcGru := Config->CfGrcGru + 01
		sRet := Config->CfGrcGru

	Case sTipo == "MM" // Novo Codigo p/ Medidas de Madeiras 

		Config->CfMmCodigo := Config->CfMmCodigo + 01
		sRet := Config->CfMmCodigo

	Case sTipo == "TM" // Novo Codigo p/ Tipos de Madeiras 

		Config->CfTmCodigo := Config->CfTmCodigo + 01
		sRet := Config->CfTmCodigo

	Case sTipo == "EQ"     //Novo Codigo p/ Item de Grupo - Estoque

		Config->CfEqCodGru := Config->CfEqCodGru + 1
		sRet := Config->CfEqCodGru

	Case sTipo == "EA"     //Novo Codigo p/ Cod. Reduzido - Estoque Anal.

		Config->CfEaReduz := Config->CfEaReduz + 1
		sRet := Config->CfEaReduz

	 Case sTipo == "CS"     //Novo Codigo p/ Comissionado

		Config->CfComissi := Config->CfComissi + 1
		sRet := Config->CfComissi

	 Case sTipo == "EF"     //Novo Codigo p/ Entidade Financeira

		Config->CfEntFina := Config->CfEntFina + 1
		sRet := Config->CfEntFina

	 Case sTipo == "SV"     //Novo Codigo p/ Codigo Serv. Venda

		Config->CfSvCodigo := Config->CfSvCodigo + 1
		sRet := Config->CfSvCodigo

	 Case sTipo == "DI"     //Novo Codigo p/ Codigo Desp. Impostos 

		Config->CfDiCodigo := Config->CfDiCodigo + 1
		sRet := Config->CfDiCodigo

	 Case sTipo == "OD"     //Novo Codigo p/ Ordem de Producao

		Config->CfOrdProd := Config->CfOrdProd + 1
		sRet := Config->CfOrdProd

	 Case sTipo == "FU"     //Novo Codigo p/ Funcionario

		Config->CfFuncion := Config->CfFuncion + 1
		sRet := Config->CfFuncion

	 Case sTipo == "OS"     //Novo Codigo p/ Ordem Servico

		Config->CfOrdServ := Config->CfOrdServ + 1
		sRet := Config->CfOrdServ

     Case sTipo == "MF"     //Novo Codigo p/ Movi. Financeira

        Config->CfMoviFin := Config->CfMoviFin + 1
        sRet := Config->CfMoviFin

	EndCase
	Config->(DbUnlock())
	RETURN(sRet)
