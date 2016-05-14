// Funcao Dupla Altura
FUNCTION P_DOUBHIG(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif

    If lCondicao // Dupla Altura
		Do Case
		Case P="1" ; sCodigo := Chr(27)+Chr(119)+"1"
		Case P="2" ; sCodigo := ""
		Case P="3" ; sCodigo := ""
		EndCase
	Else
		Do Case
		Case P="1" ; sCodigo := Chr(27)+Chr(119)+"0"
		Case P="2" ; sCodigo := ""
		Case P="3" ; sCodigo := ""
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***
