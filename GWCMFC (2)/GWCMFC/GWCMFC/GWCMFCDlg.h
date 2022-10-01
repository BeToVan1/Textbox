
// GWCMFCDlg.h : header file
//

#pragma once

// CGWCMFCDlg dialog
class CGWCMFCDlg : public CDialogEx
{
// Construction
public:
	CGWCMFCDlg(CWnd* pParent = nullptr);	// standard constructor

	virtual ~CGWCMFCDlg();;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GWCMFC_DIALOG };
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
	CEdit TextBox;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	CEdit FileName;
	afx_msg void OnBnClickedFilesubmit();
	CEdit Regex;
	CEdit Match;
	afx_msg void OnBnClickedRegexbutton();
	afx_msg void OnBnClickedAlllower();
	afx_msg void OnBnClickedApply();
	afx_msg void OnBnClickedAllcaps();
	afx_msg void OnBnClickedCapitalize();
};
