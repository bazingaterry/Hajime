#include "iostream"
#include "cmath"
using namespace std;

bool isPrime(long long num)
{
    if (num == 1) return false;
    else
    {
        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0) return false;
        return true;
    }
}

int primeGap(int mid)
{
    int left = mid, right = mid;
    while (left && !isPrime(left)) left--;
    while (!isPrime(right)) right++;
    return left == 0 ? false : right - left;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n)
        cout << primeGap(n) << endl;
    return 0;
}
