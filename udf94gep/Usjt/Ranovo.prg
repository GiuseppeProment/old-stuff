
/*旼 Function 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
  �         Name: RANOVO                Docs: Documentador                   �
  �       Author: Giuseppe Enrico Proment Jr.                                �
  � Date created: 03-17-95              Date updated: �03-17-95              �
  � Time created: 03:46:57pm            Time updated: �03:46:57pm            �
  �    Copyright: Universidade Sao Judas Tadeu                               �
  쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴캑
  �  Description: Devolve o RA novo . se nao existir devolve o velho         �
  �                                                                          �
  쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴캑
  �    Arguments: nRA                                                        �
  � Return Value: RANOVO                                                     �
  �     See Also: RAVELHO()                                                  �
  읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸*/
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


