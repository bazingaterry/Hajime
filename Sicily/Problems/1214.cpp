// Reference: Algorithm from doubleh's PPT in Algorithm Design course

#include "iostream"

using namespace std;

int cal(unsigned l)
{
    int re = 0;
    for (int i = 1; i <= 16; i++)
    {
        for (unsigned tail = 1, head, value; tail < 1 << i; tail += 2)
        {
            head = 0;
            for (int j = 0; j < i; j++)
                head = head << 1 | (tail >> j & 1);
            // even
            value = head << i | tail;
            if (value <= l) re++;
            // odd
            value = head << (i - 1) | tail;
            if (value <= l) re++;
        }
    }
    return re;
}

int main(int argc, char const *argv[])
{
    unsigned n;
    while (cin >> n)
        cout << cal(n) << endl;
    return 0;
}
