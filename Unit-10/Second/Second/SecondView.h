
// SecondView.h : CSecondView ��Ľӿ�
//

#pragma once


class CSecondView : public CView
{
protected: // �������л�����
	CSecondView();
	DECLARE_DYNCREATE(CSecondView)

// ����
public:
	CSecondDoc* GetDocument() const;

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
	virtual ~CSecondView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SecondView.cpp �еĵ��԰汾
inline CSecondDoc* CSecondView::GetDocument() const
   { return reinterpret_cast<CSecondDoc*>(m_pDocument); }
#endif

