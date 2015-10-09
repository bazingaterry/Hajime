#include "iostream"
#include "cstring"

using namespace std;

int main(int argc, char const *argv[])
{
	string gift[100];
	int loc=0;
	
	int n;
	cin >> n;
	while (n--)
	{
		int q;
		cin >> q;
		if (q == 1)
			cin >> gift[loc++];
		else
		{
			string name;
			cin >> name;
			cout << name << " " << gift[--loc] << endl;
		}
	}

	return 0;
}
