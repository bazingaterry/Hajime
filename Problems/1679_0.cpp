#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isH (int num)
{
	string str;
	while (num != 0)
	{
		str = char(num % 10 +'0') + str;
		num /= 10;
	}

	for (int i = 1; i <= str.size() - 2; ++i)
	{
		if (str[i] + '0' != str[i-1] + str[i+1] && str[i] - '0' != abs(str[i-1] - str[i+1]))
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	if (n <= 99)
	{
		cout << n << endl;
	}
	else
	{	
		int count = 99;
		for (int i = 100; i <= n; ++i)
		{
			if (isH(i))
				count++;
		}
		cout << count << endl;
	}

	return 0;
}
