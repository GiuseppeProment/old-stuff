// Funcao Superescrito
FUNCTION P_SUPERESC(lCondicao)
	Local sCodigo := "",P := Gete("P")
	If lCondicao // Superescrito
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(83)+"0"
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(84)
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***
