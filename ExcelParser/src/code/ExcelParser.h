
// ExcelParser.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExcelParserApp: 
// �йش����ʵ�֣������ ExcelParser.cpp
//

class CExcelParserApp : public CWinApp
{
public:
	CExcelParserApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExcelParserApp theApp;
