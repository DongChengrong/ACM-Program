#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000000 + 10;
int a[maxn],dp[maxn],Maxs[maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n) == 2)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);

        int Max;
        memset(dp,0,sizeof(dp));
        memset(Maxs,0,sizeof(Maxs));
        for(int i = 1; i <= m; i++)
        {
            Max = INT_MIN;
            for(int j = i; j <= n; j++)
            {
                dp[j] = max(dp[j - 1] + a[j], Maxs[j - 1] + a[j]);
                Maxs[j - 1] = Max;
                Max = max(Max,dp[j]);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
