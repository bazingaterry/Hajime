#include "iostream"
using namespace std;

long long fastMulMod(long long a, long long b, long long m)
{
	long long result = 0;
	long long base = a;
	while (b)
	{
		if (b & 1)
			result = (result + base) % m;
		base = (base * 2) % m;
		b >>= 1;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		long long arr[110];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		long long m;
		cin >> m;
		long long result = 1;
		for (int i = 0; i < n; ++i)
			result = fastMulMod(arr[i] % m, result, m);
		cout << result << endl;
	}
	return 0;
}