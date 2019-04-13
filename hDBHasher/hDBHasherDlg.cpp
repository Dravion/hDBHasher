
// hDBHasherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hDBHasher.h"
#include "hDBHasherDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "BlowFish.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChDBHasherDlg dialog



ChDBHasherDlg::ChDBHasherDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HDBHASHER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChDBHasherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ED_NEW_PASSWORD, ed_new_pw_var);
	DDX_Control(pDX, IDC_ED_NEW_PW_HASH, var_ed_new_pw_hash);
}

BEGIN_MESSAGE_MAP(ChDBHasherDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_GENERATE, &ChDBHasherDlg::OnBnClickedBtGenerate)
	ON_BN_CLICKED(IDC_BT_RESET, &ChDBHasherDlg::OnBnClickedBtReset)
	ON_BN_CLICKED(IDC_BT_COPY, &ChDBHasherDlg::OnBnClickedBtCopy)
END_MESSAGE_MAP()


// ChDBHasherDlg message handlers

BOOL ChDBHasherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

void ChDBHasherDlg::OnPaint()
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
HCURSOR ChDBHasherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ChDBHasherDlg::OnBnClickedBtGenerate()
{
	

	HM::BlowFishEncryptor a;
	std::string unenc = "test123";

	CString data;


	// Get Password text
	CWnd::GetDlgItemText(IDC_ED_NEW_PASSWORD, data);
	
	// Convert CString text to STL-String
	std::string s2 = CStringA(data);
		
	// Blowfish encrypt the provided Password by User
	std::string result  = a.EncryptToString(s2);

	// Convert CString to STL String	
	std::string str = result;
	CString ss(str.c_str());

	// Output the newly generated Blowfish hash
	this->var_ed_new_pw_hash.SetWindowText(ss);


	
	
}


void ChDBHasherDlg::OnBnClickedBtReset()
{
	this->ed_new_pw_var.SetWindowText(_T(""));
	this->var_ed_new_pw_hash.SetWindowText(_T(""));
	
}


void ChDBHasherDlg::OnBnClickedBtCopy()
{
	
}
