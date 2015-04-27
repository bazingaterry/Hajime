#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	int num[105]={0};
	num[104]=1;
	cin >> n;
	while(n--)
	{
		for (int i=104;i>=0;i--)//multiply
			num[i]*=3;
		for (int i=104;i>=0;i--)
		{
			if (num[i]>=10)//up
			{
				int k=i;
				while(num[i]>=10)
				{
					num[k-1]+=num[i]/10;
					num[k]=num[i]%10;
					k--;
				}
			}
		}
		
	}
	
	int k;
	for (k=0;k<=104;k++)
	{
		if (num[k]!=0)
		{
			for (;k<=104;k++)
				cout<<num[k];
			cout << endl;
			break;
		}
	}
	

		
	
	return 0;
}
