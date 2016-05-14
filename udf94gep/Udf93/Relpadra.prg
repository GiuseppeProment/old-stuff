#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000



/*

Funcao..............: RelatorioPadrao
Objetivo............: Emite um relatorio do objeto enviado como argumento
Finalidade..........: Relatorio de seguranca (Quebra Galho)
Observacao..........: pode ser usado para entidades que raramente precisa-
							 rao de impressao (indices economicos, etc...)

Sugestao de Utilizacao
----------------------

Nas teclas de manipulacao do objeto use

	Case nKey == pALT_I
		RelatorioPadrao(oObjeto,"Titulo da Entidade")

Aperfei‡oamento em Jul/94
-------------------------

se tamanho > 80 entao comprime
se possui quebras de cabecalho (;) faz a quebra
faz quebra de pagina com cabecalho em todas as paginas

*/

FUNCTION RelatorioPadrao(oObj,sTit)

	 Local n
     Local nPag := 0
     Local nLargura := MedeLargura(oObj)

      If confirma({"Atencao! Iniciarei a impressao onde",;
                   "voce parou o cursor ok. Deseja Imprimir?"})

         Set Device to Printer

         @ 0,0 SAY CHR(27)+CHR(79)

         Set Device to Screen

        *oObj:GoTop()

         Do  While !oObj:Stabilize(); Enddo

         Repeat
            Set Device to Printer
            If Prow()>60 .or. nPag == 0
               RelPadCabec(oObj,sTit,++nPag,nLargura)
            endif
            For n:= 1 to oObj:ColCount
               DevPos(Prow(),Pcol())
               DevOut( PADR( Eval( oObj:GetColumn(n):Block),oObj:ColWidth(n)+3 ) )
            Next
            DevPos(Prow()+1,0)
            Set Device to Screen
            oObj:Down()
            Do  While !oObj:Stabilize(); Enddo
         Until oObj:HitBottom

         If nLargura > 80
            Set Device to Printer
            p_Conf(p_Condens(.f.))
            Set Device to Screen
         Endif

         Eject

      EndIf

      VOID

Static Function RelPadCabec(oObj,sTit,nPag,nLargura)
   Local n,m,cLin
   MasterHead(sTit,"Relatorio Padrao",nPag)
   If nLargura > 80
      p_Conf(p_Condens(.t.))
   Endif
   For m:= 1 to 3 // 3 linhas no maximo
      cLin := ""
      For n:= 1 to oObj:ColCount
         cLin += PADC( GetElemento( oObj:GetColumn(n):Heading, m ) ,oObj:ColWidth(n)+3 )
      Next
      If !Empty(cLin)
         DevOut(cLin)
         DevPos(Prow()+1,0)
      Endif
   Next m
   DevPos(Prow()+1,0)
   VOID

Static Function MedeLargura(oObj)
   Local n,nLargura:=0
   For n:= 1 to oObj:ColCount
      nLargura += oObj:ColWidth(n)+3
   Next
   Return nLargura

Static Function GetElemento( cString, m)
   Local aHead:={}
   Local cAux :=""
   Local cRet
   Local n
   For n:=1 to len(cString)
      If Substr(cString,n,1)==";"
         aadd(aHead,cAux)
         cAux := ""
      Else
         cAux += Substr(cString,n,1)
      Endif
   Next n
   aadd(aHead,cAux)
   If len(aHead) >= m
      cRet := aHead[m]
   else
      cRet := " "
   endif
   Return cRet




