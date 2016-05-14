/*
  Funcao especial para abertura de arquivos e indices automaticamente

  O nome dos indices devem ser o nome do DBF + o numero sequencial

	Pass the following parameters
	  1. Character - name of the .DBF file to open
	  2. Logical - mode of open (exclusive/.NOT. exclusive)
	  3. Numeric - seconds to wait (0 = wait forever)

	Example:
	  If ! Bankuse("Accounts", .T., 5)
		  ? "Account file not available"
	  Endif
*/
FUNCTION BANKUSE(sFile,lUse,nWait,sAlias)
	Local aNtx := {},lForever,nCount,sName

	lForever := (nWait == 0)
	While (lForever .or. nWait > 0)
		If lUse // Exclusive
			If sAlias != NIL
				Use (sFile) Exclusive New Alias (sAlias)
			Else
				Use (sFile) Exclusive New
			Endif
		Else    // Shared
			If sAlias != NIL
				Use (sFile) Shared New Alias (sAlias)
			Else
				Use (sFile) Shared New
			Endif
		Endif

		If ! NetErr()  // Use Succeeds
			// Identificar os Indices
			For nCount := 1 to 16
				// Para Chegar no Maximo em 15
				If nCount > 9
                 // sName := sFile+Chr(nCount+55)+".Ntx"
                    sName := sFile+Chr(nCount+55)+IndexExt()
				Else
                 // sName := sFile+lTrim(Str(nCount))+".Ntx"
                    sName := sFile+lTrim(Str(nCount))+IndexExt()
				Endif
				If File(sName)
					Aadd(aNtx,sName)
				Else
					nCount--
					Exit
				Endif
			Next
			// Abrir os Indices
			aEval(aNtx, { |aArray| DbSetIndex(aArray) } )
			RETURN(.t.)
		Endif
		Inkey(1) // Wait 1 Second
		nWait--  
	End
	RETURN(.f.) // Use Fails

// ***
// ***
