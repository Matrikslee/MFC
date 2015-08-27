
// FifthView.cpp : CFifthView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFifthView 构造/析构

CFifthView::CFifthView()
{
	// TODO: 在此处添加构造代码

}

CFifthView::~CFifthView()
{
}

BOOL CFifthView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFifthView 绘制

void CFifthView::OnDraw(CDC* /*pDC*/)
{
	CFifthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFifthView 打印

BOOL CFifthView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFifthView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFifthView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFifthView 诊断

#ifdef _DEBUG
void CFifthView::AssertValid() const
{
	CView::AssertValid();
}

void CFifthView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFifthDoc* CFifthView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFifthDoc)));
	return (CFifthDoc*)m_pDocument;
}
#endif //_DEBUG


// CFifthView 消息处理程序
