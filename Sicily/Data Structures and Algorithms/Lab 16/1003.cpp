#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[10];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
    if (n & 1)
        cout << arr[n / 2] << endl;
    else
        cout << (arr[n / 2 - 1] + arr[n / 2]) / 2 << endl;

    return 0;
}