#include<stdio.h>

#define PI 3.1415926

int main()
{
    double r;
    while(scanf("%lf",&r) == 1)
    {
        double v = (double)4/3 * PI * r * r * r;
        int V = (v - (int)v >= 0.5 ? (int)v + 1: (int)v);
        printf("%d\n",V);
    }
    return 0;
}
