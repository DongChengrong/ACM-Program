#include<stdio.h>
#include<string.h>

#define N 110

int n;
int x[N],y[N],vis[N];

void dfs(int i,int cnt)
{
    int j;
    for(j = 1; j <= n; j++)
    if(!vis[j] && (x[i] == x[j] || y[i] == y[j]))
    { vis[j] = 1; dfs(j,cnt); }
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        int i,cnt = -1;

        for(i = 1; i <= n; i++)
            scanf("%d%d",&x[i],&y[i]);

        memset(vis,0,sizeof(vis));
        for(i = 1; i <= n; i++)
        if(!vis[i]) { vis[i] = 1; dfs(i,cnt++); }

        printf("%d\n",cnt);
    }
    return 0;
}
