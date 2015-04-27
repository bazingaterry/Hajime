#include <cstdio>

int main()
{
    float x1,y1,x2,y2,x3,y3;
    scanf("%f %f %f\n%f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("%.2f\n",(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)/2);
return 0;
}
