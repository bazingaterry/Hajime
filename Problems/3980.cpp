#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int hcToX (string str,int m)
{
	long long result=0;

	for (int i=0;i<str.size();i++)
	{
		if (48<=str[i]&&str[i]<=57) result+=(str[i]-48)*pow(m,str.size()-i-1);//number
		else result+=(str[i]-55)*pow(m,str.size()-i-1);//letter
	}
		
		return result;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		cout << hcToX (str,2) << endl;
	}
	
	return 0;
}
