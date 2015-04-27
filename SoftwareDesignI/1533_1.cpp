#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int i=1;
    while (i++&&n!=1)
    {
        if (n%i==0)     
        {
            cout << i << endl;
            n=n/i;
            i=1;
        }
        
    }
    
    return 0;
}                                 
