
// ForthView.cpp : CForthView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CForthView 构造/析构

CForthView::CForthView()
{
	// TODO: 在此处添加构造代码

}

CForthView::~CForthView()
{
}

BOOL CForthView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CForthView 绘制

void CForthView::OnDraw(CDC* pDC)
{
	CForthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	const int nCenterX = 200, nCenterY = 200;
	const int nLineXLen = 400, nLineYLen = 150;
	//画坐标轴
	// y轴
	pDC->MoveTo(nCenterX - 20, nCenterY);
	pDC->LineTo(nCenterX + nLineXLen, nCenterY);
	pDC->LineTo(nCenterX + nLineXLen - 10, nCenterY - 10);
	pDC->MoveTo(nCenterX + nLineXLen, nCenterY);
	pDC->LineTo(nCenterX + nLineXLen - 10, nCenterY + 10);
	pDC->TextOut(nCenterX + nLineXLen, nCenterY + 10, _T("Y"));
	pDC->TextOut(nCenterX + nLineXLen + 10, nCenterY + 10, _T("轴"));
	// x轴
	pDC->MoveTo(nCenterX, nCenterY + nLineYLen);
	pDC->LineTo(nCenterX, nCenterY - nLineYLen);
	pDC->LineTo(nCenterX - 10, nCenterY - nLineYLen + 10);
	pDC->MoveTo(nCenterX, nCenterY - nLineYLen);
	pDC->LineTo(nCenterX + 10, nCenterY - nLineYLen + 10);
	pDC->TextOut(nCenterX - 20, nCenterY - nLineYLen, _T("X"));
	pDC->TextOut(nCenterX - 20, nCenterY - nLineYLen + 20, _T("轴"));
	const int iPt = 300;
	const double dbMaxX = 20;
	int i;
	pDC->MoveTo(nCenterX, nCenterY);
	// 上边曲线
	for (i = 0; i < iPt; ++i) {
		double dbX = (int)(dbMaxX / iPt*i);
		int x = nCenterX - 7 * (int)dbX;
		int y = nCenterY + (int)(dbX*dbX);
		pDC->LineTo(y, x);
	}
	// 下边曲线
	pDC->MoveTo(nCenterX, nCenterY);
	for (i = 0; i < iPt; ++i) {
		double dbX = (int)(dbMaxX / iPt*i);
		int x = nCenterX + 7 * (int)dbX;
		int y = nCenterY + (int)(dbX*dbX);
		pDC->LineTo(y, x);
	}
}

// CForthView 打印

BOOL CForthView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CForthView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CForthView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CForthView 诊断

#ifdef _DEBUG
void CForthView::AssertValid() const
{
	CView::AssertValid();
}

void CForthView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CForthDoc* CForthView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CForthDoc)));
	return (CForthDoc*)m_pDocument;
}
#endif //_DEBUG


// CForthView 消息处理程序
