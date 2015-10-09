#include <iostream>
using namespace std;

int MOD;

struct mat
{
	int m[2][2];
};

mat matMultiMod(mat a,mat b) // 2x2 matrix multi mod
{
	mat result;
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			result.m[i][j]=((a.m[i][0]*b.m[0][j])%MOD+(a.m[i][1]*b.m[1][j])%MOD)%MOD;
		}
	}
	return result;
}


int fast_mod(int n)
{
	mat ans,base;
	base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
	base.m[1][1] = 0;
	ans.m[0][0] = ans.m[1][1] = 1;
	ans.m[0][1] = ans.m[1][0] = 0;

	while(n)
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
	int n;
	while(cin>>n>>MOD)
	{
		if (n==-1||MOD==-1) break;
		cout<<fast_mod(n)<<endl;
	}
return 0;
}

