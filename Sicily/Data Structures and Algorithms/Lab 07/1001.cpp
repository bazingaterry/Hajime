#include "iostream"
#include "vector"
using namespace std;

bool tryK(const vector<long long>& v, long long m, long long k)
{
	long long count = 0;
	long long index = 0;
	long long sum = 0;
	for (int index = 0; index < v.size(); ++index)
	{
		if (v[index] > k) 
			return false;
		else
		{
			if (sum + v[index] <= k)
					sum += v[index];
				else
				{
					count++;
					sum = v[index];
				}
		}
	}
	count++;
	return count <= m;
}

long long findMin(const vector<long long>& v, long long m)
{
	long long left = v.size();
	long long right = 10e9;
	long long mid = (left + right) / 2;
	while (left < right)
	{
		if (tryK(v, m, mid))
			right = mid;
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	return mid;
}

int main(int argc, char const *argv[])
{
	long long n, m;
	while (cin >> n >> m)
	{
		vector<long long> v;
		for (int i = 0; i < n; ++i)
		{
			long long num;
			cin >> num;
			v.push_back(num);
		}
		cout << findMin(v, m) << endl;
	}
	return 0;
}