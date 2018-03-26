#include<stdio.h>
#include<string.h>

#define N 100

int a[N][N];
int vis[N][N],MAX;
int m,n;

//DFS
int dfs(int i, int j, int cnt)
{
    int v = 0;
    if(vis[i][j]) return v;    //已被访问
    if(i < 1 || i > m || j < 1 || j > n) return v;   //越界

    vis[i][j] = 1;
    int e,s,n,w;
    e = s = n = w = 0;

    if(a[i][j] >= 8) {s = 1; a[i][j] -= 8;}
    if(a[i][j] >= 4) {e = 1; a[i][j] -= 4;}
    if(a[i][j] >= 2) {n = 1; a[i][j] -= 2;}
    if(a[i][j] >= 1) {w = 1; a[i][j] -= 1;}

    if(!s) v += dfs(i + 1, j, cnt); if(!e) v += dfs(i, j + 1, cnt);
    if(!n) v += dfs(i - 1, j, cnt); if(!w) v += dfs(i, j - 1, cnt);

    return v + 1;
}

int main()
{
    while(scanf("%d%d",&m,&n) == 2)
    {
        MAX = 0;
        memset(vis,0,sizeof(vis));   //init

        for(int i = 1; i <= m; i++)   //input
            for(int j = 1; j <= n; j++)
                scanf("%d",&a[i][j]);

        int cnt = 0;
        for(int i = 1; i <= m; i ++)   //input
            for(int j = 1; j <= n; j++)
                if(!vis[i][j]) {
                    int v = dfs(i,j,++cnt);
                    if(v > MAX) MAX = v;
                }

        printf("%d\n%d\n",cnt,MAX);
    }
    return 0;
}
