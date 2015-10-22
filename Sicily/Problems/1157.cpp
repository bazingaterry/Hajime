#include <iostream>
using namespace std;

int main ()
{
	int n,t,a=0,b;
	while (cin>>n&&n!=0){
		for (t=1;t<=n;++t){
			cin>>a;
			if (a>b||t==1)
			b=a;
		}
		cout<<b<<endl;
		}
	
}

