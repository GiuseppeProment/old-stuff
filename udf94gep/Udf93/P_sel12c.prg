
// Funcao 12 Caracteres p/ Polegada
FUNCTION P_SEL12CPI
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	Do Case
	Case P = "1" ; sCodigo := Chr(27)+Chr(77)
	Case P = "2" ; sCodigo := Chr(30)+"5"
	Case P = "3" ; sCodigo := Chr(30)+"5"
	EndCase
	RETURN(sCodigo)

// ***
// ***

