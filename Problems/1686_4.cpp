
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n != 0)
    {
        int count = 0;
        bool fac[100010] = {};
        while (n != 1)
        {
            for (int i = 2; i <= n; ++i)
            {
                if (n % i == 0)
                {
                    if (fac[i] == 0)
                    {
                        count++;
                        fac[i] = 1;
                    }
                    n = n / i;
                    break;
                }
            }
        }
        cout << count << endl;
    }
    

    return 0;
}                                 