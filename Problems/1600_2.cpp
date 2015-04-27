#include "iostream"
#include "cstring"
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str)
	{
		string odd = "";
		string even = "";
		for (int i = 0; i < str.size(); ++i)
		{
			if (i&1)
				odd += str[i]; 
			else
				even += str[i];
		}
		cout << even << "," << odd << endl;
	}
	return 0;
}
