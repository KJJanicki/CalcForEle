
// CalcForEleDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalcForEle.h"
#include "CalcForEleDlg.h"
#include "afxdialogex.h"
#include "ZamianaLiczb.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define _AFXDLL


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


// CCalcForEleDlg dialog



CCalcForEleDlg::CCalcForEleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCFORELE_DIALOG, pParent)
	, binary(_T(""))
	, decimal(_T(""))
	, octal(_T(""))
	, hexadecimal(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcForEleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, binary);
	DDX_Text(pDX, IDC_EDIT2, decimal);
	DDX_Text(pDX, IDC_EDIT4, octal);
	DDX_Text(pDX, IDC_EDIT3, hexadecimal);
}

BEGIN_MESSAGE_MAP(CCalcForEleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT4, &CCalcForEleDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &CCalcForEleDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcForEleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcForEleDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CCalcForEleDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CCalcForEleDlg message handlers

BOOL CCalcForEleDlg::OnInitDialog()
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

void CCalcForEleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcForEleDlg::OnPaint()
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
HCURSOR CCalcForEleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcForEleDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CCalcForEleDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCalcForEleDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCalcForEleDlg::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCalcForEleDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);	//aktualizacja daynych z interfejsu uzytkownika
	ZamianaLiczb zam;	//inicjalizacja obiektu klasy 
	std::string val;
	std::string dec;

	//sprawdzanie czy zadne pole nie jest puste
	if (decimal.IsEmpty() && binary.IsEmpty() && octal.IsEmpty() && hexadecimal.IsEmpty()) {
		MessageBox(_T("Enter the one number!"), _T("Error"), MB_OK | MB_ICONERROR);
		return;
	}

	//sprawdzanie czy tylko pole dziesietne nie jest puste
	if (!(decimal.IsEmpty()) && binary.IsEmpty() && octal.IsEmpty() && hexadecimal.IsEmpty()) {
		val = CT2A(decimal);	//konwersja wartosci z pola na string
		if (!zam.isValidDecimal(val)) {
			MessageBox(_T("Invalid decimal number! Please enter the correct number."), _T("Error"), MB_OK | MB_ICONERROR);
			return;
		}
		dec = val;
	}
	//sprawdzanie czy tylko pole binarne nie jest puste
	else if (decimal.IsEmpty() && !(binary.IsEmpty()) && octal.IsEmpty() && hexadecimal.IsEmpty()) {
		val = CT2A(binary);
		if (!zam.isValidBinary(val)) {
			MessageBox(_T("Invalid binary number! Please enter the correct number."), _T("Error"), MB_OK | MB_ICONERROR);
			return;
		}
		dec = zam.binaryToDecimal(val);	  //konwersja liczby binarnej na dziesietna i przypisanie do dec
	}
	//sprawdzanie czy tylko pole osemkowe nie jest puste
	else if (decimal.IsEmpty() && binary.IsEmpty() && !(octal.IsEmpty()) && hexadecimal.IsEmpty()) {
		val = CT2A(octal);
		if (!zam.isValidOctal(val)) {
			MessageBox(_T("Invalid octal number! Please enter the correct number."), _T("Error"), MB_OK | MB_ICONERROR);
			return;
		}
		dec = zam.octalToDecimal(val);	//konwersja liczby osemkowej na dziesietna i przypisanie do dec
	}
	//sprawdzenie czy tylko pole szesnastkowe nie jest puste
	else if (decimal.IsEmpty() && binary.IsEmpty() && octal.IsEmpty() && !(hexadecimal.IsEmpty())) {
		val = CT2A(hexadecimal);
		if (!zam.isValidHexadecimal(val)) {
			MessageBox(_T("Invalid hexadecimal number! Please enter the correct number. Pay attention to capital letters"), _T("Error"), MB_OK | MB_ICONERROR);
			return;
		}
		dec = zam.hexadecimalToDecimal(val);	//konwersja liczby szesnastkowej na dziesietna i przypisanie do dec
	}
	//komunikat, o tym ze wiecej niz jedno pole jest uzupelnione
	else {
		MessageBox(_T("Enter the one number!"), _T("Error"), MB_OK | MB_ICONERROR);
		return;
	}

	//konwersje liczby dziesietnej na liczby binarne, osemnkowe, szesnastkowe
	std::string bin_val = zam.decimalToBinary(dec);
	std::string oct_val = zam.decimalToOctal(dec);
	std::string hex_val = zam.decimalToHexadecimal(dec);

	//aktualizacja pol tekstowych na interfejsie
	decimal = dec.c_str();
	binary = bin_val.c_str();
	octal = oct_val.c_str();
	hexadecimal = hex_val.c_str();
	UpdateData(FALSE); // aktualizacja interfejsu uzytkownika
}

//przycisk "CLEAR"
void CCalcForEleDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	std::string empty = "";
	decimal = empty.c_str();
	binary = empty.c_str();
	octal = empty.c_str();
	hexadecimal = empty.c_str();
	UpdateData(FALSE);
}


void CCalcForEleDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
