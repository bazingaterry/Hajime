#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[1001];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int dis = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] - arr[i] > dis)
            {
                dis = arr[j] - arr[i];
            }
        }
    }

    cout << dis << endl;

    return 0;
}                                 