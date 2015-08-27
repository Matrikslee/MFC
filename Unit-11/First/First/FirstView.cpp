
// FirstView.cpp : CFirstView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "First.h"
#endif

#include "FirstDoc.h"
#include "FirstView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFirstView

IMPLEMENT_DYNCREATE(CFirstView, CView)

BEGIN_MESSAGE_MAP(CFirstView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDOWN()
//ON_WM_MBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CFirstView 构造/析构

CFirstView::CFirstView()
{
	// TODO: 在此处添加构造代码

}

CFirstView::~CFirstView()
{
}

BOOL CFirstView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFirstView 绘制

void CFirstView::OnDraw(CDC* pDC)
{
	CFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->m_nBubbleCount; ++i) {
		pDC->Ellipse(pDoc->m_rectBubble[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CFirstView 打印

BOOL CFirstView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFirstView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFirstView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFirstView 诊断

#ifdef _DEBUG
void CFirstView::AssertValid() const
{
	CView::AssertValid();
}

void CFirstView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFirstDoc* CFirstView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFirstDoc)));
	return (CFirstDoc*)m_pDocument;
}
#endif //_DEBUG


// CFirstView 消息处理程序


void CFirstView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->m_nBubbleCount < MAX_BUBBLE) {
		int r = rand() % 50 + 10;
		CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);
		pDoc->m_rectBubble[pDoc->m_nBubbleCount] = rect;
		++pDoc->m_nBubbleCount;
		pDoc->SetModifiedFlag();
		InvalidateRect(rect, FALSE);
	}
	CView::OnLButtonDown(nFlags, point);
}


//void CFirstView::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnMButtonDown(nFlags, point);
//}


//void CFirstView::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	MessageBox(_T("A"));
//	CView::OnMButtonDown(nFlags, point);
//}


void CFirstView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFirstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->m_nBubbleCount == 0) {
		MessageBox(_T("没有泡泡了,,,~~"));
	}
	else {
		bool isDeleted = false;
		for (int i = pDoc->m_nBubbleCount - 1; i >= 0; --i) {
			if (point.x >= pDoc->m_rectBubble[i].left && point.x <= pDoc->m_rectBubble[i].right
				&& point.y >= pDoc->m_rectBubble[i].top && point.y <= pDoc->m_rectBubble[i].bottom) {
				for (int j = i; j < pDoc->m_nBubbleCount - 1; ++j) {
					pDoc->m_rectBubble[j] = pDoc->m_rectBubble[j + 1];
				}
				--pDoc->m_nBubbleCount;
				Invalidate();
				isDeleted = true;
				break;
			}
		}
		if (!isDeleted) {
			MessageBox(_T("你没有点到泡泡哦~,~"));
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
