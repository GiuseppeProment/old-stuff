// Funcao p/ Avancar N/216 Polegadas Verticalmente
FUNCTION P_AVANCEN_216(N)
	Local sCodigo := "", P := Gete("P")
    If P == ""
       P := "1"
    Endif

    Do Case
	Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(74)+Chr(N)
	EndCase
	RETURN(sCodigo)

// ***
// ***

