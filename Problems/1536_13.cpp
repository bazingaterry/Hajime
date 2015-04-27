#include <iostream>
using namespace std;

char gpa(double t)
{
	if (t>=4.2)
		return 'A';
	else if (t>=3.4)
		return 'B';
	else if (t>=2.6)		
		return 'C';
	else if (t>=1.8)		
		return 'D';
	else if (t>=1)
		return 'E';
	else 
		return 'F';
}

int main(int argc, char const *argv[])
{
	double a,b;
	cin >> a >> b;

	if (gpa(a)==gpa(b))
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}
