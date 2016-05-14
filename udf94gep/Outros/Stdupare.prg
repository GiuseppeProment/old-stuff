Function SayTDuparec( nCodigo )  // devolve a correspondente descricao
	Local cRet
	Do Case
      Case nCodigo == 1; cRet := "NORMAL  "
      Case nCodigo == 2; cRet := "SINAL   "
      Case nCodigo == 3; cRet := "RET. CON"
      Case nCodigo == 4; cRet := "RET. ISS"
      Case nCodigo == 5; cRet := "MANUAL  "
      Case nCodigo == 6; cRet := "PEDIDO  "
      Case nCodigo == 7; cRet := "ESPECIAL"
      Case nCodigo == 8; cRet := "CORRE€AO"
      OtherWise        ; cRet := "INDETER."
	EndCase
	Return cRet
