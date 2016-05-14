// Funcao p/ Espacamento de 1/6 Polegada Entre Linhas
FUNCTION p_sel1_6
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(50)
	EndCase
	RETURN(sCodigo)

// ***
// ***

