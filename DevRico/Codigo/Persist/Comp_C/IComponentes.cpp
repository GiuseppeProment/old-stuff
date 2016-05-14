//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("IComponentes.res");
USEUNIT("..\C\CASE\Idtstrdb.cpp");
USEUNIT("..\C\CASE\Iqrysttm.cpp");
USEUNIT("..\C\CASE\Iprsstid.cpp");
USEUNIT("..\C\CASE\Funcoes.cpp");
USEUNIT("..\C\CASE\Idtstrrc.cpp");
USEUNIT("..\C\CASE\Insrtstt.cpp");
USEUNIT("..\C\CASE\Ibroker.cpp");
USEUNIT("..\C\CASE\Iprsstnt.cpp");
USEUNIT("..\C\CASE\Imptrcln.cpp");
USEUNIT("..\C\CASE\CORA_B.cpp");
USEUNIT("..\C\CASE\Istring.cpp");
USEUNIT("..\C\CASE\Isttment.cpp");
USEUNIT("..\C\CASE\Iclcprss.cpp");
USEUNIT("..\C\CASE\Iclssmap.cpp");
USEUNIT("..\C\CASE\Icolecao.cpp");
USEUNIT("..\C\CASE\Istdclco.cpp");
USEUNIT("..\C\CASE\Iassccao.cpp");
USEUNIT("..\C\CASE\Idltsttm.cpp");
USEUNIT("..\C\CASE\Idtstore.cpp");
USEUNIT("..\C\CASE\Ipdtsttm.cpp");
USEUNIT("..\C\CASE\Imdfystt.cpp");
USEUNIT("..\C\CASE\Impclsst.cpp");
USEUNIT("..\C\CASE\Ierro.cpp");
USEUNIT("..\C\CASE\Istdgnrc.cpp");
USEUNIT("..\C\CASE\Lststrng.cpp");
USEUNIT("..\C\CASE\Ibsrvdor.cpp");
USEUNIT("..\C\CASE\Intfcdor.cpp");
USEUNIT("..\C\CASE\Intfcdrb.cpp");
USEUNIT("..\C\CASE\Ivntntfc.cpp");
USEUNIT("..\C\CASE\Typevnto.cpp");
USEUNIT("..\C\CASE\Idrcftch.cpp");
USEUNIT("..\C\CASE\Iordem.cpp");
USEUNIT("..\C\CASE\Istdsttm.cpp");
USEUNIT("..\C\CASE\Icritrio.cpp");
USEUNIT("..\C\CASE\Iatrbuto.cpp");
USEUNIT("..\C\CASE\Iknwtype.cpp");
USEUNIT("..\C\CASE\Iprcmprc.cpp");
USEUNIT("..\C\CASE\Iprlgcpr.cpp");
USERES("Paleta.res");
USEUNIT("IBObjeto.cpp");
USEUNIT("IComponent.cpp");
USEUNIT("IBColecao.CPP");
USEUNIT("Modelo.cpp");
USEUNIT("EditorLista.cpp");
USEFORM("TelaEditorLista.cpp", FormEditorLista);
USEFORM("TelaCreditos.cpp", FormCreditos);
USEUNIT("IBBroker.cpp");
USEUNIT("IBDataStoreOracleActivex.cpp");
USEUNIT("IBDataStoreODBC.cpp");
USEUNIT("IBLista.cpp");
USEPACKAGE("vcl40.bpi");
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------
