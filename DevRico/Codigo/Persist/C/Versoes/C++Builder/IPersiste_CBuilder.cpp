//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library BCBMM.LIB to both the DLL project and any
//   EXE projects that use the DLL.  This will change the DLL and its calling
//   EXE's to use the BCBMM.DLL as their memory manager.  In these cases,
//   the file BCBMM.DLL should be deployed along with your DLL.
//
//   To avoid using BCBMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//---------------------------------------------------------------------------

USEUNIT("C:\DevRico\Codigo\Persist\C\Case\Iassccao.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iatrbuto.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Ibroker.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Ibsrvdor.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iclcprss.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iclssmap.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Icolecao.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Icritrio.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Idltsttm.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Idrcftch.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Idtstore.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Idtstrdb.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Idtstrrc.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Ierro.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iknwtype.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Imdfystt.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Impclsst.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Imptrcln.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Insrtstt.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Intfcdor.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Intfcdrb.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iordem.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Ipdtsttm.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iprcmprc.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iprlgcpr.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iprsstid.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iprsstnt.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Iqrysttm.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Istdclco.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Istdgnrc.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Istdsttm.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Istring.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Isttment.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Ivntntfc.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Lststrng.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\template.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Typevnto.cpp");
USEUNIT("c:\devrico\codigo\persist\c\case\Funcoes.cpp");
//USELIB("F:\Ferramentas\CBuilder4\Lib\bcbmm.lib");
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
	return 1;
}
//---------------------------------------------------------------------------