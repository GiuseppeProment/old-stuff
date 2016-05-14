#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000



FUNCTION MENUNEW(nRow, nCol, cString, nNum, cHColor, ;
					  cMessage, nMRow, nMCol, cColor, lCenter, bOperation, cRights )
	Local aArray,cItem

	// Criar a Matriz
	Default cHColor    to AColor()[2]
	Default cColor     to setcolor()
	Default nMCol      to 0
	Default cMessage   to ""
	Default bOperation to {|| pFALSE}
	Default cRights    to ""
	Default lCenter    to .f.

	If nNum == NIL   // Nao Foi Passado
		cItem := Left( Alltrim( cString ), 1 )
		nNum  := At( cItem, cString )
	Else
		cItem := SubStr( cString, nNum, 1 )
	Endif

	If lCenter // a mensagem sera centralizada
		Default nMRow to Set(pMESSAGE)
		nMCol := ( MaxCol() / 2 ) - Int( Len( cMessage ) / 2 )
	Else
		If nMRow == NIL
			DEFAULT nMRow to Set(pMESSAGE)
			nMCol := 0
		Endif
	Endif
	aArray := {nRow, nCol, cString, cItem, nNum, cHColor, cMessage,;
				  nMRow, nMCol, cColor, lCenter, bOperation, cRights}
	RETURN(aArray)

// ***
// ***
