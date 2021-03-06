// CChangeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "my_system.h"
#include "CChangeDlg.h"
#include "afxdialogex.h"


// CChangeDlg 对话框

IMPLEMENT_DYNAMIC(CChangeDlg, CDialogEx)

CChangeDlg::CChangeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ID_Change_Dialog, pParent)
	, name(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, home(_T(""))
	, address(_T(""))
	, ID(_T(""))
	, date(COleDateTime::GetCurrentTime())
{

}

CChangeDlg::~CChangeDlg()
{
}

void CChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, name);
	DDX_CBString(pDX, IDC_COMBO_SEX, sex);
	DDX_Text(pDX, IDC_EDIT_HOME, home);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, address);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDV_MaxChars(pDX, ID, 9);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, date);
}


BEGIN_MESSAGE_MAP(CChangeDlg, CDialogEx)
END_MESSAGE_MAP()


// CChangeDlg 消息处理程序
