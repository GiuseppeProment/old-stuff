static ident := 0
static trace := .f.
function rastroIN()
   if trace
   outstd(space(ident)+;
      "+"+methodName(1)+str(procline(1))+chr(13)+chr(10))
   ident+=2
   endif
return nil
function rastroOUT()
   if trace
   ident-=2
   outstd(space(ident)+;
   "-"+methodName(1)+str(procline(1))+chr(13)+chr(10))
   endif
return nil
function __trace(value)
   trace := value
return nil
/*
+Class:method (line)
 +Class:method
  +Class:method
  -Class:method
 -Class:method
-Class:method
*/

/*�� Function ��������������������������������������������������������������Ŀ
  �         Name: anyToStr()            Docs: nem tem...                     �
  �  Description: Converte qualquer tipo clipper p/ string                   �
  �       Author: Giuseppe Enrico Proment Jr                                 �
  � Date created: 11/12/98              Date updated: �11/12/98              �
  � Time created: 21:47:29              Time updated: �21:47:29              �
  �    Copyright: Giuseppe (c)                                               �
  �    E-Mail to:  gPromen@Ibm.Net                                     �
  ��������������������������������������������������������������������������Ĵ
  �    Arguments: None                                                       �
  � Return Value: string                                                     �
  �     See Also:                                                            �
  ����������������������������������������������������������������������������*/
function I_anyToStr(AnyData)
   local cRet
   local cType := ValType(AnyData)
   do case
      case cType == 'C'
         cRet := AnyData
      case cType == 'D'
         cRet := dtos(AnyData)
      case cType == 'N'
         cRet := Ltrim(str(AnyData))
      case cType == 'L'
         cRet := iif(AnyData,".T.",".F.")
      otherwise
         Alert("funcao anyToStr: dado invalido")
         quit
   endcase
return cRet


