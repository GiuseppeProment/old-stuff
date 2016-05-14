#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "Recoma.ch"
#Include "PTWindow.ch"

#DEFINE EMPRESA_SERVICO "50.996.479"
#DEFINE EMPRESA_VENDA "51.212.348"

MemVar sCorJ,sCorF,sCorT,sCorL,sCorM
MemVar aPict, nTmp

Function ProximoMes(dArg)
	Local dRet
	Local nDesloca:=0
	Local nNextDia
	Local nNextMes
	Local nNextAno
	If Month(dArg)==12
		nNextMes:=1
		nNextAno:=Val(Substr( Str(Year(dArg)+1,4),-2,2))
	Else
		nNextMes := Month(dArg)+1
		nNextAno := Val(Substr( Str(Year(dArg),4),-2,2))
	Endif
	If Day(dArg)==Day(LastDay(dArg))
		nNextDia:=Day(LastDay( CtoD( "01/"+Str(nNextMes,2)+"/"+Str(nNextAno,2) )  ))
	else
		nNextDia:=Day(dArg)
	EndIf

	Repeat
		dRet := CtoD( Str(nNextDia-nDesloca,2)+"/"+Str(nNextMes,2)+"/"+Str(nNextAno,2) )
		nDesloca++
	Until !Empty(dRet)
	Return dRet
