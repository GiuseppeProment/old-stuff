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
//  BROWSE EMPRESA

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
							TipoEmpresa
	 Objetivo       : Escolha e exibicao de Empresas associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos Empresa aberto, chamado somente por valid no get
	 Observacao     : o TipoEmpresa deve $ "SMC"(servico,comercial,mista) se
							for nil nao filtra
*/

FUNCTION SearchEmpresa(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib,cTipo)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := Empresa->(IndexOrd())
	Local lRet, cTit

	Do Case
		Case cTipo=='S' ; cTit := "SERVICOS"
		Case cTipo=='C' ; cTit := "COMERCIAIS"
		Case cTipo=='M' ; cTit := "MISTAS"
		OtherWise       ; cTit := " "
	EndCase

	Empresa->(DbSetOrder(2))

	If Empty(oGet:VarGet()) .or. !(Empresa->(DbSeek(oGet:VarGet())) .and. VerifyTipo(cTipo) )
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+8, nColJan+40, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA EMPRESAS "+cTit , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Empresa->( EmpresaBrowse( aWindow,cTipo ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(Empresa->EpCgc)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	Empresa->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(Empresa->EpNomeFant,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say Empresa->EpNomeFant color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION VerifyTipo(cTipo)
	Local lRet
	Do Case
		Case cTipo==Nil .or. Empresa->EpTipo=="M"
			lRet := .t.
		Case cTipo$"SC"
			lRet := Empresa->EpTipo==cTipo
	EndCase
	Return lRet


STATIC FUNCTION EmpresaBrowse( aWindow,cTipo )
	Local oEmpresa, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor(), bEmpresa

	If cTipo==Nil
		bEmpresa := { || .t. }
	else
		bEmpresa := "{ || Empresa->EpTipo==["+cTipo+"] .or.Empresa->EpTipo==[M]}"
		bEmpresa := &bEmpresa
	endif

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oEmpresa := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oEmpresa:headSep := Chr(205) + Chr(203) + Chr(205)
	oEmpresa:colSep  := " " + Chr(186) + " "
	oEmpresa:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oEmpresa:AddColumn( TBcolumnNew( "CGC", {|| Empresa->EpCgc } ) )
	oEmpresa:AddColumn( TBcolumnNew( "NOME FANTASIA", {|| Empresa->EpNomeFant } ) )
	oEmpresa:AddColumn( TBcolumnNew( "PROPRIETARIA", {|| If(Empresa->EpPrinc=="S","X"," ") } ) )

	// Define Filtros
	oEmpresa:GoBottomBlock := {|| GoBottom( bEmpresa ) }
	oEmpresa:GoTopBlock    := {|| GoTop( bEmpresa ) }
	oEmpresa:SkipBlock     := {|nRecords| Skiper( nRecords, bEmpresa, oEmpresa ) }
	Skiper( 0,, oEmpresa )   // Seta Variaveis Static's

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO   F10 CODIGO")

	While pTRUE

		If IsStable(oEmpresa)
			If oEmpresa:hitTop .or. oEmpresa:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oEmpresa:Cargo != NIL          // o Slot Contem Algo,
					Eval( oEmpresa:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		Empresa->( StdKey( oEmpresa, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  Empresa->( EmpSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4],bEmpresa,oEmpresa ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  Empresa->( EmpSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4],bEmpresa,oEmpresa ) )
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

Static Function EmpSeekNome(nLin,nCol,nColf,bEmpresa,oEmpresa)
		Local cEpRazaoSoc := Empresa->(MakeEmpty("EpRazaoSoc"))
		Local GetList:={}
		Empresa->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cEpRazaoSoc Pict wPicture([@! ]) Color WhatColor()
		read
		Empresa->(DbSeek(cEpRazaoSoc,.t.))
		wClose()
		While !Eval(bEmpresa) .and. !oEmpresa:HitBottom
			oEmpresa:Down()
			oEmpresa:Stabilize()
		End
		If oEmpresa:HitBottom
			oEmpresa:GoTop()
		Endif
		VOID

Static Function EmpSeekCodigo(nLin,nCol,nColf,bEmpresa,oEmpresa)
		Local nEpCgc := Empresa->(MakeEmpty("EpCgc"))
		Local GetList:={}
		Empresa->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nEpCgc Pict [99.999.999] Color WhatColor()
		read
		wClose()
		If !(Empresa->(DbSeek(nEpCgc,.t.)))
			Msg("Nao encontrado")
		Endif
		While !Eval(bEmpresa) .and. !oEmpresa:HitBottom
			oEmpresa:Down()
			oEmpresa:Stabilize()
		End
		If oEmpresa:HitBottom
			oEmpresa:GoTop()
		Endif
		VOID

