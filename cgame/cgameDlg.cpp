
// cgameDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "cgame.h"
#include "cgameDlg.h"
#include "afxdialogex.h"
#include "CChuJi.h"
#include "CJIANZAO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CcgameDlg 对话框



CcgameDlg::CcgameDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcgameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ks, button_ks);

	DDX_Control(pDX, IDC_EDIT1, ed_sl);
	DDX_Control(pDX, idc_buttonjf, button_jf);
	DDX_Control(pDX, idc_edjf, ed_jf);
	DDX_Control(pDX, IDC_ZM, ed_ZM);
	DDX_Control(pDX, IDC_ZhaoMu, button_ZM);
	DDX_Control(pDX, IDC_JianShi, JianShi);
	DDX_Control(pDX, ED_JianShi, ed_JianShi);
	DDX_Control(pDX, ED_MoFaShi, ed_MoFaShi);
	DDX_Control(pDX, ED_MuShi, ed_MuShi);
	DDX_Control(pDX, ED_GongJianShou, ed_GongJianShou);
	DDX_Control(pDX, IDC_MoFaShi, MoFaShi);
	DDX_Control(pDX, IDC_MuShi, MuShi);
	DDX_Control(pDX, IDC_GongJianShou, GongJianShou);
	DDX_Control(pDX, IDC_JianZao, button_JZ);
}

BEGIN_MESSAGE_MAP(CcgameDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_ks, &CcgameDlg::OnBnClickedks)
	ON_EN_CHANGE(IDC_EDIT1, &CcgameDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(idc_buttonjf, &CcgameDlg::OnBnClickedbuttonjf)

	ON_BN_CLICKED(IDC_ZhaoMu, &CcgameDlg::OnBnClickedZhaomu)
	ON_BN_CLICKED(IDC_JianShi, &CcgameDlg::OnBnClickedJianshi)
	ON_BN_CLICKED(IDC_MoFaShi, &CcgameDlg::OnBnClickedMofashi)
	ON_BN_CLICKED(IDC_MuShi, &CcgameDlg::OnBnClickedMushi)
	ON_BN_CLICKED(IDC_GongJianShou, &CcgameDlg::OnBnClickedGongjianshou)
	ON_BN_CLICKED(IDC_ChuJi, &CcgameDlg::OnBnClickedChuji)
	ON_BN_CLICKED(IDC_JianZao, &CcgameDlg::OnBnClickedJianzao)
END_MESSAGE_MAP()


// CcgameDlg 消息处理程序

BOOL CcgameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//TODO: 在此添加额外的初始化代码
	a = 0;
	Xmuwu = 0;
	//人口数量
	RenKou = 0;
	//
	tzmcaidan = 0;
	//职业数量的置0
	JS = 0, MFS = 0, MS = 0, GJS = 0;
	//职业人数总和
	RenShusum = 0;

	//砍树按钮的大小调整
	CWnd* p_Bks;
	p_Bks = GetDlgItem(IDC_ks);
	//button_ks.SetWindowPos(p_Bks->GetSafeHwnd, 0, 0, 20, 20, SWP_NOMOVE);
	p_Bks->SetWindowPos(NULL, 0, 0, 70, 30, SWP_NOMOVE);

	//建房按钮的大小调整
	CWnd* p_Bjf;
	p_Bjf = GetDlgItem(IDC_ks);
	p_Bjf->SetWindowPos(NULL, 0, 0, 70, 30, SWP_NOMOVE);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcgameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcgameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcgameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcgameDlg::OnBnClickedks()
{
	// TODO: 在此添加控件通知处理程序代码
	a += 5;
	CString str;
	str.Format(_T("%d"), a);
	ed_sl.SetWindowTextW(str);
	CString strtext;
	//int text;
	//ed_sl.GetWindowText(strtext);
	//text = _tstoi(strtext);
	if (a > 20)
	{
		MessageBox(_T("木头不要这么多啊！！！"));
		button_ks.EnableWindow(FALSE);

	}
}



void CcgameDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}

void CcgameDlg::OnBnClickedbuttonjf()
{
	// TODO: 在此添加控件通知处理程序代码
	if (a <= 5)
	{
		MessageBox(_T("没有木头你怎么建？？？？"));

	}
	else
	{
		a -= 10;
		Xmuwu++;
		CString mw;
		mw.Format(_T("%d"), Xmuwu);
		ed_jf.SetWindowText(mw);
		CString str;
		str.Format(_T("%d"), a);
		if (a < 20)
		{
			button_ks.EnableWindow(TRUE);
		}
		ed_sl.SetWindowTextW(str);
	}



}


void CcgameDlg::OnBnClickedZhaomu()
{
	
	// TODO: 在此添加控件通知处理程序代码
	if (Xmuwu <= 0 || Xmuwu*2 == RenKou)
	{
		MessageBox(_T("人都没地方住你还招募个鬼"));
		++tzmcaidan;
		if (tzmcaidan == 3)
		{
			MessageBox(_T("恭喜你达成招募个鬼彩蛋"));
		}
	}
	else
	{
		RenKou = Xmuwu * 2;
		CString RK;
		RK.Format(_T("%d"), RenKou);
		ed_ZM.SetWindowTextW(RK);

	}
}


void CcgameDlg::OnBnClickedJianshi()
{
	// TODO: 在此添加控件通知处理程序代码
	RenShusum = JS + MFS + MS + GJS;
	if (RenShusum == RenKou)
	{
		MessageBox(_T("没人给你转职啦，快去招募点人来"));
	}
	else
	{
		++JS;
		CString CJS;
		CJS.Format(_T("%d"), JS);
		ed_JianShi.SetWindowTextW(CJS);
	}
	
}


void CcgameDlg::OnBnClickedMofashi()
{
	// TODO: 在此添加控件通知处理程序代码
	RenShusum = JS + MFS + MS + GJS;
	if (RenShusum == RenKou)
	{
		MessageBox(_T("没人给你转职啦，快去招募点人来"));
	}
	else
	{
		++MFS;
		CString CMFS;
		CMFS.Format(_T("%d"), MFS);
		ed_MoFaShi.SetWindowTextW(CMFS);
	}
	
}


void CcgameDlg::OnBnClickedMushi()
{
	// TODO: 在此添加控件通知处理程序代码
	RenShusum = JS + MFS + MS + GJS;
	if (RenShusum == RenKou)
	{
		MessageBox(_T("没人给你转职啦，快去招募点人来"));
	}
	else
	{
		++MS;
		CString CMS;
		CMS.Format(_T("%d"), MS);
		ed_MuShi.SetWindowTextW(CMS);
	}
	
}


void CcgameDlg::OnBnClickedGongjianshou()
{
	// TODO: 在此添加控件通知处理程序代码
	RenShusum = JS + MFS + MS + GJS;
	if (RenShusum == RenKou)
	{
		MessageBox(_T("没人给你转职啦，快去招募点人来"));
	}
	else
	{
		++GJS;
		CString	CGJS;
		CGJS.Format(_T("%d"), GJS);
		ed_GongJianShou.SetWindowTextW(CGJS);
	}
	
}


void CcgameDlg::OnBnClickedChuji()
{
	// TODO: 在此添加控件通知处理程序代码
	CChuJi chuji;
	chuji.DoModal();
}


void CcgameDlg::OnBnClickedJianzao()
{
	// TODO: 在此添加控件通知处理程序代码
	CJIANZAO JianZao;
	JianZao.DoModal();

}
