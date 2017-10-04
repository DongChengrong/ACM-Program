#include<stdio.h>
#include<math.h>

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    double x1,y1,x2,y2;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        printf("%.2lf\n",dist(x1,y1,x2,y2));
    }
}
