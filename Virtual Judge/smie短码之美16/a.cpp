#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
    int arr[101];
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int minIndex = 0;
        int minNum = arr[0];
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] < minNum)
            {
                minNum = arr[i];
                minIndex = i;
            }
        }
        swap(arr[minIndex], arr[0]);
        cout << arr[0];
        for (int i = 1; i < n; ++i)
            cout << ' ' << arr[i];
        cout << endl;
    }
	return 0;
}