#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=100+10;
int vis[maxn][maxn];
int d[maxn][maxn];
int sum[maxn];

int dp(int i,int j)
{
    if(vis[i][j]) return d[i][j];
    vis[i][j]=1;
    int m=0;
    for(int k=i+1;k<=j;k++) m=min(m,dp(k,j));
    for(int k=j-1;k>=i;k--) m=min(m,dp(i,k));
    return d[i][j]=sum[j]-sum[i-1]-m;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        sum[0]=0;
        for(int i=1;i<=n;i++) { scanf("%d",&sum[i]); sum[i]+=sum[i-1]; }
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        printf("%d\n",2*dp(1,n)-sum[n]);
    }
    return 0;
}
