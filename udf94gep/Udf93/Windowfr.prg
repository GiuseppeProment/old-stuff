#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  Esta funcao cria um janela de acordo com as coordenadas contidas nos
  seguintes parametros
  aList -  Matriz que contem todas as informacoes do menu
  sTitulo - Titulo da Janela
*/
FUNCTION WINDOWFRAME( aList,sTitulo)
	Local nLinTop,nColTop,nLinBottom,nColBottom,nTamWin,sCorAnt

	If aList <> NIL
		nLinTop    := aList[1,1] - 1
		nColTop    := aList[1,2] - 1
		nLinBottom := Len(aList)+1+nLinTop
		nColBottom := nColTop+Len(aList[1,3])+1
		nTamWin    := nColBottom - nColTop
		PushFrame(nLinTop,nColTop,nLinBottom,nColBottom,pSBAR,sCorJ)
		If sTitulo # NIL
			sCorAnt := SetColor(sCorT)
			Centra(nLinTop,nColTop,nColTop+nTamWin,sTitulo)
			SetColor(sCorAnt)
		Endif
	Else
		PopFrame()
	Endif
	RETURN NIL

// ***
// ***
