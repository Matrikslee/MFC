
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
	// ��sin(x) ����
	// ��Document���ȡ��������
	const double PI = pDoc->PI;
	const double dbYMax = pDoc->dbYMax;
	const double dbYMin = pDoc->dbYMin;
	const double dbXMin = pDoc->dbXMin;
	const double dbXMax = pDoc->dbXMax;
	const int iPt = pDoc->iPt;
	const int xOrg = pDoc->xOrg;
	const int yOrg = pDoc->yOrg;
	const int xMax = pDoc->xMax;
	const int yMin = pDoc->yMin;
	const double dbXRatio = pDoc->dbXRatio;
	const double dbYRatio = pDoc->dbYRatio;
	// �������
	int x = xOrg;
	int y = yOrg;
	pDC->MoveTo(x, y);
	for (int i = 0; i <= iPt; ++i) {
		x = (int)(dbXRatio*(dbXMax / iPt*i - dbXMin) + xOrg);
		y = (int)(yOrg - dbYRatio*(sin(dbXMax / iPt*i) - dbYMin));
		pDC->LineTo(x, y);
	}
	// ��������
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xMax, yOrg);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg, yMin);
	// д�����
	x = (xMax - xOrg) / 2;
	y = yOrg + 20;
	pDC->TextOut(x, y, _T("X��"));
	x = xOrg + 20;
	y = (yOrg - yMin) / 2;
	pDC->TextOut(x, y, _T("Y��"));
	// ��ʾ��굥��������
	CString strText;
	x = pDoc->m_pointMouse.x;
	y = pDoc->m_pointMouse.y;
	strText.Format(_T("������ڵ�(%d,%d)����"), x, y);
	x = xOrg;
	y = yOrg + 40;
	pDC->TextOutW(x, y, strText);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
		// ����������ʾ
		pDoc->m_pointMouse.x = point.x;
		pDoc->m_pointMouse.y = point.y;
		Invalidate();
		// ��������
		const double eps = 0.01;
		double x = (point.x - pDoc->xOrg) / pDoc->dbXRatio + pDoc->dbXMin;
		double y = (pDoc->yOrg - point.y) / pDoc->dbYRatio + pDoc->dbYMin;
		if (fabs(y - sin(x)) < eps) {
			CString strDisplay;
			strDisplay.Format(_T("X = %d, Y = %d"), point.x, point.y);
			MessageBox(strDisplay);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}
