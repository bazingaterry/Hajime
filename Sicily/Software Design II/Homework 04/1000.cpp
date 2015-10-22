#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class seriesComp
{
public:
	int n;
	seriesComp(int n);
	int sum();
	int fib();
	double taylor(double x);
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

double seriesComp::taylor(double x)
{
    double result = 1;
    double base = 1;
    for (int i = 1; i <= n; ++i)
    {
        base *= i;
        result += pow(-1, i) * pow(x, i) / base;
    }
    return result;
}

int main() {
    int T;
    int n;
    double x;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        seriesComp mySeriesComp(n);
        cout << mySeriesComp.sum() << ' ' <<
        mySeriesComp.fib() << ' ' << mySeriesComp.taylor(x) <<
        endl;
    }
    return 0;
}
