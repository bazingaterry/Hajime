#include <cstdio>
#include <cmath>

int main()
{
	double a,b,c,x1,x2;
	scanf("%lf %lf %lf",&a,&b,&c);
	printf("%.3lf %.3lf\n",(-b-sqrt(b*b-4*a*c))/(2*a),(-b+sqrt(b*b-4*a*c))/(2*a));
	return 0;
}
