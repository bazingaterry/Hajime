#include "cstdio"
bool triple[200][200][200];

int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);

	while(n--)
	{		
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		triple[a][b][c]=1;
	}
	
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (triple[a][b][c])
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
