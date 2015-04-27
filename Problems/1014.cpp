#include <iostream>
using namespace std;

int sum16 (int);
int sum12 (int);
int sum10 (int);

int sum16 (int n)
{
	int sum=0;
	while (n!=0)
	{
		sum = sum + n%16;
		n=n/16;
	}
	return sum;
}

int sum12 (int n)
{
	int sum=0;
	while (n!=0)
	{
		sum = sum + n%12;
		n=n/12;
	}
	return sum;
}

int sum10 (int n)
{
	int sum=0;
	while (n!=0)
	{
		sum = sum + n%10;
		n=n/10;
	}
	return sum;
}

int main()
{
	for (int i=1000;i<=9999;i++) if(sum10(i)==sum16(i)&&sum12(i)==sum16(i)) cout << i <<endl;
		
	return 0;
}
