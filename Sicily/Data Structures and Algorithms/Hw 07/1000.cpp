int binSearch(const int arr[], const int size, const int target)
{
	int left = 0;
	int right = size - 1;
	int middle;
	
	while(left <= right)
	{
		middle = (right + left) / 2;
		if (arr[middle] < target)
		{
			left = middle + 1;
		}
		else if (arr[middle] == target)
		{
			while(arr[middle] == target)
				middle++;
			return middle - 1;
		}
		else if (arr[middle] > target)
		{
			right = middle - 1;
		}
	}
	return -1;
}