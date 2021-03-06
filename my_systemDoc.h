
// my_systemDoc.h: CmysystemDoc 类的接口
//


#pragma once
#include<vector>
struct Student
{
	CString ID;
	CString name;
	CString sex;
	CString birth;
	CString home;
	CString address;
	Student() {}
	Student(CString in_ID, CString in_name, CString in_sex, CString in_birth, CString in_home, CString in_address)
	{
		ID = in_ID;
		name = in_name;
		sex = in_sex;
		birth = in_birth;
		home = in_home;
		address = in_address;
	}
};


class CmysystemDoc : public CDocument
{
protected: // 仅从序列化创建
	CmysystemDoc() noexcept;
	DECLARE_DYNCREATE(CmysystemDoc)

// 特性
public:
	std::vector<Student> stus;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CmysystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
