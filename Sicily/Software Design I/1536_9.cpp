#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	long long x0,y0,x1,y1,x2,y2;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
	
	double l1=pow((x0-x1),2)+pow((y0-y1),2);
	double l2=pow((x1-x2),2)+pow((y1-y2),2);
	double l3=pow((x0-x2),2)+pow((y0-y2),2);

	if (l2+l3<l1||l2+l1<l3)	
		cout << "Danger\n";
	else
		cout << "Safe\n";


	return 0;
}
