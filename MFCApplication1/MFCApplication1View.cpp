
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "Option.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PAYROLL_RUN, &CMFCApplication1View::OnPayrollRun)
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: add construction code here

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View drawing

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect clientRact;
	GetClientRect(clientRact);
	pDC->FillSolidRect(clientRact, RGB(255, 255, 255));
	pDC->TextOutW(200, 200, text);
}


// CMFCApplication1View printing


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View message handlers


void CMFCApplication1View::OnPayrollRun()
{
	COption dlgOption;
	dlgOption.text = text;

	if (dlgOption.DoModal() == IDOK)
	{

		CString textInput;
		using namespace std;


		//Employ id

		GetDlgItemText(txtEmployer, textInput);
		int dEmployeeId = _ttof(textInput);
		//hourly Wage
		GetDlgItemText(txtHourlyWage, textInput);
		int dHourlyWage = _ttof(textInput);

		//firstweek
		GetDlgItemText(txtFwM, textInput);
		int dFirstMonday = _ttof(textInput);

		GetDlgItemText(txtFwT, textInput);
		int dFirstTuseday = _ttof(textInput);

		GetDlgItemText(txtFwW, textInput);
		int dFirstWednessday = _ttof(textInput);

		GetDlgItemText(txtFwTh, textInput);
		int dFirstThursday = _ttof(textInput);

		GetDlgItemText(txtFwF, textInput);
		int dFirstFriday = _ttof(textInput);

		GetDlgItemText(txtFwSa, textInput);
		int dFirstSaturday = _ttof(textInput);

		GetDlgItemText(txtFwSun, textInput);
		int dFirstSunday = _ttof(textInput);

		//second week
		GetDlgItemText(txtSwM, textInput);
		int dSecondMonday = _ttof(textInput);

		GetDlgItemText(txtSwT, textInput);
		int dSecondTuseday = _ttof(textInput);

		GetDlgItemText(txtSwW, textInput);
		int dSecondWednessday = _ttof(textInput);

		GetDlgItemText(txtSwTh, textInput);
		int dSecondThursday = _ttof(textInput);

		GetDlgItemText(txtSwF, textInput);
		int dSecondFriday = _ttof(textInput);

		GetDlgItemText(txtSwSa, textInput);
		int dSecondSaturday = _ttof(textInput);

		GetDlgItemText(txtSwSun, textInput);
		int dSecondSunday = _ttof(textInput);

		//hourly calculation

		int week1Hours = 0;
		int week2Hours = 0;
		week1Hours = dFirstMonday + dFirstTuseday + dFirstWednessday + dFirstThursday + dFirstFriday + dFirstSaturday + dFirstSunday;
		week2Hours = dSecondMonday + dSecondTuseday + dSecondWednessday + dSecondThursday + dSecondFriday + dSecondSaturday + dSecondSunday;


		int regularHoursWeek1 = 0;
		int regularHoursWeek2 = 0;
		int totalHours = 0;
		int overTimeHoursWeek1 = 0;
		int overTimeHoursWeek2 = 0;
		int totalOvertime = 0;

		//amount calculation

		int regualrAmountPay = 0;
		int overtimeAmountPay = 0;
		int totalEarning = 0;
		//get hours

		if (week1Hours > 40) {
			regularHoursWeek1 = 40;
			overTimeHoursWeek1 = week1Hours - 40;
		}
		else
		{
			regularHoursWeek1 = week1Hours;
		}
		if (week2Hours > 40)
		{
			regularHoursWeek2 = 40;
			overTimeHoursWeek2 = week2Hours - 40;
		}
		else
		{
			regularHoursWeek2 = week2Hours;
		}

		totalHours = regularHoursWeek1 + regularHoursWeek2;
		totalOvertime = overTimeHoursWeek1 + overTimeHoursWeek2;

		//get amount

		regualrAmountPay = dHourlyWage *totalHours;
		overtimeAmountPay = (dHourlyWage*1.5)*totalOvertime;
		totalEarning = regualrAmountPay + overtimeAmountPay;
		//set regulary hours

		string strTotalHours = to_string(totalHours);
		CString totalRegularHours(strTotalHours.c_str());
		SetDlgItemText(txtRegularHours, totalRegularHours);

		//set overtime hours
		string strTotalOvertimeHours = to_string(totalOvertime);
		CString totalOvertimeHours(strTotalOvertimeHours.c_str());
		SetDlgItemText(txtOverTimeHours, totalOvertimeHours);

		//set regular pay amount

		string strRegularAmount = to_string(regualrAmountPay);
		CString totalRegularAmount(strRegularAmount.c_str());
		SetDlgItemText(txtRegularAmount, totalRegularAmount);

		//set overtime pay 
		string strOvertimeAmount = to_string(overtimeAmountPay);
		CString totalOvertimeAmount(strOvertimeAmount.c_str());
		SetDlgItemText(txtOverTimeAmount, totalOvertimeAmount);

		//set total earn 
		string strTotalEarning = to_string(totalEarning);
		CString csTotalEarnings(strTotalEarning.c_str());
		SetDlgItemText(txtTotalEarning, csTotalEarnings);

		text = dlgOption.text;
	}
	Invalidate();
	UpdateWindow();


	// TODO: Add your command handler code here
}
