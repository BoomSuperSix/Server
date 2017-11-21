
// ExcelParserDlg.h : ͷ�ļ�
//

#pragma once
#include <string>
#include <afxdialogex.h>

// CExcelParserDlg �Ի���
class CExcelParserDlg : public CDialogEx
{
private:
	std::string m_sCurProgress;
// ����
public:
	CExcelParserDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXCELPARSER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenIn();
	afx_msg void OnBnClickedOpenOut();
	afx_msg void OnBnClickedStart();
};
