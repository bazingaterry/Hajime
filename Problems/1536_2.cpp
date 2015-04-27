#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if (dist==0)
		cout << "coincide\n";
	else if (dist<abs(r1-r2))
		cout << "containing\n";
	else if (dist==abs(r1-r2))
		cout << "internally-tangent\n";
	else if (dist<(r1+r2))
		cout << "intersection\n";
	else if (dist==r1+r2)
		cout << "externally-tangent\n";
	else
		cout << "disjoint\n";


	return 0;
}
