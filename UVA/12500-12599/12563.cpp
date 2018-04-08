#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50 + 10;
const int maxt = 180 * 50 + 100;

struct Node
{
    int time,num;
}dp[maxt];

int t[maxn];

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int test = 1; test <= Test; test++)
    {
        int n,time,sum_t = 0;
        scanf("%d %d",&n,&time);
        for(int i = 1;i <= n; i++)
        {
            scanf("%d",&t[i]);
            sum_t += t[i];
        }

        time = min(sum_t, time - 1);

        memset(dp,0,sizeof(dp));

        for(int i = 1;i <= n; i++)
        {
            for(int j = time; j >= t[i];j--)
            {
                Node u;
                u.num = dp[j - t[i]].num + 1;
                u.time = dp[j - t[i]].time + t[i];
                if(dp[j].num < u.num || (dp[j].num == u.num && dp[j].time < u.time))
                    dp[j] = u;
            }
        }

        printf("Case %d: %d %d\n",test,dp[time].num + 1,dp[time].time + 678);
    }
    return 0;
}
