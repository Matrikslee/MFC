
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
	// ���峣��
	const double PI = 3.14159265359;
	const double dbYMax = 1.0;
	const double dbYMin = -1.0;
	const double dbXMin = 0.0;
	const double dbXMax = 2 * PI;
	const int iPt = 200;
	const int xOrg = 50;
	const int yOrg = 350;
	const int xMax = 700;
	const int yMin = 20;
	// �������ݲ���������
	double dbXRatio = (xMax - xOrg) / (dbXMax - dbXMin);
	double dbYRatio = (yOrg - yMin) / (dbYMax - dbYMin);
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

	CView::OnLButtonDown(nFlags, point);
}
