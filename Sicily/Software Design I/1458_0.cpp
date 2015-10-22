#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	char ch [80];
	int i,l,k;

	cin >> i;

	for (int t=0;t<i;t++)
	{
		cin >> k;
		cin >> ch;

		int s=0;

		while (ch[s]!='\0')
		{
			if (s!=k-1) cout << ch[s];
			s++;
		}
		cout << endl;
	}
	return 0;
}
