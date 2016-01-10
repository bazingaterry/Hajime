#include "iostream"
#include "queue"
#include "vector"
using namespace std;

struct cmp
{
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		priority_queue<int, vector<int>, cmp> pq;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			pq.push(num);
		}
		while (pq.size() >= 2)
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << pq.top() << endl;
	}
	return 0;
}