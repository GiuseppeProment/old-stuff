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

Function MontaMedMade(xReduz)
Local sRet := " "
Do Case
	Case  Empty(MedMade->MmCompr) .and.;
		  !Empty(MedMade->MmLargura) .and.;
		  !Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmLargura)+" x "+Rtrim(MedMade->MmEspess)

	Case !Empty(MedMade->MmCompr) .and.;
		  !Empty(MedMade->MmLargura) .and.;
			Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmCompr)+" x "+Rtrim(MedMade->MmLargura)

	Case  Empty(MedMade->MmCompr) .and.;
		  !Empty(MedMade->MmLargura) .and.;
			Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmLargura)

	Case  Empty(MedMade->MmCompr) .and.;
			Empty(MedMade->MmLargura) .and.;
		  !Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmEspess)

	Case !Empty(MedMade->MmCompr) .and.;
			Empty(MedMade->MmLargura) .and.;
			Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmCompr)

	Case !Empty(MedMade->MmCompr) .and.;
		  !Empty(MedMade->MmLargura) .and.;
		  !Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmCompr)+" x "+Rtrim(MedMade->MmLargura)+" x "+Rtrim(MedMade->MmEspess)

	Case !Empty(MedMade->MmCompr) .and.;
			Empty(MedMade->MmLargura) .and.;
		  !Empty(MedMade->MmEspess)
		sRet := Rtrim(MedMade->MmCompr)+" x "+Rtrim(MedMade->MmEspess)
End


// se mandou parametro xReduz entao retira os espacos

If xReduz != NIL
	sRet := StrTran(sRet," ")
endif

Return sRet
