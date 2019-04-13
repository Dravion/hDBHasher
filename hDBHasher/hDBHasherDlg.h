
// hDBHasherDlg.h : header file
//

#pragma once


// ChDBHasherDlg dialog
class ChDBHasherDlg : public CDialogEx
{
// Construction
public:
	ChDBHasherDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HDBHASHER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtGenerate();
	CEdit ed_new_pw_var;
	afx_msg void OnBnClickedBtReset();
	CEdit var_ed_new_pw_hash;
	afx_msg void OnBnClickedBtCopy();
};
