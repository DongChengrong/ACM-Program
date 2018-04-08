#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define N 100 + 10

struct Edge
{
    int u,v,c;
};

vector<Edge> G[N];
int vis[N][N][N],vis_col[N];

int m,n;

void init(int n)
{
    for(int i = 1; i <= n; i++)
        G[i].clear();
    memset(vis,0,sizeof(vis));
}

bool dfs(int u, int color, int target)
{
    if(u == target)
        return true;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].v;
        int c = G[u][i].c;
        if(c == color && !vis[u][v][c])
        {
            vis[u][v][c] = vis[v][u][c] = 1;
            if(dfs(v,c,target))
                return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        init(n);
        while(m--)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            G[u].push_back((Edge){u,v,c});
            G[v].push_back((Edge){v,u,c});
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int cnt = 0;
            memset(vis,0,sizeof(vis));
            memset(vis_col,0,sizeof(vis_col));
            for(int i = 0; i < G[u].size(); i++)
            {
                int vv = G[u][i].v;
                int c = G[u][i].c;
                if(vis_col[c]) continue;
                if(!vis[u][vv][c])
                {
                    vis[u][vv][c] = vis[vv][u][c] = 1;
                    if(dfs(vv,c,v)){
                        cnt++; vis_col[c] = 1;
                    }
                }
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}