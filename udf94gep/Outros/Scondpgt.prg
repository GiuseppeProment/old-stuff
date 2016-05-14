Function SayCondPgto(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "A"; cRet := "A Vista  "
		Case cCodigo == "P"; cRet := "Parcelada"
        Case cCodigo == "E"; cRet := "Excessao "
        Case cCodigo == "C"; cRet := "A Combinar"
        OtherWise          ; cRet := "         "
	EndCase
	Return cRet

Function SvSayCondPgto(cCodigo)  // devolve a correspondente descricao
    Local cRet                   // para servicos
	Do Case
        Case cCodigo == "M"; cRet := "Medi‡ao  "
		Case cCodigo == "P"; cRet := "Parcelada"
        Case cCodigo == "C"; cRet := "A Combinar"
        OtherWise          ; cRet := "         "
	EndCase
	Return cRet

