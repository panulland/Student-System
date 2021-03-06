
// my_systemView.cpp: CmysystemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "my_system.h"
#endif

#include "my_systemDoc.h"
#include "my_systemView.h"
#include "CAddDlg.h"
#include "CChangeDlg.h"
#include "CCheckDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmysystemView

IMPLEMENT_DYNCREATE(CmysystemView, CScrollView)

BEGIN_MESSAGE_MAP(CmysystemView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_Add, &CmysystemView::OnAdd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_CHANGE, &CmysystemView::OnChange)
	ON_COMMAND(ID_DELETE, &CmysystemView::OnDelete)
	ON_COMMAND(ID_SortByID, &CmysystemView::OnSortByID)
	ON_COMMAND(ID_SortByName, &CmysystemView::OnSortByName)
	ON_COMMAND(ID_CHECK, &CmysystemView::OnCheck)
	ON_COMMAND(ID_SortByBirth, &CmysystemView::OnSortbybirth)
END_MESSAGE_MAP()

// CmysystemView 构造/析构

CmysystemView::CmysystemView() noexcept
{
	// TODO: 在此处添加构造代码
	current_student = -1;
}

CmysystemView::~CmysystemView()
{
}

BOOL CmysystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CmysystemView 绘图

void CmysystemView::OnDraw(CDC* pDC)
{
	CmysystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString head;
	head.Format(_T("%-14.14s%-15.15s%-9.9s%-15.15s%-21.21s%-46.46s"), _T(" 学号"), _T(" 姓名"), _T(" 性别"), _T(" 出生日期"), _T(" 籍贯"), _T(" 住址"));
	CFont *old_font = (CFont *)pDC->SelectStockObject(SYSTEM_FIXED_FONT);
	pDC->TextOut(0, 0, head);
	pDC->MoveTo(0, 20);
	pDC->LineTo(1200, 20);
	int num = pDoc->stus.size();
	for (int i = 0; i < num; i++)
	{
		Student st;
		st = pDoc->stus[i];
		CString temp;
		temp.Format(_T("%-14.14s%-15.15s%-9.9s%-15.15s%-21.21s%-46.46s"),
			_T(" ")+st.ID, _T(" ") + st.name, _T(" ") + st.sex, _T(" ") + st.birth, _T(" ") + st.home, _T(" ") + st.address);
		if (i != current_student)
		{
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->SetBkColor(RGB(255, 255, 255));
		}
		else
		{
			pDC->SetBkColor(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(255, 255, 255));
		}
		pDC->TextOut(0, (i + 1) * 21, temp);
		pDC->MoveTo(0, (i + 1) * 21 + 20);
		pDC->LineTo(1200, (i + 1) * 21 + 20);
	}
	pDC->MoveTo(140, 0);
	pDC->LineTo(140, (num + 1) * 21);
	pDC->MoveTo(290, 0);
	pDC->LineTo(290, (num + 1) * 21);
	pDC->MoveTo(380, 0);
	pDC->LineTo(380, (num + 1) * 21);
	pDC->MoveTo(530, 0);
	pDC->LineTo(530, (num + 1) * 21);
	pDC->MoveTo(740, 0);
	pDC->LineTo(740, (num + 1) * 21);
	pDC->SelectObject(old_font);
}

void CmysystemView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	CmysystemDoc* pDoc = GetDocument();
	sizeTotal.cx = 1200;
	sizeTotal.cy = (pDoc->stus.size() + 1) * 21;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CmysystemView 打印

BOOL CmysystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmysystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmysystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmysystemView 诊断

#ifdef _DEBUG
void CmysystemView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CmysystemView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CmysystemDoc* CmysystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmysystemDoc)));
	return (CmysystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CmysystemView 消息处理程序


void CmysystemView::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	CAddDlg AddDlg;
	while (AddDlg.DoModal() == IDOK)
	{
		if (AddDlg.ID==_T("") || AddDlg.name==_T("") || AddDlg.home==_T("") || AddDlg.address==_T(""))
		{
			AfxMessageBox(_T("请将信息填写完整"));
		}
		else
		{
			if(AddDlg.ID.GetLength()!=9)
				AfxMessageBox(_T("请正确填写9位学号"));
			else
			{
				AddDlg.birth = AddDlg.date.Format(_T("%Y-%m-%d"));
				Student temp(AddDlg.ID, AddDlg.name, AddDlg.sex, AddDlg.birth, AddDlg.home, AddDlg.address);
				CmysystemDoc *pDoc = this->GetDocument();
				pDoc->stus.push_back(temp);
				pDoc->SetModifiedFlag(true);
				pDoc->UpdateAllViews(NULL);
				break;
			}
		}
	}
}


void CmysystemView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	OnPrepareDC(&dc, NULL); //transform dc to   
										  //scrollview
	dc.DPtoLP(&point); // 物理坐标转逻辑坐标

	current_student = point.y / 21 - 1;

	Invalidate(); //重新显示视窗口内容，OnDraw将被调用


	CScrollView::OnLButtonDown(nFlags, point);
}

