#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[100010];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    long long sum = 0;

    int tmp = arr[0];
    for (int i = 0; i < n; ++i)
    {
    	if (arr[i] > tmp)
    		sum += arr[i] - tmp;
    	tmp = arr[i];
    }
    cout << sum << endl;
    

    return 0;
}                                 