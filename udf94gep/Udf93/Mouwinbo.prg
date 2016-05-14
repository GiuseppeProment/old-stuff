#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  MouseWinBox(aMouse)
  Funcao que verifica se o mouse se encontra dentro da janela do menu,
  verifica se o botao do mouse foi acionado e executa a opcao selecionada
  caso as condicoes sejam satisfeitas
*/
FUNCTION MOUSEWINBOX(aMouse)
	Local nCount := 0,aFrame := CoordsFrame(),sTime := Time()
	While NextKey() == 0
/*
		MouseCShow()
		If MouseInRegion(aFrame[1],aFrame[2],aFrame[3],aFrame[4])
			If MouseBon(2) = 4
				For nCount := 1 to Len(aMouse)
					 If MouseInRegion(aMouse[nCount][1],aMouse[nCount][2],;
											aMouse[nCount][3],aMouse[nCount][4])
						 CallBeep()
						 KeyBoard(aMouse[nCount][5]+Chr(pENTER))
						 Exit
					 Endif
				Next
			Endif
		Endif
		// Canto da Janela
		If MouseInRegion(aFrame[1]-01,aFrame[2]-01,aFrame[1]-01,aFrame[2]+02)
			If MouseBon(2) = 4
				CallBeep()
				KeyBoard(Chr(pESC))
			Endif
		Endif
		If MouseBOn(0) = 1
			KeyBoard(Chr(pLEFT_ARROW))
		Endif
		If MouseBOn(1) = 2
			KeyBoard(Chr(pRIGHT_ARROW))
		Endif

		If sTime # Time()
			DevPos(24,69) ; DevOut(sTime := Time(),ColorSet(24,69))
		Endif
*/
	End
// MouseCHide()
	RETURN("")

// ***
// ***
