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
//  BROWSE DE PEDIDOS DE SERVICO

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela

	 Objetivo       : Escolha e exibicao de Pedido Serv associado a variavel no get
	 Excessao       : Pedidos com flag atendido nao sao permitidos para escolha
	 Pre-requisitos : Arquivo PedServ aberto

*/

FUNCTION SearchPedServ(aGetList,nLinJan,nColJan,OrdemServico,FatBasePedido)
    Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := PedServ->(IndexOrd())
	Local lRet
	

    If OrdemServico == NIL
       OrdemServico := .f.
    endif

    If FatBasePedido == NIL
       FatBasePedido := .f.
    endif

    PedServ->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !PedServ->(DbSeek(EMPRESA_SERVICO+STR(oGet:VarGet(),6) )) .or. ;
        ( PedServ->(Found()) .and. ! CondPedServ(ordemServico, FatBasePedido) )
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+18, nColJan+60, WhatColor(1), pSBAR, 3, 0,;
         "PESQUISA PEDIDOS DE SERVICO"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),PedServ->( PedServBrowse( aWindow,;
         OrdemServico, FatBasePedido) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(PedServ->PsCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		// seeks na empresa e no cliente
		Empresa->( DbSeek(PedServ->PsEmpresa) )
		Cliente->( DbSeek(PedServ->PsCliente) )
		lRet:=pTRUE
	Endif
	PedServ->(DbSetOrder(nOrder1))
	Return lRet


STATIC FUNCTION CONDPEDSERV( OrdemServico , FatBasePedido)
	Local lRet := .t.
	If !Empty(PedServ->PsAtendido)
		Msg({"Pedido Ja' Atendido","Pedido e' invalido","Escolha Negada"})
		lRet := .f.
	endif
	If !Empty(PedServ->PsCancel)
		Msg({"Pedido Cancelado","Pedido e' invalido","Escolha Negada"})
		lRet := .f.
	endif
*   If (PedServ->PsDtValida < Date())
*       Msg({"Data de Validade","do pedido expirada.","Escolha Negada"})
*       lRet := .f.
*   endif
    If !OrdemServico
       If (PedServ->PsConPgto == "P")
          Msg({"Pedido parcelado","nao pode ter medicoes","Escolha Negada"})
          lRet := .f.
       endif
    endif
    If FatBasePedido
       If (PedServ->PsConPgto == "M")
          Msg({"Pedido com Medicao","somente com folha de medicao","Escolha Negada"})
          lRet := .f.
       endif
    Endif
    If Empty(PedServ->PsOkCliente) .or.;
       Empty(PedServ->PsOkFinan)   .or.;
       Empty(PedServ->PsOkVenda)
       Msg({"Pedido Nao Aprovado","Escolha Negada"})
       lRet := .f.
    Endif
	Return lRet


STATIC FUNCTION PedServBrowse( aWindow , OrdemServico, FatBasePedido)
	Local oPedidoServico, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
            sCorAnt  := SetColor(),;
            aPesquisa := PesquisaNew()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oPedidoServico := TBrowseDB(aWindow[1,1],aWindow[1,2],;
                              aWindow[1,3]-04,aWindow[1,4])

   PesquisaRowColLen( aPesquisa, aWindow[1,3]-3, aWindow[1,2], wWidth() )

   @ aWindow[1,3]-2,aWindow[1,2] to aWindow[1,3]-2,aWindow[1,4]

    @ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oPedidoServico:headSep := Chr(205) + Chr(203) + Chr(205)
	oPedidoServico:colSep  := " " + Chr(186) + " "
	oPedidoServico:footSep := Chr(196) + Chr(208) + Chr(196)

	// Criar objetos coluna

	oCol:=TBcolumnNew( "Empresa",;
			 {|| If(PedServ->PsEmpresa!=Empresa->EpCgc,;
					  Empresa->( DbSeek(PedServ->PsEmpresa) ), ) , ;
					  Empresa->EpNomeFant } )
	oCol:Width := 10
	oPedidoServico:AddColumn(oCol)


	oCol:=TBcolumnNew( "N§ Ped.",;
			 {|| PedServ->PsCodigo } )
	oPedidoServico:AddColumn(oCol)

	oCol:=TBcolumnNew( "Cliente",;
			 {|| Cliente->(DbSeek(PedServ->PsCliente)),;
				  Cliente->ClDescr } )
	oCol:Width := 20
	oPedidoServico:AddColumn(oCol)

	oCol:=TBcolumnNew( "Dt Pedido",;
			 {|| PedServ->PsDtIns } )
	oPedidoServico:AddColumn(oCol)

    oCol:=TBcolumnNew( "Dt Validade",;
             {|| PedServ->PsDtValida } )
    oPedidoServico:AddColumn(oCol)

   oCol:=TBcolumnNew( "Apv Cliente",;
          {|| PedServ->PsOkClient} )
   oPedidoServico:AddColumn(oCol)

   oCol:=TBcolumnNew( "Apv Vendas",;
          {|| PedServ->PsOkVenda} )
   oPedidoServico:AddColumn(oCol)

   oCol:=TBcolumnNew( "Apv Financ.",;
          {|| PedServ->PsOkFinan} )
   oPedidoServico:AddColumn(oCol)

   oCol:=TBcolumnNew( "Atendido",;
          {|| PedServ->PsAtendido} )
   oPedidoServico:AddColumn(oCol)

	// Define Filtros

    Centra(aWindow[1,3]-0,aWindow[1,2],aWindow[1,4],"F8 CONSULTA   F9 PESQUISA")

	While pTRUE

		If IsStable(oPedidoServico)
			If oPedidoServico:hitTop .or. oPedidoServico:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oPedidoServico:Cargo != NIL          // o Slot Contem Algo,
					Eval( oPedidoServico:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
            PesquisaZap(aPesquisa)  // desfaz a pesquisa
            Exit
		Endif
		PedServ->( StdKey( oPedidoServico, nKey ) )     // Controle de Teclagem
		Do Case
			Case nKey == pF8   // CONSULTA
				Adm29300()

            Case nKey == pF9   // Pesquisa
               If PsPesquisa(aPesquisa)
                  oPedidoServico:RefreshAll()
                  oPedidoServico:ForceStable()
               EndIf

            Case nKey == pALT_F
               PesquisaVerFiltro(aPesquisa)

            Case nKey == pENTER
                If CondPedServ(ordemservico, FatBasePedido)
					// forcar execucao das colunas derivadas (extrangeiras)
					// que realizam o posicionamento das entidades extrangeiras
					Eval(oPedidoServico:GetColumn(1):Block)
					Eval(oPedidoServico:GetColumn(3):Block)

                    * Desfaz pesquisa, porem mantem o registro corrente

                    PesquisaExit(aPesquisa)

					lRet:=pFALSE
					exit
				endif
		EndCase
	Enddo  
	RETURN( lRet )



Function PsPesquisa(aPesquisa)

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
            lRet := PsPesqNumero()
         Case nTipo == 2
            If (lRet := PsPesqCliente(aPesquisa) )
               PesquisaDisplay(aPesquisa)
            endif
         Case nTipo == 3
            If (lRet := PsPesqPeriodo(aPesquisa) )
               PesquisaDisplay(aPesquisa)
            endif
      EndCase
   Else
      lRet := .f.
   Endif

   Return .t.


Static Function PsPesqNumero()
   Local nPedido :=  PedServ->(MakeEmpty("PsCodigo"))
   Local cEmpresa := PedServ->(MakeEmpty("PsEmpresa"))
   Local cCorAnt:=SetColor()
   Local nCursor
   Local GetList:={}

   wOpen( WSet( 10, 19, 14, 52, WhatColor(1), pSBAR, 3, 5,;
   "Pedido Servi‡o ¯ Pesquisa Numero", pCENTER_JUSTIFIED,,,) )

   SetColor(WhatColor())

   @ wRow(),wCol(1)   say "Empresa ";
                      Get cEmpresa;
                      Picture [99.999.999];
                      Valid LastKey()==pUP_ARROW .or. ;
                            SearchEmpresa(GetList,04,03,.t.,Row(),Col()+2,10,"S")

   @ wRow(1),wCol(1)  say "Pedido N§ ";
                     Get nPedido;
                     Picture [999999];
                     Valid LastKey()==pUP_ARROW .or. ;
                       (IIf(PedServ->(DbSeek( cEmpresa+Str(nPedido,6) )) ,.t.,(Msg("Pedido nao encontrado"),.f.) ))

   nCursor:=SetCursor()
   SetCursor(1)
   Read
   SetCursor(nCursor)

   SetColor(cCorAnt)
   wClose()

   Return LastKey()!=pESC



Static Function PsPesqCliente(aPesquisa)
   Local nCliente := PedServ->(MakeEmpty("PsCliente"))
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
   "Pedido Servi‡o ¯ Pesquisa Cliente", pCENTER_JUSTIFIED,,,) )

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

      cFor := PsCriteria(aPesquisa,aMatCri)

      PesquisaNtxTmp(aPesquisa)

      dbSetOrder(2) // por cliente

      // posicionar o primeiro pedido
      DbSeek( nCliente )

      Index on PedServ->PsCliente;
             to (PesquisaNomeTmp(aPesquisa)) ;
             While PedServ->PsCliente == nCliente;
             For &(cFor)

      Set Index to (PesquisaNomeTmp(aPesquisa))

      lRet := .t.

   Else
      lRet := .f.
   EndIf

   Return lRet



Static Function PsPesqPeriodo(aPesquisa)
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
   "Pedido Servi‡o ¯ Pesquisa Periodo", pCENTER_JUSTIFIED,,,) )

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

      cFor := PsCriteria(aPesquisa,aMatCri)

      PesquisaNtxTmp(aPesquisa)

      dbSetOrder(3) // por data

      // posicionar o primeiro pedido
      DbSeek( DToS(dData1),.t. )

      Index on PedServ->PsDtIns;
             to (PesquisaNomeTmp(aPesquisa)) ;
             While PedServ->PsDtIns >= dData1 .and. PedServ->PsDtIns <= dData2;
             For &(cFor)

      Set Index to (PesquisaNomeTmp(aPesquisa))

      lRet := .t.

   Else
      lRet := .f.
   EndIf

   Return lRet





Static Function PsCriteria(aPesquisa,aCriterio)
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
            "( !Empty(PedServ->PsOkClient).and."+;
            "!Empty(PedServ->PsOkVenda).and." +;
            "!Empty(PedServ->PsOkFinan) )"
      Endif
      // * Exclue nao atendidos (sim)
      If Left(aCriterio[2],1) == "*"
         cFor +=;
            If( !Empty(cFor),".and."," ")+;
            "!Empty(PedServ->PsAtendido)"
      Endif
      // * Exclue aprovados (sim)
      If Left(aCriterio[3],1) == "*"
         cFor +=;
            If( !Empty(cFor),".and."," ")+;
            "( Empty(PedServ->PsOkClient).and."+;
            "Empty(PedServ->PsOkVenda).and." +;
            "Empty(PedServ->PsOkFinan) )"
      Endif
      // * Exclue atendidos (sim)
      If Left(aCriterio[4],1) == "*"
         cFor +=;
            If( !Empty(cFor),".and."," ")+;
            "Empty(PedServ->PsAtendido)"
      Endif

      If Empty(cFor)
         cFor := ".T."
      Endif

   Return cFor
