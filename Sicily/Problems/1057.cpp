# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
double dp[51][51];
double sum[51];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    sum[1]=1;
    for(int i=2;i<=50;i++)
    {
       sum[i]=0;
       for(int j=1;j<=i;j++)
       {
          dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
          sum[i]+=dp[i][j];
       }
    }
    int n;
    while(true)
    {
       cin>>n;
       if(!n) break;
       printf("%d %.0f\n",n,sum[n]);
    }
    return 0;
}
