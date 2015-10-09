#include "iostream"
#include "cmath"
using namespace std;

class seriesComp
{
public:
    int n;
    seriesComp(int n);
    int sum();
    int fib();
};

seriesComp::seriesComp(int input)
{
    n = input;
}

int seriesComp::sum()
{
    return (1 + n) * n / 2;
}

int seriesComp::fib()
{
    int sum = 0;
    int a = 0, b = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum += b;
        int tmp = b;
        b += a;
        a = tmp;
    }
    return sum;
}
