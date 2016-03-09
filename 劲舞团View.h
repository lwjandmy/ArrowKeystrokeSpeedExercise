// ������View.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEW_H__05B5773F_2E45_4307_93E9_DF26C24A7515__INCLUDED_)
#define AFX_VIEW_H__05B5773F_2E45_4307_93E9_DF26C24A7515__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyView : public CView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// Attributes
public:
	CMyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void BrushScreen(int x,int y);
	void TrueOrFalseIf(int nKeyType);
	void DrawPoint(int nPoint);
	void PointOut();
	int Rand(int nMax);
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	char m_cha[7];		//ÿһ��Ԫ����һ��1��4�����֣�������8������ַ��Ķ�Ӧ���롣
	CString m_strAll;	//�������������ķ�����ַ���
	CString m_strMain;	//ϵͳ��ʾ��Ϣ.
	int m_nTime;		//�û�����ʱ�䡣
	int m_nNext;		//��һ��Ҫ����ķ���Ķ�Ӧ���롣
	BOOL m_bTimer;		//Timer�Ƿ�����ۼơ�
	long m_nResult;		//�ܵ÷֡�
};

#ifndef _DEBUG  // debug version in ������View.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__05B5773F_2E45_4307_93E9_DF26C24A7515__INCLUDED_)
