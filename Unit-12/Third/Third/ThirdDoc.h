
// ThirdDoc.h : CThirdDoc 类的接口
//


#pragma once


class CThirdDoc : public CDocument
{
protected: // 仅从序列化创建
	CThirdDoc();
	DECLARE_DYNCREATE(CThirdDoc)

// 特性
public:
	// 定义 CBitmap 类对象以及位图的高度和宽度变量
	CBitmap m_bitmapCat;
	CBitmap m_bitmapMouse;
	int m_nCatHeight;
	int m_nCatWidth;
	int m_nMouseHeight;
	int m_nMouseWidth;
	int m_nCatXOrg;
	int m_nCatYOrg;
	int m_nMouseXOrg;
	int m_nMouseYOrg;
	CRect m_rectGameFrame;
	const int m_nGameFrameXOrg = 100;
	const int m_nGameFrameYOrg = 100;
	const int m_nGameFrameWidth = 500;
	const int m_nGameFrameHeight = 300;
	int gameLevel;
	LONG m_nKeyDown;
// 操作
public:
	void gameReset();
	bool isGameOver();
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
	virtual ~CThirdDoc();
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
