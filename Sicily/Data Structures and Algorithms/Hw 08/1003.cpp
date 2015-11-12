#include "iostream"
#include "list"
#include "map"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
	int C, N;
	while (cin >> C >> N)
	{
		list<int> operation;
		map<int, bool> hasDone;
		for (int i = 0; i < N; ++i)
		{
			int num;
			cin >> num;
			operation.push_front(num);
		}

		list<int>::iterator it = operation.begin();
		while (it != operation.end())
		{
			if (hasDone[*it])
				it = operation.erase(it);
			else
			{
				hasDone[*it] = true;
				it++;
			}
		}

		cout << operation.size() << endl;
		bool flag = false;
		while (!operation.empty())
		{
			if (flag)
				cout << ' ';
			else
				flag = true;
			cout << operation.back();
			operation.pop_back();
		}
		cout << endl;
	}
	return 0;
}