#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxm = 1000 + 10;
const int maxn = 100000 + 10;

int dp[maxm][maxm];
int a[maxn],b[maxn],k[maxn],p[maxn];

int main()
{
    int n, m;
    while(~scanf("%d%d",&n,&m))
    {
        int MAX_P = 0,MAX_B = 0,MAX_A = 0;   //分别代表最大伤害，最大防御，最大血

        //怪兽
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            MAX_A = max(MAX_A,a[i]);
            MAX_B = max(MAX_B,b[i]);
        }

        //攻击
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d",&k[i],&p[i]);
            MAX_P = max(MAX_P,p[i]);
        }

        if(MAX_P <= MAX_B)
        {
            printf("-1\n");
            continue;
        }


        memset(dp,0,sizeof(dp));

        for(int i = 0; i <= 10; i++)
        {
            for(int j = 1; j <= MAX_A; j++)
            {
                dp[j][i] = INF;
                for(int l = 1; l <= m; l++)
                {
                    int dmg = p[l] - i;
                    if(dmg <= 0) continue;
                    if(dmg >= j) dp[j][i] = min(dp[j][i], k[l]);
                    else dp[j][i] = min(dp[j][i], dp[j - dmg][i] + k[l]);
                }
            }
        }

        LL res = 0;
        for(int i = 1; i <= n; i++)
            res += dp[a[i]][b[i]];


        printf("%lld\n",res);
    }
    return 0;
}
