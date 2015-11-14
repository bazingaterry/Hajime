#include "cstdio"
int array[1000000];
int tempArray[1000000];

long long Merge(int begin, int mid, int end)
{
	for (int i = begin; i <= end; ++i)
		tempArray[i] = array[i];

	int i = begin;
	int j = mid + 1;
	int k = begin;
	long long count = 0;

	while (i <= mid && j <= end)
	{
		if (tempArray[i] <= tempArray[j])
			array[k++] = tempArray[i++];
		else
		{
			array[k++] = tempArray[j++];
			count += (mid - i + 1);
		}
	}
    while (i <= mid)
		array[k++] = tempArray[i++];
    while (j <= end)
		array[k++] = tempArray[j++];
	
	return count;
}

long long MergeInversion(int begin, int end)
{
	long long inversions = 0;
	if (begin < end)
	{
		int mid = (begin + end)/2;
		inversions += MergeInversion(begin, mid);
		inversions += MergeInversion(mid+1, end);
		inversions += Merge(begin, mid, end);
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
