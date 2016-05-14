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





Function MesAnterior(dArg)
	Local dRet
	Local nDesloca:=0
	Local nAntDia
	Local nAntMes
	Local nAntAno
	If Month(dArg)==1
		nAntMes:=12
		nAntAno:=Val(Substr( Str(Year(dArg)-1,4),-2,2))
	Else
		nAntMes := Month(dArg)-1
		nAntAno := Val(Substr( Str(Year(dArg),4),-2,2))
	Endif
	If Day(dArg)==Day(LastDay(dArg))
		nAntDia:=Day(LastDay( CtoD( "01/"+Str(nAntMes,2)+"/"+Str(nAntAno,2) )  ))
	else
		nAntDia:=Day(dArg)
	EndIf

	Repeat
		dRet := CtoD( Str(nAntDia-nDesloca,2)+"/"+Str(nAntMes,2)+"/"+Str(nAntAno,2) )
		nDesloca++
	Until !Empty(dRet)
	Return dRet
