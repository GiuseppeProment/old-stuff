//----------------------------------------------------------------------------
#ifndef UnitMaisInfoH
#define UnitMaisInfoH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TMaisInfo : public TForm
{
__published:
	TMemo *Memo1;
private:
public:
	virtual __fastcall TMaisInfo(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern TMaisInfo *MaisInfo;
//----------------------------------------------------------------------------
#endif    
