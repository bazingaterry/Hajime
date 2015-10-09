#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    double speed;
    cin >> speed;
    double time = 80000 / speed;
    if (time - (int)time == 0)
        cout << time << endl;
    else
        cout << (int)time + 1 << endl;
    return 0;
}