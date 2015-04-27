#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n >> str;
		str.erase(n-1, 1);
		for (int i = 0; i < str.size(); ++i)
		{
			str[i] = tolower(str[i]);
		}
		cout << str << endl;
	}

	return 0;
}