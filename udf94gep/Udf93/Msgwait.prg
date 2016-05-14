#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION MsgWait(cMensagem,nLin)
	Local nKey,nCount,sCorAnt := SetColor()
	If cMensagem!=Nil
		If nLin = NIL
			nLin := 21
		Endif
		wOpen(wSet(nLin,11,nLin+03,68,sCorM,pSBAR,0,5," AGUARDE ",3,,,pSBAR))
		SetColor(sCorM)
		@ wRow(),wCol(2) Say cMensagem
		SetColor(sCorAnt)
	Else
		wClose()
	Endif
	VOID


