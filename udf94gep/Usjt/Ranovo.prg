
/*ÚÄ Function ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
  ³         Name: RANOVO                Docs: Documentador                   ³
  ³       Author: Giuseppe Enrico Proment Jr.                                ³
  ³ Date created: 03-17-95              Date updated: þ03-17-95              ³
  ³ Time created: 03:46:57pm            Time updated: þ03:46:57pm            ³
  ³    Copyright: Universidade Sao Judas Tadeu                               ³
  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
  ³  Description: Devolve o RA novo . se nao existir devolve o velho         ³
  ³                                                                          ³
  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
  ³    Arguments: nRA                                                        ³
  ³ Return Value: RANOVO                                                     ³
  ³     See Also: RAVELHO()                                                  ³
  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ*/
FUNCTION RANOVO(nRA)
   Local nOrder:=Ralunos->(IndexOrd())
   Local nRaRet
   Ralunos->(DbSetOrder(1))
   If Ralunos->(DbSeek(nRA))
      If Empty(nRaRet:=Ralunos->Al_Codigo)
         nRaRet := Ralunos->Al_CodVelh
      Endif
   Else
      Ralunos->(DbSetOrder(2))
      If Ralunos->(DbSeek(nRa))
         If Empty(nRaRet:=Ralunos->Al_Codigo)
            nRaRet := Ralunos->Al_CodVelh
         Endif
      Else
         OutErr("RANovo() => RA recebido nao existe em Ralunos",nRA)
         Inkey(0)
         Quit
      Endif
   Endif
Return nRaRet


