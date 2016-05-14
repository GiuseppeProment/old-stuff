
// Funcao p/ Enfatizar
FUNCTION P_ENFA(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif

    If lCondicao  // Enfatiza
		Do Case
		Case P = "2"              ; sCodigo := ""
		Case P = "1" .or. P = "3" ; sCodigo := Chr(27)+Chr(69)
		EndCase
	Else
		Do Case
		Case P = "2"              ; sCodigo := ""
		Case P = "1" .or. P = "3" ; sCodigo := Chr(27)+Chr(70)
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***

