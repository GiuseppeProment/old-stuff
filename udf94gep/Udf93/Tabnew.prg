#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION TABNEW( nTopRow, nTopColumn, nBottomRow, cColorString, nInitPosition )
	// Cria novo marcador de scroll
	Local aTab := Array( TB_ELEMENTS )
	aTab[ TB_ROWTOP ]    := nTopRow
	aTab[ TB_COLTOP ]    := nTopColumn
	aTab[ TB_ROWBOTTOM ] := nBottomRow
	aTab[ TB_COLBOTTOM ] := nTopColumn
	// Cor padrao e preto e branco, exceto se indicarem outra coisa
	If cColorString == NIL
		cColorString := "W/N"
	Endif
	aTab[ TB_COLOR ]  := cColorString
	// Estabelece Posicao Inicial
	If nInitPosition == NIL
		nInitPosition := 1
	Endif
	aTab[ TB_POSITION ]  := nInitPosition
	RETURN(aTab)

// **

