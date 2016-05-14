#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION MENSINFO(sMensagem,nLin)
	Local nKey,nCount,sCorAnt := SetColor()
	If nLin = NIL
		nLin := 21
	Endif

	wOpen(wSet(nLin,01,nLin+03,78,sCorM,pSBAR,0,5," MENSAGEM ",3,,,pSBAR))

	SetColor(sCorM)
	@ wRow()  ,wCol()+1 Say sMensagem
	@ wRow()+1,WCol()+1 Say "Pressione Qualquer Tecla para Continuar"
	SetColor(sCorF);Inkey(0);wClear()
	SetColor(sCorAnt)
	Clear TypeaHead
	wClose()
	VOID



// ***
// ***
