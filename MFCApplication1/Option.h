#pragma once


// COption dialog

class COption : public CDialog
{
	DECLARE_DYNAMIC(COption)

public:
	COption(CWnd* pParent = NULL);   // standard constructor
	virtual ~COption();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlgmain };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
	void OnBnClickedOk();
	CString text;
};
