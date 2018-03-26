#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double m,x,y,z;
        scanf("%lf%lf%lf%lf",&m,&x,&y,&z);
        double t = x * m / (y - x);
        double s = z * t;
        printf("%.2lf\n",s);
    }
    return 0;
}
