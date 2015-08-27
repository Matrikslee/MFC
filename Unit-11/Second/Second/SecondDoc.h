
// SecondDoc.h : CSecondDoc ��Ľӿ�
//


#pragma once
#define MAX_BUBBLE 250

class CSecondDoc : public CDocument
{
protected: // �������л�����
	CSecondDoc();
	DECLARE_DYNCREATE(CSecondDoc)

// ����
public:
	CRect m_rectBubble[MAX_BUBBLE];
	int m_nBubbleCount;
	int m_nCapturedRect;
	CPoint m_pointMouse;
	BOOL m_bCaptured;
// ����
public:

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
	virtual ~CSecondDoc();
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
