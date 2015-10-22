#include "cstdio"
#include "cmath"
using namespace std;


int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int list[100000];
	
	for (int i=0;i<n;++i)
		scanf("%d",&list[i]);

	int highest=list[n-1];
	for (int i=n-1;i>=0;i--)
	{
		if (list[i]>highest)
			highest=list[i];
		list[i]=highest;
	}


	while(m--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",list[x-1]);
	}

	
	return 0;
}
