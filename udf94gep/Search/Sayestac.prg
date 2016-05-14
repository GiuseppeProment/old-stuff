FUNCTION SayEstaCli(nCliente,nLocal)
	Local nOrder1 := EstaCli->(IndexOrd())
	EstaCli->(DbSetOrder(1))
	EstaCli->(DbSeek( str(nCliente)+Str(nLocal)))
	EstaCli->(DbSetOrder(nOrder1))
	Return If(EstaCli->(Found()),IdEstab(EstaCli->EcIdenTest)," NAO EXISTE ")

Static Function IdEstab(nEcIdenTest)
	Local cRet
	Do Case
		Case nEcIdenTest == 01 ; cRet := "SEDE       "
		Case nEcIdenTest == 02 ; cRet := "FATURAMENTO"
		Case nEcIdenTest == 03 ; cRet := "ENTREGA    "
		Case nEcIdenTest == 04 ; cRet := "COBRANCA   "
		Case nEcIdenTest == 05 ; cRet := "OBRA       "
		Case nEcIdenTest == 06 ; cRet := "OUTROS     "
		OtherWise
			cRet := "  ? "
	EndCase
	Return cRet

