#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t; // t cases
	while (t--)
	{
		int count[10]{}; // contain each number count
		int n;
		cin >> n;
		while (n--)
		{
			int num;
			cin >> num;
			count[num]++;
		}
		for (int i = 0; i <= 9; ++i)
			if (count[i]!=0)
				cout << i << " " << count[i] <<endl;

	}
	return 0;
}
