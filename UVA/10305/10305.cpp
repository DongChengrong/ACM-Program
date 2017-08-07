#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
int m,n;
int topo[maxn],G[maxn][maxn],vis[maxn],cur;

//进行初始化
void init()
{
    cur=n;
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
}

//实际上深搜应该返回正确与否，但这里假设数据是正确的
//所以这个算法仅适用于本题
void dfs(int u)
{
    for(int v=0;v<n;v++)
    {
        if(G[u][v] && !vis[v])
            dfs(v);
    }
    vis[u]=1;
    topo[--cur]=u;
}

//进行拓扑排序
int toposort()
{
    for(int i=0;i<n;i++)
        if(!vis[i]) dfs(i);
    return 1;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2 && n)
    {
        init();
        //建立有向图
        for(int i=0;i<m;i++)
        {
            int v,u;
            scanf("%d%d",&u,&v);
            G[u-1][v-1]=1;
        }
        //因为没有给出无法拓扑排序时的输出结果，所以应该所有数据都合法
        toposort();
        for(int i=0;i<n-1;i++)
            printf("%d ",topo[i]+1);
        printf("%d\n",topo[n-1]+1);
    }
    return 0;
}
