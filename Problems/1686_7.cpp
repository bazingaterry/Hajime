#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, n;
	while (cin >> a >> b >> n && (a != 0 || b != 0 || n != 0))
	{
		long long fn[10010];
		fn[1] = 1;
		fn[2] = 1;
		for (int i = 3; i <= n; ++i)
		{
			fn[i] = (a * fn[i - 2] + b * fn[i - 1]) % 10;
		}
		cout << fn[n] << endl;
	} 
	

	return 0;
}
