#include "set"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while(T--)
	{
		set<int> s1, s2;
		int size;
		cin >> size;
		for (int i = 0; i < size; ++i)
		{
			int num;
			cin >> num;
			s1.insert(num);
		}
		cin >> size;
		for (int i = 0; i < size; ++i)
		{
			int num;
			cin >> num;
			s2.insert(num);
		}
		set<int>result;
		for (set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
		{
			if(!s2.count(*i))
				result.insert(*i);
		}
		for (set<int>::iterator i = result.begin(); i != result.end(); ++i)
		{
			if(i != result.begin())
				cout << " " << *i;
			else
				cout << *i;
		}
		cout << endl;
	}
	return 0;
}