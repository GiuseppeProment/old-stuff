FUNCTION SayEstEmp(nEstEmp)
	Local nOrder1 := Estabel->(IndexOrd())
	Estabel->(DbSetOrder(2))
	Estabel->(DbSeek(nEstEmp))
	Estabel->(DbSetOrder(nOrder1))
	Return If(Estabel->(Found()),Estabel->EstUnidade," NAO EXISTE ")