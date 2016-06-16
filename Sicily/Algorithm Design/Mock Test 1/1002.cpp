#include "iostream"
using namespace std;

const int MAX = 1000;

int main(int argc, char const *argv[])
{
    int res[1001];
    res[0] = 1;
    res[1] = 1;
    res[2] = 5;
    res[3] = 11;
    for (int i = 4; i <= MAX; ++i)
        res[i] = - res[i - 4] + res[i - 3] + res[i - 2] * 5 + res[i - 1];
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int W;
        cin >> W;
        cout << i << ' ' << res[W] << endl;
    }
    return 0;
}
