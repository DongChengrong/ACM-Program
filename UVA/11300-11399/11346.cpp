#include<stdio.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double a,b,s,ans;
        scanf("%lf%lf%lf",&a,&b,&s);
        if(s > a * b) ans = 0;
        else if(s <  1e-6) ans = 1;
        else ans = ((a*b) - s - s * log((a * b)/s)) / (a*b);
        printf("%.6lf%%\n",ans * 100);
    }
    return 0;
}
