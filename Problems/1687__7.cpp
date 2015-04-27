#include <cstdio>
#include "cstring"

char a[25][25];
int flag[25][25];
int sum;

void DFS(int x,int y)
{
	if(a[x-1][y]=='.' && flag[x-1][y]==0)
	{
		sum++;
		flag[x-1][y]=1;
		DFS(x-1,y);
	}
	if(a[x][y-1]=='.' && flag[x][y-1]==0)
	{
		sum++;
		flag[x][y-1]=1;
		DFS(x,y-1);
	}
	if(a[x][y+1]=='.' && flag[x][y+1]==0)
	{
		sum++;
		flag[x][y+1]=1;
		DFS(x,y+1);
	}
	if(a[x+1][y]=='.' && flag[x+1][y]==0)
	{
		sum++;
		flag[x+1][y]=1;
		DFS(x+1,y);
	}
}

int main()
{
	
	int n,m,i,j;
	while(scanf("%d%d",&m,&n),m+n)
	{
		getchar();
		sum=0;
		memset(flag,0,sizeof(flag));
		memset(a,'#',sizeof(a));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]=='@')
				{
					sum++;
					flag[i][j]=1;
					DFS(i,j);
					i=n;
					j=m;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}