
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
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
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
		for (int i = pDoc->m_nBubbleCount - 1; i >= 0; -- i) {
			if (pDoc->m_rectBubble[i].PtInRect(point)) {
				SetCapture();
				pDoc->m_bCaptured = TRUE;
				pDoc->m_pointMouse = point;
				pDoc->m_nCapturedRect = i;
				break;
			}
		}
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


void CSecondView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		if (pDoc->m_bCaptured) {
			::ReleaseCapture();
			pDoc->m_bCaptured = FALSE;
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CSecondView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		if (pDoc->m_bCaptured) {
			InvalidateRect(pDoc->m_rectBubble[pDoc->m_nCapturedRect]);
			CSize offset(point - pDoc->m_pointMouse);
			pDoc->m_rectBubble[pDoc->m_nCapturedRect] += offset;
			InvalidateRect(pDoc->m_rectBubble[pDoc->m_nCapturedRect]);
			pDoc->m_pointMouse = point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}
