#include <iostream>
using namespace std;

int min(int a,int b)
{
    if (a>b) 
		return b;
    else 
		return a;
}

int func(int n)
{
    if (n==1) 
		return 0;
    else if (n==2) 
		return 1;
    else if (n==3) 
		return 2;
    else if (n%2==0) 
		return 1+func(n/2);
    else 
		return 1+min(func(n+1),func(n-1));
}


int main()
{
    int n;
    while (cin >> n)
    	cout << func(n) <<endl;
    
    return 0;
}                                 
