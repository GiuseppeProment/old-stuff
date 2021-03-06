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

FUNCTION DESEMPENHAESTOQUE(nCodMat,nQtd,cHistor)
   Local Ordem := EstoAna->(IndexOrd())

   If nCodMat != 0
      MovEstq->(Add_Rec(0))
      EstoAna->(DbSetOrder(2))
      EstoAna->(DbSeek(nCodMat))
      EstoAna->(Rec_Lock(0))

      MovEstq->MeData     := Date()
      MovEstq->MeCodMat   := nCodMat
      MovEstq->MeDc       := "C"
      MovEstq->MeQtde     := nQtd
      MovEstq->MeHistoric := "DESEMPENHO "+Upper(cHistor)
      MovEstq->MeSdEmp    := EstoAna->EaSdEmpenh
      MovEstq->MeSdReal   := EstoAna->EaSdReal
      MovEstq->MeSdIndCf  := EstoAna->EaSdVlCf
      MovEstq->MeSdIndSf  := EstoAna->EaSdVlSf
      MovEstq->MeEmpenho  := .t.

      EstoAna->(Rec_Lock(0))
      EstoAna->EaSdEmpenh := EstoAna->EaSdEmpenh + nQtd
      EstoAna->(DbSetOrder(Ordem))

      MovEstq->(DbUnLock())
      EstoAna->(DbUnLock())

   Endif

   VOID

