
// FifthView.cpp : CFifthView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Fifth.h"
#endif

#include "FifthDoc.h"
#include "FifthView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFifthView

IMPLEMENT_DYNCREATE(CFifthView, CView)

BEGIN_MESSAGE_MAP(CFifthView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CFifthView ����/����

CFifthView::CFifthView()
{
	// TODO: �ڴ˴���ӹ������

}

CFifthView::~CFifthView()
{
}

BOOL CFifthView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFifthView ����

void CFifthView::OnDraw(CDC* pDC)
{
	CFifthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->getRect());
}


// CFifthView ��ӡ

BOOL CFifthView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFifthView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFifthView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CFifthView ���

#ifdef _DEBUG
void CFifthView::AssertValid() const
{
	CView::AssertValid();
}

void CFifthView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFifthDoc* CFifthView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFifthDoc)));
	return (CFifthDoc*)m_pDocument;
}
#endif //_DEBUG


// CFifthView ��Ϣ�������


void CFifthView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFifthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		const CRect& cRect = pDoc->getRect();
		if ( point.x >= cRect.left && point.x <= cRect.right 
			&& point.y >= cRect.top  && point.y <= cRect.bottom ) {
			MessageBox(_T("���о���!"));
		} else {
			pDoc->setRect(point.x, point.y);
		}
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
