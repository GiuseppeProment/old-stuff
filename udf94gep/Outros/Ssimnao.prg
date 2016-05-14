Function SaySimNao(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "S"; cRet := "SIM"
		Case cCodigo == "N"; cRet := "NAO"
		OtherWise          ; cRet := "Erro"
	EndCase
	Return cRet

