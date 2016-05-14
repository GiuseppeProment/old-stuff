// Funcao p/ Sublinhar
FUNCTION P_SUBLIN(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	If lCondicao // sublinhar
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+"-"+Chr(1)
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+"-"+"0"
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***

