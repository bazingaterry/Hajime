#include "cstdio"
int array[1000000];
int tempArray[1000000];

long long Merge(int beg, int mid, int end)
{
	for (int i = beg; i <= end; ++i)
		tempArray[i] = array[i];

	int i = beg;
	int j = mid + 1;
	int k = beg;
	long long inversion = 0;

	while (i <= mid && j <= end)
	{
		if (tempArray[i] <= tempArray[j])
			array[k++] = tempArray[i++];
		else
		{
			array[k++] = tempArray[j++];
			inversion += (mid - i + 1);
		}
	}
    while (i <= mid)
		array[k++] = tempArray[i++];
    while (j <= end)
		array[k++] = tempArray[j++];
	
	return inversion;
}

long long MergeInversion(int beg, int end)
{
	long long inversions = 0;
	if (beg < end)
	{
		int mid = (beg + end) / 2;
		inversions += MergeInversion(beg, mid);
		inversions += MergeInversion(mid + 1, end);
		inversions += Merge(beg, mid, end);
	}
	return inversions;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &array[i]);

	printf("%lld\n", MergeInversion(0, n-1));

	return 0;
}
