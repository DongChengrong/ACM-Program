#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

const int maxn = 500 + 20;
int G[maxn][maxn];
int in_degree[maxn];
int ans[maxn];
int n,m;

void init()
{
    memset(G,0,sizeof(G));
    memset(in_degree,0,sizeof(in_degree));
    memset(ans,0,sizeof(ans));
}

void topo()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(G[i][j]) in_degree[j]++;

    for(int i = 1; i <= n; i++)
    {
        int k = 1;
        while(in_degree[k] != 0)
            k++;
        ans[i] = k;
        in_degree[k] = -1;
        for(int j = 1; j <= n; j++)
        {
            if(G[k][j]) in_degree[j]--;
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        init();
        for(int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            G[x][y] = 1;
        }
        topo();
        for(int i = 1; i < n; i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
