Function SayFretPgto(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "S"; cRet := "Segue pedido"
		Case cCodigo == "A"; cRet := "A vista     "
        Case cCodigo == "E"; cRet := "C/Entrega   "
        Case cCodigo == "I"; cRet := "Incluso     "
        Case cCodigo == "C"; cRet := "A Combinar  "
        OtherWise          ; cRet := "            "
	EndCase
	Return cRet

