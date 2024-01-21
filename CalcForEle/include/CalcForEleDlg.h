
// CalcForEleDlg.h : header file
//

#pragma once


// CCalcForEleDlg dialog
class CCalcForEleDlg : public CDialogEx
{
// Construction
public:
	CCalcForEleDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCFORELE_DIALOG };
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
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButton1();
	CString binary;
	CString decimal;
	CString octal;
	CString hexadecimal;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
};
