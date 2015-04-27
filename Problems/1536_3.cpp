#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double v0,c0;
	int n;
	cin >> v0 >> c0 >> n;
	
	double v1,c1;//last time data
	while (n--)
	{
		char o;
		cin >> o;
		
		if (o=='P')
		{
			v1=v0;
			c1=c0;
			double v,c;
			cin >> v >> c;
			c0=(v0*c0+v*c)/(v0+v);
			v0+=v;
			cout << fixed << setprecision(0) << v0 << fixed << setprecision(5) <<  " " << c0 << endl;
		}
		else
		{
			v0=v1;
			c0=c1;
			cout << fixed << setprecision(0) << v0 << fixed << setprecision(5) <<  " " << c0 << endl;
		}
	}
	
	
	return 0;	
}
