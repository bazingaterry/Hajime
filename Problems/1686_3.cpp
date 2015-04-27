#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str;
		int dir = 100;

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == 'L')
				dir--;
			else
				dir++;
		}

		if (dir % 4 == 0)
			cout << "N\n";
		else if (dir % 4 == 1)
			cout << "E\n";
		else if (dir % 4 == 2)
			cout << "S\n";
		else if (dir % 4 == 3)
			cout << "W\n"; 
	}
	

	return 0;
}
