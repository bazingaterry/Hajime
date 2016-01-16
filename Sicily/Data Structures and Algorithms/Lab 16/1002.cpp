#include "cstdio"
#include "cstring"
using namespace std;

int m[200];

inline void init()
{
    m['a'] = 2;
    m['b'] = 4;
    m['c'] = 6;

    m['d'] = 3;
    m['e'] = 6;
    m['f'] = 9;

    m['g'] = 4;
    m['h'] = 8;
    m['i'] = 12;

    m['j'] = 5;
    m['k'] = 10;
    m['l'] = 15;

    m['m'] = 6;
    m['n'] = 12;
    m['o'] = 18;

    m['p'] = 7;
    m['q'] = 14;
    m['r'] = 21;
    m['s'] = 28;

    m['t'] = 8;
    m['u'] = 16;
    m['v'] = 24;

    m['w'] = 9;
    m['x'] = 18;
    m['y'] = 27;
    m['z'] = 36;
}

int main(int argc, char const *argv[])
{
	init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char c[110];
        scanf("%s", c);
        long long sum = 0;
        for (int i = 0; i < strlen(c); ++i)
            sum += m[c[i]];
        printf("%lld\n", sum);
    }
	return 0;
}