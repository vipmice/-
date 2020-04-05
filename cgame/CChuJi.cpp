// CChuJi.cpp: 实现文件
//

#include "pch.h"
#include "cgame.h"
#include "CChuJi.h"
#include "afxdialogex.h"


// CChuJi 对话框

IMPLEMENT_DYNAMIC(CChuJi, CDialog)

CChuJi::CChuJi(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHUJI, pParent)
{

}

CChuJi::~CChuJi()
{
}

void CChuJi::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CJed, ed_CJ);
}


BEGIN_MESSAGE_MAP(CChuJi, CDialog)
END_MESSAGE_MAP()


// CChuJi 消息处理程序
