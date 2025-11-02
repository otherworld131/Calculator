
// CalculatorDlg.h : header file
//

#pragma once


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Calculator_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Control variables
	CEdit m_editNumber1;
	CEdit m_editNumber2;
	CStatic m_staticResult;

	// Value variables
	int m_nResult;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1Number1();
	afx_msg void OnEnChangeEdit1Number2();
	afx_msg void OnBnClickedButtonClear();

	// Performs addition of two input numbers, validates for overflow, displays result, and logs calculation
	afx_msg void OnToolsCalculate();

	// Displays context menu at right-click position
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	// Writes calculation to log file with timestamp; shows warning if write fails but calculation still completes
	void LogCalculation(int nNum1, int nNum2, int nResult);

	// Performs calculation when Enter is pressed (instead of closing dialog)
	virtual void OnOK();
protected:
	// Removes non-numeric characters from edit control text (handles paste validation)
	void ValidateNumericInput(CEdit& editControl);
};
