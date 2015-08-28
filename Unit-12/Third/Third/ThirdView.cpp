
// ThirdView.cpp : CThirdView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_KEYDOWN()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CThirdView 构造/析构

CThirdView::CThirdView()
{
	// TODO: 在此处添加构造代码

}

CThirdView::~CThirdView()
{
}

BOOL CThirdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CThirdView 绘制

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
	// 显示猫
	MemDC.SelectObject(&pDoc->m_bitmapCat);
	int x = pDoc->m_nCatXOrg;
	int y = pDoc->m_nCatYOrg;
	pDC->BitBlt(x, y, x + pDoc->m_nCatWidth, y + pDoc->m_nCatHeight, &MemDC, 0, 0, SRCCOPY);
	// 显示鼠
	MemDC.SelectObject(&pDoc->m_bitmapMouse);
	x = pDoc->m_nMouseXOrg;
	y = pDoc->m_nMouseYOrg;
	pDC->BitBlt(x, y, x + pDoc->m_nMouseWidth, y + pDoc->m_nMouseHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CThirdView 打印

BOOL CThirdView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CThirdView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CThirdView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CThirdView 诊断

#ifdef _DEBUG
void CThirdView::AssertValid() const
{
	CView::AssertValid();
}

void CThirdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThirdDoc* CThirdView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThirdDoc)));
	return (CThirdDoc*)m_pDocument;
}
#endif //_DEBUG


// CThirdView 消息处理程序


//void CThirdView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnKeyDown(nChar, nRepCnt, nFlags);
//}


void CThirdView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
