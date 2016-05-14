// Funcao p/ Carta
FUNCTION P_NEARLETTER(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	If lCondicao
		Do Case
		Case P="1" ; sCodigo := Chr(27)+Chr(120)+Chr(1)
		Case P="2" ; sCodigo := Chr(27)+Chr(71)
		Case P="3" ; sCodigo := Chr(27)+Chr(71)
		EndCase
	Else
		Do Case
		Case P="1" ; sCodigo := Chr(27)+Chr(120)+"0"
		Case P="2" ; sCodigo := Chr(27)+Chr(72)
		Case P="3" ; sCodigo := Chr(27)+Chr(72)
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***

