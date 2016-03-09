// ������View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "������.h"

#include "������Doc.h"
#include "������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here
	m_bTimer=FALSE;
	m_nTime=0;
	m_nNext=1;
	m_strMain="���»س���ʼ��ʱ��";
	m_nResult=0;
	m_strAll="";
	memset(m_cha,0,8);
}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString str;
	str="ʹ��˵���������� i k j l �ֱ���� �� �� �� �� �����ð��ո񣬳�����Զ������ַ���";
	pDC->TextOut(10,15,m_strMain);
	pDC->TextOut(10,400,str);
	if(!m_strAll.IsEmpty())
		pDC->TextOut(240,200,m_strAll);
	if(!m_nTime==0)
	{
		str.Format("�ѹ���%d��",m_nTime);
		pDC->TextOut(10,70,str);
		str.Format("�ѵã�%d��",m_nResult*100/m_nTime*2);
		pDC->TextOut(10,90,str);
		str.Format("��/��%d��",m_nResult);
		pDC->TextOut(10,110,str);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL);
	return 0;
}

void CMyView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bTimer==TRUE)
	{
		CClientDC dc(this);
		m_nTime+=1;
		CString str;
		str.Format("�ѹ���%d��",m_nTime);
		BrushScreen(10,70);
		dc.TextOut(10,70,str);
		str.Format("�ѵã�%d��",m_nResult*100/m_nTime*2);
		BrushScreen(10,90);
		dc.TextOut(10,90,str);
		str.Format("��/��%d��",m_nResult);
		BrushScreen(10,110);
		dc.TextOut(10,110,str);

	}
	CView::OnTimer(nIDEvent);
}

void CMyView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CString str;
	if(nChar==0x0d)
	{
		if(m_bTimer==FALSE)
		{
			BrushScreen(10,15);
			BrushScreen(10,70);

			m_strMain="���»س�ֹͣ��ʱ��";
			dc.TextOut(10,15,m_strMain);
			m_bTimer=TRUE;

			PointOut();
		}
		else
		{
			BrushScreen(10,15);

			m_strMain.Format("������%d��,�����%d��! ���»س�������ϰ��",m_nTime,m_nResult*100/m_nTime*2);
			dc.TextOut(10,15,m_strMain);
			m_bTimer=FALSE;
			BrushScreen(10,70);
			BrushScreen(10,90);
			BrushScreen(10,110);
			BrushScreen(240,200);

			m_nTime=0;
			m_nResult=0;
			m_strAll="";
			m_nNext=1;
		}
	}
	else
	{
		if(m_bTimer==TRUE)
		{
			//�û����¿�ʼ��������ʼ������
			
			switch(nChar)
			{
			case 0x6a ://��				
				TrueOrFalseIf(3);			
				break;
			case 0x6b ://��
				TrueOrFalseIf(2);
				break;
			case 0x6c ://��
				TrueOrFalseIf(4);
				break;
			case 0x69 ://��
				TrueOrFalseIf(1);
				break;
			default:
				break;
			}
			if(m_nNext==9)//�ж�����Ѿ�������һ�����еķ���.
			{
				PointOut();
				m_nNext=1;
				goto endOnChar;
			}
		}
	}
endOnChar:
	CView::OnChar(nChar, nRepCnt, nFlags);
}

int CMyView::Rand(int nMax)
{
	int nRand=0;
	BOOL bWhile=TRUE;
	
	nRand=rand();
	while(bWhile)
	{
		nRand=nRand/nMax;
		if(nRand<=nMax)
			bWhile=FALSE;
	}
	return nRand;
}

void CMyView::PointOut()
{
	CClientDC dc(this);
	int i;
	m_strAll="";
	for(int for_i=1;for_i<=8;for_i+=1)
	{
		i=Rand(4);
		m_cha[for_i-1]=i;
		switch(i)
		{
		case 1:
			m_strAll+="         ��";
			break;
		case 2:
			m_strAll+="         ��";
			break;
		case 3:
			m_strAll+="         ��";
			break;
		case 4:
			m_strAll+="         ��";
			break;
		default:
			break;
		}
	}
	dc.TextOut(240,200,m_strAll);
}

void CMyView::DrawPoint(int nPoint)
{
	CClientDC dc(this);
	dc.TextOut(240,200,m_strAll);
	COLORREF clr=dc.SetTextColor(RGB(255,0,0));
	CSize sz=dc.GetTextExtent(m_strAll);
	CRect rect;
	rect.left=240;
	rect.top=200;
	rect.right=240 + sz.cx / 8 * nPoint;
	rect.bottom=200 + sz.cy;
	dc.DrawText(m_strAll,rect,DT_LEFT);
	dc.SetTextColor(clr);
}

void CMyView::TrueOrFalseIf(int nKeyType)
{
	if(m_cha[m_nNext-1]==nKeyType)
	{
		DrawPoint(m_nNext);
		m_nResult+=1;
		m_nNext+=1;
	}
	else
	{
		DrawPoint(0);
		m_nResult-=1;
		m_nNext=1;
	}
}

void CMyView::BrushScreen(int x, int y)
{
	CClientDC dc(this);
	CString str;
	str="ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ";
	COLORREF clr=dc.SetTextColor(dc.GetBkColor());
	dc.TextOut(x,y,str);
	dc.TextOut(x,y,str);
	dc.SetTextColor(clr);
}
