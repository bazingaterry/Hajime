#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n&&n!=0)
	{
		int stick[101]={0};
		int count=0;
		
		for (int i=0;i<n;i++) cin >> stick[i];
		
		for (int i=0;i<n;i++)
		{
			if (count==(n-1)/2) break;
			if (stick[i]==0) continue;
			
			for (int j=i+1;j<n;j++)
			{
				if (stick[i]!=0&&stick[i]==stick[j]) 
				{
					stick[i]=0;
					stick[j]=0;
					count++;
					break;
				}
				
			}
			
		}
	
		for (int i=0;i<n;i++) if(stick[i]!=0) cout << stick[i] <<endl;
	}
	
	return 0;
}
