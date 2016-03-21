#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

bool cmp(const string& s1, const string& s2)
{
    return s1 + s2 < s2 + s1;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<string> v;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < N; ++i)
            cout << v[i];
        cout << endl;
    }
    return 0;
}
