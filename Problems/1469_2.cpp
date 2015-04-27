#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double d2r (double degrees)
{
	double radius = 3.14159 * degrees / 180;
	return radius;
}

int main()
{
	double x1,x2,y1,y2;
	
	cin >> x1 >> y1 >> x2 >> y2;
	
	x1=d2r(x1);
	x2=d2r(x2);
	y1=d2r(y1);
	y2=d2r(y2);
	
	cout << fixed << setprecision(2) << 6371.01 * acos( sin(x1)*sin(x2) + cos(x1)*cos(x2)*cos(y1-y2) ) << endl;
	
	
	return 0;
}
