#include "cstdio"

int card[40];

int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i)
			card[i] = i;
		int top=1,end=n;
		while(end-top+1>=2)
		{
			printf("%d ",card[top++]);
			card[++end]=card[top++];
		}
		printf("%d \n",card[top]);
	}
	return 0;
}
