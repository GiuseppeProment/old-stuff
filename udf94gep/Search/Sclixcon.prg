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
//  BROWSE COMISSIONADOS POR CLIENTE ESPECIFICO

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
							nCodigoCliente,lSomenteAtivos
	 Objetivo       : Escolha e exibicao Comissionados por cliente associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos ClixCom e Comissi aberto, chamado somente por valid no get
*/

FUNCTION SearchClixCom(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib,;
			nClCodigo,lSoAtivos)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := ClixCom->(IndexOrd())
	Local nOrder2 := Comissi->(IndexOrd())
	Local lRet
	
	ClixCom->(DbSetOrder(1))
	Comissi->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or.;
		!ClixCom->(DbSeek( str(nClCodigo)+str(oGet:VarGet()) ) .and. VerifyCxC())
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+09, nColJan+40, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA COMISSIONADOS"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),ClixCom->;
		 ( ClixComBrowse( aWindow,nClCodigo,lSoAtivos ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(ClixCom->CcCodCom)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif

	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(Comissi->CsNome,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say Comissi->CsNome color CorGetUnSel()
		endif
	Endif

	ClixCom->(DbSetOrder(nOrder1))
	Comissi->(DbSetOrder(nOrder2))

	Return lRet

STATIC FUNCTION VerifyCxC
	If !Comissi->(DbSeek(ClixCom->CcCodCom))
		Msg({"Comissionado esta na lista",;
			  "de relacoes com clientes"  ,;
			  "porem nao existe no cadastro"})
	Endif
	Return Comissi->(Found())

STATIC FUNCTION ClixComBrowse( aWindow,nClCodigo,lSoAtivos )
	Local oClixCom, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor(),;
			bClixCom := { || ClixCom->CcCodCli==nClCodigo }

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oClixCom := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oClixCom:headSep := Chr(205) + Chr(203) + Chr(205)
	oClixCom:colSep  := " " + Chr(186) + " "
	oClixCom:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oClixCom:AddColumn( TBcolumnNew( "CD", {|| ClixCom->CcCodCom } ) )

	oClixCom:AddColumn( TBcolumnNew( "NOME", {|| Comissi->;
			  (If(DbSeek(ClixCom->CcCodCom),Comissi->CsNome," ** NAO EXISTE **"));
			  } ) )

	oClixCom:AddColumn( TBcolumnNew( "DATA BASE", {|| ClixCom->CcDataBase } ) )
	
	oClixCom:AddColumn( TBcolumnNew( "% VENDA", {|| Comissi->;
			  (If(Found(),Comissi->CsComVend,"    "));
			  } ) )
	oClixCom:AddColumn( TBcolumnNew( "% SERV.", {|| Comissi->;
			  (If(Found(),Comissi->CsComServ,"    "));
			  } ) )
	oClixCom:AddColumn( TBcolumnNew( "TIPO", {|| Comissi->;
			  (If(Found(),Comissi->CsCatego," "));
			  } ) )

	// Define Filtros
	oClixCom:GoBottomBlock := {|| OptGoBottom( bClixCom,str(nClCodigo)+Str(999,3,0) ) }
	oClixCom:GoTopBlock    := {|| OptGoTop( bClixCom,str(nClCodigo)+Str(000,3,0) ) }
	oClixCom:SkipBlock     := {|nRecords| OptSkiper( nRecords, bClixCom, oClixCom,;
										str(nClCodigo)+Str(0,3,0),str(nClCodigo)+Str(999,3,0)  ) }
	OptSkiper(0,,oClixCom,str(nClCodigo)+Str(0,3,0),str(nClCodigo)+Str(999,3,0) )   // Seta Variaveis Static's

	While pTRUE

		If IsStable(oClixCom)
			If oClixCom:hitTop .or. oClixCom:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oClixCom:Cargo != NIL          // o Slot Contem Algo,
					Eval( oClixCom:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		ClixCom->( StdKey( oClixCom, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
				// forca execucao da coluna de nome (pois da' seek no comissi)
				Eval(oClixCom:GetColumn(2):Block)
				If lSoAtivos .and. Comissi->CsStatus!="S"
					Msg("Comissionado Inativo")
					Loop
				Endif
				lRet:=pFALSE
				exit
		EndCase
	Enddo  
	RETURN( lRet )


//
