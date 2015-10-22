#include <iostream>
using namespace std;

int main()
{
	double gpa;
	cin >> gpa;
	if (gpa>=4.2) cout << "A" <<endl;
	else if (gpa<4.2&&gpa>=3.4) cout << "B" <<endl;
	else if (gpa<3.4&&gpa>=2.6) cout << "C" <<endl;
	else if (gpa<2.6&&gpa>=1.8) cout << "D" <<endl;
	else if (gpa<1.8&&gpa>=1) cout << "E" <<endl;
	else cout << "F" <<endl;
	return 0;
}
