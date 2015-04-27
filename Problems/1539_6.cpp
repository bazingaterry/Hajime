#include "iostream"
#include "string"
using namespace std;

bool isChar (char ch)
{
	if (('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z'))
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	string str;
	while(getline(cin,str))
	{
		bool ch=0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (isChar(str[i]))
			{
				cout << str[i];
				ch=1;
			}
			else if (ch)
			{
				cout << endl;
				ch=0;
			}
		}
		if (ch)
			cout << endl;
		cout << endl;
	}
	return 0;
}
