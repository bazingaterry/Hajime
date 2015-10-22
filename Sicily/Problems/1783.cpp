#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		char str[102];
		cin >> str;
		int i = 0;
		while (i <= strlen(str) - 1)
		{
			while (str[i] == '0' && i <= strlen(str) - 1)
				i++;

			int begin = i;

			while (str[i] != '0' && i <= strlen(str) - 1)
				i++;

			int end = i;

			sort(str + begin, str + end, cmp);
		}
			cout << str << endl;
	}
	return 0;
}
