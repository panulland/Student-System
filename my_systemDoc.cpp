
// my_systemDoc.cpp: CmysystemDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "my_system.h"
#endif

#include "my_systemDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CmysystemDoc

IMPLEMENT_DYNCREATE(CmysystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CmysystemDoc, CDocument)
END_MESSAGE_MAP()


// CmysystemDoc 构造/析构

CmysystemDoc::CmysystemDoc() noexcept
{
	// TODO: 在此添加一次性构造代码
}

CmysystemDoc::~CmysystemDoc()
{
}

BOOL CmysystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CmysystemDoc 序列化

void CmysystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		CString store;
		for (int i = 0; i < stus.size(); i++)
		{
			store = stus[i].ID + " " + stus[i].name + " " + stus[i].sex + " " + stus[i].birth + " " + stus[i].home + " " + stus[i].address + "\r\n";
			ar.WriteString(store);
		}
		stus.clear();
		SetModifiedFlag(false);
	}
	else
	{
		// TODO: 在此添加加载代码
		CString info;
		ar.ReadString(info);
		while (info != _T(""))
		{
			CStringArray *result = new CStringArray;
			while (true)
			{
				int index = info.Find(_T(" "));
				if (index == -1)
				{
					result->Add(info);
					break;
				}
				CString info1 = info.Left(index);
				result->Add(info1);
				info = info.Right(info.GetLength() - index - 1);
			}
			Student temp(result->GetAt(0), result->GetAt(1), result->GetAt(2), result->GetAt(3), result->GetAt(4), result->GetAt(5));
			delete result;
			stus.push_back(temp);
			ar.ReadString(info);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CmysystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CmysystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CmysystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CmysystemDoc 诊断

#ifdef _DEBUG
void CmysystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmysystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmysystemDoc 命令
