#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  MenuMouseBox(aMenu,lQuadro)
  Esta Funcao tem a finalidade de criar uma matriz com as coordenadas das
  opcoes do respectivo box
  aMenu - Matriz que contem todos os dados do menu de escolha
*/
FUNCTION MENUMOUSEBOX(aMenu,lQuadro)
	Local aMouse := {},nCount,nLin1,nLin2,nCol1,nCol2,sChar
	If lQuadro == NIL
		lQuadro := .f.
	Endif
	For nCount := 1 to Len(aMenu)
		nLin1 := aMenu[nCount][1] - If(lQuadro,1,0) // Linha Top
		nLin2 := aMenu[nCount][2] - If(lQuadro,1,0) // Linha Bottom
		nCol1 := aMenu[nCount][1] + If(lQuadro,1,0) // Coluna Top
		nCol2 := aMenu[nCount][2] +;
					Len(aMenu[nCount][3]) - If(lQuadro,1,0) // Coluna Bottom

		sChar := Upper(aMenu[nCount][4]) // Caracter HOT KEY
		Aadd(aMouse,{ nLin1,nLin2,nCol1,nCol2,sChar})
	Next
	RETURN(aMouse)


// ***
// ***
