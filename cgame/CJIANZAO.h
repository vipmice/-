#pragma once


// CJIANZAO 对话框

class CJIANZAO : public CDialog
{
	DECLARE_DYNAMIC(CJIANZAO)

public:
	CJIANZAO(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CJIANZAO();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JianZao };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
