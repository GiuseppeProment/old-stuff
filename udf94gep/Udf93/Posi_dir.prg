#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
	Parametros     : Nil
	Objetivo       : Localizar os direitos do usuario no programa
	Excessao       : Se nao achar assume DEFAULT
	Pre-requisitos : Arquivo Rights deve estar aberto, funcao principal deve iniciar c/ M_
*/
FUNCTION POSI_DIREITOS(cMainPrefix)
    // Localiza a ultima funcao c/ prefixo Main
	Local sMain,nCount := 0
	Repeat
    Until ( cMainPrefix $ (sMain := ProcName(nCount++)))
	If sMain != NIL
		If ! (Rights->(DbSeek(SubStr(Cn_Who()+Space(15),1,15)+SubStr(sMain+Space(08),1,8))))
			If ! (Rights->(DbSeek(SubStr("DEFAULT"+Space(15),1,15))))
				// Rights->(DbGoBottom()) ; DbSkip(1)
			Endif
		Endif
	Else
		SetPos(0,0); OutErr("Erro em Direitos Funcao principal Nao Localizada (ADM)")
	Endif
	VOID

