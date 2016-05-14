// Funcao 10 Caracteres p/ Polegada
FUNCTION P_SEL10CPI
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif

    Do Case
	Case P = "1" ; sCodigo := Chr(27)+Chr(80)
	Case P = "2" ; sCodigo := Chr(30)+"0"
	Case P = "3" ; sCodigo := Chr(30)+"0"
	EndCase
	RETURN(sCodigo)

// ***
// ***
