#include <iostream>
#include <string>
using namespace std;

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



int main()
{
	int year,day;
	
	cin >> year >> day;
	
	cout << "January 1, " << year << " is " << day2str(day) << endl;
	
	day+=31;
	cout << "February 1, " << year << " is " << day2str(day) << endl;
	
	if ((year%4==0&&year%100!=0)||year%400==0) day+=29;
	else day+=28;
	cout << "March 1, " << year << " is " << day2str(day) << endl;
	
	day+=31;
	cout << "April 1, " << year << " is " << day2str(day) << endl;
	
	day+=30;
	cout << "May 1, " << year << " is " << day2str(day) << endl;
	
	day+=31;
	cout << "June 1, " << year << " is " << day2str(day) << endl;
	
	day+=30;
	cout << "July 1, " << year << " is " << day2str(day) << endl;
	
	day+=31;
	cout << "August 1, " << year << " is " << day2str(day) << endl;
	
	day+=31;
	cout << "September 1, " << year << " is " << day2str(day) << endl;
	
	day+=30;
	cout << "October 1, " << year << " is " << day2str(day) << endl;
	
	day+=31;
	cout << "November 1, " << year << " is " << day2str(day) << endl;
	
	day+=30;
	cout << "December 1, " << year << " is " << day2str(day) << endl;
	
	
	
	return 0;
}
