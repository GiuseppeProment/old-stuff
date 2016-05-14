// Funcao p/ Saltar Pagina
FUNCTION P_FFEED
	Local sCodigo := "",P := Gete("P")
	Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(12)
	EndCase
	RETURN(sCodigo)

// ***
// ***
