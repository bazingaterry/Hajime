#include <iostream>
#include <cmath>

int sumDigits(int num)
{
	num = abs(num);
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}
