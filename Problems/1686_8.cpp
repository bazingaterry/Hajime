#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		int count[200][2] = {{}, {}};

		string str1, str2;
		cin >> str1 >> str2;

		for (int i = 0; i < str1.size(); ++i)
		{
			count[str1[i]][0]++;
		}

		for (int i = 0; i < str2.size(); ++i)
		{
			count[str2[i]][1]++;
		}

		for (int i = 'a'; i <= 'z'; ++i)
		{
			for (int j = 1; j <= min(count[i][0],count[i][1]); ++j)
			{
				char ch = i;
				cout << ch;
			}
		}
		cout << endl;
	}
	

	return 0;
}
