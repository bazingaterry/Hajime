#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
        int num;
        cin >> num;
        v.push_back(num);
    }
    vector<int> pre;
    for (int i = 0; i <= n; ++i)
    {
        sort(v.begin(), v.begin() + i);
        if (v != pre)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << v[i] << ' ';
            }
            cout << endl;
        }
        pre = v;
    }
	return 0;
}