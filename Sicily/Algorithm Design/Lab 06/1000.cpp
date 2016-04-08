#include "iostream"
#include "vector"
using namespace std;

vector<long long> v;
long long num;

void lis(int begin, int end)
{
    if (begin == end)
    {
        if (begin == v.size())
            v.push_back(num);
        else
            v[begin] = min(v[begin], num);
    }
    else
    {
        int mid = (begin + end) / 2;
        if (num < v[mid])
            lis(begin, mid);
        else
            lis(mid + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    while (N--)
    {
        cin >> num;
        lis(0, v.size());
    }
    cout << v.size() << ' ' << *(--v.end()) << endl;
    return 0;
}
