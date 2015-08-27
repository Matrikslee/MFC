
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

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	const int nCenterX = 200, nCenterY = 200;
	const int nLineXLen = 400, nLineYLen = 150;
	//��������
	// y��
	pDC->MoveTo(nCenterX - 20, nCenterY);
	pDC->LineTo(nCenterX + nLineXLen, nCenterY);
	pDC->LineTo(nCenterX + nLineXLen - 10, nCenterY - 10);
	pDC->MoveTo(nCenterX + nLineXLen, nCenterY);
	pDC->LineTo(nCenterX + nLineXLen - 10, nCenterY + 10);
	pDC->TextOut(nCenterX + nLineXLen, nCenterY + 10, _T("Y"));
	pDC->TextOut(nCenterX + nLineXLen + 10, nCenterY + 10, _T("��"));
	// x��
	pDC->MoveTo(nCenterX, nCenterY + nLineYLen);
	pDC->LineTo(nCenterX, nCenterY - nLineYLen);
	pDC->LineTo(nCenterX - 10, nCenterY - nLineYLen + 10);
	pDC->MoveTo(nCenterX, nCenterY - nLineYLen);
	pDC->LineTo(nCenterX + 10, nCenterY - nLineYLen + 10);
	pDC->TextOut(nCenterX - 20, nCenterY - nLineYLen, _T("X"));
	pDC->TextOut(nCenterX - 20, nCenterY - nLineYLen + 20, _T("��"));
	const int iPt = 300;
	const double dbMaxX = 20;
	int i;
	pDC->MoveTo(nCenterX, nCenterY);
	// �ϱ�����
	for (i = 0; i < iPt; ++i) {
		double dbX = (int)(dbMaxX / iPt*i);
		int x = nCenterX - 7 * (int)dbX;
		int y = nCenterY + (int)(dbX*dbX);
		pDC->LineTo(y, x);
	}
	// �±�����
	pDC->MoveTo(nCenterX, nCenterY);
	for (i = 0; i < iPt; ++i) {
		double dbX = (int)(dbMaxX / iPt*i);
		int x = nCenterX + 7 * (int)dbX;
		int y = nCenterY + (int)(dbX*dbX);
		pDC->LineTo(y, x);
	}
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
