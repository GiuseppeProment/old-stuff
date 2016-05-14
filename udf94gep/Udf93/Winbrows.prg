#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION WINBROWSE(aWin)
	Local sTime := Time()
	TabModal(aTab,nWinPos,nWinTot,.t.)
	While NextKey() = 0
/*
		MouseCShow()
		If MouseBon(2) = 4
			If MouseRow() = aWin[1,1] - 01
				Do Case
				Case MouseCol() == aWin[1,4]-01 ; KeyBoard(Chr(pLEFT_ARROW))
				Case MouseCol() == aWin[1,4]-02 ; KeyBoard(Chr(pRIGHT_ARROW))
				Case MouseCol() == aWin[1,4]-05 ; KeyBoard(Chr(pESC))
				EndCase
			Endif
			If MouseRow() = aWin[1,1] - 01 .and. MouseCol() = aWin[1,4] + 01
				KeyBoard(Chr(pUP_ARROW))
			Endif
			If MouseRow() = aWin[1,3] + 01 .and. MouseCol() = aWin[1,4] + 01
				KeyBoard(Chr(pDOWN_ARROW))
			Endif
		Endif
		If MouseBon(0) == 3
			KeyBoard(Chr(pENTER))
		Endif

		If sTime # Time()
			DevPos(24,69) ; DevOut(sTime := Time(),ColorSet(24,69))
		Endif
*/
	End
// MouseCHide()
	VOID

// ***
// ***
