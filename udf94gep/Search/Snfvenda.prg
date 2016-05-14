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
//  BROWSE NOTAS FISCAIS DE VENDA

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
     Objetivo       : Escolha e exibicao de NOTAS VENDA associado a variavel no get
	 Excessao       :
     Pre-requisitos : Arquivos NFVENDA aberto, chamado somente por valid no get
*/

FUNCTION SearchNfVenda(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
    Local nOrder1 := NfVenda->(IndexOrd())
	Local lRet
	
    NfVenda->(DbSetOrder(1))

    If Empty(oGet:VarGet()) .or. !NfVenda->(DbSeek(EMPRESA_VENDA+Str(oGet:VarGet()) ) )
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+36, WhatColor(1), pSBAR, 3, 0,;
         "PESQUISA NOTAS VENDA"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),NfVenda->( NfVendaBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
            oGet:VarPut(NfVenda->NfvNum)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
    NfVenda->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
            @ nLinExib,nColExib say Substr(SayCliente(NfVenda->NfvCliente),1,nLenExib) color;
			CorGetUnSel()
		else
            @ nLinExib,nColExib say SayCliente(NfVenda->NfvCliente) color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION NfVendaBrowse( aWindow )
   Local oNotaVenda, oCol
   Local nKey     := 0,;
         lRet     := pTRUE,;
         sCorAnt  := SetColor()

   // Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
   oNotaVenda := TBrowseDB(aWindow[1,1],aWindow[1,2],;
                       aWindow[1,3]-01,aWindow[1,4])

   @ aWindow[1,1]+02,aWindow[1,2]-01 Say Chr(198)
   @ aWindow[1,1]+02,aWindow[1,4]+01 Say Chr(181)

   oNotaVenda:headSep := Chr(205) + Chr(203) + Chr(205)
   oNotaVenda:colSep  := " " + Chr(186) + " "
   oNotaVenda:footSep := Chr(196) + Chr(208) + Chr(196)

   // Criar objetos coluna

   oCol:=TBcolumnNew( "Empresa;  ",;
          {|| If(NfVenda->NfvEmpresa!=Empresa->EpCgc,;
                 Empresa->( DbSeek(NfVenda->NfvEmpresa) ), ) , ;
                 Empresa->EpNomeFant } )
   oCol:Width := 10
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "N§ Nota;fiscal",;
          {|| NfVenda->NfvNum } )
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "N§ Pedido;Venda",;
          {|| NfVenda->NfvPedido } )
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Destinatario;  ",;
      {||;
         If( NfVenda->NfvCliFor!="F",;
             ( Cliente->(DbSeek(NfVenda->NfvCliente)) ,;
             Cliente->ClDescr );
             ,;
             ( Fornece->(DbSeek(NfVenda->NfvCliente)) ,;
             Fornece->FnDescr );
           );
      } )

   oCol:Width := 20
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Data;Emissao",;
          {|| NfVenda->NfvData } )
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Nat.;Ope.",;
          {|| Transform(NfVenda->NfvNatOpe,"@R 9.99") } )
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Modalidade;Faturamento",;
          {|| SayModoFatu(NfVenda->NfvModo) } )
   oNotaVenda:AddColumn(oCol)

   oCol:=TBcolumnNew( "Valor;Nota",;
          {|| Transform(NfVenda->NfvValMerc,"@E 99,999,999.99") } )
   oNotaVenda:AddColumn(oCol)

   @ aWindow[1,3],aWindow[1,2]  say;
   "F3 ANOTA€OES    F8 CONSULTA     F9 PESQUISA     ESC ENCERRA"

   PROCESS

      While (! oNotaVenda:Stabilize())
         nKey := Inkey()
         If nKey <> 0    // Tecla pressionada durante estabilizacao
            Exit         // Abandone estabilizacao p/ processar tecla
         Endif
      End
      If oNotaVenda:Stable
         If oNotaVenda:hitTop .or. oNotaVenda:hitBottom
            Tone(3600,.2) ; Tone(3700,.2)
         Endif
         While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
            If oNotaVenda:Cargo != NIL          // o Slot Contem Algo,
               Eval( oNotaVenda:cargo )         // Execute !
            Endif
         End
      Endif
      If nKey == pESC .or. nKey == pENTER
         Exit
      Endif

      StdKey( oNotaVenda, nKey ) // Controle de Teclagem

      Do Case

         Case nKey == pF3   // Aponta
            Appoint(Alias(),NfVenda->NfvEmpresa,Str(NfVenda->NfvNum),1,"Nota Fiscal Venda")
         Case nKey == pF8   // Zoom
            Adm2c300()
         Case nKey == pF9   // Pesquisa
         Case nKey == pALT_F10
            wMove()
            Exit
      EndCase

   END PROCESS

   Return .f.

