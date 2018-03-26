#include<stdio.h>
#include<string.h>

const int maxn = 100 + 10;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int G[maxn][maxn];
int m,n;
int vis[maxn][maxn];

void dfs(int r, int c, int cnt)
{
    if(r < 1 || r > m || c < 1 || c > n)
        return;
    if(vis[r][c]) return;
    if(!G[r][c]) return;

    vis[r][c] = 1;
    for(int i = 0; i < 4; i++)
        dfs(r+dx[i],c+dy[i],cnt);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        memset(vis,0,sizeof(vis));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d",&G[i][j]);

        int cnt = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(!vis[i][j] && G[i][j]) dfs(i,j,cnt++);
        printf("%d\n",cnt);
    }
    return 0;
}
