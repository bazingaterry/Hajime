#include "iostream"
#include "set"
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	while (cin >> N)
	{
		set<int> s;
		for (int i = 0; i < N; ++i)
		{
			int num;
			cin >> num;
			s.insert(num);
		}
		cout << s.size() << endl;
		for (set<int>::iterator it = s.begin(); it != s.end(); it++)
			if (it == s.begin())
				cout << *it;
			else
				cout << " " << *it;
		cout << endl;
	}
	return 0;
}