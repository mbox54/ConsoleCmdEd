// ConsoleCmdEdDlg.cpp : implementation file
//

////////////////////////////////////////////////////////////
// includes
////////////////////////////////////////////////////////////
#include "pch.h"
#include "framework.h"
#include "ConsoleCmdEd.h"
#include "ConsoleCmdEdDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////// 
// Custom support dialogs
////////////////////////////////////////////////////////////

// dialog to set text parameter
struct st_DlgSetParamMemory m_stDlgSetParamMemory;

char* Dlg_SetParam(char* strLabelText)
{
	// define dialog config
	m_stDlgSetParamMemory.bResult = 1;
	memcpy(m_stDlgSetParamMemory.strLabelText, strLabelText, 64);

	// NOTE:
	// -use to Show: CreateDialog
	//	HWND hDlg = CreateDialog(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDD_DIALOG_SETPARAMETER), 0, (DLGPROC)Dlg_SetParamProc);
	//	ShowWindow(hDlg, SW_SHOW);
	// -use to ShowModal: DialogBoxA
	//	HWND hWnd = (HWND)AfxGetMainWnd();
	//	DialogBoxA(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDD_DIALOG_SETPARAMETER), 0, (DLGPROC)Dlg_SetParamProc);

	// Show Modal
	HWND hWnd = (HWND)AfxGetMainWnd();
	DialogBoxA(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDD_DIALOG_SETPARAMETER), 0, (DLGPROC)Dlg_SetParamProc);

	// check Result
	if (m_stDlgSetParamMemory.bResult == 0)
	{
		// [VALID]

		return m_stDlgSetParamMemory.strTextValue;
	}
	else if (m_stDlgSetParamMemory.bResult == 1)
	{
		// [ABORT]

		return "";
	}
	else if (m_stDlgSetParamMemory.bResult == 2)
	{
		// [BAD PARAM]

		return "";
	}
}


BOOL CALLBACK Dlg_SetParamProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case WM_INITDIALOG:
			SetDlgItemText(hwndDlg, IDC_STATIC_LABEL, m_stDlgSetParamMemory.strLabelText);


			return TRUE;

		case IDOK:
			
			GetDlgItemText(hwndDlg, IDC_EDIT_VALUE, m_stDlgSetParamMemory.strTextValue, 32);
			DestroyWindow(hwndDlg);

			// set value
			m_stDlgSetParamMemory.bResult = 0;

			return TRUE;


		case IDCANCEL:
			DestroyWindow(hwndDlg);
			
			// abort
			m_stDlgSetParamMemory.bResult = 2;

			return TRUE;

			
		}
	}

	return FALSE;
}


//////////////////////////////////////////////////////////// 
// CAboutDlg dialog used for App About
////////////////////////////////////////////////////////////
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


////////////////////////////////////////////////////////////
// CConsoleCmdEdDlg dialog
////////////////////////////////////////////////////////////
CConsoleCmdEdDlg::CConsoleCmdEdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONSOLECMDED_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CConsoleCmdEdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRID, m_Grid);
}


BEGIN_MESSAGE_MAP(CConsoleCmdEdDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	// Grid event functions
	ON_NOTIFY(NM_CLICK, IDC_GRID, &CConsoleCmdEdDlg::OnGridClick)
	ON_NOTIFY(GVN_ENDLABELEDIT, IDC_GRID, &CConsoleCmdEdDlg::OnGridEndEdit)


	ON_BN_CLICKED(IDC_BUTTON1, &CConsoleCmdEdDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CConsoleCmdEdDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CConsoleCmdEdDlg::OnBnClickedButton3)
//	ON_WM_NOTIFYFORMAT()
END_MESSAGE_MAP()


////////////////////////////////////////////////////////////
// CConsoleCmdEdDlg message handlers
////////////////////////////////////////////////////////////
BOOL CConsoleCmdEdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CConsoleCmdEdDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CConsoleCmdEdDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CConsoleCmdEdDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CConsoleCmdEdDlg::OnOK()
{
	// disable auto-exit on ENTER key

//	 CDialogEx::OnOK();
}

// *** Grid OPs ***
void CConsoleCmdEdDlg::OnGridClick(NMHDR* pNotifyStruct, LRESULT* pResult)
{

}


void CConsoleCmdEdDlg::OnGridEndEdit(NMHDR* pNotifyStruct, LRESULT* pResult)
{

}

// *** File OPs ***
// new
void CConsoleCmdEdDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}

// load
void CConsoleCmdEdDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}

// save
void CConsoleCmdEdDlg::OnBnClickedButton3()
{
	char strFilename[32];
	memcpy(strFilename, Dlg_SetParam("Set file name"), 32);

}


