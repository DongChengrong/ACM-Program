#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 30000 + 10;
vector<int> G[maxn];
int out[maxn];
int ans[maxn];
int n,m;

void init()
{
    for(int i = 0; i <= n; i++)
        G[i].clear();
    memset(out,0,sizeof(out));
    memset(ans,0,sizeof(ans));
}

void toposort()
{
    int cnt = 1;
    priority_queue<int> q;
    for(int i = 1; i <= n; i++)
        if(out[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int u = q.top(); q.pop();
        ans[cnt++] = u;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            out[v]--;
            if(out[v] == 0) q.push(v);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            G[y].push_back(x);
            out[x]++;
        }
        toposort();
        for(int i = n; i > 1; i--)
            printf("%d ",ans[i]);
        printf("%d\n",ans[1]);
    }
    return 0;
}
