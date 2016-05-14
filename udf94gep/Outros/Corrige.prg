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


/*
Funcao     : Corrige
Finalidade : Corrige nPrincipal no periodo entre data1-data2 pelo nIndexador
Retorno    : Retorna o VALOR DA CORRECAO e em aMemoria a memoria de calculo
				 com a seguinte estrutura {{data,ValorIndice,ValorCorrecao}}
Excessoes  : No caso de nao achar o indexador ou valores Retorna 0
Observ.    : Arquivos IndEcon e ValIndx devem estar abertos

alteracao  : se mandar indexador 99 nao corrige (R$)

*/

Function Corrige(dData1,dData2,nIndexador,nPrincipal,aMemoria,lMsg)
	Local nValError

    DEFAULT aMemoria TO {}
    DEFAULT lMsg TO .t.

   If nIndexador == 99 .or. nIndexador == 3  // R$ R$
      Return 0
   EndIf

   If lMsg
 	   MsgWait("Calculando Correcao ...")
	Endif	

   If dData2 > dData1 .and. nIndexador!=99 // 99 e' R$ nao tem conversao
      If !IndEcon->(DbSeek(nIndexador))
           If lMsg
            Msg({"Indexador nao encontrado","Reajuste nao calculado"})
			Endif
         Quit
      endif

      If IndEcon->IeCalculo != "N"

         If IndEcon->IePeriodic == "D"
            nValError := CalcTipoDiario(dData1,dData2,nIndexador,nPrincipal,@aMemoria,lMsg)
         else
            nValError := CalcTipoMensal(dData1,dData2,nIndexador,nPrincipal,@aMemoria,lMsg)
         endif

         // se nao deu 0 entao tira o principal (retornar so' a correcao)

         If nValError != 0
            nValError -= nPrincipal
         else
            aMemoria:={}
         endif

      Else

         nValError := 0

      EndIf

   Else

      nValError := 0

   Endif

   If lMsg
      MsgWait()
	Endif

   Return nValError


Static Function CalcTipoDiario(dData1,dData2,nIndexador,nPrincipal,aMemoria,lMsg)

	Local nValor

	// localiza a 1§ data para indexar o valor
	If !ValIndx->(DbSeek( Str(nIndexador,2)+DtoS(dData1) ) ).or.;
		ValIndx->ViValor==0
        If lMsg
		   Msg({"Valor do "+IndEcon->IeDescrAb,"nao registrado.","Reajuste nao calculado"})
		Endif
		Return  0
	Endif

	aadd( aMemoria,{ DtoC(dData1) , ValIndx->ViValor , 0 } )
	nValor := nPrincipal / ValIndx->ViValor

	If !ValIndx->(DbSeek( Str(nIndexador,2)+DtoS(dData2) ) ).or.;
		ValIndx->ViValor==0
        If lMsg
		   Msg({"Valor do "+IndEcon->IeDescrAb,"nao registrado.","Reajuste nao calculado"})
		Endif
		Return  0
	Endif

	nValor *= ValIndx->ViValor
	aadd( aMemoria,{ DtoC(dData2) , ValIndx->ViValor , nValor-nPrincipal } )

	Return nValor



Static Function CalcTipoMensal(dData1,dData2,nIndexador,nPrincipal,aMemoria,lMsg)

	Local dNextData   := dData1
	Local dLastData   := dData1
	Local nValor      := nPrincipal
	Local nDiasResiduo:= 0
	Local nOrder      := ValIndx->(IndexOrd())

	ValIndx->(DbSetOrder(2))

	Repeat
		dNextData := ProximoMes(dNextData)
		If dNextData <= dData2
			// pega o indexador do mes

			If !ValIndx->(DbSeek( Str(nIndexador,2)+Substr(DtoS(dNextData),1,6))) .and.;
				!Empty(ValIndx->ViValor)
                If lMsg
				   Msg({"Valor do "+IndEcon->IeDescrAb,"nao registrado.","Reajuste nao calculado"})
				Endif
				Return  0
			Endif

			aadd( aMemoria,{ DtoC(dNextData) , ValIndx->ViValor , (nValor * ValIndx->ViValor / 100) } )

			nValor += (nValor * ValIndx->ViValor / 100)

			dLastData := dNextData
		endif

	Until dNextData > dData2

	// calcular o ultimo mes
	nDiasResiduo := dData2 - dLastData

	// pega o indexador do mes dData2 ou mais proximo

	If !ValIndx->(DbSeek( Str(nIndexador,2)+Substr(DtoS(dData2),1,6))) .and.;
		!Empty(ValIndx->ViValor)
		IF !ValIndx->(DbSeek( Str(nIndexador,2)+Substr(DtoS(dLastData),1,6))) .and.;
			!Empty(ValIndx->ViValor)
            If lMsg
			   Msg({"Valor do "+IndEcon->IeDescrAb,"nao registrado.","Reajuste nao calculado"})
			Endif
			Return  0
		EndIf
	Endif

	aadd( aMemoria,{ "Residuo "+Str(nDiasResiduo,2)+" Dias " , ;
			ValIndx->ViValor/30*nDiasResiduo , ;
			(nValor * (ValIndx->ViValor/30*nDiasResiduo) / 100) } )

	nValor += (nValor * (ValIndx->ViValor/30*nDiasResiduo) / 100)

	ValIndx->(DbSetOrder(nOrder))

	Return nValor

