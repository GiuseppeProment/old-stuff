Function SayNatOpe(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == "12"; cRet := "Venda"
		Case cCodigo == "99"; cRet := "Outras"
		OtherWise          ; cRet :=  "Erro "
	EndCase
	Return cRet

