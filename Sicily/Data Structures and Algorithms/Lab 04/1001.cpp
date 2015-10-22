#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    while (cin >> k && k)
    {
        while (k--)
        {
            int n, m;
            cin >> n >> m;
            int array[50];
            for (int i = 0; i < m; ++i)
            {
                cin >> array[i];
            }
            sort(array, array + m);
            int min = array[m - 1] - array[0];
            for (int i = 0; i <= m - n; ++i)
            {
                if (array[i + n - 1] - array[i] < min)
                    min = array[i + n - 1] - array[i];
            }
            cout << min << endl;
        }
    }
    return 0;
}