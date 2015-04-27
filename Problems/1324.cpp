#include <iostream>
using namespace std;

int main()
{
	int n,i,t,score,count;
	cin>>n;
	char result[100];
	for (i=1;i<=n;++i)
	{
		cin>>result;
		t=0,score=0,count=0;
		while (result[t]!='\0')
		{
			if (result[t]=='O')
			{
				count++;
				score=count+score;
			}
			else if (result[t]=='X')
			{
				count=0;
			}
			t++;
		}
		cout<<score<<endl;
	}
return 0;
}
