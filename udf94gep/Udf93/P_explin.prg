// Funcao P/ Expancao de uma Linha
FUNCTION P_EXPLIN(lCondicao)
	Local sCodigo := "",P := Gete("P")
    If P == ""
       P := "1"
    Endif
	If lCondicao       // Expandir
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(14)
		EndCase
	Else
		Do Case
		Case P = "1" .or. P = "2" .or. P = "3" ; sCodigo := Chr(20)
		EndCase
	Endif
	RETURN(sCodigo)
	
// ***
// ***

