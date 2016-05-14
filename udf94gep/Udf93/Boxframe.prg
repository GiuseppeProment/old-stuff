#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  BoxFrame(aList,xMsg)
  Esta funcao cria um janela de acordo com as coordenadas contidas nos
  seguintes parametros
  aList -  Matriz que contem todas as informacoes do menu
  xMsg - String ou Matriz com as mensagens
  sTitulo - Titulo da Janela
*/
FUNCTION BOXFRAME(aList,xMsg,sTitulo)
	Local nLinTop,nColTop,nLinBottom,nColBottom,nTamBox
	Local nRed := 0,nInc := 2,nMaior:= 0,nColBox,nColTopX,nColBotX
	If sTitulo = NIL
		sTitulo := ""
	Endif

	Do Case
	Case ValType(xMsg) == "A"
		If ! AAllNil(xMsg) .and. ! AAllEmpty(xMsg)
			nRed := Len(xMsg) + 05
		Endif
		nMaior := 0
		aEval(xMsg,{ |aArray| nMaior := If(nMaior < Len(aArray),Len(aArray),nMaior) } )
	Case ValType(xMsg) == "C"
		nRed   := 6
		nMaior := Len(xMsg)
	EndCase

	If aList <> NIL
		nLinTop    := aList[1][1] - nRed
		nColTop    := ((80 - nMaior) / 2) - 01
		nLinBottom := aList[Len(aList)][1] + 02
		nColBottom := nColTop + nMaior + 02
		nTamBox    := nColBottom - nColTop
		nColBottom++ // Uma Coluna em Branco entre as mensagens

		nColTopX := aList[1][2] - 4
		nColBotX := aList[Len(aList)][2] + Len(aList[Len(aList)][3]) + 4

		If nColTop > nColTopX
			nColTop := nColTopX
		Endif

		If nColBottom < nColBotX
			nColBottom := nColBotX
		Endif

		// Montar Janela
*     PushFrame(nLinTop, nColTop, nLinBottom, nColBottom, pSBAR, sCorJ)
		PushFrame(nLinTop, nColTop, nLinBottom, nColBottom, pSBAR, sCorM)
		//@ nLinTop,nColTop Say '[ ]' Color RevColor(sCorJ)

		If ! Empty(nRed)
			If ValType(xMsg) = "A" // Array
				aEval(xMsg ,{ |aTxt| ;
								SetPos(nLinTop + nInc, nColTop+2),;
								DevOut(Equaliza(aTxt,nMaior),sCorM), nInc++ })
				nInc++
			Else
				// Character
				DevPos(nLinTop + nInc, nColTop+2)
				DevOut(Equaliza(xMsg,nMaior),sCorM)
				nInc += 2
			Endif
*        DispBox(nLinTop+nInc,nColTop,nLinTop+nInc,nColBottom,pDBAR,sCorJ)
			DispBox(nLinTop+nInc,nColTop,nLinTop+nInc,nColBottom,pDBAR,sCorM)
			DevPos(nLinTop+nInc,nColTop)    ; DevOut(Chr(198),sCorM)
			DevPos(nLinTop+nInc,nColBottom) ; DevOut(Chr(181),sCorM)
		Endif
		sCorAnt := SetColor(sCorT)
		Centra(nLinTop,nColTop+04,nColTop+nTamBox,sTitulo)
		SetColor(sCorAnt)
	Else
		PopFrame()
	Endif
	RETURN NIL

