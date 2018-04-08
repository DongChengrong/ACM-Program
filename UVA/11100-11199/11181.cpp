#include<stdio.h>
#include<string.h>

const int maxn = 30;
int buy[maxn];
int n,r;
double p[maxn],sum[maxn];

void dfs(int d,int c,double prob)
{
    if(c > r || d - c > n - r) return;

    if(d == n)
    {
        if(c == r)
        {
            sum[n] += prob;
            for(int i = 0; i < d; i++)
                if(buy[i]) sum[i] += prob;
        }
        return;
    }

    //ฒปัก
    buy[d] = 0;
    dfs(d+1,c,prob*(1 - p[d]));

    //ัก
    buy[d] = 1;
    dfs(d+1,c+1,prob *p[d]);
}

int main()
{
    int kase = 1;
    while(scanf("%d%d",&n,&r) == 2 && n)
    {
        printf("Case %d:\n",kase++);
        for(int i = 0; i < n; i++)
            scanf("%lf",&p[i]);

        memset(buy,0,sizeof(buy));
        memset(sum,0,sizeof(sum));
        dfs(0,0,1.0);
        for(int i = 0; i < n; i++)
            printf("%.6lf\n",sum[i]/sum[n]);
    }
    return 0;
}
