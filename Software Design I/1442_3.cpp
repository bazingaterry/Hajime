#include <iostream>
using namespace std;

int main()
{
	int year,day=0;
	
	cin>>year;
	
	for (int y=2001;y<year;y++)
	{
		if (y%4==0) day=day+366;
		else day=day+365;
	}
	
	day=day%7 +1;
	if (day==7) day=0;

	cout << day <<endl;
	
	return 0;
}
