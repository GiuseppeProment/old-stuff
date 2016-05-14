#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION TITULO(sTitulo)
	Local sCorAnt := SetColor()
	DispBegin()
	SetColor(sCorJ)
	SetPos(00,03) ; DispOut(Replicate("Í",75))
	SetColor(sCorT)
    Centra(00,03,77," U.S.J.T. ¯ Teste "+sTitulo)
	SetColor(sCorAnt)
	DispEnd()
	VOID

