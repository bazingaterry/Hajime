#include <iostream>
using namespace std;

const long long MOD = 1000000007;

class mat
{
public:
	long long m[2][2];
};

mat matMultiMod(const mat& a, const mat& b) // 2x2 matrix multi mod
{
	mat result;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result.m[i][j] = ((a.m[i][0] * b.m[0][j]) % MOD+(a.m[i][1] * b.m[1][j]) % MOD) % MOD;
		}
	}
	return result;
}


long long fast_mod(long long n)
{
	mat ans, base;
	base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
	base.m[1][1] = 0;
	ans.m[0][0] = ans.m[1][1] = 1;
	ans.m[0][1] = ans.m[1][0] = 0;

	while (n)
	{
		if(n & 1)
			ans = matMultiMod(ans, base);
		base = matMultiMod(base, base);
		n >>= 1;
	}
	return ans.m[0][1];
}

int main()
{
	long long n;
	while (cin >> n)
		cout << fast_mod(n) << endl;
	return 0;
}

