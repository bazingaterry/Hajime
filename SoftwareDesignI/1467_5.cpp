#include <iostream>
#include <cmath>
using namespace std;

int qs(int);

int qs(int a,int b,int p)//calc (a^b)%p
{
	if (b==1) return a%p;
	else if (b==2) return (a*a)%p;
	else if (b%2==0) return ((int)pow(qs(a,b/2,p),2))%p;
	else if (b%2!=0) return (qs(a,(b-1)/2,p)*qs(a,(b+1)/2,p))%p;
}

int main()
{
	int a,b,p;
	cin >> a >> b >> p;
	cout << qs(a,b,p) <<endl;
		
	return 0;
}
