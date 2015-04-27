#include "iostream"
#include "cstring"
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str)
	{
		int fac[1000];
		int loc = 0;

		for (int i = 1; i <= str.size(); ++i)
			if (str.size() % i == 0)
				fac[loc++] = i;

		for (int i = 0; i < loc; ++i)
		{
			string base = str.substr(0,fac[i]);
			
			string newstr = "";

			for (int j = 1; j <= str.size()/fac[i]; ++j)
				newstr += base;

			if (newstr == str)
			{
				cout << base << endl;
				break;
			}

		}
		
		
	}
	return 0;
}
