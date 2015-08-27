
// FifthDoc.h : CFifthDoc ��Ľӿ�
//


#pragma once


class CFifthDoc : public CDocument
{
protected: // �������л�����
	CFifthDoc();
	DECLARE_DYNCREATE(CFifthDoc)

// ����
public:
	// �������߳���
	const double PI = 3.14159265359;
	const double dbYMax = 1.0;
	const double dbYMin = -1.0;
	const double dbXMin = 0.0;
	const double dbXMax = 2 * PI;
	const int iPt = 200;
	const int xOrg = 50;
	const int yOrg = 350;
	const int xMax = 700;
	const int yMin = 20;
	// ��������
	const double dbXRatio = (xMax - xOrg) / (dbXMax - dbXMin);
	const double dbYRatio = (yOrg - yMin) / (dbYMax - dbYMin);
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
	virtual ~CFifthDoc();
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
