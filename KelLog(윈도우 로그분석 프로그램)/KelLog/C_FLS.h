#pragma once


// C_FLS 대화 상자

class C_FLS : public CDialogEx
{
	DECLARE_DYNAMIC(C_FLS)

public:
	C_FLS(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~C_FLS();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FLS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CBitmapButton m_BuGraph;
	CBitmapButton m_BuTimeline;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
