
// FifthDoc.h : CFifthDoc 类的接口
//


#pragma once


class CFifthDoc : public CDocument
{
protected: // 仅从序列化创建
	CFifthDoc();
	DECLARE_DYNCREATE(CFifthDoc)

// 特性
public:
	// 定义曲线常量
	const double PI = 3.14159265359;
	const double dbYMax = 1.0;
	const double dbYMin = -1.0;
	const double dbXMin = 0.0;
	const double dbXMax = 2 * PI;
	const int iPt = 200;
	const int xOrg = 50;
	const int yOrg = 350;
	const int xMax = 700;
	const int yMin = 20;
	// 换算数据
	const double dbXRatio = (xMax - xOrg) / (dbXMax - dbXMin);
	const double dbYRatio = (yOrg - yMin) / (dbYMax - dbYMin);
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
	virtual ~CFifthDoc();
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
