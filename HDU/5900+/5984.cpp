#include<stdio.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double l,d;
        scanf("%lf%lf",&l,&d);
        if(l <= d) printf("0.000000\n");
        else
            printf("%.6lf\n",log(l/d) + 1);
    }
    return 0;
}
