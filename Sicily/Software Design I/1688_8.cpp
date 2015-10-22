#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 6)
        	cout << "Bob\n";
        else
        	cout << "Alice\n";
    }
    return 0;
}