#include <cstdio>

int main()
{
    int n,m;
    long long num[100002]={0};
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) 
	{
    	long long t;
		scanf("%lld",&t);
    	num[i]=num[i-1]+t;
    }
    
    int mu=1;
    long long add=0;
    while (m--)
    {
        int o;
        scanf("%d",&o);
        
        if (o==1) 
		{
			mu*=-1;
			add*=-1;
		}
        else if (o==2) 
        {
            int x;
            scanf("%d",&x);
            add+=x;
        }
        else 
        {
            int l,r;
            scanf("%d%d",&l,&r);    
            printf("%lld\n",(num[r]-num[l-1])*mu+add*(r-l+1));
        }
        
    }
    

    return 0;
}                                 
