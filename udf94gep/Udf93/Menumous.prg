#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  MenuMouseWin(aMenu)
  Funcao que cria uma matriz com a linha e o respectivo caracter do
  menu que representa a Letra de Acesso (Hot Key)
  aMenu - Matriz que contem todas as informacoes de cada linha do menu
*/
FUNCTION MENUMOUSEWIN(aMenu)
	Local aMouse := {},nCount,nLin,sChar

	For nCount := 1 to Len(aMenu)
		nLin  := aMenu[nCount][1]
		sChar := Upper(aMenu[nCount][4])
		Aadd(aMouse,{ nLin,sChar })
	Next
	RETURN(aMouse)

// ***
// ***
