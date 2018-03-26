#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define N 100000 + 100

vector<int> G[N];
int vis[N];

int n,s;

void dfs(int u)
{
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(vis[v] == 0){
            vis[v] = u; dfs(v);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&s);

        for(int i = 1; i <= n; i++)   //ǰ����Ҫ���˳�ʼ����
            G[i].clear();

        for(int i = 0; i < n - 1; i++)   //��������ͼ
        {
            int u, v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        memset(vis,0,sizeof(vis));   //init
        vis[s] = -1;
        dfs(s);
        for(int i = 1; i <= n; i++)
            printf("%d%c",vis[i],i == n ? '\n' : ' ');
    }
    return 0;
}
