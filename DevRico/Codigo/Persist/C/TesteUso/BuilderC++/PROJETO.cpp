//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UnitTela1.cpp", Form1);
USERES("Projeto.res");
USERES("Rico.res");
USEFORM("UnitAboutBox.cpp", AboutBox);
USEFORM("UnitMaisInfo.cpp", MaisInfo);
USEUNIT("cadastro.cpp");
USELIB("F:\Ferramentas\CBuilder4\Lib\bcbmm.lib");
USEFORM("UnitEdicao.cpp", Edicao);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Teste de Persistencia com C++ Builder";
		Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TMaisInfo), &MaisInfo);
                 Application->CreateForm(__classid(TEdicao), &Edicao);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
