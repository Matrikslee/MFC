
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
#include "Math.h"
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
	ON_WM_LBUTTONDOWN()
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
	// 画sin(x) 曲线
	// 从Document类获取常量数据
	const double PI = pDoc->PI;
	const double dbYMax = pDoc->dbYMax;
	const double dbYMin = pDoc->dbYMin;
	const double dbXMin = pDoc->dbXMin;
	const double dbXMax = pDoc->dbXMax;
	const int iPt = pDoc->iPt;
	const int xOrg = pDoc->xOrg;
	const int yOrg = pDoc->yOrg;
	const int xMax = pDoc->xMax;
	const int yMin = pDoc->yMin;
	const double dbXRatio = pDoc->dbXRatio;
	const double dbYRatio = pDoc->dbYRatio;
	// 定义变量
	int x = xOrg;
	int y = yOrg;
	pDC->MoveTo(x, y);
	for (int i = 0; i <= iPt; ++i) {
		x = (int)(dbXRatio*(dbXMax / iPt*i - dbXMin) + xOrg);
		y = (int)(yOrg - dbYRatio*(sin(dbXMax / iPt*i) - dbYMin));
		pDC->LineTo(x, y);
	}
	// 画坐标轴
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xMax, yOrg);
	pDC->MoveTo(xOrg, yOrg);
	pDC->LineTo(xOrg, yMin);
	// 写轴标题
	x = (xMax - xOrg) / 2;
	y = yOrg + 20;
	pDC->TextOut(x, y, _T("X轴"));
	x = xOrg + 20;
	y = (yOrg - yMin) / 2;
	pDC->TextOut(x, y, _T("Y轴"));
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


void CForthView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CForthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		//计算坐标
		const double eps = 0.01;
		double x = (point.x - pDoc->xOrg) / pDoc->dbXRatio + pDoc->dbXMin;
		double y = (pDoc->yOrg - point.y) / pDoc->dbYRatio + pDoc->dbYMin;
		if (fabs(y - sin(x)) < eps) {
			CString strDisplay;
			strDisplay.Format(_T("X = %d, Y = %d"), point.x, point.y);
			MessageBox(strDisplay);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}
