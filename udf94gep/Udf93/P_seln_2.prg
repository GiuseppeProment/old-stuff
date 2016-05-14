// Funcao p/ Espacamento de N/216 Polegada Entre Linhas
FUNCTION P_SELN_216(N)
	Local sCodigo := "",P := Gete("P")
	Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(51)+Chr(n)
	EndCase
	RETURN(sCodigo)

// ***
// ***

