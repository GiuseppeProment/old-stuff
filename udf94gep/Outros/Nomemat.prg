#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "Recoma.ch"
#Include "PTWindow.ch"

#DEFINE EMPRESA_SERVICO "50.996.479"
#DEFINE EMPRESA_VENDA "51.212.348"

MemVar sCorJ,sCorF,sCorT,sCorL,sCorM
MemVar aPict, nTmp
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
// Nome do Material

/*
	 Parametros     : nCodiMat,nTamanho
	 Objetivo       : Devolcer nome do material informado no tamanho solicitado
	 Pre-requisitos : Arquivos EstoAna aberto, pesquisando Arquivos:
							Estoque, TipoMad, e MedMad
	 Retorna        : Descricao do Material no tamanho Solicitado
*/

FUNCTION NOMEMAT(nCodMat,nTamanho)
 Local Ordem := EstoAna->(IndexOrd())
 Local Ordem2:= Estoque->(IndexOrd())
 Local OrdMed:= MedMade->(IndexOrd())
 Local OrdTip:= TipoMad->(IndexOrd())
 Local cDescrMat
 If nTamanho = NIL
	 nTamanho := 50
 Endif
 EstoAna->(DbSetOrder(2)) ; Estoque->(DbSetOrder(1))
 MedMade->(DbSetOrder(1)) ; TipoMad->(DbSetOrder(1))

 // os if's abaixo evitam seeks redundantes caso a funcao seja chamada mais
 // de uma vez sem alteracao do codigo do material

 If nCodMat != EstoAna->EaCodRedu
	 EstoAna->(DbSeek(nCodMat))
 Endif

 If EstoAna->EaCodigo != Estoque->EqCodigo
	 Estoque->(DbSeek(EstoAna->EaCodigo))
 Endif

 If EstoAna->EaCodMad !=  TipoMad->TmCodigo
	 TipoMad->(DbSeek(EstoAna->EaCodMad))
 Endif

 If EstoAna->EaCodMed != MedMade->MmCodigo
	 MedMade->(DbSeek(EstoAna->EaCodMed))
 Endif

 cDescrMat := AllTrim(Estoque->EqDescNor) +" "+;
	 AllTrim(TipoMad->TmDescrNor) +" "+ MontaMedMade()

 If Len(cDescrMat)>nTamanho

		cDescrMat := AllTrim(Estoque->EqDescAbr) +" "+;
		AllTrim(TipoMad->TmDescrAbr) +" "+ MontaMedMade("reduzir")

	 If Len(cDescrMat)>nTamanho
		cDescrMat := Left(cDescrMat,nTamanho)
	 Endif

 Endif

 EstoAna->(DbSetOrder(Ordem))
 Estoque->(DbSetOrder(Ordem2))
 MedMade->(DbSetOrder(OrdMed))
 TipoMad->(DbSetOrder(OrdTip))
 Return(cDescrMat)


