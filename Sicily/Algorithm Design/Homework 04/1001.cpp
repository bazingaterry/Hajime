#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

const double INF = 10e8;
const int SIZE = 100010;
double arr[SIZE];
double minDis;

void findClosetPair(int begin, int end)
{
    if (begin >= end)
        return;
    else
    {
        double mid = arr[end];
        int left = begin;
        int right = end - 1;
        while (left < right)
        {
            while (arr[left] < mid && left < right)
                left++;
            while (arr[right] >= mid && left < right)
                right--;
            swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[end])
            swap(arr[left], arr[end]);
        else
            left++;
        findClosetPair(begin, left - 1);
        findClosetPair(left + 1, end);
        if (left > begin) minDis = min(minDis, abs(arr[left] - arr[left - 1]));
        if (left < end) minDis = min(minDis, abs(arr[left + 1] - arr[left]));
    }
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        minDis = INF;
        findClosetPair(0, n - 1);
        cout << setprecision(6) << fixed << minDis << endl;
    }
    return 0;
}
