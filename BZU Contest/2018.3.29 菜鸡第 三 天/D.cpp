#include<stdio.h>
#include<string.h>

#define N 110

char G[N][N];
int vis[N][N];

int m,n,ei,ej;
int ok;

int dir[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int i,int j,int cnt)
{
    if(ok) return;
    if(cnt >= 4){
        if(ei == i && ej == j) {
            ok = 1; return;
        }
    }
    if(i < 1 || i > n || j < 1 || j > m) return;  //越界
    if(vis[i][j]) return;
    if(G[i][j] != G[ei][ej])  return;    //不是同一颜色

    vis[i][j] = 1;

    for(int k = 0; k < 4; k++){
        dfs(i+dir[k][0],j+dir[k][1],cnt+1);
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1; i <= n; i++)
            scanf("%s",G[i]+1);

        ok = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(ok) break;
                memset(vis,0,sizeof(vis));
                ei = i; ej = j;
                dfs(i,j,1);
            }

        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
