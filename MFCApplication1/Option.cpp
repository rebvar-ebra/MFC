// Option.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Option.h"
#include "afxdialogex.h"


#pragma warning(suppress : 4996)


// COption dialog

IMPLEMENT_DYNAMIC(COption, CDialog)

COption::COption(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_Dlgmain, pParent)
	, text(_T("$"))
{

}

COption::~COption()
{
}

void COption::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, txtTotalEarning, text);
}


BEGIN_MESSAGE_MAP(COption, CDialog)
	ON_BN_CLICKED(IDOK, &COption::OnBnClickedOk)
END_MESSAGE_MAP()


//// COption message handlers
//BOOL COption::OnInitDialog()
//{
//	COption::OnInitDialog();
//
//		// TODO: Add extra initialization here
//
//
//	time_t now = time(0);
//	tm *ltm = localtime(&now);
//	int day = ltm->tm_mday;
//	int month = ltm->tm_mon + 1;
//	int year = 1900 + ltm->tm_year;
//	int startDay = 1;
//	int endDay = 14;
//
//	if (day > 14) {
//		startDay = 15;
//		endDay = startDay + 14;
//	}
//	CTime payStart(year, month, startDay, 0, 0, 0);
//	CString s = payStart.Format("%Y/%m/%d");
//	CTime payEnd(year, month, endDay, 0, 0, 0);
//	CString e = payEnd.Format("%Y/%m/%d");
//	CString payRange = s + "  -  " + e;
//	SetDlgItemText(txtdate, payRange);
//	return TRUE;  // return TRUE  unless you set the focus to a control
//}





void COption::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
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





	
}
