/*
06/04/94

FUNCAO  : Rotina generica de anotacao em documentos
OBJETIVO: Prover e gerenciar anotacoes em quaisquer documentos

Argumentos: <cAlias> -> nome do arquivo de documento
            <cEmpresa> -> Empresa dona do documento
            <cNumDoc>  -> Codigo do documento (em str)
            <nTransacao> -> 0 - cria/edita
                            1 - le
                            2 - apaga
            [<cNomeDoc>]-> opcional, e' o nome do documento para o usuario
                           ex: cAlias="PedServ" (Pedido de Servi‡o)

Exemplo:

BASE DE DADOS: APPOINT.DBF
               APPOINT1.NTX = cAlias+cEmpresa+cNumDoc

PEDVEND 51.348.212 bbbbbb1
PEDVEND 51.348.212 bbbbbb2
PEDVEND 51.348.212 bbbbbb3

PEDSERV 50.996.001 bbbbbb1
PEDSERV 50.996.001 bbbbbb2
PEDSERV 50.996.001 bbbbbb3

CLIENTE            bbbbb11
CLIENTE            bbbbb12
CLIENTE            bbbbb30

FORNEC             bbbbb11
FORNEC             bbbbb12
FORNEC             bbbbb30


MODO DE FUNCIONAMENTO: O arquivo Appoint e' de uso exclusivo desta funcao.

*/

#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "PTWindow.ch"


Function Appoint(cAlias,cEmpresa,cNumDoc,nTransacao,cNomeDoc)

   Local sCorAnt := SetColor()
   Local sAlias  := Alias()

   DEFAULT cNomeDoc to (cAlias)
   DEFAULT cEmpresa to Space(10)
   DEFAULT nTransacao to 0

   // Verificar se o alias esta vazio
   If (cAlias)->(LastRec())==0
      Msg("Nao existe documento registrado")
   else
      BankUse( pDADOS + "Appoint", .f., 0 )

      DbSeek(PadR(cAlias,8)+PadR(cEmpresa,10)+PadR(cNumDoc,10))

      If !Found() .and. nTransacao == 1
         Msg({"Nao Existe Anotacao","para este documento."})
      elseif Found() .and. nTransacao == 2
         Rec_lock(0)
         DbDelete()
         DbUnLock()
      elseif nTransacao == 0 .or. nTransacao==1
         CriaEdita(cAlias,cEmpresa,cNumDoc,nTransacao,cNomeDoc)
      Endif

      Appoint->(DbCloseArea())
      DbSelectArea(sAlias)

   Endif

   VOID



Static Function CriaEdita(cAlias,cEmpresa,cNumDoc,nTransacao,cNomeDoc)

   Local sMemo
   Local lMode
   Local nCursor:=SetCursor()
   Local nlastlin

   If nTransacao == 0
      lMode := .t.
   else
      lMode := .f.
   Endif


   wSet( 02, 05, 23, 75, WhatColor(1), pSBAR, 0, 5,"Anotacao ¯ "+cNomeDoc,pLEFT_JUSTIFIED,,,)

   wOpen()

   If Found()
      sMemo := Appoint->Memo+IdUser()
   else
      sMemo := IdUser()
   Endif

   //Edicao
   If lMode
      @ wMaxRow(),wCol() Say "Ctrl-W Grava       Esc-Abandona" color CorGetSel()
   else
      @ wMaxRow(),wCol() Say "Esc-Encerra" color CorGetSel()
   endif
   @ wMaxRow()-1,wCol() to wMaxRow()-1,wMaxCol()


   // Localizar a ultima linha da string
   nLastLin := MlCount(sMemo,wMaxCol()-wCol())

   SetCursor(2)
   sMemo := MemoEdit(sMemo,wRow(1),wCol(),wMaxRow()-2,wMaxCol(),lMode,,,,nLastLin,0,4,0)
   SetCursor(nCursor)

   If LastKey() != pESC .and. lMode == .t.

      If Confirma("Confirma Gravacao ?")
         If !Found()
            Appoint->(Add_rec(0))
            Appoint->Alias   := cAlias
            Appoint->Empresa := cEmpresa
            Appoint->NumDoc  := cNumDoc
         Else
            Appoint->(Rec_lock(0))
         Endif
         Appoint->Memo := sMemo
         DbUnLock()
      Endif

   Endif

   wClose()

   VOID


Static Function IdUser()
   Return Chr(13)+Chr(10)+;
          PadC(("(-"+Cn_Who()+"-"+Dtoc(Date())+"-"+Time()+"-)"),wWidth(),"=") +;
          Chr(13)+Chr(10)+Chr(13)+Chr(10)


