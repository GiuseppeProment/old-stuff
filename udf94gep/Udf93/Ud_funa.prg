
#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION UD_FUNA(nStatus, nCurr_elem, nRel_Row)
	Private nRequest, nLin, nCol

	// Define status messages.
	IDLE        := 0
	PAST_TOP    := 1
	PAST_END    := 2
	KEY_EXCEPT  := 3
	NO_ITEM     := 4

	 // Define user FUNCTION requests.
	ABORT_SEL   := 0
	MAKE_SEL    := 1
	CONT_SEL    := 2
	GOTO_ITEM   := 3

	// Save screen coordinates.
	nLin := Row()
	nCol := Col()

	// Save latest keystroke.
	KeyStroke := LastKey()
	nRequest   := CONT_SEL
	Do Case
	Case nStatus == NO_ITEM
		// Nothing selectable..abort.
		nRequest := ABORT_SEL
	Case nStatus == KEY_EXCEPT
		// Keystroke exception..process it.
		nRequest := Key_except()
	Case nStatus == PAST_TOP
		// Attempted to go past the top.
		Tone(100, 1)
		KeyBoard Chr(30)        // Ctrl-PgDn
		nRequest := CONT_SEL
	Case nStatus == PAST_END
		// Attempted to go past the end.
		Tone(100, 1)
		KeyBoard Chr(31)        // Ctrl-PgUp
		nRequest := CONT_SEL
	EndCase
	// Restore screen coordinate.
	@ nLin, nCol Say ""
	RETURN(nRequest)

// ***
// ***

FUNCTION KEY_EXCEPT
	Do Case
	Case KeyStroke = 27
		// Esc..abort ACHOICE().
		RETURN ABORT_SEL
	Case KeyStroke = 13
		// Quit with no abort..only RETURN causes selection.
		RETURN MAKE_SEL
	Case KeyStroke = 1
		// Home key..top of list
		KeyBoard Chr(31)        // Ctrl-PgUp
		RETURN CONT_SEL
	Case KeyStroke = 6
		// End key..end of list.
		KeyBoard Chr(30)        // Ctrl-PgDn
		RETURN CONT_SEL
	Case IsData(KeyStroke)
		// nRequest character search.
		RETURN GOTO_ITEM
	EndCase
	RETURN(CONT_SEL)

// ***
// ***

FUNCTION ISDATA(nKey)
	// Determine If a key is xdata suitable for entry in place.
	RETURN (nKey >= 32 .and. nKey < 249 .and. nKey <> 219;
		 .and. Chr(nKey) <> ";")

// ***
// ***
