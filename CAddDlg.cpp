// CAddDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "my_system.h"
#include "CAddDlg.h"
#include "afxdialogex.h"


// CAddDlg 对话框

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ID_Add_Dialog, pParent)
	, sex(_T(""))
	, name(_T(""))
	, birth(_T(""))
	, home(_T(""))
	, address(_T(""))
	, ID(_T(""))
	, date(COleDateTime::GetCurrentTime())
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_SEX, sex);
	DDX_Text(pDX, IDC_EDIT_NAME, name);
	//DDX_Text(pDX, IDC_EDIT_BIRTH, birth);
	DDX_Text(pDX, IDC_EDIT_HOME, home);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, address);
	DDX_Text(pDX, IDC_ID_EDIT, ID);
	DDV_MaxChars(pDX, ID, 9);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, date);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddDlg 消息处理程序
