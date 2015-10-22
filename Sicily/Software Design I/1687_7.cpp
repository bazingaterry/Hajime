#include "cstdio"
#include "cstring"

int sum;
char ch[25][25];
bool jug[25][25];

void dfs(int x, int y)
{
	if(ch[x-1][y]=='.' && jug[x-1][y]==0)
	{
		sum++;
		jug[x-1][y]=1;
		dfs(x-1,y);
	}

	if(ch[x][y-1]=='.' && jug[x][y-1]==0)
	{
		sum++;
		jug[x][y-1]=1;
		dfs(x,y-1);
	}

	if(ch[x][y+1]=='.' && jug[x][y+1]==0)
	{
		sum++;
		jug[x][y+1]=1;
		dfs(x,y+1);
	}

	if(ch[x+1][y]=='.' && jug[x+1][y]==0)
	{
		sum++;
		jug[x+1][y]=1;
		dfs(x+1,y);
	}
}


int main(int argc, char const *argv[])
{
	int n, m;
	while (scanf("%d%d", &n, &m) && m + n)
	{	
		getchar();

		sum = 0;
		memset( jug, false, sizeof(jug) );
		memset( ch, '#', sizeof(ch) );

		int x, y;
		for (int i = 0; i < m; ++i)	//	read
		{
			for (int j = 1; j <= n; ++j)
			{
				scanf("%c",&ch[i][j]);
				if (ch[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
			getchar();
		}
		
		sum++;
		jug[x][y] = true;
		dfs(x, y);

		printf("%d\n", sum);
	}

	return 0;
}
