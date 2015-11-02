#include "iostream"
#include "set"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin >> n&& n != 0)
	{
		cin >> m;
		set<string> s;
		for (int i = 0; i < n; ++i)
		{
			string name;
			cin >> name;
			for (int i = 0; i < name.size(); ++i)
				name[i] = toupper(name[i]);
			s.insert(name);
		}
		for (int i = 0; i < m; ++i)
		{
			string name;
			cin >> name;
			for (int i = 0; i < name.size(); ++i)
				name[i] = toupper(name[i]);
			s.erase(name);
		}
		cout << s.size() << endl;
	}
	return 0;
}