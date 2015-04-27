#include "cstdio"
#include "cmath"

bool isPrime(int num)
{
    if (num==1) return 0;
    else 
    {
        int i;
        for (i=2;i<=sqrt(num);i++)
        {
            if (num%i==0) return 0;
        }
        return 1;
    }
}

bool isEP (int m)
{
	while(m)
	{
		if(isPrime(m)==0)
			return 0;
		m=m/10;
	}
	return 1;
}

const int fac[4]={1,3,7,9};
int num[4][100]{};

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	if (n<=5)
	{
		for (int i = pow(10,n-1); i <= pow(10,n)-1; ++i)
		{
			if(isEP(i))
				printf("%d\n",i);
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
			num[i][0]=1;
		
		for (int i = 10000; i <= 99999; ++i)//init 5
		{
			if(isEP(i))
			{
				num[0][num[0][0]]=i;
				num[0][0]++;
			}
		}
		
		for (int i = 0; i < n-5; ++i)
		{
			for (int j = 1; j < num[i][0]; ++j)//init new
			{
				for (int k = 0; k <= 3; ++k)
				{
					if (isEP(num[i][j]*10+fac[k]))
					{
						num[i+1][num[i+1][0]]=num[i][j]*10+fac[k];
						num[i+1][0]++;
					}
				}
			}
		}
		
		for (int i = 1; i < num[n-5][0]; ++i)
		{
			printf("%d\n",num[n-5][i]);
		}
	}
	return 0;
}
