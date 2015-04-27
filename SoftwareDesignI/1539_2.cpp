#include "cstdio"
#include "iostream"
using namespace std;

int num[1000001];

void Qsort(int a[],int low,int high)
{
	if(low>=high) return;
	
 	int first=low;
 	int last=high;
 	int key=a[first];
 	
	 while(first<last)
	{
	 	while(first<last&&a[last]>=key) --last;
		a[first]=a[last];
		
		while(first<last&&a[first]<=key) ++first;
		a[last]=a[first];
 	}
	
	a[first]=key;
	
	Qsort(a,low,first-1);
	Qsort(a,first+1,high);
}

int main(int argc, char const *argv[])
{
	int n;
	
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&num[i]);
	
		Qsort(num,0,n-1);
	
	for (int i = 0; i < n; ++i)
		printf("%d\n",num[i]);
	
	return 0;
}
