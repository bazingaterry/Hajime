#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int matches[]={6,2,5,5,4,5,6,3,7,6};
    long long sum[40] = {};

    for(int i = 1; i <= 9; i++)
        sum[ matches[i] ]++;

    for(int i=1; i <= 30; i++)
        for(int j = 0; j <= 9; j++)
            sum[ i + matches[j] ] += sum[i];

    sum[6] = sum[6] + 1;

    for(int i = 1; i <= 30; i++)
        sum[i] += sum[i-1];

    int n;
    while (cin >> n && n != -1)
        cout << sum[n] << endl;
    
    return 0;
}