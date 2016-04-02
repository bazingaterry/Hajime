#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		char ch[200];
		cin >> ch;
		int m=strlen(ch)/n;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;j++)
			{
				if (j&1)
					cout << ch[(j-1)*n+i-1];
				else
					cout << ch[(j-1)*n+(n-i)];
			}
		}
		cout << endl;
	}
	return 0;
}
