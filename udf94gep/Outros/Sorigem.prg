Function SayOrigem(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "S"; cRet := "Servico"
		Case cCodigo == "V"; cRet := "Venda  "
		OtherWise          ; cRet := "* Erro *   "
	EndCase
	Return cRet


