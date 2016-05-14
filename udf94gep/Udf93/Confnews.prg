#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

//Funcao p/ Confirmacao de operacao pelo usuario
FUNCTION CONFIRMA_NEWS(xMsg)
	Local lRet := .t.,sCorAnt := SetColor(),lEsc := .f.,nChoice := 2
	Private aBoxMenu := {},aBoxMouse := {},nColor

*  #IFDEF NAOMOUSE
*     aDisplay := {{ || DevPos(24,68),DevOut(" "+Time()+" ",ColorSet(24,68)) }}
*  #ELSE
*     aDisplay := {{ || MouseWinBox(aBoxMouse) }}
*  #ENDIF

	PushScreen()
	@ 22,00 Say 'Ç'+Replicate("Ä",78)+'¶' Color sCorJ
	SetColor(sCorF) ; Scroll(23,01,23,78,0) ; SetColor(sCorJ)
	Aadd(aBoxMenu,MenuNew(23,((80-Len(xMsg))/2)+20,"SIM",1,sCorM,,,,sCorM,.f.,{ || CallBeep(),.f. }))
	Aadd(aBoxMenu,MenuNew(23,((80-Len(xMsg))/2)+25,"NAO",1,sCorM,,,,sCorM,.f.,{ || CallBeep(),.f. }))
	@ 23,(((80-Len(xMsg))/2)-6) Say xMsg Color sCorL
	MenuModal(aBoxMenu,@nChoice)
	Do Case
	Case nChoice = 1 ; lRet := .t.
	Case nChoice = 2 ; lRet := .f.
	Case nChoice = 0 ; lRet := .f.
	EndCase
	PopScreen()
	SetColor(sCorAnt)
	RETURN(lRet)

