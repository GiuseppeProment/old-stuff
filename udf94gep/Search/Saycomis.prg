
FUNCTION SayComiss(nCodigo)
    Local nOrder1 := Comissi->(IndexOrd())
    Comissi->(DbSetOrder(1))
    Comissi->(DbSeek(nCodigo))
    Comissi->(DbSetOrder(nOrder1))
    Return If(Comissi->(Found()),Comissi->CsNome," NAO EXISTE ")