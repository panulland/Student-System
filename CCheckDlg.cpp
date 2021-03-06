// CCheckDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "my_system.h"
#include "CCheckDlg.h"
#include "afxdialogex.h"


// CCheckDlg 对话框

IMPLEMENT_DYNAMIC(CCheckDlg, CDialogEx)

CCheckDlg::CCheckDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ID_Check_Dialog, pParent)
	, ID(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, home(_T(""))
	, address(_T(""))
	, real_home(_T(""))
{

}

CCheckDlg::~CCheckDlg()
{
}

void CCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_NAME, name);
	DDX_Text(pDX, IDC_EDIT_BIRTH, home);
	DDX_Text(pDX, IDC_EDIT_SEX, sex);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, address);
	DDX_Text(pDX, IDC_EDIT_HOME, real_home);
}


BEGIN_MESSAGE_MAP(CCheckDlg, CDialogEx)
END_MESSAGE_MAP()


// CCheckDlg 消息处理程序
