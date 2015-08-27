
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
	ON_WM_LBUTTONDOWN()
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

void CFifthView::OnDraw(CDC* pDC)
{
	CFifthDoc* pDoc = GetDocument();
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
	// 显示鼠标单击的坐标
	CString strText;
	x = pDoc->m_pointMouse.x;
	y = pDoc->m_pointMouse.y;
	strText.Format(_T("鼠标点击在点(%d,%d)上面"), x, y);
	x = xOrg;
	y = yOrg + 40;
	pDC->TextOutW(x, y, strText);
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


void CFifthView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFifthDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc) {
		// 更新坐标显示
		pDoc->m_pointMouse.x = point.x;
		pDoc->m_pointMouse.y = point.y;
		Invalidate();
		// 计算坐标
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
