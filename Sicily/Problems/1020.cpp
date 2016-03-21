#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int arr[101];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        string bigInt;
        cin >> bigInt;
        cout << '(';
        for (int i = 0; i < n; ++i)
        {
            int result = bigInt[0] - '0';
            for (int j = 1; j < bigInt.size(); ++j)
                result = (bigInt[j] - '0' + result * 10) % arr[i];
            if (i) cout << ',';
            cout << result;
        }
        cout << ')' << endl;
    }
    return 0;
}
