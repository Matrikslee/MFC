
// ThirdDoc.h : CThirdDoc ��Ľӿ�
//


#pragma once


class CThirdDoc : public CDocument
{
protected: // �������л�����
	CThirdDoc();
	DECLARE_DYNCREATE(CThirdDoc)

// ����
public:
	// ���� CBitmap ������Լ�λͼ�ĸ߶ȺͿ�ȱ���
	CBitmap m_bitmapCat;
	CBitmap m_bitmapMouse;
	int m_nCatHeight;
	int m_nCatWidth;
	int m_nMouseHeight;
	int m_nMouseWidth;
	int m_nCatXOrg;
	int m_nCatYOrg;
	int m_nMouseXOrg;
	int m_nMouseYOrg;
	CRect m_rectGameFrame;
	const int m_nGameFrameXOrg = 100;
	const int m_nGameFrameYOrg = 100;
	const int m_nGameFrameWidth = 500;
	const int m_nGameFrameHeight = 300;
	int gameLevel;
	LONG m_nKeyDown;
// ����
public:
	void gameReset();
	bool isGameOver();
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CThirdDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
