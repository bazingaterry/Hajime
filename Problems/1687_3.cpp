#include <iostream>

using namespace std;

int main()
{
    double a, b;
    while(cin >> a >> b && a + b)
    {
        if ( a > 0 )
        	a = int(a * 100 + 0.5);
        else 
        	a = int(a * 100);
        
        b = int(b * 100);

        cout << a/100.0 - b/100.0 <<endl;
    }
    return 0;
}