#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if (dist==0)
		cout << "4\n";
	else if (dist<abs(r1-r2))
		cout << "6\n";
	else if (dist==abs(r1-r2))
		cout << "5\n";
	else if (dist<(r1+r2))
		cout << "3\n";
	else if (dist==r1+r2)
		cout << "2\n";
	else
		cout << "1\n";


	return 0;
}
