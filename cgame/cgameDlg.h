
// cgameDlg.h: 头文件
//

#pragma once


// CcgameDlg 对话框
class CcgameDlg : public CDialog
{
// 构造
public:
	CcgameDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	unsigned int a;
	unsigned int Xmuwu;
	unsigned int RenKou;
	unsigned int tzmcaidan;
	unsigned int JS, MFS, MS, GJS;
	unsigned int RenShusum;

	

	CButton button_ks;
	afx_msg void OnBnClickedks();
	CEdit ed_sl;
	afx_msg void OnEnChangeEdit1();
	CButton button_jf;
	CEdit ed_jf;
	afx_msg void OnBnClickedbuttonjf();

	CEdit ed_ZM;
	CButton button_ZM;
	afx_msg void OnBnClickedZhaomu();
	CButton JianShi;
	CEdit ed_JianShi;
	CEdit ed_MoFaShi;
	CEdit ed_MuShi;
	CEdit ed_GongJianShou;
	CButton MoFaShi;
	CButton MuShi;
	CButton GongJianShou;
	afx_msg void OnBnClickedJianshi();
	afx_msg void OnBnClickedMofashi();
	afx_msg void OnBnClickedMushi();
	afx_msg void OnBnClickedGongjianshou();
	afx_msg void OnBnClickedChuji();
	CButton button_JZ;
	afx_msg void OnBnClickedJianzao();
};
