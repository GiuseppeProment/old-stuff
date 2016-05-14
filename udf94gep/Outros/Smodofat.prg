Function SayModoFatu(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "N"; cRet := "Venda          "
		Case cCodigo == "E"; cRet := "Entrega Futura "
		Case cCodigo == "S"; cRet := "Simples remessa"
		OtherWise          ; cRet := "* Erro *       "
	EndCase
	Return cRet

