#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

//

FUNCTION TELA_PADRAO
	Local nCur := SetCursor(0),sCorAnt:=SetColor()
	PushFrame(00,00,24,79,pDBAR,sCorF) // Para Uso do Mouse
	DispBox(00,00,24,79,pDBAR,sCorJ)
	Scroll(01,01,23,78,0)  // Limpa o Fundo
	@ 02,00 Say 'Ç'+Replicate("Ä",78)+'¶' Color sCorJ
	Titulo(" ¯ Menu Principal")
	SetColor(RevColor(sCorJ))
	//SetPos(00,00) ; DispOut('[ ]')
	DevPos(24,02) ; DevOut(dExtenso(),sCorT)
*  DevPos(24,68) ; DevOut(" "+Time()+" ",sCorT)
	SetCursor(nCur)
	SetColor(sCorAnt)
	VOID

// ***
// ***

