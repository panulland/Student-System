#pragma once


// CChangeDlg 对话框

class CChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeDlg)

public:
	CChangeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChangeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_Change_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString sex;
	CString birth;
	CString home;
	CString address;
	CString ID;
	COleDateTime date;
};
