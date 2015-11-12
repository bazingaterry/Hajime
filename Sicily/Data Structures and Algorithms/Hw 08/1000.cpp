#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct element
{
	long long price;
	int number;
};

bool cmp(const element& e1, const element& e2)
{
	return e1.price > e2.price;
}

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		vector<element> v;
		for (int i = 0; i < n; ++i)
		{
			element e;
			cin >> e.price;
			e.number = i;
			v.push_back(e);
		}
		
		stable_sort(v.begin(), v.end(), cmp);

		cout << v[0].number;

		for (int i = 1; i < v.size(); ++i)
			cout << ' ' << v[i].number;
		cout << endl;
	}
	return 0;
}