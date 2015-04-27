#include <iostream>
using namespace std;


int main()
{
	int n,p,test=3,i;
	int prime[10000]={2};
	cin>>n;
	for (p=1;p<=n-1;)
	{
		for (i=0;i<=p-1;i++) if (test%prime[i]==0) break;
		if (i==p) 
		{
		prime[p]=test;
		++p;
		}
		test+=2;
	}
	cout<<prime[n-1]<<endl;
		
return 0;
}
