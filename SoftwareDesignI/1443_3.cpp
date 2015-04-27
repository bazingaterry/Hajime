#include <cstdio>
#include <cmath>

int main()
{
	double a,b,c,x1,x2,p,q;
	scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&p,&q);
	x1=(-b-sqrt(b*b-4*a*c))/(2*a);
	x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	if (((p<=x1&&x1<=q)||(p<=x2&&x2<=q))&&(b*b-4*a*c)>=0) printf ("Yes\n");
	else printf ("No\n");
	return 0;
}
