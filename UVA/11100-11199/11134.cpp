#include<stdio.h>
#include<string.h>

const int maxn = 5000 + 10;
int x[maxn],y[maxn],xl[maxn],xr[maxn],yl[maxn],yr[maxn],n;

int slove(int *a,int *l, int *r)
{
    memset(a, -1, sizeof(int) * n);
    for(int k = 1; k <= n; k++)
    {
        int cur = -1,right = maxn;
        for(int i = 0; i < n; i++)
            if(a[i] < 0 && l[i] <= k && r[i] < right)
                right = r[cur = i];
        if(cur < 0 || right < k) return 0;
        a[cur] = k;
    }
    return 1;
}

int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d %d %d",&xl[i],&yl[i],&xr[i],&yr[i]);

        if(slove(x,xl,xr) && slove(y,yl,yr))
            for(int i = 0; i < n; i++)
                printf("%d %d\n",x[i],y[i]);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
