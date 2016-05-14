#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  Confirma(xMsg)
  Funcao que abre um quadro (box) no centro da tela p/ confirmar
  qualquer procedimento
  xMsg - Pode ser uma String ou uma matriz
*/
FUNCTION CONFIRMA(xMsg,nLin)
	Local lRet := .t.,sCorAnt := SetColor(),lEsc := .f.,nChoice := 2
	Private aBoxMenu := {},aBoxMouse := {},nColor
	If nLin = NIL
		nLin := 13
	Endif

*  #IFDEF NAOMOUSE
*     aDisplay := {{ || DevPos(24,68),DevOut(" "+Time()+" ",ColorSet(24,68)) }}
*  #ELSE
*     aDisplay := {{ || MouseWinBox(aBoxMouse) }}
*  #ENDIF

	Aadd(aBoxMenu,MenuNew(nLin,33,"SIM",1,sCorM,,,,sCorM,.f.,{ || CallBeep(),.f. }))
	Aadd(aBoxMenu,MenuNew(nLin,44,"NAO",1,sCorM,,,,sCorM,.f.,{ || CallBeep(),.f. }))

*   aBoxMouse := MenuMouseBox(aBoxMenu)
	BoxFrame(aBoxMenu,xMsg)

	nColor := SetColor()
	SetColor(sCorM)
	MenuModal(aBoxMenu,@nChoice)
	SetColor(nColor)

	Do Case
	Case nChoice = 1 ; lRet := .t.
	Case nChoice = 2 ; lRet := .f.
	Case nChoice = 0 ; lRet := .f.
	EndCase
	BoxFrame()
	SetColor(sCorAnt)
	RETURN(lRet)

