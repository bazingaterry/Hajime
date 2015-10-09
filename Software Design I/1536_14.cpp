#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if ('a'<=str[i]&&str[i]<='z')
		{
			str[i]+='A'-'a';
		}
		else if ('A'<=str[i]&&str[i]<='Z')
		{
			str[i]+='a'-'A';
		}
		else if ('0'<=str[i]&&str[i]<='9')
		{
			str[i]='*';
		}

	}
	for (int i = str.size()-1; i >= 0; --i)
		cout << str[i];
	cout << endl;
	return 0;
}
