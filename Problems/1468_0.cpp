#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int level;
	
	cin >> level;
	
	for (int i=1;i<=level;i++)//the i column
	{
		for (int j=1;j<=level-i;j++)//print the space
		{
			cout << "     ";
		}
		
		for (int j=1;j<=i;j++)//print the left half numbers
		{
			cout << setw(5) << pow(2,j-1);
		}
		
		for (int j=i-1;j>=1;j--)//print the right half numbers
		{
			cout << setw(5) << pow(2,j-1);
		}
		
		cout << endl;
	}	
	
	return 0;
}
