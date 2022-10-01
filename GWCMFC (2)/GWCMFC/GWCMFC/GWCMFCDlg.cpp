
// GWCMFCDlg.cpp : implementation file
//

#include "framework.h"
#include "GWCMFC.h"
#include "GWCMFCDlg.h"
#include "afxdialogex.h"
#include <cstdio>
#include <regex>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGWCMFCDlg dialog

CGWCMFCDlg::~CGWCMFCDlg()
{
}


CGWCMFCDlg::CGWCMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GWCMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGWCMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, TextBox);
	DDX_Control(pDX, IDC_EDIT2, FileName);
	DDX_Control(pDX, IDC_EDIT3, Regex);
	DDX_Control(pDX, IDC_Match, Match);
}

BEGIN_MESSAGE_MAP(CGWCMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SAVE, &CGWCMFCDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_Load, &CGWCMFCDlg::OnBnClickedLoad)
	
	ON_BN_CLICKED(IDC_RegexButton, &CGWCMFCDlg::OnBnClickedRegexbutton)
	ON_BN_CLICKED(IDC_ALLLOWER, &CGWCMFCDlg::OnBnClickedAlllower)
	ON_BN_CLICKED(IDC_Apply, &CGWCMFCDlg::OnBnClickedApply)
	ON_BN_CLICKED(IDC_AllCaps, &CGWCMFCDlg::OnBnClickedAllcaps)
	ON_BN_CLICKED(IDC_Capitalize, &CGWCMFCDlg::OnBnClickedCapitalize)
END_MESSAGE_MAP()


// CGWCMFCDlg message handlers

BOOL CGWCMFCDlg::OnInitDialog()
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

void CGWCMFCDlg::OnPaint()
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
HCURSOR CGWCMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// In case you need to get to the Dialog from somewhere
//CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();

// And in case you need to get to the app
//CBaronPongApp* app = ( CBaronPongApp *)AfxGetApp();
CString filename = L"";

void CGWCMFCDlg::OnBnClickedSave()
{
	CString fileN = L"";			//gets name of file from edit control
	FileName.GetWindowTextW(fileN);
	filename = fileN;
	
	CString str = L"";				//gets inputted text
	TextBox.GetWindowTextW(str);
	CStdioFile file;
	file.Open(filename, CFile::modeWrite|CFile::modeCreate); //writes text onto file, creates file if it doesn't exist
	file.WriteString(str);
	file.Close();
}

void CGWCMFCDlg::OnBnClickedLoad()
{
	CString fileN = L"";			//gets name of file from edit control
	FileName.GetWindowTextW(fileN);
	filename = fileN;
	
	CStdioFile file;				
	CString str = L"";
	CString full = L"";
	file.Open(filename, CFile::modeRead); //reads strings from file and prints it
	while (file.ReadString(str))
	{
		full += str;
		full += "\n";
	}
	
	TextBox.SetWindowTextW(full);
	file.Close();
	
}

void CGWCMFCDlg::OnBnClickedRegexbutton()
{
	CString str = L"";			//main text box
	TextBox.GetWindowTextW(str);
	CString reg = L"";			//regex
	Regex.GetWindowTextW(reg);
	
	CT2A cs(str);				//convert from CString to string
	std::string string(cs);
	CT2A ct(reg);				//convert from CString to string
	std::string regex(ct);

	std::smatch allMatches;				//match
	std::regex exp(regex);		//regex
	bool rt=std::regex_match(string, allMatches,exp);

	std::string matches;	//adds to matches when there is a match
	while (std::regex_search(string, allMatches, exp))
	{
		matches += allMatches.str(1) + " ";
		string = allMatches.suffix().str();
	}

	CString Cmatches(matches.c_str(), matches.length());//shows matches
	Match.SetWindowTextW(Cmatches);
}

bool allLower = false;
bool allCaps = false;
bool Capitalize = false;
void CGWCMFCDlg::OnBnClickedAlllower()
{
	allLower = true;
}

void CGWCMFCDlg::OnBnClickedAllcaps()
{
	allCaps = true;
}

void CGWCMFCDlg::OnBnClickedCapitalize()
{
	Capitalize = true;
}

void CGWCMFCDlg::OnBnClickedApply()
{
	if (allLower == true)
	{
		CString str = L"";			//main text box
		TextBox.GetWindowTextW(str);
		CT2A cs(str);				//convert from CString to string
		std::string string(cs);
		std::wstring finalstr;
		for (int i = 0; i < string.length();i++)
		{
			char letter = string.at(i);
			string[i] = tolower(letter);
			finalstr += string[i];
		}
		CString Cfinal = finalstr.c_str();
		TextBox.SetWindowTextW(Cfinal);
		allLower = false;
	}
	else if (allCaps == true)
	{
		CString str = L"";			//main text box
		TextBox.GetWindowTextW(str);
		CT2A cs(str);				//convert from CString to string
		std::string string(cs);
		std::wstring finalstr;
		for (int i = 0; i < string.length(); i++)
		{
			char letter = string.at(i);
			string[i] = toupper(letter);
			finalstr += string[i];
		}
		CString Cfinal = finalstr.c_str();
		TextBox.SetWindowTextW(Cfinal);
		allCaps = false;
	}
	else if (Capitalize == true)
	{
		CString str = L"";			//main text box
		TextBox.GetWindowTextW(str);
		CT2A cs(str);				//convert from CString to string
		std::string string(cs);
		std::wstring finalstr;
		char letter;
		
		finalstr += toupper(string[0]);
		for (int i = 1; i < string.length(); i++)
		{
			if(i+1 < string.length())
				letter = string.at(i+1);
			if (string[i] == ' ')
			{
				string[i + 1] = toupper(letter);
				finalstr += string[i];
			}
			else
			{
				finalstr += string[i];
			}	
		}
		CString Cfinal = finalstr.c_str();
		TextBox.SetWindowTextW(Cfinal);
		Capitalize = false;
	}	
	
}

