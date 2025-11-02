
// CalculetteDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculette.h"
#include "CalculetteDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

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


// CCalculetteDlg dialog



CCalculetteDlg::CCalculetteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULETTE_DIALOG, pParent), m_nResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculetteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1_NUMBER1, m_editNumber1);
	DDX_Control(pDX, IDC_EDIT1_NUMBER2, m_editNumber2);
	DDX_Control(pDX, IDC_STATIC_RESULT, m_staticResult);
}

BEGIN_MESSAGE_MAP(CCalculetteDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CONTEXTMENU()
	ON_EN_CHANGE(IDC_EDIT1_NUMBER1, &CCalculetteDlg::OnEnChangeEdit1Number1)
	ON_EN_CHANGE(IDC_EDIT1_NUMBER2, &CCalculetteDlg::OnEnChangeEdit1Number2)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculetteDlg::OnBnClickedButtonClear)
	ON_COMMAND(ID_TOOLS_CALCULATE, &CCalculetteDlg::OnToolsCalculate)
END_MESSAGE_MAP()


// CCalculetteDlg message handlers

BOOL CCalculetteDlg::OnInitDialog()
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

	m_nResult = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculetteDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculetteDlg::OnPaint()
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
HCURSOR CCalculetteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculetteDlg::OnEnChangeEdit1Number1()
{
	ValidateNumericInput(m_editNumber1);
}

void CCalculetteDlg::OnBnClickedButtonClear()
{
	m_editNumber1.SetWindowText(_T(""));
	m_editNumber2.SetWindowText(_T(""));
	m_staticResult.SetWindowText(_T(""));
	m_nResult = 0;
}

void CCalculetteDlg::OnToolsCalculate()
{
	CString strNum1, strNum2;
	m_editNumber1.GetWindowText(strNum1);
	m_editNumber2.GetWindowText(strNum2);

	if (strNum1.IsEmpty() || strNum2.IsEmpty())
	{
		MessageBox(_T("Error: Please enter values in both number fields."),
			_T("Input Error"), MB_OK | MB_ICONERROR);
		return;
	}

	int nNumber1 = _ttoi(strNum1);
	int nNumber2 = _ttoi(strNum2);

	if (nNumber1 > INT_MAX - nNumber2)
	{
		MessageBox(_T("Error: Integer overflow! Result exceeds maximum value (2,147,483,647)."),
			_T("Calculation Error"), MB_OK | MB_ICONERROR);
		return;
	}

	m_nResult = nNumber1 + nNumber2;

	CString strResult;
	strResult.Format(_T("%d"), m_nResult);
	m_staticResult.SetWindowText(strResult);

	LogCalculation(nNumber1, nNumber2, m_nResult);
}

void CCalculetteDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CMenu menu;
	if (!menu.LoadMenu(IDR_CONTEXT_MENU))
	{
		CDialogEx::OnContextMenu(pWnd, point);
		return;
	}

	CMenu* pPopup = menu.GetSubMenu(0);
	if (pPopup == nullptr)
	{
		CDialogEx::OnContextMenu(pWnd, point);
		return;
	}

	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CCalculetteDlg::OnOK()
{
	OnToolsCalculate();
}

void CCalculetteDlg::LogCalculation(int nNum1, int nNum2, int nResult)
{
	CTime currentTime = CTime::GetCurrentTime();
	CString strTime = currentTime.Format(_T("%Y-%m-%d %H:%M:%S"));

	CString strLogEntry;
	strLogEntry.Format(_T("[%s] %d + %d = %d\r\n"), strTime, nNum1, nNum2, nResult);

	TCHAR szPath[MAX_PATH];
	GetModuleFileName(nullptr, szPath, MAX_PATH);
	CString strFilePath(szPath);
	int nLastSlash = strFilePath.ReverseFind(_T('\\'));
	if (nLastSlash >= 0)
	{
		strFilePath = strFilePath.Left(nLastSlash + 1);
	}
	strFilePath += _T("calculations.log");

	FILE* pFile = nullptr;
	errno_t err = _tfopen_s(&pFile, strFilePath, _T("a"));
	if (err == 0 && pFile != nullptr)
	{
		_fputts(strLogEntry, pFile);
		fclose(pFile);
	}
	else
	{
		CString strError;
		strError.Format(_T("Warning: Could not write to log file.\n\nPath: %s\nError code: %d\n\nCalculation completed successfully."),
			strFilePath, err);
		MessageBox(strError, _T("Logging Warning"), MB_OK | MB_ICONWARNING);
	}
}

void CCalculetteDlg::OnEnChangeEdit1Number2()
{
	ValidateNumericInput(m_editNumber2);
}

void CCalculetteDlg::ValidateNumericInput(CEdit& editControl)
{
	// Alternative: Subclass CEdit and override WM_PASTE to block invalid paste before it appears

	CString strText;
	editControl.GetWindowText(strText);

	CString strCleaned;
	for (int i = 0; i < strText.GetLength(); i++)
	{
		if (_istdigit(strText[i]))
		{
			strCleaned += strText[i];
		}
	}

	if (strCleaned != strText)
	{
		int nStart, nEnd;
		editControl.GetSel(nStart, nEnd);

		editControl.SetWindowText(strCleaned);

		int nNewPos = min(nStart, strCleaned.GetLength());
		editControl.SetSel(nNewPos, nNewPos);

		MessageBeep(MB_ICONEXCLAMATION);
	}
}
