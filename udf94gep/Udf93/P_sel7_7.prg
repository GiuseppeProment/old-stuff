// Funcao p/ Espacamento de 7/72 Polegada Entre Linhas
FUNCTION P_SEL7_72
	Local sCodigo := "",P := Gete("P")
	Do Case
	Case P="1" .or. P="2" .or. P="3" ; sCodigo := Chr(27)+Chr(49)
	EndCase
	RETURN(sCodigo)

// ***
// ***

