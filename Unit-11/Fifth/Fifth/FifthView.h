
// FifthView.h : CFifthView ��Ľӿ�
//

#pragma once


class CFifthView : public CView
{
protected: // �������л�����
	CFifthView();
	DECLARE_DYNCREATE(CFifthView)

// ����
public:
	CFifthDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFifthView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // FifthView.cpp �еĵ��԰汾
inline CFifthDoc* CFifthView::GetDocument() const
   { return reinterpret_cast<CFifthDoc*>(m_pDocument); }
#endif

