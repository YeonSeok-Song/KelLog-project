// C_FLS.cpp: 구현 파일
//

#include "stdafx.h"
#include "KelLog.h"
#include "C_FLS.h"
#include "afxdialogex.h"


// C_FLS 대화 상자

IMPLEMENT_DYNAMIC(C_FLS, CDialogEx)

C_FLS::C_FLS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FLS, pParent)
{

}

C_FLS::~C_FLS()
{
}

void C_FLS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BuGraph, m_BuGraph);
	DDX_Control(pDX, IDC_BuTimeline, m_BuTimeline);
}


BEGIN_MESSAGE_MAP(C_FLS, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// C_FLS 메시지 처리기


BOOL C_FLS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_BuGraph.LoadBitmaps(IDB_imageGRAPH, NULL, NULL, NULL);
	m_BuTimeline.LoadBitmaps(IDB_imageTIMELINE, NULL, NULL, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


HBRUSH C_FLS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	switch (nCtlColor) {
	case CTLCOLOR_DLG:   /// 다이얼로그 배경색을 white로.
	{
		return (HBRUSH)GetStockObject(WHITE_BRUSH);
		break;
	}

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
	}
}

