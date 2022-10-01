
// GWCMFC.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <thread>


// CGWCMFCApp:
// See GWCMFC.cpp for the implementation of this class
//

class MainLogic;
class CGWCMFCApp : public CWinApp
{
	MainLogic* mLogic = nullptr;

public:
	MainLogic* GetLogic() { return mLogic; }

	CGWCMFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGWCMFCApp theApp;
