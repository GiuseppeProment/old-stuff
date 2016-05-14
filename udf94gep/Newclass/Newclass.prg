
#Define pPESQUISA_ATIVA 1
#Define pARGUMENTO      2
#Define pLINHA          3
#Define pCOLUNA         4
#Define pLEN_ARGUMENTO  5
#Define pUSA_INDICE_TMP 6
#Define pALIAS          7
#Define pORDER          8
#Define pRECORD         9
#Define pFILE_TMP      10
#Define pFILTRO        11

#Include "Paths.ch"

Function PesquisaNew(aPesquisa) // Cria Objeto pesquisa ou zera se foi mandado
   If aPesquisa != Nil
      aPesquisa[ pPESQUISA_ATIVA ] := .f.
      aPesquisa[ pARGUMENTO      ] := " "
      aPesquisa[ pLINHA          ] := 0
      aPesquisa[ pCOLUNA         ] := 0
      aPesquisa[ pLEN_ARGUMENTO  ] := 0
      aPesquisa[ pUSA_INDICE_TMP ] := .f.
      aPesquisa[ pALIAS          ] := " "
      aPesquisa[ pORDER          ] := 0
      aPesquisa[ pRECORD         ] := 0
      aPesquisa[ pFILE_TMP       ] := " "
      aPesquisa[ pFILTRO         ] := {}
   Endif
   Return {.f.," ",0,0,0,.f.," ",0,0," ",{}}


Function PesquisaIsOn(aPesquisa)
   Return aPesquisa[pPESQUISA_ATIVA]

Function PesquisaRowColLen(aPesquisa,nLin,nCol,nLen)
   If nLin == Nil; nLin := 0; Endif
   If nCol == Nil; nCol := 0; Endif
   If nLen == Nil; nLen := 75; Endif
   aPesquisa[pLINHA ] := nLin
   aPesquisa[pCOLUNA] := nCol
   aPesquisa[pLEN_ARGUMENTO] := nLen
   Return Nil

Function PesquisaDisplay(aPesquisa)
   If aPesquisa[pPESQUISA_ATIVA]
      @ aPesquisa[pLINHA], aPesquisa[pCOLUNA] Say;
        Left("FILTRO PESQUISA : "+;
        AllTrim(aPesquisa[pARGUMENTO])+;
        If( !Empty( aPesquisa[pFILTRO] )," < ... Alt_F > ",""),;
        aPesquisa[pLEN_ARGUMENTO] )
   EndIf
   Return Nil

Function PesquisaCls(aPesquisa)
   If aPesquisa[pPESQUISA_ATIVA]
      @ aPesquisa[pLINHA], aPesquisa[pCOLUNA] Say;
        Space( aPesquisa[pLEN_ARGUMENTO] )
   endif
   Return Nil

Function PesquisaON(aPesquisa,cArgumento)
   aPesquisa[ pPESQUISA_ATIVA ] := .T.
   aPesquisa[ pARGUMENTO ] := cArgumento
   Return Nil

Function PesquisaOFF(aPesquisa)
   aPesquisa[ pPESQUISA_ATIVA ] := .F.
   aPesquisa[ pARGUMENTO      ] := " "
   aPesquisa[ pUSA_INDICE_TMP ] := .f.
   aPesquisa[ pALIAS          ] := " "
   aPesquisa[ pORDER          ] := 0
   aPesquisa[ pRECORD         ] := 0
   aPesquisa[ pFILE_TMP       ] := " "
   aPesquisa[ pFILTRO         ] := {}
   Return Nil

Function PesquisaAddFiltro(aPesquisa,cFiltro)
   If aPesquisa[ pPESQUISA_ATIVA ]
      AADD(aPesquisa[ pFILTRO ] , cFiltro)
   EndIf
   Return Nil

Function PesquisaVerFiltro(aPesquisa,cFiltro)
   If aPesquisa[ pPESQUISA_ATIVA ]
      If !Empty(aPesquisa[ pFILTRO ])
         Menu_ver2("Filtro de Pesquisa",aPesquisa[ pFILTRO ])
      else
         Msg({"Nenhuma condicao de filtragem",;
              "foi estabelecida."})
      endif
   else
      Msg("Nenhuma Pesquisa ativa")
   endIf
   Return Nil

Function PesquisaNtxTmp(aPesquisa) // prepara-se para trabalhar com indice temporario
   If !aPesquisa[ pPESQUISA_ATIVA ]
      Alert("Erro Metodo PesquisaNtxTmp, objeto nao ativo")
   Endif

   aPesquisa[ pUSA_INDICE_TMP ] := .T.
   aPesquisa[ pALIAS          ] := Alias()
   aPesquisa[ pORDER          ] := IndexOrd()
   aPesquisa[ pRECORD         ] := RecNo()
   aPesquisa[ pFILE_TMP       ] := NomeTemp()

   Return Nil


Function PesquisaNomeTmp(aPesquisa)
   Return aPesquisa[ pFILE_TMP ]


/*
   PesquisaZap, desfaz a pesquisa e reposiciona a fonte no estado original
   incluindo o registro em que estava antes da pesquisa
*/

Function PesquisaZap(aPesquisa)

   If aPesquisa[pPESQUISA_ATIVA]

      If aPesquisa[ pUSA_INDICE_TMP ]

         ( aPesquisa[ pALIAS ] )->(DbCloseArea())

         fErase(aPesquisa[ pFILE_TMP ] )

         BankUse(pDADOS+ aPesquisa[ pALIAS ] ,.f.,0)

         ( aPesquisa[ pALIAS ] )->(DbSetOrder( aPesquisa[ pORDER ]  ))
         ( aPesquisa[ pALIAS ] )->(DbGoTo( aPesquisa[ pRECORD ]  ))

         DbSelectArea( aPesquisa[ pALIAS ] )

      Endif

      // Cls da pesquisa
      PesquisaCls(aPesquisa)

      // desativa a pesquisa
      PesquisaOFF(aPesquisa)

   endif

   Return Nil

/*
   PesquisaExit, desfaz a pesquisa e reposiciona a fonte no estado original
   porem mantem o registro corrente da pesquisa
*/

Function PesquisaExit(aPesquisa)
   Local nRecord

   If aPesquisa[pPESQUISA_ATIVA]

      If aPesquisa[ pUSA_INDICE_TMP ]

         nRecord := ( aPesquisa[ pALIAS ] )->( RecNo() )

         ( aPesquisa[ pALIAS ] )->(DbCloseArea())

         fErase(aPesquisa[ pFILE_TMP ] )

         BankUse(pDADOS+ aPesquisa[ pALIAS ] ,.f.,0)

         ( aPesquisa[ pALIAS ] )->(DbSetOrder( aPesquisa[ pORDER ]  ))

         ( aPesquisa[ pALIAS ] )->(DbGoTo( nRecord ))

         DbSelectArea( aPesquisa[ pALIAS ] )

      Endif

      // Cls da pesquisa
      PesquisaCls(aPesquisa)

      // desativa a pesquisa
      PesquisaOFF(aPesquisa)

   endif

   Return Nil


