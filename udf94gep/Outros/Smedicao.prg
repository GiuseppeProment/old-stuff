Function SayMedicao(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "Q"; cRet := "QUINZENAL"
		Case cCodigo == "M"; cRet := "MENSAL   "
		Case cCodigo == "N"; cRet := "         "
		OtherWise          ; cRet := "*ERRO*   "
	EndCase
	Return cRet
