#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION CLSTELA(sCorTela)
	Local sCorAnt := SetColor(sCorTela)
	Scroll(01,01,23,78,0)
	SetColor(sCorAnt)
	RETURN NIL

