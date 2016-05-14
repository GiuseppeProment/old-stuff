// Calcula o numero real de linhas de TBROWSE apos uma atualizacao
FUNCTION DBPOSITION(nUltimo,bFilter)
	Local nPos := 0
	If bFilter = NIL
		bFilter := { || .t. }
	Endif

	DbGoTop()
	While ! Eof()
		If eVal(bFilter)
			nPos++
		Endif
		If Recn() == nUltimo
			Exit
		Endif
		DbSkip()
	End
	RETURN(nPos)

// **

