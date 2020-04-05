#pragma once


// CChuJi 对话框

class CChuJi : public CDialog
{
	DECLARE_DYNAMIC(CChuJi)

public:
	CChuJi(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChuJi();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHUJI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit ed_CJ;
};
