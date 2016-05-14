// Funcao Unidirecional
FUNCTION P_UNIDIR(lCondicao)
	Local sCodigo := "",P := Gete("P")
	If lCondicao // Unidirecional
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(85)+Chr(1)
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(85)+"0"
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***

