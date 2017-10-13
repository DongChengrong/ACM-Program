#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 100000000

const int maxn = 1000 + 10;
int x[maxn],y[maxn],p[maxn];
double dp[maxn];

double dist(int i,int j)
{
    double X = (x[i] - x[j]) * (x[i] - x[j]);
    double Y = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(X + Y);
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        //起点与终点坐标
        x[0] = y[0] = 0;
        x[n + 1] = y[n + 1] = 100;

        //初始化p[0]
        p[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&p[i]);
            p[i] = p[i - 1] + p[i];
        }

        //开始递推
        dp[0] = 0.0;
        for(int i = 1; i <= n+1; i++)
        {
            dp[i] = INF;
            for(int j = 0; j < i; j++)
            {
                dp[i] = min(dp[i], dp[j] + dist(i,j) + p[i - 1] - p[j]);
            }
            dp[i] += 1;
        }

        printf("%.3lf\n",dp[n+1]);
    }
}
