#include "iostream"
#include "string"
using namespace std;

bool isPalindrome(string str)
{
	for (int i = 0, j = str.size() - 1; i < j; ++i, --j)
	{
		if (str[i] != str[j])
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		while (isPalindrome(str) == 0)
		{
			string newstr;
			newstr = str;
			for (int i = 0, j = str.size() - 1; i < str.size(); ++i, --j)
			{
				str[i] += newstr[j] - '0'; 
			}

			long long num = 0;	//	str2num
			int base = 1;
			for (int i = str.size() - 1; i >= 0; --i)
			{
				num += (str[i] - '0') * base;
				base *= 10;
			}

			str = "";	//	num2str
			while (num != 0)
			{
				char ch;
				ch = (num % 10) + '0';
				str = ch + str;
				num = num / 10;
			}
			//cout << str << " ";

		}
		cout << str << endl;
	}
	

	return 0;
}
