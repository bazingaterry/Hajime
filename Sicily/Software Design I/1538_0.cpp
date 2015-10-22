#include "iostream"
#include "cmath"
using namespace std;


int main(int argc, char const *argv[])
{
	double a,b;
	cin >> a >> b;
	if (abs(a-b)<1e-6)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
