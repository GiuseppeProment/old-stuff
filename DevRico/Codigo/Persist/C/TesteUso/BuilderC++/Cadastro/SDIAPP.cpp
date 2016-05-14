//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("SDIMain.cpp", SDIAppForm);
USERES("sdiapp.res");
USEFORM("UnitMaisInfo.cpp", MaisInfo);
USEFORM("UnitAboutBox.cpp", AboutBox);
USERES("Rico.res");
USEUNIT("cadastro.cpp");
USEFORM("UnitDialogoLogin.cpp", DialogoLogin);
USEFORM("UnitDialogoEdicao.cpp", DialogoEdicao);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TSDIAppForm), &SDIAppForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TMaisInfo), &MaisInfo);
		Application->CreateForm(__classid(TDialogoLogin), &DialogoLogin);
		Application->Run();

	return 0;
}
//---------------------------------------------------------------------
