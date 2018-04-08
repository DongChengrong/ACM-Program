#include<stdio.h>

const int maxn = 10 + 10;
double l[maxn],v[maxn];

int main()
{
    int n,d;
    int T = 0;
    while(scanf("%d%d",&n,&d) == 2 && d)
    {
        double p;
        double sum = d;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf",&p,&l[i],&v[i]);
            sum += l[i] / v[i] * 2 -l[i];
        }
        printf("Case %d: %.3lf\n",++T,sum);
        printf("\n");
    }
    return 0;
}
