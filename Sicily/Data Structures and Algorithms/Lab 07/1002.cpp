#include "iostream"
#include "cmath"
using namespace std;

long double f(long double x)
{
	return exp(x) + log(x) - 1;
}

long double solve(long double y)
{
    long double left = 0;
    long double right = 24;
    long double mid = (left + right) / 2;
    while (left <= right)
    {
    	if (abs(f(mid) - y) < 1e-6)
    		return mid;
    	else if (f(mid) > y)
    		right = mid;
    	else
    		left = mid;
    	mid = (left + right) / 2;
    }
}

/*
int main(int argc, char const *argv[])
{
	for (long long i = 1; i < 1e10; i *= 10)
	{
		cout << "y = " << i << " x = " solve(i) << endl;
	}
	return 0;
}
*/