#include "string"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str && str != "*")
	{
		bool jug = 1;
		for (int i = 0; i <= int(str.size()) - 2; ++i)	//	i-pair
		{
			bool ch[26][26] = {{}, {}};
			for (int j = 0; j + i + 1<= str.size() - 1; ++j)
			{
				if( ch[str[j] - 'A'][str[j + i + 1] - 'A'] != 0)
				{
					jug = 0;
					break;
				}
				else
				{
					ch[str[j] - 'A'][str[j + i + 1] - 'A'] = true;
				}
			}
			if (jug == 0)
				break;
		}
		if (jug)
		{
			cout << str << " is surprising.\n";
		}
		else
		{
			cout << str << " is NOT surprising.\n";
		}
	}
	return 0;
}
