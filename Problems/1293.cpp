#include <iostream>
using namespace std;
int max(int);

int main()
{
	int i,t,j,biggest,temp;
	cin>>i>>j;
	for (t=i;t<=j;++t)
	{
	temp=max(t);
	if (temp>biggest||t==i)
	biggest=temp;		
	}
	cout<<biggest<<endl;
	
return 0;
}

int max(int x)
{
	int count=0;
	while (x!=1)
	{
	if (x%2==0)
	x=x/2;
	else x=3*x+1;
	count++;
	} 
	count++;

return count;
}
