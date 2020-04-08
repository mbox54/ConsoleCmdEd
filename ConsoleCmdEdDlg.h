
// ConsoleCmdEdDlg.h : header file
//

#pragma once


////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////

#include "ConCmdEdCore.h"
#include "GridTable.h"


////////////////////////////////////////////////////////////
// Custom support dialogs
////////////////////////////////////////////////////////////

// dialog to set text parameter
char*  Dlg_SetParam(char* strLabelText);
BOOL CALLBACK Dlg_SetParamProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);

struct st_DlgSetParamMemory
{
	char strTextValue[32];
	char strLabelText[64];

	BYTE bResult;
};


////////////////////////////////////////////////////////////
// CConsoleCmdEdDlg dialog
////////////////////////////////////////////////////////////
class CConsoleCmdEdDlg : public CDialogEx
{

// Construction
public:
	CConsoleCmdEdDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSOLECMDED_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();


public:	
	// *** properties ***

	// output control
	CGridTable m_Grid;

	// *** methods ***


	// *** events ***
	// Grid OPs
	afx_msg void OnGridClick(NMHDR* pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridEndEdit(NMHDR* pNotifyStruct, LRESULT* pResult);
	
	// File OPs
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
