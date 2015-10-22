#include <cstdio>
using namespace std;

int main()
{
	int n;
	int p[5000];
	int rank[5000];
	
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&p[i]);
	
	int rk=1;
	for (int score=100;score>=0;score--)
	{
		int temp=0;
		for (int i=0;i<n;i++)
		{
			
			if (p[i]==score)
			{
				rank[i]=rk;
				temp++;
			}
		}
		rk=rk+temp;
	}
	
	for (int i=0;i<n;i++) printf("%d\n",rank[i]);
	
	return 0;
}
