// Funcao p/ Espacamento de N/72  Polegada Entre Linhas
FUNCTION P_SELN_72(N)
	Local sCodigo := "", P := Gete("P")
	Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(65)+Chr(N)
	EndCase
	RETURN(sCodigo)

// ***
// ***

