#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int array[101];
	while (cin >> n && n != 0)
	{

		for (int i = 0; i < n; ++i)
		{
			cin >> array[i];
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				if (abs(array[i]) < abs(array[j]))
					swap (array[i], array[j]);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (i != 0)
				cout << " ";
			cout << array[i];
		}
		cout << endl;
	}

	return 0;
}
