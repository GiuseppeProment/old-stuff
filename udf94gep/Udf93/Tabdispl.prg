#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION TABDISPLAY( aTab )
	Local cOldColor, nRow
	cOldColor := SetColor(RevColor(SetColor()))
	DispBegin()
	SetPos(aTab[ TB_ROWTOP ]   ,aTab[ TB_COLTOP ]    ) ; DispOut(TB_UPARROW)
	SetPos(aTab[ TB_ROWBOTTOM ],aTab[ TB_COLBOTTOM ] ) ; DispOut(TB_DNARROW)
	SetColor( aTab[ TB_COLOR ] )
	
	// Desenha o Background
	For nRow := (aTab[ TB_ROWTOP ] + 1) to (aTab[ TB_ROWBOTTOM ] - 1)
		SetPos(nRow, aTab[ TB_COLTOP ]) ; DispOut(TB_BACKGROUND)
	Next
	DispEnd()
	SetColor( cOldColor )
	RETURN(aTab)

// **

