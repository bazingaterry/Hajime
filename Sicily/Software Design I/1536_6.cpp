#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i]!='a')
			str[i]-=1;
		else
			str[i]+=25;
	}
	cout << str << endl;
	return 0;
}
