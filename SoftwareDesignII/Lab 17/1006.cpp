#include "iostream"
#include "string"
using namespace std; 

const int SIZE = 110;

int toNum(char ch)
{
	if('0' <= ch && ch <= '9')
		return ch - '0';
	else
		return ch - 'A' + 10;
}

char toChar(int num)
{
	if(0 <= num && num <= 9)
		return num + '0';
	else
		return num + 'A' - 10;
}

int find(int* arr)
{
	for (int i = 0; i < SIZE; ++i)
	{
		if(arr[i] != 0)
			return i;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while(T--)
	{
		int base;
		string s1, s2;
		cin >> base >> s1 >> s2;
		int result[SIZE] = {};
		for (int i = 0; i < s1.size(); ++i)
		{
			result[SIZE - i - 1] += toNum(s1[s1.size() - 1 - i]); 
		}
		for (int i = 0; i < s2.size(); ++i)
		{
			result[SIZE - i - 1] += toNum(s2[s2.size() - 1 - i]);
		}
		for (int i = SIZE - 1; i > 0; --i)
		{
			if (result[i] >= base)
			{
				result[i - 1] += result[i] / base;
				result[i] = result[i] % base;
			}
		}
		for (int i = find(result); i < SIZE; ++i)
		{
			cout << toChar(result[i]);
		}
		cout << endl;
	}
	return 0;
}