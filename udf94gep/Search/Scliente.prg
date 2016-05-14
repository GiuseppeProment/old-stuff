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
//  BROWSE DE CLIENTE

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de Cliente associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos MedMade aberto, chamado somente por valid no get
*/

FUNCTION SearchCliente(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := Cliente->(IndexOrd())
	Local lRet
	
	Cliente->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !Cliente->(DbSeek(oGet:VarGet()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+60, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA CLIENTES"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Cliente->( ClienteBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(Cliente->ClCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	Cliente->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(Cliente->ClDescr,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say Cliente->ClDescr color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION ClienteBrowse( aWindow )
	Local oCliente, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oCliente := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oCliente:headSep := Chr(205) + Chr(203) + Chr(205)
	oCliente:colSep  := " " + Chr(186) + " "
	oCliente:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oCliente:AddColumn( TBcolumnNew( "CODIGO", {|| Cliente->ClCodigo } ) )
    oCliente:AddColumn( TBcolumnNew( "NOME", {|| Cliente->ClDescr } ) )
	// Define Filtros

    Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 NOME   F10 CODIGO   F11 PARTE DO NOME")

	While pTRUE

		If IsStable(oCliente)
			If oCliente:hitTop .or. oCliente:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oCliente:Cargo != NIL          // o Slot Contem Algo,
					Eval( oCliente:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		Cliente->( StdKey( oCliente, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  Cliente->( CliSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  Cliente->( CliSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
          Case nKey == pF11        //Procura PARTE DO NOME
                  Cliente->( CliSeekParte( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function CliSeekNome(nLin,nCol,nColf)
		Local cClDescr := Cliente->(MakeEmpty("ClDescr"))
		Local GetList:={}
		Cliente->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
         "NOME A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cClDescr Pict wPicture([@! ]) Color WhatColor()
		read
		Cliente->(DbSeek(cClDescr,.t.))
		wClose()
		VOID

Static Function CliSeekParte(nLin,nCol,nColf)
		Local cClDescr := Cliente->(MakeEmpty("ClDescr"))
		Local GetList:={}
		Cliente->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
         "PARTE DO NOME A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cClDescr Pict wPicture([@! ]) Color WhatColor()
		read
        MsgWait("Pesquisando...")
        cClDescr := AllTrim(Upper(cClDescr))
        Locate for Localiza(cClDescr)
        If Cliente->(Eof())
            Cliente->(DbSkip(-1))
        Endif
        lRet:=.t.
        MsgWait()
        wClose()
		VOID

Static Function Localiza(cSeek)
   Local lFound := cSeek $ Cliente->ClDescr
   @ wRow(1),wCol() say Cliente->ClDescr
   If lFound
      If Confirma({"Localizei o cliente abaixo.",;
                   "Tenta Achar o Proximo ?    "})
         Continue
      endif
   endif
   Return lFound


Static Function CliSeekCodigo(nLin,nCol,nColf)
		Local nClCodigo := Cliente->(MakeEmpty("ClCodigo"))
		Local GetList:={}
		Cliente->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nClCodigo Color WhatColor()
		read
		wClose()
		If !(Cliente->(DbSeek(nClCodigo,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID


