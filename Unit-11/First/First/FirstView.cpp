
// FirstView.cpp : CFirstView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "First.h"
#endif

#include "FirstDoc.h"
#include "FirstView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFirstView

IMPLEMENT_DYNCREATE(CFirstView, CView)

BEGIN_MESSAGE_MAP(CFirstView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDOWN()
//ON_WM_MBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CFirstView ����/����

CFirstView::CFirstView()
{
	// TODO: �ڴ˴���ӹ������

}

CFirstView::~CFirstView()
{
}

BOOL CFirstView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFirstView ����

void CFirstView::OnDraw(CDC* pDC)
{
	CFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->m_nBubbleCount; ++i) {
		pDC->Ellipse(pDoc->m_rectBubble[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFirstView ��ӡ

BOOL CFirstView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFirstView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFirstView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CFirstView ���

#ifdef _DEBUG
void CFirstView::AssertValid() const
{
	CView::AssertValid();
}

void CFirstView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFirstDoc* CFirstView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFirstDoc)));
	return (CFirstDoc*)m_pDocument;
}
#endif //_DEBUG


// CFirstView ��Ϣ�������


void CFirstView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->m_nBubbleCount < MAX_BUBBLE) {
		int r = rand() % 50 + 10;
		CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);
		pDoc->m_rectBubble[pDoc->m_nBubbleCount] = rect;
		++pDoc->m_nBubbleCount;
		pDoc->SetModifiedFlag();
		InvalidateRect(rect, FALSE);
	}
	CView::OnLButtonDown(nFlags, point);
}


//void CFirstView::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnMButtonDown(nFlags, point);
//}


//void CFirstView::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	MessageBox(_T("A"));
//	CView::OnMButtonDown(nFlags, point);
//}


void CFirstView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->m_nBubbleCount == 0) {
		MessageBox(_T("û��������,,,~~"));
	}
	else {
		bool isDeleted = false;
		for (int i = pDoc->m_nBubbleCount - 1; i >= 0; --i) {
			if (point.x >= pDoc->m_rectBubble[i].left && point.x <= pDoc->m_rectBubble[i].right
				&& point.y >= pDoc->m_rectBubble[i].top && point.y <= pDoc->m_rectBubble[i].bottom) {
				for (int j = i; j < pDoc->m_nBubbleCount - 1; ++j) {
					pDoc->m_rectBubble[j] = pDoc->m_rectBubble[j + 1];
				}
				--pDoc->m_nBubbleCount;
				Invalidate();
				isDeleted = true;
				break;
			}
		}
		if (!isDeleted) {
			MessageBox(_T("��û�е㵽����Ŷ~,~"));
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
