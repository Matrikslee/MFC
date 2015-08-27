
// ThirdView.cpp : CThirdView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Third.h"
#endif

#include "ThirdDoc.h"
#include "ThirdView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThirdView

IMPLEMENT_DYNCREATE(CThirdView, CView)

BEGIN_MESSAGE_MAP(CThirdView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CThirdView ����/����

CThirdView::CThirdView()
{
	// TODO: �ڴ˴���ӹ������

}

CThirdView::~CThirdView()
{
}

BOOL CThirdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CThirdView ����


void CThirdView::OnDraw(CDC* pDC)
{
	CThirdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	{
		// ��
		int left = 700, right = left + 100;
		int top = 80, bottom = top + 100;
		pDC->Ellipse(left, top, right, bottom);
		const int xCircle = (left + right) / 2;
		const int yCircle = (top + bottom) / 2;
		pDC->Ellipse(xCircle - 5, yCircle - 5, xCircle + 5, yCircle + 5);
		const double PI = 3.1415926;
		for (int i = 0; i < 16; ++i) {
			const int len = 60;
			const int xLen = (int)(len*cos(i*PI / 8));
			const int yLen = (int)(len*sin(i*PI / 8));
			pDC->MoveTo(xCircle + xLen, yCircle + yLen);
			pDC->LineTo(xCircle + (int)(xLen*2.0), yCircle + (int)(yLen*2.0));
		}
	}
	{
		// ɽ
		int x = 200, y = 100;
		const int dx = 40;
		const int dy = 150;
		pDC->MoveTo(x, y);
		x = x - dx;
		y = y + dy;
		pDC->LineTo(x, y);
		x = x - (int)(dx*0.7);
		y = y - dy / 2;
		pDC->LineTo(x, y);
		x = x - (int)(dx*0.5);
		y = y + (int)(dy*0.7);
		pDC->LineTo(x, y);
		const int left = x;
		const int bottom = y;
		x = 200, y = 100;
		pDC->MoveTo(x, y);
		x = x + dx;
		y = y + dy;
		pDC->LineTo(x, y);
		x = x + (int)(dx*0.7);
		y = y - dy / 2;
		pDC->LineTo(x, y);
		x = x + (int)(dx*0.5);
		y = y + (int)(dy*0.7);
		pDC->LineTo(x, y);
		const int right = x;
		pDC->MoveTo(left, bottom);
		pDC->LineTo(right, bottom);
	}
	{
		// ����
		const int top = 250, center = 500;
		int x = center, y = top;
		const int dx = 50, dy = 50;
		const int left = x - dx;
		const int right = x + dx;
		const int middle = y + dy;
		pDC->MoveTo(x, y);
		pDC->LineTo(left, middle);
		pDC->LineTo(left, middle + (int)(dy*1.2));
		pDC->MoveTo(x, y);
		pDC->LineTo(right, middle);
		pDC->LineTo(right, middle + (int)(dy*1.2));
		pDC->LineTo(left, middle + (int)(dy*1.2));
		pDC->MoveTo(right - dx / 2, y + dy / 2);
		pDC->LineTo(right - dx / 2, y);
		pDC->LineTo(x + (int)(dx*0.7), y);
		pDC->LineTo(x + (int)(dx*0.7), y + (int)(dy*0.7));
		pDC->Rectangle(left + 10, middle, left + 40, middle + 40);
	}
}

// CThirdView ��ӡ

BOOL CThirdView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CThirdView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CThirdView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CThirdView ���

#ifdef _DEBUG
void CThirdView::AssertValid() const
{
	CView::AssertValid();
}

void CThirdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThirdDoc* CThirdView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThirdDoc)));
	return (CThirdDoc*)m_pDocument;
}
#endif //_DEBUG


// CThirdView ��Ϣ�������
