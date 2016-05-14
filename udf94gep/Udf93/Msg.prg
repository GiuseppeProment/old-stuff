#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  Msg(xMsg)
  Funcao que abre um quadro (box) no centro da tela p/ exibir
  qualquer mensagem e espera teclar ENTER
  xMsg - Pode ser uma String ou uma matriz
*/
FUNCTION MSG(xMsg,nLin)
	Local lRet := .t.,sCorAnt := SetColor(),lEsc := .f.,nChoice := 1
	Private aBoxMenu := {},aBoxMouse := {},nColor
	If nLin = NIL
		nLin := 13
	Endif

*  #IFDEF NAOMOUSE
*     aDisplay := {{ || DevPos(24,68),DevOut(" "+Time()+" ",ColorSet(24,68)) }}
*  #ELSE
*     aDisplay := {{ || MouseWinBox(aBoxMouse) }}
*  #ENDIF

    Aadd(aBoxMenu,MenuNew(nLin,40,"OK",1,sCorM,,,,sCorM,.f.,{ || CallBeep(),.f. }))

*   aBoxMouse := MenuMouseBox(aBoxMenu)

	BoxFrame(aBoxMenu,xMsg)

	MenuModal(aBoxMenu,@nChoice)
	Do Case
	Case nChoice = 1 ; lRet := .t.
	Case nChoice = 0 ; lRet := .f.
	EndCase
	BoxFrame()
	SetColor(sCorAnt)
	RETURN(lRet)

