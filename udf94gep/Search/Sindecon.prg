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
//  BROWSE DE INDEXADORES ECONOMICOS

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de Indexador associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos IndeCon aberto, chamado somente por valid no get
*/

FUNCTION SearchIndeCon(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := IndeCon->(IndexOrd())
	Local lRet
	
	IndeCon->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !IndeCon->(DbSeek(oGet:VarGet()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+35+15+5, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA INDEXADORES"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),IndeCon->( IndeConBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(IndeCon->IeCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	IndeCon->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(IndeCon->IeDescrAb,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say IndeCon->IeDescrAb color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION IndeConBrowse( aWindow )
	Local oIndeCon, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oIndeCon := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oIndeCon:headSep := Chr(205) + Chr(203) + Chr(205)
	oIndeCon:colSep  := " " + Chr(186) + " "
	oIndeCon:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oIndeCon:AddColumn( TBcolumnNew( "DESC. ABV", {|| IndeCon->IeDescrAb } ) )
	oIndeCon:AddColumn( TBcolumnNew( "DESCRICAO", {|| IndeCon->IeDescr   } ) )
	// Define Filtros

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO")

	While pTRUE

		If IsStable(oIndeCon)
			If oIndeCon:hitTop .or. oIndeCon:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oIndeCon:Cargo != NIL          // o Slot Contem Algo,
					Eval( oIndeCon:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		IndeCon->( StdKey( oIndeCon, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  IndeCon->( IndSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function IndSeekNome(nLin,nCol,nColf)
		Local cIeDescrAb := IndeCon->(MakeEmpty("IeDescrAb"))
		Local GetList:={}
		IndeCon->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cIeDescrAb Pict wPicture([@! ]) Color WhatColor()
		read
		IndeCon->(DbSeek(cIeDescrAb,.t.))
		wClose()
		VOID

