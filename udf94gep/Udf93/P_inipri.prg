// Funcao p/ Inicializar Impressora
FUNCTION P_INIPRIN
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(64)
	EndCase
	RETURN(sCodigo)

// ***
// ***

