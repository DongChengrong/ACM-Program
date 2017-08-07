#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 10000
int dp[MAXN][MAXN];
int n,W,w[MAXN],v[MAXN];

int dfs(int i,int j)
{
    int ans=0;
    if(dp[i][j]) return dp[i][j];
    if(i==n) return 0;
    else if(j<w[i]) ans=dfs(i+1,j);
    else ans=max(dfs(i+1,j),dfs(i+1,j-w[i])+v[i]);
    return dp[i][j]=ans;
}

int main()
{
    int test=1;
    while(scanf("%d%d",&n,&W)==2 && n && W)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d%d",&w[i],&v[i]);
        printf("°¸Àý%d£º%d\n",test++,dfs(0,W));
    }
    return 0;
}
