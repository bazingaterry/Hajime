#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long num)
{
    if (num==1) return 0;
    else 
    {
        int i;
        for (i=2;i<=sqrt(num);i++)
        {
            if (num%i==0) return 0;
        }
        return 1;
    }
}


int main()
{
    int p;
    while(cin >> p)
        if (isPrime(pow(2,p)-1)&&(isPrime(p))) 
            cout << "Yes\n";
        else
            cout << "No\n";
    
    return 0;
}
