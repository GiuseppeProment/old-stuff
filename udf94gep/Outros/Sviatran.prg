Function SayViaTrans(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
		Case cCodigo == 'R'; cRet := "Rodoviario "
		Case cCodigo == 'F'; cRet := "Ferroviario"
		Case cCodigo == 'A'; cRet := "Aereo      "
		Case cCodigo == 'M'; cRet := "Maritimo   "
		OtherWise          ; cRet := "* Erro *   "
	EndCase
	Return cRet
