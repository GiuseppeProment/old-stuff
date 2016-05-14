
// Funcao Dupla Largura
FUNCTION P_DOUBWID(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif

    If lCondicao // Dupla Largura
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(87)+"1"
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(27)+Chr(87)+"0"
		EndCase
	Endif
	RETURN(sCodigo)

// ***
// ***

