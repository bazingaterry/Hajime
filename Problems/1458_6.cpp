#include <iostream>
#include <iomanip>

using namespace std;


int main ()
{
	double a;
	while (cin >> a)
	{
		cout << fixed << setprecision(10) << a << endl;
	}
	return 0;
}
