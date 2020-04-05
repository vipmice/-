
// cgame.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号


// CcgameApp:
// 有关此类的实现，请参阅 cgame.cpp
//

class CcgameApp : public CWinApp
{
public:
	CcgameApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CcgameApp theApp;
