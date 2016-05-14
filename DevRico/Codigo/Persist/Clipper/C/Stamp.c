/*�� Clipper Header ��������������������������������������������������������Ŀ
  �    File Name: STAMP.C                                                    �
  �  Description: Time Stamp by                                              �
  �       Author: Giuseppe Enrico Proment Jr                                 �
  � Date created: 27/11/98              Date updated: �27/11/98              �
  � Time created: 15:18:32              Time updated: �15:18:32              �
  �    Copyright: 1998 by Giuseppe (c)                                       �
  �    E-Mail to:  gPromen@Ibm.Net                                     �
  ����������������������������������������������������������������������������*/

#include "clipdefs.h"
#include "extend.api"

CLIPPER getStamp(void)
{
  struct divide
  {
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
  } ;

  union  uniao
  {
    unsigned long int receive;
    struct divide dividido;
  } anom;

  char buffer[4];
  time(&anom.receive);
  /*ltoa(tempo,buffer,10);*/
  buffer[0] = anom.dividido.c1;
  buffer[1] = anom.dividido.c2;
  buffer[2] = anom.dividido.c3;
  buffer[3] = anom.dividido.c4;
  /*_retclen( buffer ,4 );*/
  _retnl( anom.receive );
  return;
}

CLIPPER sizeLong(void)
{
  _retni( sizeof(long int) );
  return;
}

