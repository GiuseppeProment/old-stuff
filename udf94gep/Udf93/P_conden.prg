// ***
// ***

// Funcao p/ Condensar
FUNCTION P_CONDENS(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
    If lCondicao      // Condensar
		Do Case
		Case P = "1" .or. P = "3" .or. P = "2" ; sCodigo := Chr(15)
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "3" .or. P = "2" ; sCodigo := Chr(18)
		EndCase
	Endif
	RETURN(sCodigo)
	
// ***
// ***

