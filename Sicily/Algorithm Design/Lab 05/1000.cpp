#include "iostream"
#include "map"
using namespace std;

const int MAXSIZE = 101;

int main(int argc, char const *argv[])
{
    int size;
    while (cin >> size)
    {
        int p1[MAXSIZE], p2[MAXSIZE], result[MAXSIZE];
        for (int i = 0; i < size; ++i)
            cin >> p1[i];
        for (int i = 0; i < size; ++i)
            cin >> p2[i];
        int x, y;
        cin >> x >> y;
        map<int, int> m1;
        for (int i = x; i <= y; ++i)
        {
            result[i] = p1[i];
            m1[p1[i]]++;
        }
        int i = 0, j = 0;
        while (i < size)
        {
            if (i < x || y < i)
            {
                if (m1[p2[j]])
                    m1[p2[j++]]--;
                else
                    result[i++] = p2[j++];
            }
            else
                i++;
        }
        for (int i = 0; i < size; ++i)
            if (i)
                cout << ' ' << result[i];
            else
                cout << result[i];
        cout << endl;

        map<int, int> m2;
        for (int i = x; i <= y; ++i)
        {
            result[i] = p2[i];
            m2[p2[i]]++;
        }
        i = 0;
        j = 0;
        while (i < size)
        {
            if (i < x || y < i)
            {
                if (m2[p1[j]])
                    m2[p1[j++]]--;
                else
                    result[i++] = p1[j++];
            }
            else
                i++;
        }
        for (int i = 0; i < size; ++i)
            if (i)
                cout << ' ' << result[i];
            else
                cout << result[i];
        cout << endl;
    }
    return 0;
}
