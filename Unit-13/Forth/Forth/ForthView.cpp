
// ForthView.cpp : CForthView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Forth.h"
#endif
#include "Math.h"
#include "ForthDoc.h"
#include "ForthView.h"

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
	// ���峣��
	const double PI = 3.1415926;
	const int xOrg = 500;
	const int yOrg = 200;
	const int radius = 100;
	const int hourLen = 80;
	const int minuteLen = 70;
	const int secondLen = 60;
	double x, y;
	// ���ӱ����
	CRect tmp(xOrg-radius, yOrg-radius, xOrg+radius, yOrg+radius);
	pDC->Ellipse(tmp);
	// �̶�
	for (int i = 0; i < 12; ++i) {
		x = radius*cos(i*PI / 6);
		y = radius*sin(i*PI / 6);
		pDC->MoveTo(xOrg + (int)(x*.9), yOrg + (int)(y*.9));
		pDC->LineTo(xOrg + (int)x, yOrg + (int)y);
	}
	// ʱ��
	x = hourLen*cos(PI * 3 / 2 + pDoc->hour*PI / 6);
	y = hourLen*sin(PI * 3 / 2 + pDoc->hour*PI / 6);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg + (int) x, yOrg + (int) y );
	// ����
	x = minuteLen*cos(PI * 3 / 2 + pDoc->minute*PI / 30);
	y = minuteLen*sin(PI * 3 / 2 + pDoc->minute*PI / 30);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg + (int)x, yOrg + (int)y);
	// ����
	x = secondLen*cos(PI * 3 / 2 + pDoc->second*PI / 30);
	y = secondLen*sin(PI * 3 / 2 + pDoc->second*PI / 30);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg + (int)x, yOrg + (int)y);
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
