FUNCTION SayEmpresa(cCodigo)
	Local nOrder1 := Empresa->(IndexOrd())
	Empresa->(DbSetOrder(2))
	Empresa->(DbSeek(cCodigo))
	Empresa->(DbSetOrder(nOrder1))
	Return If(Empresa->(Found()),Empresa->EpNomeFant," NAO EXISTE ")
