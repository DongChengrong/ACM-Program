#include<cstdio>
#include<cstring>
using namespace std;
int C[20],G[20];
int dp[21][15001];
int main()
{
    int c,g;
    while(~scanf("%d%d",&c,&g))
    {
        for(int i=0;i<c;i++) scanf("%d",&C[i]);
        for(int i=0;i<g;i++) scanf("%d",&G[i]);
        memset(dp,0,sizeof(dp));
        dp[0][7500]=1;
        for(int i=1;i<=g;i++)
            for(int j=0;j<=15000;j++)
            if(dp[i-1][j])
            {
                for(int k=0;k<c;k++)
                    dp[i][j+C[k]*G[i-1]]+=dp[i-1][j];
            }
        printf("%d\n",dp[g][7500]);
    }
    return 0;
}
