#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  Equaliza(sWord,nTam)
  Esta funcao tem por objetivo equalizar um texto dentro de
  um limite pre-determinado
  sWord - String a ser equalizada
  nTam  - Limite da equalizacao
*/
FUNCTION EQUALIZA(sWord,nTam)
    Local nTam1 ,nCount
    sWord := AllTrim(sWord)
    nTam1 := Len(sWord)
    If " " $ sWord
         Do While len(sWord) < nTam
            For nCount := nTam1 to 1 Step -1
               If Len(sWord) < nTam
                  If Empty(SubStr(sWord,nCount,1))
                      sWord := Stuff(sWord,nCount,0," ")
                  Endif
               Else
                  Exit
               Endif
            Next
            nTam1 := Len(sWord)
         Enddo
    else
         PadR(sWord,nTam)
    endif
	RETURN(sWord)

// ***
// ***

