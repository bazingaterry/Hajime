#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int k, x;
    cin >> k >> x;
    string str[20];
    cin >> str[1] >> str[2];
    for (int i = 3; i <= k; ++i)
        str[i] = str[i - 2] + str[i - 1];
    int count = 0;
    for (int i = 0; i < str[k].size() - 1; ++i)
    {
        char ch1 = str[k][i];
		char ch2 = str[k][i + 1];
		string tmp = "";
		tmp += ch1;
		tmp += ch2;
		if (tmp == "AC")
            count++;
    }
    if (count == x)
        cout << "Accepted\n";
    else
        cout << "Forever alone\n";
	return 0;
}
