#include "cstdio"
#include "cmath"

bool tree[10000];
int main(int argc, char const *argv[])
{
	int l,m;
	scanf("%d %d",&l,&m);
	for (int i = 0; i <= l; ++i)
		tree[i]=1;
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for (int i = a; i <= b; ++i)
			tree[i]=0;
	}
	int result=0;
	for (int i = 0; i <= l; ++i)
		if (tree[i])
			result++;
	printf("%d\n",result );
	return 0;
}
