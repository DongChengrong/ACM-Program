#include<stdio.h>

int main()
{
    int T;
    double x1,y1,x2,y2;
    double x3,y3,x4,y4;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);

        double k = (y2 - y1) / (x2 - x1);
        double b = y1 - k * x1;

        double l = k * x3 + b;
        double r = k * x4 + b;

        if((l > y3 && r > y3) || (l < y4 && r < y4))
            printf("F\n");
        else printf("T\n");
    }
    return 0;
}
