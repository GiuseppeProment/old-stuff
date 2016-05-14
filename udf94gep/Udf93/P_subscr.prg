// Funcao Subscrito
FUNCTION P_SUBSCRIP(lCondicao)
	Local sCodigo := "",P := Gete("P")
	If lCondicao // subscrito
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(83)+"1"
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(84)
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***

