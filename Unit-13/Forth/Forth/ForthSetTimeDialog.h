#pragma once


// CForthSetTimeDialog �Ի���

class CForthSetTimeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CForthSetTimeDialog)

public:
	CForthSetTimeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CForthSetTimeDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked2();
};
