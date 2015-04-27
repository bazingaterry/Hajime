#include "iostream"
using namespace std;

long factorial(int n)
{
	long result=1;
	for (int i = 1; i <= n; ++i)
	{
		result*=i;
	}
	return result;

}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << factorial(n);
	return 0;
}
