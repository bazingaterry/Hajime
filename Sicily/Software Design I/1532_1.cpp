#include <iostream>
using namespace std;

void printMatrix(int n)
{	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==1||j==1||i==j) 
				cout << " 1";
			else 
				cout << " 0";
		}
		cout << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		printMatrix(n);
	}

	return 0;
}
