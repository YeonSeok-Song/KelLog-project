
// KelLogDlg.h: 헤더 파일
//

#pragma once
#include "C_BLS.h"
#include "C_FLS.h"

// CKelLogDlg 대화 상자
class CKelLogDlg : public CDialogEx
{
// 생성입니다.
public:
	CKelLogDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	C_FLS m_FLSDlg;
	C_BLS m_BLSDlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KELLOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	enum ThreadWorking {
		STOP = 0,
		RUNNING = 1,
		PAUSE = 2
	};
	bool m_bThreadStart;
	CWinThread *m_pThread;
	ThreadWorking m_ThreadWorkType;
	static UINT Threadtest(LPVOID _mothod);
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CBitmapButton m_BuFL;
	CBitmapButton m_BuBL;
	CBitmapButton m_BuHelp;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBitmapButton m_BuTitle;
	afx_msg void OnBnClickedBufl();
	afx_msg void OnBnClickedBubl();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
