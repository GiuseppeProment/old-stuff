#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION MSG_LOW(sMensagem,nLin)
	Local nKey,nCount,sCorAnt := SetColor()
	If nLin = NIL
		nLin := 20
	Endif

	wOpen(wSet(nLin,01,nLin+03,78,sCorJ,pSBAR,0,5," MENSAGEM ",3,,,pSBAR))

	While (nKey := Inkey()) = 0
		SetColor(sCorM)
		Marque(sMensagem,wRow(),wCol()+01,02,02)
		If Inkey() # 0 ; Exit ; Endif
		Marque("Pressione Qualquer Tecla para Retornar",wRow()+01,wCol()+01,02,02)
		For nCount := 1 to 3000
			If (nKey := Inkey()) # 0 ; Exit ; Endif
		Next
		If nKey # 0 ; Exit ; Endif
		SetColor(sCorF)
		wClear()
	End
	SetColor(sCorAnt)
	Clear TypeaHead
	wClose()
	VOID

