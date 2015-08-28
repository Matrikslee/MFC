
// ThirdDoc.cpp : CThirdDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CThirdDoc ����/����

CThirdDoc::CThirdDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CThirdDoc::~CThirdDoc()
{
}

void CThirdDoc::gameReset() {
	++gameLevel;
	// ��ʼ��è������ԭ��
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
	// ����λͼ��Դ,��ȡλͼ��Ϣ
	m_bitmapCat.LoadBitmapW(IDB_BITMAP1);
	m_bitmapMouse.LoadBitmapW(IDB_BITMAP2);
	BITMAP BM;
	m_bitmapCat.GetBitmap(&BM);
	m_nCatHeight = BM.bmHeight;
	m_nCatWidth = BM.bmWidth;
	m_bitmapMouse.GetBitmap(&BM);
	m_nMouseHeight = BM.bmHeight;
	m_nMouseWidth = BM.bmWidth;
	//��ʼ����Ϸ����
	m_rectGameFrame = CRect(m_nGameFrameXOrg, m_nGameFrameYOrg, m_nGameFrameXOrg + m_nGameFrameWidth, m_nGameFrameYOrg + m_nGameFrameHeight);
	gameLevel = 0;
	m_nKeyDown = 0;
	gameReset();
	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CThirdDoc ���л�

void CThirdDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CThirdDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CThirdDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CThirdDoc ���

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


// CThirdDoc ����
