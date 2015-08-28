
// ThirdDoc.cpp : CThirdDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Third.h"
#endif

#include "ThirdDoc.h"
#include <propkey.h>
#include "Math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CThirdDoc

IMPLEMENT_DYNCREATE(CThirdDoc, CDocument)

BEGIN_MESSAGE_MAP(CThirdDoc, CDocument)
END_MESSAGE_MAP()


// CThirdDoc 构造/析构

CThirdDoc::CThirdDoc()
{
	// TODO: 在此添加一次性构造代码

}

CThirdDoc::~CThirdDoc()
{
}

void CThirdDoc::gameReset() {
	++gameLevel;
	// 初始化猫鼠坐标原点
	m_nCatXOrg = rand() % (m_nGameFrameWidth - m_nCatWidth) + m_rectGameFrame.left + 1;
	m_nCatYOrg = rand() % (m_nGameFrameHeight - m_nCatHeight) + m_rectGameFrame.top + 1;
	m_nMouseXOrg = rand() % (m_nGameFrameWidth - m_nMouseWidth) + m_rectGameFrame.left + 1;
	m_nMouseYOrg = rand() % (m_nGameFrameHeight - m_nMouseHeight) + m_rectGameFrame.top + 1;
}

bool CThirdDoc::isGameOver() {
	bool res = false;
	int x = abs(m_nCatXOrg - m_nMouseXOrg);
	int y = abs(m_nCatYOrg - m_nMouseYOrg);
	if ((x < m_nMouseWidth || x < m_nCatWidth) && (y < m_nMouseHeight || y < m_nCatHeight)) {
		res = true;
	}
	return res;
}

BOOL CThirdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	srand(time(NULL));
	// 载入位图资源,读取位图信息
	m_bitmapCat.LoadBitmapW(IDB_BITMAP1);
	m_bitmapMouse.LoadBitmapW(IDB_BITMAP2);
	BITMAP BM;
	m_bitmapCat.GetBitmap(&BM);
	m_nCatHeight = BM.bmHeight;
	m_nCatWidth = BM.bmWidth;
	m_bitmapMouse.GetBitmap(&BM);
	m_nMouseHeight = BM.bmHeight;
	m_nMouseWidth = BM.bmWidth;
	//初始化游戏数据
	m_rectGameFrame = CRect(m_nGameFrameXOrg, m_nGameFrameYOrg, m_nGameFrameXOrg + m_nGameFrameWidth, m_nGameFrameYOrg + m_nGameFrameHeight);
	gameLevel = 0;
	m_nKeyDown = 0;
	gameReset();
	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CThirdDoc 序列化

void CThirdDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CThirdDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CThirdDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CThirdDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CThirdDoc 诊断

#ifdef _DEBUG
void CThirdDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CThirdDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CThirdDoc 命令
