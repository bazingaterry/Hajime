#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		for (int i = 0; i < str1.size(); ++i)
			if (str1[i] == ',')
				str1.erase(i, 1);

		for (int i = 0; i < str2.size(); ++i)
			if (str2[i] == ',')
				str2.erase(i, 1);

		long long num1 = 0;
		long long num2 = 0;

		int base = 1;
		if (str1[0] == '-')
		{
			for (int i = str1.size() - 1; i >= 1; --i)
			{
				num1 -= (str1[i] - '0') * base;
				base *= 10;
			}
		}
		else
		{
			for (int i = str1.size() - 1; i >= 0; --i)
			{
				num1 += (str1[i] - '0') * base;
				base *= 10;
			}
		}

		base = 1;
		if (str2[0] == '-')
		{
			for (int i = str2.size() - 1; i >= 1; --i)
			{
				num1 -= (str2[i] - '0') * base;
				base *= 10;
			}
		}
		else
		{
			for (int i = str2.size() - 1; i >= 0; --i)
			{
				num1 += (str2[i] - '0') * base;
				base *= 10;
			}
		}

		cout << num1 + num2 << endl;
	}

	return 0;
}
