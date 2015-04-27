#include "cstdio"
#include "iostream"
using namespace std;

class People
{
public:
	int value;
	int next;
};

class Circuit
{
public:
	Circuit(int n)
	{
		people = new People[2 * n];

		for (int i = 0; i < n; ++i)
		{
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			people[tmp1 - 1].value = i;
			people[tmp2 - 1].value = i;
		}

		for (int i = 0; i < 2 * n; ++i)
		{
			people[i].next = i + 1;
		}
		people[2 * n - 1].next = 0;

		all = 2 * n;
	}

	~Circuit()
	{
		delete people;
	}

	void match()
	{
		int setp = 0;
		int now = 0;
		while (all != 0 && setp <= all + 5)	//	for safety
		{
			if (people[ people[now].next ].value == people[ people[ people[now].next ].next ].value)
			{
				people[now].next = people[ people[ people[now].next ].next ].next;
				all -= 2;
				setp = 0;
			}

			now = people[now].next;
			setp++;
		}

		if (all == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	People* people;
	int all;
	
};

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n && n != 0)
	{
		Circuit circuit(n);
		circuit.match();
	}
	return 0;
}

