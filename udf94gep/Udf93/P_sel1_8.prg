// Funcao p/ Espacamento de 1/8 Polegada Entre Linhas
FUNCTION P_SEL1_8
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(48)
	EndCase
	RETURN(sCodigo)

// ***
// ***

