Function SayLocaliz( cCodigo )  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "B"; cRet := "REAL    "
		Case cCodigo == "C"; cRet := "ESTIMADA"
		Case cCodigo == "D"; cRet := "DEBITO CONTA"
		OtherWise          ; cRet := "* Erro *"
	EndCase
	Return cRet

