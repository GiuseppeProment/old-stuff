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

/*ÚÄ Function ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
  ³         Name: anyToStr()            Docs: nem tem...                     ³
  ³  Description: Converte qualquer tipo clipper p/ string                   ³
  ³       Author: Giuseppe Enrico Proment Jr                                 ³
  ³ Date created: 11/12/98              Date updated: ş11/12/98              ³
  ³ Time created: 21:47:29              Time updated: ş21:47:29              ³
  ³    Copyright: Giuseppe (c)                                               ³
  ³    E-Mail to:  gPromen@Ibm.Net                                     ³
  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
  ³    Arguments: None                                                       ³
  ³ Return Value: string                                                     ³
  ³     See Also:                                                            ³
  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ*/
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


