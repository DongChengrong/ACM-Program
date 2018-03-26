#include<stdio.h>

#define PI 3.1415926

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        double w1,w2;
        if(a >= b)
        {
            w1 = a - b;
            w2 = 2 * PI - (a - b);
        }
        else
        {
            w1 = 2 * PI - (b - a);
            w2 = b - a;
        }
        if(w1 < w2) printf("clockwise\n");
        else printf("counterclockwise\n");
    }
    return 0;
}
