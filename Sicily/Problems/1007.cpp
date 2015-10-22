#include <iostream>
#include <cstring>
using namespace std;
//toioynnkpheleaigshareconhtomesnlewx
int main()
{
	int n;
	while(1)
	{
		cin >> n;
		
		if (n==0) break;
		
		char ch[200];
		cin >> ch;
		int m=strlen(ch)/n;
	
	
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;j++)
			{
				if (j%2!=0) 
				{
					cout << ch[(j-1)*n+i-1];
				}
				else 
				{
					cout << ch[(j-1)*n+(n-i)];
				}
			}	
		}
		cout << endl;
	
	}
	
	return 0;
}
