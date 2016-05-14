#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  EntryWindow(aMouse)
  Funcao que verifica em qual linha esta posicionado o cursor do mouse
  e aciona a opcao respectiva atraves da HOT KEY
*/

FUNCTION ENTRYWINDOW(aMouse)
	Local aLinha := {},aChar := {},nOp
	aEval(aMouse,{ |aArray| Aadd(aLinha,aArray[1]),Aadd(aChar,aArray[2]) })
	If (nOp := aScan(aLinha,MouseRow())) # 0
		KeyBoard(aChar[nOp]+Chr(13))
	Endif
	RETURN NIL

// ***
// ***

