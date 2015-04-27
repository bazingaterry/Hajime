#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n && n != 0)
	{
		int* arr = new int[n];

		for (int i = 0; i < n; ++i)
			cin >> arr[i];



		int round = 0;

		while (true)
		{
			int tmp1 = arr[n - 1] / 2;
			int tmp2 = 0;
			for (int i = 0; i < n - 1; ++i)
			{
				tmp2 = arr[i] / 2;
				arr[i] = arr[i] / 2 + tmp1;
				tmp1 = tmp2;
				
				if (arr[i] & 1)
					arr[i]++;
			}

			arr[n - 1] = arr[n - 1] / 2 + tmp1;

			if (arr[n - 1] & 1)
				arr[n - 1]++;

			round++;

			bool same = true;
			for (int i = 0; i < n - 1; ++i)
			{
				if (arr[i] != arr[i + 1])
				{	
					same = false;
					break;
				}
			}
			if (arr[n - 1] != arr[0])
				same = false;

			if (same)
				break;

		}
		cout << round << " " << arr[0] << endl;

		delete arr;
	}

	return 0;
}
