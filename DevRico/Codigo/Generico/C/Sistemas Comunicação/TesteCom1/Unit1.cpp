//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    hCom = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (hCom != NULL)
    	if (!CloseHandle(hCom)) ShowErroWin32();
}
//---------------------------------------------------------------------------
void TForm1::ShowErroWin32()
{
	LPVOID lpMsgBuf;
	FormatMessage(
    	FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
	    NULL,
    	GetLastError(),
	    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
	    (LPTSTR) &lpMsgBuf,
	    0,
	    NULL
	);
	// Display the string.
	MessageBox( NULL, (char*)lpMsgBuf, "GetLastError - Win32 Erro", MB_OK|MB_ICONINFORMATION );
	// Free the buffer.
	LocalFree( lpMsgBuf );
}
void __fastcall TForm1::bLigaClick(TObject *Sender)
{
BOOL fSuccess;
log("Abrindo porta");
hCom = CreateFile(cPorta->Text.c_str(),
    GENERIC_READ | GENERIC_WRITE,
    0,    /* comm devices must be opened w/exclusive-access */
    NULL, /* no security attrs */
    OPEN_EXISTING, /* comm devices must use OPEN_EXISTING */
    FILE_FLAG_OVERLAPPED,    /* not overlapped I/O */
    NULL  /* hTemplate must be NULL for comm devices */
    );
if (hCom == INVALID_HANDLE_VALUE) ShowErroWin32();
/*
 * Omit the call to SetupComm to use the default queue sizes.
 * Get the current configuration.
 */
fSuccess = GetCommState(hCom, &dcb);
log("Configurando...");
if (!fSuccess) ShowErroWin32();
/* Fill in the DCB: baud=9600, 8 data bits, no parity, 1 stop bit. */
dcb.BaudRate = cVelocidade->Text.ToDouble();
dcb.ByteSize = cByteSize->Text.ToDouble();
dcb.Parity = cParidade->ItemIndex;
dcb.StopBits = cStopBits->ItemIndex;
fSuccess = SetCommState(hCom, &dcb);
if (!fSuccess) ShowErroWin32();
bLiga->Enabled = false;
bDesliga->Enabled = true;
bEnvia->Enabled = true;
log("Porta Aberta.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::bDesligaClick(TObject *Sender)
{
log("Fechando Porta...");
	if (hCom != NULL)
    	if (!CloseHandle(hCom)) ShowErroWin32();
bLiga->Enabled = true;
bDesliga->Enabled = false;
bEnvia->Enabled = false;
log("Porta Fechada.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
bLiga->Enabled = true;
bDesliga->Enabled = false;
bEnvia->Enabled = false;
}
//---------------------------------------------------------------------------
void TForm1::log( char* frase)
{
cLog->Lines->Add( frase );
}
//---------------------------------------------------------------------------


void __fastcall TForm1::bLimpaLogClick(TObject *Sender)
{
cLog->Clear();
}
//---------------------------------------------------------------------------
VOID WINAPI FileIOCompletionRoutine(
	DWORD dwErrorCode,
	DWORD dwNumberOfBytesTransfered,	// number of bytes transferred
    LPOVERLAPPED lpOverlapped 	// pointer to structure with I/O information
   )
{
Form1->log("Rotina Fim IO chamada.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::bEnviaClick(TObject *Sender)
{
overLap.Internal = 0;
overLap.InternalHigh = 0;
overLap.Offset = 0;
overLap.OffsetHigh = 0;
overLap.hEvent = NULL;
log("Enviando Dados...");
bool retorno = WriteFileEx(
    hCom, 	// handle to output file
    /*LPCVOID*/ (LPCVOID)cOutput->Text.c_str(), 	// pointer to input buffer
    /*DWORD*/ cOutput->Text.Length(), 	// number of bytes to write
    /*LPOVERLAPPED*/ &overLap, 	// pointer to async. i/o data
    /*LPOVERLAPPED_COMPLETION_ROUTINE*/  FileIOCompletionRoutine // ptr. to completion routine
   );
log("Dados enviados.");
if (retorno) log("Envio = true");
else log("Envio = false");
}



