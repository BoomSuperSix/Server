
// ExcelParserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExcelParser.h"
#include "ExcelParserDlg.h"
#include "afxdialogex.h"
#include <thread>
#include "FilePathMgr.h"
#include "ExcelParseMgr.h"
#include <afxwin.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExcelParserDlg �Ի���



CExcelParserDlg::CExcelParserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXCELPARSER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExcelParserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExcelParserDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_IN, &CExcelParserDlg::OnBnClickedOpenIn)
	ON_BN_CLICKED(IDC_OPEN_OUT, &CExcelParserDlg::OnBnClickedOpenOut)
	ON_BN_CLICKED(IDC_START, &CExcelParserDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CExcelParserDlg ��Ϣ�������

BOOL CExcelParserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetDlgItemTextA(IDC_PROGRESS_INFO, "0%");
	SetDlgItemTextA(IDC_PROGRESS_INFO2, "");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExcelParserDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExcelParserDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExcelParserDlg::OnBnClickedOpenIn()
{
	//TCHAR szPathName[MAX_PATH] = { 0 };
	char szPathName[MAX_PATH] = { 0 };
	BROWSEINFO bInfo = { 0 };
	bInfo.hwndOwner = GetForegroundWindow()->GetSafeHwnd();
	bInfo.lpszTitle = _T("ѡ��Ŀ¼");
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI /*����һ���༭�� �û������ֶ���д·�� �Ի�����Ե�����С֮���..;*/
		| BIF_UAHINT /*��TIPS��ʾ*/ /*| BIF_NONEWFOLDERBUTTON �����½��ļ��а�ť*/;
	// ���ڸ���� ulFlags �ο� http://msdn.microsoft.com/en-us/library/bb773205(v=vs.85).aspx;

	LPITEMIDLIST lpDlist;
	lpDlist = SHBrowseForFolder(&bInfo);
	if (nullptr == lpDlist) // ������ȷ����ť;
	{
		return;
		//strFilePath.clear();
		//return false;
	}
	SHGetPathFromIDListA(lpDlist,szPathName);
	FilePathMgr::GetInstance()->SetOpenInPath(szPathName);
	//strFilePath = szPathName;

	SetDlgItemTextA(IDC_PATH_IN, szPathName);
}


void CExcelParserDlg::OnBnClickedOpenOut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//TCHAR szPathName[MAX_PATH] = { 0 };
	char szPathName[MAX_PATH] = { 0 };
	BROWSEINFO bInfo = { 0 };
	bInfo.hwndOwner = GetForegroundWindow()->GetSafeHwnd();
	bInfo.lpszTitle = _T("ѡ��Ŀ¼");
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI /*����һ���༭�� �û������ֶ���д·�� �Ի�����Ե�����С֮���..;*/
		| BIF_UAHINT /*��TIPS��ʾ*/ /*| BIF_NONEWFOLDERBUTTON �����½��ļ��а�ť*/;
	// ���ڸ���� ulFlags �ο� http://msdn.microsoft.com/en-us/library/bb773205(v=vs.85).aspx;

	LPITEMIDLIST lpDlist;
	lpDlist = SHBrowseForFolder(&bInfo);
	if (nullptr == lpDlist) // ������ȷ����ť;
	{
		return;
		//strFilePath.clear();
		//return false;
	}
	SHGetPathFromIDListA(lpDlist, szPathName);
	FilePathMgr::GetInstance()->SetOpenOutPath(szPathName);

	SetDlgItemTextA(IDC_PATH_OUT, szPathName);
}


void CExcelParserDlg::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//test
	auto pProgressCtrl = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	if (pProgressCtrl == nullptr)
	{
		return;
	}

	pProgressCtrl->SetRange(0, 10000);
	pProgressCtrl->SetPos(0);

	GetDlgItem(IDC_OPEN_IN)->EnableWindow(FALSE);
	GetDlgItem(IDC_OPEN_OUT)->EnableWindow(FALSE);
	GetDlgItem(IDC_START)->EnableWindow(FALSE);
	int nAddStep = 3;
	ExcelParseMgr::GetInstance()->ParseExcel();
	/*for (int i = 0; i < 35; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		int nPos = pProgressCtrl->GetPos();
		if (nPos + nAddStep > 100)
		{
			nAddStep -= nPos + nAddStep - 100;
		}
		pProgressCtrl->SetStep(nAddStep);
		pProgressCtrl->StepIt();
	}*/

	GetDlgItem(IDC_OPEN_IN)->EnableWindow(TRUE);
	GetDlgItem(IDC_OPEN_OUT)->EnableWindow(TRUE);
	GetDlgItem(IDC_START)->EnableWindow(TRUE);

}
