// ForthSetTimeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Forth.h"
#include "ForthSetTimeDialog.h"
#include "afxdialogex.h"


// CForthSetTimeDialog 对话框

IMPLEMENT_DYNAMIC(CForthSetTimeDialog, CDialogEx)

CForthSetTimeDialog::CForthSetTimeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SETTIME, pParent)
{

}

CForthSetTimeDialog::~CForthSetTimeDialog()
{
}

void CForthSetTimeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CForthSetTimeDialog, CDialogEx)
	ON_BN_CLICKED(2, &CForthSetTimeDialog::OnBnClicked2)
END_MESSAGE_MAP()


// CForthSetTimeDialog 消息处理程序


void CForthSetTimeDialog::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
}
