#include "iostream"
#include "cmath"
using namespace std;

// Reference: Algorithm from doubleh's PPT in Algorithm Design course
int maxN(int year)
{
    int n = 0;
    int bit_len = 1 << ((year - 1960) / 10 + 2);
    double tmp = 0;
    while (tmp < bit_len)
        tmp += log(++n) / log(2);
    return n - 1;
}

int main(int argc, char const *argv[])
{
    int year;
    while (cin >> year && year)
        cout << maxN(year) << endl;
    return 0;
}
