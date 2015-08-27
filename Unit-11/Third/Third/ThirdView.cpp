
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
	ON_WM_LBUTTONDOWN()
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
	pDC->Ellipse(pDoc->m_rectEllipse);
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


void CThirdView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CThirdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		CSize offset(point - pDoc->m_pointEllipse);
		pDoc->m_rectEllipse += offset;
		Invalidate();
		pDoc->m_pointEllipse = point;
	}
	CView::OnLButtonDown(nFlags, point);
}
