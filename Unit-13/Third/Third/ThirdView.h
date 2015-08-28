
// ThirdView.h : CThirdView 类的接口
//

#pragma once


class CThirdView : public CView
{
protected: // 仅从序列化创建
	CThirdView();
	DECLARE_DYNCREATE(CThirdView)

// 特性
public:
	CThirdDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CThirdView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // ThirdView.cpp 中的调试版本
inline CThirdDoc* CThirdView::GetDocument() const
   { return reinterpret_cast<CThirdDoc*>(m_pDocument); }
#endif

