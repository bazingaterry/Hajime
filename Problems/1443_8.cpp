#include <iostream>
using namespace std;

int main()
{
	double x,y;
	double ax,ay,bx,by;
	
	cin >> x >> y;
	cin >> ax >> ay >> bx >> by;
	bool in=(((ax<=x&&x<=bx)||(bx<=x&&x<=ax))&&(ay<=y&&y<=by)||by<=y&&y<=ay);
	if (((y-ay)*(bx-ax))==((by-ay)*(x-ax))&&in) cout << "Yes" << endl;
	else cout << "No" <<endl;
	return 0;
}
