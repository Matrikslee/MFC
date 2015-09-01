
// ForthView.cpp : CForthView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 定义常量
	const double PI = 3.1415926;
	const int xOrg = 500;
	const int yOrg = 200;
	const int radius = 100;
	const int hourLen = 80;
	const int minuteLen = 70;
	const int secondLen = 60;
	double x, y;
	// 画钟表外框
	CRect tmp(xOrg-radius, yOrg-radius, xOrg+radius, yOrg+radius);
	pDC->Ellipse(tmp);
	// 刻度
	for (int i = 0; i < 12; ++i) {
		x = radius*cos(i*PI / 6);
		y = radius*sin(i*PI / 6);
		pDC->MoveTo(xOrg + (int)(x*.9), yOrg + (int)(y*.9));
		pDC->LineTo(xOrg + (int)x, yOrg + (int)y);
	}
	// 时针
	x = hourLen*cos(PI * 3 / 2 + pDoc->hour*PI / 6);
	y = hourLen*sin(PI * 3 / 2 + pDoc->hour*PI / 6);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg + (int) x, yOrg + (int) y );
	// 分针
	x = minuteLen*cos(PI * 3 / 2 + pDoc->minute*PI / 30);
	y = minuteLen*sin(PI * 3 / 2 + pDoc->minute*PI / 30);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg + (int)x, yOrg + (int)y);
	// 秒针
	x = secondLen*cos(PI * 3 / 2 + pDoc->second*PI / 30);
	y = secondLen*sin(PI * 3 / 2 + pDoc->second*PI / 30);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg + (int)x, yOrg + (int)y);
	// TODO: 在此处为本机数据添加绘制代码
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
