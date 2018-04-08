#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxt=200+20;
const int maxn=50+10;
const int INF=1000000;

//以下数组分别表示在某一时刻，某一车站是否有车
//不同车站到下一车站的时间
int has_train[maxt][maxn][2],t[maxn],dp[maxt][maxn];

int main()
{
    int n,T,Test=1;
    while(scanf("%d",&n)==1 && n)
    {
        int M1,M2,d;
        scanf("%d",&T);
        for(int i=1;i<n;i++) scanf("%d",&t[i]);

        memset(has_train,0,sizeof(has_train));

        //记录向右开的地铁
        scanf("%d",&M1);
        while(M1--)
        {
            scanf("%d",&d);
            for(int i=1;i<n;i++)
            {
                if(d>T) break;
                has_train[d][i][0]=1;
                d+=t[i];
            }
        }

        //记录向左开的地铁
        scanf("%d",&M2);
        while(M2--)
        {
            scanf("%d",&d);
            for(int i=n;i>1;i--)
            {
                if(d>T) break;
                has_train[d][i][1]=1;
                d+=t[i-1];
            }
        }

        memset(dp,INF,sizeof(dp));
        dp[T][n]=0;

        for(int i=T-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j<n && has_train[i][j][0] && i+t[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
                if(j>1 && has_train[i][j][1] && i+t[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        }

        printf("Case Number %d: ",Test++);
        if(dp[0][1]>=INF) printf("impossible\n");
        else printf("%d\n",dp[0][1]);
    }
    return 0;
}
