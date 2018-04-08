#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 110
#define MOD  100000000

typedef long long LL;

LL dp[N][N][2];

int main()
{
    LL n1,n2,k1,k2;
    while(scanf("%lld%lld%lld%lld",&n1,&n2,&k1,&k2) == 4)
    {
        memset(dp,0,sizeof(dp));

        for(int i = 0; i <= k1; i++) dp[i][0][0] = 1;
        for(int i = 0; i <= k2; i++) dp[0][i][1] = 1;

        for(LL i = 1; i <= n1; i++)
            for(LL j = 1; j <= n2; j++)
            {
                for(int k = 1; k <= min(i,k1); k++)
                    dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                for(int k = 1; k <= min(j,k2); k++)
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
            }
        printf("%lld\n",(dp[n1][n2][1] + dp[n1][n2][0]) % MOD );
    }
    return 0;
}
