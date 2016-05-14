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

FUNCTION EXTBXESTQ(nCodMat,nQtd,cHistor,FazEmpenhoToo)
  Local ValorSf,ValorCf,Ordem := EstoAna->(IndexOrd())

  DEFAULT FazEmpenhoToo TO .F.

  MovEstq->(Add_Rec(0))
  EstoAna->(DbSetOrder(2))
  EstoAna->(DbSeek(nCodMat))
  EstoAna->(Rec_Lock(0))
  ValorSf := ( ( EstoAna->EaSdVlSf / EstoAna->EaSdReal ) * nQtd )
  ValorCf := ( ( EstoAna->EaSdVlCf / EstoAna->EaSdReal ) * nQtd )

  MovEstq->MeData     := Date()
  MovEstq->MeCodMat   := nCodMat
  MovEstq->MeDc       := "C"
  MovEstq->MeQtde     := nQtd
  MovEstq->MeHistoric := Upper(cHistor)
  MovEstq->MeValorInd := ValorSf
  MovEstq->MeValFrete := ValorCf
  MovEstq->MeSdEmp    := EstoAna->EaSdEmpenh
  MovEstq->MeSdReal   := EstoAna->EaSdReal
  MovEstq->MeSdIndCf  := EstoAna->EaSdVlCf
  MovEstq->MeSdIndSf  := EstoAna->EaSdVlSf
  MovEstq->MeEmpenho  := FazEmpenhoToo
  MovEstq->MeReal     := .t.

  If  FazEmpenhoToo
      EstoAna->EaSdEmpenh := EstoAna->EaSdEmpenh + nQtd
  Endif

  EstoAna->EaSdReal   := EstoAna->EaSdReal + nQtd
  EstoAna->EaSdVlCf   := EstoAna->EaSdVlCf + ValorCf
  EstoAna->EaSdVlSf   := EstoAna->EaSdVlSf + ValorSf
  EstoAna->(DbSetOrder(Ordem))

  MovEstq->(DbUnLock())
  EstoAna->(DbUnLock())

  VOID

