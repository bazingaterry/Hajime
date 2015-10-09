#include "iostream"
#include "string"
#include "sstream"
#include "algorithm"

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    while(cin >> n >> m)
    {
        int num[100];
        string str[100];
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> str[i];
        }
        int x, y;
        cin >> x >> y;

        sort(num, num + n);
        sort(str, str + m);

        string result;
        stringstream tmp;
        for (int i = 0; i < n; ++i)
        {
            tmp << num[i]; 
        }
        result += tmp.str();
        for (int i = 0; i < m; ++i)
        {
            result += str[i];
        }
        
        for (int i = x; i <= y; i++)
            cout << result[i];
        cout << endl;
    }
    return 0;
}                                 