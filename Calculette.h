
// Calculette.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCalculetteApp:
// See Calculette.cpp for the implementation of this class
//

class CCalculetteApp : public CWinApp
{
public:
	CCalculetteApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCalculetteApp theApp;
