#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int dayofmonth(int year,int month)
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
	string str;

	day=day%7;

	if (day==1) str="Monday";
	else if (day==2) str="Tuesday";
	else if (day==3) str="Wednesday";
	else if (day==4) str="Thursday";
	else if (day==5) str="Friday";
	else if (day==6) str="Saturday";
	else if (day==0) str="Sunday";
	
	return str;
}

int str2day (string str)
{
	int day;
		
	if (str=="Monday") day=1;
	else if (str=="Tuesday") day=2;
	else if (str=="Wednesday") day=3;
	else if (str=="Thursday") day=4;
	else if (str=="Friday") day=5;
	else if (str=="Saturday") day=6;
	else if (str=="Sunday") day=7;
	
	return day;	
}

string month2str (int month)
{
	string str;

	if (month==1) str="January";
	else if (month==2) str="February";
	else if (month==3) str="March";
	else if (month==4) str="April";
	else if (month==5) str="May";
	else if (month==6) str="June";
	else if (month==7) str="July";
	else if (month==8) str="August";
	else if (month==9) str="September";
	else if (month==10) str="October";
	else if (month==11) str="November";
	else if (month==12) str="December";
	
	return str;
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
	{
		cout << "        ";
	}

	for (int i=1;i<=dayofmonth(year,month);i++)
	{
		cout << setw(8) << i;
		if ((i+day)%7==0) cout << endl;
	}
	
	if ((day+dayofmonth(year,month))%7!=0) cout << endl;	
	
	return 0;
}
