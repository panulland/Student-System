
// my_systemView.h: CmysystemView 类的接口
//

#pragma once
#include<algorithm>
using namespace std;


class CmysystemView : public CScrollView
{
protected: // 仅从序列化创建
	CmysystemView() noexcept;
	DECLARE_DYNCREATE(CmysystemView)

// 特性
public:
	CmysystemDoc* GetDocument() const;
	int current_student;

// 操作
public:
// 重写
public:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnSize(UINT nType, int cx, int cy);
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CmysystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAdd();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChange();
	afx_msg void OnDelete();
	afx_msg void OnSortByID();
	afx_msg void OnSortByName();
	afx_msg void OnCheck();
	afx_msg void OnSortbybirth();
};

#ifndef _DEBUG  // my_systemView.cpp 中的调试版本
inline CmysystemDoc* CmysystemView::GetDocument() const
   { return reinterpret_cast<CmysystemDoc*>(m_pDocument); }
#endif

