//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UnitAboutBox.h"
#include "UnitMaisInfo.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::bMaisInfoClick(TObject *Sender)
{
MaisInfo->ShowModal();	
}
//--------------------------------------------------------------------------- 
