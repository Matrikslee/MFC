// ForthSetTimeDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Forth.h"
#include "ForthSetTimeDialog.h"
#include "afxdialogex.h"


// CForthSetTimeDialog �Ի���

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


// CForthSetTimeDialog ��Ϣ�������


void CForthSetTimeDialog::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
