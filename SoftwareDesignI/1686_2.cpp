#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	string str[10];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << str[j][i];
		}
		cout << endl;
	}

	

	return 0;
}
