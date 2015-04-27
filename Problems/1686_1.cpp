#include "iostream"
#include "iomanip"
#include "algorithm"
#include "cmath"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j) // blank
		{
			cout << "     ";
		}

		for (int j = 0; j <= n - i; ++j)
		{
			cout << setw(5) << pow(2,j);
		}

		for (int j = n - i - 1; j >= 0 ; --j)
		{
			cout << setw(5) << pow(2,j);
		}

		cout << endl;
	}
	
	return 0;
}
