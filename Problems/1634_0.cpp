#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	
	for (int k = 1; k <= t; k++)
	{
		bool locker[1001]{};//  0==L  //  1==O
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; j+=i)
				locker[j] = 1 - locker[j];
		
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (locker[i])
				sum++;

		cout << "test case " << k << ":" << endl;
		cout << sum << endl;
	}
	return 0;
}
