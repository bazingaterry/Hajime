#include <iostream>
#include <algorithm>
using namespace std;

char num[100000000]={0};
int loc=0; //length of the num


int main()
{
	int n;
	cin >> n;
	
	while (n>=10)
	{
		for (int i=9;i>=1;i--)
		{
			if (i==1)
			{
				cout << "There is no such number.\n";
				return 0;
			}
			
			if (n%i==0)
			{
				num[loc]=i+48;
				loc++;
				n=n/i;
				break;
			}
		}
		
	}
	num[loc]=n+48;
	loc++;
	
	sort (num,num+loc);
	for (int i=0;i<loc;i++)
		cout << num[i];
	cout << endl;
	
	return 0;
}
	
