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

//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//    BROWSE MATERIAL


/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de material, associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos Estoque e Estoana abertos, chamado somente por valid no get
*/

FUNCTION SearchMat(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := Estoque->(IndexOrd())
	Local nOrder2 := EstoAna->(INdexOrd())
	Local lRet
	
	If Empty(oGet:VarGet()) .or. !(EstoAna->(DbSetOrder(2),DbSeek(oGet:VarGet()),DbSetOrder(1),Found()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+70, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA ESTOQUE"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Estoque->( MatBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		 SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(EstoAna->EaCodRedu)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		Estoque->(DbSetOrder(1))
		lRet := pTRUE
	Endif
	Estoque->(DbSetOrder(nOrder1))
	EstoAna->(DbSetOrder(nOrder2))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(NomeMat(oGet:VarGet),1,nLenExib) Color CorGetUnSel()
		else
			@ nLinExib,nColExib say NomeMat(oGet:VarGet) Color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION MatBrowse( aWindow )
	Local oEstoque, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

    Estoque->(DbSetOrder(3))

	If EOF() .or. BOF()
		DbGoTop()
	Endif


	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oEstoque := TBrowseDB(aWindow[1,1],aWindow[1,2],;
                              aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oEstoque:headSep := Chr(205) + Chr(203) + Chr(205)
	oEstoque:colSep  := " " + Chr(186) + " "
	oEstoque:footSep := Chr(196) + Chr(208) + Chr(196)

    // Criar objetos coluna
	oCol:= TBcolumnNew( "CODIGO",;
				{|| aPict:={"@R 9",,"@R 9.99",,,,"@R 9.99.9999"}, ;
					 Transform( Estoque->EqCodigo,;
									aPict[ ;
									IIf((nTmp:=Len(AllTrim(Estoque->EqCodigo))) > 0,nTmp,1);
									] ) } )
	oCol:Width := 9
	oEstoque:AddColumn(oCol)


	oCol:=TBcolumnNew( "DESCRICAO",;
             {|| If( Len(AllTrim(Estoque->EqCodigo))==7,;
             xMaterial(Estoque->EqCodigo),Estoque->EqDescNor) } )
	oCol:Width := 50
	oEstoque:AddColumn(oCol)


	oEstoque:AddColumn( TBColumnNew( "REDUZIDO", ;
										{|| If( Len( Alltrim( ;
                                                         Estoque->EqCodigo ) ) == 7 ,;
																 Transform( EstoAna->EaCodRedu, ;
                                                                                "@R 9999" ) ,;
														  "    " ) } ) )   

	// Define Filtros
	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO  F10 CODIGO")

	While pTRUE

		If IsStable(oEstoque)
			If oEstoque:hitTop .or. oEstoque:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oEstoque:Cargo != NIL          // o Slot Contem Algo,
					Eval( oEstoque:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		Estoque->( StdKey( oEstoque, nKey ) )     // Controle de Teclagem

		Do Case
		  Case nKey == pF9         //Procura Nome
				  Estoque->( MatSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  Estoque->( MatSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
              If  Len(AllTrim(Estoque->EqCodigo)) == 7
                  xMaterial(Estoque->EqCodigo) // PARA POSICIONAR O ESTOANA
				  lRet:=pFALSE
				  exit
			  endif
		EndCase
	Enddo  
	RETURN( lRet )

Static Function MatSeekNome(nLin,nCol,nColf)
		Local cEqDescNor := Estoque->(MakeEmpty("EqDescNor"))
		Local GetList:={}
		Estoque->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cEqDescNor Pict [@! ] Color WhatColor()
		read
		Estoque->(DbSeek(cEqDescNorm,.t.))
		If Estoque->(Eof())
			Estoque->(DbSkip(-1))
		Endif
		wClose()
        Estoque->(DbSetOrder(3))
        VOID

Static Function MatSeekCodigo(nLin,nCol,nColf)
		Local nEaCodRedu := EstoAna->(MakeEmpty("EaCodRedu"))
		Local GetList:={}
		Local nOrder1 := EstoAna->(IndexOrd())
		EstoAna->(DbSetOrder(2))
		Estoque->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nEaCodRedu Pict [99999] Color WhatColor()
		read
		wClose()
		If !(EstoAna->(DbSeek(nEaCodRedu)))
			Msg("Nao encontrado")
		else
			// procurar o sintetico
			Estoque->(DbSeek(EstoAna->EaCodigo))
		Endif
        EstoAna->(DbSetOrder(nOrder3))
		VOID

FUNCTION xMaterial(nCodMat)
 Local cDescrMat
 Local Ordem := EstoAna->(IndexOrd())
 Local OrdMed:= MedMade->(IndexOrd())
 Local OrdTip:= TipoMad->(IndexOrd())

 MedMade->(DbSetOrder(1))
 TipoMad->(DbSetOrder(1))
 EstoAna->(DbSetOrder(1))

 EstoAna->(DbSeek(nCodMat))
 MedMade->(DbSeek(EstoAna->EaCodMed))
 TipoMad->(DbSeek(EstoAna->EaCodMad))

 cDescrMat := AllTrim(Estoque->EqDescNor) +" "+;
				  AllTrim(TipoMad->TmDescrNor) +" "+ MontaMedMade()

 EstoAna->(DbSetOrder(Ordem))
 MedMade->(DbSetOrder(OrdMed))
 TipoMad->(DbSetOrder(OrdTip))

 Return cDescrMat


