#include <iostream>
using namespace std;

int main()
{
    int n,a,b,c;
    cin>>n;
    a=int(n/100);
    b=int(n/10)-a*10;
    c=n-b*10-a*100;
    cout<<a+b+c<<endl;
    return 0;
    
}                                 
