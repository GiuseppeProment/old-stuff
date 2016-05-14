#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
  Funcoes de Validacao de Direitos, Necessita do Arquivo Rights Aberto
*/

FUNCTION PODE_ALTERAR(lMsg)
	Local lRet := "A" $ (Rights->Us_Rights)
    DEFAULT lMsg to .t.
    If ! lRet
      If lMsg
         Msg("Voce Nao Tem Direito de Alterar Nesta Opcao")
      Endif
    Endif
	RETURN(lRet)

// ***
// ***

FUNCTION PODE_CONSULTAR
	Local lRet := "C" $ (Rights->Us_Rights)
	If ! lRet ; Msg("Voce Nao Tem Direito de Consultar Nesta Opcao") ; Endif
	RETURN(lRet)

// ***
// ***

FUNCTION PODE_EXCLUIR
	Local lRet := "E" $ (Rights->Us_Rights)
	If ! lRet ; Msg("Voce Nao Tem Direito de Excluir Nesta Opcao") ; Endif
	RETURN(lRet)

// ***
// ***

FUNCTION PODE_INCLUIR
	Local lRet := "I" $ (Rights->Us_Rights)
	If ! lRet ; Msg("Voce Nao Tem Direito de Incluir Nesta Opcao") ; Endif
	RETURN(lRet)

