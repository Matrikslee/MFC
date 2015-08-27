
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

void CFifthView::OnDraw(CDC* /*pDC*/)
{
	CFifthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

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
