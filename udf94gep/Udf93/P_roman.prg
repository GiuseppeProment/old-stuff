// Funcao P/ Romano
FUNCTION P_ROMAN(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
    If lCondicao // Roman
		Do Case
		Case P = "1" ; sCodigo := Chr(27)+Chr(107)+"0"
		Case P = "2" ; sCodigo := ""
		Case P = "3" ; sCodigo := Chr(27)+Chr(71)
		EndCase
	Else
		Do Case
		Case P = "1" ; sCodigo := Chr(27)+Chr(107)+"0"
		Case P = "2" ; sCodigo := ""
		Case P = "3" ; sCodigo := Chr(27)+Chr(72)
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***
