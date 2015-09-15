#pragma once


// CForthSetTimeDialog 对话框

class CForthSetTimeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CForthSetTimeDialog)

public:
	CForthSetTimeDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CForthSetTimeDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked2();
};
