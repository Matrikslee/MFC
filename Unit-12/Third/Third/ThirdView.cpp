
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
//	ON_WM_KEYDOWN()
ON_WM_KEYDOWN()
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
	if (!pDoc)
		return;
	CString strLine;
	strLine.Format(_T("Level = %d"), pDoc->gameLevel);
	pDC->TextOutW(10, 10, strLine);
	pDC->Rectangle(pDoc->m_rectGameFrame);
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	// ��ʾè
	MemDC.SelectObject(&pDoc->m_bitmapCat);
	int x = pDoc->m_nCatXOrg;
	int y = pDoc->m_nCatYOrg;
	pDC->BitBlt(x, y, x + pDoc->m_nCatWidth, y + pDoc->m_nCatHeight, &MemDC, 0, 0, SRCCOPY);
	// ��ʾ��
	MemDC.SelectObject(&pDoc->m_bitmapMouse);
	x = pDoc->m_nMouseXOrg;
	y = pDoc->m_nMouseYOrg;
	pDC->BitBlt(x, y, x + pDoc->m_nMouseWidth, y + pDoc->m_nMouseHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


//void CThirdView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnKeyDown(nChar, nRepCnt, nFlags);
//}


void CThirdView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CThirdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		switch (nChar)
		{
		case VK_UP :
			for (int i = 0; i < 30; ++i) {
				if (pDoc->m_nCatYOrg <= pDoc->m_rectGameFrame.top + 1) {
					break;
				}
				--pDoc->m_nCatYOrg;
				InvalidateRect(pDoc->m_rectGameFrame, TRUE);
			}
			break;
		case VK_DOWN :
			for (int i = 0; i < 30; ++i) {
				if (pDoc->m_nCatYOrg + pDoc->m_nCatHeight >= pDoc->m_rectGameFrame.bottom - 1) {
					break;
				}
				++pDoc->m_nCatYOrg;
				InvalidateRect(pDoc->m_rectGameFrame, TRUE);
			}
			break;
		case VK_LEFT :
			for (int i = 0; i < 30; ++i) {
				if (pDoc->m_nCatXOrg <= pDoc->m_rectGameFrame.left + 1) {
					break;
				}
				--pDoc->m_nCatXOrg;
				InvalidateRect(pDoc->m_rectGameFrame, TRUE);
			}
			break;
		case VK_RIGHT :
			for (int i = 0; i < 30; ++i) {
				if (pDoc->m_nCatXOrg + pDoc->m_nCatWidth >= pDoc->m_rectGameFrame.right - 1) {
					break;
				}
				++pDoc->m_nCatXOrg;
				InvalidateRect(pDoc->m_rectGameFrame, TRUE);
			}
			break;
		default :
			break;
		}
		//InvalidateRect(pDoc->m_rectGameFrame);
		if (pDoc->isGameOver()) {
			pDoc->gameReset();
			Invalidate();
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
