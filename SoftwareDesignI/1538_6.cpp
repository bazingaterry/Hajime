#include "cstdio"

void hanoi(int n,int a,int b,int c)
{
	if (n==1)
	{
		if (a==1)
		{
			if (b==2)
				printf("12\n");
			else
				printf("13\n");
		}
		else if (b==1)
		{
			if (a==2)
				printf("21\n");
			else
				printf("23\n");
		}
		else
		{
			if (a==2)
				printf("31\n");
			else 
				printf("32\n");
		}
	}
	else 
	{
		if (a==1)
		{
			if (b==2)
			{
				hanoi(n-1,1,0,2);
				printf("12\n");
				hanoi(n-1,0,2,1);
			}
			else
			{
				hanoi(n-1,1,2,0);
				printf("13\n");
				hanoi(n-1,0,1,2);
			}
		}
		else if (b==1)
		{
			if (a==2)
			{
				hanoi(n-1,0,1,2);
				printf("21\n");
				hanoi(n-1,2,0,1);
			}
			else
			{
				hanoi(n-1,2,1,0);
				printf("23\n");
				hanoi(n-1,1,0,2);
			}
		}
		else
		{
			if (a==2)
			{
				hanoi(n-1,0,2,1);
				printf("31\n");
				hanoi(n-1,2,1,0);
			}
			else 
			{
				hanoi(n-1,2,0,1);
				printf("32\n");
				hanoi(n-1,1,2,0);
			}
		}	
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	hanoi(n,1,0,2);
	
	return 0;
}
