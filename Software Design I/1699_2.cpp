#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[4000];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);
	
	for (int i = 0, j = n - 1; i < j; ++i, --j)
	{
		cout << arr[i] << endl << arr[j] << endl;
	}
	if (n & 1)
		cout << arr[n / 2] << endl;


	return 0;
}