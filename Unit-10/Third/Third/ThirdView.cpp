
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
	// TODO: add draw code for native data here
	{
		// 日
		int left = 700, right = left + 100;
		int top = 80, bottom = top + 100;
		pDC->Ellipse(left, top, right, bottom);
		const int xCircle = (left + right) / 2;
		const int yCircle = (top + bottom) / 2;
		pDC->Ellipse(xCircle - 5, yCircle - 5, xCircle + 5, yCircle + 5);
		const double PI = 3.1415926;
		for (int i = 0; i < 16; ++i) {
			const int len = 60;
			const int xLen = (int)(len*cos(i*PI / 8));
			const int yLen = (int)(len*sin(i*PI / 8));
			pDC->MoveTo(xCircle + xLen, yCircle + yLen);
			pDC->LineTo(xCircle + (int)(xLen*2.0), yCircle + (int)(yLen*2.0));
		}
	}
	{
		// 山
		int x = 200, y = 100;
		const int dx = 40;
		const int dy = 150;
		pDC->MoveTo(x, y);
		x = x - dx;
		y = y + dy;
		pDC->LineTo(x, y);
		x = x - (int)(dx*0.7);
		y = y - dy / 2;
		pDC->LineTo(x, y);
		x = x - (int)(dx*0.5);
		y = y + (int)(dy*0.7);
		pDC->LineTo(x, y);
		const int left = x;
		const int bottom = y;
		x = 200, y = 100;
		pDC->MoveTo(x, y);
		x = x + dx;
		y = y + dy;
		pDC->LineTo(x, y);
		x = x + (int)(dx*0.7);
		y = y - dy / 2;
		pDC->LineTo(x, y);
		x = x + (int)(dx*0.5);
		y = y + (int)(dy*0.7);
		pDC->LineTo(x, y);
		const int right = x;
		pDC->MoveTo(left, bottom);
		pDC->LineTo(right, bottom);
	}
	{
		// 房子
		const int top = 250, center = 500;
		int x = center, y = top;
		const int dx = 50, dy = 50;
		const int left = x - dx;
		const int right = x + dx;
		const int middle = y + dy;
		pDC->MoveTo(x, y);
		pDC->LineTo(left, middle);
		pDC->LineTo(left, middle + (int)(dy*1.2));
		pDC->MoveTo(x, y);
		pDC->LineTo(right, middle);
		pDC->LineTo(right, middle + (int)(dy*1.2));
		pDC->LineTo(left, middle + (int)(dy*1.2));
		pDC->MoveTo(right - dx / 2, y + dy / 2);
		pDC->LineTo(right - dx / 2, y);
		pDC->LineTo(x + (int)(dx*0.7), y);
		pDC->LineTo(x + (int)(dx*0.7), y + (int)(dy*0.7));
		pDC->Rectangle(left + 10, middle, left + 40, middle + 40);
	}
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
