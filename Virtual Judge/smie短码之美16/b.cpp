#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string XhcToM (int x, int m)
{
	if (x == 0)
		return "0";
	else
	{
		string result;
        bool isMin = false;
        if (x < 0)
        {
            isMin = true;
            x = -x;
        }
		while(x != 0)
		{
			string mod;
			if (0 <= x % m && x % m <= 9)
				mod = x % m + 48;
			else
				mod = x % m + 55;
			result = mod + result;
			x = x / m;
		}
		if (isMin)
            return '-' + result;
        else
            return result;
	}
}

int main(int argc, char const *argv[])
{
	int m;
	int s;
	while (cin >> s >> m)
		cout << XhcToM(s, m) << endl;
	return 0;
}