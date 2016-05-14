//---------------------------------------------------------------------------
#ifndef EditoresH
#define EditoresH
#include <dsgnintf.hpp>
//---------------------------------------------------------------------------
class PACKAGE IBEditorDeLista : public TComponentEditor
{
  public:
    System::AnsiString __fastcall GetVerb(int Index);
    int __fastcall GetVerbCount(void);
    void __fastcall ExecuteVerb(int Index);
};
#endif
