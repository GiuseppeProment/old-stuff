Function SayTipConta( cCodigo )  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "R"; cRet := "REAL    "
		Case cCodigo == "E"; cRet := "ESTIMADA"
		OtherWise          ; cRet := "* Erro *"
	EndCase
	Return cRet
