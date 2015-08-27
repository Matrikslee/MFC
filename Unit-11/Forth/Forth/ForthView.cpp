
// ForthView.cpp : CForthView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Forth.h"
#endif

#include "ForthDoc.h"
#include "ForthView.h"
#include "Math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CForthView

IMPLEMENT_DYNCREATE(CForthView, CView)

BEGIN_MESSAGE_MAP(CForthView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CForthView ����/����

CForthView::CForthView()
{
	// TODO: �ڴ˴���ӹ������

}

CForthView::~CForthView()
{
}

BOOL CForthView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CForthView ����

void CForthView::OnDraw(CDC* pDC)
{
	CForthDoc* pDoc = GetDocument();
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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CForthView ��ӡ

BOOL CForthView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CForthView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CForthView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CForthView ���

#ifdef _DEBUG
void CForthView::AssertValid() const
{
	CView::AssertValid();
}

void CForthView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CForthDoc* CForthView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CForthDoc)));
	return (CForthDoc*)m_pDocument;
}
#endif //_DEBUG


// CForthView ��Ϣ�������


void CForthView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CForthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		//��������
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
