#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		string str[3];
		cin >> str[0] >> str[1] >> str[2];
		
		if (str[0].size()<str[1].size()&&str[0].size()<str[2].size())
		{
			cout << str[0];
			if (str[1].size()<str[2].size())
				cout << str[1] << str[2] << endl;
			else
				cout << str[2] << str[1] << endl;
		}
		
		if (str[1].size()<str[0].size()&&str[1].size()<str[2].size())
		{
			cout << str[1];
			if (str[0].size()<str[2].size())
				cout << str[0] << str[2] << endl;
			else
				cout << str[2] << str[0] << endl;
		}
		
		if (str[2].size()<str[1].size()&&str[2].size()<str[0].size())
		{
			cout << str[2];
			if (str[1].size()<str[0].size())
				cout << str[1] << str[0] << endl;
			else
				cout << str[0] << str[1] << endl;
		}
		
		
	}
	
	
	return 0;
}
