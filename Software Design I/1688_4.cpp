#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
    	int h1, h2, m1, m2;
    	scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    	int t1 = h1 * 60 + m1;
    	int t2 = h2 * 60 + m2;
    	if (t2 < t1)
    	{
    		t2 += 1440;
    	}
    	int dis = t2 - t1;
    	printf("%02d:%02d\n", dis / 60, dis - (dis / 60) * 60);
    }

    return 0;
}