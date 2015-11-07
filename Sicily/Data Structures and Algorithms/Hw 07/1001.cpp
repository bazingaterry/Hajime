#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> v;
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        int Q;
        cin >> Q;
        while (Q--)
        {
            int a, b;
            cin >> a >> b;
            cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << '\n';
        }
    }
    return 0;
}