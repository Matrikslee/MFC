
// SecondView.cpp : CSecondView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Second.h"
#endif

#include "SecondDoc.h"
#include "SecondView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSecondView

IMPLEMENT_DYNCREATE(CSecondView, CView)

BEGIN_MESSAGE_MAP(CSecondView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSecondView 构造/析构

CSecondView::CSecondView()
{
	// TODO: 在此处添加构造代码

}

CSecondView::~CSecondView()
{
}

BOOL CSecondView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSecondView 绘制

void CSecondView::OnDraw(CDC* pDC)
{
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->m_nBubbleCount; ++i) {
		pDC->Ellipse(pDoc->m_rectBubble[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CSecondView 打印

BOOL CSecondView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSecondView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSecondView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSecondView 诊断

#ifdef _DEBUG
void CSecondView::AssertValid() const
{
	CView::AssertValid();
}

void CSecondView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSecondDoc* CSecondView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSecondDoc)));
	return (CSecondDoc*)m_pDocument;
}
#endif //_DEBUG


// CSecondView 消息处理程序


void CSecondView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {

	}
	CView::OnLButtonDown(nFlags, point);
}


void CSecondView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CSecondDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		if (pDoc->m_nBubbleCount < MAX_BUBBLE) {
			int radius = rand() % 50 + 10;
			CRect rect(point.x - radius, point.y - radius, point.x + radius, point.y + radius);
			pDoc->m_rectBubble[pDoc->m_nBubbleCount++] = rect;
			pDoc->SetModifiedFlag();
			InvalidateRect(rect, FALSE);
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
