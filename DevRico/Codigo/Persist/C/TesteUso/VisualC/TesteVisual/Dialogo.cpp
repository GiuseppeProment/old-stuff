// Dialogo.cpp : implementation file
//

#include "stdafx.h"
#include "TesteVisual.h"
#include "Dialogo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IDialogo dialog

IDialogo::IDialogo(CWnd* pParent /*=NULL*/)
	: CDialog(IDialogo::IDD, pParent)
{
	//{{AFX_DATA_INIT(IDialogo)
	m_DSN = _T("");
	m_usuario = _T("");
	m_senha = _T("");
	m_nome = _T("");
	m_codigo = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void IDialogo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(IDialogo)
	DDX_Control(pDX, IDC_LIST1, m_Quadro);
	DDX_Text(pDX, IDC_EDIT1, m_DSN);
	DDX_Text(pDX, IDC_EDIT_USUARIO, m_usuario);
	DDX_Text(pDX, IDC_EDIT_SENHA, m_senha);
	DDX_Text(pDX, IDC_NOME, m_nome);
	DDX_Text(pDX, IDC_CODIGO, m_codigo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(IDialogo, CDialog)
	//{{AFX_MSG_MAP(IDialogo)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnDo)
	ON_BN_CLICKED(IDC_BUTTON2, OnConecta)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnInsere)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// IDialogo message handlers

BOOL IDialogo::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void IDialogo::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR IDialogo::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void IDialogo::OnDo() 
{
	//CWaitCursor oTempo;
	HCURSOR	hNovo = AfxGetApp()->LoadCursor(IDC_CURSOR1);
	HCURSOR	hOld = SetCursor( hNovo );

	m_Quadro.ResetContent();
	//m_Quadro.AddString(); 
  try {
		IColecao<Cadastro> OsCadastros;

		m_Quadro.AddString("Preparando Colecao...");
		UpdateWindow();
		OsCadastros.pronto();
		m_Quadro.AddString("Colecao Pronta.");
		UpdateWindow();

		m_Quadro.AddString( "*** TESTE DE EOF C/ VARREDURA ***");
		UpdateWindow();

		OsCadastros.goPrimeiro();
		while ( OsCadastros.isFim()!= true )
		{
			m_Quadro.AddString( OsCadastros.ObjectRef().nome );
			UpdateWindow();
			OsCadastros.goProximo();
		}
  }

  catch( IErro e ) {
		::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}

  catch( IErro * e ) {
		::MessageBox(NULL,e->textError(),"Erro Ptr",MB_ICONEXCLAMATION);
	}

	catch(...) {::MessageBox(NULL,"Erro sem arremesso correto","Erro",MB_ICONEXCLAMATION);}

	SetCursor( hOld  );

}

void IDialogo::OnConecta() 
{
	// TODO: Add your control notification handler code here
	//CWaitCursor oTempo;
	HCURSOR	hNovo = AfxGetApp()->LoadCursor(IDC_CURSOR1);
	HCURSOR	hOld = SetCursor( hNovo );
  try {
    //oDs.setDSN("XBASE");       // Da Microsoft
    //oDs.setDSN("oracleOdbc");  // Da Oracle
		UpdateData();
    //oDs.setnomeDb( (LPCTSTR) m_DSN );      
    oDs.setDSN((LPCTSTR) m_DSN );       
    oDs.setsenha( (LPCTSTR) m_senha );      
    oDs.setusuario( (LPCTSTR) m_usuario );      
		m_Quadro.AddString("Conectando...");
		UpdateWindow();
    oDs.ligar();
		m_Quadro.AddString("Conectado.");
		UpdateWindow();
    IBroker::addDataStore( oDs );
		m_Quadro.AddString("Inicializando...");
		UpdateWindow();
    IBroker::inicialize();
		m_Quadro.AddString("Inicializado.");
		UpdateWindow();
  }
  catch( IErro e ) {
		::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}

	SetCursor( hOld  );
}

void IDialogo::OnButton3() 
{
	// TODO: Add your control notification handler code here
	Cadastro oCadastro;
	IBroker::regDataStoreForClass(oCadastro,"DEFAULT");
}

void IDialogo::OnInsere() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	try {
	Cadastro oPessoa;
	oPessoa.numero = 200; 
	oPessoa.nome = m_nome;
	oPessoa.peso = 10.50;
	oPessoa.endereco = "nem tem";
	oPessoa.save(); }
  catch( IErro e ) {
		::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}

}
