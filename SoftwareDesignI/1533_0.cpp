#include <iostream>
#include <string>
using namespace std;

bool isLeap (int year)
{
    if ((year%4==0&&year%100!=0)||year%400==0) return 1;
    else return 0;
}

int dayofmonth (int month,int year)
{
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
    else if (month==4||month==6||month==9||month==11) return 30;
    else if (month==2 && isLeap(year)) return 29;
    else return 28;
}

int main()
{
    int year,month;
    string str[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    cin >> year >> month;
    cout << str[month-1] << " " << year << " has " << dayofmonth (month,year) << " days\n";
    
    return 0;
}                                 
