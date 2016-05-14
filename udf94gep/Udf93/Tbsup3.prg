#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


* EM USO

*****************************   VERSAO ANTIGA ******************************

FUNCTION OptGOTOP(bFilter,ChaveInicio)
	DbSeek(ChaveInicio,.t.)
	While ! eVal(bFilter) .and. !bof() .and. !eof()
		DbSkip()
	End
RETURN NIL

// ***
// ***

FUNCTION OptGOBOTTOM(bFilter,ChaveFim)
	DbSeek(ChaveFim,.t.)
	While ! eVal(bFilter) .and. !bof() .and. !eof()
		DbSkip(-1)
	End
	If Eof()
		DbSkip(-1)
		If !eVal(bFilter)
			DbSkip(+1)
		endif
	endif
RETURN NIL

FUNCTION OptSKIPER(nToJump,bFilter,oObj,ChaveInicio,ChaveFim)
	Static lStartUp := .t.                        // Controla Filtro do TBBrowse()
	Static nRecNumTop,nRecNumBot                  // Registros Inicial e Final

	Local nJumPed := 0                            // Quantos registros foram saltados
	Local nLastRec                                // Ultimo Registro que satisfez a condicao

	If LastKey() <> 0
		If nToJump > 0

			// Avancar Ponteiro
			While nJumPed < nToJump .and. RecNo() <> nRecNumBot

				// Checa se e necessaria a movimentacao
				If (nLastRec := RecNo() ) <> nRecNumBot

					DbSkip()
					While ! eVal(bFilter)  .and. !Eof() .and. !Bof()
						DbSkip()
					End

				Endif
				// Caso Registro nao satisfaca a condicao ou seja fim de
				// arquivo, retrocede ponteiro e sai
				If ! eVal(bFilter) .or. Eof()
					DbGoTo(nLastRec)
					Exit
				Endif
				nJumped++
			End
		Elseif nToJump < 0
			// Retroceder Ponteiro
			While nJumPed > nToJump .and. RecNo() <> nRecNumTop

				If (nLastRec := Recn()) <> nRecNumTop

					DbSkip(-1)
					While ! eVal(bFilter)  .and. !Eof() .and. !Bof()
						DbSkip(-1)
					End
				Endif

				// Caso Registro nao satisfaca a condicao ou seja fim de
				// arquivo, retrocede ponteiro e sai
				If ! eVal(bFilter) .or. Bof()
					DbGoTo(nLastRec)
					Exit
				Endif
				nJumped--
			End
		Else
			If bFilter = NIL                        // Para utilizar o Skipper p/ Mais de Uma Fonte
				lStartUp := .t.                      // de Dados
				RETURN 0
			Endif

			If lStartUp
				lStartUp := .f.

				// Posiciona Ponteiro no Inicio do Filtro
				DbSeek(ChaveInicio,.t.)
				While ! eVal(bFilter) .and. !bof() .and. !eof()
					DbSkip()
				End
				nRecNumTop := RecNo()

				// Posiciona Ponteiro no Fim do Filtro
				DbSeek(ChaveFim,.t.)
				While ! eVal(bFilter) .and. !bof() .and. !eof()
					DbSkip(-1)
				End
				If Eof()
					DbSkip(-1)
					If !eVal(bFilter)
						DbSkip(+1)
					endif
				endif
				nRecNumBot := RecNo()
				DbGoTo(nRecNumBot)                   // Fim do Filtro
				oObj:GoTop()
			Else
				DbSkip(0)
			Endif
		Endif
	Endif
RETURN(nJumped)



