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
//  BROWSE DE FORNECEDOR

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao do Fornecedor associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos Fornece aberto, chamado somente por valid no get
*/

FUNCTION SearchFornece(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := Fornece->(IndexOrd())
	Local lRet
	
	Fornece->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !Fornece->(DbSeek(oGet:VarGet()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+60, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA FORNECEDORES"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Fornece->( ForneceBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(Fornece->FnCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	Fornece->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(Fornece->FnNome,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say Fornece->FnNome  color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION ForneceBrowse( aWindow )
	Local oFornece, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oFornece := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oFornece:headSep := Chr(205) + Chr(203) + Chr(205)
	oFornece:colSep  := " " + Chr(186) + " "
	oFornece:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oFornece:AddColumn( TBcolumnNew( "CODIGO", {|| Fornece->FnCodigo } ) )
	oFornece:AddColumn( TBcolumnNew( "RAZAO SOCIAL", {|| Fornece->FnNome } ) )
	// Define Filtros

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO   F10 CODIGO")

	While pTRUE

		If IsStable(oFornece)
			If oFornece:hitTop .or. oFornece:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oFornece:Cargo != NIL          // o Slot Contem Algo,
					Eval( oFornece:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		Fornece->( StdKey( oFornece, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  Fornece->( FornSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  Fornece->( FornSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
				  lRet:=pFALSE
				  exit
		EndCase
	Enddo  
	RETURN( lRet )

Static Function FornSeekNome(nLin,nCol,nColf)
		Local cFnNome := Fornece->(MakeEmpty("FnNome"))
		Local GetList:={}
		Fornece->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "RAZAO SOCIAL A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cFnNome Pict wPicture([@! ]) Color WhatColor()
		read
		Fornece->(DbSeek(cFnNome,.t.))
		wClose()
		VOID

Static Function FornSeekCodigo(nLin,nCol,nColf)
		Local nFnCodigo := Fornece->(MakeEmpty("FnCodigo"))
		Local GetList:={}
		Fornece->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nFnCodigo Color WhatColor()
		read
		wClose()
		If !(Fornece->(DbSeek(nFnCodigo,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID


