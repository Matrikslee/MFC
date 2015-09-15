
// ForthView.h : CForthView ��Ľӿ�
//

#pragma once


class CForthView : public CView
{
protected: // �������л�����
	CForthView();
	DECLARE_DYNCREATE(CForthView)

// ����
public:
	CForthDoc* GetDocument() const;

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
	virtual ~CForthView();
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

#ifndef _DEBUG  // ForthView.cpp �еĵ��԰汾
inline CForthDoc* CForthView::GetDocument() const
   { return reinterpret_cast<CForthDoc*>(m_pDocument); }
#endif

