// Funcao p/ Config Italico
FUNCTION P_ITALIC(lCondicao)
	Local sCodigo := ""
	P := Gete("P")
    If P == ""
       P := "1"
    Endif
	If lCondicao // italico
		Do Case
		Case P = "1" ; sCodigo := Chr(27)+Chr(52)
		Case P = "2" ; sCodigo := ""
		Case P = "3" ; sCodigo := Chr(27)+"4"
		EndCase
	Else
		Do Case
		Case P = "1" ; sCodigo := Chr(27)+Chr(53)
		Case P = "2" ; sCodigo := ""
		Case P = "3" ; sCodigo := Chr(27)+"5"
		EndCase
	Endif
	RETURN(sCodigo)
	
// ***
// ***

