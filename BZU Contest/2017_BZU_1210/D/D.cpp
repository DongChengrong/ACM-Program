#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        double s,p;
        double tol = 0,div = 0;
        while(n--)
        {
            scanf("%lf%lf",&s,&p);
            if(p == -1) continue;

            if(p >= 90) tol += 4 * s;
            if(p < 90 && p >= 80) tol += 3 * s;
            if(p < 80 && p >= 70) tol += 2 * s;
            if(p < 70 && p >= 60) tol += 1 * s;
            div += s;
        }

        if(div == 0) printf("-1\n");
        else printf("%.2lf\n",tol / div);
    }
    return 0;
}
