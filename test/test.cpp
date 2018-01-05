#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

const int maxn = 100000 + 10;
vector<int> G[maxn];
int in[maxn],sz[maxn],be[maxn],ed[maxn];
int n,ans;

void read_tree()
{
    memset(in,0,sizeof(in));
    scanf("%d",&n);
    for(int i = 1; i < n; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        in[v] = 1;
    }
}

void dfs(int u)
{
    sz[u] = 1; be[u] = u; ed[u] = u;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        be[u] = min(be[u],be[v]);
        ed[u] = max(ed[u],ed[v]);
        sz[u] += sz[v];
    }
    if(ed[u] - be[u] + 1 == sz[u]) ans++;
}

int main()
{
    read_tree();
    ans = 0;
    for(int i = 1; i <= n; i++)
        if(!in[i]) { dfs(i); break; }
    printf("%d\n",ans);
    return 0;
}
