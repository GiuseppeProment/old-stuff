#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


Function SomaDiaUtil(dData,nDias)
Local nVarDias := 0
While nVarDias != nDias
   dData += 1
   If Dow(dData)!= 7 .and. Dow(dData)!=1  // exclui 6-sabado e 7-domingo
      If !IsFeriado(dData)
         nVardias++
      Endif
   Endif
Enddo
Return dData

Function IsFeriado(dData)
   Local lRet
   Do Case
      Case Month(dData)==1 .and. Day(dData)==1  // ano novo
         lRet := .t.
      Case Month(dData)==5 .and. Day(dData)==1  // dia do trabalho
         lRet := .t.
      Case Month(dData)==9 .and. Day(dData)==7  // independencia
         lRet := .t.
      Case Month(dData)==11.and. Day(dData)==2  // finados
         lRet := .t.
      Case Month(dData)==11.and. Day(dData)==15 // proclamacao da republica
         lRet := .t.
      Case Month(dData)==12 .and. Day(dData)==25 // natal
         lRet := .t.
      Otherwise
         lRet := .f.
   EndCase

   Return lRet

