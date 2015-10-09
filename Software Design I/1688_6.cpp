#include "bits/stdc++.h"
using namespace std;

class arr
{
public:
	arr()
	{
		valid = false;
	}
	int begin;
	int end;
	bool valid;
};

int main(int argc, char const *argv[])
{
	arr list[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> list[i].begin >> list[i].end;
		list[i].valid = true;
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (list[i].begin > list[j].begin)
			{
				swap(list[i].begin, list[j].begin);
				swap(list[i].end, list[j].end);
			}
		}
	}

	for (int i = 0; i < n - 1; ++i)
	{
		if (list[i].valid)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (list[j].valid && list[i].end >= list[j].begin)
				{
					if (list[i].end < list[j].end)
						list[i].end = list[j].end;
					list[j].valid = false;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (list[i].valid)
		{
			cout << list[i].begin << " " << list[i].end << endl;
		}
	}

	return 0;
}