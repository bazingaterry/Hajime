#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
	if (n2 == 0)
		return n1;
	else
		return gcd(n2, n1 % n2);
}

int main(int argc, char const *argv[])
{
	int n1, n2;
	cin >> n1 >> n2;
	if (n1 < n2) swap(n1, n2);
	cout << gcd(n1, n2) << endl;
	return 0;
	
}