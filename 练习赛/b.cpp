#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 300 + 10;
int c[maxn][maxn],dp[maxn][maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d",&c[i][j]);
            }

            sort(c[i] + 1, c[i] + m + 1); //从小到大排序

            for(int j = 2; j <= m; j++)   //累加求和
                c[i][j] += c[i][j - 1];
        }

        for(int i = 0; i < maxn; i++)
            for(int j = 0; j < maxn; j++)
                dp[i][j] = INF;

        dp[0][0] = 0;

        //开始状态转移
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= min(i * m,n); j++)
            {
                for(int k = i - 1; k <= j; k++)  //k代表前i天购买的糖果数量
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + c[i][j - k] + (j - k) * (j - k));
                }
            }
        }
        printf("%d\n",dp[n][n]);
    }
    return 0;
}
