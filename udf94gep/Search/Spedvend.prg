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
//  BROWSE DE PEDIDOS DE VENDA

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela

	 Objetivo       : Escolha e exibicao de Pedido Venda associado a variavel no get
	 Excessao       : Pedidos com flag atendido nao sao permitidos para escolha
	 Pre-requisitos : Arquivo PedVend aberto

*/

FUNCTION SearchPedVend(aGetList,nLinJan,nColJan,SomenteAprovados)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := PedVend->(IndexOrd())
	Local lRet

	
	DEFAULT SomenteAprovados TO .f.

	PedVend->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !PedVend->(DbSeek(EMPRESA_VENDA+STR(oGet:VarGet(),6) )) .or. ;
		( PedVend->(Found()) .and. !CondPedVend(SomenteAprovados) )
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+18, nColJan+70, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA PEDIDOS DE VENDA"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),PedVend->( PedVendBrowse( aWindow,;
		 SomenteAprovados ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(PedVend->PvCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		// seeks na empresa e no cliente
		Empresa->( DbSeek(PedVend->PvEmpresa) )
		Cliente->( DbSeek(PedVend->PvCliente) )
		lRet:=pTRUE
	Endif
	PedVend->(DbSetOrder(nOrder1))
	Return lRet


STATIC FUNCTION CONDPedVend(SomenteAprovados)
	Local lRet := .t.
	If !Empty(PedVend->PvAtendido)
		Msg({"Pedido Ja' Atendido","Escolha Negada"})
		lRet := .f.
	endif
	If !Empty(PedVend->PvCancel)
		Msg({"Pedido Cancelado","Escolha Negada"})
		lRet := .f.
	endif
*   If (PedVend->PvDtValida < Date())
*       Msg({"Data de Validade","do pedido expirada.","Escolha Negada"})
*       lRet := .f.
*   endif
	If SomenteAprovados
		If Empty(PedVend->PvOkCliente) .or.;
			Empty(PedVend->PvOkFinan)   .or.;
			Empty(PedVend->PvOkVenda)
			Msg({"Pedido Nao Aprovado","Escolha Negada"})
			lRet := .f.
		Endif
	Endif
	Return lRet


STATIC FUNCTION PedVendBrowse( aWindow , SomenteAprovados)
	Local oPedidoVenda, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
            sCorAnt  := SetColor(),;
            aPesquisa := PesquisaNew()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oPedidoVenda := TBrowseDB(aWindow[1,1],aWindow[1,2],;
                              aWindow[1,3]-04,aWindow[1,4])

   PesquisaRowColLen( aPesquisa, aWindow[1,3]-3, aWindow[1,2], wWidth() )

   @ aWindow[1,3]-2,aWindow[1,2] to aWindow[1,3]-2,aWindow[1,4]

    @ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oPedidoVenda:headSep := Chr(205) + Chr(203) + Chr(205)
	oPedidoVenda:colSep  := " " + Chr(186) + " "
	oPedidoVenda:footSep := Chr(196) + Chr(208) + Chr(196)

	// Criar objetos coluna

	oCol:=TBcolumnNew( "Empresa",;
			 {|| If(PedVend->PvEmpresa!=Empresa->EpCgc,;
					  Empresa->( DbSeek(PedVend->PvEmpresa) ), ) , ;
					  Empresa->EpNomeFant } )
	oCol:Width := 10
	oPedidoVenda:AddColumn(oCol)


	oCol:=TBcolumnNew( "N§ Ped.",;
			 {|| PedVend->PvCodigo } )
	oPedidoVenda:AddColumn(oCol)

	oCol:=TBcolumnNew( "Cliente",;
			 {|| Cliente->(DbSeek(PedVend->PvCliente)),;
				  Cliente->ClDescr } )
	oCol:Width := 20
	oPedidoVenda:AddColumn(oCol)

	oCol:=TBcolumnNew( "Dt Pedido",;
			 {|| PedVend->PvDtIns } )
	oPedidoVenda:AddColumn(oCol)

	oCol:=TBcolumnNew( "Dt Validade",;
			 {|| PedVend->PvDtValida } )
	oPedidoVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Projeto",;
          {|| PedVend->PvProjeto } )
   oPedidoVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Apv Cliente",;
          {|| PedVend->PvOkClient} )
   oPedidoVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Apv Vendas",;
          {|| PedVend->PvOkVenda} )
   oPedidoVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Apv Financ.",;
          {|| PedVend->PvOkFinan} )
   oPedidoVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Atendido",;
          {|| PedVend->PvAtendido} )
   oPedidoVenda:AddColumn(oCol)


	// Define Filtros

    Centra(aWindow[1,3]-0,aWindow[1,2],aWindow[1,4],"F8 CONSULTA   F9 PESQUISA")

	While pTRUE

		If IsStable(oPedidoVenda)
			If oPedidoVenda:hitTop .or. oPedidoVenda:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oPedidoVenda:Cargo != NIL          // o Slot Contem Algo,
					Eval( oPedidoVenda:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
            PesquisaZap(aPesquisa)  // desfaz pesquisa
            Exit
		Endif
		PedVend->( StdKey( oPedidoVenda, nKey ) )     // Controle de Teclagem
		Do Case
			Case nKey == pF8   // CONSULTA
				Adm23300()

            Case nKey == pF9   // Pesquisa
               If PvPesquisa(aPesquisa)
                  oPedidoVenda:RefreshAll()
                  oPedidoVenda:ForceStable()
               EndIf

            Case nKey == pALT_F
               PesquisaVerFiltro(aPesquisa)

            Case nKey == pENTER
				If CondPedVend(SomenteAprovados)
					// forcar execucao das colunas derivadas (extrangeiras)
					// que realizam o posicionamento das entidades extrangeiras
					Eval(oPedidoVenda:GetColumn(1):Block)
					Eval(oPedidoVenda:GetColumn(3):Block)

                    * Desfaz pesquisa, porem mantem o registro corrente

                    PesquisaExit(aPesquisa)

                    lRet:=pFALSE
					exit
				endif
		EndCase
	Enddo  
	RETURN( lRet )


Function PvPesquisa(aPesquisa)

   Local lRet

   Local aTipo := { "Achar Pedido N§",;
                    "Filtrar por Cliente",;
                    "Filtrar por Periodo de Datas"}


   Local nTipo

   PesquisaZap(aPesquisa) // desfaz qualquer outra pesquisa

   // tipo de pesquisa

   nTipo := Menu_ver2("Tipo de Pesquisa",aTipo)

   If ntipo != 0
      Do Case
         Case nTipo == 1
            lRet := PvPesqNumero()
         Case nTipo == 2
            If (lRet := PvPesqCliente(aPesquisa) )
               PesquisaDisplay(aPesquisa)
            endif
         Case nTipo == 3
            If (lRet := PvPesqPeriodo(aPesquisa) )
               PesquisaDisplay(aPesquisa)
            endif
      EndCase
   Else
      lRet := .f.
   Endif

   Return .t.


Static Function PvPesqNumero()
   Local nPedido :=  PedVend->(MakeEmpty("PvCodigo"))
   Local cEmpresa := PedVend->(MakeEmpty("PvEmpresa"))
   Local cCorAnt:=SetColor()
   Local nCursor
   Local GetList:={}

   wOpen( WSet( 10, 19, 14, 52, WhatColor(1), pSBAR, 3, 5,;
   "Pedido Venda ¯ Pesquisa Numero", pCENTER_JUSTIFIED,,,) )

   SetColor(WhatColor())

   @ wRow(),wCol(1)   say "Empresa ";
                      Get cEmpresa;
                      Picture [99.999.999];
                      Valid LastKey()==pUP_ARROW .or. ;
                            SearchEmpresa(GetList,04,03,.t.,Row(),Col()+2,10,"C")

   @ wRow(1),wCol(1)  say "Pedido N§ ";
                     Get nPedido;
                     Picture [999999];
                     Valid LastKey()==pUP_ARROW .or. ;
                       (IIf(PedVend->(DbSeek( cEmpresa+Str(nPedido,6) )) ,.t.,(Msg("Pedido nao encontrado"),.f.) ))

   nCursor:=SetCursor()
   SetCursor(1)
   Read
   SetCursor(nCursor)

   SetColor(cCorAnt)
   wClose()

   Return LastKey()!=pESC



Static Function PvPesqCliente(aPesquisa)
   Local nCliente := PedVend->(MakeEmpty("PvCliente"))
   Local cCorAnt:=SetColor()
   Local nCursor
   Local GetList:={}
   Local lRet
   Local cFor
   Local aMatCri   := { "  Exclue Nao Aprovados",;
                        "  Exclue Nao Atendidos",;
                        "  Exclue Aprovados    ",;
                        "  Exclue Atendidos    "}

   wOpen( WSet( 10, 19, 14, 52, WhatColor(1), pSBAR, 3, 5,;
   "Pedido Venda ¯ Pesquisa Cliente", pCENTER_JUSTIFIED,,,) )

   SetColor(WhatColor())

   @ wRow(1), wCol(1) Say "Cliente " Get nCliente;
                      Valid LastKey()==pUP_ARROW .or. ;
                            SearchCliente(GetList,04,03,.f.)

   nCursor:=SetCursor()
   SetCursor(1)
   Read
   SetCursor(nCursor)

   SetColor(cCorAnt)
   wClose()

   If LastKey()!=pESC

      // define os criterios

      PesquisaON(aPesquisa, "CLIENTE - "+Left(Cliente->ClDescr,30) )

      cFor := PvCriteria(aPesquisa,aMatCri)

      PesquisaNtxTmp(aPesquisa)

      dbSetOrder(2) // por cliente

      // posicionar o primeiro pedido
      DbSeek( nCliente )

      Index on PedVend->PvCliente;
             to (PesquisaNomeTmp(aPesquisa)) ;
             While PedVend->PvCliente == nCliente;
             For &(cFor)

      Set Index to (PesquisaNomeTmp(aPesquisa))

      lRet := .t.

   Else
      lRet := .f.
   EndIf

   Return lRet


Static Function PvPesqPeriodo(aPesquisa)
   Local dData1 := ctod(" ")
   Local dData2 := ctod(" ")
   Local cCorAnt:=SetColor()
   Local nCursor
   Local GetList:={}
   Local lRet
   Local cFor
   Local aMatCri   := { "  Exclue Nao Aprovados",;
                        "  Exclue Nao Atendidos",;
                        "  Exclue Aprovados    ",;
                        "  Exclue Atendidos    "}

   wOpen( WSet( 10, 19, 14, 52, WhatColor(1), pSBAR, 3, 5,;
   "Pedido Venda ¯ Pesquisa Periodo", pCENTER_JUSTIFIED,,,) )

   SetColor(WhatColor())

   @ wRow(1),wCol(1) Get dData1

   @ wRow(1),Col()+2 say " Ate' ";
                     Get dData2

   nCursor:=SetCursor()
   SetCursor(1)
   Read
   SetCursor(nCursor)

   SetColor(cCorAnt)
   wClose()

   If LastKey()!=pESC

      // define os criterios

      PesquisaON(aPesquisa,"PERIODO DE "+dtoc(dData1)+" ATE' "+dtoc(dData2))

      cFor := PvCriteria(aPesquisa,aMatCri)

      PesquisaNtxTmp(aPesquisa)

      dbSetOrder(3) // por data

      // posicionar o primeiro pedido
      DbSeek( DToS(dData1),.t. )

      Index on PedVend->PvDtIns;
             to (PesquisaNomeTmp(aPesquisa)) ;
             While PedVend->PvDtIns >= dData1 .and. PedVend->PvDtIns <= dData2;
             For &(cFor)

      Set Index to (PesquisaNomeTmp(aPesquisa))

      lRet := .t.

   Else
      lRet := .f.
   EndIf

   Return lRet


Static Function PvCriteria(aPesquisa,aCriterio)
   Local nChange
   Local cXis,n,cFor
   Local aEscolha := {}

   While Lastkey()!=pESC
      nChange := Menu_Ver2("Criterio",aCriterio)
      If nChange != 0
         If Left(aCriterio[nChange],1) == "*"
            aCriterio[nChange] := Stuff(aCriterio[nChange],1,1," ")
         else
            aCriterio[nChange] := Stuff(aCriterio[nChange],1,1,"*")
         endif
      Endif
   EndDo

   For n:= 1 to len(aCriterio)
      If Left(aCriterio[n],1) == "*"
         PesquisaAddFiltro( aPesquisa, Ltrim( aCriterio[n] ) )
      Endif
   Next

   cFor := ""

      // * Exclue nao aprovados (sim)
      If Left(aCriterio[1],1) == "*"
         cFor +=;
            "( !Empty(PedVend->PvOkClient).and."+;
            "!Empty(PedVend->PvOkVenda).and." +;
            "!Empty(PedVend->PvOkFinan) )"
      Endif
      // * Exclue nao atendidos (sim)
      If Left(aCriterio[2],1) == "*"
         cFor +=;
            If( !Empty(cFor),".and."," ")+;
            "!Empty(PedVend->PvAtendido)"
      Endif
      // * Exclue aprovados (sim)
      If Left(aCriterio[3],1) == "*"
         cFor +=;
            If( !Empty(cFor),".and."," ")+;
            "( Empty(PedVend->PvOkClient).and."+;
            "Empty(PedVend->PvOkVenda).and." +;
            "Empty(PedVend->PvOkFinan) )"
      Endif
      // * Exclue atendidos (sim)
      If Left(aCriterio[4],1) == "*"
         cFor +=;
            If( !Empty(cFor),".and."," ")+;
            "Empty(PedVend->PvAtendido)"
      Endif

      If Empty(cFor)
         cFor := ".T."
      Endif

   Return cFor









