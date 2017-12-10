#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 10 + 10;
int dp[maxn];

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,0,sizeof(dp));
        dp[1] = (int)((double) k * 0.9 + 0.5);

        for(int i = 2; i <= n; i++)
            dp[i] = min(dp[i - 1] + dp[1], (int)((double) k * 0.9 * i + 0.5));

        printf("%d\n",dp[n]);
    }
	return 0;
}
