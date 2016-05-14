#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  Fil_Lock(nWait)
  Tem a finalidade de bloquear um arquivo que ja foi aberto
  nWait - Numero de Tentativas ( nWait = 0  Tenta ate Conseguir)
*/
FUNCTION FIL_LOCK(nWait)
	Local lForever

	If fLock()
		RETURN(.t.) // Locked
	Endif

	lForever := (nWait == 0)
	While (lForever .or. nWait > 0)
		Inkey(.5)   // Wait 1/2 Second
		nWait -= .5
		If fLock()
			RETURN(.t.) // Locked
		Endif
	End
	RETURN(.f.) // not locked

// ***
// ***

/*
  Rec_Lock(nWait)
  Tem a finalidade de bloquear um registro
  nWait - Numero de Tentativas ( nWait = 0  Tenta ate Conseguir)
*/
FUNCTION REC_LOCK(nWait)
	Local lForever

	If rLock()
		RETURN(.t.) // Locked
	Endif

	lForever := (nWait == 0)
	While (lForever .or. nWait > 0)
		If rLock()
			RETURN(.t.) // Locked
		Endif

		Inkey(.5)   // wait 1/2 second
		nWait -= .5
	End
	RETURN(.f.) // not locked

// ***
// ***

/*
  Rec_Lock(nWait)
  Tem a finalidade de adicionar um registro em branco
  nWait - Numero de Tentativas ( nWait = 0  Tenta ate Conseguir)
*/
FUNCTION ADD_REC(nWait)
	Local lForever

	Append Blank
	If ! NetErr()
		RETURN(.t.)
	Endif

	lForever := (nWait == 0)
	While (lForever .or. nWait > 0)
		Append Blank
		If ! NetErr()
			RETURN(.t.)
		Endif
		Inkey(.5)  // Wait 1/2 second
		nWait -= .5
	End
	RETURN(.f.) // not locked

// ***
// ***


