#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double a[5];
        bool ok = true;
        scanf("%lf%lf%lf",&a[1],&a[2],&a[3]);
        if(a[1] + a[2] <= a[3]) ok = false;
        if(a[1] + a[3] <= a[2]) ok = false;
        if(a[2] + a[3] <= a[1]) ok = false;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
