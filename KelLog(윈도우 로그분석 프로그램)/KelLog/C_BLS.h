#pragma once


// C_BLS 대화 상자

class C_BLS : public CDialogEx
{
	DECLARE_DYNAMIC(C_BLS)

public:
	C_BLS(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~C_BLS();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BLS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBitmapButton m_BuGraph;
	CBitmapButton m_BuTimeline;
};
