#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  Centra(nLin,nColIni,nColFim,sMsg)
  Tem a finalidade de centralizar um mensagem numa regiao da tela definida
  pelas coordenadas :
  nLin - Linha da p/ Exibir a Mensagem
  nColIni - Coluna Inicial p/ Exibir
  nColFim - Coluna Final p/ Exibir
  sMsg - Mensagem p/ exibir
*/
FUNCTION CENTRA(nLin,nColIni,nColFim,sMsg)
	Local nMais := Abs(((nColFim-nColIni) / 2) - (Len(sMsg) / 2))
	@ nLin,nMais+nColIni Say sMsg
	RETURN(NIL)

// ***
// ***
