#include<stdio.h>
#include<string.h>

#define N 150000 + 1000

typedef long long LL;

LL a[N],dp[N];

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        LL i,j,MAX = 0;
        for(i = 0; i < n; i++)
            scanf("%lld",&a[i]);
        memset(dp,0,sizeof(dp));
        for(j = 0; j < k; j++)
            dp[0] += a[j];
        i = 1; j = i + k - 1;
        while(j < n)
        {
            dp[i] = dp[i - 1] - a[i - 1] + a[j];
            if(dp[i] < dp[MAX]) MAX = i;
            i++; j++;
        }
        printf("%lld\n",MAX + 1);
    }
    return 0;
}
