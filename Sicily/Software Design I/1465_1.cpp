#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int mark;
	
	cin >> mark;
	if (mark<0||mark>100) cout << "Invalid" <<endl;
	else if (mark<60) cout << "Failed" <<endl;
	else cout << fixed << setprecision(1) << (mark-50.0)/10 << endl;
	
	return 0;
}
