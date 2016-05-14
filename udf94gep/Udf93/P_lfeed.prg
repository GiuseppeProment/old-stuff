// Funcao p/ Saltar Linha
FUNCTION P_LFEED
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif

    Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(10)
	EndCase
	RETURN(sCodigo)
	
// ***
// ***