/*

***************   VERSAO MAIS ANTIGA AINDA ************************************

FUNCTION OptGOTOP(bFilter,ChaveInicio)
	DbSeek(ChaveInicio,.t.)
	While ! eVal(bFilter) .and. ! Eof()
		DbSkip()
	End
*  If ! Empty(nUltRec) // Voltar ao registro anterior
*     DbGoTo(nUltRec)
*  Endif
	RETURN NIL

// ***
// ***

FUNCTION OptGOBOTTOM(bFilter,ChaveFim)
	DbSeek(ChaveFim,.t.)
	While ! eVal(bFilter)
		DbSkip(-1)
		If Bof() ; Exit ; Endif
	End
	RETURN NIL

FUNCTION OptSKIPER(nToJump,bFilter,oObj,ChaveInicio,ChaveFim)
	Static lStartUp := .t. // Controla Filtro do TBBrowse()
	Static nRecNumTop,nRecNumBot // Registros Inicial e Final

	Local nJumPed := 0     // Quantos registros foram saltados
	Local nLastRec         // Ultimo Registro que satisfez a condicao

	If LastKey() <> 0
		If nToJump > 0

			// Avancar Ponteiro
			While nJumPed < nToJump .and. RecNo() <> nRecNumBot

				// Checa se e necessaria a movimentacao
				If (nLastRec := RecNo() ) <> nRecNumBot

					DbSkip()
					While ! eVal(bFilter) .and. ! Eof()
						DbSkip()
					End

				Endif
				// Caso Registro nao satisfaca a condicao ou seja fim de
				// arquivo, retrocede ponteiro e sai
				If ! eVal(bFilter) .or. Eof()
					DbGoTo(nLastRec)
					Exit
				Endif
				nJumped++
			End
*        nWinPos := nWinPos + Abs(nJumped)
		Elseif nToJump < 0
			// Retroceder Ponteiro
			While nJumPed > nToJump .and. RecNo() <> nRecNumTop

				If (nLastRec := Recn()) <> nRecNumTop

					DbSkip(-1)
					While ! eVal(bFilter)
						DbSkip(-1)
						If Bof() ; Exit ; Endif
					End
				Endif

				// Caso Registro nao satisfaca a condicao ou seja fim de
				// arquivo, retrocede ponteiro e sai
				If ! eVal(bFilter) .or. Bof()
					DbGoTo(nLastRec)
					Exit
				Endif
				nJumped--
			End
*        nWinPos := nWinPos - Abs(nJumped)
		Else
			If bFilter = NIL   // Para utilizar o Skipper p/ Mais de Uma Fonte
				lStartUp := .t. // de Dados
				RETURN 0
			Endif

			If lStartUp
				lStartUp := .f.

				// Posiciona Ponteiro no Inicio do Filtro
				DbSeek(ChaveInicio,.t.)
				While ! eVal(bFilter) .and. ! Eof()
					DbSkip()
				End
				nRecNumTop := RecNo()

				// Posiciona Ponteiro no Fim do Filtro
				DbSeek(ChaveFim,.t.)
				While ! eVal(bFilter)
					DbSkip(-1)
					If Bof() ; Exit ; Endif
				End
				nRecNumBot := RecNo()
				DbGoTo(nRecNumBot) // Fim do Filtro
				oObj:GoTop()
			Else
				DbSkip(0)
			Endif
		Endif
	Endif
	RETURN(nJumped)

*/





/*
   ********************** VERSAO A APERFEICOAR **********************
   ERRO DETECTADO: o bloco de validacao tem condicoes de filtro nao
                   indexado.
FUNCTION OptGOTOP(bFilter,ChaveInicio)
	DbSeek(ChaveInicio,.t.)
    If ! eVal(bFilter) .and. !bof() .and. !eof()
      DbGoBottom()
      DbSkip()
    End
    RETURN NIL

// ***
// ***

FUNCTION OptGOBOTTOM(bFilter,ChaveFim)
    DbSeek(ChaveFim,.t.)
    If ! eVal(bFilter) .and. !bof() .and. !eof()
      DbSkip(-1)
      If ! eVal(bFilter) .and. !bof() .and. !eof()
         DbGoBottom()
         DbSkip()
      Endif
    End
    If Eof()
       DbSkip(-1)
       If !eVal(bFilter)
         DbSkip(+1)
       endif
    endif
	RETURN NIL

FUNCTION OptSKIPER(nToJump,bFilter,oObj,ChaveInicio,ChaveFim)
	Static lStartUp := .t. // Controla Filtro do TBBrowse()
	Static nRecNumTop,nRecNumBot // Registros Inicial e Final

	Local nJumPed := 0     // Quantos registros foram saltados
	Local nLastRec         // Ultimo Registro que satisfez a condicao

	If LastKey() <> 0
		If nToJump > 0

			// Avancar Ponteiro
			While nJumPed < nToJump .and. RecNo() <> nRecNumBot

				// Checa se e necessaria a movimentacao
				If (nLastRec := RecNo() ) <> nRecNumBot

					DbSkip()

				Endif
				// Caso Registro nao satisfaca a condicao ou seja fim de
				// arquivo, retrocede ponteiro e sai
				If ! eVal(bFilter) .or. Eof()
					DbGoTo(nLastRec)
					Exit
				Endif
				nJumped++
			End
		Elseif nToJump < 0
			// Retroceder Ponteiro
			While nJumPed > nToJump .and. RecNo() <> nRecNumTop

				If (nLastRec := Recn()) <> nRecNumTop

					DbSkip(-1)

                Endif

				// Caso Registro nao satisfaca a condicao ou seja fim de
				// arquivo, retrocede ponteiro e sai
				If ! eVal(bFilter) .or. Bof()
					DbGoTo(nLastRec)
					Exit
				Endif
				nJumped--
			End
		Else
			If bFilter = NIL   // Para utilizar o Skipper p/ Mais de Uma Fonte
				lStartUp := .t. // de Dados
				RETURN 0
			Endif

			If lStartUp
				lStartUp := .f.

				// Posiciona Ponteiro no Inicio do Filtro
				DbSeek(ChaveInicio,.t.)
*               While ! eVal(bFilter) .and. !bof() .and. !eof()
*                 DbSkip()
*               End
				nRecNumTop := RecNo()

				// Posiciona Ponteiro no Fim do Filtro
				DbSeek(ChaveFim,.t.)
                If ! eVal(bFilter) .and. !bof() .and. !eof()
					DbSkip(-1)
				End
                If Eof()
                   DbSkip(-1)
                   If !eVal(bFilter)
                     DbSkip(+1)
                   endif
                endif
				nRecNumBot := RecNo()
				DbGoTo(nRecNumBot) // Fim do Filtro
				oObj:GoTop()
			Else
				DbSkip(0)
			Endif
		Endif
	Endif
	RETURN(nJumped)

*/

