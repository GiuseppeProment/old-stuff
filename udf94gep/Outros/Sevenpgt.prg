
Function SayEvenPgto(cCodigo)  // devolve a correspondente descricao
	Local cRet
	Do Case
        Case cCodigo == "F"; cRet := "Entrega"
        Case cCodigo == "P"; cRet := "Pedido "
        Case cCodigo == "C"; cRet := "A Comb."
        OtherWise          ; cRet := "       "
	EndCase
	Return cRet
