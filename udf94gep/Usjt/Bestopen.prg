#Include "PtVerbs.ch"

FUNCTION BestOpen(sFile,lShared,nWait,lReadOnly,aNtx,sAlias)
   Local lForever,nCount,sName

   DEFAULT aNtx   TO {}

   sFile := AllTrim(sFile)

   lForever := (nWait == 0)
   While (lForever .or. nWait > 0)

      DbUseArea(.t.,,sFile,sAlias,lShared,lReadOnly)

      If ! NetErr()                              // Use Succeeds
         // Identificar os Indices
         If Empty(aNtx)
            For nCount := 1 to 16
               // Para Chegar no Maximo em 15
               If nCount > 9
                  sName := sFile+Chr(nCount+55)+IndexExt()
               Else
                  sName := sFile+lTrim(Str(nCount))+IndexExt()
               Endif
               If File(sName)
                  Aadd(aNtx,sName)
               Else
                  nCount--
                  Exit
               Endif
            Next
         EndIf
         // Abrir os Indices
         aEval(aNtx, { |aArray| DbSetIndex(aArray) } )
         RETURN(.t.)
      Endif
      Inkey(1)                                   // Wait 1 Second
      nWait--
   End
RETURN(.f.)                                      // Use Fails
