#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION TABMODAL( aTab, ncurrent, ntotal, lforceupdate )
	Local cOldColor, nNewPosition
	Local nScrollHeight := (aTab[TB_ROWBOTTOM]-1)-(aTab[TB_ROWTOP])
	If nTotal < 1
		nTotal := 1
	Endif
	If nCurrent < 1
		nCurrent := 1
	Endif
	If nCurrent > nTotal
		nCurrent := nTotal
	Endif
	If lForceUpdate == NIL
		lForceUpdate := .f.
	Endif
	cOldColor := SetColor( aTab[ TB_COLOR ] )
	
	// Determina a Nova Posicao
	nNewPosition := Round( (nCurrent / nTotal) * nScrollHeight, 0 )
	
	// Algoritmo de Posicao
	nNewPosition := If( nNewposition < 1, 1, nNewPosition )
	nNewPosition := If( nCurrent == 1, 1, nNewPosition )
	nNewPosition := If( nCurrent >= nTotal, nScrollHeight, nNewPosition )
	
	// Sobreescreve a posicao anterior
	If nNewPosition <> aTab[ TB_POSITION ] .or. lForceUpdate
		@ (aTab[ TB_POSITION ] + aTab[ TB_ROWTOP ]), aTab[ TB_COLTOP ] Say ;
				TB_BACKGROUND
		@ (nNewPosition + aTab[ TB_ROWTOP ]), aTab[ TB_COLTOP ] Say Chr(219)
		aTab[ TB_POSITION ] := nNewPosition
	Endif
	SetColor( cOldColor )
	RETURN(aTab)

