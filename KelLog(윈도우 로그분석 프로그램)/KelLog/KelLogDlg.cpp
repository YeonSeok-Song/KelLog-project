
// KelLogDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "KelLog.h"
#include "KelLogDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.


UINT CKelLogDlg::Threadtest(LPVOID _mothod) {
	CKelLogDlg* pDlg = (CKelLogDlg*)AfxGetApp()->m_pMainWnd;
	CWnd* timer;

	int num = 0;
	while (pDlg->m_ThreadWorkType == RUNNING) {
		timer->SetTimer(1, 1800000, NULL);
	}
	return 0;
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKelLogDlg 대화 상자



CKelLogDlg::CKelLogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KELLOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKelLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BuFL, m_BuFL);
	DDX_Control(pDX, IDC_BuBL, m_BuBL);
	DDX_Control(pDX, IDC_BuHelp, m_BuHelp);
	DDX_Control(pDX, IDC_BuTITLE, m_BuTitle);
	
}

BEGIN_MESSAGE_MAP(CKelLogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BuFL, &CKelLogDlg::OnBnClickedBufl)
	ON_BN_CLICKED(IDC_BuBL, &CKelLogDlg::OnBnClickedBubl)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CKelLogDlg 메시지 처리기

BOOL CKelLogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_BuBL.LoadBitmaps(IDB_imageBLS, NULL, NULL, NULL);
	//m_BuBL.SizeToContent();
	m_BuFL.LoadBitmaps(IDB_imageFLS, NULL, NULL, NULL);
	//m_BuFL.SizeToContent();
	m_BuHelp.LoadBitmaps(IDB_imageHELP, NULL, NULL, NULL);
	//m_BuHelp.SizeToContent();
	m_BuTitle.LoadBitmaps(IDB_imageTITLE, NULL, NULL, NULL);
	//m_BuGraph.LoadBitmaps(IDB_imageGRAPH, NULL, NULL, NULL);
	//m_BuTimeline.LoadBitmaps(IDB_imageTIMELINE, NULL, NULL, NULL);
	/*STARTUPINFO StartupInfo = { 0 };
	PROCESS_INFORMATION ProcessInfo;
	StartupInfo.cb = sizeof(STARTUPINFO);
	::CreateProcess(_T("C:/Users/boho 106-01/Desktop/창공/yes.lnk"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInfo);
	*/
	ShellExecute(NULL, L"runas", _T("C:/Users/boho 106-01/Desktop/창공/yes.lnk"), NULL, NULL, SW_SHOW);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CKelLogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CKelLogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CKelLogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CKelLogDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch (nCtlColor) {
	case CTLCOLOR_DLG:   /// 다이얼로그 배경색을 white로.
	{
		return (HBRUSH)GetStockObject(WHITE_BRUSH);
		break;
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
	}
}


void CKelLogDlg::OnBnClickedBufl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_FLSDlg.DoModal();
}


void CKelLogDlg::OnBnClickedBubl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_BLSDlg.DoModal();
}


void CKelLogDlg::OnTimer(UINT_PTR nIDEvent) //30분마다 수집하는 함수 실행.
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//이곳에 수집하는 코드 작성 아니면 DB에 넣는 함수 작성.
	CDialogEx::OnTimer(nIDEvent);
}

/*
void CMFCApplication1Dlg::OnClickedButtonPause()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pThread == NULL) {
		AfxMessageBox(_T("Thread Not Start!!"));
	}
	else {
		m_pThread->SuspendThread();
		m_ThreadWorkType = PAUSE;
		AfxMessageBox(_T("ThreadPause!!"));
	}
}

void CMFCApplication1Dlg::OnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pThread == NULL) {
		m_pThread = AfxBeginThread(Threadtest, this);
		if (m_pThread == NULL) {
			AfxMessageBox(_T("Error!!!"));
		}
		m_pThread->m_bAutoDelete = FALSE;
		m_ThreadWorkType = RUNNING;
	}
	else {
		if (m_ThreadWorkType == PAUSE) {

			m_pThread->ResumeThread();
			m_ThreadWorkType = RUNNING;
			AfxMessageBox(_T("Thread재시작!!"));
		}
	}
}


void CMFCApplication1Dlg::OnClickedButtonStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pThread == NULL) {
		AfxMessageBox(_T("Thread Not Start!!!"));
	}
	else {
		m_pThread->SuspendThread();
		DWORD dwResult;
		::GetExitCodeThread(m_pThread->m_hThread, &dwResult);

		delete m_pThread;
		m_pThread = NULL;

		m_ThreadWorkType = STOP;

		AfxMessageBox(_T("ThreadStop!!"));
	}
}
*/
