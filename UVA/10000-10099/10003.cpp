#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 50 + 10;
const int INF = 1000000;
int a[maxn],d[maxn][maxn],vis[maxn][maxn];

int dp(int i, int j)
{
    if(i >= j - 1) return 0;
    if(vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int &ans = d[i][j];
    for(int k = i + 1; k <= j - 1; k++)
        ans = min(ans, dp(i,k) + dp(k,j) + a[j] - a[i]);
    return ans;
}

int main()
{
    int l,n;
    while(scanf("%d",&l) == 1 && l)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        a[0] = 0, a[n + 1] = l;
        memset(vis,0,sizeof(vis));
        memset(d,INF,sizeof(d));
        printf("The minimum cutting is %d.\n",dp(0, n + 1));
    }
    return 0;
}
