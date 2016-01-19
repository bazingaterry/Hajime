#include <string>
#include <iostream>
using namespace std;

string str = "ABCDEFGHIJKLMNOPQRSTUVW";

void recursion(const string& s, int begin, int end)
{
	if (begin == end) return;
	else
	{
		cout << s + str[begin] << endl;
        recursion(s + str[begin], begin + 1, end);
		recursion(s, begin + 1, end);
	}
}

int main()
{
    int n;
    cin >> n;
    string s;
    cout << endl;
    recursion(s, 0, n);
}