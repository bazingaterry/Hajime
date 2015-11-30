#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int dayOfMonth(int year,int month)
{
	if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
	else if (month==4||month==6||month==9||month==11) return 30;
	else if (month==2) 
	{
		if ((year%4==0&&year%100!=0)||year%400==0) return 29;
		else return 28;
	}
}


string day2str (int day)
{
	day=day%7;
	if (day==1) return "Monday";
	else if (day==2) return "Tuesday";
	else if (day==3) return "Wednesday";
	else if (day==4) return "Thursday";
	else if (day==5) return "Friday";
	else if (day==6) return "Saturday";
	else if (day==0) return "Sunday";
}

int str2day (string str)
{		
	if (str=="Monday") return 1;
	else if (str=="Tuesday") return 2;
	else if (str=="Wednesday") return 3;
	else if (str=="Thursday") return 4;
	else if (str=="Friday") return 5;
	else if (str=="Saturday") return 6;
	else if (str=="Sunday") return 7;
}

string month2str (int month)
{
	if (month==1) return "January";
	else if (month==2) return "February";
	else if (month==3) return "March";
	else if (month==4) return "April";
	else if (month==5) return "May";
	else if (month==6) return "June";
	else if (month==7) return "July";
	else if (month==8) return "August";
	else if (month==9) return "September";
	else if (month==10) return "October";
	else if (month==11) return "November";
	else if (month==12) return "December";
}

int main()
{
	int year,day,month;
	cin >> year >> day >> month;
	cout << month2str(month) << " " << year << endl;
	cout <<"     Sun     Mon     Tue     Wed     Thu     Fri     Sat" << endl;
	switch(month)
	{
		case 12:
			day+=30;
		case 11:
			day+=31;
		case 10:
			day+=30;
		case 9:
			day+=31;
		case 8:
			day+=31;
		case 7:
			day+=30;
		case 6:
			day+=31;
		case 5:
			day+=30;
		case 4:
			day+=31;
		case 3:
			if ((year%4==0&&year%100!=0)||year%400==0) day+=29;
			else day+=28;
		case 2:
			day+=31;
		case 1:;
	}
	
	day=day%7;
	for (int i=day;i>=1;i--)
		cout << "        ";

	for (int i=1;i<=dayOfMonth(year,month);i++)
	{
		cout << setw(8) << i;
		if ((i+day)%7==0) cout << endl;
	}
	
	if ((day+dayOfMonth(year,month))%7!=0) cout << endl;	

	return 0;
}
