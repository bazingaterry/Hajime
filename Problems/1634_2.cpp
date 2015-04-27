#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	string str[101];
	int count = 0;
	while(cin >> str[count++]);
	count--;
	for (int i = 0; i <= count-1; ++i)
	{
		for (int j = i; j <= count - 1 + i; ++j)
		{
			int m = j % count;
			cout << str[m] << " ";
		}
		cout << endl;
	}
	return 0;
}
