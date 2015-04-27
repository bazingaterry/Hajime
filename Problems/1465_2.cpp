#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int a,b,c;
	cin >> a >>  b >> c;
	if (a>b) 
	{
		a=b-a;
		b=b-a;
		a=b+a; 
	}
	if (b>c)
	{
		b=c-b;
		c=c-b;
		b=c+b;
	}
	if (a>b) 
	{
		a=b-a;
		b=b-a;
		a=b+a; 
	}
	
	cout << a << " " << b << " " << c <<endl;
	
	
	return 0;
}
