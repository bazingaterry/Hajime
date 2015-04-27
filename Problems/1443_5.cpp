#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	double a;
	cin >> a;
	if (a<-1) a=a+1;
	else if (-1<=a&&a<1) a=abs(a);
	else if (a>=1) a=log10(a);
	cout << fixed << setprecision(2) << a << endl;
}
