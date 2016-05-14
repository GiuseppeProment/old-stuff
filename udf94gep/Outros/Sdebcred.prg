
Function SayDebCred( cCodigo )  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "D"; cRet := "DEBITO "
		Case cCodigo == "C"; cRet := "CREDITO"
		OtherWise          ; cRet := "* Erro *"
	EndCase
	Return cRet
