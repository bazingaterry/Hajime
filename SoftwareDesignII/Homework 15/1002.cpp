#include "string"
#include "iostream"
#include "stdexcept"
using namespace std;

int parseHex(string hexString)
{
	int result = 0;
	int base = 1;
	for (int i = hexString.size() - 1; i >= 0; --i)
	{
		if ('A' <= hexString[i] && hexString[i] <= 'Z')
		{
			hexString[i] -= 'A' - 'a';
		}
		if ('a' <= hexString[i] && hexString[i] <= 'f')
		{
			result += (hexString[i] - 'a' + 10) * base;
		}
		else if ('0' <= hexString[i] && hexString[i] <= '9')
		{
			result += (hexString[i] - '0') * base;
		}
		else
			throw runtime_error("Hex number format error");

		base *= 16;
	}
	return result;
}

int main()
{
	string s;
	while (cin >> s)
	{
		try
		{
			cout << parseHex(s) << endl;
		}
		catch (runtime_error& ex)
		{
			cout << ex.what() << endl;
		}
	}
	return 0;
}
