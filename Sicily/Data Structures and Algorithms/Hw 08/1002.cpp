#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct student
{
	int id;
	int sum;
	int chinese;
};

bool cmp(const student& s1, const student& s2)
{
	if (s1.sum > s2.sum)
		return true;
	else if (s1.sum < s2.sum)
		return false;
	else
	{
		if (s1.chinese > s2.chinese)
			return true;
		else if (s1.chinese < s2.chinese)
			return false;
		else return s1.id < s2.id;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	bool flag = false;
	while (cin >> n)
	{
		vector<student> v;
		for (int i = 0; i < n; ++i)
		{
			student s;
			int tmp1, tmp2;
			cin >> s.chinese >> tmp1 >> tmp2;
			s.sum = s.chinese + tmp1 + tmp2;
			s.id = i + 1;
			v.push_back(s);
		}

		sort(v.begin(), v.end(), cmp);
		
		if (flag) cout << endl;
		else flag = true;
		for (int i = 0; i < 5; ++i)
			cout << v[i].id << ' ' << v[i].sum << endl;
	}
	return 0;
}