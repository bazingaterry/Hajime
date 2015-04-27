#include "cstdio"
#include "utility"
using namespace std;

class student
{
public:
	int a;
	int b;
};

student stu[10010];
int n, s;

void sort(int left, int right)
{
	int i, j, t;
	student tmp;
	if (left > right)
	{
		return;
	}

	tmp = stu[left];
	i = left;
	j = right;

	while (i != j)
	{
		while (stu[j].b >= tmp.b && i < j)
			j--;
		while (stu[i].b <= tmp.b && i < j)
			i++;

		if (i < j)
		{
			swap(stu[i], stu[j]);
		}
	}

	stu[left] = stu[i];
	stu[i] = tmp;

	sort(left, i-1);
	sort(i+1, right);
	return;
}

int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &n, &s) && n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &stu[i].a, &stu[i].b);
		}

		sort(0, n-1);

		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			if (s >= stu[i].b)
			{
				s += stu[i].a;
			}
			else
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}