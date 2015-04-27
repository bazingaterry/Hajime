#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	int v0=0;
	double dis=0;
	cin >> n;

	while (n--)
	{
		int t,a,vt;
		cin >> t >> a;
		vt=v0+a*t;
		dis+=t*(double)(v0+vt)/2.0;
		v0=vt;
	}

	cout << fixed << setprecision(2) << dis << endl;



	return 0;
}
