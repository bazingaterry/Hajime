#include <iostream>
#include <cmath>
using namespace std;

long long qmod(long long a,long long b,long long p)
{
    if (b == 1) return a % p;
    else if (b % 2 == 0) return ((long long)pow(qmod(a, b/2, p), 2)) % p;
    else return (qmod(a, (b - 1) / 2, p) * qmod(a, (b + 1) / 2, p)) % p;
}

int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    cout << qmod(a, b, p) <<endl;  
    return 0;
}