void CmysystemView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	OnPrepareDC(&dc, NULL); //transform dc to   
										  //scrollview
	dc.DPtoLP(&point); // 物理坐标转逻辑坐标

	current_student = point.y / 21 - 1;

	Invalidate(); //重新显示视窗口内容，OnDraw将被调用

	CMenu popup; //声明一个菜单变量
	popup.LoadMenu(IDR_MENU_R);  //载入菜单资源
	CMenu* pM = popup.GetSubMenu(0);  //得到菜单项
	CPoint p;
	GetCursorPos(&p);  //得到鼠标指针的位置
	pM->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);

	CScrollView::OnRButtonDown(nFlags, point);
}

void CmysystemView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	OnPrepareDC(&dc, NULL); //transform dc to   
										  //scrollview
	dc.DPtoLP(&point); // 物理坐标转逻辑坐标

	current_student = point.y / 21 - 1;

	Invalidate(); //重新显示视窗口内容，OnDraw将被调用

	OnCheck();

	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CmysystemView::OnChange()
{
	// TODO: 在此添加命令处理程序代码
	CChangeDlg dlg;
	CmysystemDoc *pDoc = this->GetDocument();
	if (current_student < 0 || current_student >= pDoc->stus.size())
	{
		AfxMessageBox(_T("未选中目标"));
		return;
	}
	dlg.ID = pDoc->stus[current_student].ID;
	dlg.name = pDoc->stus[current_student].name;
	dlg.sex = pDoc->stus[current_student].sex;
	dlg.date.ParseDateTime(pDoc->stus[current_student].birth);
	dlg.home = pDoc->stus[current_student].home;
	dlg.address = pDoc->stus[current_student].address;
	while (dlg.DoModal() == IDOK)
	{
		if (dlg.ID == _T("") || dlg.name == _T("") || dlg.home == _T("") || dlg.address == _T(""))
		{
			AfxMessageBox(_T("请将信息填写完整"));
		}
		else if(dlg.ID.GetLength()!=9)
			AfxMessageBox(_T("请正确填写9位学号"));
		else
		{
			dlg.birth = dlg.date.Format(_T("%Y-%m-%d"));
			Student temp(dlg.ID, dlg.name, dlg.sex, dlg.birth, dlg.home, dlg.address);
			pDoc->stus[current_student] = temp;
			pDoc->SetModifiedFlag(true);
			pDoc->UpdateAllViews(NULL);
			break;
		}
	}
}


void CmysystemView::OnDelete()
{
	// TODO: 在此添加命令处理程序代码
	CmysystemDoc *pDoc = this->GetDocument();
	if (current_student < 0 || current_student >= pDoc->stus.size())
	{
		AfxMessageBox(_T("未选中目标"));
		return;
	}
	std::vector<Student>::iterator ite = pDoc->stus.begin();
	for (int i = 0; i < current_student; i++, ite++);
	pDoc->stus.erase(ite);
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

bool cmpID(Student a, Student b)
{
	return a.ID < b.ID;
}

void CmysystemView::OnSortByID()
{
	// TODO: 在此添加命令处理程序代码
	CmysystemDoc *pDoc = this->GetDocument();
	sort(pDoc->stus.begin(), pDoc->stus.end(), cmpID);
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

bool cmpName(Student a, Student b)
{
	return a.name < b.name;
}

void CmysystemView::OnSortByName()
{
	// TODO: 在此添加命令处理程序代码
	CmysystemDoc *pDoc = this->GetDocument();
	sort(pDoc->stus.begin(), pDoc->stus.end(), cmpName);
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

bool cmpBirth(Student a, Student b)
{
	return a.birth < b.birth;
}

void CmysystemView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{ // TODO: Add your specialized code here and/or call the base class
	CmysystemDoc* pDoc = GetDocument();

	// TODO: calculate the total size of this view
	CSize sizeTotal, sizePage, sizeLine;
	sizeTotal.cx = 1200;
	sizeTotal.cy = (pDoc->stus.size() + 1) * 21;
	RECT rect;
	GetClientRect(&rect); //获取视窗口的大小
	sizePage.cx = rect.right - rect.left - 8;
	sizePage.cy = rect.bottom - rect.top - 20;
	sizeLine.cx = 8;
	sizeLine.cy = 20;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	Invalidate();
}

void CmysystemView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CmysystemDoc* pDoc = GetDocument();

	// TODO: calculate the total size of this view
	CSize sizeTotal, sizePage, sizeLine;
	sizeTotal.cx = 1200;
	sizeTotal.cy = (pDoc->stus.size() + 1) * 21;
	sizePage.cx = cx - 8;
	sizePage.cy = cy - 20;
	sizeLine.cx = 8;
	sizeLine.cy = 20;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

}

void CmysystemView::OnCheck()
{
	// TODO: 在此添加命令处理程序代码
	CCheckDlg dlg;
	CmysystemDoc *pDoc = this->GetDocument();
	if (current_student < 0 || current_student >= pDoc->stus.size())
	{
		AfxMessageBox(_T("未选中目标"));
		return;
	}
	dlg.ID = pDoc->stus[current_student].ID;
	dlg.name = pDoc->stus[current_student].name;
	dlg.sex = pDoc->stus[current_student].sex;
	dlg.home = pDoc->stus[current_student].birth;
	dlg.real_home = pDoc->stus[current_student].home;
	dlg.address = pDoc->stus[current_student].address;
	if (dlg.DoModal() == IDOK)
		return;
}


void CmysystemView::OnSortbybirth()
{
	// TODO: 在此添加命令处理程序代码
	CmysystemDoc *pDoc = this->GetDocument();
	sort(pDoc->stus.begin(), pDoc->stus.end(), cmpBirth);
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}
