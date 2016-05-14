// Dialogo.h : header file
//

#if !defined(AFX_DIALOGO_H__5FB6DDFF_E79C_11D2_948B_00104B321AF0__INCLUDED_)
#define AFX_DIALOGO_H__5FB6DDFF_E79C_11D2_948B_00104B321AF0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// IDialogo dialog
#include "Cadastro.h"

class IDialogo : public CDialog
{
// Construction
public:
	//IDataStoreOracleActivex oDs;
	IDataStoreODBC oDs;
	IDialogo(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(IDialogo)
	enum { IDD = IDD_TESTEVISUAL_DIALOG };
	CListBox	m_Quadro;
	CString	m_DSN;
	CString	m_usuario;
	CString	m_senha;
	CString	m_nome;
	CString	m_codigo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(IDialogo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(IDialogo)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDo();
	afx_msg void OnConecta();
	afx_msg void OnButton3();
	afx_msg void OnInsere();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGO_H__5FB6DDFF_E79C_11D2_948B_00104B321AF0__INCLUDED_)
