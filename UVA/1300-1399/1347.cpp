#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 50 + 10;
double x[maxn],y[maxn],dist[maxn][maxn],dp[maxn][maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        //录入数据
        for(int i = 1; i <= n; i++)
            scanf("%lf %lf",&x[i],&y[i]);

        //计算距离
        for(int i = 1;i <= n; i++)
            for(int j = 1; j<= n; j++)
                dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

        //开始状态转移
        for(int i = n - 1; i >= 2; i--)
            for(int j = 1; j < i; j++)
            {
                if(i == n - 1) dp[i][j] = dist[i][n] + dist[j][n];
                else dp[i][j] = min(dist[i][i + 1] + dp[i + 1][j], dist[j][i + 1] + dp[i + 1][i]);
            }
        printf("%.2lf\n",dp[2][1] + dist[1][2]);
    }
    return 0;
}
