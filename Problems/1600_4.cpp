#include "iostream"
#include "cstring"

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str)
	{
		int loc;
		for (loc = 0; loc < str.size(); ++loc)
			if (str[loc] == '+' || str[loc] == '-')
				break;

		int num1 = 0;
		int num2 = 0;
		int base = 1;
		for (int i = loc-1; i >= 0; --i)
		{
			num1 += (str[i] - '0') * base;
			base *= 10;
		}
		base = 1;
		for (int i = str.size()-1; i >= loc + 1; --i)
		{
			num2 += (str[i] - '0') * base;
			base *= 10;
		}

		if (str[loc] == '+')
			cout << num1 + num2 << endl;
		else
			cout << num1 - num2 << endl;

	}

	return 0;
}
