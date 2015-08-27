
// FifthView.h : CFifthView 类的接口
//

#pragma once


class CFifthView : public CView
{
protected: // 仅从序列化创建
	CFifthView();
	DECLARE_DYNCREATE(CFifthView)

// 特性
public:
	CFifthDoc* GetDocument() const;

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
	virtual ~CFifthView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // FifthView.cpp 中的调试版本
inline CFifthDoc* CFifthView::GetDocument() const
   { return reinterpret_cast<CFifthDoc*>(m_pDocument); }
#endif

