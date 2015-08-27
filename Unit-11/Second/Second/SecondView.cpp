
// SecondView.cpp : CSecondView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Second.h"
#endif

#include "SecondDoc.h"
#include "SecondView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSecondView

IMPLEMENT_DYNCREATE(CSecondView, CView)

BEGIN_MESSAGE_MAP(CSecondView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSecondView ����/����

CSecondView::CSecondView()
{
	// TODO: �ڴ˴���ӹ������

}

CSecondView::~CSecondView()
{
}

BOOL CSecondView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSecondView ����

void CSecondView::OnDraw(CDC* pDC)
{
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->m_nBubbleCount; ++i) {
		pDC->Ellipse(pDoc->m_rectBubble[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSecondView ��ӡ

BOOL CSecondView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSecondView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSecondView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSecondView ���

#ifdef _DEBUG
void CSecondView::AssertValid() const
{
	CView::AssertValid();
}

void CSecondView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSecondDoc* CSecondView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSecondDoc)));
	return (CSecondDoc*)m_pDocument;
}
#endif //_DEBUG


// CSecondView ��Ϣ�������


void CSecondView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {

	}
	CView::OnLButtonDown(nFlags, point);
}


void CSecondView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		if (pDoc->m_nBubbleCount < MAX_BUBBLE) {
			int radius = rand() % 50 + 10;
			CRect rect(point.x - radius, point.y - radius, point.x + radius, point.y + radius);
			pDoc->m_rectBubble[pDoc->m_nBubbleCount++] = rect;
			pDoc->SetModifiedFlag();
			InvalidateRect(rect, FALSE);
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
