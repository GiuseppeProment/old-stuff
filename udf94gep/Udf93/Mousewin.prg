#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  MouseWindow(aMouse)
  Funcao que verifica se o mouse se encontra dentro da janela do menu,
  verifica se o botao do mouse foi acionado e chama a funcao (ENTRYWINDOW),
  caso as condicoes sejam satisfeitas
*/
FUNCTION MOUSEWINDOW(aMouse)
	Local aFrame := CoordsFrame(),sTime := Time()
/*
	MouseCShow()
	While NextKey() == 0
		// Regiao do Window
		If MouseBon(2) = 4
			If MouseInRegion(aFrame[1],aFrame[2],aFrame[3],aFrame[4])
				EntryWindow(aMouse)
			Else
				If MouseInRegion(aFrame[1]-01,aFrame[2]-01,aFrame[3]+01,aFrame[4]+01)
					KeyBoard(Chr(pESC))
				Endif
			Endif
		Endif
		If MouseBOn(0) = 1
			KeyBoard(Chr(pESC)+Chr(pLEFT_ARROW)+Chr(pENTER))
		Endif
		If MouseBOn(1) = 2
			KeyBoard(Chr(pESC)+Chr(pRIGHT_ARROW)+Chr(pENTER))
		Endif
		If sTime # Time()
			DevPos(24,69) ; DevOut(sTime := Time(),ColorSet(24,69))
		Endif
	End
	MouseCHide()
*/
	RETURN("")

// ***
// ***
