#include "bits/stdc++.h"
using namespace std;

enum MONTH {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

class Date
{
private:
	int year;
	MONTH month;
	int day; 

public:
	Date(int y, MONTH m, int d);  
	int operator[] (const char* s);
};

class IllegalSubscriptException
{
public:
	const char* what()
	{
		return "Illegal Subscript Exception";
	}
};

Date::Date(int y, MONTH m, int d) : year(y), month(m), day(d)
{
}

int Date::operator[] (const char* s)
{
	if (strcmp(s, "year") == 0)
		return year;
	else if (strcmp(s, "month") == 0)
		return month;
	else if (strcmp(s, "day") == 0)
		return day;
	else
		throw IllegalSubscriptException();
}

int main()
{
	Date date1(2011, APR, 1);
	try
	{
		cout << date1["year"] << endl;
	}
	catch (IllegalSubscriptException ex)
	{
		cout << ex.what() << endl;
	}
	
	try
	{
		cout << date1["month"] << endl;
	}
	catch (IllegalSubscriptException ex)
	{
		cout << ex.what() << endl;
	}
	
	try
	{
		cout << date1["day"] << endl;
	}
	
	catch (IllegalSubscriptException ex)
	{
		cout << ex.what() << endl;
	}
	
	try
	{
		cout << date1["abc"] << endl;
	}
	catch (IllegalSubscriptException ex)
	{
		cout << ex.what() << endl;
	}
	
	return 0;
}
